#include<iostream>
#include<cstdlib>

using namespace std;

//�ǵݹ�
/* int find(int*arr,int k)
{
    int i=k;
     while(arr[i]!=k)
     {
        i=arr[i];
     }
     return i;
}  */

//�ݹ�
int find(int*arr,int k)
{
    int i=k;
    if(arr[i]!=k)
    {
        return arr[i]=find(arr,arr[i]);
    }
    return  i;
}

void unnion(int*arr,int u,int v)
{
      arr[v]=u;
}

int main()
{
    int people=0;
    cout<<"����������"<<endl;
    cin>>people;
    int*arr=new int[people];
    for(int i=0;i<people;i++)
    {
       arr[i]=i;
    }
    int relationship;
    int u,v;
    cout<<"�������ϵ��"<<endl;
    cin>>relationship;
    for(int i=0;i<relationship;i++)
    {
        cin>>u>>v;
        unnion(arr,find(arr,u),find(arr,v));
    }
    cout<<endl;
    while(1)
{    cout<<"������������"<<endl;
    cin>>u>>v;
    if(arr[u]==arr[v])
    cout<<"YES"<<endl;
    else
    cout<<"NO"<<endl;}

    return 0;
}