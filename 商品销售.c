#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   //getche()
#include<windows.h>
#include <string.h>

float total=0;   //�����ܼ�

char ch;   //ָ����Ʒ�

int n;//case(n)

char code[10]; //��Ʒ��Ϣ

char name[10]; //��Ʒ��Ϣ

char unit[10]; //��Ʒ��Ϣ

int amount;

float unitprice;

typedef struct Goods
{
    char code[10];//����

    char name[10];//����

    char unit[10];//��λ

    int amount;//����

    float unitprice;//����
//struct Goods *next;
};

struct Goods a[1000];

int x=1;

void add(int i,char *code,char *name,char *unit,int amount,float unitprice)
{
    strcpy(a[i].code,code);

    strcpy(a[i].name,name);

    strcpy(a[i].unit,unit);

    a[i].amount=amount;

    a[i].unitprice=unitprice;
}

void f_sort()
{
    printf("��ѡ������ʽ:(1)ѡ������,(2)ð������");
    char o[2];
    scanf("%s",o);
    getchar();
    int h,j,i;
    struct Goods t;
    if(o[0]=='1')
    {
        for(h=1; h<x; h++)
        {
            for(j=1; j<x; j++)
            {
                if(a[h].unitprice<a[j].unitprice)
                {
                    t=a[h];
                    a[h]=a[j];
                    a[j]=t;
                }
            }
        }
    }
    else
    {
        struct Goods b[1000];
        int len=x-1;
        for(i=0;i<len;i++)
            b[i]=a[i+1];
        for (i=0; i<len-1; ++i)
        {
            for(j=0; j<len-1-i; ++j)
            {
                if(b[j].unitprice>b[j+1].unitprice)
                {

                    t=b[j];
                    b[j]=b[j+1];
                    b[j+1]=t;
                }
            }
        }

        for(i=0;i<len;i++)
            a[i+1]=b[i];
    }

    system("cls");
    printf(" \n");
    printf("-----------ȫ����Ʒ��Ϣ����-------------------\n");
    printf(" \n");
    printf("����   ����   ����   ����   ��λ\n");
    if(x==1)
    {
        printf("ϵͳδ��¼���κ���Ʒ��Ϣ�����¼��ɾ��!\n");
    }

    for(h=1; h<x; h++)
    {
        printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
    }
    printf("\n");
    printf("���������棨y/n��");
    char x[2];
    scanf("%s",x);
    getchar();
    if(x[0]=='y'||x[0]=='Y')
        screen();
}

void f_write()
{
    printf( "�������%d����Ʒ���룺\n",x );
    scanf("%s",code);
    printf( "�������%d����Ʒ���ƣ�\n",x );
    scanf("%s",name);
    printf( "�������%d����Ʒ������λ��\n",x );
    scanf("%s",unit);
    printf( "�������%d����Ʒ������\n",x);
    scanf("%d",&amount);
    printf( "�������%d����Ʒ���ۣ�\n",x );
    scanf("%f",&unitprice);
    //g[i]=new Goods(code,name,unit,amount,unitprice);
    add(x,code,name,unit,amount,unitprice);
    x++;
    printf( "��Ϣ¼��ɹ�!(����¼�밴y��������һ�㰴n)");
    getchar();
    scanf("%c",&ch);
    getchar();
    //printf("����%c\n",ch);
    if(ch=='y')
    {
        f_write();
    }
}

