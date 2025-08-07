//Author: Muhtasim (20.7.25)
// LCS using recursion.


#include<bits/stdc++.h>
using namespace std;

int lcs(string &s1, string &s2, int m, int n){
    if (m == 0 || n == 0)
        return 0; //base case

    if (s1[m - 1] == s2[n - 1])
        return 1 + lcs(s1, s2, m - 1, n - 1);

    else {
        return max(lcs(s1, s2, m, n - 1),
        	lcs(s1, s2, m - 1, n));
    }
}

int main() {
    string s1 ,s2;
    cin>>s1>>s2;
    int m = s1.size();
    int n = s2.size();

    cout << "Length of LCS: " << lcs(s1, s2, m, n);

    return 0;
}
