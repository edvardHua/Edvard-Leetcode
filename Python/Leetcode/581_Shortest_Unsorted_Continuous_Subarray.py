# -*- coding: utf-8 -*-

# Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order,
# then the whole array will be sorted in ascending order, too.
# You need to find the shortest such subarray and output its length.
# Input: [2, 6, 4, 8, 10, 9, 15]
# Output: 5
# Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

class Solution(object):
    def findUnsortedSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n, sorts = len(nums), sorted(nums)
        if nums == sorts: return 0
        l, r = min(i for i in range(n) if nums[i] != sorts[i]), max(i for i in range(n) if nums[i] != sorts[i])
        return r - l + 1

