int sensor = 7;
int val;
int led = 12;
int buz = 10;
int melody[] = {
  494, 659, 880, 880, 831, 880, 988, 1175, 1175, 1175, 988, 880, 831, 880, 988, 659, 587, 370, 440, 587, 370, 440, 494, 659, 880, 880, 831, 880, 988, 1175, 1175, 1175, 988, 880, 831, 880, 988, 659, 587, 370, 440, 587, 370, 440, 494
};
int noteDurations[] = {
  125, 125, 250, 125, 125, 250, 125, 125, 125, 125, 125, 125, 125, 250, 125, 125, 250, 125, 125, 250, 125, 125, 250, 125, 125, 250, 125, 125, 250, 125, 125, 125, 125, 125, 125, 125, 250, 125, 125, 250, 125, 125, 250, 125, 125, 250
};

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor,INPUT);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buz, OUTPUT);
  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(int); thisNote++) {

    // calcular la duración de la nota
    int noteDuration = noteDurations[thisNote];
    tone(buz, melody[thisNote], noteDuration);

    // pausa entre notas
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buz);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(sensor);
  if (val == LOW){
    digitalWrite(led, HIGH);
    delay(100);
    tone(buz, 2000, 64);
    delay(100);
    Serial.println("FLAP");
  }
  else {
    digitalWrite(led, LOW);
    delay(100);
  }
}
