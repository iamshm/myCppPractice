
#include <bits/stdc++.h>
using namespace std;

void shm() {
#ifndef ONLINE_JUDGE
    freopen("D:\\cpp\\input.txt", "r", stdin);
    freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
}

void reverseArray(int arr[],int sizeOfArray){
    int start = 0;
    int end = sizeOfArray -1;
    while(start<end){
        int temp = arr[start];
        arr[start]= arr[end];
        arr [end] = temp;
        start++;
        end--;
    }
}
int main()
{
    shm();
    int i, sizeOfArray = 5;
    int input[sizeOfArray];
    for (i = 0; i < sizeOfArray; ++i) {
        cin >> input[i];
    }

    reverseArray(input,sizeOfArray);

    for (i = 0; i < sizeOfArray; ++i) {
        cout << input[i] << endl;
    }

    return 0;
}
