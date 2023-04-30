#include <bits/stdc++.h>
#include "Containers.cpp"
using namespace std;

int precedence(char op) // to know the precedence of each operator
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
            while (operators.top() != '(') // as long as u didn't find the starting bracket
                                // this means that the elements in stack were between brackets
            {
                // so when u find an open bracket put and pop all stack elements in postfix
                postfix += operators.pop();
            }
            operators.pop();
            // to delete the open bracket
            // as the previous while loop pop the stack elements except the open bracket
        }
        else
        // the program enters here when it has an operators +-/*^
        // so we should add the operator to stack or add it to string and pop the whole stack
        {
            while (!operators.isEmpty() && (precedence(operators.top()) > precedence(infix[i]) || precedence(operators.top()) == precedence(infix[i]) && infix[i] != '^'))
            { // if the precedence of stack top > precedence of infix [i]
                // if the precedence of stack top == precedence of infix [i] and the operator isn't '^'
                // 2^3^4 -->>> 23^4^ wrong
                // 2^3^4 -->>> 234^^ right as 2^3^4 = 2^(3^4) in Mathematics
                // then put and pop all stack elements in postfix
                postfix += operators.pop();
            }

            operators.push(infix[i]); // push operator in stack
        }
    }
    while (!operators.isEmpty()) // remaining operators
    // as the previous loop that iterate through infix is ended
    // but the stack still has operators that hasn't been added to postfix or pooped from the stack
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
    for (const char &i : x) // & to avoid creating the copying of the character for each iteration
    {
        if (i == ' ')
            continue;
        x_withoutSpace += i;
    }
    cout << infix_to_postfix(x_withoutSpace);
}
