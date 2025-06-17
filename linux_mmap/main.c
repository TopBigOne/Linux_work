#include <stdio.h>

#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include <unistd.h>
#include <string.h>
#include <sys/mman.h>

void test_mmap();

void test_mmap() {

    const char  *file_name = "/Users/dev/Documents/Linux_work/linux_mmap/doc/yan.txt";
    const char  *message   = " hello ,----- mmap world !";
    int         fd;
    char        *mapped;
    struct stat sb;
    fd = open(file_name, O_RDWR | O_CREAT, (mode_t) 0600);
    if (fd == -1) {
        perror("open");
        return;
    }

    if (ftruncate(fd, strlen(message)) == -1) {
        perror("ftruncate");
        close(fd);
        exit(EXIT_FAILURE);
    }
    // 3. 获取文件大小
    if (fstat(fd, &sb)) {
        perror("fstat");
        close(fd);
        exit(EXIT_FAILURE);
    }
    // 4. 映射文件到内存
    mapped = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped == MAP_FAILED) {

        perror("mmap");
        close(fd);
        exit(EXIT_FAILURE);
    }
    // 5. 写入文件到内存映射区域
    strncpy(mapped, message, sb.st_size);
    // 6. 确保数据写入磁盘
    if (msync(mapped, sb.st_size, MS_SYNC) == -1) {
        perror("msync");

    }
    // 7.解除映射
    if (munmap(mapped, sb.st_size) == -1) {
        perror("munmap");
    }
    // 8. 关闭文件
    close(fd);

}

int main() {
    test_mmap();
    return 0;
}
