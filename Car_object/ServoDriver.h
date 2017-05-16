#include <Servo.h>
enum DIRECCION{IZQUIERDA=0,CENTRO=1,DERECHA=2};
class ServoDriver{
    private:
      Servo servo;
      int direcciones[3];
      int _delay;

      void init(int pin){servo.attach(pin);}
      
    public:
      ServoDriver(){}
      ServoDriver(int pin){
        init(pin);
        direcciones[IZQUIERDA]=0;
        direcciones[CENTRO]=90;
        direcciones[DERECHA]=180;
        _delay = 500;
      }
      
      void setGrados(int grados_izquierda, int grados_centro, int grados_derecha){
        direcciones[IZQUIERDA]=grados_izquierda;
        direcciones[CENTRO]=grados_centro;
        direcciones[DERECHA]=grados_derecha;
      }
      
      void setGiroDelay(int d){_delay=d;}
      
      void ir(DIRECCION direccion){
        servo.write(direcciones[direccion]);
        delay(_delay);
      }
};
