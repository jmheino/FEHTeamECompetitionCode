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

void competitiondiforder(){

    //Place robot facing right wall on the 45 degree angle in the starting box

    //Initialize robot function and prep for run
    initRobot();

    robotStart();

    #pragma region //Drive out and up the ramp
    driveDistance(4, 40);

    stopDrive();

    turnLeftDegree(45);

    stopDrive();

    driveDistance(1, 35);
    driveDistance(4, 70);
    driveDistance(8, 35);
    driveDistance(21, 70);

    stopDrive();

    turnRightDegree(90);

    correctToWall();

    stopDrive();
    #pragma endregion

   

    #pragma region//Buttons


    driveDistance(4, -45);

    turnRightDegree(45);

    driveDistance(25, -60);

    RPStoLight(buttonX, buttonY);

    driveDistance(0.5, -35);
    
    int cdsColor = CDSColor(); //Gather the CDS color and store it.

    turnHeadingFast(270);

    driveDistance(2, LOW_SPEED_PCT); // Back up to make room to maneuver

    left90(); //Turn left and face passport

    //Determine where to drive based on what button needs pressed.
    if(cdsColor == CDS_BLUE) 
    {
        rpsAdjustX = calculateXDistance(16); 
    }
    else if (cdsColor == CDS_RED)
    {
        rpsAdjustX = calculateXDistance(22); 
    }
    else
    {
        rpsAdjustX = calculateXDistance(16);
    }

    driveDistance(rpsAdjustX, LOW_SPEED_PCT);

    stopDrive();

    left90();

    double buttonTime = TimeNow();

    while(TimeNow() - buttonTime <= 0.75) 
    {
        motorLeft.SetPercent(40);
        motorRight.SetPercent(40);
    }

    stopDrive();

    LCD.Clear(BLACK);
    
    #pragma endregion

    #pragma region // Passport    

    servoPassport.SetDegree(135);

    rpsAdjustY = calculateYDistance(58.5); 

    driveDistance(rpsAdjustY, -30);

    stopDrive();

    left90();

    turnHeadingFast(180);

    rpsAdjustX = calculateXDistance(24); 

    stopDrive();

    driveDistance(rpsAdjustX, -60);

    stopDrive();

    passportSequenceFastFast();

    #pragma endregion

    #pragma region //Luggage

    RPStoRamp(luggageX, luggageY); //This is not actually ramp but luggage

    turnLeftDegree(35);

    turnHeadingFast(270);

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


    #pragma region // Fuel Levers

    driveDistance(2, -60);

    turnRightDegree(90);

    driveDistance(5, 60);

    correctToWallTimeout();

    stopDrive();

    driveDistance(2.75,-LOW_SPEED_PCT);

    stopDrive();

    servoCarrier.SetDegree(5);

    turnRightDegree(90);

    turnHeadingFast(90);

    rpsAdjustY = calculateYDistance(38);  

    driveDistance(rpsAdjustY, -45);

    stopDrive();

    driveDistance(14.5, -45); //need to adjust distance to get down ramp

    stopDrive();

    servoCarrier.SetDegree(CARRIER_ZERO_POSITION);

    left90();

    turnHeadingFast(180);

    stopDrive();

    correctToWallTimeout();

    driveDistance(2.3, -LOW_SPEED_PCT);

    stopDrive();

    if (correctLever==2)
    {   
        LCD.Clear(RED);
        left90();
        stopDrive();
    }
    else if (correctLever==1)
    {
        LCD.Clear(WHITE);
        driveDistance(3.3, -LOW_SPEED_PCT);
        left90();
        stopDrive();
    }
    else if (correctLever==0)
    {
        LCD.Clear(BLUE);
        driveDistance(6.9, -LOW_SPEED_PCT);
        stopDrive();
        left90();
        stopDrive();
    }
    else
    {
        LCD.Clear(ORANGE);
        left90();
        stopDrive();
    }

    stopDrive();

    turnHeadingFast(270);

    leverSequence();

    stopDrive();

    #pragma endregion

    #pragma region // Final Button


    left90();

    zeroCarrier();

    rpsAdjustX = calculateXDistance(16); 

    driveDistance(rpsAdjustX, MEDIUM_SPEED_PCT);

    stopDrive();

    turnRightDegree(45);

    turnHeadingFast(315);

    
    
    while (TimeNow() - endTime < 4.2);

    motorLeft.SetPercent(70);

    motorRight.SetPercent(70);

    #pragma endregion
    
}