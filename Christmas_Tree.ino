#include <BluetoothSerial.h>
#include <driver/ledc.h>

BluetoothSerial ESP_BT;

#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

const int BUZZER_PIN = 33;
const int numLeds = 6;
const int ledPins[numLeds] = {15, 17, 18, 19, 21, 22};
byte currentMode = 0;

struct {
  int startIndex;
  bool initialPhase;
  unsigned long ledTimer;
  unsigned long noteTimer;
  int currentNote;
  int pathPosition;
  bool isMoving;
  bool ledState;
} joc6State;

const int startMelody[] = {NOTE_C4, NOTE_E4, NOTE_G4, NOTE_C5};
const int noteDurations[] = {500, 500, 500, 500};

const int snakePath[] = {0, 1, 2, 3, 5, 4}; // 15-17-18-19-22-21
const int pathLength = sizeof(snakePath)/sizeof(snakePath[0]);

void setup() {
  for(int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(BUZZER_PIN, OUTPUT);
  
  ESP_BT.begin("ESP32_Snake");
  Serial.begin(115200);
  allLedsOff();
}

void loop() {
  if(ESP_BT.available()) {
    String command = ESP_BT.readStringUntil('\n');
    command.trim();
    
    if(command.startsWith("6,")) {
      int n = command.substring(2).toInt();
      if(n >=1 && n <=6) {
        currentMode = 6;
        joc6State.startIndex = n-1;
        joc6State.initialPhase = true;
        joc6State.ledTimer = millis();
        joc6State.noteTimer = millis();
        joc6State.currentNote = 0;
        joc6State.ledState = false;
        joc6State.isMoving = false;
        allLedsOff();
        
        joc6State.pathPosition = 0;
        for(int i=0; i<pathLength; i++) {
          if(snakePath[i] == joc6State.startIndex) {
            joc6State.pathPosition = i;
            break;
          }
        }
      }
    }
    else if(command.length() == 1) {
      currentMode = command.charAt(0) - '0';
      allLedsOff();
      noTone(BUZZER_PIN);
    }
  }

  switch(currentMode) {
    case 1: jocul1(); break;
    case 2: jocul2(); break;
    case 3: jocul3(); break;
    case 4: jocul4(); break;
    case 5: jocul5(); break;
    case 6: jocul6(); break;
    default: allLedsOff(); break;
  }
}


void allLedsOff() {
  for(int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
void allLedsOn() {
  for(int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}
void jocul1() {
  static unsigned long lastTime = 0;
  static byte step = 0;
  const int perechi[][2] = {{15,22}, {18,21}, {17,19}};

  if(millis() - lastTime >= 1000) {
    lastTime = millis();
    allLedsOff();
    
    digitalWrite(perechi[step][0], HIGH);
    digitalWrite(perechi[step][1], HIGH);
    tone(BUZZER_PIN, NOTE_G4, 200);
    
    step = (step + 1) % 3;
  }
}
void jocul2() {
  static unsigned long lastTime = 0;
  static byte fase = 0;
  static byte current = 0;
  const int ordineAprindere[] = {15,17,18,19,21,22};
  const int ordineStingere[] = {22,21,19,18,17,15};

  if(millis() - lastTime >= 500) {
    lastTime = millis();
    
    if(fase == 0) {
      if(current < 6) {
        digitalWrite(ordineAprindere[current], HIGH);
        tone(BUZZER_PIN, NOTE_A4, 200);
        current++;
      } else {
        fase = 1;
        current = 0;
      }
    } else {
      if(current < 6) {
        digitalWrite(ordineStingere[current], LOW);
        tone(BUZZER_PIN, NOTE_A4, 200);
        current++;
      } else {
        fase = 0;
        current = 0;
      }
    }
  }
}
void jocul3() {
  static unsigned long lastTime = 0;
  static byte fase = 0;

  switch(fase) {
    case 0: // Grup 1
      allLedsOff();
      digitalWrite(15, HIGH);
      digitalWrite(17, HIGH);
      digitalWrite(18, HIGH);
      tone(BUZZER_PIN, NOTE_E4, 200);
      lastTime = millis();
      fase = 1;
      break;
    
    case 1:
      if(millis() - lastTime >= 1000) fase = 2;
      break;
    
    case 2: // Grup 2
      allLedsOff();
      digitalWrite(19, HIGH);
      digitalWrite(21, HIGH);
      tone(BUZZER_PIN, NOTE_F4, 200);
      lastTime = millis();
      fase = 3;
      break;
    
    case 3:
      if(millis() - lastTime >= 1000) fase = 4;
      break;
    
    case 4: // Grup 3
      allLedsOff();
      digitalWrite(22, HIGH);
      tone(BUZZER_PIN, NOTE_G4, 200);
      lastTime = millis();
      fase = 5;
      break;
    
    case 5:
      if(millis() - lastTime >= 1000) fase = 6;
      break;
    
    case 6: // Toate LED-urile
      allLedsOn();
      tone(BUZZER_PIN, NOTE_C5, 200);
      lastTime = millis();
      fase = 7;
      break;
    
    case 7:
      if(millis() - lastTime >= 2000) {
        allLedsOff();
        fase = 0;
      }
      break;
  }
}
void jocul4() {
  static unsigned long lastTime = 0;
  static bool stare = false;

  if(millis() - lastTime >= 500) {
    lastTime = millis();
    stare = !stare;
    
    for(int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], stare);
    }
    tone(BUZZER_PIN, NOTE_B4, 200);
  }
}
void jocul5() {
  static unsigned long lastTime = 0;
  static byte current = 0;
  const byte ordine[] = {0, 1, 2, 3, 5, 4}; // 15,17,18,19,22,21

  if(millis() - lastTime >= 500) {
    lastTime = millis();
    
    allLedsOff();
    digitalWrite(ledPins[ordine[current]], HIGH);
    tone(BUZZER_PIN, NOTE_D4, 200);
    
    current = (current + 1) % 6;
  }
}
void jocul6() {
  if(joc6State.initialPhase) {
    if(millis() - joc6State.ledTimer >= 250) {
      joc6State.ledTimer = millis();
      joc6State.ledState = !joc6State.ledState;
      digitalWrite(ledPins[snakePath[joc6State.pathPosition]], joc6State.ledState);
      digitalWrite(ledPins[snakePath[(joc6State.pathPosition+1)%pathLength]], joc6State.ledState);
    }
    
    if(millis() - joc6State.noteTimer >= noteDurations[joc6State.currentNote]) {
      tone(BUZZER_PIN, startMelody[joc6State.currentNote], noteDurations[joc6State.currentNote]);
      joc6State.noteTimer = millis();
      joc6State.currentNote++;
      
      if(joc6State.currentNote >= 4) {
        joc6State.initialPhase = false;
        joc6State.isMoving = true;
        allLedsOff();
        joc6State.ledTimer = millis();
      }
    }
  }
  else if(joc6State.isMoving) {
    if(millis() - joc6State.ledTimer >= 700) {
      joc6State.ledTimer = millis();
      
      int currentPos = joc6State.pathPosition;
      int nextPos = (currentPos + 1) % pathLength;
      digitalWrite(ledPins[snakePath[currentPos]], LOW);
      digitalWrite(ledPins[snakePath[nextPos]], LOW);
      
      joc6State.pathPosition = nextPos;
      
      int newPos = joc6State.pathPosition;
      int newNextPos = (newPos + 1) % pathLength;
      digitalWrite(ledPins[snakePath[newPos]], HIGH);
      digitalWrite(ledPins[snakePath[newNextPos]], HIGH);
      tone(BUZZER_PIN, NOTE_C5, 200);
    }
  }
}
