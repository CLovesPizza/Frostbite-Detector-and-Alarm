long thirty = 1800000;
long ten = 600000;
long five = 300000;

void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  int reading = analogRead(1);
  int mV = (reading) * (5000/1024);
  int celsius = (mV - 500)/10;
  int degreesF = (celsius) * (1.8) + 32;

  if(degreesF<0 && degreesF>-15)
  {
    digitalWrite(3, HIGH);
    delay(thirty);
    loopThirty:
    digitalWrite(3, LOW);
    digitalWrite(3, HIGH);
    goto loopThirty;
  }

  if(degreesF<-20 && degreesF>-35)
  {
    digitalWrite(3, HIGH);
    delay(ten);
    loopTen:
    digitalWrite(3, LOW);
    digitalWrite(3, HIGH);
    goto loopTen;
  }
    
    if(degreesF<-40 && degreesF>-45)
  {
    digitalWrite(3, HIGH);
    delay(five);
    loopFive:
    digitalWrite(3, LOW);
    digitalWrite(3, HIGH);
    goto loopFive;
  }
}
