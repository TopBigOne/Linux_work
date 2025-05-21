#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "my_bio.h"




void bio_init_buffer(){


}

int bio_open(){
    fd_io = open(FILE_PATH,O_RDONLY);
        if(fd_io==-1){
            perror("open file in failure.");
            return -1;
        }
    return 0;

}

int bio_read(){
    if(fd_io<=-1){
        perror(" pls open file first.");
        return -1;
    }
    ssize_t read_size = read(fd_io,buf,sizeof (buf));

    if(read_size==-1){
        perror(" read failed");
        return -1;
    }
    // now i can show the read result...
    //printf("Read %zd bytes: %s.*s\n",read_size,(int)read_size,buf);
    printf("Read %zd bytes: %.*s\n", read_size, (int)read_size, buf);
    return 0;

}

int bio_close(){
    close(fd_io);

}
void test();
void test(){
    bio_open();
    bio_read();
    bio_close();

}


int main(void) {
    test();
    return 0;
}
