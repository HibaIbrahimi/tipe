// Definition des broches pour les LEDs et le Buzzer
int const pin_led_rouge = 8;
int const pin_led_verte = 9;
int const pin_buzzer = A0;

// Definition des broches du senseur
int pin_d = 7;   // Senseur DOUT (digitale)
int pin_a = A2;  // Senseur AOUT (analogique)


void setup()
{
  // Definir les broches du senseur comme entree
  pinMode(pin_d, INPUT);
  pinMode(pin_a, INPUT);

  // Definir le buzzer et LEDs comme sortie
  pinMode(pin_led_rouge, OUTPUT);
  pinMode(pin_led_verte, OUTPUT);
  pinMode(pin_buzzer, OUTPUT);

  // Initialiser le port serie pour la communication serie
  Serial.begin(9600);
}

void loop()
{
  // Lecture de DOUT du senseur sur l'entree digital
  int valeur_digital = digitalRead(pin_d);
  // Lecture de AOUT du senseur sur l'entree analogique
  int valeur_analogique = analogRead(pin_a);

  // Afficher les donnees sur le moniteur serie
  Serial.print("DOut : ");
  Serial.print("\t");
  Serial.print(valeur_digital);
  Serial.print("\t");
  Serial.print(" Aout : ");
  Serial.println(valeur_analogique);

  // Verifier le niveau de gaz/fumee sur le detecteur
  
  if (valeur_analogique <9 )
    {
          // Tous va bien... laisser la LED verte allumée
    
    digitalWrite(pin_led_rouge, LOW);
    digitalWrite(pin_led_verte, HIGH);
    digitalWrite(pin_buzzer, LOW);
    Serial.print("la quantité de monoxyde de carbon detectée en ppm est normale ");
    
    }

  
  else if (valeur_analogique < 26)
  {
    // Passer en mode alarme (led rouge et buzzer)
    
    digitalWrite(pin_led_rouge, HIGH);
    digitalWrite(pin_led_verte, LOW);
    digitalWrite(pin_buzzer, HIGH);
    tone(A0,300);
    Serial.print("la quantité de monoxyde de carbon detectée en ppm est de  : ");
    Serial.print("\t");
    Serial.print(valeur_analogique);
  }
  else if (valeur_analogique < 35)
  {
    digitalWrite(pin_led_rouge, HIGH);
    digitalWrite(pin_led_verte, LOW);
    digitalWrite(pin_buzzer, HIGH);
    tone(A0,1000);
    Serial.print("la quantité de monoxyde de carbon detectée en ppm est de  : ");
    Serial.print("\t");
    Serial.print(valeur_analogique);
  }

  else 
  {
    digitalWrite(pin_led_rouge, HIGH);
    digitalWrite(pin_led_verte, LOW);
    digitalWrite(pin_buzzer, HIGH);
    tone(A0,3000);
    Serial.print("la quantité de monoxyde de carbon detectée en ppm est de  : ");
    Serial.print("\t");
    Serial.print(valeur_analogique);
  }
    delay(100); // petite pause
}
