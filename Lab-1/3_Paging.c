#include<stdio.h>
#include<stdlib.h>

int main()
{ 
    int np,ps,i;
    int *sa;
    
    printf("enter how many pages\n");
    scanf("%d",&np);
    printf("enter the page size \n");
    scanf("%d",&ps);

    sa=(int*)malloc(2*np);
    
    for(i=0;i<np;i++)
    {
        sa[i]=(long)malloc(ps);
        printf("page%d\t address %u\n",i+1,sa[i]);
    }

}
