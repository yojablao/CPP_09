#include <iostream>
#include "BitcoinExchange.hpp"


int main( int ac , char **av)
{
    // if(ac != 2)
    // return std::cout << "Error: could not open file." << std::endl,1;
    // BitcoinExchange  p = BitcoinExchange::create();
    // return 0;
      try {
        BitcoinExchange btc = BitcoinExchange::create(); // ✅ works with private constructor

        // if (argc == 2) {
        //     btc.file_transaction(argv[1]);
        // } else {
        //     std::cout << "Usage: ./btc <transaction_file>" << std::endl;
        // }
    }
    catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

}