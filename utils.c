#include "utils.h"

int randInt(int min, int max) {
  return (rand() % (max - min)) + min;
}
float randFloat(float min, float max) {
  return ((float)rand() / (float)(RAND_MAX/(max - min))) + min;
}
