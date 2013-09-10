#include <iostream>

using namespace std;

double plus (double a, double b)
{
    return a + b;   
}

double minus (double a, double b)
{
    return a - b;       
}

double times (double a, double b)
{
    return a * b;       
}


double divides (double a, double b)
{
    return a / b;       
}

int main ()
{
 //      typedef double (*OP)(double,double);
 //      OP op;
       double a=4.0, b=3.3;
       cout << minus(a,b) << endl;
       cin >> a;
}
