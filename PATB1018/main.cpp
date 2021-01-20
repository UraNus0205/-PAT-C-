#include <iostream>
#include <algorithm>
using namespace std;
int change(char c)
{
    if(c=='B') return 0;//布
    if(c=='C') return 1;//锤子
    if(c=='J') return 2;//剪刀
}

int main()
{
    int n;
    cin>>n;
    char game[3]={'B','C','J'};
    int x_score[3]={0};/*win,loss,mid*/
    int x_show[3]={0},y_show[3]={0};
    int x_max=0,y_max=0;
    while(n--)
    {
        x_max=0,y_max=0;//要初始化
        char x,y;
        cin>>x>>y;
        int x1=change(x);
        int y1=change(y);

        if((x1+1)%3==y1) x_score[0]++,x_show[x1]++;
        else if(x1==y1) x_score[1]++;
        else x_score[2]++,y_show[y1]++;

        for(int i=0;i<3;i++)
        {
            if(x_show[i]>x_show[x_max]) x_max=i;
            if(y_show[i]>y_show[x_max]) y_max=i;
        }
    }
        cout<<x_score[0]<<" "<<x_score[1]<<" "<<x_score[2]<<endl;
        cout<<x_score[2]<<" "<<x_score[1]<<" "<<x_score[0]<<endl;
        cout<<game[x_max]<<" "<<game[y_max];
    return 0;
}
