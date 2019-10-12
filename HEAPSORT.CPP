#include<stdio.h>
#include<conio.h>
void heapify(int a[],int i,int n)
{
     int left,right,t=0,max;
     left=2*i;
     right=2*i+1;
     if((left<=n)&&(a[left]>a[i]))
     max=left;
     else
     max=i;
     if(right<=n&&a[right]>a[max])
     max=right;

     if(i!=max)
     {
	t=a[i];
	a[i]=a[max];
	a[max]=t;
	heapify(a,max,n);
     }
}
void build(int a[],int n)
{
  int m,j;
  m=n/2;
  for(j=m;j>=1;j--)
  heapify(a,j,n);
}
void hs(int a[],int n)
{ int j,t=0;
 build(a,n);
 for(j=n;j>1;j--)
 {
 t=a[j];
 a[j]=a[1];
 a[1]=t;
 heapify(a,1,j-1);
 }
}
void main()
{
   int n,i,a[50];
   clrscr();
   printf("Enter number of elements:");
   scanf("%d",&n);
   printf("Enter elements:");
   for(i=1;i<=n;i++)
   scanf("%d",&a[i]);
   hs(a,n);
   printf("Elements after sorting:");
   for(i=1;i<=n;i++)
   printf("%d    ",a[i]);
   getch();
}