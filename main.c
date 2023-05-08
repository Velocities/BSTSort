#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BSTSort.h"

int main() {
  srand(time(NULL));
  int nums[rand() % 10 + 1];
  int size = sizeof(nums)/sizeof(nums[0]);
  printf("nums = {");
  for (int i = 0; i < size; i += 1) {
    nums[i] = rand() % 20 + 1;
    printf("%i", nums[i]);
    if (i != size - 1) {
      printf(", ");
    }
  }
  puts("}");
  BSTSort(nums, size);
  printf("nums = {");
  for (int i = 0; i < size - 1; i += 1) {
    printf("%i, ", nums[i]);
  }
  printf("%i}\n", nums[size - 1]);
  return EXIT_SUCCESS;
}
