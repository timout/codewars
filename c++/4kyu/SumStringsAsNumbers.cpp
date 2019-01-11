/**
 * Sum Strings as Numbers
 */
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

string sumStrings(string i1, string i2)
{
    if ( i1.empty() && i2.empty() ) return "";
    if ( i1.empty() ) return i2;
    if ( i2.empty() ) return i1;
    int size = max(i1.size(), i2.size());
    string res(size+1, '0');
    auto it1 = i1.rbegin();
    auto it2 = i2.rbegin();
    int t = 0;
    int ci = size;
    while ( it1 != i1.rend() && it2 != i2.rend() ) {
        int n = (*it1 - '0') + (*it2 - '0') + t;
        string nstr = to_string(n);
        res[ci] = ( nstr.size() == 2 ) ? nstr[1] : nstr[0];
        t = ( nstr.size() == 2 ) ? 1 : 0;
        --ci;
        ++it1;
        ++it2;
    }
    auto rest = [&res, &ci, &t](char c) {
        int n = (c - '0') + t;
        string nstr = to_string(n);
        res[ci] = ( nstr.size() == 2 ) ? nstr[1] : nstr[0];
        t = ( nstr.size() == 2 ) ? 1 : 0;
        --ci;
    };
    while ( it1 != i1.rend() ) {
        rest(*it1);
        ++it1;
    }
    while ( it2 != i2.rend() ) {
        rest(*it2);
        ++it2;
    }
    if ( t > 0 ) res[ci] = '1';
    int prefix = res.find_first_not_of("0");
    if ( prefix == string::npos ) {
        prefix = ( res[0] == '0' ) ? res.size() - 1 : 0;
    } 
    return res.substr(prefix);
}

int main()
{
    string res = sumStrings(
    "0082894476439555021798165715055383585122077944468738774565062512170803202208665540537183892063392573825245124870843852131569119566078694327706711398522880713669578550082785576", 
    "605557937118497546401429817565137803618541481355997059160119854536897971031166958875083295190553155042175401398185885227");
    cout << res << endl;
    cout << sumStrings("0", "0") << endl;
}