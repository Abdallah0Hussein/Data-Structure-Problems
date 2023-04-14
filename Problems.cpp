#include <bits/stdc++.h>
#include "Containers.cpp"
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
string infix_to_postfix(string &infix)
{
    Stack operators(55); // chars
    string postfix;

    for (int i = 0; i < infix.size(); i++)
    {
        if (isdigit(infix[i])||isalpha(infix[i]))
            postfix += infix[i];
        else
        {
            while (!operators.isEmpty() && precedence(operators.peek()) >= precedence(infix[i]))
            {

                postfix += operators.pop();
            }
            operators.push(infix[i]);
        }
    }
    while (!operators.isEmpty()) // remaining
    {
        postfix += operators.pop();
    }
    return postfix;
}
int main()
{
    string x;
    cin >> x;
    cout << infix_to_postfix(x);
}