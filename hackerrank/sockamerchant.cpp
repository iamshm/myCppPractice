#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;
int sockMerchant(int n, vector<int> ar)
{
    sort(ar.begin(), ar.end());
    vector<int> temp;
    vector<int>::iterator it = ar.begin();
    int freq = 0;
    int i = 0;
    while (i != ar.size())
    {
        freq = count(ar.begin(), ar.end(), ar[i]);
        temp.push_back(freq);
        i = i + freq;
    }
    cout << "com" << endl;
    int sum = 0;
    for (int x : temp)
    {
        sum = sum + x / 2;
    }
    return sum;
}
int main()
{
    int a = 7;
    vector<int> b = {1, 2, 2, 2, 1, 2, 3};
    int c = sockMerchant(a, b);

    // cout << c << "size" << endl;
    getch();
}