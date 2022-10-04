#include "Main.h"


uintptr_t ModuleBase;


DWORD(APIENTRY* GetCurrentThreadId_Stub)();
DWORD APIENTRY GetCurrentThreadId_Hook() {

	if (GetAsyncKeyState(VK_F6) & 1) {
		uintptr_t stats[2] = { 0x65FEBBDF3F1AB4D7, 0x6DA6061FD1E081BD };

		stats[1] = 0x6DA6061FD1E081BD;
		DDL_WriteStat(0, 0, 2, stats, 1333769);
		stats[1] = 0x23631E606828D668;
		DDL_WriteStat(0, 0, 2, stats, 1333769);
		stats[1] = 0x4CD85DA54E34F20A;
		DDL_WriteStat(0, 0, 2, stats, 1333769);
	}

	return GetCurrentThreadId_Stub();
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD Reason, LPVOID lpVoid) {

	if (Reason == DLL_PROCESS_ATTACH) {
		MH_Initialize();

		ModuleBase = (uintptr_t)GetModuleHandle(0);
		const char* BaseModule = ("BlackOpsColdWar.exe");

		g_Addrs.gamemessage = find_pattern(BaseModule, ("48 8B C4 48 83 EC 78 C7 40 ?? ?? ?? ?? ??"));
		nlog("g_Addrs.gamemessage: %p\n", g_Addrs.gamemessage);
		g_Addrs.getentity = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 48 8B D8 48 85 C0 75 18 45 33 C9"));
		g_Addrs.getentity = g_Addrs.getentity + *reinterpret_cast<signed int*>(g_Addrs.getentity + 1) + 5;
		nlog("g_Addrs.getentity: %p\n", g_Addrs.getentity);
		g_Addrs.getclientddl = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 4C 8B C3 48 8D 4D 97"));
		g_Addrs.getclientddl = g_Addrs.getclientddl + *reinterpret_cast<uint32_t*>(g_Addrs.getclientddl + 1) + 5;
		nlog("g_Addrs.getclientddl: %p\n", g_Addrs.getclientddl);
		g_Addrs.livestats_getrootddl = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 40 38 7D 30"));
		g_Addrs.livestats_getrootddl = g_Addrs.livestats_getrootddl + *reinterpret_cast<uint32_t*>(g_Addrs.livestats_getrootddl + 1) + 5;
		nlog("g_Addrs.livestats_getrootddl: %p\n", g_Addrs.livestats_getrootddl);
		g_Addrs.movetopath = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 4C 8D 4D 07 41 B8 ?? ?? ?? ??"));
		g_Addrs.movetopath = g_Addrs.movetopath + *reinterpret_cast<uint32_t*>(g_Addrs.movetopath + 1) + 5;
		nlog("g_Addrs.movetopath: %p\n", g_Addrs.movetopath);
		g_Addrs.setint = find_pattern(BaseModule, ("4C 8B C9 48 85 C9 74 3B"));
		nlog("g_Addrs.setint: %p\n", g_Addrs.setint);
		g_Addrs.setuint = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 8D 46 E3"));
		g_Addrs.setuint = g_Addrs.setuint + *reinterpret_cast<uint32_t*>(g_Addrs.setuint + 1) + 5;
		nlog("g_Addrs.setuint: %p\n", g_Addrs.setuint);

		g_Addrs.getuint = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 8D 78 01"));
		g_Addrs.getuint = g_Addrs.getuint + *reinterpret_cast<uint32_t*>(g_Addrs.getuint + 1) + 5;
		nlog("g_Addrs.getuint: %p\n", g_Addrs.getuint);

		g_Addrs.weapondef = find_pattern(BaseModule, ("48 8D 05 ?? ?? ?? ?? 48 8B 04 D8 48 85 C0 74 06"));
		g_Addrs.weapondef = g_Addrs.weapondef + *reinterpret_cast<uint32_t*>(g_Addrs.weapondef + 3) + 7;
		nlog("g_Addrs.weapondef: %p\n", g_Addrs.weapondef);

		g_Addrs.dvar_getint = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 0F B7 CE 44 8B F0"));
		g_Addrs.dvar_getint = g_Addrs.dvar_getint + *reinterpret_cast<signed int*>(g_Addrs.dvar_getint + 1) + 5;
		nlog("g_Addrs.dvar_getint: %p\n", g_Addrs.dvar_getint);
		g_Addrs.a_7FF746BA84F0 = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 0F B7 CF 4C 8B F0"));
		g_Addrs.a_7FF746BA84F0 = g_Addrs.a_7FF746BA84F0 + *reinterpret_cast<uint32_t*>(g_Addrs.a_7FF746BA84F0 + 1) + 5;
		nlog("g_Addrs.a_7FF746BA84F0: %p\n", g_Addrs.a_7FF746BA84F0);

		g_Addrs.a_7FF746BA83F0 = find_pattern(BaseModule, ("48 83 EC 48 66 85 C9"));
		nlog("g_Addrs.a_7FF746BA83F0: %p\n", g_Addrs.a_7FF746BA83F0);
		g_Addrs.a_7FF746BA8280 = find_pattern(BaseModule, ("48 83 EC 28 4C 0F BF C1"));
		nlog("g_Addrs.a_7FF746BA8280: %p\n", g_Addrs.a_7FF746BA8280);
		g_Addrs.a_7FF746BA82F0 = find_pattern(BaseModule, ("48 83 EC 28 66 85 C9"));
		nlog("g_Addrs.a_7FF746BA82F0: %p\n", g_Addrs.a_7FF746BA82F0);

		g_Addrs.a_7FF746BA83B0 = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 0F B7 CE 89 45 84"));
		g_Addrs.a_7FF746BA83B0 = g_Addrs.a_7FF746BA83B0 + *reinterpret_cast<uint32_t*>(g_Addrs.a_7FF746BA83B0 + 1) + 5;
		nlog("g_Addrs.a_7FF746BA83B0: %p\n", g_Addrs.a_7FF746BA83B0);
		g_Addrs.a_7FF746BA8370 = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 89 45 B0 45 85 F6"));
		g_Addrs.a_7FF746BA8370 = g_Addrs.a_7FF746BA8370 + *reinterpret_cast<uint32_t*>(g_Addrs.a_7FF746BA8370 + 1) + 5;
		nlog("g_Addrs.a_7FF746BA8370: %p\n", g_Addrs.a_7FF746BA8370);
		g_Addrs.a_7FF746BA86B0 = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 8B 4D 98 44 8B C0"));
		g_Addrs.a_7FF746BA86B0 = g_Addrs.a_7FF746BA86B0 + *reinterpret_cast<uint32_t*>(g_Addrs.a_7FF746BA86B0 + 1) + 5;
		nlog("g_Addrs.a_7FF746BA86B0: %p\n", g_Addrs.a_7FF746BA86B0);

		g_Addrs.dvar_791DD2801E54F59C = find_pattern(BaseModule, ("48 8B 0D ?? ?? ?? ?? E8 ?? ?? ?? ?? 0F B7 CE"));
		g_Addrs.dvar_791DD2801E54F59C = g_Addrs.dvar_791DD2801E54F59C + *reinterpret_cast<uint32_t*>(g_Addrs.dvar_791DD2801E54F59C + 3) + 7;
		nlog("g_Addrs.dvar_791DD2801E54F59C: %p\n", g_Addrs.dvar_791DD2801E54F59C);

		g_Addrs.addweaponstat = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 8B D5 89 44 24 50"));
		g_Addrs.addweaponstat = g_Addrs.addweaponstat + *reinterpret_cast<uint32_t*>(g_Addrs.addweaponstat + 1) + 5;
		nlog("g_Addrs.addweaponstat: %p\n", g_Addrs.addweaponstat);

		g_Addrs.addgametypestat = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? EB 5F 48 8B 44 24 ??"));
		g_Addrs.addgametypestat = g_Addrs.addgametypestat + *reinterpret_cast<uint32_t*>(g_Addrs.addgametypestat + 1) + 5;
		nlog("g_Addrs.addgametypestat: %p\n", g_Addrs.addgametypestat);

		g_Addrs.addspecialiststat = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 48 8B AC 24 ?? ?? ?? ?? 41 8B C4"));
		g_Addrs.addspecialiststat = g_Addrs.addspecialiststat + *reinterpret_cast<uint32_t*>(g_Addrs.addspecialiststat + 1) + 5;
		nlog("g_Addrs.addspecialiststat: %p\n", g_Addrs.addspecialiststat);

		g_Addrs.addattachmentstat = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? EB 1B 48 8B 44 24 ??"));
		g_Addrs.addattachmentstat = g_Addrs.addattachmentstat + *reinterpret_cast<signed int*>(g_Addrs.addattachmentstat + 1) + 5;
		nlog("g_Addrs.addattachmentstat: %p\n", g_Addrs.addattachmentstat);

		g_Addrs.addgroupstat = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 8B 44 24 70 EB 26"));
		g_Addrs.addgroupstat = g_Addrs.addgroupstat + *reinterpret_cast<signed int*>(g_Addrs.addgroupstat + 1) + 5;
		nlog("g_Addrs.addgroupstat: %p\n", g_Addrs.addgroupstat);

		g_Addrs.setclassitem = find_pattern(BaseModule, ("48 89 74 24 ?? 57 48 83 EC 50 83 BC 24 ?? ?? ?? ?? ??"));
		nlog("g_Addrs.setclassitem: %p\n", g_Addrs.setclassitem);
		g_Addrs.getmode = find_pattern(BaseModule, ("83 8E ?? ?? ?? ?? ?? E8 ?? ?? ?? ?? 83 F8 04"));
		g_Addrs.getmode += 7;
		g_Addrs.getmode = g_Addrs.getmode + *reinterpret_cast<uint32_t*>(g_Addrs.getmode + 1) + 5;
		nlog("g_Addrs.getmode: %p\n", g_Addrs.getmode);

		g_Addrs.stringtable = find_pattern(BaseModule, ("48 89 05 ?? ?? ?? ?? 41 B8 20 30 00 00 48 8B C8"));
		g_Addrs.stringtable = g_Addrs.stringtable + *reinterpret_cast<uint32_t*>(g_Addrs.stringtable + 3) + 7;
		nlog("g_Addrs.stringtable: %p\n", g_Addrs.stringtable);

		g_Addrs.getstatsbuffer = find_pattern(BaseModule, ("48 8B D8 E8 ?? ?? ?? ?? 45 33 C9 89 7C 24 20"));
		g_Addrs.getstatsbuffer += 3;
		g_Addrs.getstatsbuffer = g_Addrs.getstatsbuffer + *reinterpret_cast<signed int*>(g_Addrs.getstatsbuffer + 1) + 5;
		nlog("g_Addrs.getstatsbuffer: %p\n", g_Addrs.getstatsbuffer);

		g_Addrs.getitemquantity = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 42 38 BC 23 ?? ?? ?? ??"));
		g_Addrs.getitemquantity = g_Addrs.getitemquantity + *reinterpret_cast<uint32_t*>(g_Addrs.getitemquantity + 1) + 5;
		nlog("g_Addrs.getitemquantity: %p\n", g_Addrs.getitemquantity);

		g_Addrs.lookupmoveto = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? EB 8A 48 8D 4D 9F"));
		g_Addrs.lookupmoveto = g_Addrs.lookupmoveto + *reinterpret_cast<uint32_t*>(g_Addrs.lookupmoveto + 1) + 5;

		g_Addrs.actordamage = find_pattern(BaseModule, ("4C 8B DC 53 55 56 41 55 41 56"));
		nlog("g_Addrs.actordamage: %p\n", g_Addrs.actordamage);

		g_Addrs.clientthinkreal = find_pattern(BaseModule, ("E8 ?? ?? ?? ?? 80 3C 3E 00 48 8B B4 24 ?? ?? ?? ??"));
		g_Addrs.clientthinkreal = g_Addrs.clientthinkreal + *reinterpret_cast<uint32_t*>(g_Addrs.clientthinkreal + 1) + 5;
		nlog("g_Addrs.clientthinkreal: %p\n", g_Addrs.clientthinkreal);

		nlog("%p %p %p %p %p %p\n", g_Addrs.gamemessage, g_Addrs.getclientddl, g_Addrs.livestats_getrootddl, g_Addrs.movetopath, g_Addrs.setint, g_Addrs.setuint, g_Addrs.weapondef);
		uintptr_t currentthreadid = (uintptr_t)(GetProcAddress(GetModuleHandle("kernel32.dll"), "GetCurrentThreadId"));

		g_Addrs.gettime = find_pattern(BaseModule, ("8A 3B B6 4E"));
		g_Addrs.gettime += 16;
		g_Addrs.gettime_tableptr = g_Addrs.gettime;
		g_Addrs.gettime = *reinterpret_cast<uintptr_t*>(g_Addrs.gettime);
		nlog("g_Addrs.gettime: %p\n", g_Addrs.gettime);
		nlog("g_Addrs.gettime_tableptr: %p\n", g_Addrs.gettime_tableptr);

		g_Addrs.addfloat = find_pattern(BaseModule, "E9 ?? ?? ?? ?? 48 63 0C 16");
		g_Addrs.addfloat = g_Addrs.addfloat + *reinterpret_cast<uint32_t*>(g_Addrs.addfloat + 1) + 5;
		nlog("g_Addrs.addfloat: %p\n", g_Addrs.addfloat);

		g_Addrs.addint = g_Addrs.gettime;
		g_Addrs.addint += 7;
		g_Addrs.addint = g_Addrs.addint + *reinterpret_cast<signed int*>(g_Addrs.addint + 1) + 5;
		nlog("g_Addrs.addint: %p\n", g_Addrs.addint);

		g_Addrs.level_time = g_Addrs.gettime;
		g_Addrs.level_time = g_Addrs.level_time + *reinterpret_cast<uint32_t*>(g_Addrs.level_time + 3) + 7;
		nlog("g_Addrs.level_time: %p\n", g_Addrs.level_time);

		g_Addrs.migrationstate = find_pattern(BaseModule, ("48 8D 0D ?? ?? ?? ?? 48 69 C2 ?? ?? ?? ?? 33 D2"));
		g_Addrs.migrationstate = g_Addrs.migrationstate + *reinterpret_cast<uint32_t*>(g_Addrs.migrationstate + 3) + 7;
		nlog("g_Addrs.migrationstate: %p\n", g_Addrs.migrationstate);

		MH_CreateHookEx((void*)(currentthreadid), &GetCurrentThreadId_Hook, &GetCurrentThreadId_Stub);
		MH_EnableHook(MH_ALL_HOOKS);
		nlog("all hooks set!\n");
	}

	return TRUE;
}

