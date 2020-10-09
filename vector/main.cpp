#include <iostream>
#include "MyVector.h"
#include "MyMatrix.h"

using namespace std;
int main()
{
  Vector<int> a(3, 3);
  Matrix<int> m(2);

  m[0][0] = 2;
  m[1][0] = 1;
  m[1][1] = 3;

  cout<< a << "\nHi\n";
  cout << "Matrix:" << endl << m;
  
  return 0;
}
