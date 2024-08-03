/*
 * `main.cpp`只需要写一个主函数就好了
 * 我们头文件要考虑的就多了
 * 
 * 十年OI一场空 不开long long见祖宗(不是
 */

#ifndef _TCK_MH
#define _TCK_MH

/* 宏 */

#include <stdlib.h>
#include <time.h>
#include "heads/player.h"
#include "heads/kill.h"
#include "heads/dosth.h"

/* 常量/变量 */

int turn = 1, /* 回合 */
    doer = 1; /* 执行者的编号 */

/* 函数 */

/* swap,见过吧 没有库 自己写 */
template<class tp>
void swap(tp &a,tp &b) {
    tp tmp = a;
    a = b;
    b = tmp;
    return;
}

void wait(int n) { /* 参数: {n: 等待n ms} */
    clock_t start = clock();
    while(clock()-start < n);
}

void suffer(void) { /* 洗牌函数 */
    /* 放置卡牌 */
    for(int i=1;i<=card_num/3;++i) 
        all_cards[i] = KILLING,
        all_cards[i+card_num/3]=FLASHING,
        all_cards[i+card_num/3*2]=PEACH;
    /* 随机洗牌 */
    for(int i=1;i<=card_num;++i) {
        srand(time(0));
        /* 代码改编自 stl_algo.h (algorithm)的random_shuffle函数 */
        int j = 1 + rand() % ((i-1)+1);
        if(i != j) swap(all_cards[i],all_cards[j]);
    }
}

void qi_card(int num,int who) { /* 起牌函数 */
    for(int i=1;i<=num;++i) {
        players[who].shoupai[players[who].c_ptr ++] = all_cards[card_ptr];
        all_cards[card_ptr ++] = NONE;
    }
}

void my_turn(void) {
    /* 起2张牌 */
    qi_card(2,ME);
    /* 列出手牌 */
    for(int i=1;i<players[1].c_ptr;++i) {
        char *output = "";
        switch(players[1].shoupai[i]) {
            case KILLING:
                output = "KILL";
                break;
            case FLASHING:
                output = "FLASH";
                break;
            case PEACH:
                output = "PEACH";
                break;
        }
        printf("%s ",output); /* 不知道要不要写`*output` 反正编译看报不报错 */
    }
    printf("\n");
    for(int i=1;i<=player_num;++i) if(players[i].living) printf("num %d: health=%d\n",i,players[i].health);
    card cd = ask_doing_something(); /* cd: card的缩写 */
    switch(cd) {
        case PEACH:
            players[1].health += 2;
            break;
        case KILLING:
            int obj = ask_for_kill();
            if(-- players[obj].health <= 0) players[obj].living = false;
            break;
    }
}

#endif