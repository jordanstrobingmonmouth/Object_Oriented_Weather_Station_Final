#include "WeatherReading.h"
#include <string>
#include <iostream>
using namespace std;

WeatherReading::WeatherReading() {
    //default values
    temp = -1000;
    speed = -1000;
    direction = "N/A";
}
WeatherReading::WeatherReading(double inTemp, int inSpeed, string inDirection) {
    temp = inTemp;
    speed = inSpeed;
    direction = inDirection;
}
void WeatherReading::setTemp(double inTemp) {
    temp = inTemp;
}
void WeatherReading::setSpeed(int inSpeed) {
    speed = inSpeed;
}
void WeatherReading::setDirection(string inDirection) {
    direction = inDirection;
}
double WeatherReading::getTemp() {
    return temp;
}
int WeatherReading::getSpeed() {
    return speed;
}
string WeatherReading::getDirection() {
    return direction;
}
void WeatherReading::print() {
    cout << "Temperature: " << temp << endl;
    cout << "Wind speed: " << speed << "\tDirection: " << direction << endl;
}

