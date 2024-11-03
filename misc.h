#pragma once

typedef unsigned char uchar;
typedef unsigned int uint;

#define TRACE_IN_USE

#ifdef TRACE_IN_USE
#define TRACE_OUTPUT(s) cout << s << endl;
#define TRACE_WITH_UINT(s, i) cout << s << i << endl;
#define TRACE_WITH_STR(s1, s2) cout << s1 << s2 << endl;
#else
#define TRACE_OUTPUT(s)
#define TRACE_WITH_UINT(s, i)
#define TRACE_WITH_STR(s1, s2)
#endif


#ifdef TRACE_IN_USE
#define TRACE(args) printf args;
#else
#define TRACE(args)
#endif
