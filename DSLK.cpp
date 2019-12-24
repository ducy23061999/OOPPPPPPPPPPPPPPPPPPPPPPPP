// #include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
		int data;
		struct Node *next;
	}list;
	list  *cuoi,*dau;
	void xoa(int n)
{
	list *p= dau;
	list *r;
	int d=0;
	while(p!=NULL)
	{
		d++;
		if(d==n)
		{
		r->next=p->next;
		free(p);
		break;	
		}
		r=p;
		p=p->next;	
	}	
}
void chen(int s)
{
    list *p = (list *)malloc(sizeof(list));    
    p->data = s;                   
    p->next = NULL;  
    if (dau == NULL)                   
        dau = p;
    else
   		cuoi->next = p;
    cuoi = p;                               
}
int Tong()
{
	int s=0;
    list *p = dau;
    while (p != NULL) {
    	if(p->data%2!=0) {
            s=s+p->data;
        } else {
            s=s-p->data;
        }
            
        p = p->next;
	}
    return s;
}
void hienthiDS()
{
    list *p = dau;
    while (p != NULL)
    {
        printf("%d ", p->data);        
        p = p->next;
    }
}
int main()
{
	list *head;
	dau=NULL;cuoi=NULL;
	int i,tam,ixoa;
	int a[1000];
	char c;
	do{
		scanf("%c",&c);
		if(c=='i')
		{
			scanf("%d",&tam);
			chen(tam);
		}
		else
		if(c=='s')
		{
			printf("%.2d\n",Tong());
		}
		else
		if(c=='0')
		break;
	}while(c!='0');
	return 0;
}
