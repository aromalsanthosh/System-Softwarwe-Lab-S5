#include <stdio.h>
#include <stdbool.h>
int main()
{
    int i, j, k, tot_blocks, n_blocks, n_files, sb[50], l[50];
    printf("\n Enter the total number of blocks : ");
    scanf("%d", &tot_blocks);
    int memory[tot_blocks];
    for (i = 0; i < tot_blocks; i++)
        memory[i] = -1;
    printf(" Enter the number of files : ");
    scanf("%d", &n_files);
    bool file_alloc[n_files];
    int alloc_info[n_files];
    printf("\n");
    for (i = 0; i < n_files; i++)
    {
        printf(" Enter the starting block number of file %d : ", i + 1);
        scanf("%d", &sb[i]);
        printf(" Enter the length of file %d : ", i + 1);
        scanf("%d", &l[i]);
        sb[i]--;
        file_alloc[i] = 0;
        alloc_info[i] = -1;
    }
    for (i = 0; i < n_files; i++)
    {
        j = sb[i];
        alloc_info[i] = j;
        file_alloc[i] = 1;
        if (memory[j] != -1)
        {
            printf("\n Cannot allocate file %d.", i + 1);
            alloc_info[i] = -1;
            file_alloc[i] = 0;
            continue;
        }
        else
        {
            for (j = sb[i]; j < sb[i] + l[i]; j++)
            {
                if (memory[j] != -1)
                {
                    //printf("\n j : %d", j);
                    printf("\n Not enough space to allocate file %d.",i+1);
                    file_alloc[i] = 0;
                    for(k = j-1;k>=sb[i];k--)
                    {
                        memory[k] = -1;
                    }
                    alloc_info[i] = -1;
                    break;
                }
                memory[j] = i + 1;
            }
        }
    }
    printf("\n\n File allocation information : ");
    printf("\n File no. Starting block no. Length \n");
    for (i = 0; i < n_files; i++)
    {
        if (file_alloc[i] == 1)
        {
            printf(" %d %d %d \n", i + 1,
                   alloc_info[i] + 1, l[i]);
        }
        else if (file_alloc[i] == 0)
        {
            printf(" %d Not allocated %d \n", i + 1,l[i]);
        }
    }
    printf("\n");
    for (i = 0; i < tot_blocks; i++)
        printf(" %d ", memory[i]);
    printf("\n");

        return 0;
}