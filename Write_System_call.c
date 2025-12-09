#include <unistd.h>

int main()
{
    char buff[20];
    int nread;

    nread = read(0, buff, 10);   // Read 10 bytes from keyboard (stdin)
    write(1, buff, nread);       // Write those bytes to screen (stdout)

    return 0;
}
