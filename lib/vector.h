typedef struct Vector Vector;

struct Vector {
  char *buffer;
  unsigned item_count;
  unsigned item_size;
  unsigned item_capacity;
};

Vector *vector_new(unsigned item_size);

void vector_init(Vector *vec, unsigned item_size);

int vector_push(Vector *vec, void *item);

int vector_shrink(Vector *vec);

void *vector_at(Vector *vec, int index);

void vector_free(Vector *vec);

void vector_remove(Vector *vec, unsigned index, unsigned count);

void vector_concat(Vector *vec, Vector *value);
