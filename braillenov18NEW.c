#include "PC_FileIO.c"

// global array storing word (10 characters + null terminator)
char wrd[11] = {'h','e','l','l','o',NULL,NULL,NULL,NULL,NULL,NULL};

//global array for the alphabet in braille
int alpha[26][6] =
{
    {0,1,0,0,0,0}, //A
    {0,1,0,1,0,0}, //B
    {1,1,0,0,0,0}, //C
    {1,1,1,0,0,0}, //D
    {0,1,1,0,0,0}, //E
    {1,1,0,1,0,0}, //F
    {1,1,1,1,0,0}, //G
    {0,1,1,1,0,0}, //H
    {1,0,0,1,0,0}, //I
    {1,0,1,1,0,0}, //J
    {0,1,0,0,0,1}, //K
    {0,1,0,1,0,1}, //L
    {1,1,0,0,0,1}, //M
    {1,1,1,0,0,1}, //N
    {0,1,1,0,0,1}, //O
    {1,1,0,1,0,1}, //P
    {1,1,1,1,0,1}, //Q
    {0,1,1,1,0,1}, //R
    {1,0,0,1,0,1}, //S
    {1,0,1,1,0,1}, //T
    {0,1,0,0,1,1}, //U
    {0,1,0,1,1,1}, //V
    {1,0,1,1,1,0}, //W
    {1,1,0,0,1,1}, //X
    {1,1,1,0,1,1}, //Y
    {0,1,1,0,1,1}, //Z
};

//fileio function
int readWordFromFile(TFileHandle &fin);

//start stop functions
void systemStart();
void systemStop ();
void eStop ();

//printing functions
void printRow(int *ptr, int len);
void printWrd(int wrdLen);

//movement functions
void movePaper(float deg); //y-axis
void moveCart(float deg, int pwr);  //x-axis
void moveCrank(float deg); //z-axis

task main() {
	SensorType [S1] = sensorEV3_Touch;
	wait1Msec(50);

	string fileName = "input.txt";
	TFileHandle fin;
  bool fileHandle = openReadPC(fin, fileName);

  if (!fileHandle) {
  	systemStart();

		while (wrd[0]!='!') {
			eStop();
			int wrdLen = readWordFromFile(fin);

			eStop();
		  printWrd(wrdLen);
		  eStop();

	  }
	  systemStop();
	}
	else {
		displayTextLine(4, "Error opening file");
	}
	closeFilePC(fin);
}

int readWordFromFile(TFileHandle &fin) {
    int charCount = 0;
    char c = 0;
    int whiteSpace = 0;

    while (readCharPC(fin, c) && charCount < 10 && whiteSpace == 0) {
        if (c == ' ' || c == '\n' || c == '\t') {
            whiteSpace = 1;
        } else {
            wrd[charCount] = c;
            charCount++;
        }
    }

    wrd[charCount] = '\0';  // null-terminate the string

    return charCount;  // return the number of characters in word (excluding null terminator)
}

//--------------------------------
void systemStart(){
	displayTextLine(3, "Press Enter to Start Printing");
 	eStop();
 	wait1Msec(10000);
 	eStop();
 	while(!getButtonPress(buttonEnter))
 	{eStop();}
  while(getButtonPress(buttonAny))
  {eStop();}
}

//--------------------------------

void eStop (){
    if (SensorValue[S1]){
        displayTextLine(4, "Emergency Stop Activated!");

        motor[motorC] = 0;
        motor[motorD] = 0;

        const int TIME_UNTIL_ROLL = 15;

        displayTextLine(5, "%d secs until paper roll out.", TIME_UNTIL_ROLL);
        wait1Msec (15000) ;

        motor[motorA] = 10;
        while (abs(nMotorEncoder[motorA]) <= 180){}
        motor[motorA] = 0;
    }
}

//--------------------------------
void systemStop (){
    while (!getButtonPress(buttonAny)){eStop();}

    while (getButtonPress(buttonDown)){eStop();}

    displayTextLine(4, "System Stopping.");

    motor[motorC] = 0;
    motor[motorD] = 0;
    motor[motorA] = 0;

		eStop();
    wait1Msec (15000) ;
    eStop();
}

void printWrd(int wrdLen) {
    int row[20];		//max of wrdLen*2
    int indices[10]; //max of wrdLen

    for (int i = 0; i < wrdLen; i++) {
    		eStop();
        //determining indices to be used for alpha (using aski codes)
        //i.e. what letter is in wrd[i]
        indices[i] = wrd[i] - 'a';
        eStop();
    }

    for(int i = 0; i <3; i++) {
    		eStop();
        int k = 0;
        for (int j = 0; j < wrdLen; j++) {
        		eStop();
            row[k]=alpha[indices[j]][i*2];
            row[k+1]=alpha[indices[j]][i*2 + 1];
            k+=2;
            eStop();
        }
        eStop();
        printRow(&row[0], wrdLen*2);
    }
    eStop();
		movePaper(8.25);
}

void printRow(int *ptr, int len) {
	int count = 0;
	nMotorEncoder[motorD] = 0;
	for (int i = 0; i<len; i++) {
		if (*ptr) {
			eStop();
			moveCrank(360);
		}
		count+=nMotorEncoder[motorA];
		eStop();
		moveCart(8.25, -10);
		eStop();
		ptr++;
	}
	eStop();
	moveCart(count, 10);
	eStop();
	movePaper(8.25);
}

void movePaper(float deg){
	nMotorEncoder[motorA] = 0;
	eStop();
	motor[motorA] = -10;
	while (abs(nMotorEncoder[motorA]) <= deg) {eStop();}
	motor[motorA] = 0;
	eStop();
}

void moveCart(float deg, int pwr){
	eStop();
	nMotorEncoder[motorD] = 0;
	eStop();
	motor[motorD] = pwr;
	while (abs(nMotorEncoder[motorD]) <= deg) {eStop();}
	motor[motorD] = 0;
	eStop();
}

void moveCrank(float deg){
	nMotorEncoder[motorC] = 0;
	eStop();
	motor[motorC] = -10;
	while (abs(nMotorEncoder[motorC]) <= deg) {eStop();}
	motor[motorC] = 0;
	eStop();
}
