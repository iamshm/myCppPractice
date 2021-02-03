#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
string kangaroo(int x1, int v1, int x2, int v2)
{
    string res;
    if (x1 == x2 && v1 == v2)
    {
        res = "YES";
    }
    else if (x1 == x2 && v1 > v2)
    {
        res = "NO";
    }
    else if (x1 <= x2 && v1 <= v2)
    {
        res = "NO";
    }
    else
    {
        if (((x2 - x1) % (v1 - v2)) == 0)

        {
            res = "YES";
        }
        else
        {
            res = "NO";
        }
    }
    return res;
}
int main()
{
    // ios::sync_with_stdio(false);
    cout << kangaroo(0, 2, 5, 3);
    getch();
}