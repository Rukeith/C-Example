#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 3
#define PARK_COST 0.05
#define ROUTEWAY_COST 0.02

//時間
typedef struct time
{
    int hour;
    int min;
}Time;

//車的訊息
typedef struct car
{
    char num[15]; /*車牌號碼*/
    Time reach;   //到達時間
    Time leave;   //離開時間
    float style;  //車的型號
    float cost1;
    float cost2;
}Car;

//停車場（棧）
typedef struct stack
{
    Car* stack[CAPACITY+1];
    int top;  //棧頂
}Park_Stack;

//隊列節點
typedef struct car1
{
    Car* data; //車的訊息
    struct car1* next; 
}QueueNode;

//通道(隊列)
typedef struct queue
{
    QueueNode * head; //隊頭
    QueueNode * rear; //隊尾
}Routeway_Queue;

//初始化停車場
void InitPark_Stack(Park_Stack* s)
{
    int i;
    s->top=0;   //Park_Stack s -> top
    for(i=0;i<=CAPACITY;i++)
        s->stack[i]=NULL; //初始化不設定數值
}

//初始化通道
void InitRoute_Queue(Routeway_Queue* q)
{
    q->head=(QueueNode*)malloc(sizeof(QueueNode));
       //設定QueueNode大小的儲存空間給head
    if(q->head!=NULL)
    {
       q->head->next=NULL; //Routeway_Queue q -> QueueNode head -> next
       q->rear=q->head;  //head初始化後rear也初始化
    }
}

//車輛到達
void Arrive(Park_Stack * park,Routeway_Queue * routeway)
{
    int tag;
    Car* p=(Car*)malloc(sizeof(Car));
    QueueNode *t=(QueueNode *)malloc(sizeof(QueueNode));
    printf("\n 輸入車號(如:9999):\n");
    scanf("%s",p->num);
    printf("選擇型號\n");
    printf("1.客車: \n2.卡車: \n3.小汽車: \n");
    scanf("%d",&tag);
    switch(tag)
    {
        case 1:
        {
            p->style=1.5;
            break;
        }
        case 2:
        {
            p->style=3.0;
            break;
        }
        case 3:
        {
            p->style=1.0;
            break;
        }
        default:
            break;
    }
    p->cost1=p->cost2=0;

    //紀錄進入的時間
    if(park->top<CAPACITY) //停車場有空位
    {
        park->top++;
        printf("\n 停車場中第%d 號位置.",park->top);
        printf("\n 請輸入到達時間:/**:**/");
        scanf("%d:%d",&(p->reach.hour),&(p->reach.min));
        park->stack[park->top]=p;
    }
    else  //停車場沒有位置,要到通道等待
    {
        printf("\n 通道中等待!");
        printf("\n 輸入進入時間:/**:**/");
        t->data=p;
        scanf("%d:%d",&(t->data->reach.hour),&(t->data->reach.min));
        t->next=NULL;
        routeway->rear->next=t;
        routeway->rear=t;
    }
}

void Show(Car* p,int room)
{
    int A1,A2,B1,B2;    
    float S,m;
    printf("\n 輸入離開時間:/**:**/");
    scanf("%d:%d",&(p->leave.hour),&(p->leave.min));
    printf("\n 離開車的車號為:");
    puts(p->num);
    printf("\n 車輛到達時間為: %d:%d",p->reach.hour,p->reach.min);
    printf("離開時間為: %d:%d",p->leave.hour,p->leave.min);
    A1=p->reach.hour;
    A2=p->reach.min;
    B1=p->leave.hour;
    B2=p->leave.min;
    S=p->style;
    p->cost2=((B1-A1)*60+(B2-A2))*PARK_COST*S;
    m=p->cost1;
    printf("\n 停車場費用為: %2.1f 元",p->cost2);
    printf("\n 總費用為: %2.1f 元",m+p->cost2);
}

