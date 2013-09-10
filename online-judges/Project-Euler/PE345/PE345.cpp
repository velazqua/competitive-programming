/* Name: Alex Velazquez
 * Start Date: September 03, 2011 @ 07:58PM
 * End Date:   ???
 * Purpose: To solve the Project Euler problem #345
 * Link: http://projecteuler.net/index.php?section=problems&id=345
 * */

#include <iostream>
#include <fstream>
#include <cstdlib>

#define SIZE 5

using namespace std;

int main ()
{
	ifstream fin;
	fin.open("PE345.txt");
	int M[SIZE][SIZE];
	for (int i=0;i<SIZE;++i)
	{
		for (int j=0;j<SIZE;++j)
		{
			fin >> M[i][j];
		}
	}
	
	int MAX = 0;
	for (int i=0;i<SIZE;++i)
	{
		for (int j=0;j<SIZE;++j)
		{
			
		}
		
	}
	fin.close();
}
