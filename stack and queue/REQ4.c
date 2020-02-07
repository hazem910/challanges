#include "evaluate.h"

int main(){
printf("please enter your experssion\n");
uint8_t str1[1000];
scanf("%s",&str1);
printf("the answer is %d\n",evaluate(str1));
}

