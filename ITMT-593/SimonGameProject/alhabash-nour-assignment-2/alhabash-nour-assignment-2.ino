#include <LiquidCrystal.h>

// buzzer frequencies
int Do = 262, Re = 294 , Mi = 330 , Fa = 349 , Sol = 392 , 
    La = 440 , Si = 494, Do2 = 524;

// pin numbers
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
const int SW_pin = 2; // digital pin connected to switch output

const int buzz = 3;

const int rightPin = 4;
const int upPin = 5;
const int downPin = 6;
const int leftPin = 7;

const int d7 = 8;
const int d6 = 9;
const int d5 = 10;
const int d4 = 11;
const int en = 12;
const int rs = 13;

//function that initializes the LCD library
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//variables
int count = 0;
int switchVal = 0; 
int xVal = 0;
int yVal = 0;
int gameOn =0;

int clickBut;
int xValue;
int yValue;

const int levelMax = 20;
int level=1;
int sequence[levelMax];
int mySequence[levelMax];
int theSpeed = 1000;

//function prototypes


void setup() {
  pinMode(rightPin, OUTPUT);
  pinMode(downPin, OUTPUT);
  pinMode(upPin, OUTPUT);
  pinMode(leftPin, OUTPUT);
  
  pinMode(buzz, OUTPUT);
  
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Welcome to the");
  lcd.setCursor(0,1);
  lcd.print("Simon Game !");
  startGameLightAndSound();
  delay(500);
}

void loop() {
  clickBut = digitalRead(SW_pin);
  Serial.println(clickBut);
  lcd.setCursor(0,0);
  lcd.print("Press Joystick");
  lcd.setCursor(0,1);
  lcd.print("button to start.");
  
  if (clickBut==0 ){
    generateSeq();
    gameOn =1;
  }
  
  while(gameOn ==1 || level != 1){
    lcd.setCursor(0,0);
    lcd.print("Level               ");
    lcd.setCursor(6,0);
    lcd.print(level);
    lcd.setCursor(0,1);
    lcd.print("                     ");
    showSeq();
    getSeq();   
  }
}



void lightsOff(){
  digitalWrite(leftPin,LOW);
  digitalWrite(upPin,LOW);
  digitalWrite(downPin,LOW);
  digitalWrite(rightPin,LOW);
}

void lightsOn(){
  digitalWrite(leftPin,HIGH);
  digitalWrite(upPin,HIGH);
  digitalWrite(downPin,HIGH);
  digitalWrite(rightPin,HIGH);
}

void switchLeftWithSound(){
  lightsOff();
  digitalWrite(leftPin,HIGH);
  while (analogRead(X_pin)<200){
    tone(buzz, Si);
  }
  noTone(buzz);
}

void switchRightWithSound(){
  lightsOff();
  digitalWrite(rightPin,HIGH);
  while (analogRead(X_pin)>800){
    tone(buzz, Mi);
  }
  noTone(buzz);
}
void switchUpWithSound(){
  lightsOff();
  digitalWrite(upPin,HIGH);
  while (analogRead(Y_pin)>800){
    tone(buzz, Fa);
  }
  noTone(buzz);
}
void switchDownWithSound(){
  lightsOff();
  digitalWrite(downPin,HIGH);
  while (analogRead(Y_pin)<200){
    tone(buzz, Sol);
  }
  noTone(buzz);
}

void switchLeft(){
  lightsOff();
  digitalWrite(leftPin,HIGH);
}

void switchRight(){
  lightsOff();
  digitalWrite(rightPin,HIGH);
}
void switchUp(){
  lightsOff();
  digitalWrite(upPin,HIGH);
}
void switchDown(){
  lightsOff();
  digitalWrite(downPin,HIGH);
}

