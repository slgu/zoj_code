#include<stdio.h>
#include<string.h>

const int MaxM = 15000;
const int MaxN = 1001;

int bcj[MaxN];
int Ancestor(int i)
{
while( bcj[i] != i)
    i = bcj[i];
return i;
}
void Connect(const int &a,const int &b)
{
if(bcj[a] == 0)
    bcj[a] = a;
if(Ancestor(b) == 0)
    bcj[b] = Ancestor(a);
else
    bcj[Ancestor(b)]=Ancestor(a);
}

struct edge
{
int x;
int y;
int weight;
};

edge e[MaxM];
int eId;

int eIndex[MaxN];
int edx;

void QuickSock(int left, int right)
{
int i = left, j = right;
edge tmp = e[left];
while(i<j)
{
    while(i < j && e[j].weight > tmp.weight)
     j--;
    if(i < j)
    {
     e[i]=e[j];
     i++;
    }
    else
     break;
    while(i < j && e[i].weight <= tmp.weight)
     i++;
    if(i < j)
    {
     e[j]=e[i];
     j--;
    }
}
e[i]=tmp;
if(i-1>left)QuickSock(left, i-1);
if(i+1<right)QuickSock(i+1, right);
}

int main()
{
//freopen("in.txt","r",stdin);
int n, m;
while(scanf("%d%d", &n, &m)!=EOF)
{
    int MaxW = 0;
    memset(bcj, 0, sizeof(bcj));
    eId = 0;
    edx = 0;
    while( m-- )
    {
     scanf("%d%d%d", &e[eId].x , &e[eId].y, &e[eId].weight);
     eId++;
    }

    QuickSock(0,eId-1);

    for(m = 0; m < eId; m++)
    {
     if( (Ancestor(e[m].x) != Ancestor(e[m].y)) || Ancestor(e[m].x) == 0 || Ancestor(e[m].y) == 0 )
     {
      if(e[m].weight > MaxW)
       MaxW = e[m].weight;
      Connect(e[m].x,e[m].y);
      eIndex[edx] = m;
      edx++;
     }
     if(edx >= n)
      break;
    }
    printf("%d\n%d\n", MaxW,n-1);
    for( m=0; m<edx; m++)
     printf("%d %d\n", e[eIndex[m]].x, e[eIndex[m]].y);
}
return 0;
}

