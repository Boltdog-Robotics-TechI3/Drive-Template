#include "main.h"

// Controller Setup
pros::Controller driverController(pros::E_CONTROLLER_MASTER);


// Motor Initialization

// Drivetrain
pros::Motor frontRightMotor(18, pros::v5::MotorGears::green, pros::v5::MotorUnits::rotations);
pros::Motor middleRightMotor(19, pros::v5::MotorGears::green, pros::v5::MotorUnits::rotations);
pros::Motor backRightMotor(20, pros::v5::MotorGears::green, pros::v5::MotorUnits::rotations);

pros::Motor frontLeftMotor(11, pros::v5::MotorGears::green, pros::v5::MotorUnits::rotations);
pros::Motor middleLeftMotor(12, pros::v5::MotorGears::green, pros::v5::MotorUnits::rotations);
pros::Motor backLeftMotor(13, pros::v5::MotorGears::green, pros::v5::MotorUnits::rotations);

pros::MotorGroup leftDrive({18, 19, 20});
pros::MotorGroup rightDrive({11, 12, 13});

// Catapult
// pros::Motor catapult(18, MOTOR_GEAR_GREEN, false, MOTOR_ENCODER_COUNTS);

// Wings

// Sensor Initialization
pros::IMU gyro(8);