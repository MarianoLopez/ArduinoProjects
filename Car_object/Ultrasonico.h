class Ultrasonico{
    private:
    const uint8_t *Echo,*Trig;
    init(){pinMode(*Echo, INPUT);pinMode(*Trig, OUTPUT);}
    
    public:
    Utrasonico(){}
    Utrasonico(const uint8_t& echo, const uint8_t& trig){
      Echo = echo;
      Trig = trig;
      init();  
    }
    
    int getDistance(){
      return 1;
      /*digitalWrite(Trig, LOW);   
      delayMicroseconds(2);
      digitalWrite(Trig, HIGH);  
      delayMicroseconds(20);
      digitalWrite(Trig, LOW);   
      float Fdistance = pulseIn(Echo, HIGH);  
      Fdistance= Fdistance/58;       
      return (int)Fdistance;*/
    }
};

