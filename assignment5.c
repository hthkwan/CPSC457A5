;; This buffer is for notes you don't want to save, and for Lisp evaluation.
;; If you want to create a file, visit that file with C-x C-f,
;; then enter the text in that file's own buffer.

#include <pthread.h>

#define MAX_QUEUE_SIZE 20

pthread_mutex_t mutex;
pthread_cond_t condc, condp;

typedef struct queue{
	int element[MAX_QUEUE_SIZE];
	uint8_t head;
	uint8_t tail;
	uint8_t remaining_elements;
	//additional var here
} prod_cons_queue;

int main(){
	
	return 0;
}

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

}


void queue_remove( prod_cons_queue *q){
	if(q->remaining_elements != 0){
		if(q->head < 19){
			q->head += 1;
			remaining_elements -= 1;
		}else{
			q->head = 0;
			remaining_elements -= 1;
		}
		
	}
}

void* producer(void *ptr){
	int msgs = 10;
	for(int i = 0;i<msgs;i++){	
		pthread_mutex_lock(&mutex);
		if(prod_cons_queue -> remaining_elements == 20) pthread_cond_wait(&condp, &mutex);
		queue_add(prod_cons_queue, (int)ptr);
		if(prod_cons_queue -> remaining_elements == 1)pthread_cond_signal(&condc);
		pthread_mutex_unlock(&mutex);
	}
}

void* consumer(void *ptr){
	int msgs = 0;
	if(prod_cons_queue ->remaining_elements == 0) pthread_cond_wait(&condc, &mutex);
	//there are messages in the queue now
	int pid = prod_cons_queue -> element[prod_cons_queue -> head];
	printf("This is a message from thread %d", pid);
	queue_remove(prod_cons_queue);
	if(prod_cons_queue -> remaining_elements == 19) pthread_cond_signal(&condp);
}


