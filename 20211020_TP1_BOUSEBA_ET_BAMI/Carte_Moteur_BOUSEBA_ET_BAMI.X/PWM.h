
#ifndef PWM_H
#define	PWM_H
#define MOTEUR_DROITE 0
#define MOTEUR_GAUCHE 1
void InitPWM(void);
void PWMSetSpeed(float vitesseEnPourcents, unsigned char nbMotor);
#endif	/* PWM_H */

