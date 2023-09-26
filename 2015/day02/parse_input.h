#ifndef PARSE_INPUT_H_
#define PARSE_INPUT_H_
struct Solution {
 int part1;
 int part2;
};

struct Solution calculateDimensions(char *inputFileName);
int countLines(char *inputFileName);
#endif // PARSE_INPUT_H_
