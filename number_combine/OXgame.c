#include <stdio.h>
#define size 3
int judge(int numofo,int numofx)
{
    int result;
    if(numofo == size){result =0;}
    else if (numofx == size){result=1;}
    return result;
}
int main()
{
    int board[size][size];
    int i , j;
    int numofx,numofo;
    int result;//-1没胜，1：x胜，0：O胜

    for (i = 0;i<size;i++)
    {
        for (j=0;j<size;j++)
        {
            scanf ("%d",&board[i][j]);
        }
    }
    //检查行
    for(i=0;i<size&&result ==-1;i++)
    {
        numofo = numofx =0;//统计ox的数量
        for (j=0;j<size;j++)
        {
            if(board[i][j]){numofx++;}
            else           {numofo++;}
            
        }
        
    }
    result = judge( numofo,numofx);
    //列
    for (j=0;j<size;j++)
    {
        numofo =numofx =0;
        for(i=0;i<size;i++)
        {
            if(board[i][j]==1){numofx++;}
            else{numofo++;}
        }
    result = judge( numofo,numofx);
        
        
    }

    //斜着
    numofo =numofx =0;
    for(i=0;i<size;i++)
    {
        if(board[i][i]==1){numofx++;}
        
        else {numofo++;}
    }
    result = judge( numofo,numofx);

    numofo =numofx =0;
    for (i=0;i<size;i++);
    {
        if (board[i][size -i-1]==1){numofx++;}
    }
    

    
}