#include"main.hpp"
#include<cstdio>
#include<cstdlib>
#include<cctype>
inline void clear()
{
    if(system("clear"))system("cls");
}
int main()
{
    std::string choose;
    char ch='\0';
    do{
        clear();
        for(const auto &i:smain::menu)
            printf("%s\r\n",i.first.c_str());
        choose.clear();
        for([&ch](){while(isspace(ch)){ch=getchar();}}();!isspace(ch);ch=getchar())
            choose+=ch;
        clear();
        if(smain::menu.count(choose))
            printf("\r\nreturn:%d\r\n",smain::menu.at(choose)());
        ch=getchar();
    }
    while (!choose.empty());
    
}