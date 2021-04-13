#include <FastLED.h>

#define LED_PIN 5 
#define NUM_LEDS 60

int joy_button_pin = 7;

int reset_random_number = HIGH;

CRGB leds[NUM_LEDS];

int points = 0;

int speed_of_movment = 500;

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  pinMode(joy_button_pin, INPUT_PULLUP);
  Serial.begin(9600);
}

//void loop()
//{
// // FastLED.clear();
// // FastLED.show();
//                fill_solid( leds, NUM_LEDS, CRGB ( 255, 255, 255)); // green
//        FastLED.show();
//        delay(800);
//        fill_solid( leds, NUM_LEDS, CRGB ( 0, 255, 0)); // green
//        FastLED.show();
//        delay(100);
//        fill_solid( leds, NUM_LEDS, CRGB ( 255, 0, 0));
//        FastLED.show();
//        delay(100);
//        fill_solid( leds, NUM_LEDS, CRGB ( 0, 0, 255));
//        FastLED.show();
//        delay(100);
//}
void loop() {
  int random_led;
  FastLED.clear();
  FastLED.show();
  random_led = random(59);
  int random_led_y_1 = random_led - 1;
  int random_led_y_2 = random_led + 1;
  leds[random_led] = CRGB ( 255, 0, 0); // RED
  leds[random_led_y_1] = CRGB ( 255, 255, 0); // Yellow
  leds[random_led_y_2] = CRGB ( 255, 255, 0); // Yellow
  for (int i = 0; i <= 59; i++) {
    leds[i] = CRGB ( 0, 0, 255); // Blue
    FastLED.show();
    delay(speed_of_movment);
    leds[i] = CRGB ( 0, 0, 0);
    FastLED.show();
    //delay(speed_of_movment);
    Serial.print("*****************button********************:");
    Serial.println(digitalRead(joy_button_pin));
    Serial.print("*************index************************:");
    Serial.println(i);
    Serial.print("*************RED************************:");
    Serial.println(random_led);
    if (digitalRead(joy_button_pin) == 0 )
    {
      if (i == random_led)
      {
        leds[i] = CRGB ( 0, 150, 0); //light green
        FastLED.show();
        delay(1000);
        fill_solid( leds, NUM_LEDS, CRGB ( 0, 255, 0)); // green
        FastLED.show();
        delay(1000);
        fill_solid( leds, NUM_LEDS, CRGB ( 0, 0, 0));
        FastLED.show();
        points++;
        speed_of_movment = speed_of_movment / 3;
        FastLED.clear();
        FastLED.show();
        break;
      }
      else
      {
        leds[i] = CRGB ( 150, 0, 0); //light green
        FastLED.show();
        delay(1000);
        fill_solid( leds, NUM_LEDS, CRGB ( 255, 0, 0)); // red
        FastLED.show();
        delay(1000);
        //fill_solid( leds, NUM_LEDS, CRGB ( 0, 0, 0));
        FastLED.clear();
        FastLED.show();

        

        break;
      }
    }

    if (i == random_led_y_1)
    {
      leds[random_led_y_1] = CRGB ( 255, 255, 0);
    }
    if (i == random_led)
    {
      leds[random_led] = CRGB ( 255, 0, 0);
    }
    if (i == random_led_y_2)
    {
      leds[random_led_y_2] = CRGB ( 255, 255, 0); 
    }

    //    if (i == 59)
    //    {
    //      leds[random_led_y_1] = CRGB ( 255, 255, 0);
    //      FastLED.clear();
    //      leds[random_led] = CRGB ( 255, 0, 0);
    //      FastLED.clear();
    //      leds[random_led_y_2] = CRGB ( 255, 255, 0);
    //      FastLED.clear();
    //      if (digitalRead(joy_button_pin = HIGH))
    //      {
    //        if (i == random_led)
    //        {
    //          leds[random_led] = CRGB ( 255, 0, 0);
    //          FastLED.clear();
    //          points++;
    //          speed_of_movment = speed_of_movment / 3;
    //        }
    //      }
    //    }
  }
}
