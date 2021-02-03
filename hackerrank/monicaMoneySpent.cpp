
#include <iostream>
#include <conio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int getMoneySpent(vector<int> keyboards, vector<int> drives, int b)
{
    int cost = 0;
    int s = keyboards.size();
    int d = drives.size();
    set<int, greater<int>> res;

    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < d; j++)
        {
            cost = keyboards[i] + drives[j];

            if (cost <= b)
            {
                res.insert(cost);
            }
        }
    }
    if (!res.empty())
    {
        cost = *res.begin();
    }
    else

    {
        cost = -1;
    }
    return cost;
}

int main()
{
    int n = 5;
    vector<int> a = {4};
    vector<int> b = {5};
    int c = getMoneySpent(a, b, n);

    cout << c << "cost" << endl;
    getch();
}