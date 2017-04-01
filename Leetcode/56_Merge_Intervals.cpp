//
// Created by edvard on 30/03/2017.
//
// Given a collection of intervals, merge all overlapping intervals.
//
// For example,
//        Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
    int start;
    int end;

    Interval() : start(0), end(0) {}

    Interval(int s, int e) : start(s), end(e) {}
};

bool comp (const Interval &a, const Interval &b){
    return b.start > a.start;
}

vector <Interval> merge(vector <Interval> &intervals) {

    // Boundary value
    if(0 == intervals.size())
        return intervals;

    // Sort intervals according to start variable
    sort(intervals.begin(), intervals.end(), comp);

    // Merging interval
    vector<Interval> mergedIntervals;
    struct Interval tmp = intervals.at(0);
    for (int i = 1; i < intervals.size(); ++i) {
        struct Interval tmp2 = intervals.at(i);

        if(tmp2.start <= tmp.end){
            if(tmp2.end > tmp.end){
                tmp.end = tmp2.end;
            }
        }else{
            mergedIntervals.push_back(tmp);
            tmp.start = tmp2.start;
            tmp.end = tmp2.end;
        }
    }

    // The last one
    mergedIntervals.push_back(tmp);

    return mergedIntervals;
}

int main() {

    struct Interval *i1 = new Interval(1, 3);
    struct Interval *i2 = new Interval(1, 3);
    struct Interval *i3 = new Interval(8, 10);
    struct Interval *i4 = new Interval(15, 18);

    vector<Interval> intervals;
    intervals.push_back(*i1);
    intervals.push_back(*i2);
    intervals.push_back(*i3);
    intervals.push_back(*i4);

    intervals = merge(intervals);


    for(struct Interval tmp : intervals){
        cout << tmp.start << " " << tmp.end << endl;
    }

    return 0;
}