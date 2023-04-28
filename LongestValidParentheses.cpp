#include <bits/stdc++.h>
#include "Containers.cpp"
using namespace std;
int main()
{
    Stack<char> s;
    string str;
    cin >> str;

    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            s.push('(');
        else
        {
            if (s.sizeStack() >= 1)
            {
                count += 2;
                s.pop();
            }
        }
    }
    cout << count << endl;
}