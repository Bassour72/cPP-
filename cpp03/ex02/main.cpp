#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n--- إنشاء كائنات ClapTrap و FragTrap ---\n";
    ClapTrap clap1("CL4P-TP");
    FragTrap frag1("FR4G-TP");

    std::cout << "\n--- اختبار الهجوم ---\n";
    clap1.attack("Target1");
    frag1.attack("Target2");

    std::cout << "\n--- اختبار تلقي الضرر ---\n";
    clap1.takeDamage(3);
    frag1.takeDamage(20);

    std::cout << "\n--- اختبار الإصلاح ---\n";
    clap1.beRepaired(5);
    frag1.beRepaired(10);

    std::cout << "\n--- اختبار دالة FragTrap الخاصة ---\n";
    frag1.highFivesGuys();

    std::cout << "\n--- اختبار نسخ FragTrap ---\n";
    FragTrap frag2 = frag1;      // copy constructor
    frag2.setName("FR4G-COPY");
    frag2.attack("AnotherTarget");
    frag2.highFivesGuys();

    std::cout << "\n--- اختبار assignment operator ---\n";
    FragTrap frag3;
    frag3 = frag1;
    frag3.setName("FR4G-ASSIGN");
    frag3.attack("FinalTarget");
    frag3.highFivesGuys();

    std::cout << "\n--- نهاية البرنامج (تدمير الكائنات) ---\n";
    return 0;
}

