#include <MIDI.h>

#define LED 13 //use the onboad led
#define CV 9 

void ccToCv(byte channel, byte number, byte value)
{ 
    if ( value >= 65 )
      digitalWrite(LED, HIGH);
    else
      digitalWrite(LED, LOW);
      
    analogWrite(CV, value*2);
}

void setup()
{
  pinMode (LED, OUTPUT);
  pinMode (CV, OUTPUT);
  MIDI.begin(MIDI_CHANNEL_OMNI); //listen on all channels
  MIDI.setHandleControlChange(ccToCv);
}

void loop()
{
  MIDI.read();            
}

