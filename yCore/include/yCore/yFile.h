#pragma once

#include <yCore/yCore.h>
#include <yCore/yIODevice.h>
#include <cstdio>

class yCORE_API yFile : public yIODevice
{
public:
	enum Permission
	{

	};

public:

	virtual yint64 bytesAvailable() const;
	virtual yint64 bytesToWrite() const;

	virtual bool open(int openMode);
	bool open(const std::string & path, int openMode);
	virtual void close();
	virtual bool isOpen() const;

	virtual yint64 read(char * data, yint64 maxSize);
	virtual yint64 write(const char * data, yint64 maxSize);
	virtual bool seek(yint64 position);
	virtual yint64 tell() const;
	virtual yint64 size() const;

	static bool copy(const std::string & fileName, const std::string & newName, bool overrideFile = true);
	static bool exists(const std::string & fileName);
	static bool remove(const std::string & fileName);
	static bool rename(const std::string & oldName, const std::string & newName);
	static bool resize(const std::string & fileName, yint64 size);

private:
	yHandle * _handle;
	std::string _path;
};