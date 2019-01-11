#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Longest Common Subsequence for 2 strings
 * Dynamic programming approach
 * TODO: add optimization: same start/end ..
 */
string lcs( string str1, string str2 )
{
    cout << "1=["<< str1 << "]" << " 2=[" << str2 << "]" << endl;
    int size1 = str1.size();
    int size2 = str2.size();
    vector<vector<int>> path(size1+1, vector<int>(size2+1, 0));
    int i = 1;
    for ( char c1 : str1 ) {
        int j = 1;
        for ( char c2: str2 ) {
            if ( c1 == c2 ) {
                path[i][j] = path[i-1][j-1] + 1;
            } else {
                path[i][j] = max(path[i][j-1], path[i-1][j]);
            }
            ++j;
        }
        ++i;
    }
    cout << "evaluated:" << path[size1][size2] << endl;
    if ( path[size1][size2] == 0 ) return "";
    string res(path[size1][size2], ' ');
    i = size1;
    int j = size2;
    int ssi = path[size1][size2] - 1;
    while ( i > 0 && j > 0 ) {
        if ( str1[i-1] == str2[j-1] ) {
            cout << '|';
            res[ssi] = str1[i-1];
            i -= 1;
            j -= 1;
            ssi -= 1;
            cout << res << '|' << i<< '|' << j << '|' << ssi << endl;
        } else if ( path[i][j-1] > path[i-1][j] ) {
            j -= 1;
        } else {
            i -= 1;
        }
    }
    return res;
}

int main()
{
    string seq = lcs("nothardlythefinaltest", "zzzfinallyzzz");
    cout << "lcs=[" << seq << "]" << endl;
}

