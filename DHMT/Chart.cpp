#include<stdio.h>
#include<math.h>
#include<graphics.h>
int main()
{
	int gd=DETECT,gm,i,n,sa=0,ea,r=150;
	float data[20],total=0;
	
	printf("\n\aEnter the total number of values to be entered: ");
	scanf("%d",&n);
	printf("\n\aEnter the values one-by-one...\n");
	for(i=1;i<=n;i++)
	{
		scanf("%f",&data[i]);
		total=total+data[i];
	}
    initgraph(&gd,&gm,NULL);
	for(i=1;i<=n;i++)
	{
		setcolor(i);
		ea=data[i];
		ea=ea+sa;
		if(i==n) ea=360;
		
		pieslice(320,240,sa,ea,r);
		sa=ea;
	}
	getch();
	closegraph();
}
