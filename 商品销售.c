#include <stdio.h>
#include <stdlib.h>
#include <conio.h>   //getche()
#include<windows.h>
#include <string.h>

float total=0;   //销售总价

char ch;   //指令控制符

int n;//case(n)

char code[10]; //商品信息

char name[10]; //商品信息

char unit[10]; //商品信息

int amount;

float unitprice;

typedef struct Goods
{
    char code[10];//代码

    char name[10];//名称

    char unit[10];//单位

    int amount;//总数

    float unitprice;//单价
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
    printf("请选择排序方式:(1)选择排序,(2)冒泡排序");
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
    printf("-----------全部商品信息如下-------------------\n");
    printf(" \n");
    printf("代码   名称   单价   总数   单位\n");
    if(x==1)
    {
        printf("系统未曾录入任何商品信息，或记录被删除!\n");
    }

    for(h=1; h<x; h++)
    {
        printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
    }
    printf("\n");
    printf("返回主界面（y/n）");
    char x[2];
    scanf("%s",x);
    getchar();
    if(x[0]=='y'||x[0]=='Y')
        screen();
}

void f_write()
{
    printf( "请输入第%d件商品代码：\n",x );
    scanf("%s",code);
    printf( "请输入第%d件商品名称：\n",x );
    scanf("%s",name);
    printf( "请输入第%d件商品计量单位：\n",x );
    scanf("%s",unit);
    printf( "请输入第%d件商品总数：\n",x);
    scanf("%d",&amount);
    printf( "请输入第%d件商品单价：\n",x );
    scanf("%f",&unitprice);
    //g[i]=new Goods(code,name,unit,amount,unitprice);
    add(x,code,name,unit,amount,unitprice);
    x++;
    printf( "信息录入成功!(继续录入按y，返回上一层按n)");
    getchar();
    scanf("%c",&ch);
    getchar();
    //printf("我是%c\n",ch);
    if(ch=='y')
    {
        f_write();
    }
}

void f_change()
{
    printf("请输入要改变的商品代码：");
    scanf("%s",code);
    int h;
    int hh=0;
    for(h=1; h<x; h++)
    {
        if(0 == strcmp(a[h].code,code))
        {
            hh=1;
            printf("商品信息如下：\n");
            printf("代码   名称   单价   总数   单位\n");
            printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
            char newco[10],newna[10],newun[10];
            int newam;
            float newunpr;
            printf("你想要修改：1、代码；2、名称；3、单价；4、总数；5、单位。\n");
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                printf("请输入修改后的商品代码：\n");
                scanf("%s",newco);
                printf("我是%s",newco);
                strcpy(a[h].code,newco);
                printf("修改成功！\n");
                break;
            case 2:
                printf("请输入修改后的商品名称：\n");
                scanf("%s",newna);
                strcpy(a[h].name,newna);
                printf("修改成功！\n");
                break;
            case 3:
                printf("请输入商品单价：\n");
                scanf("%s",newun);
                strcpy(a[h].unit,newun);
                printf("修改成功！\n");
                break;
            case 4:
                printf("请输入修改后的商品总数：\n");
                scanf("%d",newam);
                a[h].amount=newam;
                printf("修改成功！\n");
                break;
            case 5:
                printf("请输入修改后的商品单位：\n");
                scanf("%f",newunpr);
                a[h].unitprice=newunpr;
                printf("修改成功！\n");
                break;
            }
            break;
        }//if
    }//for循环
    if(hh==1)
        printf("是否继续修改？（y/n）\n");
    else
        printf("该商品不存在，是否重新查找（y/n）\n");
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
    printf("请输入要删除的商品代码：\n");
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
        printf("删除成功!\n");
    else
        printf("该商品本就不存在！\n");
    printf("是否继续删除？（y/n）\n");
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
    printf("按相应键操作：\n");
    printf("0.录入信息 1.更改信息 2.删除信息 3.返回上一层\n");
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

//打印信息

