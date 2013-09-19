#include <iostream>
#include <vector> // for std::vector
#include <set> // for std::set
#include <utility> //for std::pair and std::std::make_pair
#include <list> // for std::std::list
#include <algorithm> // for for_each

// to generate random moves for AI and turns
#include "boost/random.hpp"
#include "boost/generator_iterator.hpp"
	
template <typename P>
class Pieces {
	public:
		P Empty;
		P Player1;
		P Player2;
		
		typedef P value_type;
		
		// constructors
		Pieces () {}
		Pieces (P E, P p1, P p2) : Empty(E), Player1(p1), Player2(p2) {}
		
		// assignment operator
		Pieces& operator = (Pieces const& p)
		{
			this->Empty = p.Empty;
			this->Player1 = p.Player1;
			this->Player2 = p.Player2;
			return *this;
		}

};

template <typename T>
class Cell {
	public:
		int column;
		int row;
		T value;
		
		Cell (int c, int r, T val) : column(c), row(r), value(val) {}

		// check if two cells are identical. i.e. do they contain the same value ?
		
		bool operator == (Cell<T> const& c)
		{
			return (this->value == c.value)?true:false;
		}
};

// this '<' operator was implemented so that we could have a set of Cells .. the implementation is kind of irrelevant
template <typename T>
bool operator < (Cell<T> const& a, Cell<T> const& b)
{
	if (a.column < b.column)
		return true;
	else if (a.column > b.column)
		return false;
	else
	{
		if (a.row < b.row)
			return true;
		else
			return false;
	}
}

template <typename T>
bool operator > (Cell<T> const& a, Cell<T> const& b)
{
	return (b<a)?true:false;
}
		

template <typename T>
std::ostream& operator << (std::ostream& os, const Cell<T> & c)
{
	os << "(" << c.column << "," << c.row << ")";
	return os;
}


//Functor used to display the the winning pieces at the end of the game
template <typename P>
struct displayWinner {
	void operator () (Cell<P> c)
	{
		std::cout << c << " ";
	}
};

template <typename P>
class ConnectN {
	public:
		int N;	// Amount of elements in a row
		int R;	// Amount of rows
		int C;	// Amount of columns
	
		typedef std::vector< Cell<P> > COLUMN; 
		typedef std::vector<std::pair<COLUMN,int> > BOARD;
		typedef typename BOARD::iterator BOARD_ITER;
		typedef typename BOARD::reverse_iterator REV_BOARD_ITER;
		typedef typename COLUMN::iterator COL_ITER;
		typedef typename COLUMN::reverse_iterator REV_COL_ITER;
		
		Pieces<P> pieces; // pieces that will be used in the game
		BOARD board; 
		
		/* Constructor */
		ConnectN (Pieces<P> p, int numberOfPieces, int numberOfRows, int numberOfColumns)
			: N(numberOfPieces), R(numberOfRows), C(numberOfColumns) 
		{	
			pieces = p;
			
			// Creation of board
			// 	- C vectors of size R
			for (int i=0;i<C;++i)
			{
				// create C columns with R spaces available
				board.push_back(std::make_pair(COLUMN(),R));
				REV_BOARD_ITER rit = board.rbegin(); // iterator to the last inserted column
				for (int j=0;j<R;++j)
				{
					// populate each column with R pieces
					rit->first.push_back(Cell<P>(i+1,R-j,pieces.Empty));
				}
			}
		}
		
		
		/*	This member function checks for vertical connect N
		 * 	Returns a pair (int, list) 
		 * 		-> 1  and a list that represents the winning pieces if player 1 won
		 * 		-> -1 and a list that represents the winning pieces if player 2 won
		 *		-> -2 and an empty list if nothing found
		*/

		std::pair<int,std::list <Cell<P> > > NinRowV (int col, int f, int l)
		{	
			for (int i=0;i<l-f-N+1;++i)
			{
				std::set<P> equal; //used to check if pieces are equal
				std::list<Cell<P> > cells; //used to return winning pieces
				for (int j=0;j<N;++j)
				{
					equal.insert(board[col].first[f+i+j].value);
					cells.push_back(board[col].first[f+i+j]);
				}	
				
				// check who won
				if (equal.size() == 1 && *(equal.begin()) == pieces.Player1)
					return std::make_pair(1,cells);
				else if (equal.size() == 1 && *(equal.begin()) == pieces.Player2)
					return std::make_pair(-1,cells);
			}
			return std::make_pair(-2,std::list<Cell<P> >());
		}
		
		
		/*	This member function checks for horizontal connect N
		 * 	Returns a pair (int, list) 
		 * 		-> 1  and a list that represents the winning pieces if player 1 won
		 * 		-> -1 and a list that represents the winning pieces if player 2 won
		 *		-> -2 and an empty list if nothing found
		*/
		std::pair<int,std::list <Cell<P> > > NinRowH (int row)
		{
			for (int i=0;i<C-N+1;++i)
			{
				std::set<P> equal;
				std::list<Cell<P> > cells;
				for (int j=0;j<N;++j)
				{
					equal.insert(board[i+j].first[row].value);
					cells.push_back(board[i+j].first[row]);
				}
				
				//check who won. 
				if (equal.size() == 1 && *(equal.begin()) == pieces.Player1)
					return std::make_pair(1,cells);
				else if (equal.size() == 1 && *(equal.begin()) == pieces.Player2)
					return std::make_pair(-1,cells);
			}
			return std::make_pair(-2,std::list<Cell<P> >());
		}
				
