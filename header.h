/********************************************************************************
* header.h: Inneh�ller diverse definitioner, funktionsdeklarationer med mera.
*           UL = Unsigned Long, dvs. 32-bitars osignerad heltalsdatatyp.
*           Att den �r osignerad inneb�r att den bara kan lagra natural tal,
*           vilket �r upp till ca 4.2 miljarder, mer �n tillr�ckligt f�r en
*           klockfrekvens p� 16 MHz.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Klockfrekvens: */
#define F_CPU 16000000UL /* Definierar klockfrekvensen till 16 MHz. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>     /* Inneh�ller information om I/O-register, s�som DDRB, PORTB. */
#include <util/delay.h> /* Inneh�ller funktionalitet f�r generering av f�rdr�jning. */

/* Fixa makron f�r lysdioderna och tryckknappen: */
#define LED1 0    /* Lysdiod 1 ansluten till pin 8 / PORTB0. */
#define LED2 1    /* Lysdiod 2 ansluten till pin 9 / PORTB1. */
#define LED3 2    /* Lysdiod 2 ansluten till pin 10 / PORTB2. */
#define BUTTON1 5 /* Tryckknapp 1 ansluten till pin 13 / PORTB5. */

#define LED1_ON PORTB |= (1 << LED1) /* T�nder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2) /* T�nder lysdiod 2. */
#define LED3_ON PORTB |= (1 << LED3) /* T�nder lysdiod 3. */

#define LED1_OFF PORTB &= ~(1 << LED1) /* Sl�cker lysdiod 1. */
#define LED2_OFF PORTB &= ~(1 << LED2) /* Sl�cker lysdiod 2. */
#define LED3_OFF PORTB &= ~(1 << LED3) /* Sl�cker lysdiod 3. */

#define LEDS_ON PORTB |= ((1 << LED1) | (1 << LED2) | (1 << LED3))   /* T�nder alla lysdioder. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) /* Sl�cker alla lysdioder. */

#define BUTTON1_IS_PRESSED ((PINB & (1 << BUTTON1)) != 0) /* Indikerar nedtryckning av tryckknapp 1. */

#endif /* HEADER_H_ */