/*
    Read strings until the user types "quit" and sort the input strings
        - declare a structure 'MyString'
        - read strings from the user and store them in an array of MyString pointers
        - display the strings in the array
        - sort the array of MyString
        - display the strings in the array
        - delete all MyString objects

    Example)
        Input a strings: welcome
        Input a strings: to
        Input a strings: HGU
        Input a strings: God
        Input a strings: bless
        Input a strings: you
        Input a strings: quit           // the end of input
        count = 6
        welcome to HGU God bless you    // input strings
        ...sorting...complete!
        God HGU bless to welcome you    // sorted strings

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// TO DO: declare a structure 'MyString' composed of a character pointer 'ptr' and an integer 'len'
//        use 'typedef' together with 'struct'

typedef struct {
    char *ptr;
    int len;
} MyString;

MyString *CreateString(char *string);
void CopyString(MyString *str1, MyString *str2);
int CompareMyString(MyString *str1, MyString *str2);
void DeleteString(MyString *str);
void SortMyStringArray(MyString *array[], int count);


int main()
{
    int i = 0;
    MyString *array[MAX_LEN] = { NULL };        // an array of character pointers
    char arr[128] = "";
    int count = 0;

    // TO DO: read strings from the user, convert them into MyString objects, and store them in array
    // repeat increasing count until the user types "quit" 
    while(1) {
        // read a string using a character array and scanf()
        printf("Input a string: ");
        scanf("%s", arr);

        // if the input string is "quit", break the loop
        if(strcmp(arr, "quit") == 0) break;

        // Create a MyString object by calling CreateString(). Store the address of the MyString object in array[count]
        array[count++] = CreateString(arr);
    }

    printf("count = %d\n", count);

    // display the strings
    for(i = 0; i < count; i++)
        printf("%s ", array[i]->ptr);

    printf("\n...sorting...");
    SortMyStringArray(array, count);
    printf("complete!\n");

    // display the strings
    for(i = 0; i < count; i++)
        printf("%s ", array[i]->ptr);

    // delete all strings
    for(i = 0; i < count; i++){
        DeleteString(array[i]);
        array[i] = NULL;            // for safety
    }

    return 0;
}

MyString *CreateString(char *string)
{
    // TO DO: create a MyString object using the input string
    MyString *str = NULL;

    // TO DO: allocate a memory block whose size is 'sizeof(MyString)' and store its address in str
    //        don't forget to check memory allocation failure
    str = (MyString*)malloc(sizeof(MyString));
    //str = string;
    if(str == NULL) {
        printf("Failed to open file in line %d\n", __LINE__);
        exit(-1);
    }


    // TO DO: set str->len by the length of string
    str->len = strlen(string);

    // TO DO: allocate a memory block whose size is (str->len + 1) and store its address in str->ptr
    //        don't forget to check memory allocation failure
    str->ptr = (char*)malloc(sizeof(str->len) + 1);
    if(str->ptr == NULL) {
        printf("Failed to open file in line %d\n", __LINE__);
        exit(-1);
    }

    // TO DO: copy string into str->ptr using strcpy()
    strcpy(str->ptr, string);

    return str;
}

void CopyString(MyString *dest, MyString *src)
// copy src to dest
{
    // TO DO: read this function carefully and learn how to use structures and strings

    // if dest is not an empty string, deallocate dest->ptr
    if(dest->ptr)
        free(dest->ptr);

    // set dest->len by the length of src 
    dest->len = src->len;

    // allocate a memory block whose size is (dest->len + 1) and store its address in dest->ptr
    // don't forget to check memory allocation failure
    dest->ptr = (char*)malloc(dest->len + 1);
    if(dest->ptr == NULL){
        printf("Failed to allocate memory in line %d\n", __LINE__);
        exit(-1);
    }

    strcpy(dest->ptr, src->ptr);
}

int CompareMyString(MyString *str1, MyString *str2)
{
    return strcmp(str1->ptr, str2->ptr);
}

void DeleteString(MyString *str)
{
    // TO DO: implement this function

    // deallocate str->ptr and str
    free(str);
    free(str->ptr);
}

/*
// the selection sort algorithm for integer array
void SelectionSort(int list[], int size)
{
	for(int current = 0; current < size - 1; current++){
        // find the location of the smallest element in the 'unserted list'
		int smallest = current;
		for(int walk = current + 1; walk < size; walk++)
			if(list[walk] < list[smallest])
				smallest = walk;

        // exchange list[current] and list[smallest]
		float temp = list[current];
		list[current] = list[smallest];
		list[smallest] = temp;
	}
}
*/

void SortMyStringArray(MyString *array[], int count)
// sort an array of MyStrings
{
    // TO DO: implement this function by modifying the SelectionSort()
    // Hint) compare array[walk] and array[smallest] using CompareMyString()
    // Hint) to exchange array[current] and array[smallest], use "MyString *temp;"
    for(int current = 0 ; current < count - 1 ; current++) {
        // find the location of the smallest element in the 'unserted list'
        int smallest = current;
        for(int walk = current + 1; walk < count ; walk++) {
            if(CompareMyString(array[walk], array[smallest]) < 0)
                smallest = walk;
        }

        // exchange array[current] and array[smallest]
        MyString *temp = array[current];
        array[current] = array[smallest];
        array[smallest] = temp;
    }

}
