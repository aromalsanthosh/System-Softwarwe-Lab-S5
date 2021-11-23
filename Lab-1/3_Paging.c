#include<stdio.h>
#include<stdlib.h>

int main()
{ 
    int np,ps,i; //np = no of pages, ps = page size
    int *sa; //start address
    
    printf("enter how many pages\n");
    scanf("%d",&np);
    printf("enter the page size \n");
    scanf("%d",&ps);

    sa=(int*)malloc(2*np); //allocate memory for start address and end address
    
    for(i=0;i<np;i++)
    {
        sa[i]=(long)malloc(ps); //allocate memory for pages
        printf("page%d\t address %u\n",i+1,sa[i]); //print the start address of each page
    }

}
