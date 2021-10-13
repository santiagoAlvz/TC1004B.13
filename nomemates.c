#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle(int numsignal){
    printf("Jajajajaj %d\n", numsignal);
}

int main(){
    signal(2,handle);
    while(1){
        printf("Trabajando\n");
        sleep(1);
    }
}