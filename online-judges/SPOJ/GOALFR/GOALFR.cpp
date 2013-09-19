/* Name: Alex Velazquez
 * Start Date: November 02, 2011 @ 10:10PM
 * End Date:   November 02, 2011 @ 10:27PM (Wrong Answer)
 * 			   November 05, 2011 @ 12:10AM	
*/

#include <iostream>
#include <cmath>

#define DEBUG 0

using namespace std;

bool intersection( double X1, double Y1, double X2, double Y2, double R )
{	
	// check if goalie is in the way of the ball
	if( X1 < 0.0 ) return false;
	double dx = X2-X1;
	double dy = Y2-Y1;
	return ( dx*dx + dy*dy <= R*R) ? true : false;
}
int main ()
{
	int T;
	cin >> T;
	for( int i=0; i<T; ++i )
	{
		double ballX, ballY, goalieX, goalieY, goalieRad;
		cin >> ballX >> ballY;
		cin >> goalieX >> goalieY >> goalieRad;
		double shiftX = ballX;
		double shiftY = ballY;
		// move goalie to (0,0). shift ball, and nets as well
		double netX  = 52.50-shiftX,
			   netY1 = 03.66-shiftY,
			   netY2 = -3.66-shiftY;
		ballX = 0.0;
		ballY = 0.0;
		goalieX -= shiftX;
		goalieY -= shiftY;
		
		#if DEBUG
			cout << "ballX: " << ballX << endl;
			cout << "ballY: " << ballY << endl;
			cout << "netX: " << netX << endl;
			cout << "netY1: " << netY1 << endl;
			cout << "netY2: " << netY2 << endl;
			cout << "goalieX: " << goalieX << endl;
			cout << "goalieY: " << goalieY << endl;
			cout << "goalieRad: " << goalieRad << endl;
		#endif
		// slope of ball to nets
		double slope1 = ( netX == 0 ) ? 0 : netY1/netX;
		double slope2 = ( netX == 0 ) ? 0 : netY2/netX;
		
		// perpendicular slope of line from center of circle to lines
		double slopeBall1 = ( netY1 == 0 ) ? 0 : -1*netX/netY1;
		double slopeBall2 = ( netY2 == 0 ) ? 0 : -1*netX/netY2;
		
		// find equation of lines given the above slopes
		double b1 = goalieY - slopeBall1*goalieX;
		double b2 = goalieY - slopeBall2*goalieX;
		
		// find point of intersection
		double x1 = ( b1 ) / ( slope1 - slopeBall1 );
		double x2 = ( b2 ) / ( slope2 - slopeBall2 );
		double y1 = ( slopeBall1 * x1 ) + b1;
		double y2 = ( slopeBall2 * x2 ) + b2;
		
		if( netY1 == 0 ) 
		{
			x1 = goalieX;
			y1 = 0;
		}
		if( netY2 == 0 )
		{
			x2 = goalieX;
			y2 = 0;
		}
		if( netX == 0 && goalieX == 0 )
		{
			x1 = 0;
			x2 = 0;
			if( ballY < netY2 && goalieY > netY2 ||
				ballY > netY1 && goalieY < netY1 )
			{
				y1 = ballY;
				y2 = ballY;
			}
			else
			{
				y1 = goalieY;
				y2 = goalieY;
			}
		}
		else if( netX == 0 )
		{
			x1 = 0;
			y1 = goalieY;
			x2 = 0;
			y2 = goalieY;
		}
		
		#if DEBUG
			cout << "slope1: " << slope1 << endl;
			cout << "slope2: " << slope2 << endl;
			cout << "slopeBall1: " << slopeBall1 << endl;
			cout << "slopeBall2: " << slopeBall2 << endl;
			cout << "b1: " << b1 << endl;
			cout << "b2: " << b2 << endl;
			cout << "(x1,y1) = (" << x1 << "," << y1 << ")" << endl;
			cout << "(x2,y2) = (" << x2 << "," << y2 << ")" << endl;
		#endif
		// check if point of intersection is within radius of the goalie
		bool intersec1 = intersection( x1, y1, goalieX, goalieY, goalieRad );
		bool intersec2 = intersection( x2, y2, goalieX, goalieY, goalieRad );
		
		// check if ball is in the radius of goalie
		bool intersec3 = intersection( ballX, ballY, goalieX, goalieY, goalieRad );
		
		#if DEBUG
			cout << intersec3 << endl;
			cout << intersec1 << " " << intersec2 << endl; 
		#endif
		
		if( intersec1 && intersec2 || intersec3 )
			cout << "No goal..." << endl;
		else
			cout << "Goal!" << endl;
	}
}
