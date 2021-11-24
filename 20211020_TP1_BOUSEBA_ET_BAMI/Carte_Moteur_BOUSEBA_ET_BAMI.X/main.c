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
#include "ADC.h"
#include "robot.h"



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
InitTimer23();
InitTimer1();
InitADC1();

/*
PWMSetSpeed(0,MOTEUR_DROITE);
PWMSetSpeed(0,MOTEUR_GAUCHE);
*/

/* LED_BLANCHE = 1;

LED_BLEUE = 1;

LED_ORANGE = 1;
 */

/****************************************************************************************************/
// Boucle Principale
/****************************************************************************************************/
while(1){
    //LED_BLANCHE=!LED_BLANCHE;
    if ( ADCIsConversionFinished() == 1)
    {
        unsigned int * ADCresult = ADCGetResult();
        float ADCValue0 = ADCresult[0];
        float ADCValue1 = ADCresult[1];
        float ADCValue2 = ADCresult[2];
        ADCClearConversionFinishedFlag();
        unsigned int * result = ADCGetResult();
        float volts = ((float) result [2]) * 3.3 / 4096 * 3.2;
        robotState.distanceTelemetreDroit = 34 / volts - 5;
        volts = ((float) result[1]) * 3.3 / 4096 * 3.2;
        robotState.distanceTelemetreCentre = 34 / volts - 5;
        volts = ((float) result[0]) * 3.3 / 4096 * 3.2;
        robotState.distanceTelemetreGauche = 34 / volts - 5;
    
        
        if (ADCValue0 > 348)
        {
            LED_ORANGE = 1;
    }
        else 
        {
            LED_ORANGE = 0;
        
        }
        if (ADCValue1 > 348)
        {
            LED_BLEUE = 1;
        }
        else
        {
            LED_BLEUE = 0;
        }
        if (ADCValue2 > 348)
        {
            LED_BLANCHE = 1;
        }
        else
        {
            LED_BLANCHE = 0;
        }
        
    }
    
    
    }
} // fin main

