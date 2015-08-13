#include<iostream>
#include<cstring>
using namespace std;
struct node
{
    int x,y;
    int height;
} block[92];
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void gao(int &x,int &y,int &z)
{
    if(x<y)
    {
        swap(&x,&y);
    }

    if(z>x)
    {
        swap(&x,&z);
        swap(&z,&y);
    }
    else
        if(z>y)
        {
            swap(&z,&y);
        }

}
int map[92][92];
int max(int a,int b)
{
    return a>b?a:b;
}
int main()
{
    int n;
    int count=0;
    while(cin>>n,n)
    {
        int maxn=0;
        memset(map,0,sizeof(map));
        memset(block,0,sizeof(block));
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            gao(c,b,a);
            block[3*i-2].x=a;
            block[3*i-2].y=b;
            block[3*i-2].height=c;
            block[3*i-1].x=b;
            block[3*i-1].y=c;
            block[3*i-1].height=a;
            block[3*i].x=a;
            block[3*i].y=c;
            block[3*i].height=b;
        }
        for(int i=1;i<=3*n;i++)
        for(int j=1;j<=3*n;j++)
            if(block[i].x>block[j].x&&block[i].y>block[j].y)
            {
                map[i][j]=block[i].height+block[j].height;
            }
        for(int k=1;k<=3*n;k++)
        for(int i=1;i<=3*n;i++)
        for(int j=1;j<=3*n;j++)
        {
            if(map[i][k]&&map[k][j])
            map[i][j]=max(map[i][k]+map[k][j]-block[k].height,map[i][j]);
        }
        for(int i=1;i<=3*n;i++)
        for(int j=1;j<=3*n;j++)
        if(maxn<map[i][j])
            maxn=map[i][j];
        cout<<"Case "<<++count<<": maximum height = "<<maxn<<endl;
    }
    return 0;
}
