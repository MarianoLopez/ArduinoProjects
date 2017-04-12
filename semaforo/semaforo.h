class Semaforo{
  private:
    int rojo,amarillo,verde;
    
    void pinSetup(){
      pinMode(rojo,OUTPUT);
      pinMode(amarillo,OUTPUT);
      pinMode(verde,OUTPUT);
    }
    
  public:
    //constructor
    Semaforo(int r, int a, int v){
      setRedLed(r);
      setYellowLed(a);
      setGreenLed(v);
      pinSetup();
    }
    //setters
    void setRedLed(int r){rojo = r;}
    void setYellowLed(int a){amarillo = a;}
    void setGreenLed(int v){verde = v;}
    //getters
    int getRedLed(){return rojo;}
    int getYellowLed(){return amarillo;}
    int getGreenLed(){return verde;}
  };
