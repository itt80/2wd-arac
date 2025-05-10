
#include <Arduino.h>

//motor sürücü pin tanımlamaları
#define ENA 5
#define ENB 6
#define A_IN1 7
#define A_IN2 8
#define B_IN1 9
#define B_IN2 10




// setup fonksiyonu, Arduino'nun başlangıçta çalıştırdığı fonksiyondur.
void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(A_IN1, OUTPUT);
  pinMode(A_IN2, OUTPUT);
  pinMode(B_IN1, OUTPUT);
  pinMode(B_IN2, OUTPUT);

}



void solMotorIleri(int guc) {  
  digitalWrite(A_IN1, HIGH);
  digitalWrite(A_IN2, LOW);
  analogWrite(ENA, guc);
}


void solMotorGeri(int guc) {  
  digitalWrite(A_IN1, LOW);
  digitalWrite(A_IN2, HIGH);
  analogWrite(ENA, guc);
}

void solMotorDurdur() {  
  digitalWrite(A_IN1, LOW);
  digitalWrite(A_IN2, LOW);
  analogWrite(ENA, 0);
}

void sagMotorIleri(int guc) {  
  digitalWrite(B_IN1, LOW);
  digitalWrite(B_IN2, HIGH);
  analogWrite(ENB, guc);
}

void sagMotorGeri(int guc) {  
  digitalWrite(B_IN1, HIGH);
  digitalWrite(B_IN2, LOW);
  analogWrite(ENB, guc);
}

void sagMotorDurdur() {  
  digitalWrite(B_IN1, LOW);
  digitalWrite(B_IN2, LOW);
  analogWrite(ENB, 0);
}

void ileriGit(int guc) {
  solMotorIleri(guc);
  sagMotorIleri(guc);
}
 
void geriGit(int guc) {
  solMotorGeri(guc);
  sagMotorGeri(guc);
}

void dur() {
  solMotorDurdur();
  sagMotorDurdur();
}

void solaDon(int guc) {
  solMotorGeri(guc);
  sagMotorIleri(guc);
}
void sagaDon(int guc) {
  solMotorIleri(guc);
  sagMotorGeri(guc);
} 


// loop fonksiyonu, Arduino'nun sürekli olarak çalıştırdığı fonksiyondur.
void loop() {
  solaDon(200);
  delay(1000);  
  sagaDon(200);
  delay(1000);

  ileriGit(200);
  delay(1000);    
  geriGit(200); 
  delay(1000);
  dur();  
  delay(1000);
  
}
