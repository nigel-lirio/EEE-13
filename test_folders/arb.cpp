#include <vector>
int* foo(int *iArr){
  iArr = (int* ) malloc(sizeof(int) *2);
  iArr[0] = 1;
  iArr[1] = 2;
  return iArr;
}
