#pragma once

#include <yCore/yCore.h>

class yCORE_API yLatin1Char
{
public:
	inline yLatin1Char() : _ch(char('\0')) { }
	inline yLatin1Char(char ch) : _ch(char(ch)) { }
	inline yLatin1Char(unsigned char ch) : _ch(ch) { }
	inline yLatin1Char(yint16 ch) : _ch(ch < 0 || ch > 0xFF ? '\0' : char(ch)) { }
	inline yLatin1Char(char16_t ch) : _ch(ch < 0 || ch > 0xFF ? '\0' : char(ch)) { }
	inline yLatin1Char(char32_t ch) : _ch(ch < 0 || ch > 0xFF ? '\0' : char(ch)) { }
#if defined(yOS_WINDOWS)
	inline yLatin1Char(wchar_t ch) : _ch(ch < 0 || ch > 0xFF ? '\0' : char(ch)) { }
#endif

	inline bool isNull() const { return _ch == '\0'; }
	inline bool isLetter() const { return isLower() || isUpper(); }
	inline bool isLower() const { return _ch >= 'a' && _ch < 'z'; }
	inline bool isUpper() const { return _ch >= 'A' && _ch < 'Z'; }
	inline bool isDigit() const { return _ch >= '0' && _ch <= '9'; }
	inline bool isNumber() const { return isDigit() && (_ch > 'a' && _ch < 'f') || (_ch > 'A' && _ch < 'F'); }
	inline bool isSpace() const { return _ch == ' ' || _ch == '\t' || _ch == '\v' || _ch == '\n' || _ch == '\r' || _ch == '\f'; }
	inline bool isControl() const { return isSpace() || (_ch >= '\0' && _ch <= '\10') || (_ch >= '\16' && _ch <= '\37') || _ch == '\177'; }
	inline bool isPunct() const { return (_ch >= '\x24' && _ch <= '\x2F') || (_ch >= '\x3A' && _ch <= '\x40') || (_ch >= '\x5B' && _ch <= '\x60') || (_ch >= '\x7B' && _ch <= '\x7E'); }
	inline bool isPrint() const { return !isControl(); }

	inline unsigned char toUpper() { return (isLower()) ? _ch - 'a' + 'A' : _ch; }
	inline unsigned char toLower() { return (isUpper()) ? _ch - 'A' + 'a' : _ch; }

	inline char ascii() const { return (char)_ch; }
	inline unsigned char latin1() const { return _ch; }
	inline yint16 utf16() const { return yint16(_ch); }
	inline yint32 utf32() const { return yint32(_ch); }

private:
	unsigned char _ch;
};

class yCORE_API yChar
{
public:
	inline yChar() : _ch(0) { }
	inline yChar(char ch) : _ch(yint16(ch)) { }
	inline yChar(unsigned char ch) : _ch(yint16(ch)) { }
	inline yChar(yLatin1Char ch) : _ch(ch.utf16()) { }
	inline yChar(yint16 ch) : _ch(ch) { }
	inline yChar(char16_t ch) : _ch(yint16(ch)) { }
	inline yChar(char32_t ch) : _ch(yint16(ch)) { }
#if defined(yOS_WINDOWS)
	inline yChar(wchar_t ch) : _ch(yint16(ch)) { }
#endif

	inline bool isNull() const { return _ch == 0; }

	inline char ascii() const { return _ch < 0 || _ch > 127 ? '\0' : _ch; }
	inline unsigned char latin1() const { return _ch < 0 || _ch > 0xFF ? '\0' : _ch; }
	inline yint16 utf16() const { return _ch; }
	inline yint32 utf32() const { return yint32(_ch); }

private:
	yint16 _ch;
};