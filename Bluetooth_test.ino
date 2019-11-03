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

void setup() {
//pinMode(13,OUTPUT);   //left motors forward
//pinMode(12,OUTPUT);   //left motors reverse
//pinMode(11,OUTPUT);   //right motors forward
//pinMode(10,OUTPUT);   //right motors reverse
//pinMode(8,OUTPUT);   //Led
//  digitalWrite(8,HIGH);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  //digitalWrite(motorAspeed,HIGH);
  //digitalWrite(motorBspeed,HIGH);

  Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}

if(t == 'F'){            //move forward(all motors rotate in forward direction)
  digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);
  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
}
 
else if(t == 'G'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
  analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, vSpeed);
  }
 
else if(t == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
 digitalWrite (motorA1,LOW);
  digitalWrite(motorA2,HIGH);                       
  digitalWrite (motorB1,LOW);
  digitalWrite(motorB2,HIGH);
    analogWrite (motorAspeed, turn_speed);
  analogWrite (motorBspeed, vSpeed);
}
// 
else if(t == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
digitalWrite (motorA1,HIGH);
  digitalWrite(motorA2,LOW);                       
  digitalWrite (motorB1,HIGH);
  digitalWrite(motorB2,LOW);
   analogWrite (motorAspeed, vSpeed);
  analogWrite (motorBspeed, turn_speed);
}

else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(motorA1,LOW);
  digitalWrite(motorA2,LOW);
  digitalWrite(motorB1,LOW);
  digitalWrite(motorB2,LOW);
//
}
//delay(100);
}
