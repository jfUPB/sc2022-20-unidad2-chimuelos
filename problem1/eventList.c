#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
 EventList *eventList = malloc(sizeof(EventList));
 eventList->isEmpty = 1;
 eventList->head = NULL;
 eventList->last = NULL;
 return eventList;
}

void DestroyEventList(EventList *this)
{
  free(this); 
}

Event *SearchEvent(EventList *this, char *name)
{
 Event *event = this->head;
        if (this->isEmpty == 0)
        {
           while (event != NULL)
          {
              if (strcmp(name, event->eventName)==0)
              return event;
              event = event->next;
          }
        }
     event = NULL;
     return event;
}

void AddEvent(EventList *this, Event *event)
{
 
 if (this->isEmpty==1)
    {
      this->isEmpty=0;
      this->head=event;
      this->head->next=NULL;
      this->last=event;
      this->last->next=NULL;
    }
  else
  {
    Event *añadir=this->head;
    while (añadir!=NULL) //
    {
      if (strcmp(añadir->eventName, event->eventName)==0) //Escanea el coso y dice, el que se esta agregando y el evento son iguales
      {
        //si entra significa que ya existe
        return; //Lo saca del void
      } 
      añadir=añadir->next; //Este es el contador
      
    }
    //EN caso que ya no sean iguales, pasa para acá

    
    this->last->next=event;
    this->last=event;
  }
}

void RemoveEvent(EventList *this, char *name)
{
/*
 
 Event *actual=this->head; 
 Event *siguiente;
 if (this->isEmpty==0)
 {
  if (strcmp(name,this->head->eventName)==0)
  {
   actual= this->head->next;
   DestroyEvent(this->head); 
  }

  else
  {
    siguiente=this->head;
    this->head=this->head->next;

    while (this->head->next!=NULL)
    {
      if(strcmp(name,this->head->eventName)==0)
      {
        siguiente->next=this->head->next;
        DestroyEvent(this->head);
      }
      else
      {
        siguiente=siguiente->next;
        this->head=this->head->next;
      }
    }
  }
  if (strcmp(name,this->last->eventName)==0)
  {
    siguiente->next=NULL;
    DestroyEvent(this->last);
  }
  this->head=actual;
 }


Este código sirve pero no corre las pruebas 6, 18 y 19, básicamente porque la primera condición revisa el primer elemento
la segunda el del medio y la ultima el ultimo, pero para lo que piden las pruebas nanay mi rey asi no se puede.
Debemos corregir 
 */
   
   if (this->isEmpty == 0) //Revisión de que la lista no esté vacía, es decir contenga algo
    {
         Event *actual = this->head->next;
         Event *anterior = this->head;
         if(strcmp(name, anterior->eventName)==0)
         {
              if(anterior->next == NULL)
              {
                    this->head = NULL;
                    this->last = NULL;
                    this->isEmpty = 1;
                    DestroyEvent(anterior);
              }
              else
              {
                    this->head=actual;
                    DestroyEvent(anterior);
              }
         }
         while (actual != NULL)
         {
              if(strcmp(name, actual->eventName)==0)
              {
                   anterior->next = actual->next;
                   if (this->last->next == NULL)
                   {
                        this->last = anterior;
                        DestroyEvent(actual);
                   }
              }
              anterior = actual;
              actual = actual->next;
         }
    }
}


void ListEvents(EventList *this)
{
 
 
   if (this->isEmpty==1)
   {
    printf("empty\n");
   }
   else
   {
    Event *recorrer=this->head;
    while (recorrer!=NULL)
    {
      printf("%s\n",recorrer->eventName);
      recorrer=recorrer->next;
    }
    
    
   }
}
  
  

  





