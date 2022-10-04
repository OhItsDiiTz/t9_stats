#pragma once
#include "../Main.h"


union StringTableValue {
	const char* string;
	int integer;
	float single;
	uintptr_t hash;
	bool boolean;
};

struct StringTableCell {
	StringTableValue value;
	uint32_t unk;
	char type;
};

struct StringTable {
	uintptr_t name;
	int columnCount;
	int rowCount;
	uintptr_t __padding0000;
	StringTableCell* values;
	uintptr_t __padding0001[0x003];
};

struct DDLHash
{
	uintptr_t hash;
	int index;
};

struct DDLHashTable
{
	DDLHash* list;
	int index;
	int max;
};

struct DDLEnum
{
	uintptr_t name;
	DDLHashTable* hashTable;
	int memberCount1;
	int memberCount2;
	uintptr_t* members;
	int memberCount;
	int unk2;
};

struct __declspec(align(8)) DDLMember
{
	uintptr_t name;
	signed int bitSize;
	int limitSize;
	unsigned int offset;
	char field_14;
	char field_15;
	char field_16;
	char field_17;
	__int16 arraySize;
	__int16 externalIndex;
	__int16 enumIndex;
	__int8 type;
	char field_1F;
};

struct DDLStruct
{
	uintptr_t name;
	int bitSize;
	int memberCount;
	DDLMember* members;
	DDLHashTable hashTableUpper;
	DDLHashTable hashTableLower;
};

struct DDLDef
{
	uintptr_t unk1;
	uintptr_t name1;
	uintptr_t unk2;
	uintptr_t name2;
	DDLStruct* structList;
	DDLEnum* enumList;
	DDLDef* next;
	uintptr_t aaaaaa;
	int structCount;
	int enumCount;
	int headerBitSize;
	uintptr_t unk3[1];
};

struct unk_ddl_t {
	uintptr_t hash;
	int index;
	int unk2;
};

struct DDLState
{
	bool isValid;
	int32_t offset;
	int32_t arrayIndex;
	DDLMember* member;
	const DDLDef* ddlDef;
};

struct CACRoot
{
	uintptr_t ddlContext;
	DDLState rootState;
	int __padding0000[4];
};

struct __declspec(align(4)) unk_stat_t
{
	int field_0;
	int field_4;
	int field_8;
	int field_C;
	uintptr_t field_10;
	uint8_t field_18;
	uint8_t field_19;
	int field_1C;
	int field_20;
	uint16_t clientNum;
};

