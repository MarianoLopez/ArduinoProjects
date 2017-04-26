#include "Led.h"
enum LED{RED_LED=0,YELLOW_LED=1,GREEN_LED=2};
class Semaforo{
  private:
    int id;
    Led leds[3];//red,yellow,green;
    bool message;//bandera para imprimir mensajes
    
    //setters
    void setId(int s){id=s;}
    void setLed(LED num, String nombre, int pin) {leds[num]=Led(nombre,pin);}
    
    //getters
    Led getLed(LED num){return leds[num];}
    
    //imprimir mensaje
    void printMessageIf(String message){if(message){Serial.println(message);}}
    
  public:
    //constructores
    Semaforo(){}
    Semaforo(int n,int red, int yellow, int green){
      setId(n);
      setLed(RED_LED,"Rojo",red);
      setLed(YELLOW_LED,"Amarillo",yellow);
      setLed(GREEN_LED,"Verde",green);
      message = false;
    }
    //getters
    int getId(){return id;}
    
    //funciones
    void turnLedOn(LED num){
      for(int i=RED_LED;i<=GREEN_LED;i++){leds[i].turnOff();}//apagar todos
      Led aux = getLed(num);
      aux.turnOn();
      printMessageIf("Semaforo "+String(getId())+" - "+aux.toString());
    }
    void turnLedOff(LED num){getLed(num).turnOff();}
    void turnAll(){for(int i=RED_LED;i<=GREEN_LED;i++){leds[i].turnOn();}}
    void enableMessages(){message=true;}
    void disableMessages(){message=false;}
  };
