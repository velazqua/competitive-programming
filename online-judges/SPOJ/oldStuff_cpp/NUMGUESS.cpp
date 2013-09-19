#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

void binarySearch (int lower, int upper, int guess)
{
     string judge;
     cout << guess << endl;
     cin >> judge;
     if (judge == "LOW"){
        if (guess == int((guess+upper)/2.0))
           binarySearch(guess+1,upper,guess+1);
        else
            binarySearch(guess,upper,(int)ceil((guess+upper)/2.0));}
     else if (judge == "HIGH")
        binarySearch(lower,guess,(int)floor((guess+lower)/2.0));
}

int main ()
{
    int lower, upper;
    int guess;
    string judge;
    cin >> lower >> upper;
    guess = (int)(lower+upper)/2.0;
    binarySearch(lower,upper,guess);   
}
