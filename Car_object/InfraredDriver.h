class InfraredDriver{
  private:
    int izquierda, centro, derecha;
    void init(){
      pinMode(izquierda,INPUT);
      pinMode(centro,INPUT);
      pinMode(derecha,INPUT);
    }
  public:
    InfraredDriver(){}
    InfraredDriver(int izq, int cen, int der){
      izquierda = izq;
      centro = cen;
      derecha = der;
    }

    bool isIzquierda(){return digitalRead(izquierda);}
    bool isCentro(){return digitalRead(centro);}
    bool isDerecha(){return digitalRead(derecha);}
    
};

