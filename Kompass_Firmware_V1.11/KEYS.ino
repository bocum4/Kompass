void KEYS(){
  
// the order of the pins from lowest note is 15,16,18,2,4,6,11,12,13,14
  j++;//
  if (j>63){
    //dfreqc=(analogRead(4))*8;         
    //dfreqf=(analogRead(5)/8); 
  }

  keysb = cap.touched();
  keysd = cap.touched();

switch (keysb){
  case (1<<0):
    kh=1;
    keypress=1;
    keypressb=1;
    Serial.println("PAD 0");
    break;

  case (1<<1):
    kh=2;   
    keypress=1;   
    keypressb=1;
    Serial.println("PAD 1");
    break;

  case (1<<2):
    kh=3;   
    keypress=1;   
    keypressb=1;
    Serial.println("PAD 2");
    break;

  case (1<<3):
    kh=10;   
    keypress=1;   
    keypressb=1;
    Serial.println("PAD 3");
    break;

  default: 
    keypressb=0;   
    break;
  }

  switch (keysd){
  case (1<<4):
    kh=4;
    keypress=1;
    keypressd=1;
    Serial.println("PAD 4");
    break;

  case (1<<5):
    kh=5;   
    keypress=1;   
    keypressd=1;
    Serial.println("PAD 5");
    break;

  case (1<<6):
    kh=6;   
    keypress=1;   
    keypressd=1;
    Serial.println("PAD 6");
    break;

  case (1<<7):
    kh=7;   
    keypress=1;   
    keypressd=1;
    Serial.println("PAD 7");
    break;

  case (1<<8):
    kh=8;   
    keypress=1; 
    keypressd=1;
    Serial.println("PAD 8");  
    break;

  case (1<<9):
    kh=9;   
    keypress=1; 
    keypressd=1;
    Serial.println("PAD 9");      
    break;

  default: 

    keypressd=0;  
    break;
  }

  key = kh;

  if (keypressd==0 && keypressb==0)
  {
    keypress=0;
  }

  if (kh != prevkh || keypress!=prevkeypress){

    if (keypress == 1) {
      count=0;
      remember[0] = prevkh;
      release=255;
              releaseb=255;
      remember[1] = key;
      keydown =1;
      scan=0;
    }   

    prevkh = kh;
    prevkeypress=keypress;
    prevkeydown=keydown;
  }

  if (keypress == 0) {

    keydown =0;
    if (millis() - prev > releaselength ) {       
      prev = millis();
      if (releaselength<20){
                releaseb-=4;
        if (release > 5){
          release-=(((release))*.3);
        }

        if (release <= 10){
                  releaseb-=4;
          release =0;
          ampholder=1;
        }
      }
      if (releaselength>=20){
        releaseb-=4;
        if (release > 5){
          release-=(((release))*.02);
        }

        if (release <= 10){
          release =0;
          ampholder=1;
        }
      }




    }

  }

  
}
