class Led{
  private:
    String color;
    int pin;
    bool estado;

    //setters
    void setColor(String c){color=c;}
    void setPin(int p){pin=p;}
    void setEstado(bool e){estado=e;}
    //funciones
    void init(){pinMode(getPin(),OUTPUT);}

  public:
    //constructores
    Led(){}
    Led(String c, int p){
      setColor(c);
      setPin(p);
      setEstado(false);
      init();
    }
    //getters
    String getColor(){return color;}
    int getPin(){return pin;}
    bool getEstado(){return estado;}
    //funciones
    void turnOn(){digitalWrite(getPin(),HIGH); setEstado(true);}
    void turnOff(){digitalWrite(getPin(),LOW); setEstado(false);}
    String toString(){return "Led: "+getColor()+" Pin: "+String(getPin())+" Estado: "+String(getEstado());}
};
