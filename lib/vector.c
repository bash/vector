#include <stdlib.h>
#include <string.h>
#include "vector.h"

Vector* vector_new(int item_size) {
  Vector *vec = malloc(sizeof(Vector));

  vector_init(vec, item_size);

  return vec;
}

void vector_init(Vector *vec, int item_size) {
  vec->buffer = NULL;
  vec->item_count = 0;
  vec->item_size = item_size;
  vec->item_capacity = 0;
}

int vector_resize(Vector *vec, int capacity) {
  if (capacity < vec->item_count)
    return 0;

  char *new_buffer = malloc(capacity * vec->item_size);

  memcpy(new_buffer, vec->buffer, vec->item_count * vec->item_size);
  free(vec->buffer);

  vec->buffer = new_buffer;
  vec->item_capacity = capacity;

  return 1;
}

int vector_push(Vector *vec, void *value) {
  int item_count = vec->item_count + 1;
  
  if (vec->item_capacity < item_count)
    if (!vector_resize(vec, item_count * item_count))
      return 0;

  for (int i = 0; i < vec->item_size; i += 1)
    vec->buffer[vec->item_count * vec->item_size + i] = ((char *) value)[i];

  vec->item_count += 1;

  return 1;
}

void vector_free(Vector *vector) {
  free(vector->buffer);
  vector_init(vector, vector->item_size);  
}

void *vector_at(Vector *vec, int index) {
  if (index < 0)
    index = vec->item_count - index;
  
  if (index > vec->item_count)
    return NULL;
    
  return &vec->buffer[index * vec->item_size];
}
