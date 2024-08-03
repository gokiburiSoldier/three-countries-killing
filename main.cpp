/*
 * 这玩意儿感觉用 *gcc* 都可以编译
 */

#include <stdio.h>
#include "main.h"
#include "heads/find.h"

int status;

int main() {
    suffer();
    players[1].health = MY_HEALTH_MAX; /* 作弊行为 */
    for(int i=1;i<=3;++i) qi_card(4,i);
    while(!(status = game_has_ended())) {
        if(card_ptr > card_num) card_ptr = 1;
        if(doer == ME) my_turn();
        else { /* 人机的A.I.编写 有杀就杀 没杀且血量小于3时且有桃回血 */
            qi_card(2,doer);
            player ai = players[doer];
            int kill_pos = finddd(ai.shoupai,KILLING,ai.c_ptr-1);
            if(kill_pos != -1) {
                ai.rm(kill_pos);
                if(!ask_using_flash(doer)) {
                    printf("You are hurt by player %d\n",doer);
                    --players[1].health;
                }
                else                   players[1].rm(finddd(players[1].shoupai,FLASHING,players[1].c_ptr-1));
            }
            else if(ai.health < 3) {
                int peach_pos = finddd(ai.shoupai,PEACH,ai.c_ptr-1);
                if(peach_pos != -1) {
                    ai.rm(peach_pos);
                    ++ai.health;
                }
            }
        }
        ++turn;
        if(++doer == 4) doer = 1;
    }
    switch(status) {
        case 1:
            printf("GAME OVER! You are dead.");
            break;
        case 2:
            printf("GAME OVER! You are winner!");
            break;
    }
    system("pause");
    return 0;
}