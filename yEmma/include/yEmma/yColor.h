#pragma once

#include <yEmma/yEmma.h>
#include <yMath/yMath.h>

typedef yuint32 yRgb32, yRgb;
typedef yuint64 yRgb64;
struct yCmyk
{
	yuint8 cyan;
	yuint8 magenta;
	yuint8 yellow;
	yuint8 key;
	yuint8 alpha;
};
struct yHsl
{
	yuint16 hue;
	yuint8 saturation;
	yuint8 lightness;
	yuint8 alpha;
};
struct yHsv
{
	yuint16 hue;
	yuint8 saturation;
	yuint8 value;
	yuint8 alpha;
};

class yEMMA_API yColor
{
public:
	inline yColor() : _r(0), _g(0), _b(0), _a(0xFF) { }
	inline yColor(yuint8 red, yuint8 green, yuint8 blue, yuint8 alpha = 0xFF) : _r(red), _g(green), _b(blue), _a(alpha) { }
	inline yColor(yreal red, yreal green, yreal blue, yreal alpha = 1.f) : _r(yRound(red * 0xFF)), _g(yRound(green * 0xFF)), _b(yRound(blue * 0xFF)), _a(yRound(alpha * 0xFF)) { }
	inline explicit yColor(yRgb rgb) { setRgb(rgb); }
	inline explicit yColor(yRgb64 rgb) { setRgb64(rgb); }

	inline yRgb rgb() const { return rgb32(); }
	inline yRgb32 rgb32() const { return (_a << 24) + (_r << 16) + (_g << 8) + _b; }
	inline yRgb64 rgb64() const { return (yuint64(_a) << 48) + (yuint64(_r) << 24) + (yuint64(_g) << 16) + yuint64(_b); }
	inline void setRgb(yuint8 red, yuint8 green, yuint8 blue, yuint8 alpha = 0xFF) { _r = red; _g = green; _b = blue; _a = alpha; }
	inline void setRgb(yRgb rgb) { _a = (rgb >> 24) & 0xFF; _r = (rgb >> 16) & 0xFF; _g = (rgb >> 8) & 0xFF; _b = rgb & 0xFF; }
	inline void setRgbF(yreal red, yreal green, yreal blue, yreal alpha = 1.f) { _r = yRound(red * 0xFF); _g = yRound(green * 0xFF); _b = yRound(blue * 0xFF); _a = yRound(alpha * 0xFF); }
	inline void setRgb64(yRgb64 rgb) { _a = (rgb >> 48) & 0xFF; _r = (rgb >> 24) & 0xFF; _g = (rgb >> 16) & 0xFF; _b = rgb & 0xFF; }

	inline yuint8 red() const { return _r; }
	inline yuint8 green() const { return _g; }
	inline yuint8 blue() const { return _b; }
	inline yuint8 alpha() const { return _a; }
	inline yreal redF() const { return yreal(_r) / 0xFF; }
	inline yreal greenF() const { return yreal(_g) / 0xFF; }
	inline yreal blueF() const { return yreal(_b) / 0xFF; }
	inline yreal alphaF() const { return yreal(_a) / 0xFF; }

	inline void setRed(yuint8 red) { _r = red; }
	inline void setGreen(yuint8 green) { _g = green; }
	inline void setBlue(yuint8 blue) { _b = blue; }
	inline void setAlpha(yuint8 alpha) { _a = alpha; }
	inline void setRedF(yreal red) { _r = yRound(red * 0xFF); }
	inline void setGreenF(yreal green) { _g = yRound(green * 0xFF); }
	inline void setBlueF(yreal blue) { _b = yRound(blue * 0xFF); }
	inline void setAlphaF(yreal alpha) { _a = yRound(alpha * 0xFF); }

	yCmyk cmyk() const;
	void setCmyk(yuint8 cyan, yuint8 magenta, yuint8 yellow, yuint8 key, yuint8 alpha = 0xFF);
	inline void setCmyk(yCmyk cmyk) { setCmyk(cmyk.cyan, cmyk.magenta, cmyk.yellow, cmyk.key, cmyk.alpha); }
	inline void setCmykF(yreal cyan, yreal magenta, yreal yellow, yreal key, yreal alpha = 1.f) { setCmyk(yRound(cyan * 0xFF), yRound(magenta * 0xFF), yRound(yellow * 0xFF), yRound(key * 0xFF), yRound(alpha * 0xFF)); }

