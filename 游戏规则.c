#include <stdio.h>
#include <stdlib.h>

char law[][1145] = {
    "游戏规则",
    "----------------",
    "其实本游戏就是作者自己瞎写的",
    "起因是没人和作者一起玩《三国杀》了",
    "然后就自己写了一个低配 文字版",
    "还有两个人机",
    "还有作弊使用的",
    "----------------",
    "要开始 先要一个编译器(作者使用 Msys2的g++)",
    "然后就是编译出来一个a.exe/a.out",
    "然后运行",
    "但是游戏是全英文的"
};

int main(int argc,char* argv[]) {
    #ifdef _WIN32
    system("chcp 65001>nul");
    #else
    printf("Sorry,I cannot manage all the OS except Microsoft Windows.");
    #endif
    for(int i=0;i<12;++i) printf("%s\n",law[i]);
    system("pause");
}