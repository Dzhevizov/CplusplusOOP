#ifndef EXPLORER_H
#define EXPLORER_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <sstream>

#include "FileSystemObject.h"
#include "FileSystemObjectsContainer.h"
#include "File.h"
#include "Directory.h"
#include "Shortcuts.h"

class Root : public FileSystemObject, public FileSystemObjectsContainer
{
public:
	Root(std::vector<std::shared_ptr<FileSystemObject>>& rootObjects) 
		: FileSystemObject("")
		, m_rootObjects(rootObjects) {}

	void add(const std::shared_ptr<FileSystemObject>& obj) override
	{
		m_rootObjects.push_back(obj);
	}

	std::vector<std::shared_ptr<FileSystemObject> >::const_iterator begin() const override
	{
		return m_rootObjects.begin();
	}

	std::vector<std::shared_ptr<FileSystemObject> >::const_iterator end() const override
	{
		return m_rootObjects.end();
	}

	void setParent(const std::weak_ptr<FileSystemObject>& parent) override {}

	std::weak_ptr<FileSystemObject> getParent() const override {
		return std::weak_ptr<FileSystemObject>();
	}

	size_t getSize() const override
	{
		return 0;
	}

	void remove(std::shared_ptr<FileSystemObject> obj) override
	{
		m_rootObjects.erase(std::find(m_rootObjects.begin(), m_rootObjects.end(), obj));
	}

private:
	std::vector<std::shared_ptr<FileSystemObject>> m_rootObjects;
};


class Explorer
{
public:
	Explorer(std::vector<std::shared_ptr<FileSystemObject>>& rootObjects)
		: root(std::make_shared<Root>(rootObjects)) 
	{
		currDirectory = root;
	}

	void createFile(const std::string& filename, const std::string& contents)
	{
		auto file = std::make_shared<File>(filename, contents);
		currDirectory->add(file);
		file->setParent(std::dynamic_pointer_cast<FileSystemObject> (currDirectory));
	}

	void createDirectory(const std::string& name)
	{
		auto directory = std::make_shared<Directory>(name);
		currDirectory->add(directory);
		directory->setParent(std::dynamic_pointer_cast<FileSystemObject> (currDirectory));
	}

	void cut(std::string& name)
	{
		auto fso = find(name);
		clipboard.push_back(fso);
	}

	void paste()
	{
		for (auto fso : clipboard)
		{
			moveTo(fso, currDirectory);
		}

		clipboard.clear();
	}

	void createShortcut(std::string& name)
	{
		if (!shortcuts)
		{
			shortcuts = std::make_shared<Shortcuts>();
			root->add(shortcuts);
		}

		shortcuts->add(find(name));
	}

	bool navigate(const std::string& path)
	{
		std::vector<std::string> parts = getPathParts(path);

		return navigate(parts, parts.end());
	}

private:
	static std::vector<std::string> getPathParts(std::string path)
	{
		std::vector<std::string> parts;

		std::istringstream iStr(path);
		std::string part;
		while (std::getline(iStr, part, '/'))
		{
			parts.push_back(part);
		}

		return parts;
	}

	bool navigate(const std::vector<std::string>& path, std::vector<std::string>::iterator end)
	{
		for (auto i = path.begin(); i != end; i++)
		{
			bool navigated = navigateSingleStep(*i);

			if (!navigated)
				return false;
		}

		return true;
	}

	bool navigateSingleStep(std::string path)
	{
		if (path == "..")
		{
			auto currFso = std::dynamic_pointer_cast<FileSystemObject> (currDirectory);
			std::shared_ptr<FileSystemObject> parentPtr = (currFso ? currFso->getParent().lock()
				: std::shared_ptr<FileSystemObject>());

			if (parentPtr)
			{
				currDirectory = std::dynamic_pointer_cast<FileSystemObjectsContainer> (parentPtr);
				return true;
			}
			else
			{
				auto asRoot = std::dynamic_pointer_cast<Root> (currDirectory);

				if (asRoot)
					return false;
				else
				{
					currDirectory = root;
					return true;
				}
			}

			return false;
		}

		auto fso = findIn(currDirectory, path);

		auto nestedDir = std::dynamic_pointer_cast<FileSystemObjectsContainer> (fso);

		if (nestedDir)
		{
			currDirectory = nestedDir;
			return true;
		}

		return false; 
	}

	std::shared_ptr<FileSystemObject> find(std::string& name)
	{
		return findIn(currDirectory, name);
	}

	std::shared_ptr<FileSystemObject> findIn(std::shared_ptr<FileSystemObjectsContainer> directory, std::string& name)
	{
		for (auto fso : *directory)
		{
			if (fso->getName() == name)
				return fso;
		}

		return nullptr;
	}

	void moveTo(std::shared_ptr<FileSystemObject> obj, std::shared_ptr<FileSystemObjectsContainer> container)
	{
		auto prevContainer = std::dynamic_pointer_cast<FileSystemObjectsContainer> (obj->getParent().lock());

		if (prevContainer)
			prevContainer->remove(obj);
		else
			root->remove(obj);

		container->add(obj);

		if (container != root)
			obj->setParent(std::dynamic_pointer_cast<FileSystemObject> (container));
	}

	std::vector<std::shared_ptr<FileSystemObject>> clipboard;
	std::shared_ptr<FileSystemObjectsContainer> currDirectory;

	std::shared_ptr<Root> root;
	std::shared_ptr<Shortcuts> shortcuts;
};

#endif // !EXPLORER_H
