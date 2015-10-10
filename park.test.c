#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 3
#define PARK_COST 0.05
#define ROUTEWAY_COST 0.02

typedef struct time
{
    int hour;
    int min;
}Time;

typedef struct car
{
    char num[15];
    Time reach;
    Time leave;
    float cost1;  //park
    float cost2;  //routeway
    float style;
}Car;

typedef struct stack
{
    Car* stack[CAPACITY];
    int top;
}Park_Stack;

typedef struct car1
{
    Car* data;
    struct car1* next;
}QueueNode;

typedef struct queue
{
    QueueNode * head;
    QueueNode * rear;
}Routeway_Queue;

void InitPark_Stack(Park_Stack* s)
{
    int i;
    s->top=0;
    for(i=0;i<=CAPACITY;i++)
        s->stack[i]=NULL;
}

void InitRoute_Queue(Routeway_Queue * q)
{
    q->head=(QueueNode*)malloc(sizeof(QueueNode));
    if(q->head!=NULL)
    {
        q->head->next=NULL;
        q->rear=q->head;
    }
}


void Arrive(Park_Stack * park,Routeway_Queue * routeway)
{
    char i;
    int j=1;
    int tag;
    Car* p=(Car*)malloc(sizeof(Car));
    if(park->top>=CAPACITY)
    {
        printf("銝末��嚗�頠撌脩蝛箔�鈭�\n");
        printf("�臬憿����蝑�頠�嚗n");
        while(j=1)
        {
            printf("YES-> Y, NO->N\n");
            scanf("%s",&i);
            switch(i)
                case 'Y' || 'y':
                {
                    printf("蝣箄�撠��喲���敺�\n");
                    InRouteway(Routeway_Queue * routeway);
                    break;
                }
                case 'N' || 'n':
                    printf("����祉頂蝯�\n");
                    return;
        }
    }
    else
    {
        printf("隢撓�亥���蝣�憒�999)嚗n");
        scanf("%s",p->num);
        printf("隢��摮���\n");
        printf("1.摰Ｚ�嚗� 2.�∟�嚗� 3.撠掃頠�  \n");
        scanf("%d",&tag);
        switch(tag)
        {
            case 1:
                p->style=1.5;
                break;
            case 2:
                p->style=3.0;
                break;
            case 3:
                p->style=1.0;
                break;
            default:
                break;
        }
        p->cost1=p->cost2=0;
        park->top++;
        printf("\n\n���港葉蝚�d ��蝵柴�",park->top);
        printf("\n隢撓�亙����/**:**/");
        scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
        park->stack[park->top]=p;
    }
}


void InRouteway(Routeway_Queue * routeway)
{
    int tag;
    QueueNode *q=(QueueNode *)malloc(sizeof(QueueNode));
    printf("隢撓�亙����/**:**/\n");
    scanf("%d:%d",&(q->data->reach.hour),&(q->data->reach.min));
    printf("隢撓�亥���蝣�憒�9999)\n");
    scanf("%s",&(q->data->num));
    printf("隢撓�亥�摮��n");
    printf("1.摰Ｚ�:  2.�∟�:  3.撠掃頠�  \n");
    scanf("%s",&tag);
    switch(tag)
    {
        case 1:
            q->data->style=1.5;
            break;
        case 2:
            q->data->style=3.0;
            break;
        case 3:
            q->data->style=1.0;
            break;
        default:
            break;
    }
    q->next=NULL;
    routeway->rear->next=q;
    routeway->rear=q;
}

