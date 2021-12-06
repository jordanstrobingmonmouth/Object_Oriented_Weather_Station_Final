#pragma once
#ifndef WEATHERREADING_H
#define WEATHERREADING_H
#include <string>
#include <iostream>
using namespace std;

class WeatherReading {
private:
    double temp;
    int speed;
    string direction;
public:
    WeatherReading();
    WeatherReading(double inTemp, int inSpeed, string inDirection);
    void setTemp(double inTemp);
    void setSpeed(int inSpeed);
    void setDirection(string inDirection);
    double getTemp();
    int getSpeed();
    string getDirection();
    void print();
};

#endif //WEATHERREADING_H
