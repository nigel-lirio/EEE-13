#include <bits/stdc++.h>

using namespace std;

int main(){
    string buffer;

    while(getline(cin, buffer)){
        stringstream ss(buffer);
        string token;
        cout << "Got line: " << buffer << endl;
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