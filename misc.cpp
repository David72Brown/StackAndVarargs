#include <random>
#include <time.h>
#include <stdarg.h>
#include "misc.h"
#include "assert.h"

#ifdef TRACE_IN_USE
#define MAX_TRACE_LEN 1024
void OutputTrace(const char *FmtStr, ...)
{
	char buffer[MAX_TRACE_LEN +1];
	va_list args;
	va_start(args, FmtStr);
	vsprintf_s (buffer, MAX_TRACE_LEN, FmtStr, args);
	printf(buffer);
	printf("\n");
	va_end(args);
}
#endif
