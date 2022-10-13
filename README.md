# Anteckningar 2022-10-12
Implementering av litet inbyggt system innehållande digitala in- och utportar i form av lysdioder och tryckknappar.

Filen repetition.c innehåller en repetitionsuppgift, som demonstrerar lagring av resultet vid beräkning via returvärde jämfört med
lagring på en designerad adress.

Filen header.h innehåller diverse definitioner och inkluderingsdirektiv för ett inbyggt system innehållande tre lysdioder
anslutna till pin 8 - 10 samt en tryckknapp ansluten till pin 13.

Filen main.c innehåller implementeringen av programmet. I detta fall implementeras all kod i main, 
men kan med fördel delas in i ett fåtal funktioner för att initiera I/O-portarna, blinka samt släcka lysdioderna.
