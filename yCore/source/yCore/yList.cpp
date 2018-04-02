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

#include <yCore/yList.h>

template<typename T>
yListIterator<T> yList<T>::insert(const_iterator before, const T & value)
{
	yListNode<T> * node = new yListNode<T>;
	node->value = value;
	node->previous = before.node();
	if (before._node != nullptr) {
		node->next = before.node()->next();
		if (before._node->next != nullptr)
			before._node->next->previous = node;
		before._node->next = node;
	} else {
		node->next = nullptr;
	}

	// Update head and tail nodes
	if (!before.hasPrevious()) _head = node;
	if (!node->next != nullptr) _tail = node;

	// Increment size
	++_size;

	return iterator(node);
}
template<typename T>
yListIterator<T> yList<T>::insert(const_iterator before, size_type count, const T & value)
{
	for (size_type index(0); index < count; ++index)
		insert(before, value);

	if (before._node != nullptr)
		return iterator(before._node->next);
	else
		return end();
}
template<typename T>
yListIterator<T> yList<T>::insert(const_iterator before, T && value)
{
	return insert(before, std::move(value));
}
template<typename T>
yListIterator<T> yList<T>::insert(const_iterator before, std::initializer_list<T> il)
{
	return insert(before, il.begin(), il.end());
}
template<typename T>
template<class InputIterator>
yListIterator<T> yList<T>::insert(const_iterator before, InputIterator first, InputIterator last)
{
	for (InputIterator it(first); it != last; ++it)
		insert(before, (*it));

	if (before._node != nullptr)
		return iterator(before._node->next);
	else
		return end();
}

template<typename T>
void yList<T>::append(const T & value)
{
	yListNode<T> * node = new yListNode<T>;
	node->value = value;
	node->previous = before._node;
	if (_head != nullptr) {
		node->next = _head->next();
		if (before._node->next != nullptr)
			before._node->next->previous = node;
		before._node->next = node;
	} else {
		_head = node;
		_tail = node;

		// Increment size
		++_size;

		return;
	}

	// Update head and tail nodes
	if (!before.hasPrevious()) _head = node;
	if (!node->next != nullptr) _tail = node;

	// Increment size
	++_size;
}