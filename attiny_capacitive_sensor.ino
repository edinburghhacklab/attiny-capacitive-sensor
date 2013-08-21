#include <CapacitiveSensor.h>

#define INPUT_PIN 0
#define OUTPUT_PIN 1

// switch pin pulls low when active (high impedance when inactive)
#define SWITCH_PIN 3

// led pin goes high when active, low when inactive
#define LED_PIN 4

CapacitiveSensor cs = CapacitiveSensor(OUTPUT_PIN, INPUT_PIN);
boolean last_state = 0;

void setup()                    
{
  cs.set_CS_AutocaL_Millis(0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an example
  pinMode(LED_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT);
}

void loop()                    
{
  int threshold = 75;
  long total = cs.capacitiveSensor(30);
  if (total > threshold) {
    if (last_state==0) {
      digitalWrite(SWITCH_PIN, LOW);
      pinMode(SWITCH_PIN, OUTPUT);
      digitalWrite(LED_PIN, HIGH);
      last_state = 1;
      delay(50);
    }
  } else {
    if (last_state==1) {
      pinMode(SWITCH_PIN, INPUT);
      digitalWrite(LED_PIN, LOW); 
      last_state = 0;
      delay(50);
    }
  }
}

