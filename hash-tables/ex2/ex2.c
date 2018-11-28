#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "ex2.h"

char **reconstruct_trip(Ticket **tickets, int length)
{
  HashTable *hash = create_hash_table(16);
  char **route = malloc(length * sizeof(char *));
  // find start ticket. should be the one with NULL set
  // add start to route[0] add rest to ht with key as source and value as dest
  for(int i = 0; i < length; i++){
    printf("tickets %s\n\n", tickets[i]->source);
    if(strcmp(tickets[i]->source, "NONE")== 0){
      route[0] = tickets[i]->destination;
    }else{
      hash_table_insert(hash, tickets[i]->source, tickets[i]->destination);
    }
  }
   for(int j = 1; j < length; j++){
    //  retrieve returns NULL if it doesn't have a key
     printf("whats in ht value when asking for route[0] %s\n\n\n", hash_table_retrieve(hash, route[0]));
     if(hash_table_retrieve(hash, route[j - 1]) != NULL){
       route[j] = hash_table_retrieve(hash, route[j - 1]);
     }else{
       route[j] = "NONE";
     }
   }
  // 
  // YOUR CODE HERE

  return route;
}

void print_route(char **route, int length)
{
  for (int i = 0; i < length; i++) {
    printf("%s\n", route[i]);
  }
}