#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <list>

using namespace std;

int main ()
{
   string sentence;
   while (1)
   {
      cin >> sentence;
      if (sentence == "*")
         break;
      transform(sentence.begin(),sentence.end(),sentence.begin(),::tolower);
      list<string> words;
      istringstream iss(sentence);
      //copy(istream_iterator<string>(iss),
      //     istream_iterator<string>(),
      //     back_inserter<list<string> >(words));
      string word;
      while (iss >> word)
         words.push_back(word);
      
      list<string>::iterator first=words.begin();
      string::iterator f = first->begin();
      bool t = false;
      for (list<string>::iterator it=words.begin();it!=words.end();++it)
      {
          cout << *it << " " << (*it)[0] << " " << *f << endl;
          /*
          if ((*it)[0] != f)
          {
             cout << "N" << endl;
             t = true;
             break;
          }
          */
      }
      if (!t)
         cout << "Y" << endl;
      
   }   
}
