#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[10];
    char num[10];
    char sex[10];
    char age[10];
    char record[10];
    char position[15];
    char wanges[10];
    char tel[15];
    char addr[50];

}people;

void Menu();
void Add();
int IsUsed(char * nu);
void Display();
void Search();
void SearchForName();
void SearchForNum();
void SearchForPosition();
void Modify();
void Delete();

void main()
{
    Menu();
}

void Menu()
{
    int m;
    while(1)
    {
        printf("\n\n\n\t\t____________________________________\n");
        printf("\t\t      歡迎進入員工信息管理系統\n");
        printf("\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\n\t\t\t    添加信息, 請按1");
        printf("\n\t\t\t    查找信息, 請按2");
        printf("\n\t\t\t    修改信息, 請按3");
        printf("\n\t\t\t    刪除信息, 請按4");
        printf("\n\t\t\t    瀏覽信息, 請按5");
        printf("\n\t\t\t    退出系統, 請按0\n");
        scanf("%d",&m);
        if(m>=0&&m<=5)
        {
            switch(m)
            {
              case 1:
                Add(); 
                break;
              case 2:
                Search();
                break;
              case 3:
                Modify();
                break;
              case 4:
                Delete();
                break;
              case 5:
                Display();
                break;
              case 0:
                exit(0);
            }
            printf("\n\n操作完畢,請再次選擇！");
        }
        else
            printf("\n\n選擇錯誤,請再次選擇！");
    }
}


void Add()
{
    people one;
    FILE *fp;
    int flag=0;

    if((fp=fopen("workers","ab"))==NULL)
    {
        printf("\n打開該文件失敗！");
        exit(0);
    }
    printf("\n---請依次輸入要添加的員工信息---\n");
    printf("\n姓    名： ");
    scanf("%s",one.name);
    printf("\n 員 工 號: ");
    scanf("%s",one.num);

    while(!flag)
    {
        flag=IsUsed(one.num);
        if(!flag)
        {
          printf("\n您輸入的員工號不可用, 請重新輸入:  ");
          scanf("%s",one.num);
        }
    }
    printf("\n 性    別: ");
    scanf("%s",one.sex);
    printf("\n 年    齡: ");
    scanf("%s",one.age);
    printf("\n 最高學歷: ");
    scanf("%s",one.record);
    printf("\n 職    務: ");
    scanf("%s",one.position);
    printf("\n 薪    水: ");
    scanf("%s",one.wanges);
    printf("\n 聯繫電話: ");
    scanf("%s",one.tel);
    printf("\n 住    址: ");
    scanf("%s",one.addr);

    if(fwrite(&one,sizeof(people),1,fp)!=1)
        printf("寫文件錯誤！\n");
    fclose(fp);
}

int IsUsed(char * nu)
{
    FILE *fp;
    people one;
    
    if((fp=fopen("workers","rb"))==NULL)
    {
        printf("\n 不能打開文件！ ");
        exit(0);
    }

    fread(&one,sizeof(people),1,fp);
    while(!feof(fp))
    {
        if(strcmp(nu,one.num)==0)
        {
            fclose(fp);
            return 0;
        }
        fread(&one,sizeof(people),1,fp);
    }
    fclose(fp);
  
    return 1;
}


