#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

int main()
{
    // إنشاء كائنات ClapTrap
    ClapTrap robot1("CL4P-TP");
    ClapTrap robot2("FR4G-TP");

    std::cout << "\n--- الاختبار: الهجوم ---\n";
    robot1.attack("Target1");  // يجب أن يقلل طاقة robot1
    robot1.attack("Target2");  

    std::cout << "\n--- الاختبار: تلقي الضرر ---\n";
    robot1.takeDamage(3);      // تقلل hit points
    robot1.takeDamage(5);      
    robot1.takeDamage(10);     // يجب أن تصل hit points إلى 0

    std::cout << "\n--- الاختبار: الإصلاح ---\n";
    robot1.beRepaired(5);      // لا يجب أن ينفذ لأن hit points = 0
    robot2.beRepaired(4);      // يزيد hit points ويقلل الطاقة

    std::cout << "\n--- الاختبار: نفاد الطاقة ---\n";
    for (int i = 0; i < 11; i++)
        robot2.attack("Dummy");  // عندما تصل الطاقة إلى 0، يجب أن لا يتم الهجوم

    std::cout << "\n--- الاختبار: نسخ الكائن ---\n";
    ClapTrap robot3 = robot2;  // copy constructor
    robot3.setName("CL0P-TP");
    robot3.attack("AnotherTarget");

    return 0;
}
