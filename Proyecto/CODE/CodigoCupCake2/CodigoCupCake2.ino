// Codigo CupCake Animatrónico

#include <Servo.h> 

Servo ojo; //Servomotor que controla los ojos
Servo boca;  //Servomotor que controla la boca
int pos = 0; //Ángulo inicial
const int Trigger = 12;   //Pin digital 2 para el Trigger del sensor
const int Echo = 11;   //Pin digital 3 para el Echo del sensor
int estado=90; // Estado inicial del botón, comienza en estado 0
int vela=4; //Pin del led asociado a la vela
int izq=5; //Pin asociado al ojo izquierdo
int der=6; //Pin asociado al ojo derecho

void setup()
{ 
Serial.begin(9600);
pinMode(vela, OUTPUT);  //Configura el pin de la vela como salida
pinMode(izq, OUTPUT);  //Configura el pin del ojo izquierdo como salida
pinMode(der, OUTPUT);  //Configura el pin del ojo derecho como salida
pinMode(Trigger, OUTPUT); //pin como salida
pinMode(Echo, INPUT);  //pin como entrada
digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
ojo.attach(2); // Adjunta el objeto servo de los ojos en el pin 2
boca.attach(3); // Adjunta el objeto servo de los ojos en el pin 3
pos = (0); //Redunda posición al iniciar
ojo.write(pos); // Configura al servo de los ojos para encontrarse
                //En la posición inicial
boca.write(pos); // Configura al servo de la boca para encontrarse
                //En la posición inicial
delay(1000); //Tiempo de retraso
}


void loop()
{

  digitalWrite(vela, LOW); //Establece la salida del led de la vela
  digitalWrite(izq, LOW); //Establece la salida del led de los ojos
  digitalWrite(der, LOW);  //Establece la salida del led de la boca
  delay(100); //Tiempo de retraso
 
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
 
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/58;             //escalamos el pulso a una distancia en cm

  if (d>40&&d <=60) {     

    digitalWrite(vela, HIGH); //Secuencia de luces 
    digitalWrite(izq, LOW);  
    digitalWrite(der, LOW); 
    delay(500);  //Retraso
    digitalWrite(vela, LOW); //Secuencia de luces 
    delay(500);  //Retraso
    digitalWrite(vela, HIGH); //Secuencia de luces 
    delay(500);  //Retraso
    digitalWrite(vela, LOW); //Secuencia de luces 
    delay(250);  //Retraso
  }
  if (d>20&&d <=40) {
    digitalWrite(vela, HIGH); //Secuencia de luces 
    digitalWrite(izq, LOW);  
    digitalWrite(der, LOW); 
    delay(500);  //Retraso
    digitalWrite(izq, HIGH); 
    digitalWrite(der, HIGH); 
    delay(500);  //Retraso
    digitalWrite(izq, LOW);
    digitalWrite(der, HIGH);
    delay(500);  //Retraso
    digitalWrite(izq, HIGH);
    digitalWrite(der, LOW);
    delay(500);  //Retraso
    digitalWrite(izq, HIGH);
    digitalWrite(der, HIGH);
    digitalWrite(vela, HIGH);

   } 
  if (d>15&&d <=20){
    
    digitalWrite(vela, HIGH); //Secuencia de luces 
    digitalWrite(izq, HIGH);
    digitalWrite(der, HIGH);
    pos = (80); //Cambio de posición de ojos
    ojo.write(pos);
    delay (400); //Retraso
    pos = (110); //Cambio de posición de ojos 
    ojo.write(pos);
    delay (400); //Retraso
    pos = (130); //Cambio de posición de ojos 
    ojo.write(pos);
    delay (400); //Retraso
    pos = (130); //Cambio de posición de ojos y boca
    ojo.write(pos);
    delay (400); //Retraso
    pos = (65); //Cambio de la posición de los ojos
    ojo.write(pos);
    delay (400); //Retraso

    pos = (135); //Cambio de la posición de los ojos
    ojo.write(pos);
    delay (400); //Retraso
    
  }
  if ( d <=15){
    pos = (80); //Cambio de posición ojos
    ojo.write(pos);
    pos = (120);
    boca.write(pos); //Cambio de posición boca
    delay (1000);

    digitalWrite(vela, HIGH); //Secuencia de luces 
    digitalWrite(izq, HIGH);
    digitalWrite(der, HIGH);
    pos = (110); //Cambio de posición de ojos y boca
    ojo.write(pos);
    boca.write(pos);
    delay (800); //Retraso

    digitalWrite(vela, HIGH); //Secuencia de luces 
    digitalWrite(izq, HIGH);
    digitalWrite(der, HIGH);
    pos = (130); //Cambio de posición de ojos y boca
    ojo.write(pos);
    boca.write(pos);
    delay (800); //Retraso

    digitalWrite(vela, HIGH); //Secuencia de luces  
    digitalWrite(izq, HIGH);
    digitalWrite(der, HIGH);
    pos = (65); //Cambio de posición en los ojos
    ojo.write(pos);
    pos = (110); //Cambio de posición de la boca
    boca.write(pos);
    delay (800); //Retraso

    pos = (130); //Cambio de posición de ojos y boca
    ojo.write(pos);
    boca.write(pos);
    delay (800); //Retraso

    pos = (65); //Cambio de la posición de los ojos
    ojo.write(pos);
    pos = (110); //Cambio de posición de la boca
    boca.write(pos);
    delay (800); //Retraso

    pos = (135); //Cambio de la posición de los ojos
    ojo.write(pos);
    pos = (60);//Cambio de posición de la boca
    boca.write(pos);
    delay (800); //Retraso
  }
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(100);          //Hacemos una pausa de 100ms
 
}
 
 
