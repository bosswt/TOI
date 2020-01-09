#include "/Users/boss_wt/stdc++.h"
using namespace std;
string A,B,C;
int n;
bool is_interleaved()
{
        int m = A.length();
        int n = B.length();
        bool table[m+1][n+1];
        memset(table,0,sizeof(table));
        for(int i=0; i<=m; i++)
        {
                for(int j=0; j<=n; j++)
                {
                        if(i==0 && j==0) table[i][j] = true;
                        else if(i==0 && B[j-1] == C[j-1]) table[i][j] = table[i][j-1];
                        else if(j==0 && A[i-1] == C[i-1]) table[i][j] = table[i-1][j];
                        else if(A[i-1] == C[i+j-1] && B[j-1] != C[i+j-1]) table[i][j] = table[i-1][j];
                        else if(B[j-1] == C[i+j-1] && A[i-1] != C[i+j-1]) table[i][j] = table[i][j-1];
                        else if(A[i-1] == C[i+j-1] && B[j-1] == C[i+j-1]) table[i][j] = (table[i][j-1] || table[i-1][j]);
                }
        }
        return table[m][n];
}
int main()
{
        cin>>A>>B;
        cin>>n;
        for(int i=0; i<n; i++)
        {
                cin>>C;
                if(C.length() == A.length() + B.length() && is_interleaved())
                        cout<<"Yes\n";
                else cout<<"No\n";
        }
}
