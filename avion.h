#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct avion avion;
struct avion
{
    char identifiant[7];
    int carburant;
    int consommation;
    int heure;
    char request;
    int timeS;
    char compagnie[3];
};
typedef struct compagnie compagnie;
struct compagnie
{
   char Name[7];
};

avion addAvionTK(int time);
avion addAvionLand(int time);
void fuel();
void BL();
void planning_arr(int time);
void planning_dep(int time);
void emergency(int time);
void display_total(int time);
void display_arriv();
void display_depart();
void delete_number_dep();
void delete_number();
void delete_first_added();
void insert_arriv(avion avion1);
void insert_depart(avion avion1);
int Timechek(avion avion1);
int TimechekLD(avion avion1);
int TTall(avion avion1);
