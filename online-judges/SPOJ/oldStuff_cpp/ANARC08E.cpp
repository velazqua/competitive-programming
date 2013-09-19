#include <iostream>

using namespace std;

int main ()
{
    int A, B;
    while (cin >> A && cin >> B)
    {
          if (A == -1 && B == -1)
             break;
          else
          {
              if (A == 1 || B == 1)
                 cout << A << "+" << B << "=" << A+B << endl;
              else
                 cout << A << "+" << B << "!=" << A+B << endl;    
          }      
    }   
}
