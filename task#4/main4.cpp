#include <iostream>
#include <string>
using namespace std;
int main()
{
    enum note
    {
        DO = 1,
        RE = 2,
        MI = 4,
        FA = 8,
        SOL = 16,
        LA = 32,
        SI = 64
    };
    int melody[12];
    string combo;
    for (int i = 0; i < 12; ++i)
    {
        cout << "Enter combo notes #" << i + 1 << ": ";
        cin >> combo;
        melody[i] = stoi(combo);
    }
    for (int i = 0; i < 12; ++i)
    {
        if (melody[i] & DO)
            std::cout << "DO ";
        if (melody[i] & RE)
            std::cout << "RE ";
        if (melody[i] & MI)
            std::cout << "MI ";
        if (melody[i] & FA)
            std::cout << "FA ";
        if (melody[i] & SOL)
            std::cout << "SOL ";
        if (melody[i] & DO)
            std::cout << "LA ";
        if (melody[i] & DO)
            std::cout << "SI ";
        cout<<"\n";
    }

}