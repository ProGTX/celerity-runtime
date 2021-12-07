#pragma once

#include <assert.h>

typedef uint64_t uint64;
typedef uint32_t uint32;

#define MAX_CORES ((uint64)2048)
#define AFFINITY_MASK_BITS_PER_QUAD ((uint64)64)
#define AFFINTY_MASK_NUM_QUADS (MAX_CORES / AFFINITY_MASK_BITS_PER_QUAD)

struct _affinity_mask {
	uint64 mask_quads[AFFINTY_MASK_NUM_QUADS];
};

#ifdef _WIN32

#include <Windows.h>
#include <io.h>
typedef DWORD_PTR irt_native_cpu_set;

#else

#include <unistd.h>
typedef cpu_set_t native_cpu_set;

#endif

static native_cpu_set g_affinity_base_mask;

void affinity_int_base_mask();
uint32 affinity_cores_available();