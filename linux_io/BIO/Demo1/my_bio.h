//
// Created by dev on 25-5-21.
//

#ifndef DEMO1_MY_BIO_H
#define DEMO1_MY_BIO_H

int fd_io;

#define FILE_PATH "/home/dev/Documents/Linux_work/linux_io/BIO/Demo1/README.md"
#define BUF_SIZE 1024
char buf[BUF_SIZE];

void bio_init_buffer();
int bio_open();
int bio_read();
int bio_close();
#endif //DEMO1_MY_BIO_H
