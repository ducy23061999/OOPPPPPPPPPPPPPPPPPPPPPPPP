#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
typedef struct Node{
	int data;
	struct Node * next;
}List;
void InsertLast(List *&head, int ele){
	List *n_node = (List *)malloc(sizeof(List));
	n_node->data = ele;
	n_node->next = NULL;
	if (head == NULL){
		head = n_node;
	}else{
		List *p= head;
		while(p->next != NULL) p = p->next;
		p->next = n_node;
	}
}
void in(List *&head){
	for (List *p = head; p != NULL; p=p->next){
		printf("%d ",p->data);
	}
}
int max(List *&head){
	int i = 0;
	for (List *p = head; p != NULL; p=p->next){
		i++;
	}
	return i;
}
void Delete(List *&head, int pos){
	int f = max(head);
	if (pos <= f){
		if (pos == 1){
			head = head->next;
		} else
		{
			int dem = 1;
			List *p = head; List *luu = head;
			while(dem < pos){
				luu = p;
				p = p->next;
				dem++;
			}
			luu->next = p->next;
		}
		
	}
}
long long Sum(List *head){
	long long S = 0;
	for (List *p = head; p != NULL; p=p->next){
		if (p->data % 2 == 0){
            S += p->data;
        }  else {
            S -= p->data;
        }
	};
	return abs(S);
}
int main(){
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// #endif
	List *head = NULL;
	char in;
	int T;
	do{
		scanf("%c",&in);
		// main processs
		if (in == 'i') {
			scanf("%d",&T);
			InsertLast(head,T);
		}
		if (in == 's') printf("%lld\n",Sum(head));
		if (in == '0'){
			scanf("%d",&T);
			if (T == 0) break;
		}
			
	}while (1);
}
