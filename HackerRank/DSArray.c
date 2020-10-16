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

// Complete the hourglassSum function below.
int hourglassSum(int arr_rows, int arr_columns, int** arr) {
    int row_index= 0;
    int elem_index = 0;
    int row_max = 3;
    int column_max = 3;
    int nSumMax = 0;
    
    for(row_index = 0;row_index <= row_max;row_index++)
    {
        for(elem_index = 0;elem_index < column_max;elem_index++)
        {
            //printf("Elem at Row_Index[%d], Elem_Index[%d] is %d\n",row_index,elem_index,*(*(arr+row_index)+elem_index));
            //printf("Elem at Row%d\n",*(*(arr+row_index)+elem_index));

            //First leg
            int nSum = *(*(arr+row_index)+elem_index) + *(*(arr+row_index)+(elem_index+1))+
            *(*(arr+row_index)+(elem_index+2)) +
            //Second leg
            *(*(arr+(row_index+1))+(elem_index+1)) +
            //Third leg
            *(*(arr+(row_index+2))+elem_index) + *(*(arr+(row_index+2))+(elem_index+1)) +
            *(*(arr+(row_index+2))+(elem_index+2));

            if(nSum > nSumMax)
                nSumMax = nSum;
        }
        printf("The first element of the hour glass is: [%d]\n",*(*(arr+row_index)+elem_index));
        printf("The last elem is: [%d]\n",*(*(arr+(row_index+2))+(elem_index+2)));
        printf("Exiting for loop for row_index[%d], elem_index[%d],nSumMax[%d]\n",row_index,elem_index,nSumMax);
    }
    printf("Going to return nSumMax[%d]\n",nSumMax);
    return nSumMax;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int** arr = malloc(6 * sizeof(int*));

    for (int i = 0; i < 6; i++) {
        *(arr + i) = malloc(6 * (sizeof(int)));

        char** arr_item_temp = split_string(readline());

        for (int j = 0; j < 6; j++) {
            char* arr_item_endptr;
            char* arr_item_str = *(arr_item_temp + j);
            int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

            if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(arr + i) + j) = arr_item;
        }
    }

    int arr_rows = 6;
    int arr_columns = 6;

    int result = hourglassSum(arr_rows, arr_columns, arr);

    fprintf(fptr, "%d\n", result);

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

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

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
