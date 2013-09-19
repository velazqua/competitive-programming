#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string word;
    int n;
    while (cin >> word && word != "." && cin >> n)
    {
          for (int j=0;j<(int)word.size();++j)
          {
             cout << word.substr(j,(int)word.size()-j);
             // in between
             for (int i=0;i<n-1;++i)
                  cout << word;      
             cout << word.substr(0,j) << endl;
          }
    }   

}
