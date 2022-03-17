/* 7-3 tableTennis
 * https://pintia.cn/problem-sets/1448182951467995136/problems/1450246237307400192
 * 模拟题，不用算法，但要考虑很多细节
 */
#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 10005
#define DEF 0x3f3f3f3f

/**
n个乒乓球桌 1-n
每对pl选择open的编号最小的 没有open的就排队
最多play两小时
计数每对的等待时间 每桌的服务次数
对于vip桌 第一对vip 可以用  如果队里没有vip  那么可以当成一般的给一般的一对plays用
如果没有vip桌了 可以给vip普通桌，vip只能插vip桌，不能插普通桌
不会有重复的到达时间
**/

struct table {
    int time;       //当前用户结束时间
    int num;        //累计服务人数
    int is_vip;     //是否是vip桌子
} tab[101];

struct player {
    int arr;        //到达时间
    int time;       //游玩时长
    int is_vip;     //是否是vip
    int start;      //游玩开始时间
} players[MAXSIZE];

int N;              //用户个数
int vis[MAXSIZE];   //是否玩过
int K;              //桌子总数
int M;              //vip桌子个数
int E = 21 * 3600;  //打烊时间

int max(int a, int b) {
    return a >= b ? a : b;
}

//将时间转换为秒表示
int timeShift(int h, int m, int s) {
    return h * 3600 + m * 60 + s;
}

int cmp(const void *a, const void *b) {
    return ((struct player *) a)->arr - ((struct player *) b)->arr;   //升序排序
}

// 判断后面是否有正在等待的vip用户
int haveVip(int tabId, int playId) {
    while (++playId < N) {
        if (!vis[playId] && players[playId].is_vip) {
            if (tab[tabId].time > players[playId].time) //该桌子空出来的时候vip用户可以使用
                return playId;
            return -1;  //最先找到的vip用户就是最早来到的，所以后面的不用看了
        }
    }
    return -1;
}

int main() {
    scanf("%d", &N);
    for (int i = 0, h, m, s; i < N; ++i) {
        scanf("%d:%d:%d%d%d", &h, &m, &s, &players[i].time, &players[i].is_vip);
        players[i].arr = timeShift(h, m, s);
        // 超过120分钟的要算为120分钟
        players[i].time = (players[i].time > 120 ? 120 : players[i].time) * 60;
    }

    scanf("%d%d", &K, &M);
    for (int i = 0, id; i < M; ++i) {
        scanf("%d", &id);
        tab[id].is_vip = 1;
    }
    for (int i = 1; i <= K; ++i) {
        tab[i].time = tab[i].num = 0;
    }

    // 将用户按照到达时间升序排序
    qsort(players, N, sizeof(struct player), cmp);

    for (int i = 0; i < N; ++i) {
        if (vis[i]) continue;   //已经玩过的vip用户就不看了
        int minTi = DEF;        //该用户开始玩耍的最小时间
        int tabId = -1;         //当前最优桌子序号

        //vip客户先查看是否有空的vip桌子  没有就当成一般客户对待
        if (players[i].is_vip)
            for (int j = 1; j <= K; ++j) {
                if (tab[j].is_vip && tab[j].time <= players[i].arr) {
                    minTi = tab[j].time;
                    tabId = j;
                    break;
                }
            }

        if (tabId == -1)
            for (int j =1; j <= K; ++j) {
                if (tab[j].time <= players[i].arr) {    //有空的桌子
                    minTi = tab[j].time;
                    tabId = j;
                    break;
                } else if (tab[j].time < minTi) {       //没有空的桌子就找最快结束的桌子
                    minTi = tab[j].time;
                    tabId = j;
                }
            }

        //需要排队且最先空闲的桌子是vip而当前客户非vip
        if (minTi > players[i].arr && tab[tabId].is_vip && !players[i].is_vip) {
            int vip = haveVip(tabId, i);                                    //查找队列中是否有vip用户
            if (vip != -1) {                                                //先让vip用户使用
                if ((players[vip].start = minTi) >= E)                      //使用前先判断是否已经打烊
                    break;
                tab[tabId].num++;
                tab[tabId].time = players[vip].start + players[vip].time;   //计算桌子的下次空闲时间
                i--;                                                        //当前用户不使用，再轮一遍
                vis[vip] = 1;

                printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", players[vip].arr / 3600, players[vip].arr / 60 % 60,
                       players[vip].arr % 60,
                       players[vip].start / 3600, players[vip].start / 60 % 60, players[vip].start % 60,
                       (players[vip].start - players[vip].arr + 30)/60);
                continue;
            }
        }

        if ((players[i].start = max(minTi,players[i].arr)) >= E) break;     //使用前先判断是否已经打烊
        tab[tabId].num++;
        tab[tabId].time = players[i].start + players[i].time;
        // vis[i]=1;                                                        //非插队用户不记录也可以
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", players[i].arr / 3600, players[i].arr / 60 % 60,
               players[i].arr % 60,
               players[i].start / 3600, players[i].start / 60 % 60, players[i].start % 60,
               (players[i].start - players[i].arr + 30)/60);

    }

    for (int i = 1; i <= K; ++i) {
        printf("%d%c", tab[i].num, i == K ? '\n' : ' ');
    }
}