//Runs an RGB LED through a color wheel cycle

int brightness = 0;    // how bright the LED is. Maximum value is 255
int rad = 0;

#define RED 10
#define BLUE 11
#define GREEN 9

void setup()  { 
  // declare pins to be an output:
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

//from 0 to 127
void displayColor(uint16_t WheelPos)
{
  byte r, g, b;
  switch(WheelPos / 128)
  {
    case 0:
      r = 127 - WheelPos % 128; //Red down
      g = WheelPos % 128; // Green up
      b = 0; //blue off
      break;
    case 1:
      g = 127 - WheelPos % 128; //green down
      b = WheelPos % 128; //blue up
      r = 0; //red off
      break;
    case 2:
      b = 127 - WheelPos % 128; //blue down
      r = WheelPos % 128; //red up
      g = 0; //green off
      break;
  }
  analogWrite(RED, r*2);
  analogWrite(GREEN, g*2);
  analogWrite(BLUE, b*2);
  
}
void loop()  {   
  displayColor(rad);
  // wait for 30 milliseconds to see the dimming effect    
  delay(20);                            
  rad = (rad+1) % 384;
}
