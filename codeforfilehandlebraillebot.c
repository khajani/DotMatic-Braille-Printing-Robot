
//file i,o return word in char array form

#include "PC_FileIO.c"

char* readFile(string fileName)
{
  TFileHandle fin;
  bool fileHandle = openReadPC(fin, fileName);

  if (!fileHandle) {
      displayTextLine(1, "File not found!");
  }

  char c;
  //string word = "";
  //string word[10];

  char currentWord[10]; //GET LENGTH OF WORD
  int charCount = 0;

  while (readCharPC(fin, c)) {
  	if (c != ' '){
  		currentWord[charCount] = c;
  		charCount++;
  	} else{
  			word += c;
  		}

  }

  /*
      if (c == ' ' || c == '\n') {
          if (word != "") {
              words[charCount] = word;
              wordCount++;
              word = "";
          }
      } else {
          word += c;
      }
  }
  */

  if (word != "") {
      words[charCount] = word;
      charCount++;
  }

  closeFilePC(fin);

  return char* word[];

}

task main (){
	readFile();
}

  /*
  for (int i = 0; i < wordCount; i++) {
      string displayMsg = "Word " + numToStr(i+1) + ": " + words[i];
      displayTextLine(i + 1, displayMsg);
  }
*/


/*
TFileHandle fin;
	//bool fileHandle = openReadPC(fin,"hello.txt");


	char c;
	string word = "";
	string wordArray[];
	int wordCount = 0;

	readCharPC(fin, c);
	readTextPC(fin, word);

	//closeFilePC(fileHandle);


  int fileHandle = FileOpen(fileName, FILE_READ);

  if (fileHandle == -1)
  {
      WriteLine("File could not be opened.");
      //return;
  }

  while (FileEOF(fileHandle) == 0) // While end of file is not reached
  {
      // Read the next character from the file
      char c = FileReadByte(fileHandle);

      // If we encounter a space or newline, it's the end of a word
      if (c == ' ' || c == '\n' || c == '\r')
      {
          if (word != "")  // Check if we have a non-empty word
          {
              // Dynamically grow the array and store the word
              wordArray[wordCount] = word;
              wordCount++;  // Increment the word count
              word = "";    // Reset the word for the next one
          }
      }
      else
      {
          word += c;  // Add character to current word
      }
  }

  // Ensure the last word is added (in case the file doesn't end with a space or newline)
  if (word != "")
  {
      wordArray[wordCount] = word;
      wordCount++;
  }

  // Close the file
  FileClose(fileHandle);

  // Print the words stored in the word array
  for (int i = 0; i < wordCount; i++)
  {
      WriteLine(wordArray[i]);
  }

*/


/*FROM LEARN:
	TFileHandle fin;
	bool fileHandle = openReadPC(fin,"hello.txt");


	char c;
	string word = "";


	readCharPC(fin, c);
	readTextPC(fin, word);
	*/
