

# include <stdio.h>



void printi(int *tab,int *tab_b,int size,int indexa)
{
    int i = size;
    printf("-----------------------------------------\n");
    while(i>=0)
    {
        if(i<=indexa)
            printf("|\t%d\t\t||\t",tab[i]);
        else
            printf("|\t\t\t||\t");
        if(i<+size-indexa)
            printf("%d\t|\n",tab_b[i]);
        else
            printf("\t|\n");
        
        
        // printf("|\t%d\t\t||\t%d\t|\n",tab[i],tab_b[i]);
        i--;
    }
    printf("|\t-\t\t||\t-\t|\n|\tA\t\t||\tB\t|\n-----------------------------------------\n\n");
}