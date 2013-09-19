/* Name: Alex Velazquez
 * Start Date: October 04, 2011 @ 08:36PM
 * End Date:   October 04, 2011 @ 09:54PM
 * Purpose: To solve the SPOJ problem QKP - Queens, Knights, and Pawns
 */

#include <iostream>
#include <list>

using namespace std;

struct Piece {
	char p;
	int x;
	int y;
	Piece () : p('E'), x(1), y(1) {}
	Piece (int x_, int y_) : p('E'), x(x_), y(y_) {}
	Piece (char p_, int x_, int y_) : p(p_), x(x_), y(y_) {}
	void update (char p_, int x_, int y_) 
	{ 
		this->p = p_; 
		this->x = x_;
		this->y = y_;
	}
};

int main ()
{
	int R, C, numQueens, numKnights, numPawns, x, y;
	int w = 1;
	while (cin >> R >> C)
	{
		if (R == 0 && C == 0)
			break;
		char board[R+1][C+1];
		for (int i=0;i<=R;++i)
			for (int j=0;j<=C;++j)
				board[i][j] = 'E';
		int TOTAL = R*C;
		int removed = 0;
		list<Piece> QK;
		cin >> numQueens;
		removed += numQueens;
		for (int i=0;i<numQueens;++i)
		{
			cin >> x >> y;
			board[x][y] = 'Q';
			QK.push_back(Piece('Q',x,y));
		}
		cin >> numKnights;
		removed += numKnights;
		for (int i=0;i<numKnights;++i)
		{
			cin >> x >> y;
			board[x][y] = 'K';
			QK.push_back(Piece('K',x,y));
		}
		cin >> numPawns;
		removed += numPawns;
		for (int i=0;i<numPawns;++i)
		{
			cin >> x >> y;
			board[x][y] = 'P';
		}
		//cout << "ORIGINAL" << endl;
		//for (int i=1;i<=R;++i){
		//	for (int j=1;j<=C;++j)
		//		cout << board[i][j];
		//	cout << endl;}
		// find unsafe squares
		//cout << "removed: " << removed << endl;
		for (list<Piece>::iterator p = QK.begin(); p != QK.end(); ++p)
		{
			if (p->p == 'Q') // queen
			{
				// check all 8 adjacent squares and outwards
				// Case 1: up
				int k = p->x;
				while (--k > 0 && (board[k][p->y] == 'E' || board[k][p->y] == 'D')) {if (board[k][p->y] == 'E' )++removed;board[k][p->y]='D';} 
				// Case 2: down
				k = p->x;
				while (++k <= R && (board[k][p->y] == 'E' || board[k][p->y] == 'D')) {if (board[k][p->y] == 'E')++removed;board[k][p->y]='D';}
				// Case 3: right
				k = p->y;
				while (++k <= C && (board[p->x][k] == 'E' || board[p->x][k] == 'D')) {if (board[p->x][k] == 'E')++removed;board[p->x][k]='D';}
				// Case 4: left
				k = p->y;
				while (--k > 0 && (board[p->x][k] == 'E' || board[p->x][k] == 'D')) {if (board[p->x][k] == 'E')++removed;board[p->x][k]='D';}
				// Case 5: up right
				k = p->x;
				int h = p->y;
				while (--k > 0 && ++h <= C && (board[k][h] == 'E' || board[k][h] == 'D')) {if (board[k][h] == 'E')++removed;board[k][h]='D';}
				// Case 6: up left
				k = p->x;
				h = p->y;
				while (--k > 0 && --h > 0 && (board[k][h] == 'E' || board[k][h] == 'D')) {if (board[k][h] == 'E')++removed;board[k][h]='D';}
				// Case 7: down left
				k = p->x;
				h = p->y;
				while (++k <= R && --h > 0 && (board[k][h] == 'E' || board[k][h] == 'D')) {if (board[k][h] == 'E')++removed;board[k][h]='D';}
				// Case 8: down right
				k = p->x;
				h = p->y;
				while (++k <= R && ++h <= C && (board[k][h] == 'E' || board[k][h] == 'D')) {if (board[k][h] == 'E')++removed;board[k][h]='D';}
			}
			else // knight
			{
				if (p->x-2 > 0 && p->y-1 > 0 && board[p->x-2][p->y-1] == 'E') {board[p->x-2][p->y-1] = 'D';++removed;} 
				if (p->x-2 > 0 && p->y+1 <= C && board[p->x-2][p->y+1] == 'E') {board[p->x-2][p->y+1] = 'D';++removed;} 
				if (p->x-1 > 0 && p->y-2 > 0 && board[p->x-1][p->y-2] == 'E') {board[p->x-1][p->y-2] = 'D';++removed;}
				if (p->x-1 > 0 && p->y+2 <= C && board[p->x-1][p->y+2] == 'E') {board[p->x-1][p->y+2] = 'D';++removed;}
				if (p->x+1 <= R && p->y-2 > 0 && board[p->x+1][p->y-2] == 'E') {board[p->x+1][p->y-2] = 'D';++removed;}
				if (p->x+1 <= R && p->y+2 <= C && board[p->x+1][p->y+2] == 'E') {board[p->x+1][p->y+2] = 'D';++removed;}
				if (p->x+2 <= R && p->y-1 > 0 && board[p->x+2][p->y-1] == 'E') {board[p->x+2][p->y-1] = 'D';++removed;}
				if (p->x+2 <= R && p->y+1 <= C && board[p->x+2][p->y+1] == 'E') {board[p->x+2][p->y+1] = 'D';++removed;}
			}
			//cout << p->p << ". removed: " << removed << endl;
			//for (int i=1;i<=R;++i){
			//	for (int j=1;j<=C;++j)
			//		cout << board[i][j];
			//	cout << endl;}
		}
		cout << "Board " << w++ << " has " << TOTAL-removed << " safe squares." << endl;
	}
}
