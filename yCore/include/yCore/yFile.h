#pragma once

#include <yCore/yCore.h>
#include <yCore/yIODevice.h>
#include <cstdio>
#include <string>

class yCORE_API yFile : public yIODevice
{
public:
	enum Permission
	{
	};

public:
	yFile();
	yFile(const std::string & path);
	virtual ~yFile();

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

	inline bool copy(const std::string & name, bool override = true) { return copy(_path, name, override); }
	inline bool exists() const { return exists(_path); }
	inline bool remove() { close(); return remove(_path); }
	inline bool rename(const std::string & name) { close(); bool r = rename(_path, name); _path = name; return open(openMode()) && r; }
	inline bool resize(yint64 size) { return resize(size); }

	static bool copy(const std::string & fileName, const std::string & newName, bool overrideFile = true);
	static bool exists(const std::string & fileName);
	static bool remove(const std::string & fileName);
	static bool rename(const std::string & oldName, const std::string & newName);
	static bool resize(const std::string & fileName, yint64 size);

private:
	yHandle * _handle;
	std::string _path;
};