#include <bits/stdc++.h>

using namespace std;

int main(){
    char buffer[10000];

    while(fgets(buffer, 10000, stdin)!=NULL){ // We can limit the number of characters read to avoid overflow.
        printf("%s", buffer);  // Notice that we don't include a '\n', as fgets also stores this from the input.
        printf("Read %d characters.\n", strlen(buffer));
    }
    return 0;
}