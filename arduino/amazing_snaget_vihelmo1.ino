// C++ code
//
#include <LiquidCrystal.h>

// adresse du led rouge (PIN)
int LEDpin = 8;
#define PHOTOpin A5
// adresse du lcd (PIN) 
LiquidCrystal lcd(10, 9, 8, 6, 5, 3);
// adresse du BP1 (bouton poussoir 1) 
int Bp1 = 2;
// adresse du Buzzer (PIN) 
int BUZZER_PIN = 4;
// variable de l'etat de l'appui sur le BP1
int appui_bp1 = 0;
// variable pour son
float demi_periode = (2.27e-3) * 1000000;
//temps du son en milliseconde
float temps = 500;
//variable de calcul du temps de fonctionnement du buzzer
float duree = 0;
float frequenc = 120;
// adresse du Vibreur (PIN) 
int vibreur = 12;
String demande = "";
// adresse du led rouge (PIN) 
int pin_led_rouge = 7;

void setup()
{
  //initialiser le moniteur série
  Serial.begin(9600);
  //initialiser la LED
  pinMode(pin_led_rouge, OUTPUT);
  //initialiser la photorésistance
  pinMode(PHOTOpin, INPUT);
  //initialisation de l'écran LCD
  lcd.begin(20, 2);
  lcd.setCursor(0, 0);
  lcd.print("CoNecklace");
}

void loop()
{
  //lire la valeur de la photorésistance
  int sensor = analogRead(PHOTOpin);
  //afficher cette valeur dans le moniteur
  Serial.println(sensor);
  
  //Clignotement de ma LED
  digitalWrite(LEDpin, HIGH); // la LED s'allume
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LEDpin, LOW); // la led s'éteind
  delay(1000); // Wait for 1000 millisecond(s)
  
  // Récupération de l'état du bouton poussoir
  appui_bp1 = digitalRead(Bp1);
// si le bouton est appuyer on allume le buzzer le temps de la 
  if (appui_bp1 == LOW) {
    duree = 0;
    float frequenc;
    while (duree < temps * 1000) {
      digitalWrite(BUZZER_PIN, HIGH);
      delayMicroseconds(demi_periode);
      digitalWrite(BUZZER_PIN, LOW);
      delayMicroseconds(demi_periode);
      duree = duree + 2 * demi_periode;
    }
}
}