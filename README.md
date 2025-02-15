# Monster_Sensor
Monster Sensor / Monster Detector

gedacht für alle Kinder die Angst vor Monstern im Schrank oder unter dem Bett oder wo auch immmer haben.
Der Scaner startet, macht ein bisschen blink blink und erzählt ein bisschen was.
Es gibt 3 Knöpfe zum bedienen:

Knopf 1:
"Ein / Ausschalten"

Knopf 2:
Führt eine aktive Monster suche durch und verkündet am Ende "Keine Monster gefunden"

Knopf 3:
Aktiver Schutz vor Monstern: Eigentlich "nur" ein Nachtlicht.

Bauteile:

- ESP32-C6
- DFplayer mini + SD Karte + MP3 files
- Lautsprecher (ich habe einen 5cm Lautsprecher verwendet)
- NeopixelLED-Ring oder vergleichbar
- 3 Taster
- "Magnetladekabel"

Was kommt wo hin?
- Die Lautsprecher werden an den DFplayer mini angeschlossen
- Der DFPlayer mini wird am ESP angeschlossen: 5V an 5V, GND an GND, ACHTUNG, TX vom ESP mit an RX vom Player, und RX an TX, also gedreht!
- Taster jeweils am PIN und GND
- LED-Ring an 5V und GND vom ESP und die Datenleitung an den entsprechenden PIN.

Dann muss der Code noch auf den ESP, ich habe das mit Arduino IDE gemacht. 

Ich habe schlechte Erfahrungen damit gemach, ESP-Platinen direkt an ein Kabel anzuschließen. Daher bin ich dazu
übergegangen, Magnetische-USB-Stecker zu verwenden. Da die Platine in einer verschraubten Dose eingebaut worden ist,
habe ich mich auch dazu entschieden, eine Steckverbindung zu nehmen, die Daten übertragen kann (Sollte man noch mal was
anders Programmieren wollen)

Viel Spaß damit :-)

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Monster_Sensor
Monster Sensor / Monster Detector

for all children who are afraid of monsters in the cupboard or under the bed or wherever.
The scanner starts, makes a little blinky blinky and make some noise and tell a story.
There are only 3 buttons to operate:

Button 1:
“On / Off”

Button 2:
Performs an active monster search and announces “No monsters found” at the end

Button 3:
Active protection from monsters: actually “just” a night light.

Components:

- ESP32-C6
- DFplayer mini + SD card + MP3 files
- Speaker (I used a 5cm speaker)
- NeopixelLED ring or similar
- 3 buttons
- “Magnetic charging cable”

What goes where?
- The speakers are connected to the DFplayer mini
- The DFPlayer mini is connected to the ESP: 5V to 5V, GND to GND, ATTENTION, TX from the ESP to RX from the player, and RX to TX, i.e. turned!
- Push-button on PIN and GND
- LED ring to 5V and GND from the ESP and the data line to the corresponding PIN.

Then the code has to be written to the ESP, I did this with Arduino IDE. 

I have had bad experiences with connecting ESP boards directly to a cable. Therefore I have
to use magnetic USB connectors. Since the board has been installed in a screwed box,
I also decided to use a plug connection that can transfer data (in case you want to program something else).
want to program something else)

Have fun with it :-)l

