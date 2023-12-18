#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include "lcd1602.h"
#include <stdbool.h>

bool changePwd = false;
int i, j;
static int count = 1;
char str1[16]; 
//char password[16];
#define row 4
#define col 4
int CNUM[] = {26, 19, 13, 6};
int RNUM[] = {12, 16, 20, 21};

// 도어락 비밀번호
char doorLockPassword[] = "0000"; // 임의의 초기 비밀번호 설정

char CT[row][col] = {
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', '*'},
    {'*', '0', '#', '/'}
};

void setup();
void keypad();
void calculator(char key);
void unlockDoor();
void setup()
{
	wiringPiSetupGpio();
	xio = wiringPiI2CSetup(I2C_ADDR);
	lcd_init();
    for (i = 0; i < 4; i++)
    {
        pinMode(RNUM[i], OUTPUT);
        pinMode(CNUM[i], INPUT);
        pullUpDnControl(CNUM[i], PUD_UP);
        digitalWrite(RNUM[i], HIGH);
    }
}

int main()
{
   setup();
   lcdClear();
	lcdLoc(LINE1);
	typeln("Door Lock");
	lcdLoc(LINE2);
	typeln("Start");
//	delay(1000);
//	lcdClear();
    while (1)
    { 
       keypad();
    }

    return 0;
}

// 키패드 입력 함수
void keypad()
{
    for (i = 0; i < 4; i++)
    {
        digitalWrite(RNUM[i], LOW);
        if (digitalRead(RNUM[i]) == LOW)
        {
            for (j = 0; j < 4; j++)
            {
                if (digitalRead(CNUM[j]) == LOW)
                {
                    calculator(CT[i][j]);
                }
            }
            delay(45);
        }

        digitalWrite(RNUM[i], HIGH);
    }
}

// 눌린 키패드 저장 함수
void calculator(char key)
{
	
    if (key >= '0' && key <= '9')
    {
    	lcdClear();
        putchar('*'); //입력 숫자 * 로 출력
        fflush(stdout);
        lcdLoc(LINE1);
        typeln("PWD : ");
        strncat(str1, &key, 1); // str1에 키패드에서 입력받은 값을 추가
        for(int i = 0; i < strlen(str1);i++){
				typeln("*");
        }
    }
    else if (key == '#')
    {
        unlockDoor(); // 도어락 열기 시도
    }
    else if(doorLockPassword[0] == '\0' && key == '*'){
    	printf("\nsaveNewPwd\n");
    	strcpy(doorLockPassword,str1);
    	printf("%s\n",doorLockPassword);
    	str1[0] = '\0';
    	
    }
    else if(key == '*')
    {
    	lcdClear();
    	printf("\nResetPassword\n");
    	lcdLoc(LINE1);
    	typeIn("Change PWD:");
    	lcdLoc(LINE2);
    	str1[0] == '\0';
    	for(int i =0; i<strlen(str1);i++){
    		typeIn("*");
    	}
    	doorLockPassword[0] = '\0';
    }
}

// 도어락 열기 시도 함수
void unlockDoor()
{
    if (strlen(str1) == strlen(doorLockPassword) && strcmp(str1, doorLockPassword) == 0)
    {
    	  //lcdClear();
    	  lcdLoc(LINE2);
        typeIn("Door Unlocked!");
        str1[0] = '\0'; // str1 초기화
        //delay(1500);
        //lcdClear();
    }
    else
    {
    	lcdLoc(LINE2);
    	typeIn("Wrong PWD!");
      delay(1000);
      str1[0] = '\0'; // str1 초기화
      //delay(1500);
      //lcdClear();
    }
}
