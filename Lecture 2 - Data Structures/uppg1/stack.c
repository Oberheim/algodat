static char stack[30];
static int plats=-1;

void push(char t){
  stack[++plats]=t;
}

char pop(void){
  return stack[plats--];
}

int isempty(void){
  return plats==-1;
}

int isfull(void){
  return plats==29;
}

