/*
* + Blink 2 LED s and Fade 1 LED
* + This is a non blocking blinking and fading sketch. 
* + This sketch doesnt use any loop or delays to run these 
*   2 instructions.
* + These 2 instructions run parallely without blocking each  
*   instructions using mills() function
* 
* reference: https://www.arduino.cc/en/Tutorial/BlinkWithoutDelay
*/

const int LED_1 = 12;
const int LED_2 = 11;
const int LED_PWM_1 = 10;

const long delayTime = 100;

int LED_1_STATE = LOW;
int LED_2_STATE = LOW;

unsigned long previousBlinkMills = 0;
unsigned long previousFadeMills = 0;

int fadeValue = 0;
bool fadeState = true;

// Using for loops  -> block other instructions
// Using delays     -> block other instructions
// Solution         -> use millis() function, With state changes

void setup() {
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
}

void loop() {

  unsigned long currentMills = millis();

  // 2 LED Blink
  if(currentMills - previousBlinkMills >= delayTime) {
    previousBlinkMills = currentMills;

      if(LED_1_STATE == LOW) {
         LED_1_STATE = HIGH;
         LED_2_STATE = LOW;
      }else {
        LED_1_STATE = LOW;
        LED_2_STATE = HIGH;
      }
  }

  // 1 LED Fading
  if(currentMills - previousFadeMills >= delayTime/10) {
      previousFadeMills = currentMills;
       
      if(fadeState) {
        fadeValue += 3;  
      }else {
        fadeValue -= 3; 
      }

      if(fadeValue >= 255) {
        fadeState = false;
      } 
      else if(fadeValue <= 0) {
        fadeState = true;
      }
  }
  
  digitalWrite(LED_1, LED_1_STATE); // blink led 1
  digitalWrite(LED_2, LED_2_STATE); // blink led 2
  analogWrite(LED_PWM_1, fadeValue); // fade led  
}
