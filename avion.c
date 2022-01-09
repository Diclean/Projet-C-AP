#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "avion.h"

struct Depart
{
   avion data;
   struct Depart *next_dep;
}*front_dep = NULL,*rear_dep = NULL;

struct Arrive
{
   avion data;
   struct Arrive *next_arr;
}*front_arr = NULL,*rear_arr = NULL;

struct Liste_Compagnie
{
    avion data;
    struct Liste_Compagnie *next_flight;
}*front_flight = NULL, *rear_flight = NULL;


avion addAvionTK(int time){
    avion Avion1;
    printf("Immatriculation du véhicule: ");
    scanf("%s", Avion1.identifiant);
    printf("Depart dans : ");
    scanf("%d",&Avion1.heure);
    while(Avion1.heure<=time){
        printf("C'est trop tard\n");
        printf("Entrez un nouvelle horaire xx:xx : ");
        scanf("%d:%d", &Avion1.heure);
    }
    Avion1.timeS = time;
    Avion1.request = 'D';
    return Avion1;
}

avion addAvionLand(int time){
    avion Avion1;
    printf("Immatriculation du véhicule: ");
    scanf("%s", Avion1.identifiant);
    printf("Niveau de Fuel : ");
    scanf("%d",&Avion1.carburant);
    printf("Consomation en vol : ");
    scanf("%d",&Avion1.consommation);
    printf("Heure d'attérissage dans : ");
    scanf("%d",&Avion1.heure);
    while(Avion1.heure<=time){
        printf("C'est déjà passé\n");
        printf("Entrez de nouveau le timer : ");
        scanf("%d", &Avion1.heure);
    }
    Avion1.request = 'L';
    Avion1.timeS = time;
    return Avion1;
}

void insert_depart(avion avion1)
{
   struct Depart *newDepart;
   newDepart = (struct Depart*)malloc(sizeof(struct Depart));
   newDepart->data = avion1;
   newDepart -> next_dep = NULL;
   if(front_dep == NULL)
      front_dep = rear_dep = newDepart;
    else{
      if(newDepart->data.heure>front_dep->data.heure)
      {
          rear_dep -> next_dep = newDepart;
          rear_dep = newDepart;
      }

    if(newDepart->data.heure<front_dep->data.heure)
      {
          newDepart->next_dep=front_dep;
          front_dep=newDepart;
      }
      else{
          printf("Ce n'est pas possible\n");
      }
      }
    }

void insert_arriv(avion avion1)
{
   struct Arrive *newarriv,*temp;
   newarriv = (struct Arrive*)malloc(sizeof(struct Arrive));
   newarriv->data = avion1;
   newarriv -> next_arr = NULL;
   if(front_arr == NULL)
      front_arr = rear_arr = newarriv;
    else{
        if(newarriv->data.heure<front_arr->data.heure)
      {
          rear_arr -> next_arr = newarriv;
          rear_arr = newarriv;
      }

    if(newarriv->data.heure>front_arr->data.heure)
      {
          newarriv->next_arr=front_arr;
          front_arr=newarriv;
      }

    }
   printf("\nFlight added.\n");
}

void delete_first()
{
   if(front_dep == NULL)
      printf("\nThere isn't any flight.\n");
   else{
      struct Depart *temp = front_dep;
      front_dep = front_dep -> next_dep;
      printf("\nDeleted flight: %s\n", temp->data.identifiant);
      free(temp);
   }
}

void delete_number()
{
   int check;
   char todelete[7];
   if(front_dep == NULL)
      printf("\nThere isn't any flight to delete.\n");
   else{
      struct Depart *temp = front_dep;
      scanf("%s",&todelete);
      check=strcmp(temp->data.identifiant,todelete);
      while(check!=0)
      {
          temp = temp -> next_dep;
          check=strcmp(temp->data.identifiant,todelete);
      }
      if(check==0)
      {
          front_dep = front_dep -> next_dep;
          printf("\nDeleted flight: %s\n", temp->data.identifiant);
          free(temp);
      }

   }
}
void delete_number_dep()
{
   int check;
   char todelete[7];
   if(front_dep == NULL)
      printf("\nThere isn't any flight to delete.\n");
   else{
      struct Depart *temp = front_dep,*temp1;
      scanf("%s",&todelete);
      check=strcmp(temp->data.identifiant,todelete);
      if(temp->next_dep==NULL)
      {
          front_dep = front_dep -> next_dep;
          free(temp);
      }
      while(temp->next_dep !=NULL && check!=0)
      {
          if(temp->next_dep==NULL)
            printf("Didn't find");
          temp1=temp;
          temp=temp->next_dep;
          check=strcmp(temp->data.identifiant,todelete);
      }
      temp1->next_dep=temp->next_dep;
   }
}

