#include <stdio.h>
#include <stdlib.h>

int a = 4;

int c = 5;

int d = 6;

int e = 7;

int bar() {
  int *a = (int*) malloc(4);
  e = 1;
  return 1;
}

int foo() {
  return 2;
}

int barfoo() {
  return 3;
}

int main() {
  printf("Testing testing\n");
  return 0;
}
