#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 99999

void postfix(char recur[][100], char E_base[][100], char D_base[][100], int d_base_count, int e_base_count, int max_length);

int main(int argc, char* argv[]) {

    char str[MAX_LEN];
    char *ptr;
    char E_base[3000][100];
    char D_base[3000][100];
    char recur[100][100];
    char str2[100];
    char ptr2[100];
    int recur_count = 0;
    int e_base_count = 0;
    int d_base_count = 0;
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
            if(strcmp(ptr, "E") != 0 && strcmp(ptr, "S") != 0 && strcmp(ptr, "D") != 0) 
            {
                for(int i = 0 ; i < strlen(ptr) ; i++) {
                    if(ptr[i] == '\"') continue;
                    ptr2[ptr_count++] = ptr[i];
                }
                if(ptr2[1] == 'E' || ptr2[0] == 'E') strcpy(recur[recur_count++],ptr2);
                else if(atoi(ptr2) != 0) strcpy(E_base[e_base_count++], ptr2);
                else strcpy(D_base[d_base_count++], ptr2);
            }
            ptr = strtok(NULL, ":==");
        }
        str_count = 0;
        ptr_count = 0;
    }

    postfix(recur, E_base, D_base, e_base_count, d_base_count, atoi(argv[2]) );
    printf("GOOD JOB!\n");
    return 0;
}

void postfix(char recur[][100], char E_base[][100], char D_base[][100], int e_base_count, int d_base_count, int max_length) {
    
    int new_e_base_count = 0;
    int new_d_base_count = 0;
    char new_E_base[3000][100];
    char new_D_base[3000][100];
    printf("GOOD JOB!\n");

    for(int j = 0 ; j < 8 ; j++) {
        for(int i = 0 ; i < e_base_count ; i++) {
            char* recur_one = malloc(sizeof(char) * 1000);
            strcpy(recur_one, recur[j]);
            int len = strlen(recur_one);

            while(strstr(recur_one, "E") != NULL) {
                char* ptr = strstr(recur_one, "E");
                if(strcmp(ptr, "ED") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    recur_one[strlen(E_base[i])+1] = 'D';
                    strcpy(new_E_base[new_e_base_count++], recur_one);
                }

                if(strcmp(ptr, "E1D") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    recur_one[strlen(E_base[i])] = '1';
                    recur_one[strlen(E_base[i]) + 1] ='D';
                    strcpy(new_E_base[new_e_base_count++], recur_one);
                } 
                if(strcmp(ptr, "E2D") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    recur_one[strlen(E_base[i])] = '2';
                    recur_one[strlen(E_base[i]) + 1] ='D';
                    strcpy(new_E_base[new_e_base_count++], recur_one);
                } 
                if(strcmp(ptr, "E3D") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    recur_one[strlen(E_base[i])] = '3';
                    recur_one[strlen(E_base[i]) + 1] ='D';
                    strcpy(new_E_base[new_e_base_count++], recur_one);
                } 
                if(strcmp(ptr, "E4D") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    recur_one[strlen(E_base[i])] = '4';
                    recur_one[strlen(E_base[i]) + 1] ='D';
                    strcpy(new_E_base[new_e_base_count++], recur_one);
                } 
            }
        }
    }



    for(int i = 0 ; i < new_e_base_count ; i++) {
        for(int j = 0 ; j < d_base_count ; j++) {
            char *recur_one = malloc(sizeof(char) * 100);
            strcpy(recur_one, new_E_base[i]);
            int len = strlen(recur_one);

            while(strstr(recur_one, "D") != NULL) {
                char* ptr = strstr(recur_one, "D");
                strncpy(ptr, D_base[j], strlen(D_base[j]));
                strcpy(new_D_base[new_d_base_count++], recur_one); 
            }
        }
    }
    int count =0 ;
    for(int i = 0 ; i < new_d_base_count ; i++) {
        printf("[ %s ]", new_D_base[i]);
        count++;
    }

    postfix(recur, new_D_base, D_base, new_d_base_count, d_base_count, max_length);

}
