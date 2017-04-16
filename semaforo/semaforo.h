#include "Led.h"
enum LED{RED_LED=0,YELLOW_LED=1,GREEN_LED=2};
class Semaforo{
  private:
    String nombre;
    Led leds[3];//red,yellow,green;
    bool message;//bandera para imprimir mensajes
    //setters
    void setNombre(String s){nombre=s;}
    void setLed(LED num, String nombre, int pin) {leds[num]=Led(nombre,pin);}
    //getters
    Led getLed(LED num){return leds[num];}
    String getNombre(){return nombre;}
    //imprimir mensaje
    void printMessageIf(String message){
      if(message){Serial.println(message);}  
    }
    
  public:
    //constructor
    Semaforo(String n,int red, int yellow, int green){
      setNombre(n);
      setLed(RED_LED,"Rojo",red);
      setLed(YELLOW_LED,"Amarillo",yellow);
      setLed(GREEN_LED,"Verde",green);
      message = false;
    }
    //funciones
    void turnLedOn(LED num){
      for(int i=0;i<(sizeof(leds)/sizeof(int));i++){//sizeof returns the total number of bytes.
        Led aux = getLed(num);
        if(i==num){
          aux.turnOn();//encender
          printMessageIf(getNombre()+" "+aux.toString());
        }else{
          aux.turnOff();//apagar el resto
        }
      }
    }
    void turnLedOff(LED num){getLed(num).turnOff();}
    void enableMessages(){message=true;}
    void disableMessages(){message=false;}
  };
