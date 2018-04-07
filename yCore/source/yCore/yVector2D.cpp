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

#include <yCore/yVector2D.h>
#include <yCore/yVector3D.h>
#include <yCore/yVector4D.h>

yNAMESPACE_BEGIN

template<typename T>
yTemplateVector2D<T>::yTemplateVector2D(const yTemplateVector3D<T>& other) :
	_x(other.x()), _y(other.y())
{
}
template<typename T>
yTemplateVector2D<T>::yTemplateVector2D(const yTemplateVector4D<T>& other) :
	_x(other.x()), _y(other.y())
{
}

template<typename T>
yTemplateVector2D<T>& yTemplateVector2D<T>::operator=(const yTemplateVector3D<T>& other)
{
	_x = other.x();
	_y = other.y();
	return *this;
}
template<typename T>
yTemplateVector2D<T>& yTemplateVector2D<T>::operator=(const yTemplateVector4D<T>& other)
{
	_x = other.x();
	_y = other.y();
	return *this;
}
template<typename T>
yTemplateVector3D<T> yTemplateVector2D<T>::toVector3D() const
{
	return yTemplateVector3D<T>(_x, _y, T(0));
}
template<typename T>
yTemplateVector4D<T> yTemplateVector2D<T>::toVector4D() const
{
	return yTemplateVector3D<T>(_x, _y, T(0), T(0));
}

yNAMESPACE_END