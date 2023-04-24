#pragma region

#include <FEHLCD.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHRPS.h>
//Include Libraries Here
#include "include/constants.h"
#include "include/functions.h"
#include "include/globals.h"


int main(void)
{

   int state = 0;

   while(1)
   {
     if (state == 0) //Menu
        {
            state = menu();   
        }
        else if (state == 1) // Slow
        {
            competition();
        }
        else if (state == 2) // Fast
        {
            competitionFast();
        }
        else if(state ==3)
        {

            rpsAdjustY = 25;
             if(rpsAdjustY < 7) 
    {  
        driveDistance(rpsAdjustY, -55);
        stopDrive();
    }
    else
    {
        driveDistance(4.5, -25);
        stopDrive();
    }
    state = 0;
        }
        else if(state == 4) //Instructions
        {
            //test();

            
            state = 0;
        }
   }
}

