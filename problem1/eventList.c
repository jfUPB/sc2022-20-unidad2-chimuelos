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
    this->last->next=event;
    this->last=event;
  }
}

void RemoveEvent(EventList *this, char *name)
{
 Event *remover=this->head; 
 Event *hola;
 if (this->isEmpty==0)
 {
  if (strcmp(name,this->head->eventName)==0)
  {
   remover= this->head->next;
   DestroyEvent(this->head); 
  }

  else
  {
    hola=this->head;
    this->head=this->head->next;

    while (this->head->next!=NULL)
    {
      if(strcmp(name,this->head->eventName)==0)
      {
        hola->next=this->head->next;
        DestroyEvent(this->head);
      }
      else
      {
        hola=hola->next;
        this->head=this->head->next;
      }
    }
  }
  if (strcmp(name,this->last->eventName)==0)
  {
    hola->next=NULL;
    DestroyEvent(this->last);
  }
  this->head=remover;
  

 
 }
   

}

void ListEvents(EventList *this)
{
 Event *recorrer;
   if (this->isEmpty==1)
   {
    printf("empty\n");
   }
   else
   {
    printf("%s\n",this->head->eventName);
    while (this->head->next!=NULL)
    {
      this->head=this->head->next;
      printf("%s\n",this->head->eventName);
    }
    this->head=recorrer;
    
    
   }
}
  
  

  





