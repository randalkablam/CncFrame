#pragma once
#ifdef __linux__
#define OS_LINUX
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;

typedef void* FuncParam_t;

typedef char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;

#elif _WIN32

#define OS_WINDOWS
#include <windows.h>
#include <stdint.h>

#else
#define OS_RTOS
#define uint8_t unsigned char ;
#define uint16_t unsigned short ;
#define uint32_t DWORD;
#define uint64_t unsigned long long;

#define FuncParam_t LPVOID;


#define int8_t char;
#define int16_t short;
#define int32_t int;
#define int64_t long;
#endif

#define SYS_TICK_INTERVAL 10 // SysTick interval in  msec

