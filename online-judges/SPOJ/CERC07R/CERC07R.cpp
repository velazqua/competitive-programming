/* Alex Velazquez
 * Start: November 10, 2011 @ 10:49PM
 * End  : November 10, 2011 @ 11:16PM
*/

#include <iostream>
#include <map>

using namespace std;

void whoWon( int &score1, int &score2, int num1, int num2 )
{
	if( num1 != num2 )
	{
		if( num1 == 0 && num2 == 1 ) ++score1;
		if( num2 == 0 && num1 == 1 ) ++score2;
		if( num1 == 0 && num2 == 2 ) ++score2;
		if( num2 == 0 && num1 == 2 ) ++score1;
		if( num1 == 1 && num2 == 2 ) ++score1;
		if( num2 == 1 && num1 == 2 ) ++score2;
	}
}

int main ()
{
	map<string,map<string,int> > table;
	table["cs"]["Kamen"] = 0; table["cs"]["Nuzky"] = 1; table["cs"]["Papir"] = 2;
	table["en"]["Rock"] = 0; table["en"]["Scissors"] = 1; table["en"]["Paper"] = 2;
	table["fr"]["Pierre"] = 0; table["fr"]["Ciseaux"] = 1; table["fr"]["Feuille"] = 2;
	table["de"]["Stein"] = 0; table["de"]["Schere"] = 1; table["de"]["Papier"] = 2;
	table["hu"]["Ko"] = 0; table["hu"]["Ollo"] = 1; table["hu"]["Papir"] = 2;
	table["hu"]["Koe"] = 0; table["hu"]["Olloo"] = 1; 
	table["it"]["Sasso"] = 0; table["it"]["Forbice"] = 1; table["it"]["Carta"] = 2;
	table["it"]["Roccia"] = 0; table["it"]["Rete"] = 2;
	table["jp"]["Guu"] = 0; table["jp"]["Choki"] = 1; table["jp"]["Paa"] = 2;
	table["pl"]["Kamien"] = 0; table["pl"]["Nozyce"] = 1; table["pl"]["Papier"] = 2;
	table["es"]["Piedra"] = 0; table["es"]["Tijera"] = 1; table["es"]["Papel"] = 2;
	bool gameOver = false;
	int i = 1;
	while( 1 )
	{
		string lang1, lang2, name1, name2;
		cin >> lang1;
		if( lang1 == "." )
			break;
		else if ( lang1 == "-" )
			continue;
		cin >> name1;
		cin >> lang2 >> name2;
		int score1 = 0, score2 = 0;
		while( 1 )
		{
			string choice1, choice2;
			cin >> choice1;
			if( choice1 == "." )
			{
				gameOver = true;
				break;
			}
			else if( choice1 == "-" )
			{
				break;
			}
			cin >> choice2;
			whoWon( score1, 
					score2, 
					table[lang1][choice1],
					table[lang2][choice2] );
		}
		cout << "Game #" << i++ << ":" << endl;
		cout << name1 << ": " << score1 << " point" << ((score1 == 1)?"":"s") << endl;
		cout << name2 << ": " << score2 << " point" << ((score2 == 1)?"":"s") << endl;
		if( score1 == score2 )
			cout << "TIED GAME" << endl;
		else
			cout << "WINNER: " << ( ( score1 > score2 ) ? name1 : name2 ) << endl;
		if( gameOver )
			break;
		else
			cout << endl;
	}
}

