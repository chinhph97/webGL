#include "FileSystem.h"
#include "Engine.h"

using namespace std;


void FileSystem::Init(const string path)
{
	resourcePath = path;
}

char* FileSystem::GetContent(const string fileName)
{	
	string fullPath = GetPath(fileName);
	FILE * pf = fopen( fullPath.data(), "rb" );
	if (pf == 0)
		return NULL;
	fseek(pf, 0, SEEK_END);
	long size = ftell(pf);
	fseek(pf, 0, SEEK_SET);

	char * buffer = new char[size + 1];
	fread(buffer, sizeof(char), size, pf);
	buffer[size] = 0;
	fclose(pf);
	return buffer;
}

std::string FileSystem::GetPath(std::string path)
{
	return resourcePath + path;
}
FILE * openFile(std::string path)
{
	return fopen( path.data(), "r" );
}
fstream * FileSystem::openStream(const std::string path)
{
	fstream * f = new fstream;
	f->open( GetPath(path).data() );
	return f;
}