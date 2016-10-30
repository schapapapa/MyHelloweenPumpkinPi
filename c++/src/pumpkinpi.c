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

void blink(int start, int stop, int isEnabled);
void stopAll(int start, int stop);
void startAll(int start, int stop, int sequence[]);
void showPins(int start, int stop);
void setPinsOutput(int start, int stop);
void loop (int start , int stop, int MOTIONSENSORPORT);


int main(void)
{
	int i;
	int MOTIONSENSORPORT = 23;
	int circuitPort1 = 0;
	int circuitPort2 = 6;
	
	//set the mode to input in order to receive signals from the motion sensor....
	pinMode(MOTIONSENSORPORT, INPUT);
	
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		 printf("setup wiringPi failed !");
		return 1; 
	}
	
	printf("Showing pins \n");
	showPins(circuitPort1, circuitPort1);
	showPins(circuitPort2, circuitPort2);
	printf("setPinsOutput \n");
	setPinsOutput(circuitPort1, circuitPort1);
	setPinsOutput(circuitPort2, circuitPort2);
	printf("looping \n");
	//loop( circuitPort1 ,  circuitPort1,MOTIONSENSORPORT);
	loop( circuitPort1 ,  circuitPort2,MOTIONSENSORPORT);

	return 0;
}

void showPins(int start, int stop) {
	int i=0;
	for(i=start;i<stop+1;i++){
		printf("Init pumpkin pi pins %d(wiringPi pin)\n",i); 
		printf("Init pumpkin pi pins %d(wiringPi pin)\n",i); //when initialize wiring successfully,print message to screen
	}
}
void setPinsOutput(int start, int stop) {
	int i=0;
	for(i=start;i<stop+1;i++){   
		printf("Setting pins %d to output \n",i);    //make 8 pins' mode is output
		pinMode(i, OUTPUT);
	}
}
void loop (int start , int stop, int MOTIONSENSORPORT) {
	int on = 1;
	int off = 0;
	while (1) {
		if (digitalRead(MOTIONSENSORPORT)) {
			printf("Starting sequence \n"); 
			blink(start,stop,on);
			printf("Ending sequence \n"); 
			delay(1000);
		} else {
			stopAll( start,  stop);
		}
	}
}

//assume isEnabled means 0=false and 1 =true
//didnt want to write a logical operator Wrapper around that 
void blink(int start, int stop, int isEnabled) {
	int i = 0;
	int j = 0;
	int sequence[] = {50,50,50,50,50,50,50,50,50,50,100,100,100,100,100,100,100,100,100,100,200,200,200,200,200};
	printf("starting sequence with length %d \n",sizeof(sequence)); 
	startAll(start, stop, sequence);
}

void stopAll(int start, int stop) {
	int i=0;
	for (i=start;i<(stop+1);i++){ 
		//set to low
		led_off(i);
	}
}

void startAll(int start, int stop, int sequence[]) {
	int i=0;
	int j=0;
	
	for (j=0;j<sizeof(sequence);j++){ 
		for (i=start;i<(stop+1);i++){ 
			//set to low
			led_on(i);
		}
		delay(sequence[j]);
		for (i=start;i<(stop+1);i++){ 
			//set to low
			led_off(i);
		}
		delay(sequence[j]);
	}
}