void startGameLightAndSound(){
  lightsOff();
  switchLeft();
  tone(buzz, Do, 200);
  delay(200); 
  switchDown();
  tone(buzz, Mi, 200);
  delay(200);
  switchRight();
  tone(buzz, Fa, 200);
  delay(200);
  switchUp();
  tone(buzz, Sol, 200);
  delay(200);
  lightsOff();
  tone(buzz, La, 100);
  delay(100);
  lightsOn();
  tone(buzz, Si, 100);
  delay(100);
  lightsOff();
  tone(buzz, La, 100);
  delay(100);
  lightsOn();
  tone(buzz, Do2, 100);
  delay(100);
  lightsOff();
  tone(buzz, La, 100);
  delay(100);
  lightsOn();
  tone(buzz, Do2, 100);
  delay(100);
  lightsOff();
}

void generateSeq (){
  randomSeed(millis());
  for (int j =0;j<levelMax;j++){
    sequence[j]= random(0,4);
    Serial.println(sequence[j]);
  }
}

void showSeq(){  
  for (int i = 0; i < level; i++){
    if (sequence[i] == 0){
      switchRight();
      tone(buzz, Mi);
      delay(theSpeed);
      noTone(buzz);
      Serial.println("showing Right");
    }
    if (sequence[i] == 1){
      switchUp();
      tone(buzz, Fa);
      delay(theSpeed);
      noTone(buzz);
      Serial.println("showing Up");
    }
    if (sequence[i] == 2){
      switchDown();
      tone(buzz, Sol);
      delay(theSpeed);
      noTone(buzz);
      Serial.println("showing Down");
    }
    if (sequence[i] == 3){
      switchLeft();
      tone(buzz, Si);
      delay(theSpeed);
      noTone(buzz);
      Serial.println("showing Left");
    }  
    lightsOff();
    delay(100);
  }
  delay(100);
}


int iToVariable (int i){
  if (i==0)
    return rightPin;
  if (i==1)
    return upPin;
  if (i==2)
    return downPin;
  if (i==3)
    return leftPin;
  return 0;
}

void getSeq(){
  int correct =0;
  for (int k =0; k<level; k++){
    correct =0;
    while(correct==0){
      if (analogRead(X_pin)>800){
        switchRightWithSound();
        mySequence[k] = 0;
        correct =1;
        delay(100);
        if (mySequence[k] != sequence[k]){
          loseGame();
          lightsOff();
          return;
        }
      }
      if (analogRead(X_pin)<200){
        switchLeftWithSound();
        mySequence[k] =3;
        correct =1;
        delay(100);
        if (mySequence[k] != sequence[k]){
          loseGame();
          lightsOff();
          return;
        }
        
      }
      if (analogRead(Y_pin)>800){
        switchUpWithSound();
        mySequence[k] =1;
        correct =1;
        delay(100);
        if (mySequence[k] != sequence[k]){
          loseGame();
          lightsOff();
          return;
        }
      }
      if (analogRead(Y_pin)<200){
        switchDownWithSound();
        mySequence[k] =2;
        correct =1;
        delay(100);
        if (mySequence[k] != sequence[k]){
          loseGame();
          lightsOff();
          return;
        }
      }
      delay(300);
      lightsOff();
    }
  }
  winLevel();
}

void loseGame(){
  lcd.setCursor(0,0);
  lcd.print("GAME OVER :-( ");
  lcd.setCursor(0,1);
  delay(100);
  lcd.print("Button to retry?");
  
  tone(buzz, Mi);
  delay(300);
  tone(buzz, Re);
  delay(300); 
  tone(buzz, Mi);
  delay(300);
  tone(buzz, Re);
  delay(300); 
  tone(buzz, Do);
  delay(800);
  noTone(buzz);
  delay(1000);

  gameOn = 0;
  level = 1;
  theSpeed = 1000;
}

void winLevel(){
  if (level<levelMax){
    level++;
  }
  theSpeed-=50;
  if (level==levelMax){
    lcd.setCursor(0,0);
    lcd.print("Congratulations!");
    lcd.setCursor(0,1);
    lcd.print("Game completed.");
  }
}


