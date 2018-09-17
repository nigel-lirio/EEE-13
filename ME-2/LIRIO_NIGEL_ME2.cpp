#include <iostream>
using namespace std;
class Matrix{
  double values[4][4];
  public:
  Matrix();
  Matrix(double);
  Matrix(const Matrix&);
  void copy(Matrix&, const Matrix&);
  /*get(int i, int j){
    
  }
  set(int i, int j, double x){
    
  }*/
};
void Matrix::copy(Matrix& A, const Matrix& B){
    for(int y = 0; y < 4; y++){
      for(int x=0; x < 4; x++){
        A.values[x][y] = B.values[x][y];
        cout << values[x][y] ;
      }
      cout << endl;
     }
    cout << endl;
}
Matrix::Matrix(){
   for(int y = 0; y < 4; y++){
    for(int x=0; x < 4; x++){
      if(x == y){
        values[x][y] = 1;
      }
      else{
        values[x][y] = 0;
      }
      cout << values[x][y] ;
    }
    cout << endl;
  }
  cout << endl;
}
Matrix::Matrix(double z){
   for(int y = 0; y < 4; y++){
    for(int x=0; x < 4; x++){
      if(x == y){
        values[x][y] = z;
      }
      else{
        values[x][y] = 0;
      }
      cout << values[x][y] ;
    }
    cout << endl;
  }
  cout << endl;
}
Matrix::Matrix(const Matrix& oldM){
    copy(*this, oldM);
}
int main()
{
  Matrix a(3);
  Matrix b;
  Matrix c(a);
  Matrix d(2);
}