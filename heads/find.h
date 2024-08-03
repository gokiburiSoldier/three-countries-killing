#ifndef _BC_H
#define _BC_H

#include "player.h"

/* 本来想写一个namespace 但是就不兼容C语言 */
template<class tp>
int finddd(tp a[],tp e,int len) { /* 本来想用二分查找 但是想到列表是无序的 并且排序后顺序会不一致 */
    int rt = -1;
    for(int i=1;i<=len;++i) if(a[i] == e) {
        rt = i;
        break;
    }
    return rt;
}

#endif