/*
ID: interne4
PROG: rect1
LANG: C++
*/
/**************************************	
	OIer C++ IDE Generate
web:	http://www.n8lm.cn/product?id=1
Please don't cut down these.
**************************************/
#include <fstream>
#include <cmath>
#include <queue>
#include <memory.h>
using namespace std;
ifstream fin("rect1.in");
ofstream fout("rect1.out");

struct point { int x, y; };
struct rect { point p1, p2; int c; };//c表颜色
int area(rect r) {					//求面积
    return (r.p2.x-r.p1.x)*(r.p2.y-r.p1.y);
}
struct cutRect {
public:
    queue<rect> Q;
    rect nil;
    cutRect() { nil.c = -1; }
    void add(rect r) {				//加点
        Q.push(r);
    }
    void cut(rect r1, rect r2) {	//两个矩形的切割
        if(r2.p2.x <= r1.p1.x || r2.p2.y <= r1.p1.y
            || r2.p1.x >= r1.p2.x || r2.p1.y >= r1.p2.y) {
            add(r2);
            return;
        }

        rect rt = r2;
        if(r2.p2.x > r1.p2.x) {
            rt.p1.x = r1.p2.x, rt.p1.y = r2.p1.y, rt.p2 = r2.p2;
            r2.p2.x = r1.p2.x;
            add(rt);
        }
        if(r2.p1.x < r1.p1.x) {
            rt.p1 = r2.p1, rt.p2.y = r2.p2.y, rt.p2.x = r1.p1.x;
            r2.p1.x = r1.p1.x;
            add(rt);
        }
        if(r2.p1.y < r1.p1.y) {
            rt.p1 = r2.p1, rt.p2.y = r1.p1.y, rt.p2.x = r2.p2.x;
            r2.p1.y = r1.p1.y;
            add(rt);
        }
        if(r2.p2.y > r1.p2.y) {
            rt.p2 = r2.p2, rt.p1.x = r2.p1.x, rt.p1.y = r1.p2.y;
            r2.p2.y = r1.p2.y;
            add(rt);
        }
    }
    void cut(rect rt) {				//加入一个矩形对所有已有举行切割
        Q.push(nil);
        while(!Q.empty()) {
            rect rp = Q.front(); Q.pop();
            if(rp.c == -1) break;
            cut(rt, rp);
        }
        Q.push(rt);
    }
    void pro() {					//统计各颜色的面积
        int cnum[2600]; memset(cnum, 0, sizeof(cnum));
        rect rp;
        while(!Q.empty()) {
            rp = Q.front(); Q.pop();
            cnum[rp.c] += area(rp);
        }
        for(int i=0; i<2501; i++)
            if(cnum[i])
               fout << i << ' ' << cnum[i] << endl;
    }
}C;
int main()
{
    int W, H, n;
    rect rt;

    fin >> W >> H >> n;
    rt.p1.x = rt.p1.y = 0;
    rt.p2.x = W, rt.p2.y = H, rt.c = 1;
    C.add(rt);
    for(int i=0; i<n; i++) {
        fin >> rt.p1.x >> rt.p1.y >> rt.p2.x >> rt.p2.y >> rt.c;
        C.cut(rt);
    }
    C.pro();
    return 0;
}
/*
只是抄别人的，只觉得这人写的短小精干让人佩服。
*/



