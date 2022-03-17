/* 银行排队问题之单窗口“夹塞”版
 * https://pintia.cn/problem-sets/1448182951467995136/problems/1450246237311594496
 * 题意：N个人到到银行窗口办理业务，只有一个窗口，按照到达顺序进行排队，有M个朋友圈，后来的人看见前面有熟人可以让熟人进行办理，直到熟人开始办理自己的
 *      业务后，自己的等待时间就结束了，可以走了，而中间的人只能等着，按结束服务顺序打印所有人并且求所有人的平均等待时间
 * 提示：数据是按照到达时间来提供的；个人办理时间超过60分钟的算60分钟
 * 思路：模拟题，在遍历的时候需要将当前办理业务的人朋友圈的人找出来判断他们是否在队伍中
 *      朋友圈可以用不同名字的map执行同一个不为0的值表示朋友圈，也可以用并查集来表示
 * TODO
 *  喜欢：map可以替代并查集
 */
#include<cstdio>
#include<map>

using namespace std;
#define MAXSIZE 10100

int s[MAXSIZE];
map<string, int> group;
struct people {
    char name[5];
    int need;       //办理业务需要的时间
    int arrive;     //到达银行的时间
    int vis;        //是否已经办理过业务
} peo[MAXSIZE];

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1, num; i <= M; ++i) {     //遍历每个朋友圈，这里从1开始循环，是因为不存在的map键值对的值初始化是0，便于与无朋友圈的人区分
        scanf("%d", &num);
        char name[5];
        for (int j = 0; j < num; ++j) {
            scanf("%s", name);
            group[name] = i;                //只要是一伙的，map对应的值就不为0且是一样的
        }
    }
    for (int i = 0; i < N; ++i) {
        scanf("%s%d%d", peo[i].name, &peo[i].arrive, &peo[i].need);
        peo[i].need = peo[i].need > 60 ? 60 : peo[i].need;
        peo[i].vis=0;
    }

    int await=0;                            //总等待时间
    int last = 0;                           //最后一个用户的结束时间
    for (int i = 0; i < N; ++i) {
        if (peo[i].vis==1) continue;        //已经插过队的人不需要了
        if (peo[i].arrive>=last){           //这个人不用等待
            await+=0;
            last=peo[i].arrive+peo[i].need;
        } else{                             //这个人需要排队
            await+=last-peo[i].arrive;
            last+=peo[i].need;
        }
        peo[i].vis=1;
        printf("%s\n",peo[i].name);

        // 判断这个人是否有朋友圈
        if (group[peo[i].name]!=0){         //说明这个人还有伙伴
            int id=group[peo[i].name];
            for (int j = i+1; j <N; ++j) {  //查询后面是不是有认识的
                // 队伍中有伙伴，并且在当前人结束前在队列中，进行插队
                if (!peo[j].vis && group[peo[j].name]==id && last>=peo[j].arrive){
                    peo[j].vis=1;
                    await+=last-peo[j].arrive;
                    last+=peo[j].need;
                    printf("%s\n",peo[j].name); //插队提前办理，打印
                }
            }
        }
    }
    //TODO 标记：不能用float累加再求平均值，在随机大数据的情况下，浮点数的误差变大不能AC这个题了
    printf("%.1f",1.0*await/N);
}