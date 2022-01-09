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
    avion identifiant;
    struct Liste_Compagnie *next_flight;
}*front_flight = NULL, *rear_flight = NULL;

void insert_Avion(Compagnie)

avion addAvionTK(int time){
    avion Avion1;
    printf("Immatriculation du véhicule: ");
    scanf("%s", Avion1.identifiant);
    printf("Depart pour : ");
    scanf("%d:%d",&Avion1.heure,&Avion1.minute);
    while(Avion1.heure<=time/60 && Avion1.minute<=time%60);{
        printf("C'est trop tard\n");
        printf("Entrez un nouvelle horaire xx:xx : ");
        scanf("%d:%d", &Avion1.heure,&Avion1.minute);
    }
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
    printf("Heure d'attérissage : ");
        scanf("%d:%d",&Avion1.heure,&Avion1.minute);
    while(Avion1.heure<=time/60 && Avion1.minute<=time%60);{
        printf("C'est déjà passé\n");
        printf("Entrez un nouvelle horaire xx:xx : ");
        scanf("%d:%d", &Avion1.heure,&Avion1.minute);
    }
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

    if(newDepart->data.heure==front_dep->data.heure)
      {
         if(newDepart->data.minute>front_dep->data.minute)
      {
          rear_dep -> next_dep = newDepart;
          rear_dep = newDepart;
      }
    if(newDepart->data.minute<front_dep->data.minute)
      {
          newDepart->next_dep=front_dep;
          front_dep=newDepart;
      }
      }
    }
}
void insert_arriv(avion avion1)
{
   struct Arrive *newarriv,*temp;
   newarriv = (struct Depart*)malloc(sizeof(struct Depart));
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
          printf("\nDeleted flight: %s\n", temp->data.identifiant);
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
            printf("%s--%d%d\n",temp->data.identifiant,temp->data.heure,temp->data.minute);
            temp = temp -> next_dep;
                               }
      printf("%s-%c-%d%d\n",temp->data.identifiant,temp->data.request,temp->data.heure,temp->data.minute);
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
void display_total()
{
    if(front_dep == NULL)
      printf("\nThere aren't any planes planned to take off.\n\n");
    else{
      struct Depart *temp = front_dep;
      printf("------------DEPARTURE------------\n");
      while(temp->next_dep != NULL){
            printf("%s-%c-%d%d\n",temp->data.identifiant,temp->data.request,temp->data.heure,temp->data.minute);
            temp = temp -> next_dep;
                               }
      printf("%s-%c-%d%d\n",temp->data.identifiant,temp->data.request,temp->data.heure,temp->data.minute);
   }
   if(front_arr == NULL)
      printf("\nThere aren't any planes planned to land.\n\n");
    else{
      struct Arrive *temp = front_arr;
      printf("------------ARRIVAL------------\n");
      while(temp->next_arr != NULL){
            printf("%s-%d-%d\n",temp->data.identifiant,temp->data.carburant,temp->data.consommation);
            temp = temp -> next_arr;
                               }
      printf("%s-%c-%d-%d\n",temp->data.identifiant,temp->data.request,temp->data.carburant,temp->data.consommation);
   }
}

//function which prioritize the flights when you enter the ID
void emergency()
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
      }

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
            if(((temp->data.heure)*60)+(temp->data.minute)<=time )
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
            if(((temp->data.heure)*60)+(temp->data.minute)<=time )
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
            if(temp->data.consommation*((((temp->data.heure)*60)+(temp->data.minute))-time)<temp->data.carburant)
            {
                temp->data.request='U';
                printf("\nThis flight become a priority to land !: %s\n", temp->data.identifiant);
                break;

            }
            else{
                temp = temp -> next_arr;
                }
        }
    }
}