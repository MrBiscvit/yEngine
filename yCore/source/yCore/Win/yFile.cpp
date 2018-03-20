#include <yCore/yFile.h>
#if defined(yOS_WINDOWS)
#include <Windows.h>

yFile::yFile() :
	_handle(nullptr), _path()
{
}
yFile::yFile(const std::string & path) :
	_handle(nullptr), _path(path)
{
}
yFile::~yFile()
{
	if (isOpen())
		close();
}

bool yFile::open(int openMode)
{
	if (isOpen())
		return false;

	setOpenMode(openMode);

	DWORD winOpenMode = 0;
	if (openMode & ReadOnly)
		winOpenMode |= GENERIC_READ;
	if (openMode & WriteOnly)
		winOpenMode |= GENERIC_WRITE;

	_handle = (yHandle*)CreateFile(_path.c_str(),
						           winOpenMode,
						           FILE_SHARE_DELETE,
						           NULL,
								   OPEN_EXISTING,
								   FILE_ATTRIBUTE_NORMAL,
						           NULL);

	if (_handle)
		return true;
	else
		return false;
}
bool yFile::open(const std::string & path, int openMode)
{
	_path = path;
	return open(openMode);
}
void yFile::close()
{
	if (isOpen())
		CloseHandle(_handle);
}
bool yFile::isOpen() const
{
	return _handle;
}

yint64 yFile::read(char * data, yint64 maxSize)
{
	DWORD r = 0;
	if (isOpen() && !ReadFile(_handle, data, DWORD(maxSize), &r, NULL)) {
		return -1;
	} else {
		return r;
	}
}
yint64 yFile::write(const char * data, yint64 maxSize)
{
	DWORD w = 0;
	if (isOpen() && !WriteFile(_handle, data, DWORD(maxSize), &w, NULL))
		return false;
	else
		return w;
}
bool yFile::seek(yint64 position)
{
	if (isOpen())
		return SetFilePointer(_handle, LONG(position), NULL, FILE_BEGIN) != INVALID_SET_FILE_POINTER;
	else
		return false;
}
yint64 yFile::tell() const
{
	if (isOpen())
		return SetFilePointer(_handle, 0, NULL, FILE_CURRENT);
	else
		return false;
}
yint64 yFile::size() const
{
	if (isOpen())
		return GetFileSize(_handle, NULL);
	else
		return false;
}

bool yFile::copy(const std::string & fileName, const std::string & newName, bool overrideFile)
{
	return CopyFile(fileName.c_str(), newName.c_str(), overrideFile);
}
bool yFile::exists(const std::string & fileName)
{
	DWORD attrib = GetFileAttributes(fileName.c_str());
	return (attrib != INVALID_FILE_ATTRIBUTES &&
			!(attrib & FILE_ATTRIBUTE_DIRECTORY));
}
bool yFile::remove(const std::string & fileName)
{
	return DeleteFile(fileName.c_str());
}
bool yFile::rename(const std::string & oldName, const std::string & newName)
{
	return MoveFile(oldName.c_str(), newName.c_str());
}
bool yFile::resize(const std::string & fileName, yint64 size)
{
	yFile file;
	file.open(fileName, WriteOnly);
	file.seek(size);
	return SetEndOfFile(file._handle);
}

#endif