#include<stdlib.h>
#include<stdio.h>

//Maximum number possible in the array
#define NUM_SIZE 36267

void print_array(int array[], int array_length) {
    for(int i = 0; i < array_length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");
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
    int high = array_length - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(array[mid] == target) {
            return mid;
        } else if(array[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int target;
    int array_length;

    //Creates an array dinamically based on user input for its length
    printf("Enter a size for the array: ");
    scanf("%d", &array_length);
    int *array = malloc(array_length * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Array memory allocation failed\n");
        return EXIT_FAILURE;
    }

    //Seeds rand
    srand((unsigned int)time(NULL));
    //Populates the array with random numbers from 0 to NUM_SIZE
    for(int i = 0; i < array_length; i++) {
        array[i] = rand() % NUM_SIZE;
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("\nEnter a number to be found in the array: ");
    scanf("%d", &target);

    //printf("\nOriginal array: ");
    //print_array(array, array_length);

    selection_sort(array, array_length);

    printf("Sorted array: ");
    print_array(array, array_length);

    int res = binary_search(array, array_length, target);
    //If the number is not found, the function returns -1
    if(res >= 0) {
        printf("Number %d found at index %d", target, res);
    } else {
        printf("Number not found");
    }

    free(array);
    return EXIT_SUCCESS;
}