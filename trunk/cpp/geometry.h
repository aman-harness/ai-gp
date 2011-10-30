/*****************************************
* Title:        Solid Geometry Artificial Intelligence
* Anthor:       Alchemist
* Date:         2011.9.21
* File:         geometry.h
* Description:
******************************************/
#ifndef _N8LM_GEO_
#define _N8LM_GEO_

#include <string>
#include <vector>

using namespace std;

namespace n8lm
{

	const int maxn = 100;

	extern int map_p2[maxn][maxn];
	extern int map_p3[maxn][maxn][maxn];
	extern int map_f2[maxn][maxn];
	extern int map_l2[maxn][maxn];

	const int PARALLEL = -1;

	class Object
	{
    protected:
		string name;
		int id;
		bool enable;
	public:
		static int lastId;

		Object(string name);
		string GetName();

		int GetId();
		bool Enable();

		void SetEnable(bool x);
	};

	class Point: public Object
	{
	public:
		static int pLastId;
		Point(string name);
	};

	class Line: public Object
	{
	private:
	public:
		static int lLastId;
		vector<Point> points;

		Line(string name);
		void Add(Point p);
		bool IsInLine(Point p);

	};

	class Plane: public Object
	{
	private:
	public:
        static int fLastId;
		vector<Point> points;
		vector<Line> lines;

		Plane(string name);
		void Add(Point p);
		void Add(Line l);
		bool IsInPlane(Point p);
		bool IsInPlane(Line l);
	};

};
#endif