void f_change()
{
    printf("������Ҫ�ı����Ʒ���룺");
    scanf("%s",code);
    int h;
    int hh=0;
    for(h=1; h<x; h++)
    {
        if(0 == strcmp(a[h].code,code))
        {
            hh=1;
            printf("��Ʒ��Ϣ���£�\n");
            printf("����   ����   ����   ����   ��λ\n");
            printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
            char newco[10],newna[10],newun[10];
            int newam;
            float newunpr;
            printf("����Ҫ�޸ģ�1�����룻2�����ƣ�3�����ۣ�4��������5����λ��\n");
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                printf("�������޸ĺ����Ʒ���룺\n");
                scanf("%s",newco);
                printf("����%s",newco);
                strcpy(a[h].code,newco);
                printf("�޸ĳɹ���\n");
                break;
            case 2:
                printf("�������޸ĺ����Ʒ���ƣ�\n");
                scanf("%s",newna);
                strcpy(a[h].name,newna);
                printf("�޸ĳɹ���\n");
                break;
            case 3:
                printf("��������Ʒ���ۣ�\n");
                scanf("%s",newun);
                strcpy(a[h].unit,newun);
                printf("�޸ĳɹ���\n");
                break;
            case 4:
                printf("�������޸ĺ����Ʒ������\n");
                scanf("%d",newam);
                a[h].amount=newam;
                printf("�޸ĳɹ���\n");
                break;
            case 5:
                printf("�������޸ĺ����Ʒ��λ��\n");
                scanf("%f",newunpr);
                a[h].unitprice=newunpr;
                printf("�޸ĳɹ���\n");
                break;
            }
            break;
        }//if
    }//forѭ��
    if(hh==1)
        printf("�Ƿ�����޸ģ���y/n��\n");
    else
        printf("����Ʒ�����ڣ��Ƿ����²��ң�y/n��\n");
    getchar();
    scanf("%c",&ch);
    getchar();
    if(ch=='y')
    {
        f_change();
    }
}

void f_delete()
{
    printf("������Ҫɾ������Ʒ���룺\n");
    scanf("%s",code);
    int h,k;
    int hh=0;
    for(h=1; h<x; h++)
    {
        if(0 == strcmp(a[h].code,code))
        {
            hh=1;
            for(k=h; k<x; k++)
            {
                a[k]=a[k+1];
                x--;
            }
        }
    }
    if(hh==1)
        printf("ɾ���ɹ�!\n");
    else
        printf("����Ʒ���Ͳ����ڣ�\n");
    printf("�Ƿ����ɾ������y/n��\n");
    getchar();
    scanf("%c",&ch);
    getchar();
    if(ch=='y')
    {
        f_delete();
    }
}

void f_screen()
{
    system("cls");
    printf("����Ӧ��������\n");
    printf("0.¼����Ϣ 1.������Ϣ 2.ɾ����Ϣ 3.������һ��\n");
    scanf("%d",&n);
    switch(n)
    {
    case 0:
        f_write();
        if(ch=='n'||ch=='N')
            f_screen();
        break;
    case 1:
        f_change();
        if(ch=='n'||ch=='N')
            f_screen();
        break;
    case 2:
        f_delete();
        if(ch=='n'||ch=='N')
            f_screen();
        break;
    }
}

//��ӡ��Ϣ

void display()
{
    system("cls");
    printf(" \n");
    printf("-----------ȫ����Ʒ��Ϣ����-------------------\n");
    printf(" \n");
    printf("����   ����   ����   ����   ��λ\n");
    if(x==1)
    {
        printf("ϵͳδ��¼���κ���Ʒ��Ϣ�����¼��ɾ��!\n");
    }
    int h;
    for(h=1; h<x; h++)
    {
        printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
    }
    printf("\n");
    printf("���������棨y/n��");
    char x[2];
    scanf("%s",x);
    getchar();
    if(x[0]=='y'||x[0]=='Y')
      screen();
}

