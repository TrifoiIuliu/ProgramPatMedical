#include<ezButton.h>
#include<ezOutput.h>

//Definire butoane
ezButton btn_patSus(0);
ezButton btn_patJos(1);
ezButton btn_spateSus(2);
ezButton btn_spateJos(3);
ezButton btn_picioareSus(4);
ezButton btn_picioareJos(5);

//Definire limitatori
ezButton limit_patSus(A0);
ezButton limit_patJos(A1);
ezButton limit_spateSus(A2);
ezButton limit_spateJos(A3);

//Definire comanda actionare
ezOutput K1_punteH(6);
ezOutput K2_punteH(7);
ezOutput K3_punteH(8);
ezOutput K4_punteH(9);
ezOutput K5_motorPat(10);
ezOutput K6_motorSpate(11);
ezOutput K7_motorPicioare(12);

void setup() {
  // put your setup code here, to run once:
  btn_patSus.setDebounceTime(50);
  btn_patJos.setDebounceTime(50);
  btn_spateSus.setDebounceTime(50);
  btn_spateJos.setDebounceTime(50);
  btn_picioareSus.setDebounceTime(50);
  btn_picioareJos.setDebounceTime(50);
  limit_spateSus.setDebounceTime(50);
  limit_spateJos.setDebounceTime(50);
  limit_patSus.setDebounceTime(50);
  limit_patJos.setDebounceTime(50);

  K1_punteH.high();
  K2_punteH.high();
  K3_punteH.high();
  K4_punteH.high();
  K5_motorPat.high();
  K6_motorSpate.high();
  K7_motorPicioare.high();

 // Serial.begin(9600);
}

void loop() {

  btn_patSus.loop();
  btn_patJos.loop();
  btn_spateSus.loop();
  btn_spateJos.loop();
  btn_picioareSus.loop();
  btn_picioareJos.loop();
  limit_patSus.loop();
  limit_patJos.loop();
  limit_spateSus.loop();
  limit_spateJos.loop();

//Conditii miscare

 if(!btn_patSus.getState()&&btn_patJos.getState()&&btn_spateSus.getState()&&btn_spateJos.getState()&&btn_picioareSus.getState()&&btn_picioareJos.getState()&&!limit_patSus.getState())
 { 
  //pat sus
  punteH(1);
  delay(20);
  K6_motorSpate.high();
  K7_motorPicioare.high();
  delay(20);
  K5_motorPat.low();
 }
 else
  if(!btn_patSus.getState()&&limit_patSus.getState())
  {
    K5_motorPat.high();
    punteH(3);
    }
    
 if(!btn_patJos.getState()&&btn_patSus.getState()&&btn_spateSus.getState()&&btn_spateJos.getState()&&btn_picioareSus.getState()&&btn_picioareJos.getState()&&!limit_patJos.getState())
  {
//pat jos
  punteH(2);
   delay(20);
  K6_motorSpate.high();
  K7_motorPicioare.high();
  delay(20);
  K5_motorPat.low();
    }
 else
  if(!btn_patJos.getState()&&limit_patJos.getState())
  {
    K5_motorPat.high();
    punteH(3);
    }
    
 if(!btn_spateSus.getState()&&btn_patSus.getState()&&btn_patJos.getState()&&btn_spateJos.getState()&&btn_picioareSus.getState()&&btn_picioareJos.getState()&&!limit_spateSus.getState())
  {
//spate sus
punteH(1);
delay(20);
K5_motorPat.high();
K7_motorPicioare.high();
delay(20);
K6_motorSpate.low();
    }
 else
  if(!btn_spateSus.getState()&&limit_spateSus.getState())
  {
    K6_motorSpate.high();
    punteH(3);
    }
    
 if(!btn_spateJos.getState()&&btn_patSus.getState()&&btn_patJos.getState()&&btn_spateSus.getState()&&btn_picioareSus.getState()&&btn_picioareJos.getState()&&!limit_spateJos.getState())
   {
//spate jos
punteH(2);
delay(20);
K5_motorPat.high();
K7_motorPicioare.high();
delay(20);
K6_motorSpate.low();
    }
 else
  if(!btn_spateJos.getState()&&limit_spateJos.getState())
  {
    K6_motorSpate.high();
    punteH(3);
    }

 if(!btn_picioareSus.getState()&&btn_patSus.getState()&&btn_patJos.getState()&&btn_spateSus.getState()&&btn_spateJos.getState()&&btn_picioareJos.getState())
    {
//picioare sus
punteH(1);
delay(20);
K5_motorPat.high();
K6_motorSpate.high();
delay(20);
K7_motorPicioare.low();
    }

 if(!btn_picioareJos.getState()&&btn_patSus.getState()&&btn_patJos.getState()&&btn_spateSus.getState()&&btn_spateJos.getState()&&btn_picioareSus.getState())
    {
//picioare jos
punteH(2);
delay(20);
K5_motorPat.high();
K6_motorSpate.high();
delay(20);
K7_motorPicioare.low();
    }

  if(btn_patSus.getState()&&btn_patJos.getState()&&btn_spateSus.getState()&&btn_spateJos.getState()&&btn_picioareSus.getState()&&btn_picioareJos.getState())
    {
     punteH(3);
     K5_motorPat.high();
     K6_motorSpate.high();
     K7_motorPicioare.high();
    }

    
}


//Functie de control pentru puntea H
void punteH(int dir)
{
 switch (dir)
 {
  //daca dir==1 motoarul merge 'inainte'
  case 1:
  K1_punteH.low();
  K2_punteH.low();
  K3_punteH.high();
  K4_punteH.high();
  break;
 //daca dir==2 motoarul merge 'inapoi'
  case 2:
  K1_punteH.low();
  K2_punteH.low();
  K3_punteH.low();
  K4_punteH.low();
  break;
  //motorul este oprit
  default:
  K1_punteH.high();
  K2_punteH.high();
  K3_punteH.high();
  K4_punteH.high();
  break;
 }  
 }
    
 
