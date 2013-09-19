/* Name: Alex Velazquez
 * Start Date: October 02, 2011 @ 05:55PM
 * End Date:   October 02, 2011 @ ???
 * Purpose: To solve the SPOJ problem TWENDS - Two Ends
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct State {
	int S1;
	int S2;
	int i;
	int j;
	State (int s1, int s2, int ii, int jj) : S1(s1), S2(s2), i(ii), j(jj) {}
};

bool operator < (State const& A, State const& B)
{
	if (A.i < B.i)
		return true;
	else if (A.i > B.i)
		return false;
	else
	{
		if (A.j < B.j)
			return true;
		else
			return false;
	}
}

ostream& operator << (ostream& os, State const& S)
{
	os << "(" << S.S1 << "," << S.S2 << "). i: ";
	os << S.i << ". j: " << S.j;
	return os; 
}

int main ()
{
	int N, t, k = 1;
	while (1)
	{
		cin >> N;
		if (N == 0)
			break;
		vector<int> nums;
		for (int i=0;i<N;++i)
		{
			cin >> t;
			nums.push_back(t);
		}
		set<State> gameStates;
		gameStates.insert(State(0,0,0,(int)nums.size()-1));
		int indx, nextI, nextJ;
		for (int i=0;i<(int)nums.size()/2;++i)
		{
			//cout << "Tree level: " << i << endl;
			//cout << "Game States: " << endl;
			set<State> newStates;
			for (set<State>::iterator it = gameStates.begin();it!=gameStates.end();++it)
			{
				//cout << "Parent card: " << endl;
				//cout << *it << endl;
				// select card on left end
				if (nums[it->i+1] >= nums[it->j])
				{
					indx=it->i+1;
					nextI=it->i+2;
					nextJ=it->j;
				}
				else
				{
					indx=it->j;
					nextI=it->i+1;
					nextJ=it->j-1;
				}
				State leftCard(it->S1+nums[it->i],it->S2+nums[indx],nextI,nextJ);
				
				// select card on right end
				if (nums[it->i] >= nums[it->j-1])
				{
					indx=it->i;
					nextI=it->i+1;
					nextJ=it->j-1;
				}
				else
				{
					indx=it->j-1;
					nextI=it->i;
					nextJ=it->j-2;
				}
				State rightCard(it->S1+nums[it->j],it->S2+nums[indx],nextI,nextJ);
				//cout << "Left card: " << endl;
				//cout << leftCard << endl;
				//cout << "Right card: " << endl;
				//cout << rightCard << endl;
				pair<set<State>::iterator,bool> result = newStates.insert(leftCard);
				if (result.second == false) // duplicate indexes
				{
					// find out which state has more net points for player 1
					if (leftCard.S1-leftCard.S2 >= result.first->S1-result.first->S2)
					{
						newStates.erase(result.first);
						newStates.insert(leftCard);
					}
				}
				result = newStates.insert(rightCard);
				if (result.second == false) // duplicate indexes
				{
					// find out which state has more net points for player 1
					if (rightCard.S1-rightCard.S2 >= result.first->S1-result.first->S2)
					{
						newStates.erase(result.first);
						newStates.insert(rightCard);
					}
				}
				newStates.insert(rightCard);
			}
			gameStates=newStates;
		}
		int maxScore=0;
		for (set<State>::iterator it = gameStates.begin();it!=gameStates.end();++it)
		{
			if (it->S1-it->S2 > maxScore)
				maxScore = it->S1-it->S2;
		}
		cout << "In game " << k << ", the greedy strategy might lose by as many as ";
		cout << maxScore << " points." << endl;
		++k;
	}
}
