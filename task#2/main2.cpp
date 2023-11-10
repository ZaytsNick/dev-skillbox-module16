#include <iostream>
#include <string>
using namespace std;
int main()
{
    string whole, fraction;
    cout << "Enter whole: ";
    cin >> whole;
    cout << "Enter fraction: ";
    cin >> fraction;
    double answer = stod(whole + "." + fraction);
    cout << "\n"<< answer;
}