#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <map>
// #

class BitcoinExchange 
{
private:
    BitcoinExchange();
    std::map <std::string,float> l;
    // std::map <std::string,float> t;
    
    public:
    ~BitcoinExchange();
    static BitcoinExchange create();
    void file_transaction(char *file);
    float get_close_one(const std::string &str) ;
    void print_it(std ::string & str, float p );
    void check_num(float p);

};



#endif