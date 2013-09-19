/* Alex Velazquez
 * Start: Sun Aug  5 23:31:55 EDT 2012
 * End  : Mon Aug  6 00:59:21 EDT 2012
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
#define SZ(A)        int((A).size())
#define PB           push_back
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG        0

typedef long long int LL;

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// output: 0 if piece is white, 1 if piece is black
int blackOrWhite( char C )
{
	if( C >= 65 && C <= 90 )
		return 0;
	return 1;
}

bool isOk( int x, int y )
{
	if( x >= 0 && x < 8 && y >= 0 && y < 8 )
		return true;
	else
		return false;
}

bool checkForCheck( int x, int y, int numMoves, int moveX[], int moveY[], char piece, vector<string> &board )
{
	char kindOfPiece = blackOrWhite( piece );
	char king = 'K';
	if( !kindOfPiece )
		king += 32;
	if( piece == 'P' || piece == 'p' || piece == 'N' || piece == 'n' )
	{
		#if DEBUG
			cout << "Piece: " << piece << ". king: " << char(king) << endl;
			cout << "Current x: " << x << ". Current y: " << y << endl;
		#endif
		REP( i, numMoves )
		{
			int X = x+moveX[i];
			int Y = y+moveY[i];
			#if DEBUG
				cout << "X: " << X << ". Y: " << Y << endl;
			#endif
			if( isOk( X, Y ) && board[X][Y] == king )
				return true;
		}
	}
	else
	{
		REP( i, numMoves )
		{
			FOR( j, 1, 9 )
			{
				int X = x+j*moveX[i];
				int Y = y+j*moveY[i];
				if( isOk( X, Y ) )
				{
					if( board[X][Y] == '.' )
						continue;
					else if( board[X][Y] == king )
						return true;
					else
						break;
				} 
			}
		}		
	}
	return false;
}

int main ()
{
	vector<string> board( 8, "........" );
	string line;
	int numLines = 0;
	bool empty = false;
	int game = 1;
	while( cin >> board[numLines] )
	{
		if( !board[numLines].compare( "" ) )
			continue;
		if( board[numLines].compare( "........" ) )
			empty = true;
		++numLines;
		if( numLines >= 8 )
		{
			if( !empty ) 
				break;
			bool whiteChecked = false;
			bool blackChecked = false;
			
			REP( i, 8 )
			{
				if( whiteChecked || blackChecked )
						break;
				REP( j, 8 )
				{
					if( board[i][j] == 'k' || board[i][j] == 'K' || board[i][j] == '.' )
						continue;
					else if( board[i][j] == 'p' )
					{
						int moveX[] = {1,1};
						int moveY[] = {-1,1};
						whiteChecked = checkForCheck( i, j, 2, moveX, moveY, board[i][j], board );
						#if DEBUG
							cout << "pawn " << whiteChecked << " " << blackChecked << endl; 
						#endif
					}
					else if( board[i][j] == 'P' )
					{
						int moveX[] = {-1,-1};
						int moveY[] = {-1,1};
						blackChecked = checkForCheck( i, j, 2, moveX, moveY, board[i][j], board );
						#if DEBUG
							cout << "pawn " << whiteChecked << " " << blackChecked << endl; 
						#endif
					}
					else if( board[i][j] == 'r' || board[i][j] == 'R' )
					{
						int moveX[] = {-1,1,0,0};
						int moveY[] = {0,0,1,-1};						
						bool check = checkForCheck( i, j, 4, moveX, moveY, board[i][j], board );
						if( check )
						{
							if( board[i][j] == 'r' )
								whiteChecked = true;
							else
								blackChecked = true;
						}
						#if DEBUG
							cout << "rook " << whiteChecked << " " << blackChecked << endl; 
						#endif
					}
					else if( board[i][j] == 'b' || board[i][j] == 'B' )
					{
						int moveX[] = {1,-1,1,-1};
						int moveY[] = {1,-1,-1,1};
						bool check = checkForCheck( i, j, 4, moveX, moveY, board[i][j], board );
						if( check )
						{
							if( board[i][j] == 'b' )
								whiteChecked = true;
							else
								blackChecked = true;
						}
						#if DEBUG
							cout << "bishop " << whiteChecked << " " << blackChecked << endl; 
						#endif
					}
					else if( board[i][j] == 'q' || board[i][j] == 'Q' )
					{
						int moveX[] = {1,-1,1,-1,-1,1,0,0};
						int moveY[] = {1,-1,-1,1,0,0,1,-1};
						bool check = checkForCheck( i, j, 8, moveX, moveY, board[i][j], board );
						if( check )
						{
							if( board[i][j] == 'q' )
								whiteChecked = true;
							else
								blackChecked = true;
						}
						#if DEBUG
							cout << "queen " << whiteChecked << " " << blackChecked << endl; 
						#endif
					}
					else if( board[i][j] == 'n' || board[i][j] == 'N' )
					{
						int moveX[] = {-1,-2,1,2,-2,-1,1,2};
						int moveY[] = {-2,-1,-2,-1,1,2,2,1};
						bool check = checkForCheck( i, j, 8, moveX, moveY, board[i][j], board );
						if( check )
						{
							if( board[i][j] == 'n' )
								whiteChecked = true;
							else
								blackChecked = true;
						}
						#if DEBUG
							cout << "knight " << whiteChecked << " " << blackChecked << endl; 
						#endif
					}
					if( whiteChecked || blackChecked )
						break;
				}
			}
			
			if( whiteChecked )
				cout << "Game #" << game << ": white king is in check." << endl;
			else if( blackChecked )
				cout << "Game #" << game << ": black king is in check." << endl;
			else
				cout << "Game #" << game << ": no king is in check." << endl;
				
			numLines = 0;
			empty = false;
			++game;
		}
	}
}
