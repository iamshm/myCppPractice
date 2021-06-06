// maxm and minm in array
#include <bits/stdc++.h>
using namespace std;

void shm() {
#ifndef ONLINE_JUDGE
    freopen("D:\\cpp\\input.txt", "r", stdin);
    freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
}

struct Pair {
    int min, max;
};
struct Pair getMinMax(int a[], int low, int high) {
    struct Pair minmax, minmaxleft, minmaxright;
    // if array size is 1
    if (low == high) {
        minmax.min = a[low];
        minmax.max = a[low];
        return minmax;
    }
    // if array size is 2
    if (low + 1 == high  ) {
        if (a[low] > a[high]) {
            minmax.min = a[high];
            minmax.max = a[low];
        }
        else  {
            minmax.min = a[low];
            minmax.max = a[high];
        }
        return minmax;
    }
    // array size > 2
    int mid = (low + high) / 2;
    minmaxleft = getMinMax(a, low, mid);
    minmaxright = getMinMax(a, mid + 1, high);

    if (minmaxleft.min < minmaxright.min) {
        minmax.min = minmaxleft.min;
    } else {
        minmax.min = minmaxright.min;
    }
    if (minmaxleft.max > minmaxright.max)
        minmax.max = minmaxleft.max;
    else
        minmax.max = minmaxright.max;
    return minmax;
}
int main()
{
    shm();
    int len = 6;
    int a[len], i;
    for (i = 0; i < len; ++i) {
        cin >> a[i];
    }
    struct Pair ans = getMinMax(a, 0, len - 1);
    cout << "Min" << ans.min << endl;
    std::cout << "Max" << ans.max << std::endl;
}

