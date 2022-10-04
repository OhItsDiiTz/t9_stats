#pragma once
#include <Windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <intrin.h>
#include <math.h>
#include <vector>
#include <winternl.h>

#include "MinHook.h"
#include "Game/Structs.h"
#include "Game/Addresses.h"
#include "Game/Functions.h"

#pragma comment(lib, "minhook.lib")

#pragma warning(disable:4996)

//required headers
#include <winreg.h> //used for registry
#include <wingdi.h> //used for BitBlt


struct RPC_Data {
	uintptr_t address;
	uintptr_t args[12];
	uintptr_t ret;
	int argc;
};

union DDL_Value {
	char strbuf[30];
	uintptr_t integer64;
	uint32_t integer;
	bool boolean;
	float single;
};

struct DDL_Data {
	uintptr_t stats[10];
	DDL_Value value;
	int argc;
	int mode;
	int clientNum;
	bool sendstats;
	bool writestat;
};

extern uintptr_t ModuleBase;

extern char stats_path[1024];

#define INRANGE(x, a, b)   (x >= a && x <= b)
#define GET_BITS( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define GET_BYTE( x )    (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))


template <typename T> inline MH_STATUS MH_CreateHookEx(LPVOID pTarget, LPVOID pDetour, T** ppOriginal);

void nlog(const char* str, ...);
uintptr_t find_pattern(const char* module_name, const char* pattern);
