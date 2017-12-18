// rotation encoders on hardware interrupt pins
// these are speed encoders, not direction i.e. 3 wire
#define ENCODER_L 2
#define ENCODER_R 3

// volatiles for interrupt routines
volatile unsigned long int last_rpm_l, last_rpm_r; // duration between last two pulses in microseconds
volatile unsigned long int last_enc_l, last_enc_r; // timsestamp of last pulse inc micros()
volatile unsigned int enc_count_l, enc_count_r;    // encoder pulse counters

void update_rpm_l() {
  unsigned long int now = micros();
  enc_count_l++;
  last_rpm_l = now - last_enc_l;
  last_enc_l = now;
}

void update_rpm_r() {
  unsigned long int now = micros();
  enc_count_r++;
  last_rpm_r = now - last_enc_r;
  last_enc_r = now;
}

void setupEncoders() {
  last_rpm_l = last_rpm_r = last_enc_l = last_enc_r = 1;
  enc_count_l = enc_count_r = 0;
  pinMode(ENCODER_L, INPUT_PULLUP);
  pinMode(ENCODER_R, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCODER_L), update_rpm_l, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCODER_R), update_rpm_r, RISING);
}

unsigned long int last_average = 0;

void checkEncoders() {
  //unsigned long int now = micros();
  noInterrupts();
  if (last_rpm_l < micros() - last_enc_l) { // it's been longer than the last pulse already
    last_rpm_l = micros() - last_enc_l;
  }
  if (last_rpm_r < micros() - last_enc_r) { // it's been longer than the last pulse already
    last_rpm_r = micros() - last_enc_r;
  }
  interrupts();
  if (last_average + 5 < millis()) {
    current_rpm_l = ( current_rpm_l * 0.9 ) + (6000000.0 / (last_rpm_l * GEAR_RATIO));
    current_rpm_r = ( current_rpm_r * 0.9 ) + (6000000.0 / (last_rpm_r * GEAR_RATIO));
    last_average = millis();
  }
}

