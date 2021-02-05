#define _SCL_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdlib>
#include"Serial.Port.h"
#include <windows.h>
#include <mmsystem.h>
#include <ctime>
using namespace std;

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

// Name of the COM port associated with the arduino (Changes base on device and/or usb port).
char port[] = "\\\\.\\COM6";

int main() {
	//Determines heter or not a connection was established through COM port(s).
	SerialPort arduino(port);
	if (arduino.isConnected()) {
		cout << "Connection established" << endl << endl;
	}
	else {
		cout << "Error in port name" << endl << endl;
	}

	// While the connection is established,listen for the data recieved by arduino. If the data received contains a command, execute.
	while (arduino.isConnected()) {
		string data;
		//cout << "Enter your command: " << endl;
		//cin >> data;

		char *charArray = new char[data.size() + 1];
		copy(data.begin(), data.end(), charArray);
		charArray[data.size()] = '\n';

		arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);
		arduino.readSerialPort(output, MAX_DATA_LENGTH);

		// list of key inputs sent by the arduino device.
		string phrase = output;
		string lightsOn = "lightsOn";
		string lightsOff = "lightsOff";
		string tellJoke = "tellJoke";
		string tellTime = "tellTime";
		string tellWeather = "tellWeather";
		string playSong = "playSong";
		string setReminder = "SetReminder";

		// turn on lights
		if (strstr(phrase.c_str(), lightsOn.c_str()))
		{
			cout << "Alexa, turn the lights on." << endl;
			PlaySound(TEXT("c1_lights.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(5000);
		}
		// tell a joke
		if (strstr(phrase.c_str(), tellJoke.c_str()))
		{
			cout << "Alexa, tell me a joke." << endl;
			PlaySound(TEXT("c1_joke.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(5000);
		}
		// tell the time
		if (strstr(phrase.c_str(), tellTime.c_str()))
		{
			cout << "Alexa, what time is it? " << endl;
			PlaySound(TEXT("c1_time.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(5000);
		}
		// turn off lights
		if (strstr(phrase.c_str(), lightsOff.c_str()))
		{
			cout << "Alexa, turn the lights off." << endl;
			PlaySound(TEXT("c1_lightsOff.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(5000);
		}
		// tell the weather
		if (strstr(phrase.c_str(), tellWeather.c_str()))
		{
			cout << "Alexa, what is the weather?" << endl;
			PlaySound(TEXT("c1_weather.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(5000);
		}
		// set a reminder
		if (strstr(phrase.c_str(), setReminder.c_str()))
		{
			cout << "Alexa, set a reminder. . .etc" << endl;
			PlaySound(TEXT("c1_reminder.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(5000);
		}
		// play a song
		if (strstr(phrase.c_str(), playSong.c_str()))
		{
			cout << "Alexa, play a song." << endl;
			PlaySound(TEXT("c1_playSong.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(5000);
		}

		//delete[] charArray;
	}
	return 0;
}