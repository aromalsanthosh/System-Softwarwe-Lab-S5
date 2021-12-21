// use 'gcc 3_Paging.c' -lm to compile

#include<stdio.h>
#include<math.h>
int frametable[50],pt = 0,frame_no;

void paging(int page_no)
{
	int i;
	if(pt + page_no > frame_no)
	{
		printf("Cannot store the program as the frame table is full \n");
		return;
	}
	printf("Storing the program in frames of frame table\n");
	for(i = pt;i<pt + page_no;i++)
	{
		frametable[i] = 1;
		printf("%d -> %p \n",i,&frametable[i]);
	}
	pt = i;
	printf("\n");
}
void main()
{
	int fs,pts,fts,page_no,status;
	for(int j = 0;j<50;j++)
	{
		frametable[j] = 0;
	}
	printf("Enter the size of frame table in bytes\n");
	scanf("%d",&fts);
	printf("Enter the size of a frame in bytes \n");
	scanf("%d",&fs);
	frame_no = ceil(fts/fs);
	printf("Total possible frames = %d \n",frame_no);
	while(1)
	{
		printf("Enter 1 to store a program in the memory\nEnter 2 to exit\n");
		scanf("%d",&status);
		if(status == 1)
		{
			printf("Enter size of program in bytes\n");
			scanf("%d",&pts);
			page_no = ceil(pts/fs);
			paging(page_no);
		}
		else
			break;
	}
}
// #include<stdio.h>
// #include<stdlib.h>

// int main()
// { 
//     int np,ps,i; //np = no of pages, ps = page size
//     int *sa; //start address
    
//     printf("enter how many pages\n");
//     scanf("%d",&np);
//     printf("enter the page size \n");
//     scanf("%d",&ps);

//     sa=(int*)malloc(2*np); //allocate memory for start address and end address
    
//     for(i=0;i<np;i++)
//     {
//         sa[i]=(long)malloc(ps); //allocate memory for pages
//         printf("page%d\t address %u\n",i+1,sa[i]); //print the start address of each page
//     }

// }

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