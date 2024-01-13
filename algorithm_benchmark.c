#include "algorithm_benchmark.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include "unity.h"

void print_array(int array[], int array_length) {
    for(int i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
}

int generate_int() {
    static int initialized = 0;  // Static variable to track initialization
    if (!initialized) {
        srand((unsigned int)time(NULL));
        initialized = 1;  // Initializes srand only once
    }

    int part1 = rand() % 32767;
    int part2 = rand() % 32767;
    int combined_value = (part1 << 15) | part2;

    return combined_value % MAX_NUM;
}

// Swaps two elements
void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Checks if the user wants to print the array or not
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

double calculate_time(struct timespec end, struct timespec start) {
    double time_delta = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    return time_delta;
}

void print_time(struct timespec start, struct timespec end, double time_delta) {
    printf("Start time: %f seconds\n", start);
    printf("End time: %f seconds\n", end);
    printf("Time delta: %f seconds\n\n", time_delta);
}

void selection_sort(int array[], int array_length) {
    for(int i = 0; i < array_length-1; i++) {
        for(int j = i+1; j < array_length; j++) {
            if(array[j] < array[i]) {
                swap(&array[i], &array[j]);
            }
        }
    }
}

// Quick Sort
// Function to partition the array and return the pivot index
int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for(int j = low; j <= high; j++) {
        if(array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    // Swap array[i + 1] and pivot 
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void quick_sort(int array[], int low, int high) {
    if(low < high) {
        int pi = partition(array, low, high);
        //Sorts before the pivot
        quick_sort(array, low, pi - 1);
        //Sorts after the pivot
        quick_sort(array, pi + 1, high);
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

#ifndef TEST
int main() {
    int target, sort_choice, search_choice, array_length;
    char arr_conditional;
    int res = -1;
    struct timespec sort_start, sort_end, search_start, search_end;

    // Creates an array dinamically based on user input for its length
    printf("Enter array size: ");
    scanf("%d", &array_length);
    int *array = malloc(array_length * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Array memory allocation failed\n");
        return EXIT_FAILURE;
    }

    printf("Do you want to print the array? (This will impact performance) y/n: ");
    scanf(" %c", &arr_conditional);
    printf("\n");
    // Populates the array with random numbers from 0 to NUM_SIZE
    for(int i = 0; i < array_length; i++) {
        array[i] = generate_int();
        if(check_arr_conditional(arr_conditional) == 1) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");

    // Selects a sort and a search algorithm
    printf("\nEnter a number to be found in the array: ");
    scanf(" %d", &target);
    printf("Select a sorting algorithm: \n1 - No sorting \n2 - Selection sort \n3 - QuickSort\n");
    scanf(" %d", &sort_choice);
    printf("Select a searching algorithm: \n1 - Linear search \n----For sorted arrays---- \n2 - Binary search\n");
    scanf(" %d", &search_choice);

    // Record the sort start time
    clock_gettime(CLOCK_MONOTONIC, &sort_start);

    switch(sort_choice) {
        case 1:
            break;
        case 2:
            selection_sort(array, array_length);
            break;
        case 3:
            quick_sort(array, 0, array_length-1);
            break;
        default:
            printf("Invalid choice");
            break;
    }

    // Record the sort end time and how long it took to execute
    clock_gettime(CLOCK_MONOTONIC, &sort_end);
    double sort_delta = calculate_time(sort_end, sort_start);

    switch(search_choice) {
        case 1:
            // Record the search start time
            clock_gettime(CLOCK_MONOTONIC, &search_start);
            res = linear_search(array, array_length, target);
            break;
        case 2:
            // Record the search start time
            clock_gettime(CLOCK_MONOTONIC, &search_start);
            res = binary_search(array, array_length, target);
            break;
        default:
            // Record the search start time
            clock_gettime(CLOCK_MONOTONIC, &search_start);
            printf("Invalid choice\n");
            return EXIT_FAILURE;
            break;
    }

    // Record the search end time and how long it took to execute
    clock_gettime(CLOCK_MONOTONIC, &search_end);
    double search_delta = calculate_time(search_end, search_start);

    // Prints the array if the user chose to do so
    if(check_arr_conditional(arr_conditional) == 1) {
        printf("\n\nSorted array: ");
        print_array(array, array_length);
        printf("\n");
    }

    // If the number is not found, the function returns -1
    if(res >= 0) {
        printf("\nNumber %d found at index %d\n", target, res);
    } else {
        printf("\nNumber not found\n");
    }

    // Prints how long each algorithm took
    printf("\n--Sort time delta-- \n");
    print_time(sort_start, sort_end, sort_delta);
    printf("--Search time delta-- \n");
    print_time(search_start, search_end, search_delta);

    free(array);
    return EXIT_SUCCESS;
}
#endif