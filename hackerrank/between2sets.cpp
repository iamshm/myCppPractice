#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

int getTotalX(vector<int> a, vector<int> b)
{
    vector<int> res;
    int as = a.size();
    vector<int>::iterator end = b.begin();
    vector<int> temp;
    int flag = 0;

    for (int i = a[as - 1]; i <= *end; i++)
    {
        for (int x : a)
        {
            if (i % x == 0)
            {
                flag++;
            }
        }


        if (flag == as)
        {
            temp.push_back(i);
        }
        flag = 0;
    }

    for (int i : temp)
    {
        for (int j : b)
        {
            if (j % i == 0)
            {
                flag++;
            }
        }
        if (flag == b.size())
        {
            res.push_back(i);
        }
        flag = 0;
    }

    return res.size();
}

int main()
{
    vector<int> a = {2, 4};
    vector<int> b = {16, 32, 96};
    int c = getTotalX(a, b);

    cout << c << "size" << endl;
    getch();
}