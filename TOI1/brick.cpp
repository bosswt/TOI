#include <cstdio>
using namespace std;
char table[21][21];
int main()
{
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0; i<n; i++)
                scanf("%s",table[i]);
        for(int j=0; j<m; j++)
        {
                int k;
                scanf("%d",&k);
                int i;
                for(i=0; i<n; i++) if(table[i][j] != '.') break;
                i--;
                for(; i>=0 && k>0; i--,k--)
                        table[i][j] = '#';
        }
        for(int i=0; i<n; i++)
                printf("%s\n",table[i]);
}
