#include "check_balanced.h"



int main(){
char s1[1000];
printf("please enter the string \n");
scanf("%s",s1);
if(checkForBalancedParantheses(s1)){
    printf("balnced\n");
}
else{
    printf("notbalnced\n");
}



return 0;
}

