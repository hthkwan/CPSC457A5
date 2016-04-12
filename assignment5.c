//Remember to change "prod_cons_queue" to the actual name of the queue

#include <pthread.h>
#include <stdint.h>

#define MAX_QUEUE_SIZE 20

pthread_mutex_t mutex;
pthread_cond_t condc, condp;

typedef struct queue{
	int element[MAX_QUEUE_SIZE];
	uint8_t head;
	uint8_t tail;
	uint8_t remaining_elements;
	//additional var here
	int waiting;
} prod_cons_queue;

typedef struct vars{
	prod_cons_queue *q;
	int pid;
} vars;

int main(){

	return 0;
}

void queue_initialize (prod_cons_queue *q){
	for(int i = 0;i< 20;i++){
		q -> element[i] = NULL;
	}
	(q -> head) = (q -> tail) = 0;
	q -> remaining_elements = 0;
	q -> waiting = 0;
}

void queue_add( prod_cons_queue *q, int element){
	if(q->remaining_elements == 20){
		//is this supposed to be remaining_elements or tail?
		if(q->tail < 19){
			q->element[q->tail + 1] = element;
			q->tail ++;
		}else{
			q->element[0] = element;
			q->tail = 0;
		}
		q->remaining_elements ++;
	}

}

void queue_remove( prod_cons_queue *q){
	if(q->remaining_elements != 0){
		if(q->head < 19){
			q->head += 1;
			q->remaining_elements -= 1;
		}else{
			q->head = 0;
			q->remaining_elements -= 1;
		}

	}
}

void* producer(void *ptr){
	int msgs = 10;
	for(int i = 0;i<msgs;i++){
		pthread_mutex_lock(&mutex);
		if(((vars *)ptr)->q->remaining_elements == 20){
			((vars *)ptr)->q->waiting += 1;
			pthread_cond_wait(&condp, &mutex);
		}
		((vars *)ptr)->q->waiting -= 1;
		queue_add(((vars *)ptr)->q, ((vars *)ptr)->pid);
		if(((vars *)ptr)->q->remaining_elements == 1)pthread_cond_signal(&condc);
		pthread_mutex_unlock(&mutex);
	}
}

void* consumer(void *ptr){
	int msgs = 0;
	if(((vars *)ptr)->q->remaining_elements == 0){
		((vars *)ptr)->q->waiting += 1;
		pthread_cond_wait(&condc, &mutex);
	}
	((vars *)ptr)->q->waiting -= 1;
	//there are messages in the queue now
	int pid = ((vars *)ptr)->q->element[((vars *)ptr)->q->head];
	printf("This is a message from thread %d", ((vars *)ptr)->pid);
	queue_remove(((vars *)ptr)->q);
	if(((vars *)ptr)->q->remaining_elements == 19) pthread_cond_signal(&condp);
}
