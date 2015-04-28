/**
This is the low level aspect of theArduino Interpreter Project
(initially) performed for CS 554 Compiler construction at WPI.
**/
#include <StandardCplusplus.h>
#include <vector>

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
	LOGICHIGH,
	LOGICLOW,
	NONE
};

struct _aetoken
{
	Token token;
	String data;
};

typedef struct _aetoken AEToken;

//Initialize globals
AEToken tokens[10];
int tokenIndex = 0;
int parseIndex = 0;
char ch;
String lineIn;
AEToken *currentToken = NULL;
AEToken *peekToken = NULL;
int lineInCnt;

//First things first, define a bunch of masking functions
void parse(String input);
void nextToken(AEToken * toPass);
void scanINTToken(AEToken * toPass);
void scanREADToken(AEToken * toPass);
void scanSETToken(AEToken * toPass);
void scanANALOGToken(AEToken * toPass);
void scanDIGITALToken(AEToken * toPass);
void scanHIGHToken(AEToken * toPass);
void scanLOWToken(AEToken * toPass);
void parseReadCommand();
void parseSetCommand();
Token peekNextToken();
Token getNextToken();
Token getCurrentToken();
String getCurrentParseData();
void destroyAEToken(AEToken * target);
void debug(AEToken * target);
String readWord();
char readNextChar();

//masked functions to attempt
void attemptAnalogWrite();
void attemptAnalogRead();
void attemptDigitalRead();
void attemptDigitalWrite();

//debug variables
bool justDone = true;

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
			lineInCnt = 0; //reset for the latest string
			tokenIndex = 0; //reset for new stream of tokens
			parse(lineIn);
			justDone = true;
		}
	}

	if(justDone)
	{
		//Serial.println("We are still alive");
		justDone = false;
	}
}

/**
Completely destroys the AEToken pointer. Don't do something stupid like pass it a NULL pointer
**/
void destroyAEToken(AEToken * target)
{
	free(target);
}

/**
This method parses the input returned from reading the line.
**/
void parse(String input)
{
	//Serial.println("We are parsing the string " + lineIn);
	AEToken * temp;
	ch = readNextChar();
	nextToken(temp);
	lineIn.remove(0);

	if(tokens[0].token == NONE)
	{
		Serial.println("Attempted to delete things that weren't here");
		return;
	}

	//do some stuff with parsing here
	//int parsingIndex = 0;
	switch(tokens[0].token)
	{
		case READ:
			parseReadCommand();
			break;
		case SET:
			parseSetCommand();
			break;
		default:
			Serial.println("Parser doesn't recognize this command. SET and READ are the only two to read.");
	}

	//flush it all out!
	//Serial.print("Token number = "); Serial.println(tokenIndex);
	for(int i = 0; i < tokenIndex; i++)
	{
		debug(&tokens[i]);
	}

	Serial.println("Done!");
}

/**
This method returns the type of token that was just read in from this serial stream.
**/
void nextToken(AEToken * toPass)
{
	while(lineInCnt < lineIn.length())
	{
		int c = (char) ch;
		switch(c)
		{
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			case '0':
				scanINTToken(toPass);
				break;
			case 'r':
			case 'R':
				scanREADToken(toPass);
				break;
			case 's':
			case 'S':
				scanSETToken(toPass);
				break;
			case 'a':
			case 'A':
				scanANALOGToken(toPass);
				break;
			case 'd':
			case 'D':
				scanDIGITALToken(toPass);
				break;
			case 'h':
			case 'H':
				scanHIGHToken(toPass);
				break;
			case 'l':
			case 'L':
				scanLOWToken(toPass);
				break;
			case '\n':
				tokens[tokenIndex].token = NONE;
				tokenIndex++;
				return;
				break;
			case '\t':
			case ' ':
				ch = readNextChar(); //there must be more, per contract
				break;
			default:
				//Serial.println("Error, command not completed, flushing buffer!");
				//lineIn.remove(0);
				return;
		}
	}
}

