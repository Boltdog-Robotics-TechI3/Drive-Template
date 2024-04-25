#include "main.h"

// Controller Setup
extern pros::Controller driverController;

// Motor Initialization
extern pros::Motor frontLeftMotor;
extern pros::Motor middleLeftMotor;
extern pros::Motor backLeftMotor;

extern pros::Motor frontRightMotor;
extern pros::Motor middleRightMotor;
extern pros::Motor backRightMotor;

extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

// Sensor Initialization
extern pros::ADIAnalogIn lineTracker;
extern pros::ADIUltrasonic ultrasonic;

extern pros::IMU gyro;