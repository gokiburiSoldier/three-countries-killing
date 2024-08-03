#ifndef _TCK_K
#define _TCK_K

#include <stdio.h>
#include "player.h"

#ifndef __cplusplus
#include <stdbool.h>
#endif

int ask_for_kill(void) { /* 返回值: (被)杀的人的编号(数组下标) */
    int rt;
    printf("Input the number of the person(");
    for(int i=2;i<=player_num;++i) if(players[i].living) printf("%d ",i);
    printf("):"); /* 这个怎么像个哭脸 */
    scanf("%d",&rt);
    while(rt <= 1 || rt > player_num || (!players[rt].living)) {
        printf("the input is wrong! Please input again: ");
        scanf("%d",&rt);
    }
    return rt;
}

bool ask_using_flash(int num) {
    bool hasFlashing = false;
    for(int i=1;i<players[1].c_ptr;++ i) if(players[1].shoupai[i] == FLASHING) {
        hasFlashing = true;
        break;
    }
    if(!hasFlashing) return false;
    int rt;
    printf("Player %d is killing you! Using a flashing? (1=Yes,0=No):",num);
    scanf("%d",&rt);
    return rt;
}

#endif