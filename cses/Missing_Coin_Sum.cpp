#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    long long currSum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= (currSum + 1))
            currSum += arr[i];
        else
            break;
    }

    cout << currSum + 1 << endl;
}