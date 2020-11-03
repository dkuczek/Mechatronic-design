//Deklaracja przycisków
#define SW1 2  
#define SW2 3
#define SW3 4

//Zmienne pomocnicze określające stan przycisku SW1
int SW1_state = HIGH;
int SW1_state_last = LOW;

//Pozostałe zmienne
long lastDebounceTime = 0;
long time = 50;
int i = 0;
int state = LOW;



void setup() { 
  pinMode(SW1, INPUT_PULLUP); 
  pinMode(SW2, INPUT_PULLUP); 
  pinMode(SW3, INPUT_PULLUP); 
  
  digitalWrite(SW1, HIGH);
  
  Serial.begin(9600);

  pinMode(6, OUTPUT); 
  digitalWrite(6, HIGH); 
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  
  
  
} 
 

  
 void loop()  {  
   
   int button_read = digitalRead(SW1); 
   
   if (button_read != SW1_state_last) {
        lastDebounceTime = millis();
    }
   
   if ((millis() - lastDebounceTime) > time) {
        if (button_read != SW1_state) {
            SW1_state = button_read;

            if (SW1_state == HIGH) {
                state = !state;   
                if(state == 1 ) i++;
                Serial.println("Liczba wlaczeń programu:");
                Serial.println(i);
                Serial.println("Stan programu:");
                Serial.println(state);
            }
      
        }
        if(digitalRead(SW2) == LOW && state == 1) {
            digitalWrite(SW3,HIGH);
            digitalWrite(7, LOW); 
            digitalWrite(8, HIGH); 
        }
        if(digitalRead(SW3) == LOW && state == 1) {
            digitalWrite(SW2,HIGH);
            digitalWrite(7, HIGH); 
            digitalWrite(8, LOW); 
        }
        if(state == 0) {
           digitalWrite(7, LOW);
            digitalWrite(8, LOW);
     }
   }

    SW1_state_last = button_read; 
}
