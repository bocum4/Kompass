void DDS()
{
  releasem=release;

  if (resta==0){
      freq=frequencyouta;
    freq2=freq*3;
      if (oscsel==2){
    freq=frequencyouta;
    freq2=freq/3;
  }
  if (oscsel==4){
    freq=frequencyouta;
    freq2=freq*2;
  }
  else{
    freq=frequencyouta;
    freq2=freq/3;
  }

  
  //  noisekey=(remember[1]<<2)-3;
  }
  if (resta==1){
    freq=0;
    freq2=0;
   //noisekey=1;
  }
  if (oscswitch==1){
    increment=(pow(2,32)*freq)/(3137660);
    increment2=pow(2,32)*freq2/ (3133000);

    // increment3=pow(2,32)*freq/ (3137660);
  }
  if (oscswitch==2){
    increment=(pow(2,32)*freq)/(3137660);
    increment2=pow(2,32)*freq2/ (3133000);

    increment5=(pow(2,30)*(freq))/ (3137660+fpot);

    increment4=pow(2,32)*(freq)/ (3137660);
    increment6=pow(2,32)*(freq+i2)/ (3137660);
    increment7=pow(2,32)*(freq+i4-i3)/ (3137660);
  }
}
