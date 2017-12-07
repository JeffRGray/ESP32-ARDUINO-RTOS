/*
 Name:		RTOS_blink.ino
 Created:	12/7/2017 10:19:51 AM
 Author:	Jeff
*/

/*example from: https://techtutorialsx.com/2017/05/06/esp32-arduino-creating-a-task/
since this is .ino code, it is not necessary to have all the #includes such as freertos.h
This version creates two tasks in the .ino code, and defines one additional task in blink.cpp
(don't forget to declare the function prototypes in the header file).  Note that the function
blink() causes the words "blink-blink" to be printed, in addition to initiating the task to 
blink the LED.  The task is initited once, but it keeps running until it is stopped (as it is
with the "Hello..." tasks which run 10 times then are stopped.  Since blink_task is not stopped, 
it will continue to blink the LED.
Note that by assigning a higher priority number to a task, you will guarentee which task runs 
first.  When taskOne and taskTwo are both priority 1, then sometimes they run out of order.
This file was initiated by vmicro/create blank arduino project.*/

#include "blink.h"
void setup() {

	Serial.begin(112500);
	delay(1000);
	
	blink(); //xTaskCreate(&blink_task, "blink_task", 512, NULL, 5, NULL); //from blink.cpp

	xTaskCreate(
		taskOne,          /* Task function. */
		"TaskOne",        /* String with name of task. */
		10000,            /* Stack size in words. */
		NULL,             /* Parameter passed as input of the task */
		1,                /* Priority of the task. */
		NULL);            /* Task handle. */

	xTaskCreate(
		taskTwo,          /* Task function. */
		"TaskTwo",        /* String with name of task. */
		10000,            /* Stack size in words. */
		NULL,             /* Parameter passed as input of the task */
		2,                /* Priority of the task. */
		NULL);            /* Task handle. */

	

}

void loop() {
	delay(1000);
	//blink();
}

void taskOne(void * parameter)
{

	for (int i = 0; i<10; i++) {

		Serial.println("Hello from task 1");
		delay(1000);
	}

	Serial.println("Ending task 1");
	vTaskDelete(NULL);

}

void taskTwo(void * parameter)
{

	for (int i = 0; i<10; i++) {

		Serial.println("Hello from task 2");
		delay(1000);
	}
	Serial.println("Ending task 2");
	vTaskDelete(NULL);

}