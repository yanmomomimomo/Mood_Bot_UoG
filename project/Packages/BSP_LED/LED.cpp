/************************* Functions of LED *************************/
// Header Declaration
#include "LED.h"

// Functions
void LED_Config(){
	pinMode(LED_RED_PIN, OUTPUT);
	digitalWrite(LED_RED_PIN, LOW);
	pinMode(LED_YELLOW_PIN, OUTPUT);
	digitalWrite(LED_YELLOW_PIN, LOW);
}

void LED_RED() {
	LED_FLASH(LED_RED_PIN);
}
void LED_YELLOW() {
	LED_FLASH(LED_YELLOW_PIN);
}

/*********************************** END **********************************/
