/* Alex Velazquez
 * Start: Fri Aug 17 21:06:24 EDT 2012
 * End  : Fri Aug 17 22:58:08 EDT 2012
*/
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <deque>

using namespace std;

#define FOR(I,A,B)   for(int I= (A); I<(B); ++I)
#define REP(I,N)     FOR(I,0,N)
#define ALL(A)       (A).begin(), (A).end()
#define SZ(A)        (A).size()
#define FST(A)       (A).first
#define SEC(A)       (A).second
#define DEBUG 0

typedef long long int LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

bool checkWinner( vector< vector<int> > &vals, vector<string> &board )
{
	bool gameOver = false;
	// horizontal
	for( int i=0; i<6; ++i )
	{
		for( int j=0; j<4; ++j ) 
		{
			int result = 1;
			for( int x=0; x<4; ++x )
				result *= vals[i][j+x];
				
			if( result == 1 || result == 16 )
			{
				for( int x=0; x<4; ++x )
				{
					char piece = board[i][j+x];
					if( piece == 'x' )
						board[i][j+x] = 'X';
					else if( piece == 'o' )
						board[i][j+x] = 'O';
				}
				gameOver = true;
			}
		}
	}
	
	#if DEBUG
		cout << "No horizontal" << endl;
	#endif
	
	// vertical
	for( int i=0; i<3; ++i )
	{
		for( int j=0; j<7; ++j )
		{
			int result = 1;
			for( int x=0; x<4; ++x )
				result *= vals[i+x][j];
				
			if( result == 1 || result == 16 )
			{
				for( int x=0; x<4; ++x )
				{
					char piece = board[i+x][j];
					if( piece == 'x' )
						board[i+x][j] = 'X';
					else if( piece == 'o' )
						board[i+x][j] = 'O';
				}
				gameOver = true;
			}
		}
	}
	
	#if DEBUG
		cout << "No vertical" << endl;
	#endif
		
	// right down diagonals
	for( int i=0; i<3; ++i )
	{
		for( int j=0; j<4; ++j )
		{
			int result = 1;
			for( int x=0; x<4; ++x )
				result *= vals[i+x][j+x];
				
			if( result == 1 || result == 16 )
			{
				for( int x=0; x<4; ++x )
				{
					char piece = board[i+x][j+x];
					if( piece == 'x' )
						board[i+x][j+x] = 'X';
					else if( piece == 'o' )
						board[i+x][j+x] = 'O';
				}
				gameOver = true;
			}
		}
	}
	
	#if DEBUG
		cout << "No right down diagonals" << endl;
	#endif
	
	// right up diagonals
	for( int i=3; i<6; ++i )
	{
		for( int j=0; j<4; ++j )
		{
			int result = 1;
			for( int x=0; x<4; ++x )
				result *= vals[i-x][j+x];
				
			if( result == 1 || result == 16 )
			{
				for( int x=0; x<4; ++x )
				{
					char piece = board[i-x][j+x];
					if( piece == 'x' )
						board[i-x][j+x] = 'X';
					else if( piece == 'o' )
						board[i-x][j+x] = 'O';
				}
				gameOver = true;
			}
		}
	}
	
	#if DEBUG
		cout << "No right up diagonals" << endl;
	#endif
	
	return gameOver;
}

void printBoard( vector<string> &board )
{	
	cout << "-------" << endl;
	int r = 0;
	
	// dont display empty rows
	REP( i, 6 )
	{
		if( !board[i].compare( "       " ) )
			++r;
		else
			break;
	}
	
	FOR( i, r, 6 )
	{
		REP( j, 7 )
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << "-------" << endl;
}

int main ()
{
	int T;
	cin >> T;
	REP( t, T )
	{
		if( t == 0 )
			cin.ignore();
		string g, num, game;
		string line;
		getline( cin, line );
		stringstream lineStream( line );
		lineStream >> g >> num >> game;
		
		#if DEBUG
			cout << "g: " << g << ". num: " << num << ". game: " << game << endl;
		#endif
		
		vector<int> overflow( 8, 0 );
		vector<string> board( 6, "       " );
		vector< vector<int> > vals( 6, vector<int>( 7, 0 ) );
		int size = SZ(game);
		bool invalidGame = false;
		bool isThereWinner = false;
		bool gameOver = false;
		string winner = "";
		REP( i, size )
		{
			#if DEBUG
				cout << "Current move: " << game[i] << endl;
			#endif
			int indx = game[i]-48;
			overflow[indx]++;
			if( overflow[indx] > 6 || size > 42 )
			{
				invalidGame = true;
			}
			else
			{
				char piece = ( i % 2 ) ? 'o': 'x' ;
				board[6-overflow[indx]][indx-1] = piece;
				vals[6-overflow[indx]][indx-1] = (i%2)+1;
				
				#if DEBUG
					printBoard( board );
				#endif
				
				// check for winner
				isThereWinner = checkWinner( vals, board );
				if( isThereWinner )
				{
					gameOver = true;
					// any turns left to play? if so, invalid game
					if( i != size-1 )
						invalidGame = true;
					// who won?
					winner = ( i % 2 ) ? "second" : "first" ;
				}
				else if( !isThereWinner && size == 42 && i == size-1 )
					gameOver = true;
			}
		}
		cout << "Game #" << t+1 << " is ";
		if( invalidGame )
		{
			cout << "invalid." << endl;
		}
		else
		{
			if( gameOver )
			{
				cout << "over. ";
				if( isThereWinner )
				{
					cout << "The " << winner << " player won." << endl;
					printBoard( board );
				}
				else
					cout << "There is no winner." << endl;
			}
			else
				cout << "not over, yet." << endl;
		}
	}
}
