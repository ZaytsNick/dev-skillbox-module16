#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    enum switches
    {
        LIGHTS_INSIDE = 1,
        LIGHTS_OUTSIDE = 2,
        HEATERS = 4,
        WATER_PIPE_HEATING = 8,
        CONDITIONER = 16
    };

    int temperature_inside, temperature_outside, switches_state(0);
    bool movement, lights;
    string m;
    string state;
    for (int time = 19; time < 48; time++)
    {
        cout << "\nTemperature inside, temperature outside, movement, lights: ";
        getline(cin, state);
        stringstream states_sw(state);
        states_sw >> m;
        temperature_inside = stoi(m);
        states_sw >> m;
        temperature_outside = stoi(m);
        states_sw >> m;
        m == "yes" ? movement = 1 : movement = 0;
        states_sw >> m;
        m == "on" ? lights = 1 : lights = 0;
        //  #1 Как только температура снаружи падает ниже 0 °С, надо включить систему обогрева водопровода.
        //  Если температура снаружи поднялась выше 5 °С, то систему обогрева водопровода нужно отключить.
        if (temperature_outside <= 0)
        {
            if (~switches_state && WATER_PIPE_HEATING)
                cout << "\nWater pipe heating ON!";
            switches_state |= WATER_PIPE_HEATING;
        }
        else if (temperature_outside >= 5)
        {
            if (switches_state && WATER_PIPE_HEATING)
                cout << "\nWater pipe heating OFF!";
            switches_state &= ~WATER_PIPE_HEATING;
        }
        //  #2 Если на дворе вечер (время больше 16:00 и меньше 5:00 утра) и снаружи есть какое-то движение,
        //  то необходимо включить садовое освещение. Если движения нет или время не вечернее,
        //  то света снаружи быть не должно.
        if (time % 24 >= 16 || time % 24 <= 5 && movement)
        {
            if (~switches_state && LIGHTS_OUTSIDE)
                cout << "\nLights outside ON!";
            switches_state |= LIGHTS_OUTSIDE;
        }
        else
        {
            if (switches_state && LIGHTS_OUTSIDE)
                cout << "\nLights outside OFF!";
            switches_state &= ~LIGHTS_OUTSIDE;
        }

        //  #3 Если температура в помещении упала ниже 22 °С, должно включиться отопление.
        //  Как только температура равна или поднимается выше 25 °С, отопление автоматически отключается.
        if (temperature_inside >= 25)
        {
            // выкл отопление
            if (switches_state && HEATERS)
                cout << "\nHeaters OFF!";
            switches_state &= ~HEATERS;
        }

        else if (temperature_inside < 22)
        {
            // вкл отопление
            if (~switches_state && HEATERS)
                cout << "\nHeaters ON!";
            switches_state |= HEATERS;
        }

        //  #4 Если температура в помещении поднялась до 30 °С, включается кондиционер.
        //  Как только температура становится 25 °С, кондиционер отключается.
        if (temperature_inside <= 25)
        {
            // выкл кондер
            if (switches_state && CONDITIONER)
                cout << "\nConditioner OFF!";
            switches_state &= ~CONDITIONER;
        }
        else if (temperature_inside >= 30)
        {
            // вкл кондер
            if (~switches_state && CONDITIONER)
                cout << "\nConditioner ON!";
            switches_state |= CONDITIONER;
        }

        //  #5 Всё освещение в доме также умное и поддерживает настройку цветовой температуры для комфортного
        //  нахождения. Каждый день начиная с 16:00 и до 20:00 температура цвета должна плавно изменяться
        //  с 5000K до 2700К. Разумеется, это изменение должно происходить, если свет сейчас включён.
        //  В 00:00 температура сбрасывается до 5000К.
        if (lights)
        {
            if (time % 24 >= 0 || time % 24 < 16)
            {
                cout << "\nLights inside ON!\nColor temperature: " << 5000 << "K"; // температура =5000К
            }
            else if (time % 24 >= 16 && time % 24 <= 20)
            {
                cout << "\nLights inside ON!\nColor temperature: " << 2700 + 575 * (20 - time % 24) << "K"; // температура-=575*(20-time);
            }
        }
        else
            cout << "\nLights inside OFF!";
        cout << "\nTime: " << time << ":00" << endl;
    }
    // time++;
    // cout << "temperature_inside: " << temperature_inside << " \ntemperature_outside: " << temperature_outside << " \nmovement: " << movement << " \nlights: " << lights;
}