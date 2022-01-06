#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "avion.h"


void createFlight(avion *Avion){
    char id[20]; 
    scanf("%s", id); 
    strcpy(Avion->identifiant,id);
    

}