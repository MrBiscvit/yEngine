#pragma once

#include <yCore/yCore.h>
#include <yCore/yByteArray.h>

class yCORE_API yIODevice
{
public:
	enum OpenMode
	{
		NotOpen = 0x0,
		ReadOnly = 0x1,
		WriteOnly = 0x2,
		ReadWrite = ReadOnly | WriteOnly,
		Append = 0x4,
		Truncate = 0x8,
		Text = 0x10
	};

public:

	virtual yint64 bytesAvailable() const { return 0; }
	virtual yint64 bytesToWrite() const { return 0; }

	virtual bool open(int openMode) = 0;
	virtual void close() = 0;
	virtual bool isOpen() = 0;

	virtual bool atEnd() const { return true; }

	virtual yint64 read(char * data, yint64 maxSize) = 0;
	yByteArray read(yint64 maxSize);
	inline yByteArray readAll() { return read(size()); }
	virtual yint64 write(const char * data, yint64 maxSize) = 0;
	inline yint64 write(const char * data) { return write(data, strlen(data)); }
	inline yint64 write(const yByteArray & array) { return write(array.data(), array.size()); }
	virtual bool seek(yint64 position) = 0;
	virtual yint64 tell() const = 0;
	virtual yint64 size() const { return 0; }

	inline bool isReadable() const { return bytesAvailable() != 0; }
	inline bool isWritable() const { return bytesToWrite() != 0; }

	inline int openMode() const { return _openMode; }

protected:
	inline void setOpenMode(int openMode) { _openMode = openMode; }

private:
	int _openMode;
};