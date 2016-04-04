;; This buffer is for notes you don't want to save, and for Lisp evaluation.
;; If you want to create a file, visit that file with C-x C-f,
;; then enter the text in that file's own buffer.

#include <pthread.h>

#define MAX_QUEUE_SIZE 20
typedef struct queue{
	int element[MAX_QUEUE_SIZE];
	uint8_t head;
	uint8_t tail;
	uint8_t remaining_elements;
	//additional var here
} prod_cons_queue;

void queue_initialize (prod_cons_queue *q){
	for(int = 0;i< 20;i++){
		element[i] = null;
	}
	head = tail = 0;
	remaining_elements = 0;
}

void queue_add( prod_cons_queue *q, int element);
int queue_remove( prod_cons_queue *q);

void queue_add( prod_cons_queue *q, int element){
	q[q.tail + 1]
}


void queue_remove( prod_cons_queue *q){
	
}
