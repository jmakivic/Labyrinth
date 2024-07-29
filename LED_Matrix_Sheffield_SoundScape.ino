// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#include "pitches.h"

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6// On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 32 // Popular NeoPixel ring size

#define BRIGHTNESS 125

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 250 // Time (in milliseconds) to pause between pixels

//TOMORROW: Add an array which maps these values to the LED matrix

int buttonValue4 = 0;
int buttonValue5 = 0;
int buttonValue7 = 0;
int buttonValue9 = 0;
int buttonValue10 = 0;
int buttonValue11 =0;
int buttonValue12 =0;
int buttonValue13 =0;
int buttonValue14 =0;
int buttonValue15 =0;
int buttonValue16 =0;
int buttonValue17 =0;
int buttonValue18 =0;
int buttonValue19 =0;
int buttonValue20 =0;
int buttonValue21 =0;
int buttonValue22 =0;
int buttonValue24 =0;
int buttonValue26 =0;
int buttonValue28 =0;
int buttonValue30 = 0;
int buttonValue32 = 0;
int buttonValue34 =0;
int buttonValue36 =0;
int buttonValue38 =0;
int buttonValue40 =0;
int buttonValue42 = 0;
int buttonValue44 = 0;
int buttonValue46 = 0;
int buttonValue48 = 0;
int buttonValue50 = 0;
int buttonValue52 = 0;

bool buttonBool4 = false;
bool buttonBool5 = false;
bool buttonBool7 = false;
bool buttonBool9 = false;
bool buttonBool10 = false;
bool buttonBool11 = false;
bool buttonBool12 = false;
bool buttonBool13 = false;
bool buttonBool14 = false;
bool buttonBool15 = false;
bool buttonBool16 = false;
bool buttonBool17 = false;
bool buttonBool18 = false;
bool buttonBool19 = false;
bool buttonBool20 = false;
bool buttonBool21 = false;
bool buttonBool22 = false;
bool buttonBool24 = false;
bool buttonBool26 = false;
bool buttonBool28 = false;
bool buttonBool30 = false;
bool buttonBool32 = false;
bool buttonBool34 = false;
bool buttonBool36 = false;
bool buttonBool38 = false; 
bool buttonBool40 = false;
bool buttonBool42 = false;
bool buttonBool44 = false;
bool buttonBool46 = false;
bool buttonBool48 = false;
bool buttonBool50 = false;
bool buttonBool52 = false;

//booleans for checking patterns
//rows
bool row1 = false;
bool row2 = false;
bool row3 = false;
bool row4 = false;
bool row5 = false;
bool row6 = false;
bool row7 = false;
bool row8 = false;

bool column1 = false;
bool column2 = false;
bool column3 = false;
bool column4 = false;

bool colTrack1 = false;
bool colTrack2 = false;
bool colTrack3 = false;
bool colTrack4 = false;

bool rowTrack1 = false;
bool rowTrack2 = false;
bool rowTrack3 = false;
bool rowTrack4 = false;
bool rowTrack5 = false;
bool rowTrack6 = false;
bool rowTrack7 = false;
bool rowTrack8 = false;

int snake_length = 5;
int snake_head_position = 0;
int snake[5] ={0,0,0,0,0};


void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  pixels.setBrightness(BRIGHTNESS);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    
    pixels.setPixelColor(i, pixels.Color(168, 139, 50));
    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }

  Serial.begin(9600);
  noTone(A10);
}

