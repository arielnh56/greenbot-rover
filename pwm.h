#include <PID_v1.h>

// desired rpm
double rpm_l = 0;
double rpm_r = 0;


// current rpm - PID setpoints
double current_rpm_l = 0;
double current_rpm_r = 0;
// motor pwm - PID output
double pwm_l = 0;
double pwm_r = 0;
// pid vars
double KpL = 0.3, KiL = 4, KdL = 0.008;
double KpR = 0.3, KiR = 4, KdR = 0.008;
PID lPID(&current_rpm_l, &pwm_l, &rpm_l, KpL, KiL, KdL, DIRECT);
PID rPID(&current_rpm_r, &pwm_r, &rpm_r, KpR, KiR, KdR, DIRECT);

void setupPWM() {
  lPID.SetMode(AUTOMATIC);
  rPID.SetMode(AUTOMATIC);
  lPID.SetSampleTime(50);
  rPID.SetSampleTime(50);
  lPID.SetOutputLimits(0.0, 99.0);
  rPID.SetOutputLimits(0.0, 99.0);
}

void checkPWM() {
  lPID.Compute();
  rPID.Compute();
  MOTOR.setSpeed1(pwm_l);
  MOTOR.setSpeed2(pwm_r);
}

