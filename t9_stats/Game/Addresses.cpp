#include "Addresses.h"



const char* AddressToPattern(uintptr_t address) {
	char buffer[100];
	sprintf(buffer, "%X %X %X %X %X %X %X %X", (address) & 0xFF, (address >> 8) & 0xFF, (address >> 16) & 0xFF, (address >> 24) & 0xFF, (address >> 32) & 0xFF, (address >> 40) & 0xFF, (address >> 48) & 0xFF, (address >> 56) & 0xFF);
	return buffer;
}

Addresses g_Addrs;

