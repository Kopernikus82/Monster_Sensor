
//MONSTER SENSOR

#include <Adafruit_NeoPixel.h>
#include <DFRobotDFPlayerMini.h>

#define LED_PIN 18       
#define BUTTON1_PIN 20
#define BUTTON2_PIN 19
#define BUTTON3_PIN 17
#define NUM_LEDS 16

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
DFRobotDFPlayerMini dfPlayer;

bool programActive[3] = {false, false, false};
bool program3Running = false;


// Setup
void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.fill(strip.Color(5, 0, 0));
  strip.show();
  delay(500);
  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  Serial1.begin(9600, SERIAL_8N1, 22, 23);     // RX=22, TX=23
  if (!dfPlayer.begin(Serial1)) {
    Serial.println("DFPlayer initialisierung fehlgeschlagen");
    while (true);
  }
  delay(3000);
  dfPlayer.volume(20);
  Serial.println("Fertig geladen");
  delay(200);
  strip.fill(strip.Color(20, 0, 0));
  strip.show(); 
}

// Hauptprogramm
void loop() {
  if (digitalRead(BUTTON1_PIN) == LOW) {
    toggleProgram1();
  } else if (digitalRead(BUTTON2_PIN) == LOW) {
    runProgram2();
  } else if (digitalRead(BUTTON3_PIN) == LOW) {
    toggleProgram3();
  }
  if (program3Running) {
    runProgram3();
  }
}

// Unterprogramm 1 - "Ein / Ausschalten des Monstersensors"
void toggleProgram1() {
  if (!programActive[0]) {
    programActive[0] = true;
    strip.fill(strip.Color(0, 30, 0));
    strip.show();
    delay(2000);
    dfPlayer.play(1);
    strip.fill(strip.Color(0, 0, 40));
    strip.show();
    delay(2000);
  } else {
    strip.clear();
    strip.show();
    programActive[0] = false;
  }
  delay(1000);
}


// Ein Monsterscan wird "aktiv" durchgeführt
void runProgram2() {
  if (!programActive[1]) {
    programActive[1] = true;
    strip.fill(strip.Color(128, 128, 128));
    strip.show();
    dfPlayer.play(2);
    delay(3000);
    dfPlayer.play(6);
    unsigned long startTime = millis();
    while (millis() - startTime < 40000) {
      for (int pos = 0; pos < NUM_LEDS; pos++) {
        for (int i = 0; i < NUM_LEDS; i++) {
          int distance = (i - pos + NUM_LEDS) % NUM_LEDS;
          int brightness = max(128 - (distance * 21), 0);
          strip.setPixelColor(i, strip.Color(0, 0, brightness));
        }
        strip.show();
        delay(100);
      }
    }
    dfPlayer.play(2);
    delay(2000); 
    strip.fill(strip.Color(32, 20, 0));
    strip.show();
    delay(1000);
    programActive[1] = false;
  }
}




// "Aktiver" Monsterschutz
void toggleProgram3() {
  program3Running = !program3Running;

  if (!program3Running) {
    strip.fill(strip.Color(0, 60, 0));
    strip.show();
  } else {
    delay(100);
    dfPlayer.play(4);
    delay(3000);
    dfPlayer.play(5);
  }

  delay(500);
}

void runProgram3() {
  static int j = 0;
  static int hue = 0;

  int brightness = (sin(j * 0.1) * 127) + 128;
  uint32_t color = strip.ColorHSV(hue, 255, brightness);

  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
  hue += 256;
  if (hue > 65535) hue = 0;
  delay(100);
  j++;
}


