using namespace std;
#include <vector>
#include <iostream>

//
// get max sum contiguous subsequence
//
int max_cont_sub(int arr[], int size)
{
    // array storing highest sum at that point
    int maxes[size];
    maxes[0] = arr[0];

    // fill out the array with optimal sums
    for (int i = 1; i < size; i++)
    {
        maxes[i] = max(maxes[i-1] + arr[i], arr[i]);
    }

    // loop over sums, get highest to return
    int maxSum = maxes[0];
    for (int num : maxes)
    {
        if (num > maxSum) 
            maxSum = num;
    }

    return maxSum;
}

//
//
// 
int main()
{
    int sequences;
    cin >> sequences;

    for (; sequences > 0; sequences--)
    {
        int size;
        cin >> size;

        int arr[size];

        for(int i = 0; i < size; i++)
        {
            cin >> arr[i]; 
        }

        cout << max_cont_sub(arr, size) << endl; 

    }

    return EXIT_SUCCESS;
}



