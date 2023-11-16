

class circule : public point
{
public:
    double PI = acos(-1);
    double r;
    double x, y;
    circule(double _x, double _y, double _r)
    {
        x = _x;
        y = _y;
        r = _r;
    }
    circule(point a)
    {
        x = a.x;
        y = a.y;
        r = 0;
    }
    circule() {}
};
