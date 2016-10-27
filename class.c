#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int randomint() {
    int x = open("/dev/random", O_RDONLY);
    int random;
    read(x, &random, 4);
    close(x);
    return random;
}

int main() {
    //Populating Array.
    int randnumarr[10];
    int x = 0;
    int temp = 0;
    for (; x < 10; x++) {
        temp = randomint();
        randnumarr[x] = temp;
        printf("Random Int %d: %u\n", x, temp);
    }
    //Writing Array to a file. No loops.
    printf("\nWriting numbers into file...\n\n");
    umask(0000);
    int f = open("./arrfile", O_CREAT|O_RDWR|O_TRUNC, 0666);
    write(f, &randnumarr, 40);


    //Read File into a Different Array. No loops.
    printf("Reading File into new array...\n\n");
    int newrandnumarr[10];
    //loop through here, read 4 bytes at a time.
    close(f);
    f = open("./arrfile", O_RDWR, 0666);
    read(f, &newrandnumarr, 40);

    //Print New Array
    printf("Verification that written values are the same...\n");
    x = 0;
    for (; x < 10; x++) {
        printf("Int %d: %u\n", x, newrandnumarr[x]);
    }
    return 0;
}
