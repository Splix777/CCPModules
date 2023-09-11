#include "Bureaucrat.hpp"

int main() {
    try {
        // Test various scenarios
		Bureaucrat myBureaucrat("John", 100);
		std::cout << myBureaucrat;

        // Valid grade scenarios
        Bureaucrat valid1("Valid1", 1);
        Bureaucrat valid2("Valid2", 50);
        Bureaucrat valid3("Valid3", 149);

        // Output valid grades
        std::cout << valid1 << valid2 << valid3;

        // Increment and decrement valid grades
        valid3.incrementGrade();
        valid2.decrementGrade();

        // Output modified valid grades
        std::cout << valid1 << valid2 << valid3;

        // Invalid grade scenarios
        // try {
        //     Bureaucrat invalid1("Invalid1", 0);
        // } catch (const std::exception &e) {
        //     std::cout << e.what() << std::endl;
        // }

        // try {
        //     Bureaucrat invalid2("Invalid2", 151);
        // } catch (const std::exception &e) {
        //     std::cout << e.what() << std::endl;
        // }

        // Copy constructor and assignment operator
        Bureaucrat copyValid1(valid1);
        Bureaucrat copyValid2("CopyValid2", 100);
        copyValid2 = valid2;

        std::cout << copyValid1 << copyValid2;

        // Exception handling for grade modifications
        try
        {
            valid3.incrementGrade();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        try
        {
            valid1.decrementGrade();
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
