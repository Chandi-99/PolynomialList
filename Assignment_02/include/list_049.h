//Sathmina-CS18049
#include <malloc.h>
#define LIST_049_H_INCLUDED
#define LIST_049_H_INCLUDED
#define MAXLIST 10
#define EMPTY 0
#define FULL MAXLIST

typedef enum {FALSE, TRUE} Boolean;
typedef char ListEntry;
typedef int Position;
typedef struct listnode{
    ListEntry entry;
    struct listnode *next;
}ListNode;

typedef struct{
    int count;
    Boolean full;
    ListNode *head;
}List;

void CreateList(List *l){
    l->count =0;
    l->head = NULL;
    l->full = FALSE;
}

Boolean IsListEmpty(const List *l){
    return (l->head == NULL);
}

Boolean IsListFull(const List *l){
    return (l->full);
}

int ListSize(const List *l){
    return (l->count);
}

ListNode *MakeListNode(ListEntry x){
    ListNode *p =(ListNode *)malloc(sizeof(ListNode));

    if(p){
        p->entry = x;
        p->next = NULL;
    }

    return (p);
}

void SetPosition(Position p, List *l, ListNode **current){
    int count;
    ListNode *q;

    if(p<0 || p>=l->count){
        Error("Attempt to set a position not in the list");
    }
    else{
        q = l->head;
        for(count = 1; count <= p; count++){
            q = q->next;

        }
        *current = q;
    }

}

void InsertList(Position p, ListEntry x, List *l){
    ListNode *newnode, *current;

    if(p<0 || p> ListSize(l)){
        Error("attempt to insert a position not in the list");
    }
    else{
        newnode = MakeListNode(x);
        if(newnode == NULL){
            l->full = TRUE;
            Error("Not enough memory for additional node");
        }
        else{
            if(p==0){
                newnode->next=l->head;
                l->head=newnode;

            }
            else{
                SetPosition(p-1,l,&current);
                newnode->next = current->next;
                current->next = newnode;
            }
            l->count++;
        }
    }
}

void TraverselList(const List *l, void(*Visit)(ListEntry)){
int i;
for(i=0, i< l->count-1;i++){
    (*Visit)(l->enrty[i])
}

}
#endif // LIST_049_H_INCLUDED
