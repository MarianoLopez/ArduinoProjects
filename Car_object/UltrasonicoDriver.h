class UltrasonicoDriver{
    private:
    uint8_t Echo,Trig;
    
    
    void init(){pinMode(Echo, INPUT);pinMode(Trig, OUTPUT);}
    
    public:
    UltrasonicoDriver(){}
    UltrasonicoDriver(uint8_t echo,uint8_t  trig){
      Echo = echo;
      Trig = trig;
      init();  
    }
    
    int getDistancia(){
      digitalWrite(Trig, LOW);   
      delayMicroseconds(2);
      digitalWrite(Trig, HIGH);  
      delayMicroseconds(20);
      digitalWrite(Trig, LOW);   
      float Fdistance = pulseIn(Echo, HIGH);  
      Fdistance= Fdistance/58;       
      return (int)Fdistance;
    }
};

