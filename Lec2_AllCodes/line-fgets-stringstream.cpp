#include <bits/stdc++.h>

using namespace std;

int main(){
    char buffer[10000];

    while(fgets(buffer, 10000, stdin)!=NULL){
        stringstream ss(buffer);
        string token;
        printf("Got line: %s", buffer);
        int cnt = 0;
        printf("Tokens:");
        while(ss >> token){  // Just like cin >> token
            cout << " " << token;
            cnt++;
        }
        printf("\n");
        printf("Got %d token(s).\n", cnt);


    }

    return 0;
}