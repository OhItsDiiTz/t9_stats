#pragma once
#include "../Main.h"


struct Addresses {
	unsigned __int64 gamemessage;
	uintptr_t getentity;
	uintptr_t getclientddl;
	uintptr_t livestats_getrootddl;
	uintptr_t movetopath;
	uintptr_t setint;
	uintptr_t setuint;
	uintptr_t getuint;
	uintptr_t weapondef;
	uintptr_t dvar_getint;
	uintptr_t a_7FF746BA84F0;
	uintptr_t a_7FF746BA83F0;
	uintptr_t a_7FF746BA8280;
	uintptr_t a_7FF746BA82F0;
	uintptr_t a_7FF746BA83B0;
	uintptr_t a_7FF746BA8370;
	uintptr_t a_7FF746BA86B0;
	uintptr_t dvar_791DD2801E54F59C;

	uintptr_t addweaponstat;
	uintptr_t addgametypestat; //E8 ?? ?? ?? ?? EB 5F 48 8B 44 24 ??
	uintptr_t addspecialiststat;
	uintptr_t addattachmentstat;
	uintptr_t addgroupstat;

	uintptr_t setclassitem;
	uintptr_t getmode;
	uintptr_t stringtable;
	uintptr_t getstatsbuffer;
	uintptr_t getitemquantity;
	uintptr_t lookupmoveto;
	uintptr_t actordamage;
	uintptr_t clientthinkreal;
	uintptr_t gettime;
	uintptr_t gettime_tableptr;
	uintptr_t addfloat;
	uintptr_t addint;
	uintptr_t level_time;
	uintptr_t migrationstate;
};

const char* AddressToPattern(uintptr_t address);

extern Addresses g_Addrs;

