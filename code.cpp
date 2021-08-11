// C++ code
//

const uint8_t btn_pin = 2;

void setup()
 
{
  pinMode(A0, INPUT);
  pinMode(btn_pin, INPUT);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(btn_pin), toggle, FALLING);
}

void loop()
  
{
  int tempAnalog = analogRead(A0); //Read the analog value from sensor
  float v = (tempAnalog * 5.0)/1024; //Convert value to a usable value as a voltage
  float mV = v * 1000; //Convert usable voltage to mV for simplicity of calculation.
  
  float tempReadout =  (mV-500)/10; //Assign calculated temperature to variable.
  
  if (tempReadout > 32.5) {  //If temperature value is more than 32.5C light glows bright.
    digitalWrite(13, HIGH);
  
  }
  
  if (tempReadout < 32.5) { //If temperature value is less than 32.5C, light turns off.
    digitalWrite(13, LOW);
  }
  
}

void toggle() {
  
  digitalWrite(5, HIGH);
}