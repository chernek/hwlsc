#include "windows.h"
#include "tchar.h"
#include "vector"

#include "funcs.h"

bool findTempFolders(std::vector <std::string>& tmpPaths)
{  
   using namespace std;
   
   tmpPaths.clear();   
   HKEY hKey;
   if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, _T("SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment"), 0, KEY_READ, &hKey) != ERROR_SUCCESS)
      return false; 
   char keyData[MAX_PATH];
   DWORD keyDataSz = MAX_PATH;
   string envStr;
   char* pVar;
   string regStr;
   if (RegQueryValueEx(hKey, _T("TEMP"), 0, 0, (LPBYTE) keyData, &keyDataSz) != ERROR_SUCCESS)
   {
      RegCloseKey(hKey);
      return false;         
   }
   else
   {
      keyData[keyDataSz] = '\0';      
      regStr = keyData;
      size_t ob = regStr.find('%');      
      if (ob != string::npos)
      {
         size_t cb = regStr.find('%', ob + 1);
         if (cb != string::npos)
         {
            string ts = regStr.substr(ob + 1, cb - 1);
            regStr.erase(ob, cb + 1);
            pVar = getenv(ts.c_str());  
            envStr = pVar;                      
         }
         regStr = envStr + regStr;
         tmpPaths.push_back(regStr);
      }
   }
   if (RegQueryValueEx(hKey, _T("TMP"), 0, 0, (LPBYTE) keyData, &keyDataSz) != ERROR_SUCCESS)
   {
      RegCloseKey(hKey);
      return false;         
   }
   else
   {
      keyData[keyDataSz] = '\0';
      regStr = keyData;
      size_t ob = regStr.find('%');      
      if (ob != string::npos)
      {
         size_t cb = regStr.find('%', ob + 1);
         if (cb != string::npos)
         {
            string ts = regStr.substr(ob + 1, cb - 1);
            regStr.erase(ob, cb + 1);
            pVar = getenv(ts.c_str());  
            envStr = pVar;                      
         }
         regStr = envStr + regStr;
         tmpPaths.push_back(regStr);
      }
   }
   pVar = getenv(_T("TEMP")); 
   if (!pVar)
      return false;
   else
   {      
      envStr = pVar;
      tmpPaths.push_back(envStr);
   }
   pVar = getenv(_T("TMP")); 
   if (!pVar)
      return false;
   else
   {
      envStr = pVar;      
      tmpPaths.push_back(envStr);
   }
   return true;
}