	inline yuint8 cyan() const { return cmyk().cyan; }
	inline yuint8 magenta() const { return cmyk().magenta; }
	inline yuint8 yellow() const { return cmyk().yellow; }
	inline yuint8 key() const { return cmyk().key; }
	inline yreal cyanF() const { return yreal(cmyk().cyan) / 0xFF; }
	inline yreal magentaF() const { return yreal(cmyk().magenta) / 0xFF; }
	inline yreal yellowF() const { return yreal(cmyk().yellow) / 0xFF; }
	inline yreal keyF() const { return yreal(cmyk().key) / 0xFF; }

	inline void setCyan(yuint8 cyan) { yCmyk v(cmyk()); setCmyk(cyan, v.magenta, v.yellow, v.key, v.alpha); }
	inline void setMagenta(yuint8 magenta) { yCmyk v(cmyk()); setCmyk(v.cyan, magenta, v.yellow, v.key, v.alpha); }
	inline void setYellow(yuint8 yellow) { yCmyk v(cmyk()); setCmyk(v.cyan, v.magenta, yellow, v.key, v.alpha); }
	inline void setKey(yuint8 key) { yCmyk v(cmyk()); setCmyk(v.cyan, v.magenta, v.yellow, key, v.alpha); }
	inline void setCyanF(yreal cyan) { setCyan(yRound(cyan * 0xFF)); }
	inline void setMagentaF(yreal magenta) { setMagenta(yRound(magenta * 0xFF)); }
	inline void setYellowF(yreal yellow) { setYellow(yRound(yellow * 0xFF)); }
	inline void setKeyF(yreal key) { setKey(yRound(key * 0xFF)); }

	yHsl hsl() const;
	// TODO: Implement functions for HSL -> RGB

	inline yuint16 hslHue() const { return hsl().hue; }
	inline yuint8 hslSaturation() const { return hsl().saturation; }
	inline yuint8 hslLightness() const { return hsl().lightness; }
	inline yreal hslHueF() const { return yreal(hsl().hue) / 360; }
	inline yreal hslSaturationF() const { return yreal(hsl().saturation) / 0xFF; }
	inline yreal hslLightnessF() const { return yreal(hsl().lightness) / 0xFF; }
	inline yuint8 lightness() const { return hslLightness(); }
	inline yreal lightnessF() const { return hslLightnessF(); }

	yHsv hsv() const;
	void setHsv(yuint16 hue, yuint8 saturation, yuint8 value, yuint8 alpha = 0xFF);
	inline void setHsv(yHsv hsv) { setHsv(hsv.hue, hsv.saturation, hsv.value, hsv.alpha); }
	inline void setHsvF(yreal hue, yreal saturation, yreal value, yreal alpha = 1.f) { setHsv(yRound(hue * 360), yRound(saturation * 0xFF), yRound(value * 0xFF), yRound(alpha * 0xFF)); }

	inline yuint16 hsvHue() const { return hsv().hue; }
	inline yuint8 hsvSaturation() const { return hsv().saturation; }
	inline yuint8 hsvValue() const { return hsv().value; }
	inline yreal hsvHueF() const { return yreal(hsv().hue) / 360; }
	inline yreal hsvSaturationF() const { return yreal(hsv().saturation) / 0xFF; }
	inline yreal hsvValueF() const { return yreal(hsv().value) / 0xFF; }
	inline yuint16 hue() const { return hsvHue(); }
	inline yreal hueF() const { return hsvHueF(); }
	inline yuint8 saturation() const { return hsvSaturation(); }
	inline yreal saturationF() const { return hsvSaturationF(); }
	inline yuint8 value() const { return hsvValue(); }
	inline yreal valueF() const { return hsvValueF(); }

	inline void setHsvHue(yuint16 hue) { yHsv v(hsv()); setHsv(hue, v.saturation, v.value, v.alpha); }
	inline void setHsvSaturation(yuint8 saturation) { yHsv v(hsv()); setHsv(v.hue, saturation, v.value, v.alpha); }
	inline void setHsvValue(yuint8 value) { yHsv v(hsv()); setHsv(v.hue, v.saturation, value, v.alpha); }
	inline void setHsvHueF(yreal hue) { setHsvHue(yRound(hue * 360)); }
	inline void setHsvSaturationF(yreal saturation) { setHsvSaturation(yRound(saturation * 0xFF)); }
	inline void setHsvValueF(yreal value) { setHsvValue(yRound(value * 0xFF)); }
	inline void setHue(yuint16 hue) { setHsvHue(hue); }
	inline void setSaturation(yuint8 saturation) { setHsvSaturation(saturation); }
	inline void setValue(yuint8 value) { setHsvValue(value); }
	inline void setHueF(yreal hue) { setHsvHueF(hue); }
	inline void setSaturationF(yreal saturation) { setHsvSaturationF(saturation); }
	inline void setValueF(yreal value) { setHsvValueF(value); }

private:
	yuint8 _r, _g, _b, _a;
};