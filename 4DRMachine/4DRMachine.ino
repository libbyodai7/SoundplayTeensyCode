float data = 0.0;

const int channel = 1;
const int controller = 22;

const int analogInPin1 = A9;
const int analogInPin2 = A8;

const float TriggerThresh = 800.0;

int notes[4] = {60, 64, 67, 72};
int SensorNote1 = 20;
int SensorNote2 = 80;

//pressed values
bool pressed[4] = {false};




void setup () {
  Serial.begin(9600);
  pinMode(23, INPUT_PULLUP);
  pinMode(22, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);

}

void loop () {
 usbMIDI.read(); 

 //pin mappings
int p[4] = {23, 22, 21, 20};

//analog read values
int a[4] = {0};


  
for (int i = 0; i < 4; ++i)
{

  a[i] = analogRead(p[i]);
  Serial.println(data);
 if ((a[i] < TriggerThresh) && (pressed[i] == false)){
  usbMIDI.sendNoteOn(notes[i], 100, channel);
  //Serial.println(a[i],  "note ON");
  pressed[i] = true;
 } 
 
 if ((a[i] >= TriggerThresh) && (pressed[i] = true)){
  usbMIDI.sendNoteOff(notes[i], 100, channel);
 // Serial.println( a[i], "note OFF");
  pressed[i]=false;
 }

 
}

  delay(5);
  }
