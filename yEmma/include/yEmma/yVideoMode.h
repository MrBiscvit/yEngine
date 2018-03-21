#pragma once

#include <yEmma/yEmma.h>
#include <yMath/yVector2D.h>
#include <yMath/yVector4D.h>

class yEMMA_API yVideoMode
{
public:
	inline yVideoMode() : _size(), _depth() { }
	inline yVideoMode(const yIntVector2D & size, const yIntVector4D & depth = yIntVector4D(8)) : _size(size), _depth(depth) { }
	inline yVideoMode(int width, int height, int depth) : _size(width, height), _depth(depth) { }

	inline yIntVector2D size() const { return _size; }
	inline int width() const { return _size.x(); }
	inline int height() const { return _size.y(); }
	inline void setSize(const yIntVector2D & size) { _size = size; }
	inline void setSize(int width, int height) { _size = yIntVector2D(width, height); }

	inline yIntVector4D pixelDepth() const { return _depth; }
	inline int redDepth() const { return _depth.x(); }
	inline int greenDepth() const { return _depth.y(); }
	inline int blueDepth() const { return _depth.z(); }
	inline int alphaDepth() const { return _depth.w(); }
	inline void setPixelDepth(int depth) { _depth = yIntVector4D(depth/4); }
	inline void setPixelDepth(const yIntVector4D & depth) { _depth = depth; }
	inline void setRedDepth(int depth) { _depth.setX(depth); }
	inline void setGreenDepth(int depth) { _depth.setY(depth); }
	inline void setBlueDepth(int depth) { _depth.setZ(depth); }
	inline void setAlphaDepth(int depth) { _depth.setW(depth); }

private:
	yIntVector2D _size;
	yIntVector4D _depth;
};