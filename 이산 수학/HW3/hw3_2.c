#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 99999

void parenthesis(char recur[][100], char E_base[][100], char D_base[][100], char R_base[][100], 
            int e_base_count, int d_base_count, int r_base_count, int max_length);

int main(int argc, char* argv[]) {

    char str[MAX_LEN];

    char *ptr;
    char E_base[100][100];
    char D_base[100][100];
    char R_base[100][100];
    char recur[100][100];
    char str2[100];
    char ptr2[100];
    int recur_count = 0;
    int e_base_count = 0;
    int d_base_count = 0;
    int r_base_count = 0;

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
            if(strcmp(ptr, "E") != 0 && strcmp(ptr, "S") != 0 && strcmp(ptr, "D") != 0 && strcmp(ptr, "R")) 
            {
                for(int i = 0 ; i < strlen(ptr) ; i++) {
                    if(ptr[i] == '\"') continue;
                    ptr2[ptr_count++] = ptr[i];
                }

                if(ptr2[0] == 'E' || ptr2[1] == 'E' || ptr2[2] == 'E' || 
                    ptr2[0] == 'D' || ptr2[1] == 'D' || ptr2[2] == 'D' ||
                    ptr2[0] == 'R' || ptr2[1] == 'R' || ptr2[2] == 'R') strcpy(recur[recur_count++],ptr2);
                else if(ptr2[0] =='(') strcpy(E_base[e_base_count++], ptr2);
                else if(ptr2[0] =='{') strcpy(D_base[d_base_count++], ptr2);
                else strcpy(R_base[r_base_count++], ptr2);

            }
            ptr = strtok(NULL, ":==");
        }
        str_count = 0;
        ptr_count = 0;
    }

    printf(" %s %s %s\n", E_base[0], D_base[0], R_base[0]);
    parenthesis(recur, E_base, D_base, R_base, e_base_count, d_base_count, r_base_count, atoi(argv[2]));

    return 0;
}

