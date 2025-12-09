#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
    int fd, pos;
    char buff[11];     // +1 for safety (null termination not required)

    fd = open("seeking", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // Move pointer to 10th byte (index 10)
    pos = lseek(fd, 10, SEEK_SET);
    printf("Pointer is at %d position\n", pos);

    // Read 10 characters from 10th position
    read(fd, buff, 10);
    
    // Write these 10 characters to screen
    write(1, buff, 10);

    close(fd);
    return 0;
}
