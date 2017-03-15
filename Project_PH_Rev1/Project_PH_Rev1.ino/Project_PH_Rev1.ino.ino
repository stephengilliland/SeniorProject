#include <Wire.h>

int LED = 13;
int pH = 72;
int packetnum = 1;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()

void requestEvent()
{
  
  if(packetnum == 1)
  {
    Wire.write("P"); // respond with
  }
  if(packetnum == 2)
  {
    Wire.write(pH);
  }
  packetnum = packetnum + 1;
  if(packetnum > 2)
    packetnum = 1;
    
  
  
  // as expected by master
}

void loop() {
  // put your main code here, to run repeatedly:
  
}