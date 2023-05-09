// int rightIR=2;// purple wire
// int leftIR=3;// black wire
// 5th pin 3 and 4th mototr red
//9th pin 1 and 2 motor dark green
// int A=10; // dark green
// int B=5;
// int speed=225;
#include <VirtualWire.h>

char *data;

char input;     // to store input character received via BT.

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  Serial.begin(9600);  
  vw_set_tx_pin (3);
  vw_setup (2000);

  pinMode(5, LOW);
  pinMode(6, LOW);
  pinMode(10, LOW);
  pinMode(11, LOW);

  // pinMode(2,INPUT);
  // pinMode(3,INPUT);
  // pinMode(A0,INPUT);
  // pinMode(10, OUTPUT); // dark green 3rd and 4th motor
  // pinMode(5,OUTPUT); // red 1 and 2nd motor
}

void loop()
{
  // speed = analogRead(A0);
  // speed = speed * 0.249;
  // analogWrite(A,speed);
  // analogWrite(B,speed);

  while(Serial.available())
  {
    input =Serial.read();
    Serial.println(input);
    
    if(input == 'F')
    {
      data="f";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      forward();
    }

    else if (input == 'R')
    {
      data="r";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();//turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    
      right();
    }

    else if (input== 'L')
    {
      data="l";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      left();    
    }  

    else if (input== 'G')
    {
      data="g";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      backward();

    }  
    else if (input== 'S')
    {
      data="s";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();//STOP (all motors stop)
      stop();
    
    }  
  }
}  

void forward()
  {
  digitalWrite(6, LOW	);
  digitalWrite(5, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void stop()
  {
  digitalWrite(6, LOW	);
  digitalWrite(5, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void backward()
  {
  digitalWrite(6, HIGH	);
  digitalWrite(5, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void right()
  {
  digitalWrite(6, HIGH	);
  digitalWrite(5, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void left()
  {
  digitalWrite(6, LOW	);
  digitalWrite(5, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}