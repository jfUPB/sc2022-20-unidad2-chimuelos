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

    Event *search=this->head;

    if (this->isEmpty==0)
    {
      while (search!=NULL)
      {
        if(strcmp(name,search->eventName)==0)
        {
          return search;
          search=search->next;
        }
      }

      
    }

    search=NULL;
    return search;

    

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

  if (this->isEmpty==0)
  {
    /* code */
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
  
  

  





