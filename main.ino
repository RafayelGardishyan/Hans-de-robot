//#include <StaticThreadController.h>
//#include <Thread.h>
//#include <ThreadController.h>

// Import all necessary libraries

#include <SPI.h>
#include <Wire.h>
#include <light_sensor.h>
#include <mode.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DRV8835MotorShield.h>


// Define all needed names

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

DRV8835MotorShield motors;

//int ls_pins[4] = {A4, A5, 5, 6};
//LightSensorController lsc = LightSensorController(ls_pins);
LightSensor ls = LightSensor(A0);
LightSensor ls2 = LightSensor(A15);
LightSensor lsf = LightSensor(A1);
LightSensor lsf2 = LightSensor(A14);

//Thread lightSensorThread = Thread();  

void checkLightSensors(){
  Serial.println(lsf.GetValue(Mode::analog), DEC);
}

int speed1 = 50;
int speed2 = 50;

void setup()   { 
  /*
   * Setup function
   * Input:
   *   - None
   * Output:
   *   - None
   * Initialize all things and run some functions.
   * Will be ran at thw very beginning
   */
  // Flip motor 2
  motors.flipM2(true); 
  //  motors.setM1Speed(200);
  // Set speaker pin
  pinMode(2, OUTPUT);  

  //lsc.GetValue(0, Mode::analog);

  // Begin a serial port connection on 9600 frequency
  Serial.begin(9600);

  // Setup display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.display();
  display.clearDisplay();

  // Initialize threads for sensors
//  lightSensorThread.setInterval(10);
//  lightSensorThread.onRun(checkLightSensors); 
}


void loop() {
  motors.setM1Speed(speed1);
  motors.setM2Speed(speed2);
  // Play all songs
  playSongs();
}
