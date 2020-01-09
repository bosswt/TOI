#include <iostream>
#include <algorithm>
using namespace std;
int l,k;
string lock1,lock2,key;
void middle(int i,int j,char &ans)
{
  int ch[3];
  ch[0] = lock1[i]-'A';
  ch[1] = lock2[i]-'A';
  ch[2] = key[j]-'A';
  sort(ch,ch+3);
  ans = ch[1]+'A';
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>l>>k;
  cin>>lock1>>lock2>>key;
  for(int i=0;i<l;i++)
  {
    for(int j=k-1;j>=0;j--)
    {
      char ans;
      middle(i,j,ans);
      key[j] = ans;
    }
  }
  cout<<key;
}
