#include <unistd.h>
#include <ctype.h>

int main(){
    char c, may;
    read(STDIN_FILENO,&c,1);
    may = toupper(c);
    write(STDOUT_FILENO,&may,1);
    return 0;
}