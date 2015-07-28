#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include "stack.h"

int main(void){
  int i,tal,*pek;

  InitStack(sizeof(int),1000);
  for(i=0;i<1000;i++){
    tal=rand()%100+1;
    if(tal>=50)
      Push(&tal);
  }
  while(!IsEmpty()){
    pek=(int *)Pop();
    tal=*pek;
    printf("%4d",tal);
  }
  printf("\n");
  //getch();
}
