#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int caseInsensitiveStringCompare( const std::string& str1, const std::string& str2 ) {
    std::string str1Cpy( str1 );
    std::string str2Cpy( str2 );
    std::transform( str1Cpy.begin(), str1Cpy.end(), str1Cpy.begin(), ::toupper );
    std::transform( str2Cpy.begin(), str2Cpy.end(), str2Cpy.begin(), ::toupper );
	//cout << str1Cpy << " " << str2Cpy << " " <<<< endl;
	//cout << str1 << " " << str2 << " " << str1.compare(str2) << endl;
    return ( str1Cpy.compare(str2Cpy) );
}

int main ()
{
	string a = "alExaa", b = "alexa";
	//cout << "compare: " << a.compare(b) << endl;
	cout << "case compare: " << caseInsensitiveStringCompare(a,b) << endl;
}
