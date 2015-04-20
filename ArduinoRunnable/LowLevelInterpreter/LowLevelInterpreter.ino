/**
This is the low level aspect of theArduino Interpreter Project
(initially) performed for CS 554 Compiler construction at WPI.
**/
#include <QueueList.h> //from http://playground.arduino.cc/Code/QueueList

//initialize the constant token values here
enum Token {
	INVALID,
	END,
	INT,
	FLOAT,
	READ,
	SET,
	DIGITAL,
	ANALOG,
	NONE
};

//Initialize globals
QueueList<Token> tokens;
char ch;
String lineIn;
Token currentToken;
Token peekToken;

//First things first, define a bunch of masking functions
QueueList<Token> parse(String input);
Token nextToken(void);

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
	if(Serial.available())
	{
		//The higher level just sent us some stuff, read it in.
		lineIn += (char) Serial.read();
		if(lineIn[lineIn.length() - 1] == '\n')
		{
			//we are done with this line, do something with parse
			parse(lineIn);
		}
	}
}

/**
This method parses the input returned from reading the line.
**/
QueueList<Token> parse(String input)
{
	Serial.println("We are parsing something now!\n");
	lineIn.remove(0);
	return tokens;
}

/**
This method returns the type of token that was just read in from this serial stream.
**/
Token nextToken(void)
{
	char chLoc = Serial.read();
	if(chLoc == ' ')
	{
		return NONE;
	}

	String word;
	while(chLoc != ' ')
	{
		word += chLoc;
	}

	return INVALID;
}
