typedef struct LNode *List
struct LNode{
    ElementType Data;
    List Next;
};
struct LNode L;
List PtrL;

List MakeEmpty()
{
    List PtrL;
    PtrL =(List)malloc(sizeof(struct List));
    PtrL->Last=-1;
    return PtrL;
}

int Find(ElementType X,List PtrL)
{
    int i= 0;
    while(i<=PtrL->Last && PtrL->Data[i]!=X)
        i++;
    if(i>PtrL->Last) return -1;
    else return i;
}

void Insert(ElementType X,int i,List PtrL)
{
    int j;
    if(PtrL->Last == MAXSIZE-1)
    {
        printf("表满")；
        return;
    }
    if(i<1||i>PtrL->Last+2)
    {
        printf("位置不hefa")
        return;
    }
    for(j=PtrL->Last;j>=i-1;j--)
        PtrL->Data[j+1]=PtrL->Last[j];
    PtrL->Data[i-1]=X;
    PtrL->Last++;
}

void Delete(int i,List PtrL)
{
    if(i<1 || i > PtrL->Last+1)
    {
        printf("不存在第%d个元素",i);
        return ;
    }
    for(int j=i;j<=PtrL->Last;j++)
        PtrL->Data[j-1]=PtrL->Data[j];
    PtrL->Last--;
    return;
}
----
int Length(List PtrL)
{
    List p = PtrL;
    int j=0;
    while(p)
    {
        p=p->next;
        j++;
    }
    return j;
}

List *FindKth(int k,List *PtrL)
{
    List *p = PtrL;
    int i=0;
    while(p!=NULL&&i<k)
    {
        p=p->Next;
        i++;
    }
    if(i==k)
    {return p;}
    else{return NULL;}

}

void merge(LNode *A,LNode *B,LNode *&C)
{
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *r;
    C=A;
    C->next = NULL;
    free(B);
    r=C;
    ...
}

void find(ElementType X,List PtrL)
{
    List p = PtrL;
    while(p!=NULL&&p->Data!=X)
        p=p->Next;
    return p;
}


List Insert(ElementType X,int i,List PtrL)
{
    List p,s;
    if(i==1)
    {
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=PtrL;
        return s;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL){
        printf("参数i错");
        return NULL;
    }
    else
    {
        s=(List)malloc(sizeof(struct LNode));
        s->Data=X;
        s->Next=p->Next;
        p->Next=s;
        return PtrL;
    }
}

List Delete(int i,List PtrL)
{
    List p,s;
    if(i==1)
    {
        s=PtrL;
        if(PtrL!==NULL) PtrL = PtrL-Next;
        else return NULL;
        free(s);
        return PtrL;
    }
    p=FindKth(i-1,PtrL);
    if(p==NULL)
    {   
        printf("第%d个节点不存在",i-1);
        return NULL;
    }else if(p->Next==NULL)
    {
        printf("第%d个节点不存在",i);
        return NULL;
    }else
    {
        s=p->Next;
        p->Next=s->Next;
        free(s);
        return PtrL;
    }
}