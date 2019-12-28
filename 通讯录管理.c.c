#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
typedef struct student
{
    char name[20];
    char num[20];
    char sex [20];
    char phone[20];
    struct student *next;
}stu;
stu *head;

void print()    //首页面菜单
{
    printf("\n\n\n");
    printf("    \t\t\t通讯录管理系统\n");
    printf("\n");
    printf("    \t\t1.输入数据");
    printf("\t\t2.显示数据\n");
    printf("    \t\t3.插入数据");
    printf("\t\t4.删除数据\n");
    printf("      \t\t5.查看数据");
    printf("\t\t6.修改数据\n");
    printf("      \t\t7.保存数据");
    printf("\t\t8.返回主菜单\n");
    printf("\t\t9.退出\n");

}

void input(stu *p1)    //输入的数据
{
    printf("姓名:");
    scanf("%s",&p1->name);

    printf("学号:");
    scanf("%s",&p1->num);

    printf("性别:");
    scanf("%s",&p1->sex);

    printf("手机号:");
    scanf("%s",&p1->phone);

}

stu * inputdata()    //数据输入的函数
{
    stu *p1,*p2;
    int i=1;
    p1=(stu *)malloc(sizeof(stu));
    if(p1!=NULL)
    {
        head=p1;
        printf("\n\t\t输入数据\n");
        printf("在姓名处输入'好'表示数据结束\n");
        while(i)
        {
            printf("姓名:");
            scanf("%s",&p1->name);
            if(strcmp(p1->name,"好")==0)
            {
                printf("\n输入完毕!\n");
                i=0;
                p2->next=NULL;
                free(p1);
                p1=p2;
            }

             else
            {
                printf("学号:");
                scanf("%s",&p1->num);

                printf("性别:");
                scanf("%s",&p1->sex);

                printf("手机号:");
                scanf("%s",&p1->phone);

                p2=p1;
                p1=(stu *)malloc(sizeof(stu));
                if(p1!=NULL)
                {
                    p2->next=p1;
                }
            }
        }
        return(p1->next);
    }
}

stu * lookdata(stu *p1)    //查看数据的函数
{
    printf("\n\t\t显示数据\n");
    while(p1!=NULL)
    {
        printf("姓名:%s\t\t",p1->name);
        printf("学号:%s\t\t",p1->num);
        printf("性别:%s\t\t",p1->sex);
        printf("手机号:%s\t\t",p1->phone);
        printf("\n\n");
        p1=p1->next;
    }
    return p1;
}


void insert()    //插入数据
{
    int i;
    char named[20];
    stu *p1,*p2,*p3;
    p1=head;
    p3=(stu *)malloc(sizeof(stu));
    p3->next=NULL;
    printf("\n\t\t\t插入数据\n");
    printf("请输入插入者的资料:\n");
    input(p3);
    printf("\n插入选项\n");
    printf("1.首位置插入\t2.尾位置插入\t3.前插\n");
    printf("请选择:");
    scanf("%d",&i);
    switch(i)
    {
    case 1:p3->next=p1;
        head=p3;
        break;
    case 2:while(p1->next!=NULL)
           {
               p2=p1;
               p1=p1->next;
           }
        p1->next=p3;
        break;
    case 3:printf("请输入姓名（前插）:");
        scanf("%s",named);
        while(strcmp(named,p1->name)!=0)
        {
            p2=p1;
            p1=p1->next;
        }
        p2->next=p3;
        p3->next=p1;
        break;
    }
    printf("插入成功!\n");
    return;
}

