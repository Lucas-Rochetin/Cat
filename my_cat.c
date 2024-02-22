#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int my_cat(char* file_name){
    int fd = open(file_name, O_RDONLY);
    int read_size = 0;
    char buffer[1];
    read_size = read(fd, buffer, 1);
    while (read_size == 1) {
        write(STDOUT_FILENO, buffer, read_size); 
        read_size = read(fd, buffer, 1);
        }
    close(fd);
}

int main(int argc, char **argv){
    int index;

    for (index = 1; index < argc; index++){
        my_cat(argv[index]);
    }
}
