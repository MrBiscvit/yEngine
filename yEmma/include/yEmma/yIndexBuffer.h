#pragma once

#include <yEmma/yEmma.h>

class yEMMA_API yIndexBuffer
{
public:
	virtual ~yVertexBuffer();

private:
	class Private;
	Private * _p;
};