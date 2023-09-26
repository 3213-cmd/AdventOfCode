#include "parse_input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINESIZE 255


struct Solution calculateDimensions(char *inputFileName) {
     int l,h,w, lw, wh, hl, slack, totalArea = 0, bow, totalRibbon = 0;
     const char delimiter[2] = "x";
     char *currentLine;
     FILE *fp = fopen(inputFileName, "r");
     currentLine = malloc(MAXLINESIZE);

     while (fgets(currentLine, MAXLINESIZE , fp)) {
         l = atoi(strtok(currentLine, delimiter));
         w = atoi(strtok(NULL, delimiter));
         h = atoi(strtok(NULL, delimiter));
         lw = l*w;
         wh = w*h;
         hl = h*l;
         if (lw <= wh && lw <= hl) slack = lw;
         if (wh <= lw && wh <= hl) slack = wh;
         if (hl <= wh && hl <= lw) slack = hl;
         totalArea += (2*lw + 2*wh + 2*hl + slack);
         /* part2 */
         /* Reusing the variables: lw,wh,hl are now the perimeter instead of the surface are */
         /* slack is the ribbon needed  (without the bow) */
         bow = l*w*h;
         lw = (l+l+w+w);
         wh = (w+w+h+h);
         hl = (h+h+l+l);
         if (lw <= wh && lw <= hl) slack = lw;
         if (wh <= lw && wh <= hl) slack = wh;
         if (hl <= wh && hl <= lw) slack = hl;
         totalRibbon+= bow+slack;

     }
     struct Solution result = {totalArea, totalRibbon};
     return result;
}


/* Not Used Anymore */
int countLines(char *inputFileName) {
 char currentChar;
 int lines = 0;
 FILE *fp = fopen(inputFileName, "r");
 for (currentChar = getc(fp); currentChar!= EOF; currentChar = getc(fp)) {
     if (currentChar=='\n') {
         lines++;
     }
 }
 return lines;
}
