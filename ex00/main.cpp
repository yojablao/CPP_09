#include <iostream>
#include "BitcoinExchange.hpp"


int main( int ac , char **av)
{
    // if(ac != 2)
    // return std::cout << "Error: could not open file." << std::endl,1;
    // BitcoinExchange  p = BitcoinExchange::create();
    // return 0;
      try {
        BitcoinExchange btc = BitcoinExchange::create(); 

        if (ac == 2) {
            btc.file_transaction(av[1]);
        } else {
            std::cout << "Usage: ./btc <transaction_file>" << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cerr  << e.what() << std::endl;
    }

}