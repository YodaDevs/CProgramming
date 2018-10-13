#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

char notcase(char c){
       if((c >= 'A') && (c <= 'Z'))
           return 'a' + (c - 'A');
        
       return c;
}

void strncase (char* s){
   while(*s != '\0'){

       *s = notcase(*s);
       s++;
   }
}