void loop() {

  noTone(A10);

  buttonValue4 = digitalRead(4);
  buttonValue5 = digitalRead(5);
  buttonValue7 = digitalRead(7);
  buttonValue9 = digitalRead(9);
  buttonValue10 = digitalRead(10);
  buttonValue11 = digitalRead(11);
  buttonValue12 = digitalRead(12);
  buttonValue13 = digitalRead(13);
  buttonValue14 = digitalRead(14);
  buttonValue15 = digitalRead(15);
  buttonValue16 = digitalRead(16);
  buttonValue17 = digitalRead(17);
  buttonValue18 = digitalRead(18);
  buttonValue19 = digitalRead(19);
  buttonValue20 = digitalRead(2);
  buttonValue21 = digitalRead(3);
  buttonValue22 = digitalRead(22);
  buttonValue24 = digitalRead(24);
  buttonValue26 = digitalRead(26);
  buttonValue28 = digitalRead(28);
  buttonValue30 = digitalRead(30);
  buttonValue32 = digitalRead(32);
  buttonValue34 = digitalRead(34);
  buttonValue36 = digitalRead(36);
  buttonValue38 = digitalRead(38);
  buttonValue40 = digitalRead(40);
  buttonValue42 = digitalRead(42);
  buttonValue44 = digitalRead(44);
  buttonValue46 = digitalRead(46);
  buttonValue48 = digitalRead(48);
  buttonValue50 = digitalRead(50);
  buttonValue52= digitalRead(52);

  ////no//////tone(A11);
  //noTone(A10);
   
  if(buttonValue4 == HIGH){
    onColor(50, 66, 168,1);
    Serial.println(4);
    if(buttonBool4 == false){
      tone(A11, NOTE_D1, 1000);
      tone(A10, NOTE_D1, 1000);
      delay(100);
      buttonBool4 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,1);
    buttonBool4 = false;
  }

  if(buttonValue5 == HIGH){
    onColor(50, 66, 168,6);
    Serial.println(5);
    if(buttonBool5 == false){
        tone(A11, NOTE_D1, 1000);
        tone(A10, NOTE_D1, 1000);
        delay(100);
        buttonBool5 = true;
        noTone(A10);
        noTone(A11);
    }
  }else{
    offColor(168, 139, 50,6);
    buttonBool5 = false;
  }
 
  if(buttonValue7 == HIGH){
    onColor(50, 66, 168,9);
    Serial.println(7);
    if(buttonBool7 == false){
      tone(A11, NOTE_F1, 1000);
      tone(A10, NOTE_F1, 1000);
      delay(100);
      buttonBool7 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,9);
    buttonBool7 = false;
  }

  if(buttonValue9 == HIGH){
    onColor(50, 66, 168,14);
    Serial.println(9);
    if(buttonBool9 == false){
      tone(A11, NOTE_C3, 1000);
      tone(A10, NOTE_C3, 1000);
      delay(100);
      buttonBool9 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,14);
    buttonBool9 = false;
  }

  if(buttonValue10 == HIGH){
    onColor(50, 66, 168,17);
    Serial.println(10);
    if(buttonBool10 == false){
      tone(A11, NOTE_A2, 1000);
      tone(A10, NOTE_A2, 1000);
      delay(100);
      buttonBool10 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,17);
    buttonBool10 = false;
  }

  if(buttonValue11 == HIGH){
    onColor(50, 66, 168,22);
    Serial.println(11);
    if(buttonBool11 == false){
      Serial.println("tone!!!");
      tone(A11, NOTE_C5, 1000);
      tone(A10, NOTE_C5, 1000);
      delay(100);
      buttonBool11 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,22);
    buttonBool11 = false;
  }

  if(buttonValue12 == HIGH){
    onColor(50, 66, 168,25);
    Serial.println(12);
    if(buttonBool12 == false){
      tone(A11, NOTE_B3, 1000);
      tone(A10, NOTE_B3, 1000);
      delay(100);
      buttonBool12 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,25);
    buttonBool12 = false;
  }

  if(buttonValue13 == HIGH){
    onColor(50, 66, 168,30);
    Serial.println(13);
    if(buttonBool13 == false){
      tone(A11, NOTE_G4, 1000);
      tone(A10, NOTE_G4, 1000);
      delay(100);
      buttonBool13 = true;
      noTone(A10);
      noTone(A11);
    } 
  }else{
    offColor(168, 139, 50,30);
    buttonBool13 = false;
  }

  if(buttonValue14 == HIGH){
    onColor(50, 66, 168,0);
    Serial.println(14);
    if(buttonBool14 == false){
      tone(A11, NOTE_D4, 1000);
      tone(A10, NOTE_D4, 1000);
      delay(100);
      buttonBool14 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,0);
    buttonBool14 = false;
  }

  if(buttonValue15 == HIGH){
    onColor(50, 66, 168,7);
    Serial.println(15);
    if(buttonBool15 == false){
      tone(A11, NOTE_F6, 1000);
      tone(A10, NOTE_F6, 1000);
      delay(100);
      buttonBool15 = true;
      noTone(A10);
      noTone(A11);
    }

  }else{
    offColor(168, 139, 50,7);
    buttonBool15 = false;
  }

  if(buttonValue16 == HIGH){
    onColor(50, 66, 168,8);
    Serial.println(16);
    if(buttonBool16 == false){
      tone(A11, NOTE_AS7, 1000);
      tone(A10, NOTE_AS7, 1000);
      delay(100);
      buttonBool16 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,8);
    buttonBool16 = false;
  }

  if(buttonValue17 == HIGH){
    onColor(50, 66, 168,15);
    Serial.println(17);
    if(buttonBool17 == false){
      tone(A11, NOTE_C8, 1000);
      tone(A10, NOTE_C8, 1000);
      delay(100);
      buttonBool17 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,15);
    buttonBool17 = false;
  }

  if(buttonValue18 == HIGH){
    onColor(50, 66, 168,16);
    Serial.println(18);
    if(buttonBool18 == false){
      tone(A11, NOTE_D4, 1000);
      tone(A10, NOTE_D4, 1000);
      delay(100);
      buttonBool18 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,16);
    buttonBool18 = false;
  }

  if(buttonValue19 == HIGH){
    onColor(50, 66, 168,23);
    Serial.println(19);
    if(buttonBool19 == false){
      tone(A11, NOTE_DS8, 1000);
      tone(A10, NOTE_DS8, 1000);
      delay(100);
      buttonBool19 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,23);
    buttonBool19 = false;
  }

  if(buttonValue20 == HIGH){
    onColor(50, 66, 168,31);
    Serial.println(20);
    if(buttonBool20 == false){
      tone(A11, NOTE_E5, 1000);
      tone(A10, NOTE_E5, 1000);
      delay(100);
      buttonBool20 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,31);
    buttonBool20 = false;
  }

  if(buttonValue21 == HIGH){
    onColor(50, 66, 168,24);
    Serial.println(21);
    if(buttonBool21 == false){
      tone(A11, NOTE_D4, 1000);
      tone(A10, NOTE_D4, 1000);
      delay(100);
      buttonBool21 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,24);
    buttonBool21 = false;
  }

  if(buttonValue22 == HIGH){
    onColor(50, 66, 168,29);
    Serial.println(22);
    if(buttonBool22 == false){
      tone(A11, NOTE_A4, 1000);
      tone(A10, NOTE_A4, 1000);
      delay(100);
      buttonBool22 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,29);
    buttonBool22 = false;
  }

  if(buttonValue24 == HIGH){
    onColor(50, 66, 168,26);
    Serial.println(24);
    if(buttonBool24 == false){
      tone(A11, NOTE_GS5, 1000);
      tone(A10, NOTE_GS5, 1000);
      delay(100);
      buttonBool24 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,26);
    buttonBool24 = false;
  }

  if(buttonValue26 == HIGH){
    onColor(50, 66, 168,21);
    Serial.println(26);
    if(buttonBool26 == false){
      tone(A11, NOTE_D1, 1000);
      tone(A10, NOTE_D1, 1000);
      delay(100);
      buttonBool26 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,21);
    buttonBool26 = false;
  }

  if(buttonValue28 == HIGH){
    onColor(50, 66, 168,18);
    Serial.println(28);
    if(buttonBool28 == false){
      tone(A11, NOTE_A1, 1000);
      tone(A10, NOTE_A1, 1000);
      delay(100);
      buttonBool28 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,18);
    buttonBool28 = false;
  }

  if(buttonValue30 == HIGH){
    onColor(50, 66, 168,13);
    Serial.println(30);
    if(buttonBool30 == false){
      tone(A11, NOTE_G6, 1000);
      tone(A10, NOTE_G6, 1000);
      delay(100);
      buttonBool30 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,13);
    buttonBool30 = false;
  }

  if(buttonValue32 == HIGH){
    onColor(50, 66, 168,2);
    Serial.println(32);
    if(buttonBool32 == false){
      tone(A11, NOTE_B7, 1000);
      tone(A10, NOTE_B7, 1000);
      delay(100);
      buttonBool32 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,2);
    buttonBool32 = false;
  }

  if(buttonValue34 == HIGH){
    onColor(50, 66, 168,10);
    Serial.println(34);
    if(buttonBool34 == false){
      tone(A11, NOTE_E6, 1000);
      tone(A10, NOTE_E6, 1000);
      delay(100);
      buttonBool34 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,10);
    buttonBool34 = false;
  }

  if(buttonValue36 == HIGH){
    onColor(50, 66, 168,5);
    Serial.println(36);
    if(buttonBool36 == false){
      tone(A11, NOTE_G2, 1000);
      tone(A10, NOTE_G2, 1000);
      delay(100);
      buttonBool36 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,5);
    buttonBool36 = false;
  }

  if(buttonValue38== HIGH){
    onColor(50, 66, 168,3);
    Serial.println(38);
    if(buttonBool38 == false){
      tone(A11, NOTE_B0, 1000);
      tone(A10, NOTE_B0, 1000);
      delay(100);
      buttonBool38 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,3);
    buttonBool38 =false;
  }

  if(buttonValue40== HIGH){
    onColor(50, 66, 168,4);
    Serial.println(40);
    if(buttonBool40 == false){
      tone(A11, NOTE_AS5, 1000);
      tone(A10, NOTE_AS5, 1000);
      delay(100);
      buttonBool40 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,4);
    buttonBool40 = false;
  }

  if(buttonValue42== HIGH){
    onColor(50, 66, 168,11);
    Serial.println(42);
      if(buttonBool42 == false){
      tone(A11, NOTE_D4, 1000);
      tone(A10, NOTE_D4, 1000);
      delay(100);
      buttonBool42 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,11);
    buttonBool42 = false;
  }

  if(buttonValue44== HIGH){
    onColor(50, 66, 168,12);
    Serial.println(44);
    if(buttonBool44 == false){
      tone(A11, NOTE_F3, 1000);
      tone(A10, NOTE_F3, 1000);
      delay(100);
      buttonBool44 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,12);
    buttonBool44 = false;
  }

  if(buttonValue46== HIGH){
    onColor(50, 66, 168,19);
    Serial.println(46);
    if(buttonBool46 == false){
      tone(A11, NOTE_C1, 1000);
      tone(A10, NOTE_C1, 1000);
      delay(100);
      buttonBool46 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,19);
    buttonBool46 = false;
  }

  if(buttonValue48== HIGH){
    onColor(50, 66, 168,20);
    Serial.println(48);
    if(buttonBool48 == false){
      tone(A11, NOTE_B7, 1000);
      tone(A10, NOTE_B7, 1000);
      delay(100);
      buttonBool48 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,20);
    buttonBool48 = false;
  }

  if(buttonValue50 == HIGH){
    onColor(50, 66, 168,27);
    Serial.println(50);
    if(buttonBool50 == false){
      tone(A11, NOTE_FS6, 1000);
      tone(A10, NOTE_FS6, 1000);
      delay(100);
      buttonBool50 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,27);
    buttonBool50 = false;
  }

  if(buttonValue52 == HIGH){
    onColor(50, 66, 168,28);
    Serial.println(52);
    if(buttonBool52 == false){
      tone(A11, NOTE_F4, 1000);
      tone(A10, NOTE_F4, 1000);
      delay(100);
      buttonBool52 = true;
      noTone(A10);
      noTone(A11);
    }
  }else{
    offColor(168, 139, 50,28);
    buttonBool52 = false;
  }

  //if all are powered
  //Booleans for checking connection types 
  



  if(buttonValue4 == HIGH && buttonValue5 == HIGH && buttonValue7 == HIGH && buttonValue9 == HIGH && buttonValue10 == HIGH 
  && buttonValue11 == HIGH && buttonValue12 == HIGH && buttonValue13 == HIGH && buttonValue14 == HIGH && buttonValue15 == HIGH && buttonValue16 == HIGH
  && buttonValue17 == HIGH && buttonValue18 == HIGH && buttonValue19 == HIGH && buttonValue20 == HIGH && buttonValue21 == HIGH && buttonValue22 == HIGH
  && buttonValue24 ==  HIGH && buttonValue26 ==  HIGH && buttonValue28 ==  HIGH && buttonValue30 ==  HIGH && buttonValue32 ==  HIGH 
  && buttonValue34 ==  HIGH && buttonValue36 ==  HIGH && buttonValue38 ==  HIGH && buttonValue40 ==  HIGH && buttonValue42 ==  HIGH && 
  buttonValue44 ==  HIGH && buttonValue46 ==  HIGH && buttonValue48 ==  HIGH && buttonValue50 ==  HIGH && buttonValue52 ==  HIGH){

     
     row1 = true;
     row2 = true;
     row3 = true;
     row4 = true;
     row5 = true;
     row6 = true;
     row7 = true;
     row8 = true;
     column1 = true;
     column2 = true;
     column3 = true;
     column4 = true;
     colTrack1 = false;
     colTrack2 = false;
     colTrack3 = false;
     colTrack4 = false;
     rowTrack1 = false;
     rowTrack2 = false;
     rowTrack3 = false;
     rowTrack4 = false;
     rowTrack5 = false;
     rowTrack6 = false;
     rowTrack7 = false;
     rowTrack8 = false;                                                                       
     rainbow(20);
    
  }

  if(buttonValue52 == HIGH && buttonValue22 == LOW && buttonValue13 == HIGH && buttonValue20 == LOW && 
     buttonValue50 == LOW  && buttonValue24 == HIGH && buttonValue12 == LOW && buttonValue21 == HIGH &&
     buttonValue48 == HIGH && buttonValue26 == LOW && buttonValue11 == HIGH && buttonValue19 == LOW &&
     buttonValue46 == LOW && buttonValue28 == HIGH && buttonValue10 == LOW && buttonValue18 == HIGH &&
     buttonValue44 == HIGH && buttonValue30 == LOW && buttonValue9 == HIGH && buttonValue17 == LOW &&
     buttonValue42 == LOW && buttonValue34 == HIGH && buttonValue7 == LOW && buttonValue16 == HIGH &&
     buttonValue40 == HIGH && buttonValue36 == LOW && buttonValue5 == HIGH && buttonValue15 == LOW &&
     buttonValue38 == LOW && buttonValue32 == HIGH && buttonValue4 == LOW && buttonValue14 == HIGH){

      twinkle(242,0,185);
  }

  if(buttonValue52 == LOW && buttonValue22 == HIGH && buttonValue13 == LOW && buttonValue20 == HIGH && 
     buttonValue50 == HIGH  && buttonValue24 == LOW && buttonValue12 == HIGH && buttonValue21 == LOW &&
     buttonValue48 == LOW && buttonValue26 == HIGH && buttonValue11 == LOW && buttonValue19 == HIGH &&
     buttonValue46 == HIGH && buttonValue28 == LOW && buttonValue10 == HIGH && buttonValue18 == LOW &&
     buttonValue44 == LOW && buttonValue30 == HIGH && buttonValue9 == LOW && buttonValue17 == HIGH &&
     buttonValue42 == HIGH && buttonValue34 == LOW && buttonValue7 == HIGH && buttonValue16 == LOW &&
     buttonValue40 == LOW && buttonValue36 == HIGH && buttonValue5 == LOW && buttonValue15 == HIGH &&
     buttonValue38 == HIGH && buttonValue32 == LOW && buttonValue4 == HIGH && buttonValue14 == LOW){

      twinkle(242,69,0);
  }

  if(buttonValue52 == HIGH && buttonValue50 == HIGH && buttonValue48 == HIGH && buttonValue46 == HIGH && buttonValue44 == HIGH && 
    buttonValue42 == HIGH && buttonValue40 == HIGH && buttonValue38 == HIGH){
    if(column1 == false){
      pixels.setPixelColor(28, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(27, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(20, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(19, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(12, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(11, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(4, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(3, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
    }
    colTrack1 = true;
  }else{
    column1 = false;
    colTrack1 = false;
  }

  if(buttonValue22 == HIGH && buttonValue24 == HIGH && buttonValue26 == HIGH && buttonValue28 == HIGH && buttonValue30 == HIGH && 
    buttonValue34 == HIGH && buttonValue36 == HIGH && buttonValue32 == HIGH){
    if(column2 == false){
      pixels.setPixelColor(29, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(26, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(21, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(18, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(13, pixels.Color(193, 100, 2255));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(10, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(5, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(2, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
    }
     colTrack2 = true;
  }else{
    column2 = false;
    colTrack2 = false;
  }

  if(buttonValue13 == HIGH && buttonValue12 == HIGH && buttonValue11 == HIGH && buttonValue10 == HIGH && buttonValue9 == HIGH && 
    buttonValue7 == HIGH && buttonValue5 == HIGH && buttonValue4 == HIGH){
    if(column3 == false){
      pixels.setPixelColor(30, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(25, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(22, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(17, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(14, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(9, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(6, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(1, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
    }
    colTrack3 = true;
  }else{
    column3 = false;
    colTrack3 = false;
  }

  if(buttonValue20 == HIGH && buttonValue21 == HIGH && buttonValue19 == HIGH && buttonValue18 == HIGH && buttonValue17 == HIGH && 
    buttonValue16 == HIGH && buttonValue15 == HIGH && buttonValue14 == HIGH){
    if(column4 == false){
      pixels.setPixelColor(31, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(24, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(23, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(16, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(15, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(8, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(7, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
      pixels.setPixelColor(0, pixels.Color(193, 100, 255));
      pixels.show();
      delay(100);
    }
    colTrack4 = true;
  }else{
    column4 = false;
    colTrack4 = false;
  }

  if(buttonValue52 == HIGH && buttonValue22 == HIGH && buttonValue13 == HIGH && buttonValue20 == HIGH){
    if(row8 == false){
      pixels.setPixelColor(31, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(30, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(29, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(28, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      //row8 = true;
    }
    rowTrack8 = true;
  }else{
    row8 = false;
    rowTrack8 = false;
  }
  
  if(buttonValue50 == HIGH && buttonValue24 == HIGH && buttonValue12 == HIGH && buttonValue21 == HIGH){
    if(row7 == false){
      pixels.setPixelColor(27, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(26, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(25, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(24, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      //row7 = true;
    }
    rowTrack7 = true;
  }else{
    row7 = false;
    rowTrack7 = false;
  }
  
  if(buttonValue48 == HIGH && buttonValue26 == HIGH && buttonValue11 == HIGH && buttonValue19 == HIGH){
    if(row6 == false){
      pixels.setPixelColor(23, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(22, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(21, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(20, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
    }
      //row6 = true;
  rowTrack6 = true;
  }else{
    row6 = false;
    rowTrack6 = false;
  }
  
  if(buttonValue46 == HIGH && buttonValue28 == HIGH && buttonValue10 == HIGH && buttonValue18 == HIGH){
    if(row5 == false){
      pixels.setPixelColor(19, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(18, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(17, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(16, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      //row5 = true;
    }
    rowTrack5 = true;
  }else{
    row5 = false; 
    rowTrack5 = false; 
  }
  
  if(buttonValue44 == HIGH && buttonValue30 == HIGH && buttonValue9 == HIGH && buttonValue17 == HIGH){
    if(row4 == false){
      pixels.setPixelColor(15, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(14, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(13, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(12, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      //row4 = true;
    }
    rowTrack4 = true;
  }else{
    row4 = false;
    rowTrack4 = false;
  }
  if(buttonValue42 == HIGH && buttonValue34 == HIGH && buttonValue7 == HIGH && buttonValue16 == HIGH){
    if(row3 == false){
      pixels.setPixelColor(11, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(10, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(9, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(8, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      //row3 = true;
    }
    rowTrack3 = true;
  }else{
    row3 = false;
    rowTrack3 = false;
  }
  if(buttonValue40 == HIGH && buttonValue36 == HIGH && buttonValue5 == HIGH && buttonValue15 == HIGH){
    if(row2 == false){
      pixels.setPixelColor(7, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(6, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(5, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(4, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      //row2 = true;
    }
    rowTrack2 = true;
  }else{
    row2 = false;
    rowTrack2 = false;
  }
  if(buttonValue38 == HIGH && buttonValue32 == HIGH && buttonValue4 == HIGH && buttonValue14 == HIGH){

    if(row1 == false){
      pixels.setPixelColor(3, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100); 
      pixels.setPixelColor(2, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(1, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      pixels.setPixelColor(0, pixels.Color(255, 100, 200));
      pixels.show();
      delay(100);
      //row1 = true;
    }
    rowTrack1 = true;
  }else{
    row1 = false;
    rowTrack1 = false;
  }

  if(colTrack1 == true && colTrack3 == true){
    makePixelRun(100, 255, 113);
    colTrack1 = false;
    colTrack3 = false;
  }
  if(colTrack2 == true && colTrack4 == true){
    makePixelRun(0,255,20);
    colTrack2 = false;
    colTrack4 = false;
  }
  if(rowTrack1 == true && rowTrack3 == true && rowTrack5 == true && rowTrack7 == true){
    makePixelRun(234, 242,0);
    rowTrack1 = false;
    rowTrack3 = false;
    rowTrack5 = false;
    rowTrack7 = false;
  }
  if(rowTrack2 == true && rowTrack4 == true && rowTrack6 == true && rowTrack8 == true){
    makePixelRun(242,105,0);
    rowTrack2 = false;
    rowTrack4 = false;
    rowTrack6 = false;
    rowTrack8 = false;
  }
}// end loop


void offColor(int r,int g, int b, int index){
    pixels.setPixelColor(index, pixels.Color(r,g,b));
    pixels.show();
}

void onColor(int r, int g, int b, int index){
    pixels.setPixelColor(index, pixels.Color(r,g,b));
    pixels.show();
}

void twinkle(int r,int g,int b){
 
 int values[16];
 for(int i=0; i<16; i++){
  values[i] = random(0,31);
 }

 for(int i=0; i<16; i++){
  pixels.setPixelColor(values[i], pixels.Color(r,g,b));
  pixels.show();
  delay(200);
  pixels.setPixelColor(values[i], pixels.Color(0,0,0));
  pixels.show();
  delay(200);
  pixels.setPixelColor(values[i], pixels.Color(r,g,b));
  pixels.show();
  delay(200);
  pixels.setPixelColor(values[i], pixels.Color(0,0,0));
  pixels.show();
  delay(200);
  pixels.setPixelColor(values[i], pixels.Color(r,g,b));
  pixels.show();

 }

}                                                                                                                                                                                                                         

void snakeExplosion(int r, int g, int b){

  pixels.fill(66, 245, 170);
  
  // Update snake position
  snake_head_position += 1;
  if (snake_head_position >= 32) {
    snake_head_position = 0;
  }
  for (int i = snake_length - 1; i > 0; i--) {
    snake[i] = snake[i - 1];
  }
  snake[0] = snake_head_position;
  
  // Draw snake
  for (int i = 0; i < snake_length; i++) {
    pixels.setPixelColor(snake[i], r,g,b);
  }
  
  // Show updated frame
  pixels.show();
  
  // Delay to control animation speed
  delay(200);
  
}

void makePixelRun(int r, int g, int b){

  for(int i=0; i<32;i++){
    pixels.setPixelColor(i, r, g, b);
    delay(200);
    pixels.show();
    if(i>0){
      pixels.setPixelColor(i-1, 255, 255, 0);
      pixels.show();
    }
   
  }  
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<pixels.numPixels(); i++) {
      pixels.setPixelColor(i, Wheel((i+j) & 255));
    }
    pixels.show();
    delay(wait);
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(int WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
