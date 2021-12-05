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

/*
Output:
aromal@Aromal-Nitro-5:~/SS_Lab/System-Software-Lab-S5/Lab-1$ ./a.out 
enter how many pages
6
enter the page size 
4
page1    address 1241164512
page2    address 1241164544
page3    address 1241164576
page4    address 1241164608
page5    address 1241164640
page6    address 1241164672
*/