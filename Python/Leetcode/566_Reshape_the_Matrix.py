#!/usr/bin/env python
# -*- coding: UTF-8 -*-

import numpy as np

def matrixReshape(nums, r, c):
    """
    :type nums: List[List[int]]
    :type r: int
    :type c: int
    :rtype: List[List[int]]
    """
    if len(nums) == 0:
        return nums

    if len(nums) * len(nums[0]) != r * c:
        return nums

    integrate = []
    for i in nums:
        integrate.extend(i)

    del nums

    res = []
    for i in range(0, r):
        row = []
        for j in range(0, c):
            row.append(integrate[i*c + j])
        res.append(row)

    return res

def matruxReshape2(nums, r, c):
    try:
        np.reshape(nums, (r, c)).tolist()
    except:
        return nums


def matrixReshape3(nums, r, c):
    flat = sum(nums, [])
    if len(flat) != r * c:
        return nums
    tuples = zip(*([iter(flat)] * c))
    return map(list, tuples)