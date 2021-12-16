/*-----------------------------------------------------------------------------------------------------
  ----------------------------------------------------------------------------------------------------
  ---------------------------------------------------------------------------------------------------

            _____   ____   _____ ____ ____  __  ___
           |  __ \ / __ \ / ____/ __ \___ \/_ |/ _ \
           | |__) | |  | | |   | |  | |__) || | (_) |
           |  _  /| |  | | |   | |  | |__ < | |> _ <
           | | \ \| |__| | |___| |__| |__) || | (_) |
           |_|  \_\\____/ \_____\____/____/ |_|\___/
                    SIMPLE SERVO CONTROLLER

  This is some super simple code for controlling servos via id and angle values.
  This has been made for the Arduino Nano with a PCA9685 16 channel i2c PWM breakout board.

                         -:Wiring:-
                ARDUINO NANO --->    PCA9685
                     A5      --->      SCL
                     A4      --->      SDA
                    GND      --->      GND
                     5V      --->      VCC

  THIS CODE UTILISES THE ADAFRUIT PWM SERVO DRIVER LIBRARY, TO ADD IT TO YOUR ARDUINO IDE:
  - Click on; Sketch
  - Click on; Include Library
  - Click on; Manage Libraries...
  - In the search bar that appears, type in "Adafruit PWM Servo Driver" and click install on the one that appears with the same name.
  Now you have the neccessary libraries to run the following code.

                     -:USING THE CODE:-
                      ----------------
  When uploaded you can then send simple commands to the board to control your servos.
  It must be in the following format:
    ServoNumber,ServoAngle

    So for example:

    UpdateServo(6, 90);

    This will move servo number 6 to an angle of 90 degrees.

  That is everything you need to know to use the board

  Debugging:

  If you send your servo an angle value and it does not line up, then you may need to calibrate the servo minimum and maximum pulse lengths
  Currently they have been calibrated for a range of 0 to 180 degrees for the Towerpro MG996R
  #define SERVOMIN  135 // This is the 'minimum' pulse length count (out of 4096) For the MG996R this wants to be 135
  #define SERVOMAX  482 // this is the 'maximum' pulse length count (out of 4096) For the MG996R this wants to be 482

  ------------------------------------------------------------------------------------------------
  -------------------------------------------------------------------------------------------------
*/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define SERVOMIN  135 // This is the 'minimum' pulse length count (out of 4096) For the MG996R this wants to be 135
#define SERVOMAX  482 // this is the 'maximum' pulse length count (out of 4096) For the MG996R this wants to be 482

Adafruit_PWMServoDriver PCA9685 = Adafruit_PWMServoDriver();

int ServoPositions[16][5]; //you can use this to make a 2D array of values for your 16 servos positions for each point of your walking gait

//----------------------------------------------------------------------------//
void setup() {
  Serial.begin(115200); //Nice faster speed
  PCA9685.begin();
  PCA9685.setPWMFreq(50); //Maximum speed this can be set to is 1600
  Wire.setClock(400000); // Fast 400khz I2C Mode
  Serial.println("PCA9685 Servo Controller Connected & Ready");
}


/*----------------------------------------------------------------------------
   __  __          _____ _   _
  |  \/  |   /\   |_   _| \ | |
  | \  / |  /  \    | | |  \| |
  | |\/| | / /\ \   | | | . ` |
  | |  | |/ ____ \ _| |_| |\  |
  |_|  |_/_/    \_\_____|_| \_|
  ----------------------------------------------------------------------------*/
  
