#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"prototypes.h"

int main(int argc, char const *argv[])
{
    welcome();
    printf("\n   Saisir la date d'aujourd'hui \n");
	control_lireDate(&today);
	MenuPrincipal(today);
system("pause");
  return 0;
}
