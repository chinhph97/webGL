#pragma once
#include "Engine.h"
#include "Singleton.h"

class FileSystem : public Singleton<FileSystem>
{
private:
	std::string resourcePath;
public:	
	void Init(const std::string path);
	char* GetContent(const std::string path);
	std::string GetPath(const std::string path);
	FILE * openFile(const std::string path);
	std::fstream * openStream(const std::string path);
};

