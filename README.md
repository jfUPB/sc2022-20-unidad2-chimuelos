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

  Event *event = this->head; //Puntero que está apuntando al head
 
        if (this->isEmpty == 0) //si hay algo en la lista, entra
        
        {
        
           while (event != NULL) // Mientras en el head exista algo
        
          {
          
              if (strcmp(name, event->eventName)==0) //compara el name con el event.name, y si son iguales
              
              return event; //Devuelve al puntero
              
              event = event->next; //este es el contador, hace que recorra
              
          }
          
        }
        
     event = NULL; //Si no hay nada en la lista, el contenido del puntero será nulo
     
     return event; // devuelve al puntero
     
}

void AddEvent(EventList *this, Event *event)
{
  
 if (this->isEmpty==1) //Si la lista está vacía
 
    {
    
      this->isEmpty=0; //se crea la lista
      
      this->head=event; //en el head se pone el evento
      
      this->head->next=NULL; //El evento que sigue va a ser NULL
      
      this->last=event; //En el last, como esta condicion solo funciona para el primer evento añadido entonces ese evento será el primero y el unico
      
      this->last->next=NULL; //como es el unico tons lo siguiente a este también será nulo
      
    }
    
  else
  
  {
  
    Event *añadir=this->head; //si la lista contiene algo, se crea un puntero de tipo EVENT que contiene al head
    
    while (añadir!=NULL) //mientras en el head exista algo
    
    {
    
      if (strcmp(añadir->eventName, event->eventName)==0) //compara el nombre del puntero con el del evento actual, y si son iguales
      
      {
      
        return; // saca de todo
        
      } 
      
      añadir=añadir->next;// contador (lo que hace que recorra)
      
    }
    
    this->last->next=event; //el evento que entra va a ser el siguiente al last
    
    this->last=event; //a medida que se van añadiendo se van rodando, tons el evento que entra pasa a ser la cola 
    
  }
  
}

void RemoveEvent(EventList *this, char *name)
{
 
   if (this->isEmpty == 0) //Revisión de que la lista no esté vacía, es decir contenga algo
   
    {
         Event *actual = this->head->next; //puntero de tipo event que apunta al evento siguiente en el head
         
         Event *anterior = this->head; //puntero de tipo event que apunta al head
         
         if(strcmp(name, anterior->eventName)==0) //compara el nombre que se pide en la funcion como parametro con el nombre del evento actual
         
         {
              if(anterior->next == NULL) //si el evento que le sigue al actual es NULO
              
              {
                    this->head = NULL; //EL head queda nulo
                    
                    this->last = NULL;//EL last queda nulo
                    
                    this->isEmpty = 1;//LA LISTA QUEDA VACÍA
                    
                    DestroyEvent(anterior); //Se destruye el evento actual
                    
              }
              
              else
              
              {
                    this->head=actual; //en el head se pone lo que está en el puntero siguiente, es decir se rueda hacia atrás el evento
                    
                    DestroyEvent(anterior); //se destruye el evento actual
                    
              }
              
         }
         
         while (actual != NULL) //mientras el evento siguiente no sea nulo
         
         {
              if(strcmp(name, actual->eventName)==0) //compara el nombre del evento que recibe como parametro con el nombre del evento siguiente
              
              {
                   anterior->next = actual->next;//aquí se van enlazando los eventos para que el que se destruya no acabe con la cadena
                   
                   if (this->last->next == NULL) //si el evento siguiente al ultimo es nulo
                   
                   {
                        this->last = anterior; //entonces el ultimo evento será el evento siguiente en el head
                        
                        DestroyEvent(actual); //se destruye el evento que se solicitó arriba
                        
                   }
              }
              
              anterior = actual; //si no se cumple la condición, el head contendrá al evento siguiente en el head
              
              actual = actual->next; //contador (recorre los eventos)
              
         }
    }
   
}


void ListEvents(EventList *this)
{

   if (this->isEmpty==1) //si la lista está vacía
   
   {
   
    printf("empty\n"); //imprime esto
    
   }
   
   else //sino
   
   {
   
    Event *recorrer=this->head; //se crea un puntero que apunta al head
    
    while (recorrer!=NULL) //mientras en el head exista algo
    
    {
    
      printf("%s\n",recorrer->eventName); //imprime el nombre del evento actual
      
      recorrer=recorrer->next; //aquí pasa al siguiente evento en el head
      
    }
    
    
   }
   
}
