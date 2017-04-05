// Projet Nachlass
// Programme de gestion des portes automatiques
// 2016 Julien Auberson
// Theatre de Vidy Lausanne


#include <DmxMaster.h>



//////////////////////////////////////////// Assignation des pin's et vitesses.
// Porte           1    2    3    4    5    6    7   8     
int bouton[8] =  { 23,  25,  27,  29,  31,  33,  35, 37 }; // PIN bouton ouverture
int capteur[8] = { 22,  24,  26,  28,  30,  32,  34, 40 }; // PIN capteur IR
int vo[8] =      {150, 150, 150, 150, 150, 150, 150, 150}; // vitesse fermeture
int vf[8] =      {150, 150, 150, 150, 150, 150, 150, 150}; // vitesse ouverture
int pc[8] =      {255, 255, 255, 255, 255, 255, 255, 255}; // position porte capteur
int voc[8] =     {225, 225, 225, 225, 225, 225, 225, 225}; // vitesse action capteur
int ch[8] =      {1,     4,   7,  10,  13,  16,  19,  22}; // 

int Bouton_Urgence = 38;
int Bouton_Rideau = 39;
int vfR = 100;
int voR = 100;


void setup(){

DmxMaster.maxChannel(27);

  for (int i = 0; i < 8; i++)
  {
  pinMode(bouton[i], INPUT_PULLUP);
  pinMode(capteur[i], INPUT_PULLUP);
  }
  
pinMode(Bouton_Urgence, INPUT_PULLUP); 
pinMode(Bouton_Rideau, INPUT_PULLUP); 

Serial.begin(9600);
Serial.println("Ready");
}
 
void loop(){

 
  
  
//////////////////////////////////////////////////////////////////////////////////////////// Porte i
  
  for (int i = 0; i < 8; i++)
  { 
    
if (!digitalRead(bouton[i]) == HIGH){
      DmxMaster.write(ch[i], vo[i]);
      DmxMaster.write(ch[i]+1, 255);
      DmxMaster.write(ch[i]+2, 255);
      //Serial.print("Ouverture porte  ");
      //Serial.println(i+1);
      //Serial.println(ch[i]);
      //Serial.println(ch[i]+1);
      //Serial.println(ch[i]+2);


    }
  
else {

      DmxMaster.write(ch[i], vf[i]);
      DmxMaster.write(ch[i]+1, 0);
      DmxMaster.write(ch[i]+2, 0);
     // Serial.print("Fermeture porte  ");
    //  Serial.println(dmx1, dmx2,dmx3);


}

if (!digitalRead(capteur[i]) == HIGH && !digitalRead(bouton[i]) == LOW){
      DmxMaster.write(ch[i], voc[i]);
      DmxMaster.write(ch[i]+1, pc[i]);
      DmxMaster.write(ch[i]+2, 255);
      Serial.print("Capteur Porte ");
      Serial.println(i+1);


  }
  }

  
if (!digitalRead(Bouton_Urgence) == LOW){
      
      DmxMaster.write(1, 255);
      DmxMaster.write(2, 255);
      DmxMaster.write(3, 255);
      Serial.println("Ouverture URGENCE porte 1");
      Serial.println("");
  
      DmxMaster.write(4, 255);
      DmxMaster.write(5, 255);
      DmxMaster.write(6, 255);
      Serial.println("Ouverture URGENCE porte 2");
      Serial.println("");
      
      DmxMaster.write(7, 255);
      DmxMaster.write(8, 255);
      DmxMaster.write(9, 255);
      Serial.println("Ouverture URGENCE porte 3");
      Serial.println("");
      
      DmxMaster.write(10, 255);
      DmxMaster.write(11, 255);
      DmxMaster.write(12, 255);
      Serial.println("Ouverture URGENCE porte 4");
      Serial.println("");
      
      DmxMaster.write(13, 255);
      DmxMaster.write(14, 255);
      DmxMaster.write(15, 255);
      Serial.println("Ouverture URGENCE porte 5");
      Serial.println("");
  
      DmxMaster.write(16, 255);
      DmxMaster.write(17, 255);
      DmxMaster.write(18, 255);
      Serial.println("Ouverture URGENCE porte 6");
      Serial.println("");
      
      DmxMaster.write(19, 255);
      DmxMaster.write(20, 255);
      DmxMaster.write(21, 255);
      Serial.println("Ouverture URGENCE porte 7");
      Serial.println("");
      
      DmxMaster.write(22, 255);
      DmxMaster.write(23, 255);
      DmxMaster.write(24, 255);
      Serial.println("Ouverture URGENCE porte 8");
      Serial.println("");
      delay(45000);  // Attention DELAY le programme ne fera rien d'autre.
  }

if (!digitalRead(Bouton_Rideau) == HIGH){
      
      DmxMaster.write(25, voR);
      DmxMaster.write(26, 255);
      DmxMaster.write(27, 255);
      //Serial.println("Ouverture Rideau");
      //Serial.println("");
}
else {
  
      DmxMaster.write(25, vfR);
      DmxMaster.write(26, 0);
      DmxMaster.write(27, 0);
}
  
 }