void display_depart()
{
   if(front_dep == NULL)
      printf("\nThere are no plane ready to take off.\n");
   else{
      struct Depart *temp = front_dep;
      while(temp->next_dep != NULL){
            printf("%s--%d\n",temp->data.identifiant,temp->data.heure);
            temp = temp -> next_dep;
                               }
      printf("%s-%c-%d\n",temp->data.identifiant,temp->data.request,temp->data.heure);
   }
}

//function which display the arrivals
void display_arriv()
{
   if(front_arr == NULL)
      printf("\nThere are no plane ready to land.\n");
   else{
      struct Arrive *temp = front_arr;
      while(temp->next_arr != NULL){
            printf("%s-%c-%d-%d\n",temp->data.identifiant,temp->data.request,temp->data.carburant,temp->data.consommation);
            temp = temp -> next_arr;
                               }
      printf("%s-%c-%d-%d\n",temp->data.identifiant,temp->data.carburant,temp->data.consommation);
   }
}

//function which display all the flights (departure & arrivals)
void display_total(int time)
{
    if(front_dep == NULL)
      printf("\nThere aren't any planes planned to take off.\n\n");
    else{
      struct Depart *temp = front_dep;
      printf("------------DEPARTURE------------\n");
      while(temp->next_dep != NULL){
            printf("%s-%c-%d\n",temp->data.identifiant,temp->data.request,(temp->data.heure)-time);
            temp = temp -> next_dep;
                               }
      printf("%s-%c-%d\n",temp->data.identifiant,temp->data.request,(temp->data.heure)-time);
   }
   if(front_arr == NULL)
      printf("\nThere aren't any planes planned to land.\n\n");
    else{
      struct Arrive *temp = front_arr;
      printf("------------ARRIVAL------------\n");
      while(temp->next_arr != NULL){
            printf("%s-%d-%d\n",temp->data.identifiant,(temp->data.carburant)-(time-(temp->data.timeS)),temp->data.consommation);
            temp = temp -> next_arr;
                               }
      printf("%s-%c-%d-%d\n",temp->data.identifiant,temp->data.request,(temp->data.carburant)-(time-(temp->data.timeS)),temp->data.consommation);
   }
}

//function which prioritize the flights when you enter the ID
void emergency(int time)
{
    int check;
   char toprioritize[7];
   if(front_arr == NULL)
      printf("\nPas d'avion en prio.\n");
   else{
      struct Arrive *temp = front_arr;
      scanf("%s",&toprioritize);
      check=strcmp(temp->data.identifiant,toprioritize);
      while(check!=0)
      {
          temp = temp -> next_arr;
          check=strcmp(temp->data.identifiant,toprioritize);
      }
      if(check==0)
      {
          temp->data.request='U';
          printf("\nAvion Priorisé: %s\n", temp->data.identifiant);
            int time = temp->data.heure;
            printf("%d result Timecheck",TimechekLD((temp->data)));
          
      }
    temp = front_arr;

   }
}

//funtion which check with the time if a plane must take off according to its time of takeoff
void planning_dep(int time)
{
    if(front_dep !=NULL)
    {
        struct Depart *temp = front_dep;
        while(temp != NULL)
        {
            if((temp->data.heure)<=time)
            {

                front_dep = front_dep -> next_dep;
                printf("\nThis flight took off: %s\n", temp->data.identifiant);
                break;

            }
            else{
                temp = temp -> next_dep;
                }
        }
    }
}

//funtion which check with the time if a plane must land
void planning_arr(int time)
{
    if(front_arr !=NULL)
    {
        struct Arrive *temp = front_arr;
        while(temp != NULL)
        {
            if((temp->data.heure)<=time )
            {

                front_arr = front_arr -> next_arr;
                printf("\nThis flight landed: %s\n", temp->data.identifiant);
                break;

            }
            else{
                temp = temp -> next_arr;
                }
        }
    }
}

//funtion which check if a plane have enough fuel to achieve its flight, if not, the function prioritized the flights
void fuel(int time)
{
    if(front_arr !=NULL)
    {
        struct Arrive *temp = front_arr;
        while(temp != NULL)
        {
            if(temp->data.consommation*(((temp->data.heure)-time)<temp->data.carburant))
            {
                temp->data.request='U';
                break;

            }
            else{
                temp = temp -> next_arr;
                }
        }
    }
}

int Timechek(avion avion1){
   if(front_dep == NULL){
    return 1;
   }
    else{
      struct Depart *temp = front_dep;
      while(temp != NULL){
            if((temp->data.heure)==(avion1.heure)){
                return 0;
            }
            temp = temp -> next_dep;
   }
   return 1;
}
}
int TimechekLD(avion avion1){
    if(front_arr !=NULL)
    {
        struct Arrive *temp = front_arr;
        while(temp != NULL)
        {
            if((temp->data.heure) == (avion1.heure) )
            {   
                return 0;
            }
            else{
                temp = temp -> next_arr;
                }
        }
    }
    return 1;
   }


int TTall(avion avion1,int time){
if(Timechek(avion1)==1 && TimechekLD(avion1)==1){
    return 1;
}
else{
    return 0;
}
}
