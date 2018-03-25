#include <yEmma/yColor.h>

yCmyk yColor::cmyk() const
{
	yCmyk cmyk;

	cmyk.key = 1 - yMax(_r, yMax(_g, _b));
	cmyk.cyan = (1 - _r - cmyk.key) / (1 - cmyk.key);
	cmyk.magenta = (1 - _g - cmyk.key) / (1 - cmyk.key);
	cmyk.yellow = (1 - _b - cmyk.key) / (1 - cmyk.key);
	cmyk.alpha = _a;

	return cmyk;
}
void yColor::setCmyk(yuint8 cyan, yuint8 magenta, yuint8 yellow, yuint8 key, yuint8 alpha)
{
	_r = (1 - cyan) * (1 - key);
	_g = (1 - magenta) * (1 - key);
	_b = (1 - yellow) * (1 - key);
	_a = alpha;
}

yHsl yColor::hsl() const
{
	yHsl hsl;

	const yreal r(redF()), g(greenF()), b(blueF());
	const yreal max = yMax(r, yMax(g, b));
	const yreal min = yMin(r, yMin(g, b));
	const yreal delta = max - min;
	const yreal delta2 = max + min;
	const yreal lightness = 0.5f * delta2;

	hsl.lightness = yRound(lightness * 0xFF);
	hsl.alpha = _a;
	if (delta == 0.f) {
		hsl.hue = 0xFFFF;
		hsl.saturation = 0;
	} else {
		yreal hue = 0;
		if (lightness < 0.5f)
			hsl.saturation = yRound((delta / delta2) * 0xFF);
		else
			hsl.saturation = yRound((delta / (2.f - delta2)) * 0xFF);
		if (r == max) {
			hue = ((g - b) / delta);
		} else if (g == max) {
			hue = (2.f + (b - r) / delta);
		} else if (b == max) {
			hue = (4.f + (r - g) / delta);
		}
		hue *= 60.f;
		if (hue < 0.f)
			hue += 360.f;
		hsl.hue = yRound(hue * 100);
	}
		
	return hsl;
}

yHsv yColor::hsv() const
{
	yHsv hsv;

	const yreal r(redF()), g(greenF()), b(blueF());
	const yreal max = yMax(r, yMax(g, b));
	const yreal min = yMin(r, yMin(g, b));
	const yreal delta = max - min;

	hsv.value = yRound(max * 0xFF);
	hsv.alpha = _a;
	if (delta == 0.f) {
		hsv.hue = 0xFFFF;
		hsv.saturation = 0;
	} else {
		yreal hue = 0.f;
		hsv.saturation = yRound((delta / max) * 0xFF);
		if (r == max) {
			hue = ((g - b) / delta);
		} else if (g == max) {
			hue = (2.f + (b - r) / delta);
		} else if (b == max) {
			hue = (4.f + (r - g) / delta);
		}
		hue *= 60.f;
		if (hue < 0.f)
			hue += 360.f;
		hsv.hue = yRound(hue * 100);
	}

	return hsv;
}
void yColor::setHsv(yuint16 hue, yuint8 saturation, yuint8 value, yuint8 alpha)
{
	if (saturation = 0 || hue == 0xFFFF) {
		_r = _g = _b = value;
		_a = alpha;
		return;
	}

	const yreal h = hue == 36000 ? 0.f : hue / 6000.f;
	const yreal s = yreal(saturation / 0xFF);
	const yreal v = yreal(value / 0xFF);
	const int i = int(h);
	const yreal f = h - i;
	const yreal p = v * (1.f - s);

	if (i & 1) {
		const yreal q = v * (1.f - (s * f));

		switch (i) {
		case 1:
			_r = yRound(q * 0xFF);
			_g = yRound(v * 0xFF);
			_b = yRound(p * 0xFF);
			break;
		case 3:
			_r = yRound(p * 0xFF);
			_g = yRound(q * 0xFF);
			_b = yRound(v * 0xFF);
			break;
		case 5:
			_r = yRound(v * 0xFF);
			_g = yRound(p * 0xFF);
			_b = yRound(q * 0xFF);
			break;
		}
	} else {
		const yreal t = v * (1.f - (s * (1.f - f)));

		switch (i) {
		case 0:
			_r = yRound(v * 0xFF);
			_g = yRound(t * 0xFF);
			_b = yRound(p * 0xFF);
			break;
		case 2:
			_r = yRound(p * 0xFF);
			_g = yRound(v * 0xFF);
			_b = yRound(t * 0xFF);
			break;
		case 4:
			_r = yRound(t * 0xFF);
			_g = yRound(p * 0xFF);
			_b = yRound(v * 0xFF);
			break;
		}
	}
}