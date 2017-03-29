typedef struct Vector Vector;

struct Vector {
  char *buffer;
  unsigned item_count;
  unsigned item_size;
  unsigned item_capacity;
};

Vector *vector_new(unsigned item_size);

void vector_init(Vector *vec, unsigned item_size);

unsigned vector_push(Vector *vec, void *item);

unsigned vector_shrink(Vector *vec);

void *vector_at(Vector *vec, int index);

void vector_free(Vector *vec);