void Show(Car * p)
{
    int a1,a2,b1,b2;
    float sum,s;
    printf("隢撓�仿����/**:**/\n");
    scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
    printf("�ａ�頠����:%s",p->num);
    printf("頠��圈����� %d : %d \n",p->reach.hour,p->reach.min);
    printf("頠��ａ����� %d : %d \n",p->leave.hour,p->leave.min);
    a1=p->reach.hour;
    a2=p->reach.min;
    b1=p->leave.hour;
    b2=p->leave.min;
    s=p->style;
    p->cost2=((b1-a1)*60+(b2-a2))*PARK_COST*s;
    sum=p->cost1+p->cost2;
    printf("\n ���游鞎餌�� %2.1f ��,p->cost2);
    printf("\n 蝮質祥�函: %2.1f ��,sum);
    free(p);
}  

void Leave_Park(Park_Stack * park,Routeway_Stack * routeway)
{
    int c1,c2,d1,d2;
    Car *p;
    Park_Stack temp;
    Park_Stack * Temp=&temp;
    QueueNode * q;
    InitPark_Stack(Temp);
    int room;
    while(1)
    {
        if(park->top>0)
        {
            while(1)
            { 
                printf("隢撓�亙�頠�/1--%d/",park->top); 
                scanf("%d",&room);        
                if(room>=1 && room<=park->top)
                    break;  
            }
            while(park->top>=room)
            {
                p=park->stack[park->top];
                park->stack[park->top]=NULL;
                park->top--;
            }
            Show(&p);
            if((routeway->head!=routeway->rear)&&(park->top<CAPACITY))
            {
                park->top++;
                q=routeway->head->next;
                park->stack[park->top]=routeway->head->data;
                printf("\n������蝣潛%s ����頠�洵%d 雿蔭",routeway->head->data.num,park->top);
                printf("\n隢撓�亦����/**:**/");
                scanf("%d:%d",&(park->stack[park->top]->leave.hour),&(park->stack[park->top]->leave.min));
                c1=park->stack[park->top]->reach.hour;
                c2=park->stack[park->top]->reach.min;
                d1=park->stack[park->top]->leave.hour;
                d2=park->stack[park->top]->leave.min;
                
                park->stack[park->top]->cost1=((d1-c1)*60+(d2-c2))*ROUTEWAY_COST*S;
                printf("��蝑���鞎餌嚗�d\n",park->stack[park->top]->cost1);

                routeway->head->next=q->next;
                if(q==routeway->rear)
                    routeway->rear=routeway->head;
                free(q);
            }
            else
                printf(" ���扳���摮���\n");
        }
        else
            printf("���游�∟�嚗n");   
    }
}

Car popqueue(Routeway_Queue * w)
{
    QueueNode *p;
    Car temp;
    
    if(w->head==NULL)
    {
        printf("���箇征嚗瘜��\n");
        exit(1);
    }

    temp.reach.hour=w->head->next->data->reach.hour;
    temp.reach.min=w->head->next->data->reach.min;
    temp.num=w->head->next->data->num;
    temp.style=w->head->next->data->style;


    p=w->head;
    w->head=p->next;

    if(w->head==NULL)
        w->head=p->next;
    free(p);
    return temp;
}

void pushqueue(Routeway_Queue *w,Car x)
{
    QueueNode *p;
    p=(QueueNode *)malloc(sizeof(QueueNode));
    p->data=(Car *)malloc(sizeof(Car));

    if(p==NULL)
    {
        printf("�批�蝛粹���憭望�!\n");
        exit(1);
    }


    p->data->reach.hour=x->reach.hour;
    p->data->reach.min=x->reach.min;
    p->data->style=x.style;
    p->data->num=x.num;
    p->next=NULL;

    if(w.rear==NULL)
        w->head=w->rear=p;
    else
        w->rear=w->rear->next=p;
}

void Leave_Routeway(Routeway * routeway)
{
    int counter=0;
    int i,j,HOUR,MIN,e1,e2;
    float mo;
    Car a,b;
    QueueNode * t;
    t=routeway->head->next;
    while(t!=NULL)
    {
        counter++;
        t=t->next;
    }
    
    if(counter=0)
    {
        printf("\n ���扳���頛�\n");
        return;
    }

    printf("���抒�冽�%d 頛�嚗撓�仿������蝵殷�",counter);
    scanf("%d",&i);
    
    for(j=1;j<=i-1;j++)
    {
        a=popqueue(routeway);
        pushqueue(routeway,a);
    }
    
    a=popqueue(routeway);
    
    for(;j<=counter;j++)
    {
        b=popqueue(routeway);
        pushqueue(routeway,b);
    }
 
    printf("\n ���扯���蝣�s ��撠��\n",b.num);
    pirntf("隢撓�仿����/**:**/: \n");
    scanf("%d:%d",&HOUR,&MIN);
 
    e1=b.reach.hour;
    e2=b.reach.min;

    mo=((HOUR-e1)*60+(MIN-e2))*ROUTEWAY_COST*(b.reach.style);
    printf(" �券��蝑���頠祥�� %2.1f\n",mo);   
}



void List_Park(Park_Stack * park)
{
    int i;
    printf("\n\n ���湔��殷�\n");
    printf("雿蔭  頠��� �圈���\n");
    for(i=1;i<=park->top;i++)
    {
        printf("%d    ",i);
        printf("%s     ",park->stack[i]->num);
        printf("%d:%d    \n",park->stack[i]->reach.hour,park->stack[i]->reach.min);
    }
}

void List_Routeway(Routeway_Queue * routeway)
{
    QueueNode *p;
    p=routeway->head->next;
    if(routeway->head != routeway->rear)
    {
        printf("\n ���抒���頠��Ⅳ憒�嚗�);
        while(p!=NULL)
        {
            puts(p->data->num);
            p=p->next;
        } 
    }
}



void List(Park_Stack *park,Routeway_Queue *routeway)
{
    int t,flag=1;
    while(flag)
    {
        while(1)
        {
            printf(" �豢��單��靽⊥嚗n");
            printf("1.���� 2.��  3.銝�n");
            scanf("%d",&t);
            if(t>=1 && t<=3)
                break;
            else
                printf("頛詨�航炊嚗��活�豢��n");
        }
       
        switch(i)
        {
            case 1:
                List_Park(park);
                break;
            case 2:
                List_Routeway(routeway);
                break;
            case 3:
                flag=0;
                break;
            default :
                break;
        }
    }
}


//選單程式
void Manage()
{
    int i;
    int j=1;
    char charj;
    Park_Stack park;
    Routeway_Queue routeway;
    InitPark_Stack(&park);
    InitRoute_Queue(&routeway);
    printf("***************************************************\n");
    printf("*------------------���渡恣�頂蝯�----------------*\n");
    printf("***************************************************\n");
    while(1)
    { 
        printf("\n1.�脣  2.�ａ�  3.皜  4.��\n");
        scanf("%d",&i);
        if(i>=1 && i<=4)
        {
            switch(i)
            {
                case 1:
                    Arrive(&park,&routeway);
                    break;
                case 2:
                {
                    int k;
                    printf("隢��閬��芷�n");
                    printf("1.���� 2.��  3.銝�n");
                    scanf("%d",&k);
                    switch(k)
                    {
                        case 1:
                            Leave_Park(&park,&routeway);
                            break;
                        case 2:
                            Leave_Routeway(&routeway);
                            break;
                        case 3:
                            break;
                     }

                }
                case 3:
                    List(&park,&routeway);
                    break;
                case 4:
                    while(j=1)
                    {
                        printf("隢Ⅱ摰�衣����ａ�蝟餌絞嚗�);
                        printf("YES-> Y , NO-> N\n");
                        scanf("%s",&charj);
                        switch(charj)
                            case 'Y' || 'y':
                                return;
                            case 'N' || 'n':
                                break;
                    }
            }
        }
        else
            printf("頛詨�航炊嚗��頛詨�n");
    }

}


void main()
{
    Manage();
}
