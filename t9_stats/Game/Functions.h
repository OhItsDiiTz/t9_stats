#pragma once
#include "../Main.h"


struct DDLState;
struct unk_ddl_t;
struct unk_stat_t;
struct StringTable;

void CG_GameMessage(int localClientNum, const char* msg);


uintptr_t GetEntity(int clientNum);
uintptr_t GetClientDDLStats(int clientNum, int mode);
DDLState* LiveStats_GetRootDDLState(DDLState* state, uintptr_t context);
bool DDL_MoveToPath(DDLState* fromState, DDLState* toState, int argc, unk_ddl_t* path);
bool DDL_SetInt(const DDLState* state, uintptr_t ddlContext, int val);
bool DDL_SetUInt(const DDLState* state, uintptr_t ddlContext, uint32_t val);
uint32_t DDL_GetUInt(const DDLState* state, uintptr_t ddlContext);

uintptr_t LiveStorage_GetStatsBufferWithCaller(int localClientNum, const char* filestr, const char* funcstr, int line, int mode);

bool DDL_Lookup_IsArrayRoot(const DDLState* state);

void DDL_WriteStat(int clientNum, int mode, int argc, uintptr_t* stats, uint32_t value);
uint32_t DDL_ReadStat(int clientNum, int mode, int argc, uintptr_t* stats);

int Dvar_GetInt(uintptr_t dvar);

void sub_7FF74B7EA770(unk_stat_t* stat, uint16_t clientNum, int a3, int a4, int a5, int a6, uint8_t a7, uint8_t a8, uintptr_t a9);
int* sub_7FF746BA84F0(__int16 a1);
char sub_7FF746BA83F0(__int16 a1);
char sub_7FF746BA8280(__int16 a1, unsigned int a2);
__int64 sub_7FF746BA82F0(__int64 a1, int a2);
__int64 sub_7FF746BA83B0(__int16 a1);
__int64 sub_7FF746BA8370(__int16 a1);
__int64 sub_7FF746BA86B0(__int16 clientNum, int a2);

void AddWeaponStat(int clientNum, uintptr_t weaponHash, uint32_t weaponStatIndex, uintptr_t weaponStat, uintptr_t value);

void GScr_AddWeaponStatMoreInternal(uintptr_t playerEnt, __int16 playerNum, unk_stat_t* unk_struct, uintptr_t* weaponHashPtr, unsigned int weaponStatIndex, uintptr_t* weaponStatPtr, uintptr_t addValue, char* a8, bool a9);
void GScr_AddGameTypeStatInternal(uintptr_t playerEnt, unsigned __int16 clientNum, uintptr_t* statNamePtr, uintptr_t addValue);
void GScr_AddSpecialistStatInternal(uintptr_t entity, __int16 clientNum, unsigned int specialistNum, uintptr_t* statNamePtr, uintptr_t addValue);
void GScr_AddAttachmentStatInternal(uintptr_t playerEnt, unsigned __int16 playerNum, unsigned int attachmentIndex, uintptr_t* StatHashPtr, uintptr_t addValue, bool a6);
void GScr_AddGroupStatInternal(uintptr_t playerEnt, unsigned __int16 clientNum, unsigned int groupIndex, uintptr_t* statNamePtr, uintptr_t addValue, bool a6);

int SetClassItem(__int64 luaVM, unsigned int localClientNum, unsigned int ClassIndex, const char* slotName, unsigned int itemId, unsigned int mode);

int Com_SessionMode_GetMode();

const char* StringTable_GetColumnValueForRow(const StringTable* table, const int row, const int column);

void G_DamageActor(uintptr_t targ, uintptr_t inflictor, uintptr_t attacker, const float* dir, const float* point, int damage, int dflags, int mod, __int64 weapon, __int64 a10, int a11, float* a12, int a13, __int16 a14, int a15, char a16, __int64 a17);

double Abs(const float* v);
float Vec3Distance(const float* v1, const float* v2);
int getNearestZombie(int clientNum);

void ScrVm_AddFloat(int inst, float val);
void ScrVm_AddInt(int inst, int val);

bool sub_7FF74CA7E9F0(int a1);
