// pre-processor directives
#define _SCL_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdlib>
#include"SerialPort.h"
#include <windows.h>
#include <mmsystem.h>
#include <ctime>
using namespace std;

// global variables and commands
char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];
char port[] = "\\\\.\\COM6";

string phrase = "";
const string coinFlip = "c1";
const string tellQuote = "c3";
const string tellJoke = "c4";
const string tellWeather = "c2";
const string playSong = "c6";
const string setReminder = "c5";


int main() {

	SerialPort arduino(port);

	if (arduino.isConnected()) {
		cout << "Connection established" << endl << endl;
	}
	else {
		cout << "Error in port name" << endl << endl;
	}

	while (arduino.isConnected()) {
		arduino.readSerialPort(output, MAX_DATA_LENGTH);
		phrase = output;

		// if command is recognizeed, play output audio

		// flip a coin
		if (strstr(phrase.c_str(), coinFlip.c_str()))
		{
			cout << "Alexa, flip a coin." << endl;
			PlaySound(TEXT("c1_coinFlip.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}
		// weather
		else if (strstr(phrase.c_str(), tellWeather.c_str()))
		{
			cout << "Alexa, what is the weather in Riverside?" << endl;
			PlaySound(TEXT("c1_weather.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}
		//quote
		else if (strstr(phrase.c_str(), tellQuote.c_str()))
		{
			cout << "Alexa, tell me a quote." << endl;
			PlaySound(TEXT("c1_quote.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}
		//reminder
		else if (strstr(phrase.c_str(), setReminder.c_str()))
		{
			cout << "Alexa, remind me to do homework at 4:00 PM. " << endl;
			PlaySound(TEXT("c1_reminder.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}
		//joke
		else if (strstr(phrase.c_str(), tellJoke.c_str()))
		{
			cout << "Alexa, tell a joke." << endl;
			PlaySound(TEXT("c1_joke.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}
		//song
		else if (strstr(phrase.c_str(), playSong.c_str()))
		{
			cout << "Alexa, play songs by Ben Howard." << endl;
			PlaySound(TEXT("c1_playSong.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}

	}

	return 0;

}