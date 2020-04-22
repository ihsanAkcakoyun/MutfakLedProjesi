#include <SharpIR.h>

#define IR A1 // define signal pin
#define model 1080 // used 1080 because model GP2Y0A21YK0F is used
// Sharp IR code for Robojax.com
// ir: the pin where your sensor is attached
// model: an int that determines your sensor:  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y
//                                            430 for GP2Y0A41SK
/*
  2 to 15 cm GP2Y0A51SK0F  use 1080
  4 to 30 cm GP2Y0A41SK0F / GP2Y0AF30 series  use 430
  10 to 80 cm GP2Y0A21YK0F  use 1080
  10 to 150 cm GP2Y0A60SZLF use 10150
  20 to 150 cm GP2Y0A02YK0F use 20150
  100 to 550 cm GP2Y0A710K0F  use 100550

*/
SharpIR SharpIR(IR, model);



#define ldr A2
#define led 3


int uzaklik;
int ldrDurum = 0;

boolean sonDurum;


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ldr, INPUT);
  digitalWrite(led, LOW);
  sonDurum = 0;
}

void loop() {


  ldrDurum = analogRead(ldr);
  if (ldrDurum < 7)
  {
    uzaklik = SharpIR.distance();
    Serial.print("uzaklik= ");
    Serial.println(uzaklik);
    Serial.print("son durum= ");
    Serial.println(sonDurum);
    Serial.print("LDR= ");
    Serial.println(ldrDurum);

    while (uzaklik < 55)
    {
      sonDurum = !sonDurum;
      delay(750);
      break;

    }
    if (sonDurum == 1)
    {

      digitalWrite(led, HIGH);

    }
    if (sonDurum == 0)
    {

      digitalWrite(led, LOW);
    }
  }
  if (ldrDurum > 25)
  {

    sonDurum = 0;
    digitalWrite(led, LOW);
  }
}
