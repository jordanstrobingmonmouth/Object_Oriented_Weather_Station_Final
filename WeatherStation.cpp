#include "WeatherStation.h"
#include "WeatherReading.h"
#include <string>
#include <iostream>
using namespace std;

WeatherStation::WeatherStation(string inName, int historySize) {
    running = true;
    counter = 0;
    name = inName;
    size = historySize;
    history = new WeatherReading[size];
}
WeatherStation::~WeatherStation() {
    delete[] history;
    history = NULL;
}
void WeatherStation::input() {
    counter++;
    double temp;
    int speed;
    string direction;
    cout << "What is the current temperature? " << endl;
    cin >> temp;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, type in a valid temperature: ";
        cin >> temp;
    }

    cout << "What is the wind speed? " << endl;
    cin >> speed;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, type in a valid speed: ";
        cin >> speed;
    }

    cin.ignore(1000, '\n');
    cout << "What is the wind direction? " << endl;
    getline(cin, direction);

    if (counter > size) {
        for (int i = 0; i < size - 1; i++) {
            history[i].setTemp(history[i + 1].getTemp());
            history[i].setSpeed(history[i + 1].getSpeed());
            history[i].setDirection(history[i + 1].getDirection());
        }

        WeatherReading w(temp, speed, direction);
        history[size-1] = w;

    }
    else if (counter <= size) {
        WeatherReading w(temp, speed, direction);
        history[counter-1] = w;
    }
}
void WeatherStation::printHistory() {
    if (counter < size) {
        for (int i = counter - 1; i >= 0; i--) {
            cout << "The " << name << " Weather Station" << endl;
            history[i].print();

            if (i > 0) {
                cout << endl;
            }
        }
    }
    else {
        for (int i = size - 1; i >= 0; i--) {
            cout << "The " << name << " Weather Station" << endl;
            history[i].print();

            if (i > 0) {
                cout << endl;
            }
        }
    }
}
void WeatherStation::printRecent() {
    if (counter < size) {
        cout << "The " << name << " Weather Station" << endl;
        history[counter-1].print();
    }
    else {
        cout << "The " << name << " Weather Station" << endl;
        history[size-1].print();
    }
}
void WeatherStation::stop() {
    running = false;
}
void WeatherStation::menu() {
    bool canPrint = false;
    while (running) {
        cout << "\nChoose which option you'd like (1, 2, 3 or 4):" << endl;
        cout << "OPTION 1: Input" << endl;
        cout << "OPTION 2: Print recent input" << endl;
        cout << "OPTION 3: Print up to " << size << " inputs" << endl;
        cout << "OPTION 4: Exit" << endl;

        cin >> option;
        if (option == 1) {
            input();
            canPrint = true;
        }
        else if (option == 2) {
            if (!canPrint) {
                cout << "No data to print." << endl;
                continue;
            }
            printRecent();
        }
        else if (option == 3) {
            if (!canPrint) {
                cout << "No data to print." << endl;
                continue;
            }
            printHistory();
        }
        else if (option == 4) {
            stop();
        }
        else {
            cout << "Invalid input" << endl;
            continue;
        }
    }
}

