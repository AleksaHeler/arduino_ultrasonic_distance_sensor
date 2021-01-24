// Mesures somewhat accurate distance with ultrasonic distance sensor

#define SAMPLE_SIZE 20
#define SENSOR_OFFSET 5 //cm

const int vccPin = 11;
const int pingPin = 12; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 13; // Echo Pin of Ultrasonic Sensor

float cm;
long duration;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   
   pinMode(vccPin, OUTPUT);
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);
   
   digitalWrite(vccPin, HIGH);
}

void loop() {
  cm = 0;

  // Saple couple of times
  for(int i = 0; i < SAMPLE_SIZE; i++){
    digitalWrite(pingPin, LOW); // Send signal
    delayMicroseconds(2);
    digitalWrite(pingPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(pingPin, LOW);
    
    duration = pulseIn(echoPin, HIGH); // Receive signal
    cm += duration / 29.0 / 2.0; // us to cm
    
    delay(20);
  }
  
  cm /= SAMPLE_SIZE;
  
  Serial.print(cm + SENSOR_OFFSET);
  Serial.println("cm");
}
