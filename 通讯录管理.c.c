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

void print()    //��ҳ��˵�
{
    printf("\n\n\n");
    printf("    \t\t\tͨѶ¼����ϵͳ\n");
    printf("\n");
    printf("    \t\t1.��������");
    printf("\t\t2.��ʾ����\n");
    printf("    \t\t3.��������");
    printf("\t\t4.ɾ������\n");
    printf("      \t\t5.�鿴����");
    printf("\t\t6.�޸�����\n");
    printf("      \t\t7.��������");
    printf("\t\t8.�������˵�\n");
    printf("\t\t9.�˳�\n");

}

void input(stu *p1)    //���������
{
    printf("����:");
    scanf("%s",&p1->name);

    printf("ѧ��:");
    scanf("%s",&p1->num);

    printf("�Ա�:");
    scanf("%s",&p1->sex);

    printf("�ֻ���:");
    scanf("%s",&p1->phone);

}

stu * inputdata()    //��������ĺ���
{
    stu *p1,*p2;
    int i=1;
    p1=(stu *)malloc(sizeof(stu));
    if(p1!=NULL)
    {
        head=p1;
        printf("\n\t\t��������\n");
        printf("������������'��'��ʾ���ݽ���\n");
        while(i)
        {
            printf("����:");
            scanf("%s",&p1->name);
            if(strcmp(p1->name,"��")==0)
            {
                printf("\n�������!\n");
                i=0;
                p2->next=NULL;
                free(p1);
                p1=p2;
            }

             else
            {
                printf("ѧ��:");
                scanf("%s",&p1->num);

                printf("�Ա�:");
                scanf("%s",&p1->sex);

                printf("�ֻ���:");
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

stu * lookdata(stu *p1)    //�鿴���ݵĺ���
{
    printf("\n\t\t��ʾ����\n");
    while(p1!=NULL)
    {
        printf("����:%s\t\t",p1->name);
        printf("ѧ��:%s\t\t",p1->num);
        printf("�Ա�:%s\t\t",p1->sex);
        printf("�ֻ���:%s\t\t",p1->phone);
        printf("\n\n");
        p1=p1->next;
    }
    return p1;
}


void insert()    //��������
{
    int i;
    char named[20];
    stu *p1,*p2,*p3;
    p1=head;
    p3=(stu *)malloc(sizeof(stu));
    p3->next=NULL;
    printf("\n\t\t\t��������\n");
    printf("����������ߵ�����:\n");
    input(p3);
    printf("\n����ѡ��\n");
    printf("1.��λ�ò���\t2.βλ�ò���\t3.ǰ��\n");
    printf("��ѡ��:");
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
    case 3:printf("������������ǰ�壩:");
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
    printf("����ɹ�!\n");
    return;
}

void deleted()    //ɾ������
{
    stu *p1,*p2;
    char Name[20];
    printf("\n\t\t\tɾ������\n");
    printf("������Ҫɾ��������:");
    scanf("%s",Name);
    p1=head;
    if(head==NULL)
    {
    printf("����Ϊ��!\n");
    return;
    }
    if(strcmp(Name,p1->name)==0)
    {
    head=p1->next;
    printf("ɾ���ɹ�!\n");
    return;
    }
    while(p1!=NULL&&(strcmp(Name,p1->name)!=0))
    {
    p2=p1;
    p1=p1->next;
    }
    if(p1==NULL)
    {
    printf("���˲�����!\n");
    return;
    }
    if(p1->next!=NULL)
    {
    p1=p1->next;
    p2->next=p1;
    printf("ɾ���ɹ�!\n");
    return;
    }
    else
    {
    p2->next=NULL;
    printf("ɾ���ɹ�!\n");
    return;
    }
}


find(stu *p2)        //ͨ���������Ҳ鿴���ݵĺ���
{
    char name[20];
    int b=0;
    printf("\n\t\t\t�鿴����\n");
    printf("��������������˵�����:");
    scanf("%s",name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
            printf("��Ҫ�ҵ�������\n");
            printf("����:%s\n",p2->name);
            printf("ѧ��:%s\t",p2->num);
            printf("�Ա�:%s\t",p2->sex);
            printf("�ֻ���:%s\t",p2->phone);
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("\n��Ҫ���ҵ��˲�����!\n");
    }
}


update(stu *p2)   //ͨ�����������޸�����
{
    char name[20];
    int b=0,i;
    printf("\n\t\t\t�޸�����\n");
    printf("�����뽫Ҫ�޸��˵�����:");
    scanf("%s",name);
    while(p2!=NULL)
    {
        if(strcmp(name,p2->name)==0)
        {
            printf("��ͬѧ����Ϣ\n");
            printf("����:%s\n",p2->name);
            printf("ѧ��:%s\t",p2->num);
            printf("�Ա�:%s\t",p2->sex);
            printf("�ֻ���:%s\t",p2->phone);
            printf("\n��ѡ��Ҫ�޸ĵ���Ϣ\n");
            printf("\t1.����\t2.ѧ��\t3.�Ա�\t4.�ֻ���\n");
            printf("\n����ѡ����(1~4):");
            scanf("%d",&i);
            printf("�������޸�֮�������\n");
            switch(i)
            {
            case 1:printf("����:");
                scanf("%s",&p2->name);
                break;
            case 2:printf("ѧ��:");
                scanf("%s",&p2->num);
                break;
            case 3:printf("�Ա�:");
                scanf("%s",&p2->sex);
                break;
            case 4:printf("�ֻ���:");
                scanf("%s",&p2->phone);
                break;
            }
            printf("\n�޸ĳɹ�!\n");
            b=1;
        }
        p2=p2->next;
    }
    if(b==0)
    {
        printf("û�д��˵�����!\n");
    }
}


save(stu *p2)   //��������
{
    FILE *fp;
    char file[20];
    printf("\n\t\t\t��������\n");
    printf("�����ļ���:");
    scanf("%s",file);
    if((fp=fopen(file,"w"))==NULL)
    {
        printf("cannot open this file\n");
        exit(0);
    }
    fprintf(fp,"����\tѧ��\t�Ա�\t�ֻ���\n");
    while(p2!=NULL)
    {
        fprintf(fp,"%s\t",p2->name);
        fprintf(fp,"%s\t",p2->num);
        fprintf(fp,"%s\t",p2->sex);
        fprintf(fp,"%s\t",p2->phone);
        p2=p2->next;
    }
    printf("\n����ɹ�!\n");
    fclose(fp);
}


void screen()
{
    int i;
    char s[251]={"��ӭʹ��ͨѶ¼����ϵͳ"};

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
        printf("���������ѡ��(1~9):");
        loop:scanf("%d",&i);
        if(i<1||i>9)
        {
            printf("��������,����1~9�н���ѡ��:");
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
