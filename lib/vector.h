struct Vector {
  char *buffer;
  size_t item_count;
  size_t item_size;
  size_t item_capacity;
};

typedef struct Vector Vector;

Vector *vector_new(size_t item_size);

void vector_init(Vector *vec, size_t item_size);

int vector_push(Vector *vec, void *item);

int vector_shrink(Vector *vec);

void *vector_at(const Vector *vec, size_t index);

void vector_free(Vector *vec);

void vector_remove(Vector *vec, size_t index, size_t count);

int vector_concat(Vector *vec, Vector *value);

size_t vector_length(const Vector *vec);