void deleted()    //删除数据
{
    stu *p1,*p2;
    char Name[20];
    printf("\n\t\t\t删除数据\n");
    printf("请输入要删除的姓名:");
    scanf("%s",Name);
    p1=head;
    if(head==NULL)
    {
    printf("内容为空!\n");
    return;
    }
    if(strcmp(Name,p1->name)==0)
    {
    head=p1->next;
    printf("删除成功!\n");
    return;
    }
    while(p1!=NULL&&(strcmp(Name,p1->name)!=0))
    {
    p2=p1;
    p1=p1->next;
    }
    if(p1==NULL)
    {
    printf("此人不存在!\n");
    return;
    }
    if(p1->next!=NULL)
    {
    p1=p1->next;
    p2->next=p1;
    printf("删除成功!\n");
    return;
    }
    else
    {
    p2->next=NULL;
    printf("删除成功!\n");
    return;
    }
}


find(stu *p2)        //通过姓名查找查看数据的函数
{
    char name[20];
    int b=0;
    printf("\n\t\t\t查看数据\n");
    printf("请输入您想查找人的姓名:");
    scanf("%s",name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
            printf("你要找到的数据\n");
            printf("姓名:%s\n",p2->name);
            printf("学号:%s\t",p2->num);
            printf("性别:%s\t",p2->sex);
            printf("手机号:%s\t",p2->phone);
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\n您要查找的人不存在!\n");
    }
}


update(stu *p2)   //通过姓名查找修改数据
{
    char name[20];
    int b=0,i;
    printf("\n\t\t\t修改数据\n");
    printf("请输入将要修改人的姓名:");
    scanf("%s",name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
            printf("该同学的信息\n");
            printf("姓名:%s\n",p2->name);
            printf("学号:%s\t",p2->num);
            printf("性别:%s\t",p2->sex);
            printf("手机号:%s\t",p2->phone);
            printf("\n请选择要修改的信息\n");
            printf("\t1.姓名\t2.学号\t3.性别\t4.手机号\n");
            printf("\n您的选择是(1~4):");
            scanf("%d",&i);
            printf("请输入修改之后的内容\n");
            switch(i)
            {
            case 1:printf("姓名:");
                scanf("%s",&p2->name);
                break;
            case 2:printf("学号:");
                scanf("%s",&p2->num);
                break;
            case 3:printf("性别:");
                scanf("%s",&p2->sex);
                break;
            case 4:printf("手机号:");
                scanf("%s",&p2->phone);
                break;
            }
            printf("\n修改成功!\n");
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("没有此人的资料!\n");
    }
}


save(stu *p2)   //保存数据
{
    FILE *fp;
    char file[20];
    printf("\n\t\t\t保存数据\n");
    printf("输入文件名:");
    scanf("%s",file);
    if((fp=fopen(file,"w"))==NULL)
    {
        printf("cannot open this file\n");
        exit(0);
    }
    fprintf(fp,"姓名\t学号\t性别\t手机号\n");
    while(p2!=NULL)
    {
        fprintf(fp,"%s\t",p2->name);
        fprintf(fp,"%s\t",p2->num);
        fprintf(fp,"%s\t",p2->sex);
        fprintf(fp,"%s\t",p2->phone);
        p2=p2->next;
    }
    printf("\n保存成功!\n");
    fclose(fp);
}


void screen()
{
    int i;
    char s[251]={"欢迎使用通讯录管理系统"};

    printf("\n\n\n\t\t\t");
    for(i=0;s[i]!=NULL;i++)
    {
        Sleep(30);
        printf("%c",s[i]);
    }
}


void main()
{
    int i;
    screen();
    Sleep(3000);
    print();
    while(1)
    {
        printf("请输入你的选择(1~9):");
        loop:scanf("%d",&i);
        if(i<1||i>9)
        {
            printf("输入有误,请在1~9中进行选择:");
            goto loop;
        }
        switch(i)
        {
        case 1:
            inputdata();
            break;
        case 2:
            lookdata(head);
            break;
        case 3:
            insert();
            break;
        case 4:
             deleted();
            break;
        case 5:
            find(head);
            break;
        case 6:
            update(head);
            break;
        case 7:
            save(head);
            break;
        case 8:
            print();
            break;
        case 9:
            exit(1);
            break;
        }
    }
}
