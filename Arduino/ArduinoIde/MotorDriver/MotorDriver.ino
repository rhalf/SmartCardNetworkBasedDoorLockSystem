int iPinSignal = 0;  //RX // signal coming raspberry gpio 18 
int iPinMotorA = A4;
int iPinMotorB = A5;
int iPinLimitLeft = 11;
int iPinLimitRight = 12;

int iMasterDelay = 3000;
int iMasterDelaySpeed = 100;

void setup()
{
  // put your setup code here, to run once:
  pinMode(iPinSignal,INPUT);
  pinMode(iPinMotorA,OUTPUT);
  pinMode(iPinMotorB,OUTPUT);
  pinMode(iPinLimitLeft,INPUT);
  pinMode(iPinLimitRight,INPUT);
     
  //Enable Pullup resistor
  digitalWrite(iPinLimitLeft,HIGH);
  digitalWrite(iPinLimitRight,HIGH);
  
  //Set the pin of motor to low
  digitalWrite(iPinMotorA,LOW);
  digitalWrite(iPinMotorB,LOW);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if(digitalRead(iPinSignal)) {
      
      //Power up motor forward
      digitalWrite(iPinMotorA,HIGH);
      digitalWrite(iPinMotorB,LOW);
  
      for(int iCounter = 0; iCounter < iMasterDelay; iCounter += iMasterDelaySpeed) {
        delay(iMasterDelaySpeed);
        if (!digitalRead(iPinLimitLeft)) {
          break;
        }
      }
      
      //Power up motor backward
      digitalWrite(iPinMotorA,LOW);
      digitalWrite(iPinMotorB,HIGH);
  
      
      for(int iCounter = 0; iCounter < iMasterDelay; iCounter += iMasterDelaySpeed) {
        delay(iMasterDelaySpeed);
        if (!digitalRead(iPinLimitRight)) {
          break;
        }
      }
        
      //Turn off Motor
      digitalWrite(iPinMotorA,LOW);
      digitalWrite(iPinMotorB,LOW);
  }
}
