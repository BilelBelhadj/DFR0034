/*
  Titre      : CapteurSonThingsBoard
  Auteur     : Bilel Belhadj
  Date       : 24/11/2021
  Description: Le programme utilise le DFR0036 pour serveillir la periode de travail d'un etudiant, si l'etudiant ecoute une music trés douce
               un led vert va continuer a allumer, des que le son augmente un peut un led bleu va allumer pour le dire que la musique peut
               etre une soustraction, enfin si le son devien a etre tres fort la LED Rouge s'allume pour demander de diminuer le son.
  Version    : 0.0.1
*/



#include <Arduino.h>
#include "WIFIConnector_MKR1000.h"
#include "MQTTConnector.h"

const int ledPinRouge = 1;
const int d = 500 ;

void setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  wifiConnect();
  MQTTConnect();
  pinMode(ledPinRouge , OUTPUT); 

}
void loop()
{
      int val;
      val=analogRead(1); 
                         //connect mic sensor to Analog 0
      Serial.println(val,DEC);              //print the sound value to serial
      delay(d);

        if (val > 200)                       //le son est douce, la LED Vert va continuer a allumer 
        {
          digitalWrite(ledPinRouge , HIGH);  //Led bleu 0
        }else{
          digitalWrite(ledPinRouge , LOW);

        }

      appendPayload("son", val);
      sendPayload();  
        
}