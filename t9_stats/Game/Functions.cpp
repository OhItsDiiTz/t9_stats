#include "Functions.h"


void CG_GameMessage(int localClientNum, const char* msg) {
	auto func = reinterpret_cast<void(*)(int, const char*)>(g_Addrs.gamemessage);
	func(localClientNum, msg);
}

uintptr_t GetEntity(int clientNum) {
	auto func = reinterpret_cast<uintptr_t(*)(int)>(g_Addrs.getentity);
	return func(clientNum);
}

uintptr_t GetClientDDLStats(int clientNum, int mode) {
	auto func = reinterpret_cast<uintptr_t(*)(int, int)>(g_Addrs.getclientddl);
	return func(clientNum, mode);
}

DDLState* LiveStats_GetRootDDLState(DDLState* state, uintptr_t context) {
	auto func = reinterpret_cast<DDLState * (*)(DDLState*, uintptr_t)>(g_Addrs.livestats_getrootddl);
	return func(state, context);
}

bool DDL_MoveToPath(DDLState* fromState, DDLState* toState, int argc, unk_ddl_t* path) {
	auto func = reinterpret_cast<bool(*)(DDLState*, DDLState*, int, unk_ddl_t*)>(g_Addrs.movetopath);
	return func(fromState, toState, argc, path);
}

bool DDL_SetInt(const DDLState* state, uintptr_t ddlContext, int val) {
	auto func = reinterpret_cast<bool(*)(const DDLState*, uintptr_t, int)>(g_Addrs.setint);
	return func(state, ddlContext, val);
}

bool DDL_SetUInt(const DDLState* state, uintptr_t ddlContext, uint32_t val) {
	auto func = reinterpret_cast<bool(*)(const DDLState*, uintptr_t, uint32_t)>(g_Addrs.setuint);
	return func(state, ddlContext, val);
}

uint32_t DDL_GetUInt(const DDLState* state, uintptr_t ddlContext) {
	auto func = reinterpret_cast<uint32_t(*)(const DDLState*, uintptr_t)>(g_Addrs.getuint);
	return func(state, ddlContext);
}




uintptr_t LiveStorage_GetStatsBufferWithCaller(int localClientNum, const char* filestr, const char* funcstr, int line, int mode) {
	auto func = reinterpret_cast<uintptr_t(*)(int, const char*, const char*, int, int)>(g_Addrs.getstatsbuffer);
	return func(localClientNum, filestr, funcstr, line, mode);
}

bool DDL_Lookup_IsArrayRoot(const DDLState* state) {
	DDLMember* member = state->member;
	return member && member->field_1F && member->enumIndex == -1 && state->arrayIndex == -1;
}

void DDL_WriteStat(int clientNum, int mode, int argc, uintptr_t* stats, uint32_t value) {
	DDLState state;
	uintptr_t context;

	if (clientNum != 123) {
		context = GetClientDDLStats(clientNum, mode);
	}
	else {
		context = LiveStorage_GetStatsBufferWithCaller(0, "", "", 0, mode);
	}

	if (context != 0) {
		LiveStats_GetRootDDLState(&state, context);

		unk_ddl_t* path = (unk_ddl_t*)malloc(sizeof(unk_ddl_t) * argc);
		for (int i = 0; i < argc; i++) {
			path[i].hash = stats[i];
			path[i].index = -1;
		}

		if (DDL_MoveToPath(&state, &state, argc, path)) {
			nlog("attempting to write to %p\n", stats[1]);
			if (DDL_SetUInt(&state, context, value)) {
				nlog("set %i to %p with success\n", value, stats[1]);
			}
		}
		free(path);
	}
}

uint32_t DDL_ReadStat(int clientNum, int mode, int argc, uintptr_t* stats) {
	DDLState state;
	uintptr_t context;

	if (clientNum != 123) {
		context = GetClientDDLStats(clientNum, mode);
	}
	else {
		context = LiveStorage_GetStatsBufferWithCaller(0, "", "", 0, mode);
	}

	if (context != 0) {
		LiveStats_GetRootDDLState(&state, context);

		unk_ddl_t* path = (unk_ddl_t*)malloc(sizeof(unk_ddl_t) * argc);
		for (int i = 0; i < argc; i++) {
			path[i].hash = stats[i];
			path[i].index = -1;
		}

		if (DDL_MoveToPath(&state, &state, argc, path)) {
			free(path);
			nlog("attempting to read to %p\n", stats[1]);
			return DDL_GetUInt(&state, context);
		}

	}
}


int Dvar_GetInt(uintptr_t dvar) {
	auto func = reinterpret_cast<int(*)(uintptr_t)>(g_Addrs.dvar_getint);
	return func(dvar);
}

