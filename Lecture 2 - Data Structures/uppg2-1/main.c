#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include "stack.h"

int main(void){
 push('H');
 push('�');
 push('k');
 push('a');
 push('n');
 while(!isempty())
   printf("%c",pop());
}
