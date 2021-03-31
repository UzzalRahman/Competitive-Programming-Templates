//*** Polygon: Check if it is possible to create a polygon with a given angle ***
void makePolygon(double a)
{
    // N denotes the number of sides of polygons possible
    double n = 360 / (180 - a);
    if (n == (int)n)
        cout << "YES";
    else
        cout << "NO";
}
