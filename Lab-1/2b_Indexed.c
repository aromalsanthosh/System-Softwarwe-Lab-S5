#include<stdio.h>
#include<stdlib.h>

int main()
{
	int total_no_of_blocks, ind_block, n, c;
	int i,j,k;
	printf("\n Enter the total number of blocks : ");
	scanf("%d",&total_no_of_blocks);
	int no_of_empty_blocks = total_no_of_blocks;
	int f[total_no_of_blocks];
	for(i = 0;i < total_no_of_blocks; i++) //initializing unallocated blocks to 0
		f[i+1] = 0;
		
	printf("\n Before Allocation : \n");
	for( i = 0; i < total_no_of_blocks; i++)
	{
		if(f[i+1] == 0)
			printf(" %d : Not Allocated \n",i+1);
		else
			printf(" %d : Allocated \n",i+1);		
	}
	printf("\n");
	x :
	if(no_of_empty_blocks > 0)
	{
		printf(" Enter the index block : ");
		scanf("%d",&ind_block);
		if(f[ind_block] == 0)
		{
			f[ind_block] = 1;
			printf(" Enter the number of blocks to be indexed : ");
			scanf("%d",&n);
			if(no_of_empty_blocks < n)
			{	
				printf(" Not enough blocks left !\n");
				exit(0);
			}
		}
		else
		{
			printf(" Block is already allocated !\n");
			goto x;
		}
		int indexed[n];
		printf(" Enter the content(s) of the index block :\n");
		for(i = 0; i < n; i++)
		{	
			scanf("%d",&indexed[i+1]);
			if(indexed[i+1] == ind_block)
			{
				printf(" Cannot index the index block again !\n");
				f[ind_block] = 0;
				goto x;
			} 
		}
			
		for(i = 0; i < n; i++)
		{	if(f[indexed[i+1]] == 1 )
			{
				printf(" Block is already allocated !\n");
				f[ind_block] = 0;
				goto x;
			}
		}
		for(j = 0;j < n; j++)
			f[indexed[j+1]] = 1;
		
		no_of_empty_blocks -= (n+1);	
		printf(" Allocation has been done successfully !");
		printf("\n File Indexed :\n");
		for(k = 0; k < n; k++)
		{
			if(f[indexed[k+1]] == 1)
				printf(" %d->%d : Allocated \n",ind_block,indexed[k+1]);
			else 
				printf(" %d->%d : Not Allocated \n",ind_block,indexed[k+1]);
		}
		
		printf("\n After Allocation :\n");
		for(k = 0; k < total_no_of_blocks; k++)
		{
			if(f[k+1] == 0)
				printf(" %d : Not Allocated\n",k+1);
			else
					printf(" %d : Allocated\n",k+1);
		}	
		printf("\n Enter '1' to continue and '0' to exit : ");
		scanf("%d",&c);
		if(c == 1)
			goto x;
		else 
			exit(0);
	}
	else
	{
		printf(" No more empty blocks available !\n");
		exit(0);
	}
	return 0;
}