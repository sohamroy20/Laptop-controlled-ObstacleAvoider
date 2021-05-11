//Initialization
const int trigPin = 12;
const int echoPin = 11;
const int buzzPin = 8;
int motorR1=10;        // Motor Pins
int motorR2=9;
int motorL1=5;
int motorL2=6;
char x;
int duration;
int distance;
int b=1;
int c=1;
unsigned int on=0;
unsigned int on1=0;
unsigned int on2=0;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(buzzPin, OUTPUT);
  
  pinMode(motorR1,OUTPUT);
  pinMode(motorR2,OUTPUT);
  pinMode(motorL1,OUTPUT);
  pinMode(motorL2,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  x=Serial.read();                             // taking input from keyboard

if(x=='W' || x=='w')                           //forward using letter 'w'
{
  digitalWrite(motorR1,LOW);
  digitalWrite(motorR2,HIGH);
  digitalWrite(motorL1,LOW);
  digitalWrite(motorL2,HIGH);
}

else if (x=='s' || x=='S')                    //backward
{
  digitalWrite(motorR1,HIGH);
  digitalWrite(motorR2,LOW);
  digitalWrite(motorL1,HIGH);
  digitalWrite(motorL2,LOW);
}

else if (x=='a' || x=='A')                    //left 

{
  digitalWrite(motorR1,LOW);
  digitalWrite(motorR2,HIGH);
  digitalWrite(motorL1,HIGH);
  digitalWrite(motorL2,LOW);
}

else if (x=='d' || x=='D')                    //right

{
  digitalWrite(motorR1,HIGH);
  digitalWrite(motorR2,LOW);
  digitalWrite(motorL1,LOW);
  digitalWrite(motorL2,HIGH);
}

else if (x==' ')                              //stop
{
  digitalWrite(motorR1,LOW);
  digitalWrite(motorR2,LOW);
  digitalWrite(motorL1,LOW);
  digitalWrite(motorL2,LOW);
}
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034*(duration/2);
  on=millis();//100
  
  if (distance <= 5)
  {
    digitalWrite(buzzPin,HIGH);
  }

  else if (distance <= 15 && distance > 5)
  {
    if(b==1)
    {
     on1=on;
     on2=on1+50;
     b=0;
    }
    if(on<(on1+50))
    {
       digitalWrite(buzzPin,HIGH);
    }
    else if((on<(on2+50)) && (on>=(on1+50)))
    {
       digitalWrite(buzzPin,LOW);
    }
    else
    {
     b=1;
    }
    c=1;
  }


   else if (distance <= 25 && distance > 15)
    {
     if(c==1)
     {
      on1=on;
      on2=on1+300;
      c=0;
     }
     if(on<(on1+300))
     {
       digitalWrite(buzzPin,HIGH);
     }
     else if((on<(on2+300)) && (on>=(on1+300)))
     {
       digitalWrite(buzzPin,LOW);
     }
     else
     {
      c=1;
     }
     b=1;
   }
  
    
  else
  {
     digitalWrite(buzzPin,LOW);
     b=1;
     c=1;
     on=on1=on2=0;
  }
  Serial.print("distance = ");
  Serial.println(distance);
  Serial.print("Duration =");
  Serial.println(duration);
  
 // delay(300);
}
