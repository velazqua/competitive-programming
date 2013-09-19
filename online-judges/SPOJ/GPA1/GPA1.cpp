/* Name: Alex Velazquez
 * Start Date: October 27, 2011 @ 09:03PM
 * End Date:   October 27, 2011 @ 09:29PM
*/

#include <iostream>
#include <algorithm>
#include <deque>
#include <sstream>
#include <cstdio>

using namespace std;

double strInt( string x )
{
	double value;
	istringstream M(x);
	M >> value;
	return value;
}

double markToPoint( double mark )
{
	if     ( mark >= 91.0 ) return 10;
	else if( mark >= 81.0 ) return 9;
	else if( mark >= 71.0 ) return 8;
	else if( mark >= 61.0 ) return 7;
	else if( mark >  50.0 ) return 6;
	else if( mark == 50.0 ) return 5;
	else return 0;
}

int main ()
{
	int N;
	cin >> N;
	for( int i=0; i<N; ++i )
	{
		deque<double> credits;
		double t;
		for( int j=0; j<6; ++j )
		{
			cin >> t;
			credits.push_back(t);
		}
		deque<double> courseMarks;
		for( int k=0; k<6; ++k )
		{
			double course = 0.0;
			deque<double> assignmentMarks;
			string assig;
			for( int j=0; j<3; ++j )
			{
				cin >> assig;
				if( assig.compare( "ab" ) == 0 )
				{
					assignmentMarks.push_back(0.0);
				}
				else
				{
					double mark = strInt( assig );
					assignmentMarks.push_back( mark );
				}
			}
			sort( assignmentMarks.begin(), assignmentMarks.end() );
			assignmentMarks.pop_front();
			// total marks from assignments
			course += (assignmentMarks[0]+assignmentMarks[1])/40.0*45.0;
			// total marks from final exam
			double finalExam;
			cin >> finalExam;
			course += finalExam/2.0;
			// marks from attendance
			double attendance, attMarks;
			cin >> attendance;
			if( 	 attendance < 51.0 ) attMarks = 5.0;
			else if( attendance < 61.0 ) attMarks = 4.0;
			else if( attendance < 71.0 ) attMarks = 3.0;
			else if( attendance < 81.0 ) attMarks = 2.0;
			else if( attendance < 91.0 ) attMarks = 1.0;
			else attMarks = 0.0;
			course += attMarks;
			courseMarks.push_back( course );
		}
		bool fail = false;
		double GPA = 0.0;
		double sumCredits = 0.0;
		for( int k=0; k<6; ++k)
		{
			if( markToPoint(courseMarks[k]) == 0 ) fail = true;
			GPA += credits[k]*markToPoint(courseMarks[k]);
			sumCredits += credits[k];
		}
		GPA /= sumCredits;
		cout << ((fail)?"FAILED, ":"PASSED, ");
		printf("%.2f\n", GPA);
	}
}
