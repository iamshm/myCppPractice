
#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

string angryProfessor(int k, vector<int> a)
{
    int count = 0;
    string res;
    for (int i : a)
    {
        if (i <= 0)
        {
            count++;
        }
    }
    cout << count;

    if (count < k) //k=3 count=2
    {
        res = "YES";
    }
    else
    {
        res = "NO";
    }
    return res;
}
int main()
{
    vector<int> a = {1, -1, 2, 0};
    // ios::sync_with_stdio(false);
    cout << angryProfessor(2, a);

    getch();
}
