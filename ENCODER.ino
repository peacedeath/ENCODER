
#define pin_A 12
#define pin_B 11

bool state;
int i;

void setup() {
  Serial.begin(115200);
   
  pinMode(pin_A, INPUT_PULLUP);
  pinMode(pin_B, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  i = 0;
}

void loop() {

  if (state != digitalRead(pin_A)) {
    if (!state && digitalRead(pin_A) && digitalRead(pin_B) || state && !digitalRead(pin_A) && !digitalRead(pin_B)) {
      state = digitalRead(pin_A);
      if (i<255) i++;
    }
    if (state && !digitalRead(pin_A) && digitalRead(pin_B) || !state && digitalRead(pin_A) && !digitalRead(pin_B)) {
      state = digitalRead(pin_A);
      if (i>0) i--;
    }
    Serial.printf("%i\n", i);
    analogWrite(9, i);
  } 
  
}
