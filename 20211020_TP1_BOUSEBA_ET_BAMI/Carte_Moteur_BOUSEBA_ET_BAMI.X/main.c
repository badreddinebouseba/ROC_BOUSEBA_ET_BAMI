/* 
 * File:   main.c
 * Author: TABLE 6
 *
 * Created on 20 octobre 2021, 10:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "IO.h"
#include "IO.h"
#include "timer.h"
#include "PWM.h"



int main (void){
/***************************************************************************************************/
//Initialisation de l?oscillateur
/****************************************************************************************************/
InitOscillator();

/****************************************************************************************************/
// Configuration des entrées sorties
/****************************************************************************************************/
InitIO();
InitPWM();
PWMSetSpeed(40);


LED_BLANCHE = 1;

LED_BLEUE = 1;

LED_ORANGE = 1;
InitTimer23();
InitTimer1();
/****************************************************************************************************/
// Boucle Principale
/****************************************************************************************************/
while(1){
    //LED_BLANCHE=!LED_BLANCHE;
    
} // fin main
}
