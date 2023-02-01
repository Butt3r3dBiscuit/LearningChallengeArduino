#include <math.h>


int ThermistorPin = 2;
int Vo;
double V = 3.3;
double R1 = 10000;
double R2, logR2;
double T;
double c1 = 6.6454e-3, c2 = -6.61678e-04, c3 = 3.51502e-06;

void setup() {
Serial.begin(9600);
}

void loop() {

  Vo = analogRead(ThermistorPin);
  R2 = R1 * ((V*204.6) / (double)Vo - 1.0d);
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