#include <iostream>
#include <string>

using namespace std;

int main()
{
    enum action
    {
        addition = '+',
        subtraction = '-',
        multiplication = '*',
        division = '/'
    };
    string condition, Snumber1(""), Snumber2("");
    int act(0);
    cout << "Enter expression: ";
    cin >> condition;
    for (int i = 0; i < condition.size(); i++)
    {
        if (condition[i] == action::addition || action::division || action::multiplication || action::subtraction)
        {
            act = i;
            continue;
        }
        else if (!act)
            Snumber1 += condition[i];
        if (act)
            Snumber1 += condition[i];
    }

    double number1 = stod(Snumber1);
    double number2 = stod(Snumber2);
    if (condition[act] == action::addition)
        cout << number1 << action::addition << number2 << "=" << number1 + number2;
    else if (condition[act] == action::division)
        cout << number1 << action::division << number2 << "=" << number1 + number2;
    else if (condition[act] == action::multiplication)
        cout << number1 << action::multiplication << number2 << "=" << number1 + number2;
    else if (condition[act] == action::subtraction)
        cout << number1 << action::subtraction << number2 << "=" << number1 + number2;
}