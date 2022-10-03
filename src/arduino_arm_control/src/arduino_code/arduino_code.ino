#include <Servo.h>

Servo servo9;
Servo servo10;
Servo servo11;

#define HOME_ANGLE 90
#define JOINT_VEL_FAST 60
#define JOINT_VEL_SLOW 30

bool servos_moving = 0;
char fb_s9[]= "AAA";
char fb_s10[]= "AAA";
char fb_s11[] = "AAA";


// LUT of char representation of numbers
const char nr_LUT[10] = {'0', '1', '2',
                         '3', '4', '5',
                         '6', '7', '8', '9'};

void setup()
{
  Serial.begin(115200);
  servo9.attach(9);
  servo10.attach(10);
  servo11.attach(11);
}

void parseToString(char *input, int number)
{
  // FILL WITH ZEROS
  // PARSE INT TO STRING
  if (input < 100)
  {
    input[0] = nr_LUT[0];
    input[1] = nr_LUT[number / 10];
    input[2] = nr_LUT[number % 10];
  }
  else
  {
    input[0] = nr_LUT[number / 100];
    input[1] = nr_LUT[number / 10 % 10];
    input[2] = nr_LUT[number % 10];
  }
}

void startEaseToAllServos(String string_cmd)
{
  long angle11 = string_cmd.substring(0, 4).toInt();
  long angle10 = string_cmd.substring(4, 8).toInt();
  long angle9 = string_cmd.substring(8, 12).toInt();

  servo9.write(angle9);
  servo10.write(angle10);
  servo11.write(angle11);
}

void fb_positions()
{
  // GIVE ANGLE FEEDBACK
    uint8_t fb9 = servo9.read();
    uint8_t fb10 = servo10.read();
    uint8_t fb11 = servo11.read();
        
    parseToString(fb_s9, fb9);
    parseToString(fb_s10, fb10);
    parseToString(fb_s11, fb11);

    char result[12];
    sprintf(result, "%s,%s,%s\n", fb_s9, fb_s10 , fb_s11 );
    Serial.write(result);
}

String inputString;
String out = String();
char inChar;

void loop()
{
  if (Serial.available() > 11)
  {
      inChar = Serial.read();
      if (inChar == '<')
      {
        inputString = Serial.readStringUntil('>');
        startEaseToAllServos(inputString);
      } 
      fb_positions();
     
  } 
}
