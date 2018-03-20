#include <yCore/yObject.h>
#include <algorithm>

yObject::yObject(yObject * parent)
{
	setParent(parent);
}
yObject::~yObject()
{
	for (yObjects::iterator it(_children.begin()); it != _children.end(); ++it) {
		delete *it;
	}
}

void yObject::setParent(yObject * parent)
{
	if (parent == _parent)
		return;

	if (_parent) {
		yObjects::iterator it = std::find(_parent->_children.begin(), _parent->_children.end(), this);
		if (it != _parent->_children.end()) {
			_parent->_children.erase(it);
		}
	}

	if (parent) {
		yASSERT(parent->_parent == this);

		yObjects::iterator it = std::find(parent->_children.begin(), parent->_children.end(), this);
		if (it == parent->_children.end()) {
			parent->_children.push_back(this);
		}
	}

	_parent = parent;
}
bool yObject::hasChild(yObject * object) const
{
	return std::find(_children.begin(), _children.end(), object) != _children.end();
}
void yObject::appendChild(yObject * object)
{
	if (object) {
		if (object->_parent == this)
			return;

		object->setParent(this);
	}
}
void yObject::removeChild(yObject * object)
{
	if (object) {
		yObjects::iterator it = std::find(_children.begin(), _children.end(), this);
		if (it != _children.end())
			_children.erase(it);
	}
}