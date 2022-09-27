# sc2022-20-unidad2-chimuelos
sc2022-20-unidad2-chimuelos created by GitHub Classroom

## Ana María Díaz Rocha
## Josue Quinche Parra
## Juan Esteban Montoya Gómez - 424817
## Sara Londoño Orrego




   EventList *CreateEventList(void) //Ya esto lo dió el profe en clase

{

    EventList *eventList = malloc(sizeof(EventList));
 
    eventList->isEmpty = 1;
 
    eventList->head = NULL;
 
    eventList->last = NULL;
 
    return eventList;
 
}



void DestroyEventList(EventList *this) //Aquí se libera memoria, destruyendo un evento de la lista

{

    free(this); //el comando free libera memoria y recibe como parámetro el evento en específico DE LA LISTA que va a destruir, botar, sacar, pulverizar
  
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
    while (añadir!=NULL)
    {
      if (strcmp(añadir->eventName, event->eventName)==0)
      {
        return;
      } 
      añadir=añadir->next;
      
    }
    
    this->last->next=event;
    this->last=event;
  }
}

void RemoveEvent(EventList *this, char *name)
{
 
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
