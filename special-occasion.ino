const int BUTTON = 2;
const int SPEAKERCONTROL = 3;
const int REDLED = 4;
const int GREENLED = 5;
const int BLUELED = 6;
const int LED = 13;

String command;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT);
  pinMode(SPEAKERCONTROL, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  pinMode(BLUELED, OUTPUT);
  digitalWrite(BUTTON, HIGH); // pull-up
  Serial.begin(9600);
}

boolean handle_button()
{
  int button_pressed = !digitalRead(BUTTON); // pin low -> pressed
  return button_pressed;
}

void specialOccasion(){
  digitalWrite(LED, HIGH);
  digitalWrite(SPEAKERCONTROL, HIGH);
  for(int i = 0; i < 10; i++){
      digitalWrite(REDLED, HIGH);
      delay(100);
      digitalWrite(REDLED, LOW);
      digitalWrite(GREENLED, HIGH);
      delay(100);
      digitalWrite(GREENLED, LOW);
      digitalWrite(BLUELED, HIGH);
      delay(100);
      digitalWrite(BLUELED, LOW);
  }
  digitalWrite(LED, LOW);
  digitalWrite(SPEAKERCONTROL, LOW);
}
void loop() {
  // put your main code here, to run repeatedly:

  boolean button_pressed = handle_button();

  if(button_pressed){
    specialOccasion();
  }
  else{
    digitalWrite(LED, LOW);
    digitalWrite(SPEAKERCONTROL, LOW);
  }
  if(Serial.available()){
    command = Serial.readString();
    Serial.println("got command: " + command);
  }
  if(command == "special-occasion"){
    
    specialOccasion();
    command = "";
  }
  delay(20);
}