void sub_7FF74B7EA770(unk_stat_t* stat, uint16_t clientNum, int a3, int a4, int a5, int a6, uint8_t a7, uint8_t a8, uintptr_t a9) {
	stat->field_8 = a5;
	stat->field_C = a6;
	stat->field_10 = a9;
	stat->field_18 = a7;
	stat->field_19 = a8;
	*&stat->field_1C = 0i64;
	stat->field_0 = a3;
	stat->field_4 = a4;
	stat->clientNum = clientNum;
}

int* sub_7FF746BA84F0(__int16 a1) {
	auto func = reinterpret_cast<int* (*)(__int16)>(g_Addrs.a_7FF746BA84F0);
	return func(a1);
}

char sub_7FF746BA83F0(__int16 a1) {
	auto func = reinterpret_cast<char(*)(__int16)>(g_Addrs.a_7FF746BA83F0);
	return func(a1);
}

char sub_7FF746BA8280(__int16 a1, unsigned int a2) {
	auto func = reinterpret_cast<char(*)(__int16, unsigned int)>(g_Addrs.a_7FF746BA8280);
	return func(a1, a2);
}

__int64 sub_7FF746BA82F0(__int64 a1, int a2) {
	auto func = reinterpret_cast<__int64(*)(__int64, int)>(g_Addrs.a_7FF746BA82F0);
	return func(a1, a2);
}

__int64 sub_7FF746BA83B0(__int16 a1) {
	auto func = reinterpret_cast<__int64(*)(__int16)>(g_Addrs.a_7FF746BA83B0);
	return func(a1);
}

__int64 sub_7FF746BA8370(__int16 a1) {
	auto func = reinterpret_cast<__int64(*)(__int16)>(g_Addrs.a_7FF746BA8370);
	return func(a1);
}

__int64 sub_7FF746BA86B0(__int16 clientNum, int a2) {
	auto func = reinterpret_cast<__int64(*)(__int16, int)>(g_Addrs.a_7FF746BA86B0);
	return func(clientNum, a2);
}

void AddWeaponStat(int clientNum, uintptr_t weaponHash, uint32_t weaponStatIndex, uintptr_t weaponStat, uintptr_t value) {
	unk_stat_t stat;
	int dvarval = Dvar_GetInt(*reinterpret_cast<uintptr_t*>(g_Addrs.dvar_791DD2801E54F59C));
	sub_7FF74B7EA770(&stat, clientNum, sub_7FF746BA86B0(clientNum, dvarval), sub_7FF746BA8370(clientNum), sub_7FF746BA83B0(clientNum), sub_7FF746BA82F0(clientNum, dvarval), sub_7FF746BA8280(clientNum, dvarval), sub_7FF746BA83F0(clientNum), (uintptr_t)sub_7FF746BA84F0(clientNum));
	GScr_AddWeaponStatMoreInternal(GetEntity(clientNum), clientNum, &stat, &weaponHash, weaponStatIndex, &weaponStat, value, 0, 1);
}

void GScr_AddWeaponStatMoreInternal(uintptr_t playerEnt, __int16 playerNum, unk_stat_t* unk_struct, uintptr_t* weaponHashPtr, unsigned int weaponStatIndex, uintptr_t* weaponStatPtr, uintptr_t addValue, char* a8, bool a9) {
	auto func = reinterpret_cast<void(*)(uintptr_t playerEnt, __int16 playerNum, unk_stat_t * unk_struct, uintptr_t * weaponHashPtr, unsigned int weaponStatIndex, uintptr_t * weaponStatPtr, uintptr_t addValue, char* a8, bool a9)>(g_Addrs.addweaponstat);
	func(playerEnt, playerNum, unk_struct, weaponHashPtr, weaponStatIndex, weaponStatPtr, addValue, a8, a9);
}

void GScr_AddGameTypeStatInternal(uintptr_t playerEnt, unsigned __int16 clientNum, uintptr_t* statNamePtr, uintptr_t addValue) {
	auto func = reinterpret_cast<void(*)(uintptr_t, unsigned __int16, uintptr_t*, uintptr_t)>(g_Addrs.addgametypestat);
	func(playerEnt, clientNum, statNamePtr, addValue);
}

void GScr_AddSpecialistStatInternal(uintptr_t entity, __int16 clientNum, unsigned int specialistNum, uintptr_t* statNamePtr, uintptr_t addValue) {
	auto func = reinterpret_cast<void(*)(uintptr_t, __int16, unsigned int, uintptr_t*, uintptr_t)>(g_Addrs.addspecialiststat);
	func(entity, clientNum, specialistNum, statNamePtr, addValue);
}

