#include <LiquidCrystal.h>

#define pinSensor      A0     // Pino do sensor de umidade do solo
#define pinTemp        A1     // Pino do sensor de temperatura
#define pinPot         A2     // Pino do potenciômetro
#define verdePin       3      // Pino do LED verde
#define vermelhoPin    2      // Pino do LED vermelho
#define dcMotor        5      // Pino do motor DC

// Define os pinos do display LCD
const int rsPin = 12;
const int enPin = 11;
const int d4Pin = 9;
const int d5Pin = 8;
const int d6Pin = 7;
const int d7Pin = 6;

LiquidCrystal lcd(12, 11, 9, 8, 7, 6);  // Configura os pinos do LCD


void setup() {
  pinMode(pinSensor, INPUT);     // Define o pino do sensor de umidade do solo como entrada
  pinMode(pinTemp, INPUT);       // Define o pino do sensor de temperatura como entrada
  pinMode(pinPot, INPUT);        // Define o pino do potenciômetro como entrada
  pinMode(verdePin, OUTPUT);     // Define o pino do LED verde como saída
  pinMode(vermelhoPin, OUTPUT);  // Define o pino do LED vermelho como saída
  pinMode(dcMotor, OUTPUT);      // Define o pino do motor DC como saída

  lcd.begin(16, 2);  // Inicia o LCD com 16 colunas e 2 linhas
}

void loop() {
  int umidade = lerSensor(pinSensor);     // Lê o valor do sensor de umidade do solo
  int temperatura = lerSensor(pinTemp);   // Lê o valor do sensor de temperatura
  int potenciometro = lerSensor(pinPot);  // Lê o valor do potenciômetro
  
    
 
 // Umidade abaixo de 60: liga o LED verde e o motor DC
  if (umidade < 60) {     
    digitalWrite(verdePin, LOW);
    digitalWrite(vermelhoPin, HIGH);
    digitalWrite(dcMotor, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Umid. Solo: ");    
    lcd.print(umidade);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Irrigacao ON");    
    delay(3000);
    lcd.clear();
  }
  else{       
    digitalWrite(verdePin, HIGH);
    digitalWrite(vermelhoPin, LOW);
    digitalWrite(dcMotor, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Umid. Solo: ");
    lcd.print(umidade);
    lcd.print("%"); 
    lcd.setCursor(0, 1);
    lcd.print("Irrigacao OFF");
    delay(3000);
    lcd.clear();
  }
  
  // Exibe a temperatura no LCD por 3 segundos
  lcd.setCursor(0, 0);
  lcd.print("Temperatura: ");
  lcd.print(temperatura);
  lcd.print("C");
  delay(3000);
  lcd.clear();

  // Exibe o valor do potenciômetro no LCD por 3 segundos
  lcd.setCursor(0, 0);
  lcd.print("Umidade Ar: ");
  lcd.print(potenciometro);
  lcd.print("%");
  delay(3000);
  lcd.clear();
 

  delay(1000);  // Aguarda 1 segundo
}
 

int lerSensor(int pin) {
  int valor = analogRead(pin);              // Lê o valor analógico do sensor
  int mapeado = map(valor, 0, 1023, 0, 100); // Mapeia o valor para uma faixa de 0 a 100
  return mapeado;
}
