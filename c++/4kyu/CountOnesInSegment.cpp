/**
* Given two numbers: 'left' and 'right' (1 <= 'left' <= 'right' <= 200000000000000) 
* return sum of all '1' occurencies in binary representations of numbers between 'left' and 'right' 
* (including both)
*
* Example:
* countOnes 4 7 should return 8, because:
* 4(dec) = 100(bin), which adds 1 to the result.
* 5(dec) = 101(bin), which adds 2 to the result.
* 6(dec) = 110(bin), which adds 2 to the result.
* 7(dec) = 111(bin), which adds 3 to the result.
* So finally result equals 8.
**/

#include <iostream>

int find_set_bits(int n, int count) 
{
    if ( n <= 0 ) return count;
    return  find_set_bits(n>>1, count + (n & 1));
}

/**
 * Simple brute force solution
 */
int simple(int m, int n) 
{
    int count = 0;
    while (m <=n ) count += find_set_bits(m++, 0);
    return count;
}

/**
 * Using fact: that for 2^b - 1 numbers (1, 3, 7, 15, 31..), the number of set bits is b * 2^(b-1).
 */


using llong = unsigned long long;

llong find_set_bits_adv(int last){ 
    int two = 2;
    llong res = 0; 
    int n = last; 
    while( n ){ 
        res += ( last / two ) * ( two >> 1 ); 
        if( ( last & ( two - 1 ) ) > ( two >> 1 ) - 1 ) res += ( last & ( two - 1 ) ) - ( two >> 1 ) + 1; 
        two <<= 1; 
        n >>= 1; 
    } 
    return res; 
}


//4250829:231192380 =131546184 
int main()
{
    int l = 4250829;
    int r = 231192380;
    //std::cout << "simple " << l << ":" << r << "=" << simple(l, r) << std::endl;
    std::cout << "adv " << l << ":" << r << "=" << (find_set_bits_adv(r) - find_set_bits_adv(l-1)) << std::endl;
}