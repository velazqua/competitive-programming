/* Alex Velazquez
 * Start: Sat Feb 25 20:09:35 EST 2012
 * End  : Wed Feb 29 19:52:23 EST 2012
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <utility>
#include <vector>

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define DEBUG 0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct Student {
	vector<int> tests;
	int bonus;
	int absences;
	double avg;
	int grade;
	Student( vector<int> T, int B, int A ) : tests(T), bonus(B), absences(A) {}
};

double roundNearestTenth( double x )
{
	return float(int(x*10+0.5))/10;
}

int main ()
{
	int N;
	cin >> N;
	cout << "MAKING THE GRADE OUTPUT" << endl;
	REP( i, N )
	{
		int S, T;
		cin >> S >> T;
		vector<Student> students;
		bool removed = false;
		REP( j, S )
		{
			int bonus, absences;
			vector<int> tests( T );
			REP( k, T )
				cin >> tests[k];
			sort( tests.begin(), tests.end(), greater<int>() );
			if( tests.size() > 2 )
				tests.pop_back(), removed = true;
			cin >> bonus;
			cin >> absences;
			students.push_back( Student( tests, bonus, absences ) );
		}
		if( removed ) 
			--T;
		REP( j, S )
		{
			//compute student avgs
			REP( k, T )
			{
				students[j].avg += students[j].tests[k];
			}
			students[j].avg /= (double)T;
			students[j].avg = roundNearestTenth( students[j].avg );
			#if DEBUG
				cout << "Student avg: " << students[j].avg << endl;
			#endif
		}
		// compute overall class average
		double classAvg = 0.0;
		REP( j, S )
		{
			classAvg += students[j].avg;
		}
		classAvg /= (double)S;
		classAvg = roundNearestTenth( classAvg );
		
		// compute standard deviation
		double sd = 0.0;
		REP( j, S )
		{
			sd += (students[j].avg-classAvg)*(students[j].avg-classAvg);
		}
		sd /= S;
		sd = sqrt( sd );
		sd = roundNearestTenth( sd );
		sd = ( sd < 1.0 ) ? 1.0 : sd ;
		#if DEBUG
			cout << "Class avg: " << classAvg << endl;
			cout << "Standard Deviation: " << sd << endl;
		#endif
		// compute bonus points
		REP( j, S )
		{
			students[j].avg += (students[j].bonus/2)*3.0;
			students[j].avg = roundNearestTenth( students[j].avg );
			#if DEBUG
				cout << "Avg with bonus: " << students[j].avg << endl;
			#endif
		}
		
		// compute grade letters for students
		REP( j, S )
		{
			if     ( students[j].avg >= classAvg+1*sd )
				students[j].grade = 4;
			else if( students[j].avg >= classAvg && students[j].avg < classAvg+1*sd )
				students[j].grade = 3;
			else if( students[j].avg < classAvg && students[j].avg >= classAvg-1*sd )
				students[j].grade = 2;
			else 
				students[j].grade = 1;
		}
		
		// compute letter grade after absences
		REP( j, S )
		{
			#if DEBUG
				cout << "Number of absences: " << students[j].absences << endl;
				cout << "UnAdjGrade " << j << " = " << students[j].grade << endl;
			#endif
			int lettersDown = students[j].absences/4;
			if( students[j].absences == 0 )
				students[j].grade += 1;
			else
				students[j].grade -= lettersDown;
			if( students[j].grade > 4 ) 
				students[j].grade = 4;
			if( students[j].grade < 0 ) 
				students[j].grade = 0;
		}
		
		double avgGradePoint = 0.0;
		//compute average grade point
		REP( j, S )
		{
			#if DEBUG
				cout << "AdjGrade " << j << " = " << students[j].grade << endl;
			#endif
			avgGradePoint += students[j].grade;
		}
		avgGradePoint /= (double)S; 
		printf( "%.1f\n", avgGradePoint );
	}
	cout << "END OF OUTPUT" << endl;
}
