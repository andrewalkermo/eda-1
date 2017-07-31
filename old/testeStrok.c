#include <stdio.h>
#include <string.h>

int main(void) {
const char* lineConst = "This .is an. example"; // the "input string"
char line[256];  // where we will put a copy of the input
char *subString; // the "result"

strcpy(line, lineConst);

subString = strtok(line,"."); // find the first double quote
subString=strtok(NULL,".");   // find the second double quote

printf("the thing in between quotes is '%s'\n", subString);
}
