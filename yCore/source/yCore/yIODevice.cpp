#include <yCore/yIODevice.h>

yByteArray yIODevice::read(yint64 maxSize)
{
	char * data = (char*) malloc(maxSize * sizeof(char));
	read(data, maxSize);
	yByteArray array(data);
	free(data);
	return array;
}