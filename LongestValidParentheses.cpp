#include <bits/stdc++.h>
#include "Containers.cpp"
using namespace std;
int longestValidParentheses(string str)
{
    Stack <char>s;
    int count = 0, ans = 0;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(')s.push('(');
        else{
            if(s.sizeStack() >= 1)
            {
                count+=2;
                s.pop();
            }
            else{
                s.clear();
                ans = max(ans, count);
                count = 0;
            }
        }
    }
    ans = max(ans, count);
    cout << ans << endl;
}
int main()
{
    Stack<char> s;
    string str;
    cin >> str;

    cout << longestValidParentheses(str);
}