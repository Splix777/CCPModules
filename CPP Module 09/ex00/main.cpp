#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./btc <input.txt>" << std::endl;
        return (1);
    }
    std::string file = argv[1];
    BitcoinExchange exchange;
    try
    {
        exchange.loadData();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " <.csv file!>" << std::endl;
    }
    try
    {
        exchange.printExchangeRates(file);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " <.txt file!>" << std::endl;
    }
    
    return (0);
}