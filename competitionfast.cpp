// Required proteus firmware libraries
#include <FEHUtility.h>
#include <FEHLCD.h>
#include <FEHSD.h>
#include <FEHIO.h>
#include <FEHServo.h>
#include <FEHMotor.h>
#include <FEHRPS.h>

// Required personal libraries
#include "include/constants.h"
#include "include/globals.h"
#include "include/functions.h"

#include <cmath>

void competitionFast(){

    //Place robot facing right wall on the 45 degree angle in the starting box

    //Initialize robot function and prep for run
    initRobot();

    robotStart();

    #pragma region //Drive out and up the ramp
    driveDistance(4.5, 40);

    stopDrive();

    turnLeftDegree(45);

    stopDrive();

    driveDistance(1, 35);
    driveDistance(4, 70);
    driveDistance(8, 35);
    driveDistance(22, 65);

    stopDrive();

    turnRightDegree(90);

    correctToWall();

    stopDrive();
    #pragma endregion

    #pragma region //Luggage

    driveDistance(1, -35);

    driveDistance(16.9, -80); //Drive to luggage area

    stopDrive();

    turnRightDegree(90);

    stopDrive();

    double luggageTime = TimeNow();
    while(TimeNow() - luggageTime <= 0.5) 
    {
        motorLeft.SetPercent(60);
        motorRight.SetPercent(60);
    }
    stopDrive();

    luggageSequence(); //Deposit luggage and ensure it is in right place

    #pragma endregion

    #pragma region//Buttons

    driveDistance(1, -55);

    turnRightDegree(5);

    driveDistance(17, -55);



    turnLeftDegree(30);

    RPStoLightTO(buttonX, buttonY);

   

    driveDistance(0.5, -25);
    
    int cdsColor = CDSColor(); //Gather the CDS color and store it.

    float currentHeading = 270 - RPS.Heading();

    if(currentHeading < -10)
    {

        turnRightDegree(RPS.Heading() - 270 - 5);
    }
    else if (currentHeading <= 10 && currentHeading >= -10)
    {

    }
    else if (currentHeading > 10)
    {
        turnLeftDegree(270 - RPS.Heading() - 5);
    }
    
    


    turnHeadingFast(270); //Turn facing north

    driveDistance(2, 45); // Back up to make room to maneuver

    turnLeftDegree(95); //Turn left and face passport

    //Determine where to drive based on what button needs pressed.
    if(cdsColor == CDS_BLUE) 
    {
        rpsAdjustX = calculateXDistance(16.5); 
    }
    else if (cdsColor == CDS_RED)
    {
        rpsAdjustX = calculateXDistance(22.25); 
    }
    else
    {
        rpsAdjustX = calculateXDistance(16.5);
    }

    driveDistance(rpsAdjustX, LOW_SPEED_PCT);

    stopDrive();

    turnLeftDegree(90);

    rpsAdjustY = calculateYDistance(58.5); 

    if(RPS.Y() > 60)
    {
    driveDistance(rpsAdjustY, 40);
    }

    double buttonTime = TimeNow();

    while(TimeNow() - buttonTime <= 0.5) 
    {
        motorLeft.SetPercent(60);
        motorRight.SetPercent(60);
    }

    stopDrive();

    LCD.Clear(BLACK);
    
    #pragma endregion

    #pragma region // Passport    

    servoPassport.SetDegree(140);

    rpsAdjustY = calculateYDistance(58.5); 

    if(rpsAdjustY < 7) 
    {  
        driveDistance(rpsAdjustY, -55);
    }
    else
    {
        driveDistance(4.5, -50);
    }
    

    stopDrive();

    turnLeftDegree(90);

    turnHeadingFast(180);

    rpsAdjustX = calculateXDistance(24); 

    stopDrive();

    driveDistance(rpsAdjustX, -55);

    stopDrive();

    passportSequenceFast();

    #pragma endregion

    #pragma region // Fuel Levers
   turnLeftDegree(55);

    stopDrive();

    turnHeadingFast(235);

    rpsAdjustX = calculateXDistance(5); //Need Actual coord to lever

    driveDistance(rpsAdjustX, 80);  //Distance needs changed

    stopDrive();

    turnRightDegree(55);

    turnHeadingFast(180);

    correctToWallTimeout();

    stopDrive();

    driveDistance(2.75,-LOW_SPEED_PCT);

    stopDrive();

    right90();

    servoCarrier.SetDegree(5);

    turnHeadingFast(90);

    rpsAdjustY = calculateYDistance(38);  

    driveDistance(rpsAdjustY, -70);

    stopDrive();

    driveDistance(14.5, -70); //need to adjust distance to get down ramp

    stopDrive();

    servoCarrier.SetDegree(CARRIER_ZERO_POSITION);

    turnLeftDegree(90);

    stopDrive();

    correctToWallTimeout();

    driveDistance(2.0, -35);

    stopDrive();

    if (correctLever==2)
    {   
        LCD.Clear(RED);
        turnLeftDegree(88);
        stopDrive();
    }
    else if (correctLever==1)
    {
        LCD.Clear(WHITE);
        driveDistance(3.3, -35);
        turnLeftDegree(88);
        stopDrive();
    }
    else if (correctLever==0)
    {
        LCD.Clear(BLUE);
        driveDistance(7.3, -35);
        stopDrive();
        turnLeftDegree(88);
        stopDrive();
    }
    else
    {
        LCD.Clear(ORANGE);
        turnLeftDegree(88);
        stopDrive();
    }

    stopDrive();

    turnHeadingFast(270);

    leverSequence();

    stopDrive();

    #pragma endregion

    #pragma region // Final Button


    turnLeftDegree(70);

    zeroCarrier();

    rpsAdjustX = calculateXDistance(16); 

    driveDistance(rpsAdjustX, 60);

    stopDrive();

    turnRightDegree(45);

    turnHeadingFast(315);


    motorLeft.SetPercent(90);

    motorRight.SetPercent(90);

    #pragma endregion
    
}