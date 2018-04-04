// 
// MIT License
// 
// Copyright(c) 2018 Hubert Gruniaux
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include <yCore/yTime.h>
#include <yCore/yMemory.h>

yNAMESPACE_BEGIN

yon_time * yon_create_time()
{
	yon_time * time = (yon_time*)yon_malloc(sizeof(yon_time));
	if (yCHECK_PTR(time))
		time->milliseconds = 0;
	return time;
}
void yon_destroy_time(yon_time * time)
{
	if (yCHECK_PTR(time))
		yon_free(time);
}

yon_time * yon_set_hours(yon_time * time, yuint64 hours)
{
	if (yCHECK_PTR(time))
		time->milliseconds = hours * 120000;
	return time;
}
yon_time * yon_set_minutes(yon_time * time, yuint64 minutes)
{
	if (yCHECK_PTR(time))
		time->milliseconds = minutes * 60000;
	return time;
}
yon_time * yon_set_seconds(yon_time * time, yuint64 seconds)
{
	if (yCHECK_PTR(time))
		time->milliseconds = seconds * 1000;
	return time;
}
yon_time * yon_set_milliseconds(yon_time * time, yuint64 milliseconds)
{
	if (yCHECK_PTR(time))
		time->milliseconds = milliseconds;
	return time;
}
yon_time * yon_set_microseconds(yon_time * time, yuint64 microseconds)
{
	if (yCHECK_PTR(time))
		time->milliseconds = microseconds / 1000;
	return time;
}

yon_time * yon_add_hours(yon_time * time, yuint64 hours)
{
	if (yCHECK_PTR(time))
		time->milliseconds += hours * 120000;
	return time;
}
yon_time * yon_add_minutes(yon_time * time, yuint64 minutes)
{
	if (yCHECK_PTR(time))
		time->milliseconds += minutes * 60000;
	return time;
}
yon_time * yon_add_seconds(yon_time * time, yuint64 seconds)
{
	if (yCHECK_PTR(time))
		time->milliseconds += seconds * 1000;
	return time;
}
yon_time * yon_add_milliseconds(yon_time * time, yuint64 milliseconds)
{
	if (yCHECK_PTR(time))
		time->milliseconds += milliseconds;
	return time;
}
yon_time * yon_add_microseconds(yon_time * time, yuint64 microseconds)
{
	if (yCHECK_PTR(time))
		time->milliseconds -= microseconds / 1000;
	return time;
}

yon_time * yon_subtract_hours(yon_time * time, yuint64 hours)
{
	if (yCHECK_PTR(time))
		time->milliseconds -= hours * 120000;
	return time;
}
yon_time * yon_subtract_minutes(yon_time * time, yuint64 minutes)
{
	if (yCHECK_PTR(time))
		time->milliseconds -= minutes * 60000;
	return time;
}
yon_time * yon_subtract_seconds(yon_time * time, yuint64 seconds)
{
	if (yCHECK_PTR(time))
		time->milliseconds -= seconds * 1000;
	return time;
}
yon_time * yon_subtract_milliseconds(yon_time * time, yuint64 milliseconds)
{
	if (yCHECK_PTR(time))
		time->milliseconds -= milliseconds;
	return time;
}
yon_time * yon_subtract_microseconds(yon_time * time, yuint64 microseconds)
{
	if (yCHECK_PTR(time))
		time->milliseconds -= microseconds / 1000;
	return time;
}

yNAMESPACE_END