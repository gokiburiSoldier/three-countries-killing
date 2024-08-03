#ifndef _DST_H
#define _DST_H

#include "player.h"
#include <stdio.h>

card ask_doing_something(void) { /* 返回值: 卡牌 */
    int rt,cp = players[1].c_ptr;
    card r;
    player plr = players[1];
    printf("Input card number(");
    for(int i=1;i<cp;++i) printf("%d ",i);
    printf("):"); /* 还是那句话 好像哭脸 */
    scanf("%d",&rt);
    while(rt <= 0 || rt >= cp || plr.shoupai[rt] == PEACH && plr.health >= MY_HEALTH_MAX || plr.shoupai[rt] == FLASHING) {
        printf("Input is wrong! Please input again: ");
        scanf("%d",&rt);
    }
    r = players[1].shoupai[rt];
    players[1].rm(rt);
    return r;
}


/* 为什么用 short? 因为我的内存是一个bit一个bit买的 */
short game_has_ended(void) {
    if(players[1].health <= 0) return 1; /* 我挂了 */
    for(int i=2;i<=player_num;++i) if(players[i].living) return 0; /* 还有活的 */
    return 2; /* 别人都挂了 */
}

#endif