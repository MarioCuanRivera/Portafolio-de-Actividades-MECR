#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX en pin 2, TX en pin 3

Servo base, brazo1, brazo2, pinza;

char Dato = 'X';

void setup() {
  base.attach(9);    // Servo de la base
  brazo1.attach(10);  // Primer servo del brazo
  brazo2.attach(11);  // Segundo servo del brazo
  pinza.attach(12);   // Servo de la pinza

  base.write(90);   // Base en posición central
  brazo1.write(90); // Brazo1 en posición inicial
  brazo2.write(90); // Brazo2 en posición inicial
  pinza.write(90);  // Pinza cerrada a medio camino

  mySerial.begin(9600); 
  Serial.begin(9600);   
}

void loop() {
  if (mySerial.available() > 0) {
    Dato = mySerial.read(); 
    Serial.println(Dato);   

    if (Dato == 'A') { // Girar la base hacia un lado
      base.write(0); 
    } 
    if (Dato == 'B') { // Girar la base hacia el otro lado
      base.write(180);
    }

    if (Dato == 'C') { // Subir brazo
      brazo1.write(45);  
      brazo2.write(45); 
    } 
    if (Dato == 'D') { // Bajar brazo
      brazo1.write(135); 
      brazo2.write(135); 
    }

    // Control de la pinza
    if (Dato == 'E') { // Abrir pinza
      pinza.write(0); 
    } 
    if (Dato == 'F') { // Cerrar pinza
      pinza.write(180);
    }

    delay(100); 
  }
}
