#include <bits/stdc++.h>
#include "Containers.cpp"
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}
string infix_to_postfix(string &infix)
{
    Stack<char> operators; // chars
    string postfix;

    for (int i = 0; i < infix.size(); i++)
    {
        if (isdigit(infix[i]) || isalpha(infix[i]))
            postfix += infix[i];

        else if (infix[i] == '(')
            operators.push(infix[i]);

        else if (infix[i] == ')')
        {
            while (operators.top() != '(')
            {
                postfix += operators.pop();
            }
            operators.pop();
        }
        else
        // 2^3^4 -->>> 23^4^ wrong
        { // 2^3^4 -->>> 234^^ right as 2^3^4 = 2^(3^4) in Mathematics
            while (!operators.isEmpty() && (precedence(operators.top()) > precedence(infix[i]) || precedence(operators.top()) == precedence(infix[i]) && infix[i] != '^'))
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
    getline(cin, x); // getline as cin takes the input when typing any space
    string x_withoutSpace = "";
    for (const char &i : x) //& to avoid creating the copying of the character for each iteration
    {
        if (i == ' ')
            continue;
        x_withoutSpace += i;
    }
    cout << infix_to_postfix(x_withoutSpace);
}
