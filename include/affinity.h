#pragma once

#ifdef _WIN32

#include <Windows.h>
#include <io.h>
typedef DWORD_PTR native_cpu_set;

#else

#include <unistd.h>
typedef cpu_set_t native_cpu_set;

#endif

static native_cpu_set g_affinity_base_mask;

void affinity_int_base_mask();
uint32_t affinity_cores_available();