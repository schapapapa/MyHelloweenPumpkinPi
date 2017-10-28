#include <wiringPi.h>
#include <stdio.h>

//make led_n on
void led_on(int n)
{
	digitalWrite(n, LOW);
}

//make led_n off
void led_off(int n)
{
	digitalWrite(n, HIGH);
}

void setPinsOutput(int start, int stop) {
	int i=0;
	for(i=start;i<stop+1;i++){   
		printf("Setting pins %d to output \n",i);    //make 8 pins' mode is output
		pinMode(i, OUTPUT);
	}
}

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !\n ");
		return 1; 
	}
	delay(1000);
	led_off(26);
	delay(1000);
	led_on(26);
	while (1) {
		int circuitPort = 26;
		setPinsOutput(26,26);
    	int randomnumber;
    	randomnumber = rand() % 300;
		led_on(26);
		delay(randomnumber);
		led_off(26);
		randomnumber = rand() % 300;
		delay(randomnumber);
	}


	return 0;
}






