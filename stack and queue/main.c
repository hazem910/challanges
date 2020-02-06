#include <stdio.h>
#include <stdlib.h>
#include "stach.h"
int main()
{
   ST_stackInfo st1;
createStack(&st1,30);
   push(&st1, 10);
    push(&st1, 20);
    push(&st1, 30);

    printf("%i popped from stack\n", pop(&st1));
      printf("%i popped from stack\n", pop(&st1));

return 0;
}
