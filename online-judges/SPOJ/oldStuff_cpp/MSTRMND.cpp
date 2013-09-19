#include <iostream>

using namespace std;

int main ()
{
    int guess[4];
    int judge;
    guess[0] = 1; guess[1] = 1; guess[2] = 1; guess[3] = 1;
    for (int i=0;i<10;++i)
    {
        for (int j=0;j<4;++j)
            cout << guess[j] << ((j!=3)?" ":"");
        cout << endl;
        int counter = 0;
        for (int j=0;j<4;++j)
        {
            cin >> judge;
            if (judge == -1)
               guess[j]+= 1;
            else if (judge == 0)
                 guess[j] += 1;               
            else
                counter+=1;
        }
        if (counter == 4)
           break;
    }   
}