//����
void s_buy()
{
    float price=0;//������Ʒ�۸�
    printf("��������Ҫ�����Ʒ���룺\n");
    scanf("%s",code);
    int h;
    for(h=1; h<x; h++)
    {
        if(0 == strcmp(a[h].code,code))
        {
            printf("��������Ҫ�������Ʒ������\n");
            scanf("%d",&amount);
            price=amount*a[h].unitprice;
            a[h].amount=a[h].amount-amount;
            printf("\n");
            printf("���� ���� ���� ���� С��\n");
            printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
            total=total+price;
            break;
        }
    }
    printf("��1�������򣬰�2������\n");
    scanf("%d",&n);
    if(n==2)
    {
        printf("\n");
        printf("����������ܼ�:%fԪ��\n",total);
    }
    else
    {
        s_buy();
    }
}
//���ȫ����Ʒ��Ϣ
void s_screen()
{
    system("cls");
    printf(" \n");
    printf("-----------ȫ����Ʒ��Ϣ����-------------------\n");
    printf(" \n");
    printf("����   ����   ����   ����   ��λ\n");
    if(x==1)
    {
        printf("ϵͳδ��¼���κ���Ʒ��Ϣ�����¼��ɾ��!\n");
    }
    int h;
    for(h=1; h<x; h++)
    {
        printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
    }
    printf("\n");
    printf("���������棨y/n��");
    char x[2];
    scanf("%s",x);
    getchar();
    if(x[0]=='y'||x[0]=='Y')
        screen();
    printf("\n");

    float price=0;//������Ʒ�۸�
    printf("��������Ҫ�����Ʒ���룺\n");
    scanf("%s",code);
    for(h=1; h<x; h++)
    {
        if(0 == strcmp(a[h].code,code))
        {
            printf("��������Ҫ�������Ʒ������\n");
            scanf("%d",&amount);
            price=amount*a[h].unitprice;
            a[h].amount=a[h].amount-amount;
            printf("\n");
            printf("���� ���� ���� ���� С��\n");
            printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
            total=total+price;
            break;
        }
    }
    printf("��1�������򣬰�2������\n");
    scanf("%d",&n);
    if(n==2)
    {
        printf("\n");
        printf("����������ܼ�:%fԪ��\n",total);
    }
    else
    {
        s_buy();
    }
}

//�۰���Һ���
void f_sort2()
{
    int h,j,i;
    struct Goods t;

        for(h=1; h<x; h++) //�ȶ���Ʒ�ĵ��۽�������
        {
            for(j=1; j<x; j++)
            {
                if(a[h].unitprice<a[j].unitprice)
                {
                    t=a[h];
                    a[h]=a[j];
                    a[j]=t;
                }
            }
        }
    printf("��������Ʒ���ۣ�");
    int y;
    scanf("%d",&y);
    int l=1,r=x-1,mid,ans;  //�۰������Ʒ��Ϣ
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid].unitprice<y)
        {
            l=mid+1;
        }
        else if(a[mid].unitprice>y)
        {
            r=mid-1;
        }
        else
        {
            ans=mid;
            break;
        }
    }
     printf("����   ����   ����   ����   ��λ\n");
     printf("%s\t%s\t%s\t%d\t%f\n",a[mid].code,a[mid].name,a[mid].unit,a[mid].amount,a[mid].unitprice);
}

//ϵͳ������
void screen()
{
    system("cls");

    printf( "***********************************************\n" );
    printf("*               ��Ʒ����ͳ��ϵͳ              *\n" );
    printf( "*                                             *\n" );
    printf( "*               (1) ������Ʒ��Ϣ              *\n" );
    printf( "*                                             *\n" );
    printf("*               (2) ��������ͳ��              *\n" );
    printf("*                                             *\n" );
    printf("*               (3) ����Ʒ����������          *\n" );
    printf("*                                             *\n" );
    printf("*               (4) �鿴������Ʒ��Ϣ          *\n" );
    printf("*                                             *\n" );
    printf("*               (5) �������۰������Ʒ         *\n" );
    printf("*                                             *\n" );
    printf( "*               (0) �� ��                     *\n" );
    printf( "***********************************************\n" );

    scanf("%c",&ch);

    getchar();

    if(ch=='1')
    {
        f_screen();
        if(n==3)
        {
            getchar();
        }

        screen();
    }

    else if(ch=='2')
    {
        s_screen();
    }
    else if(ch=='3')
    {
        f_sort();
    }
    else if(ch=='4')
    {
        display();
    }
    else if(ch=='5')
    {
        f_sort2();
    }
    else if(ch=='0')
    {
        return;
    }
    else
    {
        printf( "�������ϵͳ����������");
        screen();
    }
}

int main()
{
    system("color f2");
    screen();
    return 0;
}
