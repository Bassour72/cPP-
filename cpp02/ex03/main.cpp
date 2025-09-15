
#include "Point.hpp"  // ملف الكلاس Point

int main()
{
    // إنشاء رؤوس المثلث
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(2.0f, 4.0f);

    // نقاط للاختبار
    Point inside(2.0f, 2.0f);
    Point outside(5.0f, 5.0f);
    Point edge(2.0f, 0.0f);
    Point vertex(0.0f, 0.0f);

    // اختبار النقاط
    std::cout << "Inside point: " << bsp(a, b, c, inside) << std::endl;   // متوقع: 1 (true)
    std::cout << "Outside point: " << bsp(a, b, c, outside) << std::endl; // متوقع: 0 (false)
    std::cout << "Edge point: " << bsp(a, b, c, edge) << std::endl;       // متوقع: 0 (false)
    std::cout << "Vertex point: " << bsp(a, b, c, vertex) << std::endl;   // متوقع: 0 (false)

    return 0;
}
