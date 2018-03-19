#include <yCore/yGlobal.h>

void _yon_assert(const char * assertion, const char * file, int line) throw()
{
	std::fprintf(stderr, "ASSERT: \"%s\" in file %s, line %i", assertion, file, line);
	std::abort();
}
void _yon_assert_x(const char * where, const char * what, const char * file, int line) throw()
{
	std::fprintf(stderr, "ASSERT failure in %s: \"%s\", file %s, line %i", where, what, file, line);
	std::abort();
}