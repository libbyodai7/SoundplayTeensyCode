#include <HCSR04.h>
const int channel = 3;

float data;
byte current_value;
byte previous_value;
const int controller = 24;

UltraSonicDistanceSensor distanceSensor(0, 1);

void setup () {

}

void loop () {
  usbMIDI.read(); 
  
  data = distanceSensor.measureDistanceCm();

 Serial.println(data);

  if (data >= 2.0 && data <= 70.0) {

    current_value = map(data, 2.0, 70.0, 30, 85);

    Serial.println(current_value);

    if (current_value != previous_value) {

      usbMIDI.sendNoteOn( current_value, 100, channel);
      delay(100);
      usbMIDI.sendNoteOff( current_value, 100, channel);
      
       while (usbMIDI.read()) {
  }
      
    }

    delay(5);
  }
}
