using namespace std;
#include "geometry.h"

namespace n8lm
{
	int map_p2[maxn][maxn] = {0};
	int map_p3[maxn][maxn][maxn] = {0};
	int map_f2[maxn][maxn] = {0};
	int map_l2[maxn][maxn] = {0};


	int Object::lastId = 0;
	int Point::pLastId = 0;
	int Line::lLastId = 0;
	int Plane::fLastId = 0;

    Object::Object(string name)
    {
        this->name = name;
        id = lastId ++;
    }

    string Object::GetName()
    {
        return name;
    }

    int Object::GetId()
    {
        return id;
    }

    bool Object::Enable()
    {
        return enable;
    }

    void Object::SetEnable(bool x)
    {
        enable = x;
    }

    Point::Point(string name):Object(name)
    {
        id = pLastId ++;
    }

    Line::Line(string name):Object(name)
    {
        id = lLastId ++;
    }

    void Line::Add(Point p)
    {
        if(IsInLine(p))
            return;
        for(int i = 0; i < points.size(); i ++)
        {
            if(points[i].GetId() < p.GetId())
                map_p2[points[i].GetId()][p.GetId()] = this->GetId();
            else
                map_p2[p.GetId()][points[i].GetId()] = this->GetId();
        }
        for(int i = 0; i < points.size(); i ++)
        for(int j = 0; j < i; j ++)
        {
            if(points[i].GetId() < p.GetId())
            {
                map_p3[points[j].GetId()][points[i].GetId()][p.GetId()] = -1;
            }
            else if(points[j].GetId() > p.GetId())
            {
                map_p3[p.GetId()][points[j].GetId()][points[i].GetId()] = -1;
            }
            else
                map_p3[points[j].GetId()][p.GetId()][points[i].GetId()] = -1;
        }
        points.push_back(p);
    }

    bool Line::IsInLine(Point p)
    {
        for(int i = 0; i < points.size(); i ++)
        {
            if(points[i].GetId() == p.GetId())
                return true;
        }
        return false;
    }


    Plane::Plane(string name):Object(name)
    {
        id = fLastId ++;
    }

    void Plane::Add(Point p)
    {
        if(IsInPlane(p))
            return;
        for(int i = 0; i < points.size(); i ++)
        for(int j = 0; j < i; j ++)
        {
            if(i == j)
                continue;
            int p1,p2,p3;
            p1 = points[i].GetId();
            p2 = points[j].GetId();
            p3 = p.GetId();

            if(p2 > p3)
            {
                swap(p2,p3);
            }

            if(p1 > p2)
            {
                swap(p1,p2);
            }

            if(p2 > p3)
            {
                swap(p2,p3);
            }

            map_p3[p1][p2][p3] = this->GetId();
        }
        points.push_back(p);
    }

    void Plane::Add(Line l)
    {
        if(IsInPlane(l))
            return;

        for(int i = 0; i < lines.size(); i ++)
            Add(lines[i]);
        lines.push_back(l);
    }

    bool Plane::IsInPlane(Point p)
    {
        for(int i = 0; i < points.size(); i ++)
        {
            if(points[i].GetId() == p.GetId())
                return true;
        }
        return false;
    }

    bool Plane::IsInPlane(Line l)
    {
        for(int i = 0; i < lines.size(); i ++)
        {
            if(lines[i].GetId() == l.GetId())
                return true;
        }
        return false;
    }
};
