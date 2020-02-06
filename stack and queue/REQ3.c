#include "qeue.h"


int main(){

ST_queueInfo queue1;
createQueue(&queue1,50);
enqueue(&queue1, 10);
enqueue(&queue1, 20);
enqueue(&queue1, 30);
enqueue(&queue1, 40);
printf("%d dequeued from queue\n\n", dequeue(&queue1));



return 0;
}
