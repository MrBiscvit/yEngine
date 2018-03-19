#pragma once

#include <yCore/yCore.h>

class yCORE_API yByteArray
{
public:
	yByteArray();
	yByteArray(const char * data, int size);
	yByteArray(const char * data);
	yByteArray(int count, char charater);
	yByteArray(char character);
	~yByteArray();

	inline int size() const { return _size; }
	inline int length() const { return _size; }
	inline int count() const { return _size; }
	inline bool empty() const { return _size == 0; }
	inline bool isEmpty() const { return _size == 0; }

	inline char front() const { return at(0); }
	inline char & front() { return at(0); }
	inline char back() const { return at(_size - 1); }
	inline char & back() { return at(_size - 1); }
	char at(int index) const;
	char & at(int index);

	inline char * data() { return _data; }
	inline const char * data() const { return _data; }
	inline const char * constData() const { return _data; }

	void clear();
	void resize(int size, char character = '\0');

	inline yByteArray & insert(int index, const yByteArray & other) { return insert(index, other._data, other._size); }
	yByteArray & insert(int index, const char * data, int length);
	inline yByteArray & insert(int index, const char * data) { return insert(index, data, (int)strlen(data)); }
	yByteArray & insert(int index, int count, char character);
	inline yByteArray & insert(int index, char character) { return insert(index, 1, character); }

	inline yByteArray & append(const yByteArray & other) { return append(other._data, other._size); }
	inline yByteArray & append(const char * data, int length) { return insert(_size-1, data, length); }
	inline yByteArray & append(const char * data) { return append(data, (int)strlen(data)); }
	inline yByteArray & append(int count, char character) { return insert(_size - 1, count, character); }
	inline yByteArray & append(char character) { return append(1, character); }
	inline yByteArray & push_back(const yByteArray & other) { return append(other); }
	inline yByteArray & push_back(const char * data) { return append(data); }
	inline yByteArray & push_back(char character) { return append(character); }

	inline yByteArray & prepend(const yByteArray & other) { return prepend(other._data, other._size); }
	inline yByteArray & prepend(const char * data, int length) { return insert(0, data, length); }
	inline yByteArray & prepend(const char * data) { return prepend(data, (int)strlen(data)); }
	inline yByteArray & prepend(int count, char character) { return insert(0, count, character); }
	inline yByteArray & prepend(char character) { return prepend(1, character); }
	inline yByteArray & push_front(const yByteArray & other) { return prepend(other); }
	inline yByteArray & push_front(const char * data) { return prepend(data); }
	inline yByteArray & push_front(char character) { return prepend(character); }

	void remove(int pos, int length);

	yByteArray & fill(char character, int size = -1);

private:
	int _size;
	char * _data;
};