void display()
{
    system("cls");
    printf(" \n");
    printf("-----------全部商品信息如下-------------------\n");
    printf(" \n");
    printf("代码   名称   单价   总数   单位\n");
    if(x==1)
    {
        printf("系统未曾录入任何商品信息，或记录被删除!\n");
    }
    int h;
    for(h=1; h<x; h++)
    {
        printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
    }
    printf("\n");
    printf("返回主界面（y/n）");
    char x[2];
    scanf("%s",x);
    getchar();
    if(x[0]=='y'||x[0]=='Y')
      screen();
}

//买入
void s_buy()
{
    float price=0;//单个商品价格
    printf("请输入想要买的商品代码：\n");
    scanf("%s",code);
    int h;
    for(h=1; h<x; h++)
    {
        if(0 == strcmp(a[h].code,code))
        {
            printf("请输入想要购买的商品数量：\n");
            scanf("%d",&amount);
            price=amount*a[h].unitprice;
            a[h].amount=a[h].amount-amount;
            printf("\n");
            printf("代码 名称 单价 数量 小计\n");
            printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
            total=total+price;
            break;
        }
    }
    printf("按1继续购买，按2结束。\n");
    scanf("%d",&n);
    if(n==2)
    {
        printf("\n");
        printf("购买结束，总计:%f元！\n",total);
    }
    else
    {
        s_buy();
    }
}
//输出全部商品信息
void s_screen()
{
    system("cls");
    printf(" \n");
    printf("-----------全部商品信息如下-------------------\n");
    printf(" \n");
    printf("代码   名称   单价   总数   单位\n");
    if(x==1)
    {
        printf("系统未曾录入任何商品信息，或记录被删除!\n");
    }
    int h;
    for(h=1; h<x; h++)
    {
        printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
    }
    printf("\n");
    printf("返回主界面（y/n）");
    char x[2];
    scanf("%s",x);
    getchar();
    if(x[0]=='y'||x[0]=='Y')
        screen();
    printf("\n");

    float price=0;//单个商品价格
    printf("请输入想要买的商品代码：\n");
    scanf("%s",code);
    for(h=1; h<x; h++)
    {
        if(0 == strcmp(a[h].code,code))
        {
            printf("请输入想要购买的商品数量：\n");
            scanf("%d",&amount);
            price=amount*a[h].unitprice;
            a[h].amount=a[h].amount-amount;
            printf("\n");
            printf("代码 名称 单价 数量 小计\n");
            printf("%s\t%s\t%s\t%d\t%f\n",a[h].code,a[h].name,a[h].unit,a[h].amount,a[h].unitprice);
            total=total+price;
            break;
        }
    }
    printf("按1继续购买，按2结束。\n");
    scanf("%d",&n);
    if(n==2)
    {
        printf("\n");
        printf("购买结束，总计:%f元！\n",total);
    }
    else
    {
        s_buy();
    }
}

//折半查找函数
void f_sort2()
{
    int h,j,i;
    struct Goods t;

        for(h=1; h<x; h++) //先对商品的单价进行排序
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
    printf("请输入商品单价：");
    int y;
    scanf("%d",&y);
    int l=1,r=x-1,mid,ans;  //折半查找商品信息
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
     printf("代码   名称   单价   总数   单位\n");
     printf("%s\t%s\t%s\t%d\t%f\n",a[mid].code,a[mid].name,a[mid].unit,a[mid].amount,a[mid].unitprice);
}

//系统主界面
void screen()
{
    system("cls");

    printf( "***********************************************\n" );
    printf("*               商品销售统计系统              *\n" );
    printf( "*                                             *\n" );
    printf( "*               (1) 更改商品信息              *\n" );
    printf( "*                                             *\n" );
    printf("*               (2) 进行销售统计              *\n" );
    printf("*                                             *\n" );
    printf("*               (3) 对商品按单价排序          *\n" );
    printf("*                                             *\n" );
    printf("*               (4) 查看所有商品信息          *\n" );
    printf("*                                             *\n" );
    printf("*               (5) 按单价折半查找商品         *\n" );
    printf("*                                             *\n" );
    printf( "*               (0) 退 出                     *\n" );
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
        printf( "输入错误，系统重新启动！");
        screen();
    }
}

int main()
{
    system("color f2");
    screen();
    return 0;
}
