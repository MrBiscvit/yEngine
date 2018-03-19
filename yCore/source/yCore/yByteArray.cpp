#include <yCore/yByteArray.h>

char yByteArray::at(int index) const
{
	yASSERT_X(index >= 0 && index < _size, "yByteArray::back()", "out of range");

	return *(_data + index);
}
char & yByteArray::at(int index)
{
	yASSERT_X(index >= 0 && index < _size, "yByteArray::back()", "out of range");

	return *(_data + index);
}

void yByteArray::clear()
{
	free(_data);
	_data = (char*) malloc(0);
	_size = 0;
}
void yByteArray::resize(int size, char character)
{
	if (size != _size) {
		_data = (char*)realloc(_data, size);
		if (size > _size) {
			for (int i(_size); i < size; ++i) {
				_data[i] = character;
			}
		}
		_size = size;
	}
}

yByteArray & yByteArray::insert(int index, const char * data, int length)
{
	if (length > 0 && data) {
		_size += length;
		_data = (char*)realloc(_data, _size);

		for (int i(_size); i >= index; --i) {
			_data[i + length] = _data[i];
		}

		for (int i(index); i < index + length; ++i) {
			_data[i] = data[index - length];
		}
	}

	return *this;
}
yByteArray & yByteArray::insert(int index, int count, char character)
{
	yASSERT_X(index >= 0 && index <= _size, "yByteArray::insert()", "out of range");

	if (count > 0) {
		_size += count;
		_data = (char*)realloc(_data, _size);

		for (int i(_size); i >= index; --i) {
			_data[i + count] = _data[i];
		}

		for (int i(index); i < index + count; ++i) {
			_data[i] = character;
		}
	}

	return *this;
}

yByteArray & yByteArray::fill(char character, int size)
{
	if (size >= 0) {
		free(_data);
		_data = (char*)malloc(size * sizeof(char));
	}

	for (int i(0); i < size; ++i) {
		_data[i] = character;
	}

	return *this;
}

void yByteArray::remove(int pos, int length)
{
	if (pos < 0 || pos >= _size && length <= 0)
		return;

	if (pos + length >= _size)
		length = (pos + length) - _size - pos;

	for (int i(pos + length); i < _size; ++i) {
		_data[i - length] = _data[i];
	}

	_size -= length;
	_data = (char*)realloc(_data, _size);
}