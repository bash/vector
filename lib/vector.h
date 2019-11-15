#ifndef VECTOR

#define VECTOR(type) vector_new(sizeof(type))
#define VECTOR_WITH_CAPACITY(type, capacity) vector_new_with_capacity(sizeof(type), capacity)

struct Vector {
  char *buffer;
  size_t item_count;
  size_t item_size;
  size_t item_capacity;
};

typedef struct Vector Vector;

Vector *vector_new(size_t item_size);

Vector *vector_new_with_capacity(size_t item_size, size_t initial_capacity);

void vector_init(Vector * const vec, size_t item_size);

void vector_init_with_capacity(Vector * const vec, size_t item_size, size_t initial_capacity);

int vector_push(Vector * const vec, void * const item);

int vector_shrink(Vector * const vec);

void * const vector_at(Vector * const vec, size_t index);

void vector_free(Vector * const vec);

void vector_remove(Vector * const vec, size_t index, size_t count);

int vector_concat(Vector * const vec, Vector *value);

size_t vector_length(Vector * const vec);

#endif