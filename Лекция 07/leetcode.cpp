#include <iostream>
#include <algorithm>
using namespace std;

void InsertSort(int* A, int n){
    for(int i = 1; i <n; i++){
        int x = A[i];
        int j = i - 1;
        for(; j > -1 && A[j] > x; j--){
            A[j + 1] = A[j];
        }
        A[j + 1] = x;
    }
}

int findShortestSubArray(int* nums, int numsSize) {
    int* temp = new int[numsSize];
    for (int i=0; i<numsSize; i++) temp[i]=nums[i];
    InsertSort(temp, numsSize);
    int min_value = temp[0], max_value = temp[numsSize - 1];
    int M = max_value-min_value + 1;
    int x = temp[0];
    int* degrees = new int[M];
    for (int i=0; i<M; i++) degrees[i]=0;
    int count = 1;
    for (int i=1; i<numsSize; i++, count++) {
        if (temp[i] != x) {
            degrees[x - min_value] = count;
            count = 0;
            x = temp[i];
        }
    }
    degrees[x] = count;
    for (int i=0; i<M; i++) {
        if (degrees[i]>0) {
            cout << i + min_value << " " << degrees[i] << endl;
        }
    };

}

int main(){
    int a[]{1,1,5,1,7,7,1};
    findShortestSubArray(a, 7);
}