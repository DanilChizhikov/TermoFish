#include "SDControll.hpp"

#define CLK 3
#define DIO 2

TM1637 display(CLK, DIO);

void DisplaySetup(){
    display.begin();
    display.setBrightness(4);
}

void DisplayUpdate(float temp){
	unsigned int RAWtemp = temp * 100;    // переводим в целое число
	int8_t Digits[] = {0x00,0x00,0x00,0x00};  // буфер для цифр LED-индикатора
	Digits[0] = (byte)(RAWtemp / 1000) % 10; // раскидываем 4-значное число на цифры
	Digits[1] = (byte)(RAWtemp / 100) % 10;
	Digits[2] = (byte)(RAWtemp / 10) % 10;
	Digits[3] = (byte)(RAWtemp) % 10;
	char displayInfo = temp;
	display.display(displayInfo);    // команда вывода буфера на дисплей (из библиотеки)
}