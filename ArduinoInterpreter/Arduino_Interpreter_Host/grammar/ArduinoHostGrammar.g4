/**
 * Define a grammar called ArduinoHostGrammar
 * This grammar is the higher level language that interfaces with the user
 * For the lower level language, please see the lower level spec file.
 */
 
grammar ArduinoHostGrammar;

command: 	setCommand | 
			readCommand;

setCommand:  SET INT (HIGH | LOW | INT); //this command applies to all pins. Semantics will take care of what to do.

readCommand: (ANALOG | DIGITAL)? READ INT; //this applies to all pins except for 0, 1, a motor, and any pin you read off of.

//reserved words
SET: 		'SET' | 'set';
READ:		'READ' | 'read';
HIGH: 		'HIGH' | '1';
LOW: 		'LOW' | '0';
ANALOG:		'ANALOG';
DIGITAL:	'DIGITAL';

//operators

//primary statements here
ID : 			LETTER (LETTER|DIGIT|'_')* ;
INT : 		DIGIT+ ;
WS :			[ \t\r\n]+ -> skip ; 
fragment
LETTER :		[A-Za-z] ;
fragment
DIGIT :		[0-9] ;


