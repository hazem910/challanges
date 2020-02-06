
#include "check_balanced.h"
uint8_t matching_brackets(char l,char r){
    uint8_t ret=notmatched;
if(((l=='{'&&r=='}'))||((l=='[')&&(r==']'))||((l=='(')&&(r==')')))
{
    ret=matched;

}

return ret;
}

uint8_t checkForBalancedParantheses(uint8_t* expression){
uint8_t counter;
uint8_t ret=balnced;
ST_stackInfo st1;
createStack(&st1,sizeof(expression));
for(counter=0;counter<sizeof(expression)*4;counter++){
    if((expression[counter]=='{')||(expression[counter]=='[')||(expression[counter]=='(')){
        push(&st1,expression[counter]);
       }
    else if ((expression[counter]=='}')||(expression[counter]==']')||(expression[counter]==')'))
    {
        if(isEmpty(&st1)==empty){
            ret=not_balnced;
            break;
        }
        else if(matching_brackets(peek(&st1),expression[counter])==notmatched){
                ret=not_balnced;
                break;

        }
        else{
            pop(&st1);
        }

    }

}
 if(isEmpty(&st1)==notempty){
        ret=not_balnced;
    }


    return ret;
}








