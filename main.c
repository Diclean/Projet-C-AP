#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "avion.h"



int main()
{
 int time = 0;
 while(time<10){
printf("Hello take a look at the menu!!\n"),
 avion Avion1;
 Avion1 = addAvionTK(time);
 insert_depart(Avion1);
 display_total();
 }
}
