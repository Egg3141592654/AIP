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
	char * data;
};

typedef struct _aetoken AEToken;

//Initialize globals
std::vector<AEToken> tokens;
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
void destroyAEToken(AEToken * target);
void debug(AEToken * target);
String readWord();
char readNextChar();

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
			parse(lineIn);
		}
	}
}

/**
Completely destroys the AEToken pointer. Don't do something stupid like pass it a NULL pointer
**/
void destroyAEToken(AEToken * target)
{
	if((target->token == INT) || (target->token == FLOAT))
		free(target->data);
	free(target);
}

/**
This method parses the input returned from reading the line.
**/
void parse(String input)
{
	Serial.println("We are parsing something now!\n");
	AEToken * temp;
	ch = readNextChar();
	nextToken(temp);
	lineIn.remove(0);

	//do some stuff with parsing here

	//flush it all out!
	Serial.println("Starting flush");
	for(int i = tokens.size() -1; i >= 0; i--)
	{
		temp = &tokens[i];
		debug(temp);
		destroyAEToken(temp);
		tokens.pop_back();
	}
	Serial.println("Done!");
}

/**
This method returns the type of token that was just read in from this serial stream.
**/
void nextToken(AEToken * toPass)
{
	while(ch != '\n')
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
			case '\t':
			case ' ':
				ch = readNextChar(); //there must be more, per contract
				break;
			default:
				Serial.println("Error, command not completed, flushing buffer!");
				lineIn.remove(0);
				return;
		}
	}
}

/**
Scan and store an INT token into the tokens vector yo
**/
void scanINTToken(AEToken * toPass)
{
	String sb;
	sb += readWord();
	
	//check for . to see if we are a float
	bool flt = false;
	for(int i = 0; i < sb.length(); i++)
	{
		flt |= sb[i] == '.';
	}

	toPass = (AEToken *)(malloc(sizeof(AEToken)));
	toPass->data = (char *)malloc(sizeof(char) * sb.length() + 1);
	toPass->token = flt ? FLOAT : INT;
	toPass->data[0] = (char) sb.length(); //stuff the length of this pointer as the first address

	for(int i = 1; i <= sb.length(); i++)
	{
		toPass->data[i] = sb[i - 1];
	}

	tokens.push_back(*toPass); //need to free this bud!
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
		toPass = (AEToken *)malloc(sizeof(AEToken));
		toPass->token = READ;
		tokens.push_back(*toPass);
	}
	else
	{
		Serial.println("IDS ARENT WUPPORTED YET YO!");
	}
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
		toPass = (AEToken *)malloc(sizeof(AEToken));
		toPass->token = ANALOG;
		tokens.push_back(*toPass);
	}
	else
	{
		Serial.println("IDS ARENT WUPPORTED YET YO!");
	}
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
		toPass = (AEToken *)malloc(sizeof(AEToken));
		toPass->token = DIGITAL;
		tokens.push_back(*toPass);
	}
	else
	{
		Serial.println("IDS ARENT WUPPORTED YET YO!");
	}
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
		toPass = (AEToken *)malloc(sizeof(AEToken));
		toPass->token = LOGICHIGH;
		tokens.push_back(*toPass);
	}
	else
	{
		Serial.println("IDS ARENT WUPPORTED YET YO!");
	}
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
		toPass = (AEToken *)malloc(sizeof(AEToken));
		toPass->token = LOGICLOW;
		tokens.push_back(*toPass);
	}
	else
	{
		Serial.println("IDS ARENT WUPPORTED YET YO!");
	}
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
		toPass = (AEToken *)malloc(sizeof(AEToken));
		toPass->token = SET;
		tokens.push_back(*toPass);
	}
	else
	{
		Serial.println("IDS ARENT WUPPORTED YET YO!");
	}
}

/**
read in the next word (stop at space, \t or \n) and return it.
**/
String readWord()
{
	String temp;
	while((ch != ' ') && (ch != '\t') && (ch != '\n'))
	{
		temp += ch;

		ch = readNextChar();
	}

	Serial.println("Read word " + temp);

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
		for(int i = 1; i <= target->data[0]; i++)
		{
			temp += target->data[i];
		}

		Serial.println(temp.toInt());
		break;
	case FLOAT:
		Serial.print("FLOAT ");
		for(int i = 1; i <= target->data[0]; i++)
		{
			temp += target->data[i];
		}

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