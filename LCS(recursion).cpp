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




/*

#include <bits/stdc++.h>
using namespace std;

string S1, S2;
int dp[1001][1001];

// Recursive function to get length of LCS
int lcs(int m, int n) {
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (S1[m - 1] == S2[n - 1])
        return dp[m][n] = 1 + lcs(m - 1, n - 1);
    else
        return dp[m][n] = max(lcs(m - 1, n), lcs(m, n - 1));
}

// Function to reconstruct LCS string from memo table
string getLCS(int m, int n) {
    string lcsStr = "";
    while (m > 0 && n > 0) {
        if (S1[m - 1] == S2[n - 1]) {
            lcsStr += S1[m - 1];
            m--;
            n--;
        } else if (dp[m - 1][n] > dp[m][n - 1])
            m--;
        else
            n--;
    }
    reverse(lcsStr.begin(), lcsStr.end());
    return lcsStr;
}

int main() {
    cin >> S1 >> S2;
    int m = S1.size(), n = S2.size();

    memset(dp, -1, sizeof(dp));
    int length = lcs(m, n);
    string lcsString = getLCS(m, n);

    cout << "Length of LCS: " << length << endl;
    cout << "LCS: " << lcsString << endl;

    return 0;
}

*/
