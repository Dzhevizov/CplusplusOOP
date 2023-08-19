#ifndef TREE_VIEW_H
#define TREE_VIEW_H

void renderTreeView(const std::shared_ptr<FileSystemObject>& root, int levelsIn, std::ostringstream& output)
{
	for (int i = 0; i < levelsIn; ++i)
	{
		output << "--->";
	}

	output << root->getName() << std::endl;

	auto asContainer = std::dynamic_pointer_cast<FileSystemObjectsContainer>(root);

	if (asContainer)
	{
		std::vector<std::shared_ptr<FileSystemObject>> sortedNames(asContainer->begin(), asContainer->end());
		std::sort(sortedNames.begin(), sortedNames.end(), [](const std::shared_ptr<FileSystemObject> a,
			const std::shared_ptr<FileSystemObject> b) {return a->getName() < b->getName(); });

		for (auto obj : sortedNames)
		{
			renderTreeView(obj, levelsIn + 1, output);
		}
	}
}

std::string getTreeView(const std::vector<std::shared_ptr<FileSystemObject>>& rootObjects)
{
	std::ostringstream output;

	for (auto obj : rootObjects) 
	{ 
		renderTreeView(obj, 0, output); 
	} 
	
	return output.str();
}

#endif // !TREE_VIEW_H
