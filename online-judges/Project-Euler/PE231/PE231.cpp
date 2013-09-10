#include <iostream>
#include <list>
using namespace std;

int main ()
{
    int N=10, R=3, K=N-R;
    int LIMIT=N-R;
    list<int> NUM;
    list<int> DEN;
    for (int i=N;i>LIMIT && R != 1;--i)
    {
        NUM.push_back(i);
        DEN.push_back(R);
        for (list<int>::iterator it=NUM.begin();it!=NUM.end();++it){
            for (list<int>::iterator jt=DEN.begin();jt!=DEN.end();++jt){
            if (*it%*jt==0){ // if divisible
               NUM.push_back(*it / *jt);
               NUM.erase(it);
               DEN.erase(jt);
            }
        }
    }
        R--;
    }    //cout << i << endl;
    cin >> N;
}
