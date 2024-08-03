#ifndef _PLAYER
#define _PLAYER

#ifndef __cplusplus
#include <stdbool.h>
#endif

#define KILLING  0x114 /* 杀 */
#define FLASHING 0x115 /* 闪 */
#define PEACH    0x116 /* 桃 */
#define NONE     114514 /* 空的卡牌 */
#define ME       1 /* 玩家编号 */
#define card int
#define MY_HEALTH_MAX 20

template<class t>
void swap2(t &a,t &b) {
    t tmp = a;
    a = b;
    b = tmp;
}

const int player_num = 3; /* 玩家数量 */
const int card_num = 102;/* 为什么是102张？因为他善。并且保证是3,2的最小倍数 */
int all_cards[card_num+1] = {},card_ptr=1;

struct player {
    bool living = true;
    card shoupai[card_num] = {};
    int c_ptr=1,health=4;
    void rm(int pos) {
        --c_ptr;
        for(int i=pos;i<c_ptr+1;++i) swap2(shoupai[i],shoupai[i+1]);
    }
} players[player_num+1];

#endif