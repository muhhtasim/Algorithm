#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,amount;
    cout<<"Enter the number of coins :";
    cin>>n;
    int coin[n];
    cout<<"Enter those coin :"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>coin[i];
    }
    cout<<"Enter the amount :"<<endl;
    cin>>amount;
    int table[n+1][amount+1];
    int choice[n+1][amount+1];
    for(int i=0; i<=n; i++)
    {
        table[i][0]=0;
    }
    for(int j=1; j<=amount; j++)
    {
        table[0][j]=amount+1;
        choice[0][j] = -1;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=amount; j++)
        {
            if(j>=coin[i-1])
            {
                table[i][j]=min (table[i-1][j],(1+table[i][j-coin[i-1]]));
                choice[i][j] = i;
            }
            else
            {
                table[i][j]=table[i-1][j];
                choice[i][j] = choice[i-1][j];
            }
        }
    }

    cout<<"Minimum number of coin :"<<table[n][amount]<<endl;

    cout << "Coins used: ";
     int j = amount;
    while (j > 0)
    {
        int i = choice[n][j];
        if (i == -1) break;
        int coinUsed = coin[i - 1];
        cout << coinUsed << " ";
        j -= coinUsed;
    }
    cout << endl;



    return 0;
  
}

