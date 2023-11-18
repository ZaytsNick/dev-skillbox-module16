#include <iostream>
#include <sstream>
// #include <string>

using namespace std;

int main()
{
    string buffer;
    cout << "Enter expression: ";
    cin >> buffer;
    double a, b;
    char operation;
    stringstream stream(buffer);
    stream >> a >> operation >> b;
    cout << a << operation << b << "=";
    switch (operation)
    {
    case '+':
        cout << a + b;
        break;
    case '-':
        cout << a - b;
        break;
    case '*':
        cout << a * b;
        break;
    case '/':
        cout << a / b;
        break;
    }
}