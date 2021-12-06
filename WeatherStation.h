#pragma once
#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H
#include <string>
#include "WeatherReading.h"

class WeatherStation {
private:
    string name;
    int size;
    WeatherReading * history;
    int counter;
    bool running;
    int option;
public:
    WeatherStation(string inName, int historySize);
    ~WeatherStation();
    void input();
    void printHistory();
    void printRecent();
    void stop();
    void menu();
};

#endif //WEATHERSTATION_H
