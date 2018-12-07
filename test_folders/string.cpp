#include <iostream>
#include <string>
using namespace std;
//Algorithm from Ryan Duldulao

string words[] = {"abc", "de", "fgh"};

//function builds string per letter per word, where every letter is a node 
void print_perm(int count, string build){
    if(count == 3)
    {
        //base case: 3rd level of tree; print word build
        cout << build << endl;
        return;
    }
    //begins with first letter of first word that branches to first letter of second word then first letter of third word
    //function loop iterates through every letter; function stack iterates through every word
    for(int x = 0; x < words[count].length(); x++){
            string temp = build; //updates word build 
            //pushes letter of current word to word build
            temp.push_back(words[count][x]);
            //calls on next word 
            print_perm(count+1, temp);
    }
}
int main()
{
    //Begin with 0 and empty string
    print_perm(0,"");
    return 0;
}
