#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the rotLeft function below.

// Please store the size of the integer array to be returned in result_count pointer. For example,
// int a[3] = {1, 2, 3};
//
// *result_count = 3;
//
// return a;
//
int* rotLeft(int a_count, int* a, int d, int* result_count) {
    int* temp = (int*)malloc(a_count * sizeof(int));
    printf("Intitial: ");
    for(int iVal = 0;iVal < a_count;iVal++)
    {
        printf(" %d",a[iVal]);
    }
    printf("\n");

    static int nStartPos = 0;
    for(int nVal = d;nVal < a_count;nVal++)
    {
        *(temp+nStartPos) = *(a+nVal);
        nStartPos++;
    }
    printf("After Copying elements to be rotated: \n");
    for(int iVal = 0;iVal < a_count;iVal++)
    {
        printf(" %d",*(temp+iVal));
    }
    printf("\n");
    printf("The value of nStartPos after rotation is done: [%d]\n",nStartPos);
    for(int nVal = 0;nVal < d;nVal++)
    {
        *(temp+nStartPos) = *(a+nVal);
        nStartPos++;
    }
    *result_count = nStartPos;
    printf("The value of a_count is:[%d], nStartPos is: [%d],result_count is:[%d]\n",a_count,nStartPos,*result_count);
    
    printf("The value of incoming array A is: \n");
    for(int iVal = 0;iVal < a_count;iVal++)
    {
        printf("%d \n",*(a+iVal));
    }
    
    printf("The value of outgoing array temp is: \n");
    for(int iVal = 0;iVal < a_count;iVal++)
    {
        printf("%d \n",*(temp+iVal));
    }
    //free(temp);
    return temp;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nd = split_string(readline());

    char* n_endptr;
    char* n_str = nd[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* d_endptr;
    char* d_str = nd[1];
    int d = strtol(d_str, &d_endptr, 10);

    if (d_endptr == d_str || *d_endptr != '\0') { exit(EXIT_FAILURE); }

    char** a_temp = split_string(readline());

    int* a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        char* a_item_endptr;
        char* a_item_str = *(a_temp + i);
        int a_item = strtol(a_item_str, &a_item_endptr, 10);

        if (a_item_endptr == a_item_str || *a_item_endptr != '\0') { exit(EXIT_FAILURE); }

        *(a + i) = a_item;
    }

    int a_count = n;

    int result_count;
    int* result = rotLeft(a_count, a, d, &result_count);
    printf("INSIDE MAIN: value of result_count is: %d \n",result_count);
    
    for(int iVal = 0;iVal < result_count;iVal++)
    {
        //a[iVal] = temp[iVal];
        printf(" %d",result[iVal]);
    }

    for (int i = 0; i < result_count; i++) {
        fprintf(fptr, "%d", *(result + i));

        if (i != result_count - 1) {
            fprintf(fptr, " ");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
