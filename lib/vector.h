typedef struct Vector Vector;

struct Vector {
  char *buffer;
  int item_count;
  int item_size;
  int item_capacity;
};

Vector *vector_new(int item_size);

void vector_init(Vector *vec, int item_size);

int vector_push(Vector *vec, void *item);

int vector_shrink(Vector *vec);

void *vector_at(Vector *vec, int index);

void vector_free(Vector *vec);
