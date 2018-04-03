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

#ifndef _YON_MATH_HEADER_
#define _YON_MATH_HEADER_
#pragma once

#include <yCore/yCore.h>
#include <cmath>

yNAMESPACE_BEGIN

template<typename T>
inline T ySin(T value) { return std::sin(value); }
template<typename T>
inline T yCos(T value) { return std::cos(value); }
template<typename T>
inline T yTan(T value) { return std::tan(value); }
template<typename T>
inline T yAsin(T value) { return std::asin(value); }
template<typename T>
inline T yAcos(T value) { return std::acos(value); }
template<typename T>
inline T yAtan(T value) { return std::atan(value); }
template<typename T>
inline T yAtan(T value1, T value2) { return std::atan2(value1, value2); }

template<typename T>
inline T ySinh(T value) { return std::sinh(value); }
template<typename T>
inline T yCosh(T value) { return std::cosh(value); }
template<typename T>
inline T yTanh(T value) { return std::tanh(value); }
template<typename T>
inline T yAsinh(T value) { return std::asinh(value); }
template<typename T>
inline T yAcosh(T value) { return std::acosh(value); }
template<typename T>
inline T yAtanh(T value) { return std::atanh(value); }

template<typename T>
inline T yExp(T value) { return std::exp(value); }
template<typename T>
inline T yLog(T value) { return std::log(value); }

template<typename T>
inline T yPow(T value, T exponent) { return std::pow(value, exponent); }
template<typename T>
inline T ySqrt(T value) { return std::sqrt(value); }
template<typename T>
inline T yCbrt(T value) { return std::cbrt(value); }
template<typename T>
inline T yHypot(T value1, T value2) { return std::hypot(value1, value2); }

yNAMESPACE_END

#endif // !_YON_MATH_HEADER_