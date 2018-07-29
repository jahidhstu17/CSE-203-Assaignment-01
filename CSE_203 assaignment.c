#include <stdio.h>
#include <stdlib.h>
int arr[6757],size;
void view()
{
    int i;
    printf("Array is:");
    for(i=1; i<=size; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}
void newelement()
{
    int item,pos,i,*s;
    printf("Enter the ITEM to be selected :");
    scanf("%d",&item);//Take item from user.
    printf("Enter position of ITEM:");
    scanf("%d",&pos);
    for(i=size; i>=pos; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos]=item;
    s=&size;
    *s=*s+1;
    view();
}
void search()
{
    int item,loc=0,i=1;
    printf("Enter an ITEM that you want to selected:");
    scanf("%d",&item);
    for(i=1; i<=size; i++)
    {
        if(arr[i]==item)
        {
            loc=i;
            printf("%d is found in location %d\n",item,loc);
        }
    }
    if(loc==0)
    {
        printf("ITEM not found");
    }
}
void del()
{
    int x=size;
    int item,loc=0,i=1,j,*s,ok=0;
    printf("Enter an item to be deleted:");
    scanf("%d",&item);
    for(i=1; i<=size; i++)
    {
        if(ok==1 && i!=1)
        {
            i--;
            ok=0;
        }
        if(arr[i]==item)
        {
            loc=i;
            for(j=loc; j<=size-1; j++)
            {
                arr[j]=arr[j+1];
            }
            //delete(arr[j+1]);
            size--;
            ok=1;
            //size=size-1;
            //*s=*s-1;
        }
    }
    if(loc==0)
    {
        printf("ITEM not found");
    }
    else
    {
        view();
    }
}
void asort()
{
    int i,ptr,swap;
    for(i=1; i<=size; i++)
    {
        for(ptr=1; ptr<=size-i; ptr++)
        {
            if(arr[ptr]>arr[ptr+1])
            {
                swap=arr[ptr];
                arr[ptr]=arr[ptr+1];
                arr[ptr+1]=swap;
            }
        }
    }
    printf("Sorted list in ascending order:\n ");
    view();
}
void dsort()
{
    int i,ptr,swap;
    for(i=1; i<=size-1; i++)
    {
        for(ptr=1; ptr<=size-i; ptr++)
        {
            if(arr[ptr]=arr[ptr+1])
            {
                swap=arr[ptr];
                arr[ptr]=arr[ptr+1];
                arr[ptr+1]=swap;
            }
        }
    }
    printf("Sorted list in descending order:\n");
    view();
}
void mem()
{
    int p,i,index,ad,loc;
    p=*arr+1;
    printf("Enter the index:[N.B. index 1 means first element]:");
    scanf("%d",&index);
    index--;
    if(index>size)
    {
        printf("Your given index is invalid:");
    }
    else
    {
        ad=p+sizeof(int)*index;
        printf("Teh %dth element is allocated in location %d",index+1,ad);
    }
}
void choose()
{
    int choice;
    printf("Enter your choice:\n1.view\n2.insert\n3.search\n4.delete\n5.ascending sorting\n6.descending sorting\n7.memory allocation\n");
    while(scanf("%d",&choice)!=0)
    {
        if(choice==1)
        {
            view();
        }
        else if(choice==2)
        {
            newelement();
        }
        else if(choice==3)
        {
            search();
        }
        else if(choice==4)
        {
            del();
        }
        else if(choice==5)
        {
            asort();//asort calling function.
        }
        else if(choice==6)
        {
            dsort();//dsort calling function.
        }
        else if(choice==7)
        {
            mem();//calling function.
        }

    }
}
void more()
{
    int more;
    printf("Do you want to do perform extra job? if YES,enter 1; otherwise enter 0:");
    scanf("%d",&more);
    if(more==1)
    {
        system("cls");
        choose();
    }
    else
        exit;
}
int main()
{
    int i,choice,decide;
    printf("Enter array size:");
    scanf("%d",&size);
    printf("Enter array elements:");
    for(i=1; i<=size; i++)
    {
        scanf("%d",arr+i);
    }
    printf("Dear user ,are you interested to work...if YES press 1,else 0\n");
    scanf("%d",&decide);
    if(decide==1)
    {
        choose();
    }
    else
        exit;
}
