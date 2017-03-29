#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "vector.h"

#define EXPAND_FACTOR 1.5

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

int vector_resize(Vector *vec, int capacity) {
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

int vector_expand(Vector *vec, int item_count) {
  assert(vec);

  if (vec->item_capacity < item_count)
    if (!vector_resize(vec, item_count * EXPAND_FACTOR))
      return 0;

  return 1;
}

int vector_push(Vector *vec, void *value) {
  assert(vec);

  unsigned item_count = vec->item_count + 1;

  if (!vector_expand(vec, item_count))
    return 0;

  for (int i = 0; i < vec->item_size; i += 1)
    vec->buffer[vec->item_count * vec->item_size + i] = ((char *) value)[i];

  vec->item_count += 1;

  return 1;
}

void vector_free(Vector *vec) {
  assert(vec);

  free(vec->buffer);
  free(vec);
}

unsigned vector_calculate_index(Vector *vec, int index) {
  if (index < 0)
    index += vec->item_count;

  assert(index >= 0);
  assert(index < vec->item_count);

  return index;
}

void *vector_at(Vector *vec, int index) {
  assert(vec);

  index = vector_calculate_index(vec, index);
    
  return &vec->buffer[index * vec->item_size];
}

void vector_remove(Vector *vec, int index, unsigned count) {
  assert(vec);
 
  index = vector_calculate_index(vec, index);

  if ((index + count) >= vec->item_count)
    return;

  unsigned offset = (index + count) * vec->item_size;
  unsigned end = (vec->item_count - count) * vec->item_size;
  unsigned remove = count * vec->item_size;

  for (int i = offset; i <= end; i += 1)
    vec->buffer[i - remove] = vec->buffer[i];

  vec->item_count -= count;
}

int vector_shrink(Vector *vec) {
  assert(vec);

  return vector_resize(vec, vec->item_count);
}

int vector_concat(Vector *vec, Vector *value) {
  assert(vec);
  assert(value);

  unsigned item_count = vec->item_capacity + value->item_count;

  if (!vector_expand(vec, item_count))
    return 0;

  for (int i = 0; i < value->item_count; i += 1) {
    vector_push(vec, vector_at(value, i));
  }

  return 1;
}
