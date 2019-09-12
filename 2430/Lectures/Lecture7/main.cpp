#include <iostream>

using namespace std;

void mergeSort() { //Running time nlogn.  High space complexity (Multiple temporary arrays necessary).  Slightly faster than quickSort.
    //split array into two arrays
    //keep splitting suparrays in half, to new subarrays.  Eventually you will have an upside down tree of arrays
    //sort each subarray, then merging subarrays going back up the tree.
    //This can be done in parallel


}

void quickSort() {  //Every time a pivot is selected, it gets sorted to the correct position.  Lower space complexity, but more swaps than merge sort.  nlogn running time.
    //pivot p = first number
    //last number in array swap with pivot
    //for(int j = 7;number > pivot; j--)    check for number smaller than pivot
    //swap
    //repeat step 2 (stop on next smallest number under pivot number)
    //as i crosses j, stop sorting, put pivot at i  (Pivot now at correct position)
    //array left of pivot becomes "left array," right of pivot becomes "right array"
    //repeat for left array (first number becomes pivot)
    //j looks for first element less than pivot, i for first element greater
    //swap i and j, then continue
    //once i and j cross repeat process, again splitting and sorting left array
}

void shellSort() {  //modified insertion sort.  Decreased number of swaps, but multiple insertion sorts.  Really useful for large arrays.  Smaller arrays should just go for insertion sort
    //split array into 2 arrays by separation so each array is composed of every other set of numbers of a specificic separation.  Start by making arrays by making arrays the numbers 5 apart in array
    //apply insertion sort on each array
    //repeat for 3 separation
    //do normal insertion sort

    //separation can be really any set of numbers, but it should aim to start at half the array size, cannot use separations too largee, or much of array may be left unsorted.  Always 3 passes, the final being the entire array.
}


void bucketSort() {  //Use with large numbers.  No swaps or comparisons.  
    //Create 10 "buckets"
    //Sort array into buckets based on 1s digit
    //Empty buckets in order (first in first out)
    //Repeat for as many times as the length of the largest number
    
    
    
    //ex:  1, 10, 2832, 1231, 721, 711, 424
    //put all numbers with numbers in 1s places in corresponding bucket (1, 1231, 711, 721 in 1s bucket, 10 in 0s bucket, etc)
    //10, 1, 1231, 721, 711, 2832, 4214
    //Sort to buckets based on 10s place
    //1, 10, 711, 4214, 721, 1231, 2832
    //Sort based in 100s place
    //1, 10, 4214, 1231, 711, 721, 2832
    //sort based on 1000s digit
    //1, 10, 711, 721, 1231, 2832
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
