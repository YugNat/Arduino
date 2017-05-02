//**************************************************************
//Commande de moteur pas-à-pas unipolaire 4 fils
//tiptopboards.com 05/12/2013
// Driver ULN2003 et moteur réducté au 1:64
//
//**************************************************************
//Inclure la librairie stepper.h
 #include <Stepper.h>
 #define STEPS 64
  
  //Créer une instance de la classe stepper
  //Le moteur (fils 1 2 3 4) est branché sur les sorties 8 9 10 11 de l'Arduino (et sur GND, +V)
  Stepper small_stepper(STEPS, 8, 10, 9, 11);     // Sens horaire
  
  //Stepper small_stepper(STEPS, 11, 10, 9, 8);  // Sens anti-horaire en inversant 8 et 11 (si on préfère)
  int  Steps2Take = 0;  //Nombre de pas de rotation demandé au moteur
  long temps =0;          //Durée de rotation pour un tour
  //************************************************************
  // Pour un moteur de ce type : http://tiptopboards.com/151-moteur-pas-%C3%A0-pas-r%C3%A9duct%C3%A9-de-5v-4-fils-driver-.html
  // 64 pas par tour, 4 phases, angle de 5.625° selon les spécifications du moteur
  // Démultiplication 1:64 pour ce moteur réducté mécaniquement
  //   360° / 5.625° * 64 = 4096 angles avec la démultiplication 
  //   360° / 5.625° * 64  * 4 bobines / 2 bipolaire = 2048 step / tour
  

void setup() 
 {                
  Serial.begin(9600);     // 9600 bps
  Serial.println("Test de moteur pas a pas");  
  }

void loop() 
  {
  Serial.println("Moteur en marche ");  
  //Faire tourner le moteur
  small_stepper.setSpeed(10); //Vitesse de 300 (max) réduire ce chiffre pour un mouvement plus lent
  //100 permet d'éavoir un couple élevé >300 le moteur vibre sans tourner
  
  Steps2Take  = 2048;  // Une rotation complète avec 2048 pas (1 tour environ 4.5sec)
  //Pour tourner à l'envers de 6 fois 1/30eme de tour, simplement multiplier Steps2Take par 6/30 et mettre un moins pour inverser le sens
  // Exemple  Steps2Take  = -6*2048/30;
  temps = millis();
  small_stepper.step(Steps2Take);  //Ca tourne
  temps =  millis()- temps ;  //Chronomètre un rour complet  6.236 sec par tour à vitesse 200
  Serial.println(temps);      //Affiche le temps (en ms) pour un tour complet
  delay(2000);  //pause
 }
