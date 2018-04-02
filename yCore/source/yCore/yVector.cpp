// 
// MIT License
// 
// Copyright(c) 2018 Hubert Gruniaux
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// 

#include <yCore/yVector.h>

template<typename T>
void yVector<T>::reserve(size_type size)
{
	if (size <= 0) return;

	if (data != nullptr) {
		T * data = _data;
		_data = new T[_size + _capacity + size];
		std::memcpy(_data, data, _size);
		delete[] data;
		_capacity += size;
	} else {
		_data = new T[size];
		_capacity = size;
		_size = 0;
	}
}
template<typename T>
void yVector<T>::resize(size_type size, const T & value)
{
	if (size <= 0) return;

	if (data != nullptr) {
		T * data = _data;
		_data = new T[size];
		std::memcpy(_data, data, size);
		if (size > _size)
			std::for_each(_data + _size, _data + size, [ ](T & el) { el = value; };);
		delete[] data;
		_size = size;
		_capacity = 0;
	} else {
		_data = new T[size];
		std::for_each(_data, _data + size, [ ](T & el) { el = value; };);
		_capacity = 0;
		_size = size;
	}
}
template<typename T>
void yVector<T>::clear()
{
	_size = 0;
	_capacity = 0;
	delete[] _data;
	_data = nullptr;
}
template<typename T>
void yVector<T>::squeeze()
{
	if (!_capacity) return;

	T * data = _data;
	_data = new T[_size];
	std::memcpy(_data, data, _size);
	delete[] data;
	_capacity = 0;
}