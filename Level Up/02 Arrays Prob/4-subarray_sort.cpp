// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// bool outOfOrder(vector<int> &arr, int i)
// {
// }

// pair<int, int> subArraySort(vector<int> &arr)
// {
//     int smallest, largest;
//     smallest = INT_MAX;
//     largest = INT_MIN;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int x = arr[i];
//         if (outOfOrder(arr, i))
//         {
//             smallest = min(smallest, x);
//             largest = max(largest, x);
//         }
//     }

//     if (smallest == INT_MAX)
//     {
//         return {-1, -1};
//     }
//     return {smallest};
// }

// int main()
// {
//     vector<int> arr{1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
//     auto p = subArraySort(arr);
//     cout << p.first << " " << p.second << endl;
//     return 0;
// }