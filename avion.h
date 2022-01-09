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
    int minute;
    char request;

};
typedef struct compagnie compagnie;
struct compagnie
{
   char Name[7];
};

avion addAvionTK(int time);
avion addAvionLand(int time);
void fuel();
void planning_arr(int time);
void planning_dep(int time);
void emergency();
void display_total();
void display_arriv();
void display_depart();
void delete_number_dep();
void delete_number();
void delete_first_added();
void insert_arriv(avion avion1);
void insert_depart(avion avion1);
