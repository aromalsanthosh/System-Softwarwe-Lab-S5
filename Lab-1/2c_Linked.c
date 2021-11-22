#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int tot_blocks, n_files, empty_blocks;
int initialize(bool blocks[], int next[], int SB[], int EB[])
{
    for (int i = 0; i < tot_blocks; i++)
    {
        blocks[i] = false; // 0 - block free
        next[i] = -1;      // gives next bl_no
    }
    for (int i = 0; i < n_files; i++)
    {
        SB[i] = -1; // Starting Block_nos
        EB[i] = -1; //Ending Block_nos
    }
    return 0;
}
int getBN(bool blocks[])
{
    int j = 0, val = -1;
    srand(time(0));
    while (j == 0 && empty_blocks > 0)
    {
        val = rand() % tot_blocks;
        if (blocks[val] == false)
        {
            blocks[val] = true;
            j = 1;
        }
    }
    return val;
}
int main()
{
    int i, j;
    printf("\n Enter the total number of blocks : ");
    scanf("%d", &tot_blocks);
    printf(" Enter total number of files : ");
    scanf("%d", &n_files);
    bool blocks[tot_blocks];
    int next[tot_blocks];
    int SB[n_files];
    int EB[n_files];
    int fileLen[n_files]; //Contains length of each file
    int val, prev;
    empty_blocks = tot_blocks;
    initialize(blocks, next, SB, EB);
    printf("\n Enter the length of the each file : \n");
    for (i = 0; i < n_files; i++)
    {
        printf(" File %d - ", i);
        scanf("%d", &fileLen[i]);
    }
    for (i = 0; i < n_files; i++)
    {
        if (fileLen[i] <= empty_blocks)
        {
            j = 1;
            SB[i] = getBN(blocks);
            j++;
            prev = SB[i];
            while (j <= fileLen[i])
            {
                next[prev] = getBN(blocks);
                prev = next[prev];
                j++;
                empty_blocks--;
            }
            EB[i] = prev;
        }
    }
    printf("\n File no. Starting block Ending Block\n");
    for (i = 0; i < n_files; i++)
    {
        if (SB[i] != -1)
            printf(" %d %d %d\n", i, SB[i],
                   EB[i]);
        else
            printf(" %d Couldn't be allocated\n", i);
    }
    printf("\n File no.\t Path\n");
    for (i = 0; i < n_files; i++)
    {
        printf(" %d\t ", i);
        if (SB[i] != -1)
        {
            int p = SB[i];
            while (p != -1)
            {
                printf(" %d -> ", p);
                p = next[p];
            }
            printf(" NULL\n");
        }
        else
            printf(" None");
    }
    printf("\n");
    return 0;
}