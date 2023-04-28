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
// string infix_to_postfix(string &infix)
// {
//     Stack<char> operators; // chars
//     string postfix;

//     for (int i = 0; i < infix.size(); i++)
//     {
//         if (isdigit(infix[i]) || isalpha(infix[i]))
//             postfix += infix[i];

//         else if (infix[i] == '(')
//             operators.push(infix[i]);

//         else if (infix[i] == ')')
//         {
//             while (operators.peek() != '(')
//             {
//                 postfix += operators.pop();
//             }
//             operators.pop();
//         }
//         else
//         // 2^3^4 -->>> 23^4^ wrong
//         { // 2^3^4 -->>> 234^^ right
//             while (!operators.isEmpty() && (precedence(operators.peek()) > precedence(infix[i]) || precedence(operators.peek()) == precedence(infix[i]) && infix[i] != '^'))
//             {
//                 postfix += operators.pop();
//             }
//             operators.push(infix[i]);
//         }
//     }
//     while (!operators.isEmpty()) // remaining
//     {
//         postfix += operators.pop();
//     }
//     return postfix;
// }
int main()
{
//     string x;
//     cin >> x;
//     cout << infix_to_postfix(x);
    SLL<int> lst;
    lst.insertAtHead(2);
    lst.insertAtHead(3);
    lst.insertAtHead(4);
    lst.insertAtHead(0);
    lst.insertAtHead(5);
    lst.print();
    lst.removeAt(0);
    lst.print();

}
