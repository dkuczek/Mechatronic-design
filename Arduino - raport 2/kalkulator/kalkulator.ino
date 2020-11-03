float number1; 
float number2;
char operation; 
float result; 

void setup() {
  Serial.begin(9600); 
  Serial.println("Podaj dzialanie do wyliczenia (np: 2+3)");
  Serial.println();
}

void loop() {
  while(Serial.available() > 0) {       
    number1 = Serial.parseFloat();    
    operation = Serial.read();  
    number2 = Serial.parseFloat();     
    calculate();  
    Serial.print("Wynik = ");
    Serial.println(result); 
    Serial.println("Gotowe..."); 
    Serial.println(); 
  }
}

void calculate() {  
    if (number2 == 0) {
    Serial.println("Blad, zle dane wejsciowe!!"); 
    Serial.println();
    result = 0;
  }
  
  else if (operation == '+') {
    result = number1 + number2;
  }
  else if (operation == '-')  {
    result = number1 - number2; 
  }
  else if (operation == '*')  {
    result = number1 * number2; 
  }
  else if (operation == '/')  {
    result = number1 / number2; 
  }

  else  {
    Serial.println("Blad, zle dane wejsciowe!!"); 
    Serial.println();
    result = 0;
  }
}
