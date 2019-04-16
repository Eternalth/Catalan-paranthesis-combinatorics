#include <iostream>
#include <cmath>
using namespace std;
long long b,d,c,coefficient[1000],n,m,num[1000],p=0,k;

int binomialCoeff(long long b, long long d)
{
  if (d==0 || d==b)
    return 1;
 
  return  binomialCoeff(b-1, d-1) + binomialCoeff(b-1, d);
}
 
int main()
{
  num[1]=1;
  cin>>m; //length
  cin>>n; //depth
  for(int k=1; k<=n; k++)
  {
    for(int i=0; i<=k; i++)
    {
      c=c+(pow(-1,k+i)*binomialCoeff(i+2*n-2*k+1,i));
    }
    coefficient[k] = c;
    c=0;
  }
  
  for(int j=1; j<=m/2; j++)
  {
   for(int i=1; i<m/2-(n-1); i++)
    {
      k=j-(i-1);
      if(k<0) k=0;
      p=p+pow(-1,i-1)*num[k]*coefficient[i];
    }
    num[j+1] = p;
    p=0;
  }
  cout<<num[m/2-(n-1)];
}
