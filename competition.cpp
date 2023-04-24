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

void competition(){

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
    driveDistance(4, 60);
    driveDistance(8, 35);
    driveDistance(21, 60);

    stopDrive();

    turnRightDegree(90);

    correctToWall();

    stopDrive();
    #pragma endregion

    #pragma region //Luggage

    driveDistance(2, -35);

    driveDistance(15, -65); //Drive to luggage area

    stopDrive();

    right90();

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

    driveDistance(4, -60); //Drive backwards to prep for next task

    stopDrive();

    #pragma endregion

    #pragma region//Buttons

    #pragma region //Linefollowing to light 

    turnRightDegree(175); //Turn to face north

    findLine(); //Drive until robot hits line

    followToColor(); //Linefollow white until color is found

    
    int cdsColor = CDSColor(); //Gather the CDS color and store it.

    turnRightDegree(25);

    turnHeadingFast(90); //Turn facing north

    driveDistance(2, -LOW_SPEED_PCT); // Back up to make room to maneuver

    right90(); //Turn right and face passport

    #pragma endregion

    

    #pragma region //RPS to light 
    /*

     driveDistance(18, -55);

    turnLeftDegree(35);

    RPStoLight(buttonX, buttonY);

   

    driveDistance(0.5, -25);
    
    int cdsColor = CDSColor(); //Gather the CDS color and store it.

     float currentHeading = 270 - RPS.Heading();

    if(currentHeading < -10)
    {

        turnRightDegree(RPS.Heading() - 270);
    }
    else if (currentHeading <= 10 && currentHeading >= -10)
    {

    }
    else if (currentHeading > 10)
    {
        turnLeftDegree(270 - RPS.Heading());
    }
    
    


    turnHeadingFast(270); //Turn facing north

    driveDistance(2, 45); // Back up to make room to maneuver

    turnLeftDegree(90); //Turn left and face passport

    */

    #pragma endregion



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

    rpsAdjustY = calculateYDistance(58.5); 

    driveDistance(rpsAdjustY, 40);

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

    servoPassport.SetDegree(140);

    rpsAdjustY = calculateYDistance(58.5);

    if(rpsAdjustY < 7) 
    {  
        driveDistance(rpsAdjustY, -45);
    }
    else
    {
        driveDistance(4.5, -45);
    }

    stopDrive();

    left90();

    turnHeadingFast(180);

    rpsAdjustX = calculateXDistance(24); 

    stopDrive();

    driveDistance(rpsAdjustX, -45);

    stopDrive();

    passportSequenceFast();

    #pragma endregion

    #pragma region // Fuel Levers
    turnLeftDegree(55);

    stopDrive();

    turnHeadingFast(235);

    rpsAdjustX = calculateXDistance(4); //Need Actual coord to lever

    driveDistance(rpsAdjustX, 70);  //Distance needs changed

    stopDrive();

    turnRightDegree(55);

    turnHeadingFast(180);

    correctToWallTimeout();

    stopDrive();

    driveDistance(2.75,-LOW_SPEED_PCT);

    stopDrive();

    servoCarrier.SetDegree(5);

    right90();

    turnHeadingFast(90);


    rpsAdjustY = calculateYDistance(38);  ////Need Coord at top of ramp

    driveDistance(rpsAdjustY, -50);

    stopDrive();

    driveDistance(14.5, -50); //need to adjust distance to get down ramp

    stopDrive();

    servoCarrier.SetDegree(CARRIER_ZERO_POSITION);

    left90();

    turnHeadingFast(180);

    stopDrive();

    correctToWallTimeout();

    driveDistance(2.0, -LOW_SPEED_PCT);

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
        driveDistance(3.3, -LOW_SPEED_PCT);
        turnLeftDegree(88);
        stopDrive();
    }
    else if (correctLever==0)
    {
        LCD.Clear(BLUE);
        driveDistance(7.3, -LOW_SPEED_PCT);
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


    turnLeftDegree(75);

    zeroCarrier();

    rpsAdjustX = calculateXDistance(16); 

    driveDistance(rpsAdjustX, MEDIUM_SPEED_PCT);

    stopDrive();

    turnRightDegree(45);

    turnHeadingFast(315);
    
    driveDistance(2, 35);

    int endTimeout = TimeNow();

    while(TimeNow() - endTimeout < 5)
    {
    motorLeft.SetPercent(70);
    motorRight.SetPercent(70);
    }
    stopDrive();

    driveDistance(-4, LOW_SPEED_PCT);
    turnRightDegree(10);

    motorLeft.SetPercent(50);
    motorRight.SetPercent(50);


    #pragma endregion
    
}