#ifndef DIRECTORY_H
#define DIRECTORY_H

class Directory : public FileSystemObject, public FileSystemObjectsContainer
{
public:
	Directory(std::string name)
		: FileSystemObject(name)
	{
	}

	size_t getSize() const override
	{
		size_t sum = 0;

		for (auto obj : files)
		{
			sum += obj->getSize();
		}

		return sum;
	}

	std::vector<std::shared_ptr<FileSystemObject> >::const_iterator begin() const override
	{
		return files.begin();
	}

	std::vector<std::shared_ptr<FileSystemObject> >::const_iterator end() const override
	{
		return files.end();
	}

	void add(const std::shared_ptr<FileSystemObject>& obj) override
	{
		files.push_back(obj);
	}

private:
	std::vector<std::shared_ptr<FileSystemObject>> files;
};

#endif // !DIRECTORY_H
