#pragma once

#include <yEmma/yEmma.h>

class yEMMA_API yVertexBuffer
{
public:
	virtual ~yVertexBuffer();

private:
	class Private;
	Private * _p;
};