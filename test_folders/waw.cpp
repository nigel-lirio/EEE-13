#include <iostream>
class Food_Review{
    int score = 0;
    public:
    Food_Review(){
        score = 1;
    }
    Food_Review(int x){
        score = x;
    }
    int get_score(){
        return score;
    }
};

int main(){
    Food_Review A; //Triggers Constructor with no input
    Food_Review B(3); //Triggers Constructor with int input
    std::cout << "A SCORE: " << A.get_score() << std::endl; //Returns 1
    std::cout << "B SCORE: " << B.get_score() << std::endl; //Returns 3
    return 0;
}