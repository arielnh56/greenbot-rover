void loop() {
//  digitalWrite(13,HIGH); delay(10);
  checkEncoders();
//  digitalWrite(13,LOW);
  checkRovertalk();
  checkPWM();
//  if (last_debug + 25 < millis()) {
//    last_debug = millis();
//    Serial.print(current_rpm_r);    Serial.print(" ");
//    Serial.println(pwm_r);
//  }
}

