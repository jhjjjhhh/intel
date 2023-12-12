#include <stdio.h>
#include <wiringPi.h>
#include <stdbool.h>

#define KEY 5
#define LED 21

bool Toggle = FALSE;
bool Flag = FALSE;

int main(){

	printf("Raspberry Pi - key Input Test\n");

	wiringPiSetupGpio();

	pinMode(KEY,INPUT);
	pinMode(LED,OUTPUT);
	
	while(1){
		if(digitalRead(KEY) == LOW){ //버튼을 누를 때마다
			if(Flag == FALSE){
				Flag = TRUE;
				Toggle = !Toggle;
				digitalWrite(LED, Toggle);
				if(Toggle == TRUE) printf("LED ON !!!\n");
				else printf("LED OFF !!!\n");
				delay(50);
			}
		}
		else if(digitalRead(KEY) == HIGH){
			if(Flag == TRUE){
				Flag = FALSE;
			}
		}
	}
	return 0;
}
