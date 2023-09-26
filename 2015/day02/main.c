#include <stdio.h>
#include "parse_input.h"
int main() {
   // printf() displays the string inside quotation
   int lines;
   struct Solution result;
   /* lines = countLines("input.txt"); */
   result = calculateDimensions("input.txt");
   printf("The result for part one is: %i\n", result.part1);
   printf("The result for part two is: %i\n", result.part2);
   return 0;
}