void loop( ) {

  UpdateServo(0, 90);          //N/A
  UpdateServo(1, 90);          //FR Knee
  UpdateServo(2, 90);          //FR Thigh
  UpdateServo(3, 93);          //FR Hip
  UpdateServo(4, 90);          //N/A
  UpdateServo(5, 90);          //BR Knee
  UpdateServo(6, 90);          //BR Thigh
  UpdateServo(7, 90);          //BR Hip
  UpdateServo(8, 90);          //N/A
  UpdateServo(9, 90);          //BL Knee
  UpdateServo(10, 90);         //BL Thigh
  UpdateServo(11, 100);         //BL Hip
  UpdateServo(12, 90);         //N/A
  UpdateServo(13, 90);         //FL Knee
  UpdateServo(14, 90);         //FL Thigh
  UpdateServo(15, 85);         //FL Hip

delay(4000);

for (int x = 0; x < 15; x++) {

/////////////////////////Front Left Step///////////////////////////////////////

delay(800);

 UpdateServo(6, 130);          //BR thigh
 UpdateServo(5, 55);          //BR Knee
 
 UpdateServo(10,65);          //BL thigh
 UpdateServo(9, 100);          //BL Knee 

 UpdateServo(1, 105);          //FR Knee

 delay(50);

   UpdateServo(13, 20);          //FL Knee  

delay(50);
 UpdateServo(14, 0);          //FL Thigh



delay(100);
 UpdateServo(13, 145);          //FL Knee
 UpdateServo(15, 70);         //FL Hip

 delay(100);
 UpdateServo(14, 50);          //FL Thigh
   
 delay(50);
 UpdateServo(1, 105);          //FR Knee
 UpdateServo(6, 80);          //BR thigh
 UpdateServo(10,100);          //BL thigh
  UpdateServo(9, 90);          //BL Knee 
   UpdateServo(5, 90);          //BR Knee
  



////////////////////////Front Right Step/////////////////////////////////////////

delay(800);

  UpdateServo(7, 100);          //BR Hip

  delay(50);
 UpdateServo(6, 110);          //BR thigh
 UpdateServo(5, 75);          //BR Knee
 
 UpdateServo(10,70);          //BL thigh
 UpdateServo(9, 100);          //BL Knee 
 
delay(50);

   UpdateServo(13, 150);        //FL Knee 
   
delay(50);

 UpdateServo(1, 180);          //FR Knee

delay(50);
 UpdateServo(2, 180);          //FR Thigh
 UpdateServo(3, 110);          //FR Hip

delay(50);
 UpdateServo(1,35);          //FR Knee
 delay(50);
 
  UpdateServo(7, 90);          //BR Hip
 UpdateServo(2, 130);          //FR Thigh
  UpdateServo(14, 40);          //FL Thigh


delay(200);


 UpdateServo(10, 150);          //BL Thigh
 UpdateServo(6, 30);          //BR Thigh

 UpdateServo(5, 150);         //BR Knee
 UpdateServo(9, 30);          //BL Knee

  

////////////////////////////Back Left Step//////////////////////////////////////////////

delay(800);
 UpdateServo(14, 70);          //FL Thigh
 UpdateServo(2, 110);          //FR Thigh
  
 UpdateServo(13, 100);          //FL Knee 
 UpdateServo(1,80);          //FR Knee
   
 UpdateServo(7, 70);          //BR Hip

      
delay(100);
 UpdateServo(9, 180);          //BL Knee

delay(100);
 UpdateServo(10, 0);          //BL Thigh

delay(300);
 UpdateServo(9, 140);          //BL Knee

delay(100);  
 UpdateServo(14, 80);          //FL Thigh
 UpdateServo(2, 100);          //FR Thigh
  
 UpdateServo(10, 60);          //BL Thigh
 UpdateServo(7, 90);          //BR Hip

 UpdateServo(9, 120);          //BL Knee




////////////////////////////Back Right Step//////////////////////////////////////////////

delay(800);


 UpdateServo(13,50);          //FL Knee 
 UpdateServo(1,120);          //FR Knee


delay(200); 
 UpdateServo(5, 0);         //BR Knee   
 UpdateServo(7, 120);         //BR Hip


delay(100);    
 UpdateServo(6, 140);        //BR Thigh 
 
delay(100); 
 UpdateServo(7, 90);        //BR Hip 
delay(100); 
 UpdateServo(5, 80);        //BR Knee 
 
delay(400); 
 UpdateServo(6,108);       //BR Thigh 

 delay(100);
UpdateServo(11, 100);         //BL Hip  
UpdateServo(3, 93);          //FR Hip
UpdateServo(15, 80);         //FL Hip
 
delay(100);

 UpdateServo(13,90);          //FL Knee 
 UpdateServo(1,90);          //FR Knee
 UpdateServo(9, 90);          //BL Knee
 UpdateServo(5, 90);         //BR Knee 
delay(100);

 UpdateServo(14, 100);          //FL Thigh
 UpdateServo(2, 90);          //FR Thigh
  UpdateServo(6,90);       //BR Thigh 
   UpdateServo(10, 90);          //BL Thigh

}
delay(1000000);
}
//End of Main
//----------------------------------------------------------------------------//






/*----------------------------------------------------------------------------
   ______ _    _ _   _  _____ _______ _____ ____  _   _  _____
  |  ____| |  | | \ | |/ ____|__   __|_   _/ __ \| \ | |/ ____|
  | |__  | |  | |  \| | |       | |    | || |  | |  \| | (___
  |  __| | |  | | . ` | |       | |    | || |  | | . ` |\___ \
  | |    | |__| | |\  | |____   | |   _| || |__| | |\  |____) |
  |_|     \____/|_| \_|\_____|  |_|  |_____\____/|_| \_|_____/
  ----------------------------------------------------------------------------*/
void UpdateServo (int Id, int Angle) {

  double pulselength = map(Angle, 0, 180, SERVOMIN, SERVOMAX); //map the degree value to pulselength value
  PCA9685.setPWM(Id, 0, pulselength); //Send the angle to the appropiate servo

}
