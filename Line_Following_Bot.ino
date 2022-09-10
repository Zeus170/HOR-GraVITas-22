//intializing Motors for wheels
int mot1=9;
//motor 1
int mot2=6;
//motor 2
int mot3=5;
//motor 3
int mot4=3;
//motor 4


//intializing IR sensors
int left=13;
int right=12;

//IR sensor return variables
int Left=0;
int Right=0;


//functions for bot maneuvering
void LEFT (void);
void RIGHT (void);
void STOP (void);


//setup block; setting pinModes
void setup()
{
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);

//for IR inputs
  pinMode(left,INPUT);
  pinMode(right,INPUT);

//initial values for IR sensors
  digitalWrite(left,HIGH);
  digitalWrite(right,HIGH);
  
  
}

void loop() 
{

 //forward movement. On each iteration, BO motor will complete 1 rotation
analogWrite(mot1,255);
analogWrite(mot2,0);
analogWrite(mot3,255);
analogWrite(mot4,0);

//infinite loop
while(1)
{
  Left=digitalRead(left);
  Right=digitalRead(right);

  //checks for IR output
  if((Left==0 && Right==1)==1)
  //move left
  LEFT();
  else if((Right==0 && Left==1)==1)
  //move right
  RIGHT();
}
}

void LEFT (void)
{

  //moves left by rotating one wheel by a factor of 30
   analogWrite(mot3,0);
   analogWrite(mot4,30);
   
   
   while(Left==0)
   {
    Left=digitalRead(left);
    Right=digitalRead(right);
    if(Right==0)
    {
      int lprev=Left;
      int rprev=Right;
      STOP();
      while(((lprev==Left)&&(rprev==Right))==1)
      {
         Left=digitalRead(left);
         Right=digitalRead(right);
      }
    }
    analogWrite(mot1,255);
    analogWrite(mot2,0); 
   }
   analogWrite(mot3,255);
   analogWrite(mot4,0);
}

void RIGHT (void)
{
   analogWrite(mot1,0);
   analogWrite(mot2,30);

   while(Right==0)
   {
    Left=digitalRead(left);
    Right=digitalRead(right);
    if(Left==0)
    {
      int lprev=Left;
      int rprev=Right;
     STOP();
      while(((lprev==Left)&&(rprev==Right))==1)
      {
         Left=digitalRead(left);
         Right=digitalRead(right);
      }
    }
    analogWrite(mot3,255);
    analogWrite(mot4,0);
    }
   analogWrite(mot1,255);
   analogWrite(mot2,0);
}
void STOP (void)
{
analogWrite(mot1,0);
analogWrite(mot2,0);
analogWrite(mot3,0);
analogWrite(mot4,0);
  
}
