//
// Created by edvard on 28/03/2017.
//
#include <iostream>
#include <vector>
using namespace std;

void my_merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // 注意一个为 0 的情况
    if(0 == m){
        nums1 = nums2;
        return;
    }else if(0 == n){
        return;
    }

    vector<int> tmp;

    int i = 0, j = 0, k = 0;
    while(i < m && j < n){
        if(nums1.at(i) > nums2.at(j)){
            tmp.push_back(nums2.at(j));
            j ++;
        }else{
            tmp.push_back(nums1.at(i));
            i ++;
        }
        k ++;
    }

    // 这里直接加上长度 m  或 n 比直接写 end() 要好
    // 因为有时候 m 是表示前几位，而不是排序数组里面全部的元素
    if(i == m){
        tmp.insert(tmp.begin() + k, nums2.begin() + j, nums2.begin() + n);
    }else {
        tmp.insert(tmp.begin() + k, nums1.begin() + i, nums1.begin() + m);
    }

    nums1 = tmp;
}

int main(void){

    int n1[] = {4, 0, 0, 0, 0, 0};
    int n2[] = {1, 2, 3, 5, 6};
    vector<int> num1(n1, n1 + 6);
    vector<int> num2(n2, n2 + 5);
    my_merge(num1, 1, num2, 5);

//    int n1[] = {};
//    int n2[] = {1, 2, 3, 5, 6};
//    vector<int> num1(n1, n1 + 0);
//    vector<int> num2(n2, n2 + 5);
//    my_merge(num1, 0, num2, 5);


    for(int tmp : num1){
        cout << tmp << " ";
    }

    return 0;
}