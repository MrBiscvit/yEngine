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

#include <yCore/yChrono.h>
#include <yCore/yMemory.h>

yNAMESPACE_BEGIN

typedef struct yon_chrono
{
	yon_time * last_time;
} yon_chrono;

yon_chrono * yon_create_chrono()
{
	yon_chrono * chrono = (yon_chrono*)yon_malloc(sizeof(yon_chrono));
	if (yCHECK_PTR(chrono)) {
		chrono->last_time = yon_create_time();
	}

	return chrono;
}
void yon_destroy_chrono(yon_chrono * chrono)
{
	if (yCHECK_PTR(chrono)) {
		yon_destroy_time(chrono->last_time);
		yon_free(chrono);
	}
}

void yon_start_chrono(yon_chrono * chrono)
{
	if (yCHECK_PTR(chrono)) {
		yon_get_current_time(chrono->last_time);
	}
}
yon_time * yon_restart_chrono(yon_chrono * chrono, yon_time * elapsed)
{
	yuint64 elapsedMilliseconds;
	if (yCHECK_PTR(chrono)) {
		yon_set_milliseconds(elapsed, yon_get_milliseconds(chrono->last_time));
		yon_get_current_time(chrono->last_time);
		elapsedMilliseconds = yon_get_milliseconds(chrono->last_time) - yon_get_milliseconds(elapsed);
		return yon_set_milliseconds(elapsed, elapsedMilliseconds);
	} else {
		return yNULLPTR;
	}
}
yon_time * yon_elapsed_chrono(yon_chrono * chrono, yon_time * elapsed)
{
	yon_time * currentTime = yon_create_time();
	if (yCHECK_PTR(chrono)) {
		yon_get_current_time(currentTime);
		yon_set_milliseconds(elapsed, yon_get_milliseconds(currentTime) - yon_get_milliseconds(chrono->last_time));
		yon_destroy_time(chrono->last_time);
		chrono->last_time = currentTime;
		return elapsed;
	} else {
		return yNULLPTR;
	}
}

yNAMESPACE_END