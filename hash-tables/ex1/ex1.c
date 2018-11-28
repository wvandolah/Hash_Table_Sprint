#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"
#include "ex1.h"

Answer *get_indices_of_item_weights(int *weights, int length, int limit)
{
  HashTable *ht = create_hash_table(16);
  Answer *answer = malloc(sizeof(Answer));
  // weights is an a pointer to array of weight
  // storing weights as a key in object
  // loop weights
  // try to find a key in ht that equals limit - current 
  // if found return answer if not added to ht
  // answer should be index of weights not actual weight
  for(int i = 0; i < length; i++){
    int matcher = hash_table_retrieve(ht, limit - weights[i]);
    printf("weights %d\n\n", weights[i]);
    printf("matcher %d\n\n", matcher);
    if(matcher == -1){
      hash_table_insert(ht, weights[i], i);
    }else{
      answer->index_1 = i;
      answer->index_2 = matcher;
      destroy_hash_table(ht);
      return answer;
    }
  }
  // YOUR CODE HERE
  destroy_hash_table(ht);
  return NULL;
}

void print_answer(Answer *answer)
{
  if (answer != NULL) {
    printf("%d %d\n", answer->index_1, answer->index_2);
  } else {
    printf("NULL\n");
  }
}