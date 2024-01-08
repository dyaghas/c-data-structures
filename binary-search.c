#include<stdlib.h>
#include<stdio.h>

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
    int array[] = {194324, 32666, 403731, 311926, 310596, 289204, 248602, 888733, 646772, 571721, 151601, 184418, 
        622696, 506675, 417956, 888990, 12077, 482657, 119617, 620023, 933142, 693270, 665048, 153206, 452862, 235405, 
        275695, 69058, 536350, 487784, 786502, 507755, 730442, 76896, 305262, 236559, 13359, 564403, 426686, 120618, 
        995742, 734830, 1375, 602901, 50188, 759572, 814795, 13445, 490245, 642889, 809841, 343347, 563953, 792690, 
        130398, 792691, 479629, 428458, 35298, 622845, 772618, 316772, 438803, 757954, 123386, 430213, 367230, 700235, 
        542694, 932600, 14526, 571653, 245818, 611368, 1951, 507732, 114972, 193728, 898363, 115695, 38948, 715707, 
        503661, 699489, 504299, 530696, 292322, 985067, 322764, 230346, 421809, 289611, 646353, 199596, 355971, 759574, 
        406413, 371321, 174283, 63503, 299450, 626861, 655346, 687843, 979164, 722594, 413578, 969474, 479816, 226239, 
        379585, 737041, 757662, 506988, 52108, 516369, 183603, 515165, 737130, 701076, 277896, 264670, 17162, 930419, 
        84796, 649620, 494742, 473195, 235473, 934795, 373460, 790410, 646456, 160339, 154559, 391423, 116683, 928221, 
        324471, 820777, 561440, 885545, 812642, 299884, 311786, 318732, 728383, 873013, 589869, 628285, 106973, 668301, 
        18658, 903986, 437296, 87785, 455097, 465204, 318373, 111631, 516055, 316945, 837214, 173529, 582214, 41068, 
        883320, 831743, 725150, 15751, 18338, 845905, 855988, 356463, 683631, 371451, 873624, 958799, 948211, 85913, 
        757128, 468005, 62578, 680752, 492389, 635520, 346149, 540974, 698918, 99604, 387014, 973989, 560463, 896694, 
        497126, 221572, 54518, 410460, 513385, 297106
    };
    size_t array_length = sizeof(array) / sizeof(array[0]);
    printf("Enter a number to be found in the array: ");
    scanf("%d", &target);

    printf("\nOriginal array: ");
    print_array(array, array_length);

    selection_sort(array, array_length);
    
    printf("Sorted array: ");
    print_array(array, array_length);

    int res = binary_search(array, array_length, target);
    //If the number is not found, the function returns -1
    if(res >= 0) {
        printf("Number %d found on index %d", target, res);
    } else {
        printf("Number not found");
    }

    return EXIT_SUCCESS;
}