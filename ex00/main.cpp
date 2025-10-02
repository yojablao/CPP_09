#include <iostream>
#include "BitcoinExchange.hpp"


int main( int ac , char **av)
{
      try {   
          if (ac == 2) {
            BitcoinExchange btc = BitcoinExchange::create(); 
            btc.file_transaction(av[1]);
        } else {
            std::cout << "Usage: ./btc <transaction_file>" << std::endl <<  "Error: could not open file." << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cerr  << e.what() << std::endl;
    }

}