/**
Scan and store an INT token into the tokens vector yo
**/
void scanINTToken(AEToken * toPass)
{
	Serial.println("Reading int");
	String sb;
	sb += readWord();
	
	//check for . to see if we are a float
	bool flt = false;
	for(int i = 0; i < sb.length(); i++)
	{
		flt |= sb[i] == '.';
	}

	tokens[tokenIndex].token = flt ? FLOAT : INT;
	
	/*
	//char * logic
	for(int i = 0; i < sb.length(); i++)
	{
		tokens[tokenIndex].data += sb[i];
	}*/

	//String logic
	tokens[tokenIndex].data = "";
	for(int i = 0; i < sb.length(); i++)
	{
		tokens[tokenIndex].data += sb[i];
	}

	tokenIndex++; //integrate for the next token
}

/**
Scan in a read token into the tokens vector yo!
**/
void scanREADToken(AEToken * toPass)
{
	//we don't actually support IDs yet, just read it in and see what happens
	String temp;
	temp += readWord();
	temp.toUpperCase();

	if(temp.compareTo("READ") == 0)
	{
		tokens[tokenIndex].token = READ;
	}
	else
	{
		Serial.println("IDS ARENT SUPPORTED YET YO!");
	}

	tokenIndex++; //integrate for the next token
}

/**
Scan in an ANALOG token into the tokens vector yo!
**/
void scanANALOGToken(AEToken * toPass)
{
	//we don't actually support IDs yet, just read it in and see what happens
	String temp;
	temp += readWord();
	temp.toUpperCase();

	if(temp.compareTo("ANALOG") == 0)
	{
		tokens[tokenIndex].token = ANALOG;
	}
	else
	{
		Serial.println("IDS ARENT SUPPORTED YET YO!");
		Serial.print("Found sequence " + temp);
	}

	tokenIndex++; //integrate for the next token
}

/**
Scan in a DIGITAL token into the tokens vector yo!
**/
void scanDIGITALToken(AEToken * toPass)
{
	//we don't actually support IDs yet, just read it in and see what happens
	String temp;
	temp += readWord();
	temp.toUpperCase();

	if(temp.compareTo("DIGITAL") == 0)
	{
		tokens[tokenIndex].token = DIGITAL;
	}
	else
	{
		Serial.println("IDS ARENT WUPPORTED YET YO!");
	}

	tokenIndex++; //integrate for the next token
}

/**
Scan in a HIGH token into the tokens vector yo!
**/
void scanHIGHToken(AEToken * toPass)
{
	//we don't actually support IDs yet, just read it in and see what happens
	String temp;
	temp += readWord();
	temp.toUpperCase();

	if(temp.compareTo("HIGH") == 0)
	{
		tokens[tokenIndex].token = LOGICHIGH;
	}
	else
	{
		Serial.println("IDS ARENT WUPPORTED YET YO!");
	}

	tokenIndex++; //integrate for the next token
}

/**
Scan in a LOW token into the tokens vector yo!
**/
void scanLOWToken(AEToken * toPass)
{
	//we don't actually support IDs yet, just read it in and see what happens
	String temp;
	temp += readWord();
	temp.toUpperCase();

	if(temp.compareTo("LOW") == 0)
	{
		tokens[tokenIndex].token = LOGICLOW;
	}
	else
	{
		Serial.println("IDS ARENT WUPPORTED YET YO!");
	}

	tokenIndex++; //integrate for the next token
}

/**
Scan in a SET token into the tokens vector yo!
**/
void scanSETToken(AEToken * toPass)
{
	//we don't actually support IDs yet, just read it in and see what happens
	String temp;
	temp += readWord();
	temp.toUpperCase();

	if(temp.compareTo("SET") == 0)
	{
		tokens[tokenIndex].token = SET;
	}
	else
	{
		Serial.println("IDS ARENT WUPPORTED YET YO!");
	}

	tokenIndex++; //integrate for the next token
}