template <typename T> inline MH_STATUS MH_CreateHookEx(LPVOID pTarget, LPVOID pDetour, T** ppOriginal) {
	return MH_CreateHook(pTarget, pDetour, reinterpret_cast<LPVOID*>(ppOriginal));
}

void nlog(const char* str, ...) {
	va_list ap;
	HWND notepad, edit;
	char buf[256];

	va_start(ap, str);
	vsprintf(buf, str, ap);
	va_end(ap);
	strcat(buf, "");
	notepad = FindWindowA(NULL, ("Untitled - Notepad"));
	if (!notepad)
		notepad = FindWindowA(NULL, ("*Untitled - Notepad"));

	edit = FindWindowEx(notepad, NULL, ("EDIT"), NULL);
	SendMessageA(edit, EM_REPLACESEL, 0, (LPARAM)buf);
}


uintptr_t find_pattern(const char* module_name, const char* pattern) {
	const auto get_module_size = [=](uintptr_t module_base)
	{
		return reinterpret_cast<PIMAGE_NT_HEADERS>(module_base + reinterpret_cast<PIMAGE_DOS_HEADER>(module_base)->e_lfanew)->OptionalHeader.SizeOfImage;
	};
	const auto module_start = (uintptr_t)GetModuleHandle(module_name);
	if (module_start != 0ULL)
	{
		const auto module_end = module_start + get_module_size(module_start);

		const char* pattern_current = pattern;
		uintptr_t current_match = NULL;

		MEMORY_BASIC_INFORMATION64 page_information = {};
		for (auto current_page = reinterpret_cast<unsigned char*>(module_start); current_page < reinterpret_cast<unsigned char*>(module_end); current_page = reinterpret_cast<unsigned char*>(page_information.BaseAddress + page_information.RegionSize))
		{
			VirtualQuery(reinterpret_cast<LPCVOID>(current_page), reinterpret_cast<PMEMORY_BASIC_INFORMATION>(&page_information), sizeof(MEMORY_BASIC_INFORMATION));
			if (page_information.Protect == PAGE_NOACCESS)
				continue;

			if (page_information.State != MEM_COMMIT)
				continue;

			if (page_information.Protect & PAGE_GUARD)
				continue;

			for (auto current_address = reinterpret_cast<unsigned char*>(page_information.BaseAddress); current_address < reinterpret_cast<unsigned char*>(page_information.BaseAddress + page_information.RegionSize - 0x8); current_address++)
			{
				if (*current_address != GET_BYTE(pattern_current) && *pattern_current != '\?') {
					current_match = 0ULL;
					pattern_current = pattern;
					continue;
				}

				if (!current_match)
					current_match = reinterpret_cast<uintptr_t>(current_address);

				pattern_current += 3;
				if (pattern_current[-1] == NULL)
					return current_match;
			}
		}
	}

	return 0ULL;
}
