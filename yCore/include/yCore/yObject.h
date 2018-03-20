#pragma once

#include <yCore/yCore.h>
#include <vector>

class yObject;
typedef std::vector<yObject*> yObjects;

class yCORE_API yObject
{
public:
	yObject(yObject * parent = nullptr);
	virtual ~yObject();

	inline yObject * parent() const { return _parent; }
	inline bool hasParent() const { return _parent; }
	void setParent(yObject * parent);
	inline yObjects children() const { return _children; }
	inline bool hasChildren() const { return !_children.empty(); }
	bool hasChild(yObject * object) const;
	void appendChild(yObject * object);
	inline void removeChildren() { _children.clear(); }
	void removeChild(yObject * object);

private:
	yObject * _parent;
	yObjects _children;
};