		/*
		int deliver;
		int turn = 1;
		bool onStrike = false;
		bool onSpare = false;
		while( frames < 9 )
		{
			cin >> deliver;
			if( deliver == 10 ) // strike
			{
				++frames;
				bonus += 10;
				turn = 1;
				onStrike = true;
			}
			else
			{
				if( turn == 1 ) // first deliver
				{
					// add score of current frame
					score += deliver;
					if( onSpare )
					{
						totalScore += bonus + score;
						bonus = 0;
						onSpare = false;
					}
					turn = 2;
				}
				else // second deliver
				{
					// add score of current frame
					score += deliver;
					if( score == 10 ) // spare
					{
						bonus += 10;
						onSpare = true;
					}
					if( onStrike )
					{
						totalScore += score+bonus;
						bonus = 0;
						onStrike = false;
					}
					totalScore += score;
					score = 0;
					turn = 1;
					++frames;
				}
			}
			cout << totalScore << endl;
		}
		// last frame is done separately
		int firstTurn, secondTurn, thirdTurn=0;
		cin >> firstTurn >> secondTurn;
		if( firstTurn == 10 || firstTurn+secondTurn == 10 )
		{
			cin >> thirdTurn;
		}
		totalScore += firstTurn + secondTurn + thirdTurn;
		cout << "==> " << totalScore+bonus << endl;
		*/
