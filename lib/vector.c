#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "vector.h"

Vector *vector_new(unsigned item_size) {
  Vector *vec = malloc(sizeof(Vector));

  vector_init(vec, item_size);

  return vec;
}

void vector_init(Vector *vec, unsigned item_size) {
  assert(vec);

  vec->buffer = NULL;
  vec->item_count = 0;
  vec->item_size = item_size;
  vec->item_capacity = 0;
}

unsigned vector_resize(Vector *vec, int capacity) {
  assert(vec);

  if (capacity < vec->item_count)
    return 0;

  char *new_buffer = malloc(capacity * vec->item_size);

  memcpy(new_buffer, vec->buffer, vec->item_count * vec->item_size);
  free(vec->buffer);

  vec->buffer = new_buffer;
  vec->item_capacity = capacity;

  return 1;
}

unsigned vector_push(Vector *vec, void *value) {
  assert(vec);

  unsigned item_count = vec->item_count + 1;
  
  if (vec->item_capacity < item_count)
    if (!vector_resize(vec, item_count * item_count))
      return 0;

  for (unsigned i = 0; i < vec->item_size; i += 1)
    vec->buffer[vec->item_count * vec->item_size + i] = ((char *) value)[i];

  vec->item_count += 1;

  return 1;
}

void vector_free(Vector *vec) {
  assert(vec);

  free(vec->buffer);
  vector_init(vec, vec->item_size);
}

void *vector_at(Vector *vec, int index) {
  assert(vec);

  if (index < 0)
    index += vec->item_count;

  assert(index >= 0);

  if (index > vec->item_count)
    return NULL;
    
  return &vec->buffer[index * vec->item_size];
}

unsigned vector_shrink(Vector *vec) {
  assert(vec);

  return vector_resize(vec, vec->item_count);
}
