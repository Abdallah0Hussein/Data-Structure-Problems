#include <iostream>
#include <vector>

using namespace std;

void decToBin(int dec)
{
  vector<int> binNum;

  if (dec == 0)
  {
    cout << 0;
    return;
  }

  while (dec != 0)
  {
    if (dec % 2 > 0)
    {
      binNum.push_back(1);
    }
    else
    {
      binNum.push_back(0);
    }
    dec /= 2;
  }

  for (int i = binNum.size() - 1; i >= 0; --i)
  {
    cout << binNum[i];
  }
}

void binNumsUpToN(int n)
{
  for (int i = 1; i <= n; i++)
  {
    decToBin(i);
    cout << " ";
  }
  cout << endl;
}

int main()
{
  binNumsUpToN(10);
}