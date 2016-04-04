;; This buffer is for notes you don't want to save, and for Lisp evaluation.
;; If you want to create a file, visit that file with C-x C-f,
;; then enter the text in that file's own buffer.

#include <pthread.h>

#define MAX_QUEUE_SIZE 20

pthread_mutex_t mutex;

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
	pthread_mutex_lock(mutex);
	if(q->remaining_elements == 20){	
		if(tail < 19){
			q->element[q->tail + 1] = element;
			q->tail ++;
		}else{
			q->element[0] = this.element;
			q->tail = 0;
		}
		q->remaining_elements ++;
	}
	pthread_mutex_unlock(mutex);
}


void queue_remove( prod_cons_queue *q){
	pthread_mutex_lock(mutex);
	if(q->remaining_elements != 0){
		q->head += 1;
		remaining_elements -= 1;
	}
	pthread_mutex_unlock(mutex);
}

void* producer(void *ptr){
	
}

void* consumer(void *ptr){
	
}


