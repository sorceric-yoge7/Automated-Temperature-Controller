# Automated-Temperature-Controller
This is an arduino code for the project entitled "Automated Temperature Controller". The components include LED/buzzer, Servo Motor, Dc motor, Arduino UNO, Motor driver/L293D, Jumper Wires, Power supply, 9V/12V Battery, LCD Display 16x2 DHT11 Temperature Sensor.  The arduino controls the system which is a closed loop system and it is a real time processing model.  

The digital temperature and humidity sensor continuously monitors the temperature of the surrounding(Battery and Arduino) and updates to the controller.  If it exceeds the certain temperature, the motor unit which is actually a cooling system gets turned on.  It reduces the heat by moving horizontally with the help of the servo drive.  Also this consists of a LED/Buzzer to indicate the alarm sound to warn the people.  The LCD display shows the temperature and humidity level of the system and also it sends the warning message like "Over Heating, Cooling System Turns off".  With this miniature model, the cooling of the system is done and the temperature is maintained.  After the reduction in temperature to normal level, the cooling system is turned off, Thus a closed loop system is achieved.

The DC motor is mounted on the servo motor and is controlled by the arduino and roatated through servo.  Refer the connection details and the Pin out of the L293D IC.



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

