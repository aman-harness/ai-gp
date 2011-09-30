/*****************************************
* Title: Solid Geometry Artificial Intelligence
* Created by Alchemist
* Date: 2011.9.30
*
*
******************************************/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <map>

#include "geometry.h"

using namespace std;
using namespace n8lm;

vector<Point> points;
vector<Line> lines;
vector<Plane> planes;

int GetLineByName(string str)
{
    for(int i = 1; i < Line::lLastId; i ++)
    {
        if(str == lines[i].GetName())
            return lines[i].GetId();
    }
    return 0;
}

bool isEnd();

void parallel(int a, int b)
{
    if(a == b)
        return;
    if(a > b)
    {
        int t = b;
        b = a;
        a = t;
    }
    int pl = map_p3[lines[a].points[0].GetId()][lines[a].points[1].GetId()][lines[b].points[0].GetId()];
    planes[pl].Add(lines[a]);
    planes[pl].Add(lines[b]);
    map_l2[a][b] = PARALLEL;
}

ofstream logfile;

void aibfs()
{
    //int i,j,k,l;
    while(1)
    {
        if(isEnd())
        {
            cout << "Successfully proved!" << endl;
            return;
            // TODO: Do output.
        }
        // Self-evident Truth 1
        for(int i = 1; i < Point::pLastId; i ++)
        {
            for(int j = 1; j < i; j ++)
            {
                for(int k = 1; k < Plane::fLastId; k ++)
                {
                    if(planes[k].Enable() && planes[k].IsInPlane(points[i]) && planes[k].IsInPlane(points[j]))
                        planes[k].Add(lines[map_p2[j][i]]);
                }
            }
        }

        // Self-evident Truth 2
        short pp[maxn] = {0};
        int p[maxn] = {0}, pn;
        for(int i = 1; i < Plane::fLastId; i ++)
        {
            if(planes[i].Enable())
            for(int j = 1; j < i; j ++)
            {
                if(!planes[j].Enable())
                    break;
                memset(pp,0,sizeof(pp));
                for(int k = 0; k < planes[i].points.size(); k ++)
                {
                    pp[planes[i].points[k].GetId()] ++;
                }
                for(int k = 0; k < planes[j].points.size(); k ++)
                {
                    pp[planes[j].points[k].GetId()] ++;
                }
                memset(p,0,sizeof(p));
                pn = 0;
                for(int k = 1; k < Point::pLastId; k ++)
                {
                    if(pp[k] == 2)
                    {
                        p[pn ++] = k;
                    }
                    if(pn == 3)
                    {
                        if(lines[map_p2[p[0]][p[1]]].IsInLine(points[p[2]]))
                            break;
                        else
                            pn = 2;
                    }
                }
                if(pn == 3)
                {
                    for(int k = 0; k < planes[i].lines.size(); k ++)
                        planes[j].Add(planes[i].lines[k]);
                    for(int k = 0; k < planes[i].points.size(); k ++)
                        planes[j].Add(planes[i].points[k]);
                    planes[i].SetEnable(1);
                }
            }
        }
        //for()

        // Self-evident Truth 3
        /*for(int i = 1; i < Plane::fLastId; i ++)
        {
            for(int j = 1; j < i; j ++)
            {
                for(int k = 0; k < planes[i].points.size(); k ++)
                {
                    if(planes[j].IsInPlane(planes[i].points[k]))
                        lines[map_f2[j][i]].Add(planes[i].points[k]);
                }
            }
        }*/

        // Self-evident Truth 4
        for(int i = 1; i < Line::lLastId; i ++)
        {
            for(int j = 1; j < i; j ++)
            {
                for(int k = 1; k < j; k ++)
                {
                    if(map_l2[j][i] == PARALLEL && map_l2[k][j] == PARALLEL && map_l2[k][i] != PARALLEL)
                    {
                        parallel(k,i);
                    }
                }
            }
        }
        // Self-evident Truth 5
        //for()
	}
}

int pn;

