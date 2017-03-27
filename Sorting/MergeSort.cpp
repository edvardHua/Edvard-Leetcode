//
// Created by edvard on 01/03/2017.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

void my_copy(int *src, int start, int length, int *dest, int desStart) {
    for (int i = 0; i < length; i++) {
        dest[desStart + i] = src[start + i];
    }
}

void print_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void init_int_array(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        arr[i] = 0;
    }
}

void merge(int *arr, int left, int mid, int right) {

    // Temporary merged results variable
    int resLen = right - left + 1;
    int tmpRes[resLen];
    init_int_array(tmpRes, resLen);

    // Copy left part elements into new array
    int leftLen = mid - left + 1;
    int leftPart[leftLen];
    init_int_array(leftPart, leftLen);
    my_copy(arr, left, leftLen, leftPart, 0);
    // Copy right part elements into new array
    int rightLen = right - mid;
    int rightPart[rightLen];
    init_int_array(rightPart, rightLen);
    my_copy(arr, mid + 1, rightLen, rightPart, 0);

    // Merging operation
    int i = 0, j = 0, k = 0;
    while (i < leftLen & j < rightLen) {
        if (leftPart[i] > rightPart[j]) {
            tmpRes[k] = rightPart[j];
            j++;
        } else {
            tmpRes[k] = leftPart[i];
            i++;
        }
        k++;
    }

    // Appending the rest elements
    if (i == leftLen) {
        my_copy(rightPart, j, rightLen - j, tmpRes, k);
    } else if (j == rightLen) {
        my_copy(leftPart, i, leftLen - i, tmpRes, k);
    }

    // Copy to original array
    my_copy(tmpRes, 0, resLen, arr, left);

}

/**
 *
 * @param arr
 * @param left
 * @param right
 */
void merge_sort(int *arr, int left, int right) {

    if (right > left) {
        int mid = (left + right) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

/**
 * TODO
 * @param arr
 * @param len
 */
void merge_sort_non_recursive(int *arr, int len) {

    int tmp[len];

    // The length of each merge array
    for(int mergeUnit = 1; mergeUnit < len; mergeUnit *= 2){

    }

}

//int main(void){
//
//    int test[] = {4, 2, 3, 9, 8, 7, 5};
//    merge_sort(test, 0, 6);
//
//    print_array(test, 7);
//
//    return 0;
//}
