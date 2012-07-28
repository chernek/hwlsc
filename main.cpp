#include "iostream"
#include "vector"
#include "set"
#include "tchar.h"

#include "funcs.h"
#include "main.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

std::set <char> mainActs;

char printGreet()
{
   using namespace std;
   
   string greetStr = "HwCleaner, ver. 27.07.2012";
	string eqStr = "";
	for (int i = 0;  i < greetStr.length();  ++i)
	{
		eqStr += '=';
	}		
	cout << greetStr << '\n' << eqStr << "\n\n\n";
	cout << "Choose action:\n\n";
	cout << "1 - Show temp folders\n";
	cout << "\nPress X to exit the program.\n\n" << "Action: ";
	char key;
	cin >> key;
	while (mainActs.find(key) == mainActs.end())
	{
      cout << "\nUnrecognized action. Please choose action again: ";
      cin >> key;
   }
	//int key = getwchar();
   return key;
}

void tempFoldersDialog()
{
   using namespace std;
   
   vector <string> tmpPaths;    
   if (!findTempFolders(tmpPaths))
   {
      cout << "\nTemporary folders not found.\n\n";
      break;
   }
   {
      vector <string>::iterator it = tmpPaths.begin();
      int i = 0;
      do
      {
         if (tmpPaths.at(i) == tmpPaths.at(i + 1))
         {                     
            tmpPaths.erase(tmpPaths.begin() + i);
            ++i;
         }
         else
            i += 2;
      }
      while (i < tmpPaths.size());
      set <char> tempActs;
      tempActs.insert('1');
      tempActs.insert('2');
      cout << "\n\nTemp folders list:\n\n";
      for (it = tmpPaths.begin();  it != tmpPaths.end();  ++it)
      {
         cout << *it << '\n';
      }      
      cout << "Choose action:\n\n";
   	cout << "1 - Clean temp folders\n";
   	cout << "2 - Return to main screen\n";
   	cout << "\nPress X to exit the program.\n\n" << "Action: ";
   	char key;
   	cin >> key;
   	while (acts.find(key) == acts.end())
   	{
         cout << "\nUnrecognized action. Please choose action again: ";
         cin >> key;
      }
      switch (key)
      {
           
      }
   }
}

int main(int argc, char *argv[]) 
{
   mainActs.insert('1');
	mainActs.insert('X');
   cts.insert('x');
	char key = printGreetDialog();
	switch (key)
	{
	   case '1':
      {
         tempFoldersDialog();   
      }
   }
   std::vector <std::string> tmpPaths;    
   if (findTempFolders(tmpPaths))
   {  
      std::vector <std::string>::iterator it = tmpPaths.begin();
      int i = 0;
      do
      {
         if (tmpPaths.at(i) == tmpPaths.at(i + 1))
         {                     
            tmpPaths.erase(tmpPaths.begin() + i);
            ++i;
         }
         else
            i += 2;
      }
      while (i < tmpPaths.size());
      for (it = tmpPaths.begin();  it != tmpPaths.end();  ++it)
      {
         std::cout << *it << '\n';
      }
   }
   _getwch();
   return 0;
}
