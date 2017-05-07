//
// Created by edvard on 15/02/2017.
//
// Given an array of integers, every element appears twice except for one. Find that single one.
//

int singleNumber(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size();){
        if(i + 1 >= nums.size()){
            return nums.at(i);
        }
        if(nums.at(i) != nums.at(i + 1)){
            return nums.at(i);
        }
        i = i + 2;
    }
}

