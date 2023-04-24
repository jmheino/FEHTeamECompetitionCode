#ifndef CONSTANTS_H
#define CONSTANTS_H

#define PI 3.14159265358979

#define MOTOR_PORT_L FEHMotor::Motor0
#define MOTOR_PORT_R FEHMotor::Motor1
#define MOTOR_VOLTS 9.0 

#define MOTOR_SIDE_DIR_CORRECTOR -1


//Servo
#define SERVO_PORT_PASSPORT FEHServo::Servo0
#define SERVO_PORT_CARRIER FEHServo::Servo1
#define L_MICROSWITCH_PORT FEHIO::P3_7
#define R_MICROSWITCH_PORT FEHIO::P0_2
#define L_OPTO_PORT FEHIO::P2_3
#define M_OPTO_PORT FEHIO::P2_0
#define R_OPTO_PORT FEHIO::P1_6


// Ports
#define CDS_CELL_PORT FEHIO::P1_0
#define ENCODER_LEFT_PORT FEHIO::P3_0
#define ENCODER_RIGHT_PORT FEHIO::P0_0

//Colors
#define CDS_RED_NO_FILTER 0.15
#define CDS_BLUE_NO_FILTER 0.35 //NO VALUE
#define CDS_OFF_NO_FILTER 2.36 
#define CDS_RED_RED_FILTER 0.185
#define CDS_BLUE_RED_FILTER 0.510
#define CDS_OFF_RED_FILTER 2.96
#define CDS_THRESHOLD 0.15

//Drive PID Values
#define DRIVE_kP 0.75//0.75
#define DRIVE_kI 0.1//0.1
#define DRIVE_kD 0.25//0.25

//Encoder constants
#define ENCODER_COUNTS 318


//Motor Speed Percent
#define TURN_PERCENT 50
#define VERY_LOW_SPEED_PCT 20
#define LOW_SPEED_PCT 35
#define MEDIUM_SPEED_PCT 50
#define HIGH_SPEED_PCT 75

//Motor linear speeds
#define LOW_SPEED_IN_PER_SEC 5
#define MEDIUM_SPEED_IN_PER_SEC 10
#define HIGH_SPEED_IN_PER_SEC 20

//Calculations for distance (all in inches)
#define WHEEL_DIAM 2.5
#define WHEEL_CIRC (WHEEL_DIAM * PI)
#define COUNTS_PER_INCH (ENCODER_COUNTS/WHEEL_CIRC)
#define INCHES_PER_COUNT (WHEEL_CIRC/ENCODER_COUNTS)
#define COUNTS_PER_360 890.4
#define COUNTS_PER_90 222.6
#define COUNTS_PER_DEGREE (COUNTS_PER_360/360)

//Time delay
#define DELAY 100

//Motor Values
#define FULL_POWER_RPM
#define IN_PER_SEC (FULL_POWER_RPM * WHEEL_CIRC * 60)

//Pulse
#define PULSE_DELAY 0.075
#define PULSE_POWER 15

//RPS
#define HEADING_TOLERANCE 1
#define BIG_HEADING_TOLERANCE 2

//Caculations
#define RADIANS_TO_DEGREES (180/PI)

//Coordinates
#define LIGHT_X_COORD 20
#define LIGHT_Y_COORD 20

//Color
#define CDS_NO_LIGHT 0
#define CDS_RED 1
#define CDS_BLUE 2


//Line follower values
#define LEFT_OPTO_WHITE_LINE_VALUE 1.2
#define MIDDLE_OPTO_WHITE_LINE_VALUE 1.113
#define RIGHT_OPTO_WHITE_LINE_VALUE 0.383
#define OPTO_THRESHOLD 0.4
#define LEFT_HIGHER_THRESHOLD (LEFT_OPTO_WHITE_LINE_VALUE + OPTO_THRESHOLD)
#define LEFT_LOWER_THRESHOLD (LEFT_OPTO_WHITE_LINE_VALUE - OPTO_THRESHOLD)
#define MIDDLE_HIGHER_THRESHOLD (MIDDLE_OPTO_WHITE_LINE_VALUE + OPTO_THRESHOLD)
#define MIDDLE_LOWER_THRESHOLD (MIDDLE_OPTO_WHITE_LINE_VALUE - OPTO_THRESHOLD)
#define RIGHT_HIGHER_THRESHOLD (RIGHT_OPTO_WHITE_LINE_VALUE + OPTO_THRESHOLD)
#define RIGHT_LOWER_THRESHOLD (RIGHT_OPTO_WHITE_LINE_VALUE - OPTO_THRESHOLD)
#define BACKGROUND_OPTO_VALUE 2.0

//Servo Values
#define PASSPORT_SERVO_MIN 508
#define PASSPORT_SERVO_MAX 2412
#define CARRIER_SERVO_MIN 580
#define CARRIER_SERVO_MAX 2245
#define CARRIER_ZERO_POSITION 150
#define CARRIER_LEVER_DOWN_ANGLE 15
#define CARRIER_LEVER_UP_ANGLE 35
#define SET_TO_FLIP_LEVER_DOWN 40
#define SET_TO_FLIP_LEVER_UP 10
#define PASSPORT_ZERO_POSITION 25
#define PASSPORT_LEVER_UP 0
#define PASSPORT_LEVER_DOWN 115
#define PASSPORT_LEVER_UP_PREP 180
#define PASSPORT_LEVER_DOWN_PREP 0
#define CARRIER_LUGGAGE_DROP 35
#define CARRIER_LUGGAGE_CHECK 45

#endif