		/*	This member function checks if the game is over 
		 * 	Returns a pair (int, list) 
		 * 		-> 1  and a list that represents the winning pieces if player 1 won
		 * 		-> 0 and an empty list if a draw
		 * 		-> -1 and a list that represents the winning pieces if player 2 won
		 *		-> -2 and an empty list if nothing found (continue game)
		*/
		
		
		std::pair<int,std::list <Cell<P> > > gameOver (void)
		{			
			//check for vertical n-in-a-row
			for (int i=0;i<C;++i)
			{
				std::pair<int,std::list<Cell<P> > > w;
				// if there are at least n elements in the column
				if (R-board[i].second >= N) 
				{
					w = NinRowV(i,board[i].second,R);
					if (w.first == 1||w.first == -1) return w;
				}
			}

			// min (all cols)
			//check for horizontal n-in-a-row
			for (int i=R-1;i>=0;--i)
			{
				std::pair<int,std::list<Cell<P> > > w = NinRowH(i);
				if (w.first == 1||w.first == -1) return w;
			}
			
			//check for diagonal n-in-a-row (down right)
			
			for (int i=N-1;i<C;++i)
			{
				for (int j=N-1;j<R;++j)
				{
					std::set<P> equal;
					std::list<Cell<P> > cells;
					for (int k=0;k<N;++k)
					{
						equal.insert(board[i-k].first[j-k].value);
						cells.push_back(board[i-k].first[j-k]);
					}
						
					if (equal.size() == 1 && *(equal.begin()) == pieces.Player1)
						return std::make_pair(1,cells);
					else if (equal.size() == 1 && *(equal.begin()) == pieces.Player2)
						return std::make_pair(-1,cells);
				}
			}
			
			//check for diagonal n-in-a-row (up right)
			for (int i=0;i<C-N+1;++i)
			{
				for (int j=N-1;j<R;++j)
				{
					std::set<P> equal;
					std::list<Cell<P> > cells;
					for (int k=0;k<N;++k)
					{
						equal.insert(board[i+k].first[j-k].value);
						cells.push_back(board[i+k].first[j-k]);
					}
					
					if (equal.size() == 1 && *(equal.begin()) == pieces.Player1)
						return std::make_pair(1,cells);
					else if (equal.size() == 1 && *(equal.begin()) == pieces.Player2)
						return std::make_pair(-1,cells);
				}
			}		
			//check for empty square
			for (int i=0;i<C;++i)
				for (int j=0;j<R;++j)
					if (board[i].first[j].value == pieces.Empty)
						return std::make_pair(-2,std::list<Cell<P> >());
			
			//draw
			return std::make_pair(0,std::list<Cell<P> >());
		}
		
		
		/* This member function displays the current status of the game */
		void displayGame (void)
		{
			for (int i=0;i<R;++i)
			{
				std::cout << "#|";
				for (int j=0;j<C;++j)
					std::cout << board[j].first[i].value << "|";
				std::cout << "# " << R-i << std::endl;
			}
			
			// formatting output .. only works with pieces of length 1
			std::cout << "  ";
			for (int k=1;k<=C;++k)
				std::cout << k/10 << " ";
			std::cout << std::endl;
				
			std::cout << "  ";
			for (int k=1;k<=C;++k)
				std::cout << k%10 << " ";
			std::cout << std::endl;
		}
		
		// Input: player (which piece to display), and col (which column to insert)
		// Output:
		// 		- returns true if successful
		// 		- return false if not successful
		
		bool applyMove (int player,int col)
		{
			P s;
			if (player == 0) s = pieces.Player1; //player1
			else s = pieces.Player2;
			if (invalidCol(col)||isColFull(col)) // check if column is full or invalid col
				return false;
			else
				board[col-1].first[--board[col-1].second].value = s;
			return true;
		}
		
		// Checks if a column is full
		bool isColFull (int col)
		{
			return (board[col-1].second == 0)? true:false;
		}				
		
		//checks for invalid column
		bool invalidCol (int col)
		{
			return (col < 1 || col > C)?true:false;
		}
};

int main ()
{
	using namespace std;
	using namespace boost;

	int numPieces, numRows, numCols;	

	typedef Pieces<string> PIECE;
	typedef PIECE::value_type VAL;
	
	PIECE p(".","x","o");
	ConnectN<VAL> C4(p,numPieces,numRows,numCols);
	
	int col; // column input
	int player=0;
	
	bool AI=false;
	bool gameOn=true;
	while (gameOn)
	{
		//if it's the AI's turn ..
		if (AI && player%2==AIturn)
		{
			cout << "AI's turn: " << endl;
			while (true)
			{
				col = dice(); 
				// generate a number number until it finds an empty column
				if (!C4.isColFull(col)) 
					break;
			}
			C4.applyMove(player%2,col);
		}
		else
		{
			do {
				cout << "Player " << player%2+1 << "'s turn: " << endl;
				if (cin >> col)
				{
					if (C4.applyMove(player%2,col))
						break;
				}
				else //if cin fails
				{
					cin.clear();
					cin.ignore();
				}
			} while (true);
		}
		
		C4.displayGame();
		
		pair<int,list<Cell<VAL> > > line = C4.gameOver();
		switch (line.first)
		{
			case 1 :
				if (AI && player%2==AIturn)
					cout << "AI wins!" << endl;
				else
					cout << "Player 1 wins!" << endl;
		
				// display the indices on the board of winning pieces
				for_each(line.second.begin(),line.second.end(),displayWinner<VAL>());
		
				gameOn=false;
				break;
			case -1 : 
				if (AI && player%2==AIturn)
					cout << "AI wins!" << endl;
				else
					cout << "Player 2 wins!" << endl;
		
				// display the indices on the board of winning pieces
				for_each(line.second.begin(),line.second.end(),displayWinner<VAL>());
		
				gameOn=false;
				break;
			case 0 : cout << "Draw!" << endl;gameOn=false;break;
		}
		
		player++;
	}	
}