/**
read in the next word (stop at space, \t or \n) and return it.
**/
String readWord()
{
	String temp;
	while((ch != ' ') && (ch != '\t') && (ch != '\n'))
	{
		//Serial.println("Read char " + ch);
		temp += ch;

		ch = readNextChar();
	}

	return temp;
}

/**
used to print out what was interpreted by the system
**/
void debug(AEToken * target)
{
	String temp;
	switch(target->token)
	{
	case INVALID:
		break;
	case END:
		Serial.println("END NODE");
		break;
	case INT:
		Serial.print("INT ");
		temp = target->data;
		Serial.println(temp.toInt());
		break;
	case FLOAT:
		Serial.print("FLOAT ");
		Serial.println(temp.toFloat());
		break;
	case READ:
		Serial.println("READ");
		break;
	case SET:
		Serial.println("SET");
		break;
	case DIGITAL:
		Serial.println("DIGITAL");
		break;
	case ANALOG:
		Serial.println("ANALOG");
		break;
	case LOGICHIGH:
		Serial.println("HIGH");
		break;
	case LOGICLOW:
		Serial.println("LOW");
		break;
	case NONE:
		Serial.println("NONE NODE");
		break;
	}
}

/**
Return the next char in the sequence!
**/
char readNextChar()
{
	char tmp = lineIn[lineInCnt];
	lineInCnt++;
	return tmp;
}

void parseReadCommand()
{
	//we alreaday know that the first token was the read
	//check if the user set the next token to be analog or digital

	switch(getNextToken())
	{
		case ANALOG:
			getNextToken(); //set up the read function
			attemptAnalogRead();
			break;
		case DIGITAL:
			getNextToken(); //set up the read function
			attemptDigitalRead();
			break;
		case INT:
			attemptDigitalRead();
			break;
		case FLOAT:
			Serial.println("Warning, converting float to an int. This isn't safe yo!");
			attemptDigitalRead();
			break;
		default:
			Serial.println("Parsing error on the read command. Please see the command outline for instructions");
	}
}

void parseSetCommand()
{
	//we alreaday know that the first token was the set
}

Token peekNextToken()
{
	if(tokenIndex ==  parseIndex)
		return INVALID;

	return tokens[parseIndex + 1].token;
}

Token getNextToken()
{
	if(tokenIndex == parseIndex)
		return INVALID;

	parseIndex++;
	return tokens[parseIndex].token;
}

Token getCurrentToken()
{
	return tokens[parseIndex].token;
}

String getCurrentParseData()
{
	return tokens[parseIndex].data;
}

void attemptAnalogWrite()
{

}

void attemptAnalogRead()
{
	//we are here looking to read the pin at this token. check if we are safe.
	if(!(getCurrentToken() == INT || getCurrentToken() == FLOAT))
	{
		Serial.println("Cannot read pins that aren't numbers!");
		return;
	}

	int pin = getCurrentParseData().toInt();
	if(pin <= 5) //can't write to pins 0 or 1 due to serial lines
	{
		//valid pin numbers, check for banned pins for digital read
		pinMode(pin, INPUT);
		Serial.println(digitalRead(pin) == 0 ? "Logic Low read" : "Logic High read");
	}
	else
	{
		Serial.println("Cannot read from this pin, it is a serial line!");
	}
}

void attemptDigitalRead()
{
	//we are here looking to read the pin at this token. check if we are safe.
	if(!(getCurrentToken() == INT || getCurrentToken() == FLOAT))
	{
		Serial.println("Cannot read pins that aren't numbers!");
		return;
	}

	int pin = getCurrentParseData().toInt();
	if(pin > 1) //can't write to pins 0 or 1 due to serial lines
	{
		//valid pin numbers, check for banned pins for digital read
		pinMode(pin, INPUT);
		Serial.println(digitalRead(pin) == 0 ? "Logic Low read" : "Logic High read");
	}
	else
	{
		Serial.println("Cannot read from this pin, it is a serial line!");
	}
}

void attemptDigitalWrite()
{

}
