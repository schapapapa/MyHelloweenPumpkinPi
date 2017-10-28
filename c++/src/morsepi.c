#include <wiringPi.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//make led_n on
void led_on(int n)
{
	digitalWrite(n, LOW);
	printf("setting port to low %i \n",n);
}

//make led_n off
void led_off(int n)
{
	digitalWrite(n, HIGH);
	printf("setting port to high %i \n",n);
}

void loop (int argc, char *argv[]);
void waitShortSequence();
void waitLongSequence();
void waitBetweenChars();

#define MAX 500
#define SIZE 500

#define WAITBETWEENCHARS 300
#define WAITLONG 200
#define WAITSHORT 100

char charToUpper(char str)
{

   char c;
   c = (toupper(str));
 
   return c;
}


int main( int argc, char *argv[] )  {
	
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !\n ");
		return 1; 
	}

	int i = 0;
 	for (i = 0; i < argc; i++) {
 		printf("\n%s\n", argv[i]);
 	}
 	loop(argc, argv);
}

//returns the size of a character array using a pointer to the first element of the character array
int getArraySize(char *ptr)
{
    //variable used to access the subsequent array elements.
    int offset = 0;
    //variable that counts the number of elements in your array
    int count = 0;

    //While loop that tests whether the end of the array has been reached
    while (*(ptr + offset) != '\0')
    {
        //increment the count variable
        ++count;
        //advance to the next element of the array
        ++offset;
    }
    //return the size of the array
    return count;
}

void loop(int argc, char *argv[] ) {
	

	printf("Starting sequence \n");

	int z;
	for (z = 0; z < argc; z++) {
 		printf("in loop showing arguments %s\n", argv[z]);
 	}
	int sizeOfArray = argc;
	int circuitPort = 26;
	pinMode(circuitPort, OUTPUT);
	printf("array size %i \n" , sizeOfArray);

	//return if no string was specified...
	if (sizeOfArray<2) {
		return;
	}

	while (1) {
		int w = 0;
	 	for (w = 1; w < argc; w++) {

	 		int wordSize = getArraySize(argv[w]);

	 		printf("word size %i \n" , wordSize);
			printf("Starting sequence \n");
			
			char string[MAX][SIZE];
			char destination[MAX] [MAX][8];

			char *input[38]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O",
			               "P","Q","R","S","T","U","V","W","X","Y","Z","0","1","2","3",
			                "4","5","6","7","8","9"," "};

			char *output[38]={".-","-...","-.-.","-..",".","..-.","--.",
			                "....","..",".---","-.-",".-..","--","-.",
			                "---",".--.","--.-",".-.","...","-","..-",
			                "...-",".--","-..-","-.--","--..","-----",
			                ".----","..---","...--","....-",".....",
			                "-....","--...","---..","----.","/"};
			 int inputSize = 38;
			 int outputSize = 38;

			char code;
			char separator;


			printf("Defined constants \n");

			separator = ' ';
			
			int i = 0;
			int j;
			for(i=0;i<wordSize;i++){
				code = argv[w][i];
				
				printf("code %c \n" , code);

				if (code == separator) {
					continue;
				}

				code = charToUpper(code);
				printf("new code %c \n" , code);
				
				printf("size of mapping table %i \n" , inputSize);
				for(j=0;j<38;j++){
					//found 
					printf("comparing %s \n",input[j]);
					int found = 0;
					if (*input[j]==code) {
						printf("Found charcter %c \n",code);
						found = 1;
						//now we have the morseCode
						int k = 0;
						printf("morse code %s \n",output[j]);
						printf("size of morse code %i \n",sizeof(output[j]));
						
						for(k=0;k<sizeof(output[j]);k++){
							//we can only have "." or "-"
							if (output[j][k] == '.') {
								printf("found short \n");

								led_on(circuitPort);
								waitShortSequence();
								led_off(circuitPort);
								waitBetweenChars();
								
							} else if (output[j][k] == '-')  {
								printf("found long \n");
								led_on(circuitPort);
								waitLongSequence();
								led_off(circuitPort);
								waitBetweenChars();
								
							} else {
								continue;
							}
						}
						if (found) {
							break;
						}
					}	
				}
			}
		}
		delay(5000);
	}
	
}

void waitShortSequence() {
	delay(WAITSHORT);
}

void waitLongSequence() {
	delay(WAITLONG);
}

void waitBetweenChars() {
	delay(WAITBETWEENCHARS);
}



