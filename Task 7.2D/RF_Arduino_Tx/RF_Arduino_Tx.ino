#include <VirtualWire.h>
char t;
char *data;

void setup ()
{
  pinMode (4, OUTPUT); //left motors forward
  pinMode (5, OUTPUT); //left motors reverse
  pinMode (9, OUTPUT); //right motors forward
  pinMode (11, OUTPUT); //right motors reverse

  Serial.begin(9600);

  vw_set_tx_pin (3);
  vw_setup (2000);

  pinMode(4, LOW);
  pinMode(5, LOW);
  pinMode(9, LOW);
  pinMode(11, LOW);
}

void loop()
{
  if(Serial.available())
  {
    t = Serial.read();
    Serial.println(t);
  }

  if(t == 'F')
  {
    data="f";
    vw_send((uint8_t *)data, strlen (data));
    vw_wait_tx();
    digitalWrite (9, HIGH);
    digitalWrite (4, HIGH);
  }
  else if (t =='G')
  {
    data="g";
    vw_send((uint8_t *)data, strlen (data));
    vw_wait_tx();
    digitalWrite (5, HIGH);
    digitalWrite (11, HIGH);
  }
  else if(t == 'L') 
  {
    data="l";
    vw_send((uint8_t *)data, strlen (data));
    vw_wait_tx();
    digitalWrite (9, HIGH); //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  }
  else if(t == 'R') 
  {
    data="r";
    vw_send((uint8_t *)data, strlen (data));
    vw_wait_tx();//turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    digitalWrite (4, HIGH);
  }
  else if(t == 'S') 
  {
    data="s";
    vw_send((uint8_t *)data, strlen (data));
    vw_wait_tx();//STOP (all motors stop)
    digitalWrite (9, LOW);
    digitalWrite (5, LOW);
    digitalWrite (4, LOW);
  }
}