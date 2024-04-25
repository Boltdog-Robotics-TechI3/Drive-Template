#include "main.h"
#include <iostream>
#include "cmath"
using namespace std;


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "Skills Run" and "Match Auton" If the robot is selected for match auton, qualififaction rounds is defaultly selected
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;

	if (pressed) {

	} else {

	}
}

/**
 * A callback function for LLEMU's right button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "Elimination rounds auton selected" and "Qualification rounds auton selected"
 */

void on_right_button() {
	static bool pressed = false;
	pressed = !pressed;

	if (pressed) {

	} else {

	}
}

/**
 * A callback function for LLEMU's right button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "Elimination rounds auton selected" and "Qualification rounds auton selected"
 */

void on_left_button() {
	static bool pressed = false;
	pressed = !pressed;

	if (pressed) {

	} else {

	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "TECHI3 Ruff and Ready");

	// activating v5 buttons
	pros::lcd::register_btn1_cb(on_center_button);
	// pros::lcd::register_btn0_cb(on_right_button);
	// pros::lcd::register_btn2_cb(on_left_button);


	drivetrainInitialize();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	// calibrate gyro
	gyro.reset();
	gyro.set_heading(0);
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	pros::lcd::set_text(1, "TECHI3 Ruff and Ready");
	gyro.reset();
	gyro.set_heading(0);
	pros::lcd::register_btn1_cb(on_center_button);
	// pros::lcd::register_btn0_cb(on_right_button);
	// pros::lcd::register_btn2_cb(on_left_button);
	drivetrainInitialize();
	}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	// if (elim == true) {

	// 	score2TriBalls();
	// 	finalPartElims();

	// } else if (qual == true) {
	// rotateToHeadingGyro(90);
		// score2TriBalls();
		// finalPartQuals();

	// } else if (skills == true) {

	// 	skillsAutoLift();

	// }
}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	while (true) {
        // master.set_text(1, 0, to_string(gyro.get_heading()));

		drivetrainPeriodic();
	
		pros::lcd::set_text(0, "Drivetrain Left Encoder: " + to_string(frontLeftMotor.get_position()));

		pros::delay(20);
	}
}	


