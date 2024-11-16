//--------------------------------
/*
bool ALPHABET[1][3][2]
{
    {{0,0},
     {0,0},
     {0,0}} //" "
}
*/

void printRows(int numLetters, int *ptr){};

void movePaper(int deg){};
void moveCart(int deg){};
void moveCrank(int deg){};

/*
task main()
{
    /*
    motor[motorA] = -10; //paper
    motor[motorD] = -10; //cart
    motor[motorC] = 30;  //crank
    wait1Msec(10000);
    */
}
*/

//--------------------------------
void printRows(int numLetters, int *ptr){
    for (int i = 0; i < numLetters*2; i++) {
        if (*ptr) {
            moveCrank(360);
        }
        moveCart(8.25);
        ptr++;
    }
}

//--------------------------------
void movePaper(int deg){
    nMotorEncoder[motorA] = 0;
    motor[motorA] = -10;
    while (nMotorEncoder[motorA] <= deg) {}
    motor[motorA] = 0;
}

//--------------------------------
void moveCart(int deg){
    nMotorEncoder[motorD] = 0;
    motor[motorD] = -10;
    while (nMotorEncoder[motorD] <= deg) {}
    motor[motorD] = 0;
}

//--------------------------------
void moveCrank(int deg){
    nMotorEncoder[motorC] = 0;
    motor[motorC] = -10;
    while (nMotorEncoder[motorC] <= deg) {}
    motor[motorC] = 0;
}

//--------------------------------

//array alpha
int alpha[1][3][2] = {

    {
        {0,1},
        {0,0},
        {0,0}
    } //A

    {
        {0,1},
        {0,1},
        {0,0}
    } //B

    {
        {1,1},
        {0,0},
        {0,0}
    } //C

    {
        {1,1},
        {1,0},
        {0,0}
    } //D

    {
        {0,1},
        {1,0},
        {0,0}
    } //E

    {
        {1,1},
        {0,1},
        {0,0}
    } //F

    {
        {1,1},
        {1,1},
        {0,0}
    } //G

    {
        {0,1},
        {1,1},
        {0,0}
    } //H

    {
        {1,0},
        {0,1},
        {0,0}
    } //I

    {
        {1,0},
        {1,1},
        {0,0}
    } //J

    {
        {0,1},
        {0,0},
        {0,1}
    } //K

    {
        {0,1},
        {0,1},
        {0,1}
    } //L

    {
        {1,1},
        {0,0},
        {0,1}
    } //M

    {
        {1,1},
        {1,0},
        {0,1}
    } //N

    {
        {0,1},
        {1,0},
        {0,1}
    } //O

    {
        {1,1},
        {0,1},
        {0,1}
    } //P

    {
        {1,1},
        {1,1},
        {0,1}
    } //Q

    {
        {0,1},
        {1,1},
        {0,1}
    } //R

    {
        {1,0},
        {0,1},
        {0,1}
    } //S

    {
        {1,0},
        {1,1},
        {0,1}
    } //T

    {
        {0,1},
        {0,0},
        {1,1}
    } //U

    {
        {0,1},
        {0,1},
        {1,1}
    } //V

    {
        {1,0},
        {1,1},
        {1,0}
    } //W

    {
        {1,1},
        {0,0},
        {1,1}
    } //X

    {
        {1,1},
        {1,0},
        {1,1}
    } //Y

    {
        {0,1},
        {1,0},
        {1,1}
    } //Z

}

//--------------------------------
void systemStart()
{
   displayTextLine(3, "Press Enter to Start Printing");

   wait1Msec(1000);

   while(!getButtonPress(buttonEnter))
        {}

   while(getButtonPress(buttonAny))
    {}

}

//--------------------------------
/*
string readWord(ifstream inputFile)
{
        string words;

        inputFile>>words;

        return words;
}
*/

//--------------------------------
void printWord(string words,int alphabet[][][], int print[])
{

        int a = 0;
    for(int i = 0; i< words.length(); i++)
    {
        char letter = words[i];
        //ascii value of a is 97 and z is 122, so letter can be identified by difference
        //index of letter is given
        int index = letter - 'a';
    for(int k = 0; k<3; k++)
    {

    for(int j = 0; j<2; j++)
    {
        print[a] = alphabet[index][k][j];

        //go from here to only slot specific values
        a++;
    }
    }
    }
}

SensorType [S1] = sensorEV3 Touch ;
int statusEStop = SensorValue[S1];

void eStop (int statusEStop){

    if (statusEStop > 0){
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

    while (!getButtonPress(buttonAny)){}

    while (getButtonPress(buttonDown)){}

    displayTextLine(4, "System Stopping.");

    motor[motorC] = 0;
    motor[motorD] = 0;
    motor[motorA] = 0;

    wait1Msec (15000) ;

}

//--------------------------------

#include "PC_FileIO.c"

char* charPointers[10]; 

char** readWordFromFile(string fileName) {
    TFileHandle fin;
    bool fileHandle = openReadPC(fin, fileName);

    if (!fileHandle) {
        displayTextLine(4, "Error opening file");
        return NULL;
    }

    char word[10];  // temporary array
    int charCount = 0;
    char c = 0;
    int whiteSpace = 0;

    while (readCharPC(fin, c) && charCount < 10 && whiteSpace == 0) {
        if (c == ' ' || c == '\n' || c == '\t') {
            whiteSpace = 1;
        } else {
            word[charCount] = c; 
            charPointers[charCount] = &word[charCount]; 
            charCount++;
        }
    }

    closeFilePC(fin);
    return charPointers;  
}
