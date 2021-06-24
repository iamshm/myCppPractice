#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'sortRoman' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY names as parameter.
 */

// storing values of roman nos
int conDecimal(char c) {
    switch (c) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    default:
        return 1;
    }
}

//convert to roman
int romanInt(string s) {
    int res = conDecimal(s[0]);
    for (int i = 1; i < s.size(); i++) {
        res += conDecimal(s[i]);
        if (conDecimal(s[i - 1]) < conDecimal(s[i]))
            res -= 2 * conDecimal(s[i - 1]);
    }
    return res;
}
// comparator for sorting
bool cmp(pair<string, pair<string, int>> name1, pair<string, pair<string, int>> name2) {
    pair<string, int> nam1 = name1.second;
    pair<string, int> nam2 = name2.second;

    if (nam1.first == nam2.first)
        return nam1.second < nam2.second;

    return nam1.first.compare(nam2.first) < 0;
}
vector<string> sortRoman(vector<string> names) {
    map<string, pair<string, int>> name_map;

    //patition acc to space
    for (auto name : names) {
        for (int i = 0; i < name.size(); i++) {
            if (name[i] == ' ') {
                name_map[name] = make_pair(name.substr(0, i), romanInt(name.substr(i + 1)));
            }
        }
    }
    vector<pair<string, pair<string, int>>> sorted_names;
    for (auto it : name_map) {
        sorted_names.push_back(make_pair(it.first, it.second));
    }

    sort(sorted_names.begin(), sorted_names.end(), cmp);
    vector<string> ans;
    for (auto it : sorted_names) {
        ans.push_back(it.first);
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string names_count_temp;
    getline(cin, names_count_temp);

    int names_count = stoi(ltrim(rtrim(names_count_temp)));

    vector<string> names(names_count);

    for (int i = 0; i < names_count; i++) {
        string names_item;
        getline(cin, names_item);

        names[i] = names_item;
    }

    vector<string> result = sortRoman(names);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
