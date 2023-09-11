#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
        Bureaucrat bureaucrat1("John", 30);
        Bureaucrat bureaucrat2("Alice", 100);

        Form form1("Allow Nukes", 40, 30);
        Form form2("Enforce Happiness", 80, 70);

        std::cout << bureaucrat1 << std::endl;
        std::cout << bureaucrat2 << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

    try
    {
        form1.beSigned(bureaucrat1);
        form1.beSigned(bureaucrat1);
        // form2.beSigned(bureaucrat2);

        bureaucrat1.signForm(form1);
        bureaucrat1.signForm(form2);
        bureaucrat2.signForm(form1);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;

    return (0);
}