//離開停車場
void Leave_Park(Park_Stack* park,Routeway_Queue* routeway)
{
    int C1,C2,D1,D2;
    float S;
    int room;
    Car *p,*t;
    QueueNode *q;
    Park_Stack temp;
    Park_Stack * Temp=&temp;
    InitPark_Stack(Temp);

    if(park->top>0)
    {
        while(1)
        {
            printf("\n 輸入停車位/1--%d/: ",park->top);
            scanf("%d",&room);
            if(room>=1&&room<=park->top)
                break;
        }
        while(park->top>room)
        {
            Temp->top++;
            Temp->stack[Temp->top]=park->stack[park->top];
            park->stack[park->top]=NULL;
            park->top--;
        }
        p=park->stack[park->top];
        park->stack[park->top]=NULL;
        park->top--;
        while(Temp->top=1)
        {
            park->top++;
            park->stack[park->top]=Temp->stack[Temp->top];
            Temp->stack[Temp->top]=NULL;
            Temp->top--;
        }
 
        Show(p,room);

        if((routeway->head!=routeway->rear)&&(park->top<CAPACITY))
        {
          q=routeway->head->next;
          t=q->data;
          park->top++;
          printf("\n 通到的車牌號為%s 的車道停車場的第%d 位置",t->num,park->top);
          printf("\n 輸入當前時間/**:**/:");

          C1=t->reach.hour;
          C2=t->reach.min;
          scanf("%d:%d",&(t->reach.hour),&(t->reach.min));
          D1=t->reach.hour;
          D2=t->reach.min;
          S=t->style;
          t->cost1=((D1-C1)*60+(D2-C2))*ROUTEWAY_COST*S;

          printf("\n 待停車費為%2.1f",t->cost1);

          routeway->head->next=q->next;
          if(q==routeway->rear)
            routeway->rear=routeway->head;
          park->stack[park->top]=t;
          free(q);
        }
        else printf("\n 通道中沒有車輛等候\n");
    }
    else printf("\n停車場內無車\n");
}

//向隊列中插入一元素
void pushqueue(Routeway_Queue *w,Car x)
{
    int i,n;
    QueueNode *p;
    p=(QueueNode *)malloc(sizeof(QueueNode));
    p->data=(Car*)malloc(sizeof(Car));
    
    if(p==NULL)
    {
        printf("內存空間分配失敗!\n");
        exit(1);
    }

    p->data->reach.hour=x.reach.hour;
    p->data->reach.min=x.reach.min;
    p->data->style=x.style;

    n=strlen(x.num);
    for(i=1;i<=n;i++)
        p->data->num[i-1]=x.num[i-1];
        
    p->data->num[i-1]='\0';
    p->next=NULL;

    if(w->rear==NULL)
        w->head=w->rear=p;
    else
        w->rear=w->rear->next=p;
}

//隊列中刪除隊首元素, 並返回原隊首元素
Car popqueue(Routeway_Queue *w)
{
    int i,n;
    QueueNode *p;
    Car temp;

    //若隊列為空,則停止運行
    if(w->head==NULL)
    {
        printf("\n 隊列為空, 無法刪除! \n");
        exit(1);
    }
    
    //temp.cost=0
    temp.reach.hour=w->head->next->data->reach.hour;
    temp.reach.min=w->head->next->data->reach.min;

    n=strlen(w->head->next->data->num);
    for(i=1;i<=n;i++)
        temp.num[i-1]=w->head->next->data->num[i-1];
    temp.num[i-1] = '\0';

    temp.style=w->head->next->data->style;
    temp.leave.hour=temp.reach.hour;
    temp.leave.min=temp.reach.min;

    p=w->head;
    w->head=p->next;

    if(w->head==NULL)
        w->rear=NULL;
    free(p);
    return temp;  
}

