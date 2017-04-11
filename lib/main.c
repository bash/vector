#include <stdio.h>
#include "vector.h"

struct Test {
  int foo;
};

void print_vector(Vector *vec) {
  for (int i = 0; i < vector_length(vec); i += 1) {
    struct Test *t = vector_at(vec, i);
    printf("i = %d, foo = %d\n", i, t->foo);
  }
}

int main(int argc, char *argv[]) { 
  Vector *vec = vector_new(sizeof(struct Test));
  
  for (int i = 0; i < 7; i++) {
    struct Test test = { i * 10 };

    vector_push(vec, &test);
    printf("count = %d, capacity = %d\n", vec->item_count, vec->item_capacity);
  }

  vector_shrink(vec);
  printf("count = %d, capacity = %d\n", vec->item_count, vec->item_capacity);

  print_vector(vec);

  vector_remove(vec, 1, 2);
  printf("count = %d, capacity = %d\n", vec->item_count, vec->item_capacity);

  print_vector(vec);

  vector_free(vec);
  printf("count = %d, capacity = %d\n", vec->item_count, vec->item_capacity);
}
