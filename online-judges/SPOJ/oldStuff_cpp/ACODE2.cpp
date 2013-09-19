#include <iostream>
#include <fstream>

using namespace std;

void f (string num, int c, int s, unsigned long long &A)
{
   //cout << num << " " << c << " " << s << " " << A << endl;
   if (s == c)
   {
      ++A;
      return;
   }
   else
   {
      //cout << num << " " << c+1 << " " << s << " " << A << endl;
      if (c+1 < s)
      {
         if (int(num[c+1])-48 != 0)
         {
            f(num,c+1,s,A);               
         }
         if (int(num[c])-48 <= 2 && c+1 < s && int(num[c+1])-48 <= 6)
         {
            //cout << num << " " << c+2 << " " << s << " " << A << endl;
            f(num,c+2,s,A);
         }        
      }
      else
      {
          f(num,c+1,s,A); 
      }
   }
   
}

int main ()
{
   ifstream fin;
   fin.open("ACODE.txt");
   string num;
   while (1)
   {
      fin >> num;
      if (num == "0")
         break;
      
      unsigned long long A=0LL;
      f(num,0,num.size(),A);
      cout << A << endl;      
   }
   fin.close();
   int i;
   cin >> i;   
}