void copyright()
{
    cout << "Solid Geometry Artificial Intelligence" << endl;
    cout << "Created by Alchemist" << endl;
    cout << "Date: 2011.9.30" << endl;
    cout << endl;
}


const char TYPE_PARALLEL = 'P';
const char TYPE_COPLANAR = 'C';
const char TYPE_COLLINEAR = 'c';

struct Condition
{
    char type;
    int aug[10];
}conclu;

bool isEnd()
{
    if(conclu.type == TYPE_PARALLEL)
    {
        if(map_l2[conclu.aug[0]][conclu.aug[1]] == PARALLEL)
            return 1;
    }
    return 0;
}

void input()
{
    int i, j, k;
    string str, a, b;
    int la,lb;

    cout << "Please input the amount of points." << endl;
    cin >> pn;
    string name;

    name = "Pa";
    points.clear();
    Point p("VACANCY_P");
    points.push_back(p);
    for(i = 1; i <= pn; i ++)
    {
        Point po(name);
        name[1] ++;
        points.push_back(po);
    }
    name = "L";
    lines.clear();
    Line l("VACANCY_L");
    lines.push_back(l);
    for(i = 1; i <= pn; i ++)
    for(j = 1; j < i; j ++)
    {
        Line li(name + points[j].GetName()[1] + points[i].GetName()[1]);
        li.Add(points[j]);
        li.Add(points[i]);
        lines.push_back(li);
        map_p2[j][i] = li.GetId();
    }

    name = "F";
    planes.clear();
    Plane f("VACANCY_F");
    planes.push_back(f);
    for(i = 1; i <= pn; i ++)
    for(j = 1; j < i; j ++)
    for(k = 1; k < j; k ++)
    {
        Plane pl(name + points[k].GetName()[1] + points[j].GetName()[1] + points[i].GetName()[1]);
        pl.Add(points[k]);
        pl.Add(points[j]);
        pl.Add(points[i]);
        planes.push_back(pl);
        map_p3[k][j][i] = pl.GetId();
    }

    cout << "Please input the conditions" << endl;
    logfile << "Conditions:" << endl;
    while(1)
    {
        cin >> str;
        if(str == "//")
        {
            cin >> a >> b;

            la = GetLineByName(a);
            lb = GetLineByName(b);
            if(la > 0 && lb > 0)
            {
                parallel(la, lb);
                cout << lines[la].GetName() << " // " << lines[lb].GetName() << endl;
                logfile << lines[la].GetName() << " // " << lines[lb].GetName() << endl;
            }
        }
        else if(str == "help")
        {
            cout << "// : parallel" << endl;
            cout << "end : end up the input" << endl;
            cout << "quit : end up the input" << endl;
        }
        else  if(str == "end" || str == "quit")
            break;
        else
        {
            cout << "\"" << str << "\" can not be recognised." << endl;
            cout << "input \"help\" and enter. It will show the help." << endl;
        }
    }
	cout << "You have been finished the input of conditions" << endl;
	cout << endl;
    cout << "Please input the confirmation:" << endl;
    logfile << "Confirmation:" << endl;

    /*
    TODO: code about input hte information of confirmation.
    */
    cin >> str;
    if(str == "//")
    {
        cin >> a >> b;

        conclu.type = TYPE_PARALLEL;
        conclu.aug[0] = GetLineByName(a);
        conclu.aug[1] = GetLineByName(b);
        cout << lines[conclu.aug[0]].GetName() << " // " << lines[conclu.aug[1]].GetName() << endl;
        logfile << lines[conclu.aug[0]].GetName() << " // " << lines[conclu.aug[1]].GetName() << endl;
    }

}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    copyright();

    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    logfile.open("log.txt", ios::app);
    logfile << "The current date/time is: " << asctime (timeinfo) << endl;
    //streambuf *outbuf = cout.rdbuf(logfile.rdbuf());

    input();
    aibfs();
    logfile << endl;
	//cout << "You have been finished the input of conditions" << endl;
	cin.get();
	//system("pause");
	return 0;
}
