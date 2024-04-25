#include "main.h"
#include <iostream>
using namespace std;



// Code to be run upon initialization
void drivetrainInitialize(){
	// setting motor brake modes
	frontLeftMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
    middleLeftMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
    backLeftMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);

	frontRightMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
    middleRightMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);
	backRightMotor.set_brake_mode(MOTOR_BRAKE_BRAKE);

    frontLeftMotor.set_reversed(false);
    middleLeftMotor.set_reversed(false);
    backLeftMotor.set_reversed(false);

    frontRightMotor.set_reversed(false);
    middleRightMotor.set_reversed(false);
    backRightMotor.set_reversed(false);
}

// Code to be run repeatedly in OpControl
void drivetrainPeriodic() {
    drive();
}

// User Drive Function
void drive() {
    double y1 = (driverController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
    double x2 = (driverController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));

    arcadeDrive(x2, y1);


    pros::lcd::set_text(6, "Heading:" + to_string(gyro.get_heading()));

}

//bad
void tankDrive(int left, int right) {
    //brings any numbers out side of range into range
    // left = max(-127, min(127, left));
    // right = max(-127, min(127, right));
    //sets motor speeds
    leftDrive.move(left);
    rightDrive.move(right);
}

//good
void arcadeDrive(int moveValue, int rotateValue) {
    //mixes the numbers
    int leftMotorSpeed = moveValue - rotateValue;
    int rightMotorSpeed = moveValue + rotateValue;
    //determines which is higher
    int mx = max(abs(leftMotorSpeed), abs(rightMotorSpeed));
    //scales both sides evenly based on if max > 127
    if (mx > 127) {
        leftMotorSpeed = (leftMotorSpeed / mx) * 127;
        rightMotorSpeed = (rightMotorSpeed / mx) * 127;
    }
    tankDrive(leftMotorSpeed, rightMotorSpeed);
}



// AUTO METHODS //

// Move x distance using PROS built-in movement methods
void moveDistance(int distance, int speed) {
    double targetDistanceLeft = frontLeftMotor.get_position() + distance;
    double targetDistanceRight = frontRightMotor.get_position() + distance;

    // leftDrive.move_absolute(targetDistanceLeft, speed);
    // rightDrive.move_absolute(targetDistanceRight, speed);

    leftDrive.move_relative(distance, speed);
    rightDrive.move_relative(distance, speed);

    while (abs(abs(targetDistanceLeft) - abs(frontLeftMotor.get_position())) > 20) {
    }
	
    leftDrive.move_relative(0, speed);
    rightDrive.move_relative(0, speed);
    pros::delay(200);
}

// rotate to face a certain angle using a p controller and the gyro
void rotateToHeadingGyro(double angle) {
    double kP = 1.75;

    double error = angle - gyro.get_heading();

    while (abs(error) > .5) {
		int motorVal = error * kP;
		leftDrive.move(motorVal);
		rightDrive.move(-motorVal);
	    error = angle - gyro.get_heading();
	}

    leftDrive.move(0);
	rightDrive.move(0);
}

