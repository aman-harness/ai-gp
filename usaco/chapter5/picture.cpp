/*
ID: interne4
PROG: picture
LANG: C++
DATA: 2011.02.21
ALGO: 
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
ifstream fin("picture.in");
ofstream fout("picture.out");

struct point
{
	int x, y;
};

struct rect
{
	point p1, p2;
	int c;
	int isc[4];
};//c表颜色
int area(rect r) {					//求面积
    return (r.p2.x-r.p1.x)*(r.p2.y-r.p1.y);
}

int per(rect r) {					//求面积
    return ((r.p2.x-r.p1.x)+(r.p2.y-r.p1.y)) * 2;
}

struct cutRect {
public:
    queue<rect> Q;
    rect nil;
    int per;
    cutRect()
	{
		nil.c = -1;
		per = 0;
	}
    void add(rect r) {				//加点
        Q.push(r);
    }
    void cut(rect r1, rect r2) {	//两个矩形的切割
    	
    	per += per(r2);
    	
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

    fin >> n;
    rt.p1.x = rt.p1.y = 0;
    rt.p2.x = W, rt.p2.y = H, rt.c = 1;
    C.add(rt);
    for(int i=0; i<n; i++) {
        fin >> rt.p1.x >> rt.p1.y >> rt.p2.x >> rt.p2.y;
        rt.isc[0] = rt.isc[1] = rt.isc[2] = rt.isc[3] = 1;
        C.cut(rt);
    }
    C.pro();
    return 0;
}



