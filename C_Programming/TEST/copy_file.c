#include<stdio.h>

#define SOURCE_FILE "data.txt"
#define DEST_FILE "data2.txt"

int main() {

    char value = '0';

    FILE *s = fopen(SOURCE_FILE, "r");
    FILE *d = fopen(DEST_FILE, "w");

    while(1) {
        int ret = fscanf(s, "%c", &value);
        if(ret == EOF)
            break;
        fprintf(d, "%c", value);
    }

    fclose(s);
    fclose(d);

    return 0;
}