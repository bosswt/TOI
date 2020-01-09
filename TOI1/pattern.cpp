#include <cstdio>
int min(int a,int b)
{
        return a<b ? a : b;
}
int row;
int col;
int len,n;
int m = -1;
char cloth[50001][71];
int main()
{
        scanf("%d",&n);
        for(int i=0; i<n; i++) for(int j=0; j<70; j++) cloth[i][j] = 'o';
        for(int i=0; i<n; i++)
        {
                scanf("%d %d %d",&row,&col,&len);
                if(row > m)
                        m = row;
                for(int j=col; j<min(col+len,71); j++)
                        cloth[row-1][j-1] = 'x';
        }
        for(int i=0; i<m; i++)
        {
                for(int j=0; j<70; j++)
                {
                        printf("%c",cloth[i][j]);
                }
                printf("\n");
        }
}
/*
   4
   1 1 10
   2 3 9
   3 5 25
   2 20 2
 */
