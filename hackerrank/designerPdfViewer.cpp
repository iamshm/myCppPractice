
#include <bits/stdc++.h>
#include <conio.h>

using namespace std;
int designerPdfViewer(vector<int> h, string word)
{
    int len = word.length();
    int height = -1;
    for (int i = 0; i < len; i++)
    {
        if (h[word[i] - 'a'] > height)
        {
            height = h[word[i] - 'a'];
        }
    }
    height = height * len;
    return height;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //when using this output will be displayed only after building
    // during active debug it doesnt dispaly output
    cin.tie(NULL);
    vector<int> h = {1, 3, 1, 3, 1, 4, 1, 3, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7};
    string word = "zaba";
    cout << designerPdfViewer(h, word);

    getch();
}