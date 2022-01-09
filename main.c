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
 system ("clear	"); 
 Affichage();
 display_total(time);
planning_arr(time);
 planning_dep(time);

 if(time%5 == 0){
     time++;
meteo();
 printf("\033[%d;%dH", 25, 70);
 printf("Hello take a look at the menu!! il est %d\n",time),
 printf("\033[%d;%dH", 28, 70);
 printf("1 - Ajouter un avion au décollage");
 printf("\033[%d;%dH", 30, 70);
 printf("2 - Ajouter un avion à l'attérissage");
 printf("\033[%d;%dH", 32, 70);
 printf("3 - Supprimer un avion au départ");
 printf("\033[%d;%dH", 34, 65);
 printf("Entrez la commande choisi : ");
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
        fuel(time);

        }
        
        else if(TTall(avion1)){
            printf("la piste est déjà prise\n");
        }

        break;
    case 3:
        delete_number_dep();
        printf("avion annulé\n");
        break;
 }
}
 time += 1;
 }
}
