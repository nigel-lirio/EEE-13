#include <bits/stdc++.h>

using namespace std;

int main(){
    string buffer;  // With the string class, we can just append characters arbitrary and not be concerned with overflow, compared to fgets in C.

    while(getline(cin, buffer)){
        cout << buffer << endl;  // getline excludes the newline (`\n') character, so we put endl manually.
        printf("Read %d characters.\n", buffer.size());
    }

    return 0;
}
