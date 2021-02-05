/* Alexa and Arduino at your fingertips
Created by: Alex Peterson on 10/2/2018

This program intercepts Serial port communication, and
plays audio files controling Alexa, based on the data recieved.
*/

#define _SCL_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cstdlib>
#include"Serial.Port.h"
#include <windows.h>
#include <mmsystem.h>
#include <ctime>
using namespace std;

// Name of the COM port associated with the arduino (Changes base on device and/or usb port).
char port[] = "\\\\.\\COM6";


int main() {
	char output[MAX_DATA_LENGTH];
	char incomingData[MAX_DATA_LENGTH];
	SerialPort arduino(port);
	string coinFlip = "flip";
	string tellFact = "fact";
	string tellQuote = "quote";
	string tellJoke = "joke";
	string tellTime = "time";
	string tellWeather = "weather";
	string playSong = "song";
	string setReminder = "reminder";
	//Determines heter or not a connection was established through COM port(s).
	if (arduino.isConnected()) {
		cout << "Connection established" << endl << endl;
	}
	else cout << "Error in port name" << endl << endl;

	// If the data received contains a command, execute.
	while (arduino.isConnected()) {
		string data;

		arduino.readSerialPort(output, MAX_DATA_LENGTH);
		cout << output << endl;
		string phrase = output;
		string s1 = "lights";
		string s2 = "joke";
		string s3 = "time";
		if (strstr(phrase.c_str(), tellFact.c_str()))
		{
			cout << "Alexa, tell me a fact." << endl;
			PlaySound(TEXT("c1_fact.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}
		else if (strstr(phrase.c_str(), tellQuote.c_str()))
		{
			cout << "Alexa, what is the quote of the day?" << endl;
			PlaySound(TEXT("c1_quote.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}
		else if (strstr(phrase.c_str(), playSong.c_str()))
		{
			cout << "Alexa, play songs by Ben Howard." << endl;
			PlaySound(TEXT("c1_playSong.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}
		else if (strstr(phrase.c_str(), tellTime.c_str()))
		{
			cout << "Alexa, what time is it? " << endl;
			PlaySound(TEXT("c1_time.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}
		else if (strstr(phrase.c_str(), coinFlip.c_str()))
		{
			cout << "Alexa, flip a coin." << endl;
			PlaySound(TEXT("c1_coinFlip.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}
		else if (strstr(phrase.c_str(), setReminder.c_str()))
		{
			cout << "Alexa, remind me to do homework at 4:00 PM." << endl;
			PlaySound(TEXT("c1_reminder.wav"), NULL, SND_FILENAME | SND_ASYNC);
			Sleep(4000);
		}
		phrase = "";
	}
	return 0;
}