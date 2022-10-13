/********************************************************************************
* main.c: Implementering med blinkning av lysdioder anslutna till pin 8 - 10
*         via en tryckknapp anslutna till pin 13. Vid nedtryckning blinkar
*         lysdioderna fram�t i en slinga (fr�n pin 8 - 10). Annars h�lls de 
*         sl�ckta. I detta fall implementeras all kod i main, men kan med f�rdel 
*         delas in i ett f�tal funktioner f�r att initiera I/O-portarna, 
*         blinka samt sl�cka lysdioderna.
********************************************************************************/
#include "header.h"

/********************************************************************************
* main: Implementerar i detta fall all funktionalitet direkt i denna funktion.
*       F�rst s�tts lysdioderna till utportar genom att ettst�lla motsvarande
*       bitar i datariktningsregister DDRB. Sedan aktiveras den interna 
*       pullup-resistorn p� tryckknappens pin f�r att se till att insignalen
*       alltid blir h�g (1) eller l�g (0), annars hamnar denna i ett flytande
*       tillst�nd mellan 0 - 1, som inom digitalteknik kallas tri-state.
* 
*       Sedan sker avl�sning av tryckknappens insignal kontinuerligt. Vid
*       nedtryckning blinkar lysdioderna i en slinga, annars h�lls de sl�ckta.
********************************************************************************/
int main(void)
{
   DDRB = ((1 << LED1) | (1 << LED2) | (1 << LED3)); 
   PORTB = (1 << BUTTON1);

   while (1) 
   {
      if (BUTTON1_IS_PRESSED) 
      {
         LED1_ON; 
         _delay_ms(100); 

         LED1_OFF;
         LED2_ON;
         _delay_ms(100); 


         LED2_OFF;
         LED3_ON;
         _delay_ms(100); 

         LED3_OFF; 
      }
      else
      {
         LEDS_OFF;
      }
      
   }

   return 0;
}

