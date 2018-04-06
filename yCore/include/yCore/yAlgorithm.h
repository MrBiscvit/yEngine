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

#ifndef _YON_ALHORITHM_HEADER_
#define _YON_ALHORITHM_HEADER_
#pragma once

#include <yCore/yCore.h>
#include <algorithm>

yNAMESPACE_BEGIN

template<class Iterator1, class Iterator2>
inline bool yEqual(Iterator1 first1, Iterator1 last1, Iterator2 first2, Iterator2 last2)
{ return std::equal(first1, last1, first2, last2); }
template <class Iterator, typename T>
inline Iterator yFind(Iterator first, Iterator last, const T & value)
{ return std::find(first, last, value); }
template <class Iterator, typename T>
inline int yCount(Iterator first, Iterator last, const T & value)
{ return std::count(first, last, value); }
template<class Iterator, class SubSequenceIterator>
inline Iterator ySearch(Iterator first1, Iterator last1, SubSequenceIterator first2, SubSequenceIterator last2)
{ return std::search(first1, last1, first2, last2); }

template<typename InputIterator, class OutputIterator>
inline OutputIterator yCopy(InputIterator first, InputIterator last, OutputIterator result)
{ return std::copy(first, last, result); }
template<typename InputIterator, class OutputIterator>
inline OutputIterator yMove(InputIterator first, InputIterator last, OutputIterator result)
{ return std::move(first, last, result); }
template<class Iterator, typename T>
inline void yReplace(Iterator first, Iterator last, const T & oldValue, const T & newValue)
{ std::replace(first, last, oldValue, newValue); }
template <class Iterator, typename T>
inline void yFill(Iterator first, Iterator last, const T & value)
{ std::fill(first, last, value); }
template <class Iterator, class T>
inline Iterator yRemove(Iterator first, Iterator last, const T& value)
{ return std::remove(first, last, value); }
template <class Iterator>
inline Iterator yUnique(Iterator first, Iterator last)
{ return std::unique(first, last); }
template <class Iterator>
inline void yReverse(Iterator first, Iterator last)
{ std::reverse(first, last); }

template <class Iterator>
inline void ySort(Iterator first, Iterator last)
{ std::sort(first, last); }
template <class Iterator>
inline bool yIsSorted(Iterator first, Iterator last)
{ return std::is_sorted(first, last); }

template <class Iterator>
inline Iterator yMinElement(Iterator first, Iterator last)
{ return std::min_element(first, last); }
template <class Iterator>
inline Iterator yMaxElement(Iterator first, Iterator last)
{ return std::max_element(first, last); }

yNAMESPACE_END

#endif // !_YON_ALHORITHM_HEADER_