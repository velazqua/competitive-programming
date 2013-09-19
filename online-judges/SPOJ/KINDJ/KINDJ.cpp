#include <iostream>

int main(int argc, const char *argv[])
{
  char c;
  bool inWord = false;
  int wordCount = 0;
  while (std::cin.get(c))
  {
    if (isalpha(c))
    {
      if (!inWord)
      {
        inWord = true;
        ++wordCount;
      }
    }
    else
    {
      inWord = false;
      if (c == '\n')
      {
        std::cout << wordCount << std::endl;
        wordCount = 0;
      }
    }
  }
  return 0;
}
