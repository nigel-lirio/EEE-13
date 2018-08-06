#include <stdio.h>

//get minimum element of array from index a to index b, inclusive
int get_min(int *array, int a, int b);

//get maximum element of array from index a to index b, inclusive
int get_max(int *array, int a, int b);

//get sum of odd digits of string number
//example   sum_of_odd_digits("12351") == 10
int sum_of_odd_digits(char *str);



//implement them here




int array[] = {1,4,-1,2,5};

int main() {
	printf("%d %d %d\n",
		get_min(array,1,4),
		get_max(array,0,2),
		sum_of_odd_digits("12351"));

	//should output "-1 4 10"
}