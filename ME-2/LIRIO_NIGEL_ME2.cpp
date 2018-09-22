#include <iostream>
using namespace std;
class Matrix{
  double values[4][4];
  public:
  Matrix();
  Matrix(double);
  Matrix(const Matrix&);
  void copy(Matrix&, const Matrix&);
  double get(int, int);
  void set(int, int, double);
  void print();
  Matrix operator+ (const Matrix&);
  Matrix operator- (const Matrix&);
  Matrix operator* (const Matrix&);
  Matrix operator* (double);
};
void Matrix::copy(Matrix& A, const Matrix& B){
    for(int y = 0; y < 4; y++){
      for(int x=0; x < 4; x++){
        A.values[x][y] = B.values[x][y];
      }
     }
}
double Matrix::get(int i, int j){
  return this -> values[i][j];
}
void Matrix::set(int i, int j, double x){
  this -> values[i][j] = x;
}
void Matrix::print(){
  for(int y = 0; y < 4; y++){
    for(int x = 0; x < 4; x++){
      cout << values[x][y] << "|";
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
    }
  }
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
    }
  }
}
Matrix::Matrix(const Matrix& oldM){
    copy(*this, oldM);
}
Matrix Matrix::operator+ (const Matrix& B){
  Matrix C;
  for(int y = 0; y <4; y++){
    for(int x = 0; x <4; x++){
      C.values[x][y] = (this->values[x][y])+(B.values[x][y]);
    }
  }
  return C;
}
Matrix Matrix::operator- (const Matrix& B){
  Matrix C;
  for(int y = 0; y <4; y++){
    for(int x = 0; x <4; x++){
      C.values[x][y] = (this->values[x][y])-(B.values[x][y]);
    }
  }
  return C;
}
Matrix Matrix::operator* (const Matrix& B){
  double total; 
  Matrix C;
  for(int y = 0; y <4; y++){
    for(int x = 0; x <4; x++){
      total = 0;
      for(int t = 0; t<4; t++)
      {
        total += this->values[t][y] * B.values[x][t];
      }
      C.values[x][y] = total;
    }
  }
  return C;
}
Matrix Matrix::operator* (double B){
  Matrix C;
  for(int y = 0; y <4; y++){
    for(int x = 0; x <4; x++){
      C.values[x][y] = (this->values[x][y])*B;
    }
  }
  return C;
}
int main()
{
}