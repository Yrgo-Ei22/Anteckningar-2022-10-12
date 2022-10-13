/********************************************************************************
* header.h: Innehåller diverse definitioner, funktionsdeklarationer med mera.
*           UL = Unsigned Long, dvs. 32-bitars osignerad heltalsdatatyp.
*           Att den är osignerad innebär att den bara kan lagra natural tal,
*           vilket är upp till ca 4.2 miljarder, mer än tillräckligt för en
*           klockfrekvens på 16 MHz.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

/* Klockfrekvens: */
#define F_CPU 16000000UL /* Definierar klockfrekvensen till 16 MHz. */

/* Inkluderingsdirektiv: */
#include <avr/io.h>     /* Innehåller information om I/O-register, såsom DDRB, PORTB. */
#include <util/delay.h> /* Innehåller funktionalitet för generering av fördröjning. */

/* Fixa makron för lysdioderna och tryckknappen: */
#define LED1 0    /* Lysdiod 1 ansluten till pin 8 / PORTB0. */
#define LED2 1    /* Lysdiod 2 ansluten till pin 9 / PORTB1. */
#define LED3 2    /* Lysdiod 2 ansluten till pin 10 / PORTB2. */
#define BUTTON1 5 /* Tryckknapp 1 ansluten till pin 13 / PORTB5. */

#define LED1_ON PORTB |= (1 << LED1) /* Tänder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2) /* Tänder lysdiod 2. */
#define LED3_ON PORTB |= (1 << LED3) /* Tänder lysdiod 3. */

#define LED1_OFF PORTB &= ~(1 << LED1) /* Släcker lysdiod 1. */
#define LED2_OFF PORTB &= ~(1 << LED2) /* Släcker lysdiod 2. */
#define LED3_OFF PORTB &= ~(1 << LED3) /* Släcker lysdiod 3. */

#define LEDS_ON PORTB |= ((1 << LED1) | (1 << LED2) | (1 << LED3))   /* Tänder alla lysdioder. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) /* Släcker alla lysdioder. */

#define BUTTON1_IS_PRESSED ((PINB & (1 << BUTTON1)) != 0) /* Indikerar nedtryckning av tryckknapp 1. */

#endif /* HEADER_H_ */