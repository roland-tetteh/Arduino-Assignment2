int buzzerPin = 8;
int segmentPins[] = {2, 3, 4, 5, 6, 7, 9};
int numSegments = 7;

byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 0, 0, 1, 0, 0},
  {0, 1, 1, 1, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 0},
  {1, 0, 1, 1, 1, 0, 0},
  {1, 1, 0, 1, 1, 1, 0},
  {1, 1, 0, 1,  0, 1, 1},

  {1, 1, 1, 0, 1, 1, 1},
};

void showDigit(int n) {
   if (n < 0 || n > 9) return;

  for(int i = 0; i < numSegments; i++) {
    digitalWrite(segmentPins[i], digits[n][i]);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  for(int i = 0; i < numSegments; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  Serial.println(" === Beeping Countdown Starting ===");
  int count = 9;
  while(count >= 1 ) {
    Serial.print("Counting: ");
    Serial.println(count);

    showDigit(count);
    tone(buzzerPin, 1000,200);
    delay(1000);
    count = count - 1;
  }
  int zero = 0;
  showDigit(zero);
  tone(buzzerPin, 1500, 1000);
  Serial.println("=== Countdown Complete === ");
}

  
void loop() {
  // put your main code here, to run repeatedly:

} **