void GScr_AddAttachmentStatInternal(uintptr_t playerEnt, unsigned __int16 playerNum, unsigned int attachmentIndex, uintptr_t* StatHashPtr, uintptr_t addValue, bool a6) {
	auto func = reinterpret_cast<void(*)(uintptr_t, unsigned __int16, unsigned int, uintptr_t*, uintptr_t, bool)>(g_Addrs.addattachmentstat);
	func(playerEnt, playerNum, attachmentIndex, StatHashPtr, addValue, a6);
}

void GScr_AddGroupStatInternal(uintptr_t playerEnt, unsigned __int16 clientNum, unsigned int groupIndex, uintptr_t* statNamePtr, uintptr_t addValue, bool a6) {
	auto func = reinterpret_cast<void(*)(uintptr_t, unsigned __int16, unsigned int, uintptr_t*, uintptr_t, bool)>(g_Addrs.addgroupstat);
	func(playerEnt, clientNum, groupIndex, statNamePtr, addValue, a6);
}


int SetClassItem(__int64 luaVM, unsigned int localClientNum, unsigned int ClassIndex, const char* slotName, unsigned int itemId, unsigned int mode) {
	auto func = reinterpret_cast<int(*)(__int64, unsigned int, unsigned int, const char*, unsigned int, unsigned int)>(g_Addrs.setclassitem);
	return func(luaVM, localClientNum, ClassIndex, slotName, itemId, mode);
}

int Com_SessionMode_GetMode() {
	auto func = reinterpret_cast<int(*)()>(g_Addrs.getmode);
	return func();
}


const char* StringTable_GetColumnValueForRow(const StringTable* table, const int row, const int column) {
	char buf[80];

	if (table->columnCount <= column || (row | column) < 0 || table->rowCount <= row)
		return "null";
	int v4 = column + table->columnCount * row;
	const char* result = "null";
	memset(buf, 0, 80);
	switch (table->values[v4].type) {
	case 1:
		return table->values[v4].value.string;
		break;

	case 2:
	case 7:
	case 8:
		_snprintf(buf, 80, "%p", table->values[v4].value.hash);
		return buf;
		break;
	case 4:
		_snprintf(buf, 80, "%i", table->values[v4].value.integer);
		return buf;
		break;
	case 5:
		_snprintf(buf, 80, "%f", table->values[v4].value.single);
		return buf;
		break;
	case 6:
		_snprintf(buf, 80, "%s", table->values[v4].value.boolean ? "true" : "false");
		return buf;
		break;
	default:
		return "";
		break;
	}

	return "";
}

void G_DamageActor(uintptr_t targ, uintptr_t inflictor, uintptr_t attacker, const float* dir, const float* point, int damage, int dflags, int mod, __int64 weapon, __int64 a10, int a11, float* a12, int a13, __int16 a14, int a15, char a16, __int64 a17) {
	auto func = reinterpret_cast<void(*)(uintptr_t, uintptr_t, uintptr_t, const float*, const float*, int, int, int, __int64, __int64, int, float*, int, __int16, int, char, __int64)>(g_Addrs.actordamage);
	func(targ, inflictor, attacker, dir, point, damage, dflags, mod, weapon, a10, a11, a12, a13, a14, a15, a16, a17);
}

double Abs(const float* v)
{
	return (float)sqrt((float)((float)((float)(v[0] * v[0]) + (float)(v[1] * v[1])) + (float)(v[2] * v[2])));
}

float Vec3Distance(const float* v1, const float* v2)
{
	float dir[3];

	dir[0] = v2[0] - v1[0];
	dir[1] = v2[1] - v1[1];
	dir[2] = v2[2] - v1[2];
	return Abs(dir);
}

int getNearestZombie(int clientNum) {
	float dist = 99999999;
	int nearest;
	uintptr_t me = GetEntity(clientNum);
	for (int i = 0; i < 1024; i++) {
		uintptr_t ent = GetEntity(i);
		if (*reinterpret_cast<short*>(ent + 0x282) == 15) {
			uintptr_t actor = *reinterpret_cast<uintptr_t*>(ent + 0x300);
			if (actor) {
				if (*reinterpret_cast<char*>(actor + 0x6B4)) {
					float distance = Vec3Distance((float*)(ent + 0x2D4), (float*)(me + 0x2D4));
					if (distance <= dist) {
						dist = distance;
						nearest = i;
					}
				}
			}
		}
	}
	return nearest;
}

void ScrVm_AddFloat(int inst, float val) {
	auto func = reinterpret_cast<void(*)(int, float)>(g_Addrs.addfloat);
	func(inst, val);
}

void ScrVm_AddInt(int inst, int val) {
	auto func = reinterpret_cast<void(*)(int, int)>(g_Addrs.addint);
	func(inst, val);
}

bool sub_7FF74CA7E9F0(int a1) {

	switch (a1)
	{
	case 1:
	case 8:
	case 10:
	case 12:
	case 23:
	case 24:
	case 45:
		return true;
	default:
		return false;
	}
}

