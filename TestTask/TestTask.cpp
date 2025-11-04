#include "UserInterface.h"
#include <Windows.h>

int main()
{
   SetConsoleOutputCP(1251);
   SetConsoleCP(1251);

   UserInterface ui;
   ui.run();
   return 0;
}