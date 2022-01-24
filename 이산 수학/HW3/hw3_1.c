#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 99999

void recur_palindrome(char recur[][200], char base[][100], int base_count, int max_length);
void base_palindrome(char base[][100] , int base_count);

int main(int argc, char* argv[]) {

    char str[MAX_LEN];
    char *ptr;
    char base[100][100];
    char recur[100][200];
    char str2[100];
    char ptr2[100];
    int recur_count = 0;
    int base_count = 0;
    int str_count = 0;
    int ptr_count = 0;

    FILE *fp;
    fp = fopen(argv[1], "rt");

    while(!feof(fp)) {
        
        fgets(str, MAX_LEN, fp);
        str[strlen(str)-1] = '\0';

        for(int i = 0 ; i < strlen(str) ; i++) {
            if(str[i] == ' ') {
                continue;
            }
            str2[str_count++] = str[i];
        }
        str[strlen(str)-1] = '\0';
        ptr = strtok(str2, ":==");
        while(ptr != NULL) {
            if(strcmp(ptr, "E") != 0 && strcmp(ptr, "S") != 0) 
            {
                for(int i = 0 ; i < strlen(ptr) - 1 ; i++) {
                    if(ptr[i] == '\"') continue;
                    ptr2[ptr_count++] = ptr[i];
                }
                if(ptr2[1] == 'E') strcpy(recur[recur_count++],ptr2);
                else strcpy(base[base_count++],ptr2);
            }
            ptr = strtok(NULL, ":==");
        }
        str_count = 0;
        ptr_count = 0;
    }
    base_palindrome(base, base_count);
    recur_palindrome(recur, base, base_count, atoi(argv[2]));

    return 0;
}

void recur_palindrome(char recur[][200], char base[][100], int base_count, int max_length) {
    int new_base_count = 0;
    char new_base[100][100];
    int index_E = 0;

    for(int i = 0 ; i < base_count ; i++) {
        for(int k = 0 ; k < 2 ; k++) {
            char recur_one[10];
            strcpy(recur_one, recur[k]);
            int len = strlen(recur_one);

            while(strstr(recur_one, "E") != NULL) {

                char* ptr = strstr(recur_one, "E");
                recur_one[len-1 + strlen(base[i]) - 1] = recur_one[len-1];
                strncpy(ptr, base[i], strlen(base[i]));
                if(strlen(recur_one) > max_length) return;

                if(strstr(recur_one, "E") == NULL) {
                    strcpy(new_base[new_base_count], recur_one); 
                    printf("[ %s ]", new_base[new_base_count++]);
                }
            }
        }
    }
    
    recur_palindrome(recur, new_base, new_base_count, max_length);
}

void base_palindrome(char base[][100], int base_count) {
    printf("[ ANSWER ] \n\n");

    for(int i = 0 ; i < base_count ; i++) {
        printf("[ %s ]", base[i]);
    }
}