//從通道離開
void Leave_Routeway(Routeway_Queue *routeway)
{
    int len=0;
    int i,loca,Hour,Min,a,b;
    float weight,fee3;
    QueueNode *p;
    Car first,last;

    p=routeway->head->next;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }

    if(len==0)
    {
        printf("\n 通道內沒有車輛\n");
        return;
    }

    printf("\n 通道現在有%d 輛車,輸入離開通道車的位置:",len);
    scanf("%d",&loca);

    for(i=1;i<=(loca-1);i++)
    {
        first=popqueue(routeway);
        pushqueue(routeway,first);
    }

    last=popqueue(routeway);
    printf("\n 通道內車牌號為%s 的車離開",last.num);
    printf("\n 輸入當前的時間(**:**) :");
    scanf("%d:%d",&Hour,&Min);

    a=last.reach.hour;
    b=last.reach.min;
    weight=last.style;
    fee3=((Hour-a)*60+(Min-b))*ROUTEWAY_COST*weight;
    printf("\n 在通道的待停車費為:%2.1f\n",fee3);
}


//顯示停車場的清單
void List_Park(Park_Stack * park)
{
    int i;
    if(park->top>0)
    {
        printf("\n 停車場清單:");
        printf("\n 位置  車牌號  到達時間\n");
        for(i=1;i<=park->top;i++)
        {
            printf("%d    ",i);
            printf("%s     ",park->stack[i]->num);
            printf("%d:%d",park->stack[i]->reach.hour,park->stack[i]->reach.min);
            printf("\n");
        }
    }
    else
        printf("\n 停車場內暫時沒有車輛!");
}


//顯示通道的清單
void List_Routeway(Routeway_Queue * routeway)
{
    QueueNode * p;
    p=routeway->head->next;
    if(routeway->head !=routeway->rear)
    {
        printf("\n 在通道中等待的車牌號如下:\n");
        while(p!=NULL)
        {
            puts(p->data->num);
            p=p->next;
        }
    }
    else
        printf("\n 通道內暫時沒有車輛!");
}


//顯示清單
void List(Park_Stack * park,Routeway_Queue * routeway)
{
    int t;
    int flag=1;
    while(flag)
    {
        printf("\n 選擇想查看的對應信息:");
        printf("\n1.停車場  2.通道  3.不查看\n");
        while(1)
        {
            scanf("%d",&t);
            if(t>=1 && t<=3)
                break;
            else
                printf("\n 無效!請選擇1--3");
        }
        switch(t)
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
            default:
                break;
        }
    }
}



//系統管理函數
void Manage()
{
    int t1,t2;
    int flag=1;
    
    Park_Stack park;
    Routeway_Queue routeway;
    InitPark_Stack(&park);
    InitRoute_Queue(&routeway); //初始化停車場和通道

    while(1)
    {
        printf("**************************************************\n");
        printf("*--------------------停車場管理系統-------------------*\n");
        printf("**************************************************\n");
        printf("\n1.到達 2.離開 3.清單 4.退出\n");
        while(1)
        {
            scanf("%d",&t1);
            if(t1>=1 && t1<=4)
                break;
            else
                printf("\n 無效!請選擇:1-4");
        }
        
        switch(t1)
        {
            case 1:   //到達
                Arrive(&park,&routeway);
                break;
            case 2:   //離開
            {
                while(flag)
                {
                    printf("\n 選擇離開地點:1.停車場  2.通道  3.不離開\n");
                    while(1)
                    {
                      scanf("%d",&t2);
                      if(t2>=1 && t2<=3)
                        break;
                      else
                        printf("\n 無效!請選擇1-3:\n");
                    }
 
                    switch(t2)
                    {
                      case 1:
                        Leave_Park(&park,&routeway);
                        break;
                      case 2:
                        Leave_Routeway(&routeway);
                        break;
                      case 3:
                        flag=0;
                        break;
                      default:
                        break;
                    } 
                }
                
                flag=1;
                break;  
            }
            case 3:   //清單
              List(&park,&routeway);
              break;
            case 4:   //退出
              return;
            default:
              break;
        }
    }
}

void main()
{
    Manage();
}

