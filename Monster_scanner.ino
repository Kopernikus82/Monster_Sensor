
//MONSTER SENSOR

#include <Adafruit_NeoPixel.h>
#include <DFRobotDFPlayerMini.h>

#define LED_PIN 5
#define BUTTON1_PIN 6
#define BUTTON2_PIN 7
#define BUTTON3_PIN 8
#define NUM_LEDS 9

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
DFRobotDFPlayerMini dfPlayer;

bool programActive[3] = {false, false, false};
bool program3Running = false;



void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.clear();
  strip.show();                               //Alle LED´s ausschalten
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  Serial1.begin(9600, SERIAL_8N1, 9, 10);     // RX=9, TX=10
  if (!dfPlayer.begin(Serial1)) {
    Serial.println("DFPlayer initialization failed!");
    while (true);
  }
  dfPlayer.volume(15);                        // Lautstärke (0 to 30)

  Serial.println("Setup completed!");
}

void loop() {
  if (digitalRead(BUTTON1_PIN) == LOW) {
    runProgram1();
  } else if (digitalRead(BUTTON2_PIN) == LOW) {
    runProgram2();
  } else if (digitalRead(BUTTON3_PIN) == LOW) {
    toggleProgram3();
  }
  if (program3Running) {
    runProgram3();
  }
}


// Startprogramm
void runProgram1() {
  if (!programActive[0]) {
    programActive[0] = true;
    strip.fill(strip.Color(255, 255, 255));
    strip.show();
    delay(2000);
    strip.fill(strip.Color(255, 165, 0));
    strip.show();
    delay(2000);
    strip.fill(strip.Color(0, 255, 0));
    strip.show();
    delay(2000);
    dfPlayer.play(1);                       // Erste MP3 abspielen (Monstersensor gestartet)
    strip.fill(strip.Color(0, 0, 255));
    strip.show();
    delay(1000);                            // Debounce
    programActive[0] = false;
  }
}


// Aktiver Monster Scan
void runProgram2() {
  if (!programActive[1]) {
    programActive[1] = true;
    dfPlayer.playMp3Folder(2);          // Zweite MP3 abspielen (Monstersensor gestartet)
      delay(500);
    for (int i = 0; i < 10; i++) {
      strip.fill(strip.Color(random(0, 255), random(0, 255), random(0, 255)));
      strip.show();
      delay(200);
    }
    for (int i = 0; i < 5; i++) {
      dfPlayer.playMp3Folder(2);          // Zweite MP3 abspielen (Monstersensor gestartet)
      delay(500);

      //MONSTER SCAN MP3
    }
    dfPlayer.play(3);                     // Dritte MP3 abspielen (Keine Monster gefunden)
    strip.fill(strip.Color(0, 0, 255));
    strip.show();
    delay(1000);                          // Debounce
    programActive[1] = false;
  }
}


//Passiver Monster Scan mit Nachtlicht

void toggleProgram3() {
  program3Running = !program3Running;

  if (!program3Running) {
    strip.fill(strip.Color(0, 0, 255));
    strip.show();
  } else {
    strip.fill(strip.Color(255, 255, 255));
    strip.show();
    dfPlayer.play(4);                      //Vierte MP3 abspielen (Monsterscanner gestartet)
    delay(500);
    strip.fill(strip.Color(255, 165, 0));
    strip.show();
    delay(5000);
    strip.fill(strip.Color(0, 255, 0));
    strip.show();
    delay(500);
    strip.fill(strip.Color(0, 0, 255));
    strip.show();
    dfPlayer.play(5);                     //Fünfte MP3 abspielen (Monsterscanner gestartet)
    delay(2000);
  }

  delay(500); // Debounce
}

void runProgram3() {
  // Pulsing light effect
  static int j = 0; // Static variable to keep track of the pulsing state
  int brightness = (sin(j * 0.1) * 127) + 128; // Sinusoidal pulsing
  strip.fill(strip.Color(brightness, 0, brightness));
  strip.show();
  delay(100);
  j++;
}
