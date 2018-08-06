#include <stdio.h>

//get minimum element of array from index a to index b, inclusive
int get_min(int *array, int a, int b);

//get maximum element of array from index a to index b, inclusive
int get_max(int *array, int a, int b);

//get sum of odd digits of string number
//example   sum_of_odd_digits("12351") == 10
int sum_of_odd_digits(char *str);



//implement them here

int get_min(int *array, int a, int b){
	if(b >= a){
		int min_num = array[a];
		int p = a+1;
		for(; p <= b; p++){
			if(array[p] < min_num){
				min_num = array[p];
			}
		}
		return min_num;
	}
	else{
		printf("Invalid Index Range \n");
	}
}

int get_max(int *array, int a, int b){
	if(b >= a){
		int max_num = array[a];
		int p = a+1;
		for(; p <= b; p++){
			if(array[p] > max_num){
				max_num = array[p];
			}
		}
		return max_num;
	}
	else{
		printf("Invalid Index Range \n");
	}
}

int sum_of_odd_digits(char *str){
	int sum = 0;
	int z, j;
	for(z = 0; str[z]; z++){
		j = str[z] - '0'; // Type Conversion Method From: https://stackoverflow.com/questions/628761/convert-a-character-digit-to-the-corresponding-integer-in-c
		if(j % 2){
			sum += j;
		}
	}
	return sum;
}

int array[] = {1,4,-1,2,5};

int main() {
	printf("%d %d %d\n",
		get_min(array,1,4),
		get_max(array,0,2),
		sum_of_odd_digits("12351")); 

	//should output "-1 4 10"
}