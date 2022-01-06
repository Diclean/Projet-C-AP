#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct cellule_avion Cellule_avion;
typedef struct
{
    char nom[7];
    char acronyme[3];
    Cellule_avion* ListeAvion;
}Compagnie;

typedef struct
{
    char identifiant[7];
    int carburant;
    int consommation;
    char heure_decollage[3];
    Compagnie* compagnie;
}avion;

typedef struct cellule_avion
{
    avion Avion;
    struct cellule_avion* suivant_compagnie;
    struct cellule_avion* precedent_compagnie;
    struct cellule_avion* suivant_attente;
}Cellule_avion;

typedef Cellule_avion* Liste_Avion;

typedef struct Queue
{
    Cellule_avion* first;
    Cellule_avion* last;
}Queue;

typedef struct cellule_compagnie
{
    Compagnie* compagnie;
    struct cellule_compagnie* suivant;
}Cellule_compagnie;

typedef Cellule_compagnie* Liste_Compagnie;

typedef struct cellule_blacklist
{
    char name[10];
    struct cellule_blacklist* suivant;
}Cellule_blacklist;

typedef Cellule_blacklist* Liste_blacklist;

void createFlight();