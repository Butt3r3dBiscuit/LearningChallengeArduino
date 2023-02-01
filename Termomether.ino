#include <math.h>


int ThermistorPin = A1;
int Vo;
double R1 = 10001;
double R2, logR2;
double T;
double c1 = 6.6454e-3, c2 = -6.61678e-04, c3 = 3.51502e-06;

void setup() {
Serial.begin(9600);
}

void loop() {

  Vo = analogRead(ThermistorPin);
  Serial.print("Voltage: ");
  Serial.println(Vo);
  Serial.print((double) 5*Vo/1023);
  Serial.println(" V");
  R2 = R1 * (1023 / (double)Vo - 1.0d);
  Serial.print("R2: ");
  Serial.println(R2);
  logR2 = log(R2);
  T = (1.0d / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15d;

  Serial.print("Temperature using Steinhart: "); 
  Serial.print(T);
  Serial.println(" C"); 

  T = -24.43d*logR2 + 253.79d;
  Serial.print("Temperature using Regression: "); 
  Serial.print(T);
  Serial.println(" C");
  
  Serial.flush();

  delay(500);
}