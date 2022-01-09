#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "avion.h"



int main()
{
 int time = 0,x;
 avion avion1;
 while(time<1440){
     
 planning_arr(time);
 planning_dep(time);
 if(time%5 == 0){
 printf("Hello take a look at the menu!! il est %d\n",time),
 printf("1 - Ajouter un avion au décollage\n2 - Ajouter un avion à l'attérissage\n3 - Supprimer un avion au départ\n4 - Faîtes attérir un avion en priorité('U')\n");
 scanf("%d",&x);
 
 switch(x){
    case 1:
        
        avion1 = addAvionTK(time);
        if(TTall(avion1)==1){
        insert_depart(avion1);
        }
        
        else if(TTall(avion1)==0){
            printf("la piste est déjà prise\n");
        }
        break;
    case 2:
        avion1 = addAvionLand(time); 
        if(TTall(avion1)==1){
        insert_arriv(avion1);
        }
        
        else if(Timechek(avion1)==0 || TimechekLD(avion1)==0){
            printf("la piste est déjà prise\n");
        }
        break;
    case 3:
        delete_number_dep();
        printf("avion annulé\n");
        break;
    case 4:
        emergency(time);

 }
  display_total(time);
   fuel(time);
}
 time += 1;
 }
}
