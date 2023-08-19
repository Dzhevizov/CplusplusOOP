#ifndef FILE_H
#define FILE_H

class File : public FileSystemObject, public ByteContainer
{
public:
	File(std::string name, std::string bytes)
		: FileSystemObject(name)
		, bytes(bytes)
	{
	}

	size_t getSize() const override
	{
		return bytes.length();
	}

	std::string getBytes() const override
	{
		return bytes;
	}

private:
	std::string bytes;
};

#endif // !FILE_H
