#include <stdio.h>

enum fruit_tag {
  BLUEBERRY,
  BANANA,
  PINEAPPLE,
  WATERMELON
};
typedef enum fruit_tag fruit_t;

void printFruit(fruit_t myFruit) {
  switch(myFruit) {
    case BLUEBERRY:
      printf("a blueberry");
      break;
    case BANANA:
      printf("a banana");
      break;
    case PINEAPPLE:
      printf("a pineapple");
      break;
    case WATERMELON:
      printf("a watermelon");
      break;
  }
}

void compareFruit(fruit_t fruit1, fruit_t fruit2) {
  if (fruit1 > fruit2) {
    printFruit(fruit1);
    printf(" is larger than ");
    printFruit(fruit2);
  }
  else {
    printFruit(fruit1);
    printf(" is smaller than ");
    printFruit(fruit2);
  }
}

int main(void) {
  fruit_t myFruit = PINEAPPLE;
  fruit_t otherFruit = BLUEBERRY;
  compareFruit(myFruit, otherFruit);
  return 0;
}