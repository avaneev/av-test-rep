#ifndef TEST_INCLUDED
#define TEST_INCLUDED

#if !defined( __cplusplus ) || __cplusplus < 201103L

	#include <stdint.h>
	#include <string.h>

	#define _U64_C( x ) (uint64_t) ( x )
	#define _NOEX

#else // __cplusplus

	#include <cstdint>
	#include <cstring>

	#define _U64_C( x ) UINT64_C( x )
	#define _NOEX noexcept

#endif // __cplusplus

#endif // TEST_INCLUDED
