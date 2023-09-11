#include "Harl.hpp"

int main(void)
{
    Harl harl;

    // Test different complaint levels
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");

    // Test an invalid complaint level
    harl.complain("INVALID");
    harl.complain("1");
    harl.complain("NOT LEVEL");

    return (0);
}