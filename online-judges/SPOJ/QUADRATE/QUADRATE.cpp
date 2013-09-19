/* Name: Alex Velazquez
 * Start Date: October 26, 2011 @ 12:15AM
 * End Date:   October 26, 2011 @ 01:17AM
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main ()
{
	int T;
	cin >> T;
	cin.ignore();
	for( int i=0; i<T; ++i )
	{	
		string eq;
		getline(cin,eq);
		//cout << "Equation is " << eq << endl;
		vector<int> signPlaces;
		int k=0;
		int x=0;
		// count the number of + and -
		for( string::iterator it = eq.begin(); it!=eq.end(); ++it )
		{
			if( *it == '+' || *it == '-' )
				signPlaces.push_back(k);
			if( *it == 'x' )
				++x;
			++k;
		}
		
		// extract "a"
		size_t aLocation = eq.find("*x*x");
		size_t b = eq.rfind( "*x" );
		int equalSign = eq.find( "=" );
		string A, B, C;
		if( aLocation != string::npos ) // something was found
		{
			A = eq.substr( 0, aLocation );
		} 
		else
		{
			A = "1";
		}
		if( signPlaces.size() == 0 ) // b = 0 and c = 0
		{
			B = "0";
			C = "0";
			//cout << quadraticEquation( intA, 0, 0 ) << endl;
		}
		else if( signPlaces.size() == 1 ) // b = 0 or c = 0
		{
			if( x == 3 ) // b exists (is it 1 or != 1?) 
			{
				if( b == aLocation+2) // "*x not found"
				{
					B = eq.substr( signPlaces[0], 1 ) + "1";
					C = "0";
				}
				else
				{
					B = eq.substr( signPlaces[0], b-signPlaces[0] );
					C = "0";
				}
			}
			else // c exists
			{
				B = "0";
				C = eq.substr( signPlaces[0], equalSign-signPlaces[0] );
			}
			
		}
		else // b != 0 and c != 0
		{
			if( signPlaces[0]+2 == signPlaces[1] )
			{
				B = eq.substr( signPlaces[0], 1) + "1";
				C = eq.substr( signPlaces[1], equalSign-signPlaces[1] );	
			}
			else
			{ 
				B = eq.substr( signPlaces[0], b-signPlaces[0] );
				C = eq.substr( signPlaces[1], equalSign-signPlaces[1] );
			}
		} 
		istringstream ab(A), bb(B), cb(C);
		int ai, bi, ci;
		ab >> ai;
		bb >> bi;
		cb >> ci;
		int D = bi*bi-4*ai*ci; 
		if( D < 0 )
			cout << "Imaginary roots." << endl;
		else if( D == 0 )
			cout << "Equal roots." << endl;
		else
			cout << "Distinct real roots." << endl;
	}
}	
