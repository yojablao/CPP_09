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
    
    public:
    ~BitcoinExchange();
    static BitcoinExchange create();
    void file_transaction(char *file);

};

BitcoinExchange::BitcoinExchange()
{
    std::ifstream in;

    std::string buffer;
    std::stringstream buf;
    float p;
    in.open("data.csv");
    if(!in.is_open())
        throw std::logic_error("could not open  data.csv file.");
    while(std::getline(in,buffer))
    {
        buf << (buffer) ;
        // std::cout << buf;
        buffer.clear();
            // std::cout << "date : " << buffer << ", value :" << p << std::endl;
        sstream:
                if (std::getline(buf, buffer, ',') && (buf >> p)) {
            l[buffer] = p;
        } else {
            if(buffer == "date")
            {
                buf.clear();
                continue;

            }
            throw std::logic_error("something wrong in data.csv file");
        }
        // if(std::getline(buf,buffer,','))
        // {
        //     buf >> p;
        //     std::cout << "date : " << buffer << ", value :" << p << std::endl;
        
        //     // if(!buf.eof())
        //     //     throw std::logic_error("something wrong in data.csv file");
        //     l[buffer] = p;
        // }   
            // std::cout << "date : " << buffer << ", value :" << p << std::endl;
            buf.clear();

    }
    in.close();
            std::cout << "value : : " << l["2010-08-20"] << "" << std::endl;
}
BitcoinExchange BitcoinExchange::create() {
    return BitcoinExchange();
}
void BitcoinExchange::file_transaction(char *file)
{
    // std::ifstream in;
    // std::string buffer;
    // size_t i ;
    // in.open(file);
    // if(!in.is_open())
    //     throw std::logic_error(std::string("could not open") + std::string(file));
    // while(std::getline(in,buffer))
    // {
    //     data << buffer;   
    // }
    // in.close();
    // int date;
    // int day;
    // int xhar;
    // while (!data.eof())
    // {
        
    // }
    
}

BitcoinExchange::~BitcoinExchange()
{}



#endif