/*
 * evaluate.c
 *
 *  Created on: feb 6, 2020
 *      Author: hazem ebrahim
 */

#include "evaluate.h"



sint64_t evaluate(uint8_t* expression){
uint16_t counter;
uint16_t counter2=0;
uint16_t counter3=0;
uint8_t string[1000]={0};
uint8_t string2[1000]={0};
ST_queueInfo queue1;
createQueue(&queue1,strlen(expression));
sint64_t ret=0;
sint64_t sum=0;
uint8_t num=0;
for(counter=0;counter<strlen(expression);counter++){
     if((expression[counter]=='{')||(expression[counter]=='[')||(expression[counter]=='(')){

            string[counter2]=expression[counter];

            counter2++;
        }
        else if((expression[counter]=='}')||(expression[counter]==']')||(expression[counter]==')'))
{

 string[counter2]=expression[counter];
            counter2++;
}
else{
         string2[counter3]=expression[counter];
          counter3++;

}
}
 if(checkForBalancedParantheses(expression)==not_balnced){
    printf("the Parantheses is not balnced\n");
 }
else{

for(counter=0;string2[counter]!='\0';counter++){
    enqueue(&queue1,string2[counter]);}


while((front(&queue1)!='+')&&(front(&queue1)!='-')&&(front(&queue1)!='/')&&(front(&queue1)!='*')){
    num=dequeue(&queue1);
    num-=48;
    sum=(sum*10)+num;
}
ret=sum;
sum=0;
while(queueisEmpty(&queue1)==notempty){

    switch (dequeue(&queue1)){
    case '+':
             while((front(&queue1)!='+')&&(front(&queue1)!='-')&&(front(&queue1)!='/')&&(front(&queue1)!='*')&&(queueisEmpty(&queue1)==notempty)){
                  num=dequeue(&queue1);
                  num-=48;
                  sum=(sum*10)+num;
                   }
             ret+=sum;
             sum=0;
              break;
    case '-':
              while((front(&queue1)!='+')&&(front(&queue1)!='-')&&(front(&queue1)!='/')&&(front(&queue1)!='*')&&(queueisEmpty(&queue1)==notempty)){
                  num=dequeue(&queue1);
                  num-=48;
                  sum=(sum*10)+num;
                   }
             ret-=sum;
             sum=0;
              break;
    case '*':
              while((front(&queue1)!='+')&&(front(&queue1)!='-')&&(front(&queue1)!='/')&&(front(&queue1)!='*')&&(queueisEmpty(&queue1)==notempty)){
                  num=dequeue(&queue1);
                  num-=48;
                  sum=(sum*10)+num;
                   }
             ret*=sum;
             sum=0;
              break;
    case '/':
              while((front(&queue1)!='+')&&(front(&queue1)!='-')&&(front(&queue1)!='/')&&(front(&queue1)!='*')&&(queueisEmpty(&queue1)==notempty)){
                  num=dequeue(&queue1);
                  num-=48;
                  sum=(sum*10)+num;
                   }
             ret/=sum;
             sum=0;
             break;

    default:

             break;
    }


}




}




return ret;
}
