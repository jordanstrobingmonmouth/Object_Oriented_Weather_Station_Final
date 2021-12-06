#include <iostream>
#include <string>
#include "WeatherStation.h"
using namespace std;

int main() {
    string name = "";
    int size = 0;

    cout << "What is the name of the weather station? " << endl;
    getline(cin, name);

    cout << "How many inputs do you want to save? " << endl;
    cin >> size;

    WeatherStation w1(name, size);
    w1.menu();
    return 0;
}
