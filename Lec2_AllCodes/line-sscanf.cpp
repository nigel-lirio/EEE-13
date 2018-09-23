#include <bits/stdc++.h>

using namespace std;

int main(){
    char buffer[10000];

    while(fgets(buffer, 10000, stdin)!=NULL){
        int a,b,c;
        int ret = sscanf(buffer, "%d %d %d", &a, &b, &c);  // Scan the numbers from the string

        if(ret == 1){
            printf("Only read 1 number: %d\n", a);
        } else if (ret == 2){
            printf("Got two numbers: %d %d\n",a,b);
        } else if (ret == 3){
            printf("Got all three: %d %d %d\n",a,b,c);
        }

    }
    return 0;
}