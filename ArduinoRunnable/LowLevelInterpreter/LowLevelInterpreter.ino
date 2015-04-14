/**
This is the low level aspect of theArduino Interpreter Project
(initially) performed for CS 554 Compiler construction at WPI.
**/
#include <QueueList.h> //from http://playground.arduino.cc/Code/QueueList

//First things first, define a bunch of masking functions
QueueList<char> parse(String input);

//initialize the constant token values here
const char INVALID   = 0;
const char END       = 1;
const char INT       = 2;
const char FLOAT     = 3;
const char READ      = 4;
const char SET       = 5;
const char DIGITAL   = 6;
const char ANALOG    = 7;

//Initialize globals
QueueList<char> tokens;

/**
This only runs once
**/
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

/**
This loops over and over again
**/
void loop() {
  Serial.println("Yo Deadbolt!");
  delay(1000);
}

QueueList<char> parse(String input)
{
  
  return tokens;
}
