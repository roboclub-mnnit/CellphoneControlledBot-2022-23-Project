//Arduino Code

//LEFT_M1 and LEFT_M2 are left motor ends
int RIGHT_M1 = 6;
int RIGHT_M2 = 9;  //high for front

//RIGHT_M1 and RIGHT_M2 are right motor ends
int LEFT_M1 = 10;  
int LEFT_M2 = 11;  //high for front
String str,str1,str2,str3;
float xi,yi,zi,xd,yd,zd;
int x,c=0;
void setup() {
  // put your setup code here, to run once:
          Serial.begin(9600);
        pinMode(LEFT_M1 , OUTPUT);
        pinMode(LEFT_M2 , OUTPUT);
        pinMode(RIGHT_M1, OUTPUT);
        pinMode(RIGHT_M2, OUTPUT);

}
void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available())                 
{ str=Serial.readStringUntil('\n');
  x=str.indexOf('/');
  str1=str.substring(0,x);
  str.remove(0,x+1);
  x=str.indexOf('/');
  str2=str.substring(0,x);
  str.remove(0,x+1);
  int x=str.indexOf('\n');
  str3=str.substring(0,x);
  str.remove(0,x+1);
  if(c==0){
        xi=str1.toFloat();
        yi=str2.toFloat();
        zi=str3.toFloat();
        c++;
    }
        xd=str1.toFloat();
        yd=str2.toFloat();
        zd=str3.toFloat();
  Serial.println('\n');
  Serial.println(xd);
  Serial.println('\n');
  Serial.println(yd);
  Serial.println('\n');
  Serial.println(zd);

  if(xd>9.00||xd<0.00||((xd<6.00&&xd>3.00))&&(yd<1.50&&yd>(-1.50))){//STOPPING CONDITION
                        analogWrite(LEFT_M1, 0);
                        analogWrite(LEFT_M2, 0);
                        analogWrite(RIGHT_M1, 0);
                        analogWrite(RIGHT_M2, 0);      
   }
  else if(xd<3.00&&(yd<1.50&&yd>(-1.50))){//FORWARD MOVEMENT
    if(xd>0.00){
                        analogWrite(LEFT_M1, 0);
                        analogWrite(LEFT_M2, (4.50-xd)*60);
                        analogWrite(RIGHT_M1, 0);
                        analogWrite(RIGHT_M2, (4.50-xd)*60);
      
      }
    else if(xd<0.00){
                        analogWrite(LEFT_M1, 0);
                        analogWrite(LEFT_M2, (4.50)*60);
                        analogWrite(RIGHT_M1, 0);
                        analogWrite(RIGHT_M2, (4.50)*60);
      }
    }
  else if(xd>6.00&&(yd<1.50&&yd>(-1.50))){//REVERSE MOVEMENT
                        analogWrite(LEFT_M2, 0);
                        analogWrite(LEFT_M1, (xd-4.5)*60);
                        analogWrite(RIGHT_M2, 0);
                        analogWrite(RIGHT_M1, (xd-4.5)*60);
    }
  else if((xd<6.00&&xd>3.00)&&(yd>1.50)){//SHARP RIGHT TURN
                        analogWrite(LEFT_M1, 0);
                        analogWrite(LEFT_M2, 150);
                        analogWrite(RIGHT_M1, 150);
                        analogWrite(RIGHT_M2, 0);
    }
  else if((xd<6.00&&xd>3.00)&&(yd<(-1.50))){//SHARP LEFT TURN
                        analogWrite(LEFT_M1, 150);
                        analogWrite(LEFT_M2, 0);
                        analogWrite(RIGHT_M1, 0);
                        analogWrite(RIGHT_M2, 150);
    }
   else if(xd>6.00&&(yd<(-1.50))){
    if(yd>(-5.00)){
                        analogWrite(LEFT_M2, 0);
                        analogWrite(LEFT_M1, (xd-4.50)*40+(-1.50-yd)*20);
                        analogWrite(RIGHT_M2, 0);
                        analogWrite(RIGHT_M1, (xd-4.50)*40-(-1.50-yd)*20);      
      }
     else if(yd<(-5.00)){
                        analogWrite(LEFT_M2, 0);
                        analogWrite(LEFT_M1, (xd-4.50)*40+70);
                        analogWrite(RIGHT_M2, 0);
                        analogWrite(RIGHT_M1, (xd-4.50)*40-70);       
      }
    }
   else if(xd<3.00&&(yd<(-1.50))){
    if(yd>(-5.00)){
                        analogWrite(LEFT_M1, 0);
                        analogWrite(LEFT_M2, (xd-4.50)*40-(-1.50-yd)*20);
                        analogWrite(RIGHT_M1, 0);
                        analogWrite(RIGHT_M2, (xd-4.50)*40+(-1.50-yd)*20);      
      }
     else if(yd<(-5.00)){
                        analogWrite(LEFT_M1, 0);
                        analogWrite(LEFT_M2, (xd-4.50)*40-70);
                        analogWrite(RIGHT_M1, 0);
                        analogWrite(RIGHT_M2, (xd-4.50)*40+70);       
      }
    }    
    else if(xd>6.00&&(yd>(1.50))){
    if(yd<(5.00)){
                        analogWrite(LEFT_M2, 0);
                        analogWrite(LEFT_M1, (xd-4.50)*40-(-1.50+yd)*20);
                        analogWrite(RIGHT_M2, 0);
                        analogWrite(RIGHT_M1, (xd-4.50)*40+(-1.50+yd)*20);      
      }
     else if(yd>(5.00)){
                        analogWrite(LEFT_M2, 0);
                        analogWrite(LEFT_M1, (xd-4.50)*40-70);
                        analogWrite(RIGHT_M2, 0);
                        analogWrite(RIGHT_M1, (xd-4.50)*40+70);       
      }
    }
   else if(xd<3.00&&(yd>(1.50))){
    if(yd<(5.00)){
                        analogWrite(LEFT_M1, 0);
                        analogWrite(LEFT_M2, (xd-4.50)*40+(-1.50+yd)*20);
                        analogWrite(RIGHT_M1, 0);
                        analogWrite(RIGHT_M2, (xd-4.50)*40-(-1.50+yd)*20);      
      }
     else if(yd>(5.00)){
                        analogWrite(LEFT_M1, 0);
                        analogWrite(LEFT_M2, (xd-4.50)*40+70);
                        analogWrite(RIGHT_M1, 0);
                        analogWrite(RIGHT_M2, (xd-4.50)*40-70);       
      }
    } 
  }
}
