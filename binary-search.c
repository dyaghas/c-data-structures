#include<stdlib.h>
#include<stdio.h>
#include<time.h>

// Maximum number possible in the array
#define NUM_SIZE 36267

void print_array(int array[], int array_length) {
    for(int i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

int check_arr_conditional(char cond) {
    if(cond == 'y') {
        return 1;
    } else {
        if(cond != 'n') {
            printf("Invalid character, 'n' considered instead\n");
        }
        return -1;
    }
}

void calculate_time(struct timespec end, struct timespec start) {
    double time_delta = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;;

    printf("Start time: %f seconds\n", start);
    printf("End time: %f seconds\n", end);
    printf("Time delta: %f seconds\n", time_delta);
}

void selection_sort(int array[], int array_length) {
    for(int i = 0; i < array_length-1; i++) {
        for(int j = i+1; j < array_length; j++) {
            if(array[j] < array[i]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int binary_search(int array[], int array_length, int target) {
    int low = 0; 
    int iterations = 0;
    int high = array_length - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        iterations++;

        if(array[mid] == target) {
            printf("Iterations: %d\n", iterations);
            return mid;
        } else if(array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1; 
        }
    }
    printf("Iterations: %d\n", iterations);
    return -1;
}

int linear_search(int array[], int array_length, int target) {
    for(int i = 0; i < array_length; i++) {
        if(array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int target;
    int array_length;
    char arr_conditional;

    printf("start clock: %ld\n", clock());
    // Creates an array dinamically based on user input for its length
    printf("Enter a size for the array: ");
    scanf("%d", &array_length);
    int *array = malloc(array_length * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Array memory allocation failed\n");
        return EXIT_FAILURE;
    }
    printf("Do you want to print the array (This will seriously impact performance) y/n: ");
    scanf(" %c", &arr_conditional);
    printf("\n");

    // Seeds rand
    srand((unsigned int)time(NULL));
    // Populates the array with random numbers from 0 to NUM_SIZE
    for(int i = 0; i < array_length; i++) {
        array[i] = rand() % NUM_SIZE;
        if(check_arr_conditional(arr_conditional) == 1) {
            printf("%d ", array[i]);
        }
    }

    selection_sort(array, array_length);
    
    if(check_arr_conditional(arr_conditional) == 1) {
        printf("\n\nSorted array: ");
        print_array(array, array_length);
    }
    printf("\n");

    printf("\nEnter a number to be found in the array: ");
    scanf(" %d", &target);
    // Record the start time
    struct timespec search_start, search_end;
    clock_gettime(CLOCK_MONOTONIC, &search_start);
    int res = binary_search(array, array_length, target);
    // Record the end time
    clock_gettime(CLOCK_MONOTONIC, &search_end);
    calculate_time(search_end, search_start);
    // If the number is not found, the function returns -1
    if(res >= 0) {
        printf("Number %d found at index %d\n", target, res);
    } else {
        printf("Number not found\n");
    }
    free(array);
    return EXIT_SUCCESS;
}