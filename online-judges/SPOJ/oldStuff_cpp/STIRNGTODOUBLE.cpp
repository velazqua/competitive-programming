#include <iostream>
#include <sstream>

using namespace std;

int main ()
{
	std::istringstream stm;
	stm.str(" 3.141518");
	double a;
	stm >> a;
	cout << a << endl;
}
