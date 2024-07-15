const int button0 = 35;    
const int button1 = 34;    
const int button2 = 39;    
const int button3 = 36;
const int led0 = 16;
const int led1 = 17;
const int led2 = 19;
const int led3 = 23;
const int ledT = 32;

int buttonState0;
int buttonState1;
int buttonState2;
int buttonState3;
int lastButtonState0 = LOW;
int lastButtonState1 = LOW;
int lastButtonState2 = LOW;
int lastButtonState3 = LOW;

unsigned long lastDebounceTime0 = 0;  
unsigned long lastDebounceTime1 = 0;  
unsigned long lastDebounceTime2 = 0;  
unsigned long lastDebounceTime3 = 0;
unsigned long debounceDelay = 50;

void setup() {
  pinMode(button0, INPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ledT, OUTPUT);
  
  offAllLeds();
  digitalWrite(led0, HIGH);
}

void loop() {
  int reading0 = digitalRead(button0);
  int reading1 = digitalRead(button1);
  int reading2 = digitalRead(button2);
  int reading3 = digitalRead(button3);
  
  if (reading0 != lastButtonState0) {
    lastDebounceTime0 = millis();
  }
  
  if (reading1 != lastButtonState1) {
    lastDebounceTime1 = millis();
  }

  if (reading2 != lastButtonState2) {
    lastDebounceTime2 = millis();
  }
  
  if (reading3 != lastButtonState3) {
    lastDebounceTime3 = millis();
  }

  if ((millis() - lastDebounceTime0) > debounceDelay) {
    if (reading0 != buttonState0) {
      buttonState0 = reading0;

      if (buttonState0 == HIGH) {
        offAllLeds();
        digitalWrite(led0, HIGH);
      }
    }
  }
  
  if ((millis() - lastDebounceTime1) > debounceDelay) {
    if (reading1 != buttonState1) {
      buttonState1 = reading1;

      if (buttonState1 == HIGH) {
        offAllLeds();
        digitalWrite(led1, HIGH);
      }
    }
  }
  
  if ((millis() - lastDebounceTime2) > debounceDelay) {
    if (reading2 != buttonState2) {
      buttonState2 = reading2;

      if (buttonState2 == HIGH) {
        offAllLeds();
        digitalWrite(led2, HIGH);
      }
    }
  }
  
  if ((millis() - lastDebounceTime3) > debounceDelay) {
    if (reading3 != buttonState3) {
      buttonState3 = reading3;

      if (buttonState3 == HIGH) {
        offAllLeds();
        digitalWrite(led3, HIGH);
      }
    }
  }

  lastButtonState0 = reading0;
  lastButtonState1 = reading1;
  lastButtonState2 = reading2;
  lastButtonState3 = reading3;

  if(lastButtonState0 == HIGH || lastButtonState1 == HIGH || lastButtonState2 == HIGH || lastButtonState3 == HIGH) {
    digitalWrite(ledT, HIGH);
  }
  else {
    digitalWrite(ledT, LOW);
  }
}

void offAllLeds(){
  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}
