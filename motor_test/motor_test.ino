// map function that constrains bad input
// value, origional range, modified range
int cmap(int val, int olow, int ohigh, int mlow, int mhigh) {
  return constrain(map(val, olow, ohigh, mlow, mhigh), mlow, mhigh);
}

// struct to make motor control easier
struct Motor {
  uint8_t fpin;                             //fwd pin
  uint8_t rpin;                             //reverse pin
  void speed(int val);                      //function setting speed
} leftmotor{ 8, 9 }, rightmotor{ 10, 11 };  // init right away

// speed function for setting motor speed
void Motor::speed(int val) {
  int map_speed = cmap(abs(val), 0, 100, 0, 255);
  // check if its forward or reverse
  if (val > 0) {
    analogWrite(fpin, map_speed);
    analogWrite(rpin, 0);
  } else {
    analogWrite(fpin, 0);
    analogWrite(rpin, map_speed);
  }
}


void setup() {
  pinMode(20, INPUT);
  while (digitalRead(20))
    delay(20);

  leftmotor.speed(20);
  rightmotor.speed(-20);
  delay(3000);

  leftmotor.speed(-20);
  rightmotor.speed(20);
  delay(3000);

  leftmotor.speed(0);
  rightmotor.speed(0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
