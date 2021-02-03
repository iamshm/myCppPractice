#include <bits/stdc++.h>
using namespace std;

void shm() {
#ifndef ONLINE_JUDGE
    freopen("D:\\cpp\\input.txt", "r", stdin);
    freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
}

//when the input is in sorted format which means that the first activity will have the least finish time
void maxActivities (vector<int> s,vector<int> f,int n)
{
    int i=0;
    std::cout << "Selected Activites" << std::endl;
    std::cout << i << std::endl; //first job will always be selected
    for (int j = 1;  j < n; ++ j) {
        if(s[j]>=f[i]){
            std::cout << j << std::endl;
            i=j;
        }
    }
}

void sortedInputs(){
    std::vector<int> s = {1,3,0,5,8,5};
    std::vector<int> f = {2,4,6,7,9,9};
    int n = s.size();
    maxActivities(s,f,n);
}

bool sortbySecond(const pair<int,int> &a, const pair<int,int> &b) { return  (a.second < b.second);}

void maxAct2(vector<pair<int,int>> arr){
    sort(arr.begin(),arr.end(),sortbySecond);
    std::cout << "In an unsorted input selected activites are" << std::endl;
    auto i = arr.begin();
    std::cout << "("<< i->first<<","<<i->second<<")" << std::endl;
    for(auto j = arr.begin()+1;j!=arr.end();j++)
        if(j->first>=i->second)
        {
            std::cout << "(" << j->first <<"," <<j->second <<")" << std::endl;
            i=j;
        }
}

void unSortedInputs(){
    vector<pair<int,int> > arr ;
    arr.push_back(make_pair(5,9));
    arr.push_back(make_pair(1,2));
    arr.push_back(make_pair(3,4));
    arr.push_back(make_pair(0,6));
    arr.push_back(make_pair(5,7));
    arr.push_back(make_pair(8,9));

    maxAct2(arr);
}

int main()
{
    shm();
    sortedInputs();
    unSortedInputs();
    return 0;
}

