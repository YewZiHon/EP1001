void setup() {
  // put your setup code here, to run once:
  PORTA.DIR=0x02;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTA.OUT=0x02;
  delay(1000);
  PORTA.OUT=0x00;
  delay(1000);
}
