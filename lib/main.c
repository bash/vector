#include <stdio.h>
#include "vector.h"

struct Test {
  int foo;
};

int main(int argc, char* argv[]) {
 
  Vector *vec = vector_new(sizeof(struct Test));
  struct Test test = { 666 };

  vector_push(vec, &test);
  printf("count = %d, capacity = %d\n", vec->item_count, vec->item_capacity);

  vector_push(vec, &test);
  printf("count = %d, capacity = %d\n", vec->item_count, vec->item_capacity);

  vector_push(vec, &test);
  printf("count = %d, capacity = %d\n", vec->item_count, vec->item_capacity);

  vector_push(vec, &test);
  printf("count = %d, capacity = %d\n", vec->item_count, vec->item_capacity);

  vector_push(vec, &test);
  printf("count = %d, capacity = %d\n", vec->item_count, vec->item_capacity);

  struct Test *t = vector_at(vec, 0);

  printf("%d\n", t->foo);
}
