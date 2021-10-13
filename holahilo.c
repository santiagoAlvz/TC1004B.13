#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10000

void *printHola(void *arg){
    char *p = (char *)arg;
    printf("Hola desde hilo %s\n",p);
    pthread_exit(NULL);
}

int saldo = 0;
pthread_mutex_t lockSaldo = PTHREAD_MUTEX_INITIALIZER;

void * suma100(void *arg){
    int lsaldo;

    pthread_mutex_lock(&lockSaldo);
    lsaldo = saldo;
    lsaldo += 100;
    saldo = lsaldo;
    pthread_mutex_unlock(&lockSaldo);

    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    char *s = "Soy un hilo";
    for(int i = 0; i < NUM_THREADS; i++){
        pthread_create(&threads[i],NULL,suma100,NULL);
    }

    for(int i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i],NULL);
    }

    printf("El saldo final es %d\n",saldo);
    pthread_exit(NULL);
}