//nums with even no of digits
#include<stdio.h>
int main()
{
    int x,i,y[5],num,dc;
    int even;
    x=0;
    while(x<=4)
    {
      printf("Enter a number: ");
      scanf("%d",&y[x]);
      fflush(stdin);
      x++;
    }
    x=0;
    even=0;
    while(x<=4)
    {
        if(y[x]<0)
        {
         num=y[x]*(-1);
        }
        else{
         num=y[x];
        }
        dc=1;
       while(num>9)
        {
          dc++;
          num=num/10;
        }
        
     //printf("The number of digits in (%d) is/are %d.\n",y[x],dc);
      if(dc%2==0)
      {
        even++;
      }
     x++;
    }
    printf("%d",even);
    
    return 0;
}