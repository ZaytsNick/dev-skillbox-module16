#include <iostream>
using namespace std;
int main()
{

    float delta, speed(0);
    do
    {

        char speed_str[5];
        cout << "\nSpeed delta: ";
        cin >> delta;
        speed += delta;
        sprintf(speed_str, "%.1f", speed);
        cout << "\nSpeed: " << speed_str;
    } while (delta + 0.01 > 0);
}