void parenthesis(char recur[][100], char E_base[][100], char D_base[][100], char R_base[][100], 
        int e_base_count, int d_base_count, int r_base_count, int max_length) 
{ 
    int new_e_base_count = 0;
    int new_d_base_count = 0;
    int new_r_base_count = 0;
    char new_E_base[1000][100];
    char new_D_base[1000][100];
    char new_R_base[1000][100];

    for(int j = 0; j < 3 ; j++){
        for(int i = 0 ; i < e_base_count ; i++){
            char* recur_one = malloc(sizeof(char) * 1000);
            strcpy(recur_one, recur[j]);
            int len = strlen(recur_one);

            while(strstr(recur_one, "E") != NULL) {
                char* ptr = strstr(recur_one, "E");
                if(strcmp(ptr, "E()") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    recur_one[strlen(E_base[i])] = '(';
                    recur_one[strlen(E_base[i])+1] = ')';
                    strcpy(new_E_base[new_e_base_count++], recur_one);
                }
                else if(strcmp(ptr, "E)") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    recur_one[strlen(recur_one)] = ')';
                    strcpy(new_E_base[new_e_base_count++], recur_one);

                }
                else if(strcmp(ptr, "E") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    strcpy(new_E_base[new_e_base_count++], recur_one);
                }
            }
        }
    }

    for(int j = 3; j < 6 ; j++){
        for(int i = 0 ; i < d_base_count ; i++){
            char* recur_one = malloc(sizeof(char) * 1000);
            strcpy(recur_one, recur[j]);
            int len = strlen(recur_one);

            while(strstr(recur_one, "D") != NULL) {
                char* ptr = strstr(recur_one, "D");
                if(strcmp(ptr, "D{}") == 0) 
                {
                    strncpy(ptr, D_base[i], strlen(D_base[i]));
                    recur_one[strlen(D_base[i])] = '{';
                    recur_one[strlen(D_base[i])+1] = '}';
                    strcpy(new_D_base[new_d_base_count++], recur_one);
                }
                else if(strcmp(ptr, "D}") == 0) 
                {
                    strncpy(ptr, D_base[i], strlen(D_base[i]));
                    recur_one[strlen(recur_one)] = '}';
                    strcpy(new_D_base[new_d_base_count++], recur_one);
                }
                else if(strcmp(ptr, "D") == 0) 
                {
                    strncpy(ptr, D_base[i], strlen(D_base[i]));
                    strcpy(new_D_base[new_d_base_count++], recur_one);
                }
            }
        }
    }
    for(int j = 3; j < 6 ; j++){
        for(int i = 0 ; i < e_base_count ; i++){
            char* recur_one = malloc(sizeof(char) * 1000);
            strcpy(recur_one, recur[j]);
            int len = strlen(recur_one);

            while(strstr(recur_one, "D") != NULL) {
                char* ptr = strstr(recur_one, "D");
                if(strcmp(ptr, "D{}") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    recur_one[strlen(E_base[i])] = '{';
                    recur_one[strlen(E_base[i])+1] = '}';
                    strcpy(new_D_base[new_d_base_count++], recur_one);
                }
                else if(strcmp(ptr, "D}") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    recur_one[strlen(recur_one)] = '}';
                    strcpy(new_D_base[new_d_base_count++], recur_one);
                }
                else if(strcmp(ptr, "D") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    strcpy(new_D_base[new_d_base_count++], recur_one);
                }
            }
        }
    }
    for(int j = 6; j < 9 ; j++){
        for(int i = 0 ; i < r_base_count ; i++){
            char* recur_one = malloc(sizeof(char) * 1000);
            strcpy(recur_one, recur[j]);
            int len = strlen(recur_one);

            while(strstr(recur_one, "R") != NULL) {
                char* ptr = strstr(recur_one, "R");
                if(strcmp(ptr, "R[]") == 0) 
                {
                    strncpy(ptr, R_base[i], strlen(R_base[i]));
                    recur_one[strlen(R_base[i])] = '[';
                    recur_one[strlen(R_base[i])+1] = ']';
                    strcpy(new_R_base[new_r_base_count++], recur_one);
                }
                else if(strcmp(ptr, "R]") == 0) 
                {
                    strncpy(ptr, R_base[i], strlen(R_base[i]));
                    recur_one[strlen(recur_one)] = ']';
                    strcpy(new_R_base[new_r_base_count++], recur_one);
                }
                else if(strcmp(ptr, "R") == 0) 
                {
                    strncpy(ptr, R_base[i], strlen(R_base[i]));
                    strcpy(new_R_base[new_r_base_count++], recur_one);
                }
            }
        }
    }
    for(int j = 6; j < 9 ; j++){
        for(int i = 0 ; i < e_base_count ; i++){
            char* recur_one = malloc(sizeof(char) * 1000);
            strcpy(recur_one, recur[j]);
            int len = strlen(recur_one);

            while(strstr(recur_one, "R") != NULL) {
                char* ptr = strstr(recur_one, "R");
                if(strcmp(ptr, "R[]") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    recur_one[strlen(E_base[i])] = '[';
                    recur_one[strlen(E_base[i])+1] = ']';
                    strcpy(new_R_base[new_r_base_count++], recur_one);
                }
                else if(strcmp(ptr, "R]") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    recur_one[strlen(recur_one)] = ']';
                    strcpy(new_R_base[new_r_base_count++], recur_one);
                }
                else if(strcmp(ptr, "R") == 0) 
                {
                    strncpy(ptr, E_base[i], strlen(E_base[i]));
                    strcpy(new_R_base[new_r_base_count++], recur_one);
                }
            }
        }
    }
    for(int j = 6; j < 9 ; j++){
        for(int i = 0 ; i < d_base_count ; i++){
            char* recur_one = malloc(sizeof(char) * 1000);
            strcpy(recur_one, recur[j]);
            int len = strlen(recur_one);

            while(strstr(recur_one, "R") != NULL) {
                char* ptr = strstr(recur_one, "R");
                if(strcmp(ptr, "R[]") == 0) 
                {
                    strncpy(ptr, D_base[i], strlen(D_base[i]));
                    recur_one[strlen(D_base[i])] = '[';
                    recur_one[strlen(D_base[i])+1] = ']';
                    strcpy(new_R_base[new_r_base_count++], recur_one);
                }
                else if(strcmp(ptr, "R]") == 0) 
                {
                    strncpy(ptr, D_base[i], strlen(D_base[i]));
                    recur_one[strlen(recur_one)] = ']';
                    strcpy(new_R_base[new_r_base_count++], recur_one);
                }
                else if(strcmp(ptr, "R") == 0) 
                {
                    strncpy(ptr, D_base[i], strlen(D_base[i]));
                    strcpy(new_R_base[new_r_base_count++], recur_one);
                }
            }
        }
    }

    int rcount =0 ;
    for(int i = 0 ; i < new_e_base_count ; i++) {
        int count = 0;
        for(int j = i+1 ; j < new_e_base_count ; j++) {
            if(strcmp(new_E_base[i], new_E_base[j]) == 0) {
                count++;
            }
        }
        if(count == 0) {
            if(strlen(new_E_base[i]) <= max_length)
                printf(" %s " , new_E_base[i]);
            else
                rcount++;
        }
    }
    printf("\n");
    for(int i = 0 ; i < new_d_base_count ; i++) {
        int count = 0;
        for(int j = i+1 ; j < new_d_base_count ; j++) {
            if(strcmp(new_D_base[i], new_D_base[j]) == 0) {
                count++;
            }
        }
        if(count == 0) {
            if(strlen(new_D_base[i]) <= max_length)
                printf(" %s " , new_D_base[i]);
            else
                rcount++;
        }
    }
    printf("\n");
    
    for(int i = 0 ; i < new_r_base_count ; i++) {

        int count = 0;
        for(int j = i+1 ; j < new_r_base_count ; j++) {
            if(strcmp(new_R_base[i], new_R_base[j]) == 0) {
                count++;
            }
        }
        if(count == 0) {
            if(strlen(new_R_base[i]) <= max_length)
                printf(" %s " , new_R_base[i]);
            else    
                rcount++;
        }
    }
    printf("\n");
    
    if(rcount > 0) return;

    parenthesis(recur, new_E_base, new_D_base, new_R_base, 
                new_e_base_count, new_d_base_count, new_r_base_count, max_length);
}