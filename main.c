/********************************************************************************
* main.c: Implementering med blinkning av lysdioder anslutna till pin 8 - 10
*         via en tryckknapp anslutna till pin 13. Vid nedtryckning blinkar
*         lysdioderna framåt i en slinga (från pin 8 - 10). Annars hålls de 
*         släckta. I detta fall implementeras all kod i main, men kan med fördel 
*         delas in i ett fåtal funktioner för att initiera I/O-portarna, 
*         blinka samt släcka lysdioderna.
********************************************************************************/
#include "header.h"

/********************************************************************************
* main: Implementerar i detta fall all funktionalitet direkt i denna funktion.
*       Först sätts lysdioderna till utportar genom att ettställa motsvarande
*       bitar i datariktningsregister DDRB. Sedan aktiveras den interna 
*       pullup-resistorn på tryckknappens pin för att se till att insignalen
*       alltid blir hög (1) eller låg (0), annars hamnar denna i ett flytande
*       tillstånd mellan 0 - 1, som inom digitalteknik kallas tri-state.
* 
*       Sedan sker avläsning av tryckknappens insignal kontinuerligt. Vid
*       nedtryckning blinkar lysdioderna i en slinga, annars hålls de släckta.
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

