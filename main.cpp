#include <iostream>
using namespace std;
int cifMax(int n)
{
    int max=-1;
    while(n)
    {
        if((n%10)>max)
            max=n%10;
        n=n/10;
    }
    return max;
}

int cifMin(int n)
{
    int min=10;
    while(n)
    {
        if((n%10)<min)
            min=n%10;
        n=n/10;
    }
    return min;
}

bool ok=std::cin.eof();

int main()
{
    int x[40],n=0,i,j,k;
    while(!ok)
    {
        cin>>x[n++];
        ok=std::cin.eof();
    }
    n--;
    for(k=0;k<10;k++)
    {
        int v[40]={0},nr=0;
        for(i=0;i<n;i++)
            if(cifMin(x[i])==k)
            {
                v[nr]=x[i];
                nr++;
            }
        for(i=0;i<nr-1;i++)
            for(j=i+1;j<nr;j++)
            {
                if(cifMax(v[i])>cifMax(v[j]))
                    swap(v[i],v[j]);
                else if(cifMax(v[i])==cifMax(v[j]))
                        if(v[i]>v[j])
                            swap(v[i],v[j]);
            }
        for(i=0;i<nr;i++)
            cout<<v[i]<<" ";
    }
    return 0;
}
