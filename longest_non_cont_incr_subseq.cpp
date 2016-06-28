using namespace std;
#include <iostream>

//
// get longest increasing subsequence
//
int longest_incr_sub(int arr[], int size)
{
    int curr_max;
    int curr_prev_index;
    int lengths[size];
    int seq[size];
    lengths[0] = 1;
    seq[0] = -1;

    // fill out the array with optimal lengths
    // ending at each index
    for (int i = 1; i < size; i++)
    {
        curr_max = 0;
        curr_prev_index = -1;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (lengths[j] > curr_max)
                {
                    curr_max = lengths[j];
                    curr_prev_index = j;
                }
            }
        }
        lengths[i] = curr_max + 1;
        seq[i] = curr_prev_index;
    }

    // get the longest subsequence from results
    // and keep the index it ends at
    int starting_point = 0;
    for (int i = 0; i < size; i++)
    {
        if (lengths[i] > starting_point)
            starting_point = i;
    }

    // print out the actual sequence
    int i = starting_point;
    while (i != -1)
    {
        cout << arr[i] << endl;
        i = seq[i];
    }

    return lengths[starting_point];
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
            cout << arr[i] << " ";
        }
        cout << endl; 
        cout << "total length: " << longest_incr_sub(arr, size) << endl;
    }

    return EXIT_SUCCESS;
}



