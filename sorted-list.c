/*
 * sorted-list.c
 *
 *  Created on: Oct 2, 2012
 *      Author: chensiyuan2010
 */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "sorted-list.h"
Index *Index_create(void *data)
{
	Index *node;
	if(!(node=malloc(sizeof(Index)))) return NULL;
	node->fn=data;
	node->count=0;
	node->next=NULL;
	return node;
}

NODE *node_create(void *data)
{
	NODE *node;
	if(!(node=malloc(sizeof(NODE)))) return NULL;
	node->data=data;
	node->next=NULL;
	return node;
}

NODE * countCreate(CompareFuncT cf){
	NODE* re=malloc( sizeof( NODE ) );;

	re->cp=cf;
	re->head=malloc( sizeof( NODE) );
	re->cp=(CompareFuncT)malloc( sizeof( CompareFuncT) );//should malloc;
	re->head->node=NULL;
	return re;

}

SortedListPtr SLCreate(CompareFuncT cf){
	    SortedListPtr	SL ;
	    SortedListPtr	h;

	   SL= malloc( sizeof( SortedListPtr ) );
	SL->cp=(CompareFuncT)malloc( sizeof( CompareFuncT) );
	  SL->cp=cf;
	 // h=malloc( sizeof( SortedListPtr ) );
	// SL->head=h;
	  SL->head=malloc( sizeof( SortedListPtr ) );
	  SL->head->node=NULL;

	return SL;

}
void SLDestroy(SortedListPtr list){
	free(list);
}

int SLInsertCount(NODE * list, void *newObj,char * fn){

	Index * p;
	p=Index_create(NULL);
	Index * new=Index_create(fn);
	new->count=newObj;
	Index *dex=Index_create(NULL);


	if(list->node==NULL){
		list->node=new;
		list->head->node=list->node;
		return 1;
	}
	else{
		for(p=list->node;p!=NULL;p=p->next){
			if(list->cp(p->count,newObj)<0){
				list->node=new;
				list->node->next=p;
				list->head->node=list->node;
				return 1;
			}
			else if(list->cp(p->count,newObj)>=0&&p->next==NULL){


				p->next=new;

				return 1;
			}

			else if(p->next!=NULL){
				if(list->cp(p->count,newObj)>=0&&list->cp(p->next->count,newObj)<0){  // list->cp(p->next->data,newObj<0)

				new->next=p->next;
				p->next=new;


				return 1;
			 }
			}
	}


  }

	return 1;
}
int SLInsert(SortedListPtr list, void *newObj,char *filen){

	NODE * p;
	p=node_create(NULL);
	NODE * new=node_create(newObj);

	Index *dex=Index_create(filen);


	if(list->node==NULL){
		list->node=new;
		new->temp=dex;//n    the first run cat
		new->temp->count++;//n
		list->head->node=list->node;
		return 1;
	}
	else{
		for(p=list->node;p!=NULL;p=p->next){
			if(list->cp(p->data,newObj)<0){
				list->node=new;
				list->node->next=p;
				new->temp=dex;//n
						new->temp->count++;//n
						list->head->node=list->node;
				return 1;
			}
			else if(list->cp(p->data,newObj)>=0&&p->next==NULL){

				if(list->cp(p->data,newObj)==0){
					p->temp->count++;
					break;
				}
				p->next=new;
				new->temp=dex;//n
						new->temp->count++;//n
				return 1;
			}

			else if(p->next!=NULL){
				if(list->cp(p->data,newObj)>=0&&list->cp(p->next->data,newObj)<0){  // list->cp(p->next->data,newObj<0)
					if(list->cp(p->data,newObj)==0){
						p->temp->count++;
						break;
					}
				new->next=p->next;
				p->next=new;
				new->temp=dex;//n
						new->temp->count++;//n
				return 1;
			 }
			}
	}


  }

	return 1;
}

int SLRemove(SortedListPtr list, void *newObj){
	NODE *	p=node_create(NULL);
		p=list->head->node;
		if(p==NULL){
			return 0;
		}
		if(list->cp(p->data,newObj)==0){
			list->head->node=p->next;
			return 1;
		}
		for(;p->next!=NULL;p=p->next){
			if(list->cp(p->next->data,newObj)==0){
				p->next=p->next->next;
				return 1;
			}
		}

	return 0;
}

SortedListIteratorPtr SLCreateIterator(SortedListPtr list){

		NODE *p =malloc(sizeof(NODE));
		SortedListIteratorPtr	ret;
		ret= (SortedListIteratorPtr)malloc( sizeof( SortedListIteratorPtr ) );
		SortedListPtr head=malloc( sizeof( SortedListPtr ) );
			p=list->head->node;//wrong

			ret->ptr=p;
		return ret;
}

void SLDestroyIterator(SortedListIteratorPtr iter){
	free(iter);
}

void *SLNextItem(SortedListIteratorPtr iter){

		NODE * p= iter->ptr;
			 if(p!=NULL){



		iter->ptr=iter->ptr->next;


		return p;
			 }
			 return NULL;

}
	Index *CountNextItem(Index * head){

		//Index * p= malloc(sizeof(Index));
	Index*	p=head;

		//printf("the nextItem is %d\n",head->count);
			 if(p!=NULL){



		head=head->next;


		return p;
			 }
			 return NULL;
}
