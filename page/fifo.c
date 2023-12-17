#include <stdio.h>

void main()
{
    int i, j, n, pg[100], m, fr[100], k = 0, fnd = 0, cnt = 0, hit = 0;
    printf("ENTER THE NUMBER OF PAGES : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("ENTER THE PAGE NUMBER %d: ", i + 1);
        scanf("%d", &pg[i]);
    }
    printf("ENTER THE NUMBER OF FRAMES : ");
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        fr[i] = -1;
    }
    printf("\n\tREFERENCE STRING \t\t  STATUS\t PAGE NUMBER\n");
    for (i = 0; i < n; i++)
    {
        fnd = 0;
        printf("\t\t%d\t\t",pg[i]);
        for (j = 0; j < m; j++)
        {
            if (pg[i] == fr[j])
            {
                fnd = 1;
                hit++;
            }
        }

        // updating frame
        if(fnd == 0){
            fr[k] = pg[i];
            k = (k +1)%m;
            cnt++;
        }

        // printing hit or miss
        if(fnd == 0) printf("\tmiss\t");
        else printf("\thit\t");

        // printing the frame tab
        for(j = 0; j <m; j++){
            if(fr[j] != - 1)
            printf("%d ",fr[j]);
        }
        printf("\n");
    }
    printf("hit = %d miss = %d\n",hit,cnt);
}