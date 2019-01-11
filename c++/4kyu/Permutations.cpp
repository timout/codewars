#include <string>
#include <vector>
#include <iostream>
#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * Find all unique permutation of a string
 * 
 */

void permutations(int s, string str, unordered_set<string> & pset)
{
    if ( s == str.size() - 1 ) {
        cout << str << endl;
        pset.insert(str);
    } else {
        permutations(s+1, str, pset);
        for ( int i = s+1; i < str.size(); ++i ) {
            char c = str[s];
            str[s] = str[i];
            str[i] = c;
            permutations(s+1, str, pset);
            str[i] = str[s];
            str[s] = c;
        }
    }
}

vector<string> permutations(string str)
{
    unordered_set<string> pset;
    permutations(0, str, pset);
    vector<string> v(pset.begin(), pset.end());
    return v;
}

int main()
{
    vector<string> v = permutations("1234");
    for ( string & s : v ) cout << s << endl;
}