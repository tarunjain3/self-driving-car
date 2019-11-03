char t;
  const int motorA1      = 3;  
  const int motorA2      = 4; 
  const int motorAspeed  = 5;
  const int motorB1      = 7; 
  const int motorB2      = 8; 
  const int motorBspeed  =6;
   int vSpeed = 110;        // MAX 255
  int turn_speed = 230;    // MAX 255 
  int turn_delay = 10;

   const int left_sensor_pin =9;
  const int right_sensor_pin =10;

  
  int left_sensor_state;
  int right_sensor_state;
void setup() {

  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
   pinMode(left_sensor_pin, INPUT);
  pinMode(right_sensor_pin, INPUT);
  Serial.begin(9600);
}

void loop() {

  if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}

if(t=='M')manualmode();

left_sensor_state = digitalRead(left_sensor_pin);
right_sensor_state = digitalRead(right_sensor_pin);

if(right_sensor_state == HIGH && left_sensor_state == LOW)
{ 
  right();  
  }
if(right_sensor_state == LOW && left_sensor_state == HIGH)
{
  left();
  delay(turn_delay);
  }

if(right_sensor_state == LOW && left_sensor_state == LOW)
{
  forward();
  delay(turn_delay);
  
  }

if(right_sensor_state == HIGH && left_sensor_state == HIGH)
{ 
  stops();
  }

}

void manualmode()
 {  
  while(1)
  {
    if(Serial.available())
    {
      t = Serial.read();
      Serial.println(t);
    }
    
  if(t == 'F'){            //move forward(all motors rotate in forward direction)
    forward();
  }
 
else if(t == 'G'){      //move reverse (all motors rotate in reverse direction)
  back();
  }
 
else if(t == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
 right();
}
// 
else if(t == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
left();
}

else if(t == 'S'){      //STOP (all motors stop)
 stops();
}


    if(t == 'm')return;
  }
 }

void forward()
{
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
}

void back()
{
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
}

void left()
{
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
   analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, turn_speed);
}

void right()
{
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  analogWrite (motorAspeed, turn_speed);
  analogWrite (motorBspeed, vSpeed);
}

void stops()
{
  digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,LOW);
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,LOW);
}
