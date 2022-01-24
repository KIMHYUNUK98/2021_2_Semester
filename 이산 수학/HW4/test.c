#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ezdib.h"

int main(int argc, char *argv[]) {

    char name[128];
    char setting[128][32];
    char matching[128];
    int input[128];
    int level[128] = {0};
    int input_count = 0;
    int count = 0;
    int same = 0;

    FILE *fp = fopen(argv[1], "r");

    while(fgets(name, 128, fp)) {

        name[strlen(name)-1] = '\0';
        char *ptr = strtok(name, " ");

        while(ptr != NULL) {
            for(int i = 0 ; i < count ; i++) {
                if(strcmp(setting[i],ptr) == 0)
                    same++;
            }
            if(same == 0)
                strcpy(setting[count++], ptr);
            ptr = strtok(NULL, " ");
            same = 0;
        }
    }
    fclose(fp);

    FILE *rp = fopen(argv[1], "r");

    while(fgets(matching, 128, rp)) {
        matching[strlen(matching) - 1] = '\0';
        char *pt = strtok(matching, " ");

        while(pt != NULL) {
            for(int i = 0 ; i < count ; i++) {
                if(strcmp(setting[i], pt) == 0) {
                    input[input_count++] = i;
                }
            }
            pt = strtok(NULL, " ");
        }
    }

    for(int i = 0 ; i < input_count ; i++) {
        if(i >= 1 && i % 2 == 1 && input[i-1] != input[i] )
            level[input[i]]++;
    }

    int order[128] ={0};
    int order_count = 0;

    int matrix[100] = {0,};
    int matrix_count[100];
    int max_level = -1;

    double x_data[100];
    double y_data[100];

    for(int i = 0 ; i < count ; i++) {
        matrix[level[i]]++; 
        if(max_level < level[i]) max_level = level[i];
        matrix_count[i] = 1;
        x_data[i] = 0.F;
        y_data[i] = 0.F;
    }

    HEZDIMAGE hDib;
    HEZDFONT hFont;
    
    char fname[ 256 ] = { 0 };
    sprintf(fname, "input1.data.bmp");

    hDib = ezd_create( 640, -500, 1, 0 );

    for(int i = 0 ; i < count ; i++) {
        hFont = ezd_load_font( EZD_FONT_TYPE_MEDIUM, 0,0);
        ezd_text( hDib, hFont, setting[i], 
                    -1, 600 / (matrix[level[i]] + 1) * matrix_count[level[i]]-30, 
                    (450 / max_level+1) * (-level[i] + max_level + 0.05)+10, 0xff0000);
        ezd_circle(hDib, 600 / (matrix[level[i]] + 1) * matrix_count[level[i]], 
                    (450 / max_level+1) * (-level[i] + max_level + 0.05), 6, 'o');
        x_data[i] = 600 / (matrix[level[i]] + 1) * matrix_count[level[i]]++;
        y_data[i] = (450 / max_level+1) * (-level[i] + max_level + 0.05);
    }

    for(int i = 0 ; i < input_count-1 ; i++) {
        if(level[input[i+1]] - level[input[i]] == 1)
            ezd_line( hDib, x_data[input[i]], y_data[input[i]], 
                            x_data[input[i+1]], y_data[input[i+1]],
                            0xff0000 );
    }

    // Save the test image
	ezd_save( hDib, fname );

    // Free resources
    if ( hDib )
        ezd_destroy( hDib );

    return 0;
}
