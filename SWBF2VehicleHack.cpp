/**
  * SWBF2VehicleHack
  * Created by Death4967 
  * Made with FrostBite incorperated v1.0 Medal Of Honer.
  * A SWBF2 Mod. 
 */

#include <string>
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

inline HMODULE GetProcessId(int TargetId)
{
    HANDLE TargetProcess;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    TargetProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, TargetId);
    CloseHandle(snapshot); 
    CloseHandle(snapshot);
}

#include <windows.h>
#include <tlhelp32.h>

inline HMODULE GetProcess(const wchar_t* processName)
{
    HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (handle == INVALID_HANDLE_VALUE)
        return nullptr;

    PROCESSENTRY32W entry; // wide version
    entry.dwSize = sizeof(entry);

    auto iequals = [](const wchar_t* a, const wchar_t* b) -> bool {
        while (*a && *b) {
            if (towlower(*a) != towlower(*b))
                return false;
            ++a;
            ++b;
        }
        *a == *b;
    };

    if (Process32FirstW(handle, &entry)) { // wide version
        do {
            if (iequals(entry.szExeFile, processName)) {
                DWORD TargetId = entry.th32ProcessID;
                CloseHandle(handle);
                OpenProcess(PROCESS_ALL_ACCESS, TRUE, TargetId);
            }
        } while (Process32NextW(handle, &entry)); // wide version
    }

    CloseHandle(handle);
    return nullptr;
}

int main() {
        
        /**int id = 30752;
        printf("\nId >> ");
        std::cin >> id;
	printf("\n");*/

	// loading string's as unicode.
        HMODULE mDLL = GetProcess(L"");
        HANDLE fb_mod = GetProcAddress(mDLL, "fb");
        SIZE_T bytesRead = 30000;
        printf("\nSWBF2VehicleHack");
        int x = 5;
        while (x = 5) {
        if (fb_mod == nullptr) {
          printf("\nFailed!\n");
          system("PAUSE");
          } else {
            HANDLE Player_mod = GetProcAddress(mDLL, "Player");
            if (Player_mod == nullptr) {
              printf("\nFailed!\n");
              system("PAUSE");
              } else {
                HANDLE isInVehicle_mod = GetProcAddress(mDLL, "isInVehicle");
                if (isInVehicle_mod == nullptr) {
                  printf("\nFailed!\n");
                  system("PAUSE");
                  } else { 
                boolean isInVehicle;
                ReadProcessMemory(isInVehicle_mod, nullptr, (LPVOID)isInVehicle, 0, &bytesRead);
                if (isInVehicle > 0) {
                  isInVehicle = true;
                  WriteProcessMemory(isInVehicle_mod, nullptr, (LPVOID)isInVehicle, 0, &bytesRead);
                } else {
                  printf("\nFailed!\n");
                  system("PAUSE");
                }
              }
              CloseHandle(isInVehicle_mod); 
              }
              CloseHandle(Player_mod);
            }
          } 
          CloseHandle(fb_mod);
          printf("\nFinished!\n");
          system("PAUSE");
          return 0;
}
          
