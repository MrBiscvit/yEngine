#pragma once

#include <yEmma/yEmma.h>

typedef yuint32 yRgb32, yRgb;
typedef yuint64 yRgb64;

class yEMMA_API yColor
{
public:
	inline yColor() : _r(0), _g(0), _b(0), _a(0xFF) { }
	inline yColor(yuint8 red, yuint8 green, yuint8 blue, yuint8 alpha = 0xFF) : _r(red), _g(green), _b(blue), _a(alpha) { }
	inline yColor(yreal red, yreal green, yreal blue, yreal alpha = 1.f) : _r(red * 0xFF), _g(green * 0xFF), _b(blue * 0xFF), _a(alpha * 0xFF) { }
	inline explicit yColor(yRgb rgb) { setRgb(rgb); }
	inline explicit yColor(yRgb64 rgb) { setRgb64(rgb); }

	inline yuint8 red() const { return _r; }
	inline yuint8 green() const { return _g; }
	inline yuint8 blue() const { return _b; }
	inline yuint8 alpha() const { return _a; }
	inline yreal redF() const { return _r / 0xFF; }
	inline yreal greenF() const { return _g / 0xFF; }
	inline yreal blueF() const { return _b / 0xFF; }
	inline yreal alphaF() const { return _a / 0xFF; }

	inline void setRed(yuint8 red) { _r = red; }
	inline void setGreen(yuint8 green) { _g = green; }
	inline void setBlue(yuint8 blue) { _b = blue; }
	inline void setAlpha(yuint8 alpha) { _a = alpha; }
	inline void setRedF(yreal red) { _r = red * 0xFF; }
	inline void setGreenF(yreal green) { _g = green * 0xFF; }
	inline void setBlueF(yreal blue) { _b = blue * 0xFF; }
	inline void setAlphaF(yreal alpha) { _a = alpha * 0xFF; }

	inline yRgb rgb() const { return (_a << 24) + (_r << 16) + (_g << 8) + _b; }
	inline yRgb64 rgb64() const { return (_a << 48) + (_r << 24) + (_g << 16) + _b; }
	inline void setRgb(yuint8 red, yuint8 green, yuint8 blue, yuint8 alpha = 0xFF) { _r = red; _g = green; _b = blue; _a = alpha; }
	inline void setRgb(yRgb rgb) { _a = (rgb >> 24) & 0xFF; _r = (rgb >> 16) & 0xFF; _g = (rgb >> 8) & 0xFF; _b = rgb & 0xFF; }
	inline void setRgbF(yreal red, yreal green, yreal blue, yreal alpha = 1.f) { _r = red * 0xFF; _g = green * 0xFF; _b = blue * 0xFF; _a = alpha * 0xFF; }
	inline void setRgb64(yRgb64 rgb) { _a = (rgb >> 48) & 0xFF; _r = (rgb >> 24) & 0xFF; _g = (rgb >> 16) & 0xFF; _b = rgb & 0xFF; }

private:
	yuint8 _r, _g, _b, _a;
};