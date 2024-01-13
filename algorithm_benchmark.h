#ifndef ALGORITHM_BENCHMARK_H
    #define ALGORITHM_BENCHMARK_H
    // Biggest random number possible in the array
    #define MAX_NUM 999999
    #include<time.h>
    struct timespec;

    void print_array(int array[], int array_length);

    int generate_int();
    
    void swap(int *num1, int *num2);

    int check_arr_conditional(char cond);

    double calculate_time(struct timespec end, struct timespec start);
    void print_time(struct timespec start, struct timespec end, double time_delta);
    
    void selection_sort(int array[], int array_length);
    int partition(int array[], int low, int high);
    void quick_sort(int array[], int low, int high);
    int linear_search(int array[], int array_length, int target);
    
#endif