void Display()
{
    people one;
    FILE *fp;

    if((fp=fopen("workers","rb"))==NULL)
    {
        printf("\n 打開文件失敗！");
        exit(0);
    }

    printf("\n\n%20s\n","---以下為所有員工信息---");
    printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n","姓名","員工號","性別","年齡","最高學歷","職務","薪水","聯繫電話","住址");
    fread(&one,sizeof(people),1,fp);
    while(!feof(fp))
    {
    
        printf("%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
        fread(&one,sizeof(people),1,fp);
    }
    fclose(fp);
}


void Search()
{
    int i;
    printf("\t\t\t\t＊ 按員工查找請按 1＊\n");
    printf("\t\t\t\t＊ 按員工號查找請按 2\n＊");
    printf("\t\t\t\t＊ 按職位閘找請按 3＊\n");
    scanf("%d",&i);
    if(i>0&&i<4)
    {
        switch(i)
        {
        case 1: 
          SearchForName();
          break;
        case 2:
          SearchForNum();
          break;
        case 3:
          SearchForPostition();
          break;
        }
        printf("\n\n 查找完畢!!!");
    }
    else
        printf("\t\t\t\t 輸入完畢!!!");
}

void SearchForName()
{
    FILE *fp;
    people one;
    int k=0;
    char na[10];
    printf("\n 請輸入你要查找的員工姓名：");
    scanf("%s",na);
    
    if((fp=fopen("workers","rb"))==NULL)
    {
        printf("\n不能打開文件! ");
        exit(0);
    }

    fread(&one,sizeof(people),1,fp);
    while(!feof(fp))
    {

        if(strcmp(na,one.name)==0)
        {
            k++;
            if(k==1)
            {
              printf("\n\n 查找姓名為%s的紀錄, 詳細信息為: \n",na);
              printf("\n-10s-8s-5s-5s-10s-8s-8s-10s-15s\n","姓名","員工號","性別","年齡","最高學歷","職務","薪水","聯繫電話","住址");
            }
            printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
        }
        fread(&one,sizeof(people),1,fp);
    }
    if(k==0)
        printf("\n\n 對不起, 查無此人! ");
    else
        printf("\n\n 此次查找共找到%d 條姓名為%s 的紀錄!\n",k,na);
    fclose(fp);
}

void SearchForNum()
{
    int k=0;
    char nu[10];
    FILE *fp;
    people one ;
    printf("\n請出入您要查詢的員工號\n");
    scanf("%s",nu);

    if((fp=fopen("workers","rb"))==NULL)
    {
        printf("\n 打開文件失敗! ");
        exit(0);
    }

    fread(&one,sizeof(people),1,fp);
    while(!feof(fp))
    {
        if(!strcmp(nu,one.num))
        {
            k=1;
            printf("\n\n 查到員工號為%s 的紀錄, 詳細信息為: \n",nu);
            printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n","姓名","員工號","性別","年齡","最高學歷","職務","薪水","聯繫電話","住址");
            printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
        }
        fread(&one,sizeof(people),1,fp);
    }
    if(!k)
        printf("\n\n 對不起, 查無此人! ");
    fclose(fp);
} 

void SearchForPosition()
{
    int k=0;
    char pos[15];
    FILE *fp;
    people one;
    printf("\n 請輸入您要查詢的職務\n");
    scanf("%s",pos);
    
    if((fp=fopen("workers","rb"))==NULL)
    {
        printf("\n 打開文件失敗! ");
        exit(0);
    }
    fread(&one,sizeof(people),1,fp);
    while(!feof(fp))
    {
        if(strcmp(pos,one.position)==0)
        {
            k++;
            if(k==1)
            {
              printf("\n\n查到職務為%s 的紀錄, 詳細信息為: \n",pos);
              printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n","姓名","員工號","性別","年齡","最高學歷","職務","薪水","聯繫電話","住址");
            }
            printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
        }
        fread(&one,sizeof(people),1,fp);
    }
    if(k==0)
        printf("\n\n 對不起, 查無此人! ");
    else
        printf("\n\n 此次查找共找到%d 條職務為%s 的紀錄!\n",k,pos);
    fclose(fp);
}

void Modify()
{
    int k=0;
    long a;
    char nu[10];
    FILE *fp;
    people one;
    printf("\n 請輸入你要修改的員工的員工號: ");
    scanf("%s",nu);
    
    if((fp=fopen("workers","rb+"))==NULL)
    {
        printf("\n 打開文件失敗! ");
        exit(0);
    }

    a=ftell(fp);
    fread(&one,sizeof(people),1,fp);
    while(!feof(fp))
    {
        if(strcmp(nu,one.num))
        {
            k=1;
            break;
        }
        a=ftell(fp);
        fread(&one,sizeof(people),1,fp);
    }

    if(k)
    {
        printf("\n 已查到員工號為%s 的紀錄, 原紀錄為: \n",nu);        
        printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n","姓名","員工號","性別","年齡","最高學歷","職務","薪水","聯繫電話","住址");
        printf("%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
        printf("\n 請依次輸入新紀錄信息\n");
        printf("\n 姓    名:  ");
        scanf("%s",one.name);
        strcpy(one.num,nu);   /*不懂這東西*/
        printf("\n 性    別:  ");
        scanf("%s",one.sex);
        printf("\n 年    齡:  ");
        scanf("%s",one.age);
        printf("\n 最高學歷:  ");
        scanf("%s",one.record);
        printf("\n 職    務:  ");
        scanf("%s",one.position);
        printf("\n 薪    水:  ");
        scanf("%s",one.wanges);
        printf("\n 聯繫電話:  ");
        scanf("%s",one.tel);
        printf("\n 住    址:  ");
        scanf("%s",one.addr);

        fseek(fp,a,0);
        
        if(fwrite(&one,sizeof(people),1,fp)!=1)
            printf("寫入文件錯誤!\n");
    }

    else
        printf("\n 對不起, 查無此人,無法進行修改");
    fclose(fp);
}

void Delete()
{
    int m,k=0;
    long a,b;
    char nu[10];
    FILE *fp1,*fp2;
    people one;
    printf("\n 請輸入您要刪除的員工的員工號:");
    scanf("%s",nu);
    if((fp1=fopen("workers","rb+"))==NULL)
    {
        printf("\n 打開文件失敗! ");
        exit(0);
    }
 
    if((fp2=fopen("casual","wb+"))==NULL)
    {
        printf("\n 打開文件失敗! ");
        exit(0);
    }
    fread(&one,sizeof(people),1,fp1);
    while(!feof(fp1))
    {
        if(strcmp(nu,one.num)==0)
        {
            k=1;
            b=ftell(fp1);
            break;
        }
        if(fwrite(&one,sizeof(people),1,fp2)!=1)
            printf("寫入文件失敗!\n");
        fread(&one,sizeof(people),1,fp1);
    }
    if(k==1)
    {
        printf("\n 已查到員工號為%s 的紀錄, 詳細信息為: \n",nu);
        printf("\n%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n","姓名","員工號","性別","年齡","最高學歷","職務","薪水","聯繫電話","住址");
        printf("%-10s%-8s%-5s%-5s%-10s%-8s%-8s%-10s%-15s\n",one.name,one.num,one.sex,one.age,one.record,one.position,one.wanges,one.tel,one.addr);
        printf("\n 確實要刪除此條紀錄嗎? 按1為不刪除; 按0為刪除\n");
        scanf("%d",&m);

        if(m==0)
        {
            fseek(fp1,b,0);
            fread(&one,sizeof(people),1,fp1);
            while(!feof(fp1))
            {
                if(fwrite(&one,sizeof(people),1,fp2)!=1)
                  printf("寫入文件錯誤!\n");
                fread(&one,sizeof(people),1,fp1);
            }
            rewind(fp2);
            fclose(fp1);
            if((fp1=fopen("workers","wb"))==NULL)
            {
                printf("\n 打開文件失敗! ");
                exit(0);
            }
            fread(&one,sizeof(people),1,fp2);
            while(!feof(fp2))
            {
                if(fwrite(&one,sizeof(people),1,fp1)!=1)
                  printf("寫文件錯誤!\n");
                fread(&one,sizeof(people),1,fp2);
            }
            fclose(fp1); 
            fclose(fp2);
        } 
   }
   else
   {
        printf("\n 對不起, 查無此人! ");
        fclose(fp1);
        fclose(fp2);
   }
}

