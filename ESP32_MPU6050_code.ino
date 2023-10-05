#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
Adafruit_MPU6050 m_p_u;
void setup(){
  Serial.begin(115200);
  while(!Serial)
  delay(20);
  if(!m_p_u.begin()){

    while(1){

      delay(20);
    }
  }
}
void loop(){
  //Acceleration on x,y,z planes 
  sensors_event_t acc,gcc,temp;
  m_p_u.getEvent(&acc,&gcc,&temp);
  Serial.println("Acceleration on x axes");
  Serial.println(acc.acceleration.x);
  Serial.println("Acceleration on y axes");
  Serial.println(acc.acceleration.y);
  Serial.println("Acceleration on z axes");
  Serial.println(acc.acceleration.z);
  delay(1000);
  //rotation  on x,y,z planes 
  Serial.println("rotation on x axes");
  Serial.println((gcc.gyro.x)*180/3.14);
  Serial.println("rotation on y axes");
  Serial.println((gcc.gyro.y)*180/3.14);
  Serial.println("rotation on z axes");
  Serial.println((gcc.gyro.z)*180/3.14);
  delay(1000);
// by bathri
}