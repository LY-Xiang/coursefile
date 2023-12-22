#include <stdio.h>
#include <stdlib.h>
#define MAX_YEARS 10000
int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int year) 
{   
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) 
        return 1;
    else
        return 0;
}

int getDaysOfMonth(int year, int month) 
{
    if (month < 1 || month > 12)
    {
        printf("无效的月份\n");
        exit(1);
    }
    if (month == 2 && isLeapYear(year)) 
        return 29;
    else
        return months[month];
}

void printyearday(int year, int month) 
{
    int i, j, k, dayOfWeek, numDays;
    char week[7][10] = {"日", "一", "二", "三", "四", "五", "六"};
    dayOfWeek = (year - 1) * 365 + (year - 1) / 4 - (month - 1) * 30 + (month - 1) / 4 + 1 % 7;
    numDays = getDaysOfMonth(year, month);
    printf("\n");
    printf("%s %d\n", week[dayOfWeek], year);
    printf("\t一月\t二月\t三月\t四月\t五月\t六月\t七月\t八月\t九月\t十月\t十一月\t十二月\n");
    for (i = 1; i <= numDays; i++) {
        printf("%4d ", i);
        if ((i + dayOfWeek) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    int year, month;
    while (1)
    {
        printf("     万年历查询程序:\n");
        printf("1. 查询某年是否为闰年\n");
        printf("2. 查询某月的天数\n");
        printf("3. 打印某年的全年日历\n");
        printf("4. 退出\n");
        printf("请输入要查询的选项:");
        scanf("%d", &month);
        switch (month)
        {
        case 1:
            printf("请输入年份：");
            scanf("%d", &year);
            if (isLeapYear(year))
                printf("%d 年是闰年\n", year);
            else
                printf("%d 年不是闰年\n", year);
            break;
        case 2:
            printf("请输入年份：");
            scanf("%d", &year);
            printf("请输入月份：");
            scanf("%d", &month);
            if (getDaysOfMonth(year, month)!= 0)
                printf("%d 年 %d 月有 %d 天\n", year, month, getDaysOfMonth(year, month));
            else
                printf("无效的月份\n");
            break;
        case 3:
            printf("请输入年份：");
            scanf("%d", &year);
            printyearday(year, month);
            break;
        case 4:
            return 0;
        default:
            printf("请按要求重新输入！！！\n");
            break;
        }
    }
}