/*

    Mission:
            1 Read float numbers in a textfile into an array
                the file does not contains more than 100 numbers. (set the array size by 100)

            2.Compute the following statistics:
                count
                mininum and maximum of the numbers
                mean = <sum of data[i]'s> / count
                variance = <sum of data[i]*data[i]> / count - mean * mean
                standard deviation = the square root of variance

    Example)
        When data1.txt contains the following numbers,
            0.777062
            0.902524
            0.876980
            0.558855
            0.224219
            0.014557
            0.025788
            0.120151
            0.128330
            0.704245
            0.252968
            0.044435
            0.055605

        the result should be as follows:
            Input filename: data1.txt       // the user typed data1.txt
            count = 13
            min = 0.014557
            max = 0.902524
            mean = 0.360440
            variance = 0.112150
            standard deviation = 0.334887


    Example)
        When data2.txt contains the following numbers,
            0.984741
            0.757653
            0.298044
            0.073580
            0.134251
            0.557451
            0.671010
            0.084811
            0.368419
            0.076937
            0.370495
            0.440931
            0.251045
            0.632862

        the result should be as follows:

        Input filename: data2.txt           // the user typed data2.txt
        count = 14
        min = 0.073580
        max = 0.984741
        mean = 0.407302
        variance = 0.074183
        standard deviation = 0.272366

*/


#include <stdio.h>
#include <float.h>
#include <math.h>

#define MAX_LEN 100

int main()
{
    // Initialize variables
    float data[MAX_LEN];
    int count = 0;

    // read filename
    char filename[256] = "";
    printf("Input filename: ");
    scanf("%s", filename);

    // TO DO: open file  (check for file open failure)
    FILE *fp = fopen(filename, "r");
    if(fp == NULL){
        printf("Failed to open file %s\n", filename);
        return -1;
    }

    // TO DO: read numbers from the file into a float array increasing the counter
    //        check the return value of fscanf() to terminate when all numbers were read
    //        do not read more data than MAX_LEN
    while(fscanf(fp, "%f", &data[count]) != EOF) {
        count++;
    }
    
    // TO DO: close file
    fclose(fp);

    printf("count = %d\n", count);
    
    // get the statistics
    float min = FLT_MAX;        // FLT_MAX is defined in float.h
    float max = FLT_MIN;        // FLT_MIN is defined in float.h
    float sum = 0.F;
    float mean = 0.F;
    float sum_square = 0.F;
    float var = 0.F;
    float stdev = 0.F;

    
    // TO DO: compute min, max, mean, var, and stdev
    for(int i = 0 ; i < count ; i++) {
        if(min > data[i])   
            min = data[i];
        if(max < data[i]) 
            max = data[i];
        sum += data[i];
    }
    mean = sum / count;

    for(int i = 0 ; i < count ; i++) {
        var += (data[i] - mean) * (data[i] - mean); 
    }
    
    var = var / count;

    stdev = sqrt(var);

    // display the results
    printf("min = %f\n", min);
    printf("max = %f\n", max);
    printf("mean = %f\n", mean);
    printf("variance = %f\n", var);
    printf("standard deviation = %f\n", stdev);

    return 0;
}
