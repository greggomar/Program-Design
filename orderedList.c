#include "orderedList.h"
#include <assert.h>

Node *orderedInsert(Node *p, int newval)
/*********************************************************\
* Allocates a new Node with data value newval and inserts *
* into the ordered list with first node pointer p in such *
* a way that the data values in the modified list are in  *
* nondecreasing order as the list is traversed.           *
\*********************************************************/
{
   Node *q = (Node*)malloc(sizeof(Node));
   Node *tmp = p;
   q->data = newval;
   if (!p || newval <= p->data)
   {  
      q->next = p;
      return q;
   }
   while (tmp->next && tmp->next->data <= newval)
   {
      tmp = tmp->next;
   }
   q->next = tmp->next;
   tmp->next = q;
   return p;
}

void printList(FILE *outfile, Node *p)
/*********************************************************\
* Prints the data values in the list with first node      *
* pointer p from first to last, with a space between      *
* successive values. Prints newline at end of the list.   *
\*********************************************************/
{
   Node *prn = p;
   if(!prn) return;
   fprintf(outfile, "%d", prn->data);
   while(prn->next)
   {
      prn = prn->next;
      fprintf(outfile, " %d", prn->data);
   }
   fprintf(outfile, "\n");
   return;
}

void clearList(Node **p)
/*********************************************************\
* Deletes all nodes in the list with first node pointer   *
* *p, resulting in *p having value NULL. Note that we are *
* passing a pointer by address so we can modify that      *
* pointer.                                                *
\*********************************************************/
{
   Node *fre = *p;
   while(*p)
   {
      *p = (*p)->next;
      free(fre);
      fre = *p;
   }
   return;
}