//Implementation of Hashing with collision and resolution
//Author: Manish Tomar
//Date: April 21,2013

#include <stdio.h>
#include <conio.h>
#include <malloc.h>

main()
{
    int size,key,n,address,*arr,temp,i;

    printf("\n***************************************************************");
    printf("\nCollision Resolution Technique : Quadratic Probing");
    printf("\nThe Hash Function is Key modulo TableSize");
    printf("\nThe Table Size must be atleast two times the Total Numbers.");
    printf("\n***************************************************************");
    printf("\n\nEnter Table Size : ");
    scanf("%d",&size);

    arr=(int*)malloc(sizeof(size));
    for(i=0;i<size;i++)
        arr[i]=-1;
    printf("\nHow Many Items? ");
    scanf("%d", &n);
    printf("\nEnter %d Keys\n",n);
    for(i=0;i<n;i++)
    {
        int j=1;
        scanf("%d",&key);
        address=key%size;
        printf("\nH(%d modulo %d)=%d", key,size,address);
        temp=address;
        if(arr[address] == -1)
            arr[address]=key;
        else
        {
            while(arr[temp] != -1)
            {
                printf("\t(Collision occurs, Rehash required)\n");
                temp=address+(j*j);
                if(temp >= size)
                temp=temp - size;
                printf("\tH'=%d + %d=%d",address,(j*j),temp);
                j++;
            }
            address=temp;
            arr[address]=key;
        }
    }
    printf("\n\n************");
    printf("\nHash Table\n");
    printf("************");
    printf("\n");
    for(i=0;i<size;i++)
    {
        if(arr[i] != -1)
            printf("\n%d \t %d",i,arr[i] );
        else
            printf("\n%d",i);
    }
printf("\n");
getch();
return 0;
}

/*input:25 46 75 29 36 53 68 89 117 120 140*/
