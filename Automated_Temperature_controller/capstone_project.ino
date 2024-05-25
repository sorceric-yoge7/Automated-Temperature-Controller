#include <DHT.h>

#define DHTPIN 2         
#define DHTTYPE DHT11    
DHT dht(DHTPIN, DHTTYPE);
#include <Servo.h>

Servo myservo; 
int enA = 8;
int in1 = 9;
int in2 = 10;

void setup() {
  Serial.begin(9600);    
  dht.begin();          
  pinMode(4,OUTPUT);
  myservo.attach(6);
  pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
}

void loop() {
  delay(1000);           

  float humidity = dht.readHumidity();         
  float temperature = dht.readTemperature();   

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C");

  Serial.print("  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  
if (temperature > 28) {
 
  Serial.println("The System's temperature is HIGH, Fan turning on");
  digitalWrite(enA,HIGH);
  digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
  myservo.write(0);     
  delay(2000);          
  myservo.write(90);    
  delay(2000);          
 
} else {
  
  Serial.println("System is  Normal ");
  digitalWrite(4,HIGH);
  delay(2000);
  digitalWrite(4,LOW);
}

   
}
