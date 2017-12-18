#include <EasyTransferI2C.h>

//EasyTransfer
EasyTransferI2C ETdown;

struct DOWN_DATA_STRUCTURE {
  //put your variable definitions here for the data you want to send
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  double rpm_r;
  double rpm_l;
};

//give a name to the group of data
DOWN_DATA_STRUCTURE downdata;

void receiveET(int numBytes) {}

void setupRovertalk() {
  ETdown.begin(details(downdata), &Wire);
  //define handler function on receiving data
  Wire.onReceive(receiveET);
}

void checkRovertalk() {
    if (ETdown.receiveData()) {
    MOTOR.setDir1((downdata.rpm_l < 0) ? DIRR : DIRF);
    MOTOR.setDir2((downdata.rpm_r < 0) ? DIRR : DIRF);
    rpm_l = abs(downdata.rpm_l);
    rpm_r = abs(downdata.rpm_r);
  }
}

