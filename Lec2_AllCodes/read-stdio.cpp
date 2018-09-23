#include <stdio.h>

int main(){
    int num1, num2;
    char c1, c2;
    char str1[100], str2[100];
    double d1,d2;

    // Scanf can scan primitive types (int, char, double) as well as C-strings (char arrays), and is faster than cin.
    while(scanf("%d %d %c %c %lf %lf %s %s", &num1, &num2, &c1, &c2, &d1, &d2, str1, str2)!=EOF){
        printf("%d %d %c %c %f %f %s %s\n", num1, num2, c1, c2, d1, d2, str1, str2);  // The default precision for floats is 6 decimal places.
        printf("d1: %.3f (3 decimal places) %.9f (9 decimal places)\n", d1, d1);
    }

    return 0;
}