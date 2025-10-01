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
    void check_num(float p,const std::string &str);

};
void BitcoinExchange::print_it(std ::string & str, float p)
{
    std::cout << str+ " => " <<  p << " = " << get_close_one(str) * p << std::endl;
}
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
        buffer.clear();
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
        buf.clear();

    }
    in.close();
    // std::cout << "value : : " << l["2022-03-29"]   << std::endl;
}
float BitcoinExchange::get_close_one(const std::string &str) 
{
    std::map<std::string,float>::iterator it = l.lower_bound(str);
    if (it != l.end() && it->first == str)
        return it->second;
    else if(it != l.begin())
    {--it;
    return it->second;}
    std::cout << str << "TEST "<< std::endl;

    throw std::logic_error("Error: bad input => " + str);
}
BitcoinExchange BitcoinExchange::create() {
    return BitcoinExchange();
}
void BitcoinExchange::check_num(float p,const std::string &str)
{
    if(p > 1000)throw std::logic_error ("too large a number.");
    if(p < 0)throw std::logic_error ("not a positive number.");
}
void BitcoinExchange::file_transaction(char *file)
{
    std::ifstream in;

    std::string buffer;
    std::stringstream buf;
    float p;
    in.open(file);
    if(!in.is_open())
        throw std::logic_error("could not open file.");
    while(std::getline(in,buffer))
    {
        buf.clear(); 
        try
        {
            
            buf << (buffer) ;
            buffer.clear();
            if (std::getline(buf, buffer, '|') && (buf >> p) )
            {
                check_num(p,buffer);
                print_it(buffer,p);
            } else {
                if(buffer == "date")
                {
                    buf.clear();
                    continue;
                }
                // std::cout << buffer<< ":" << p << std::endl;
               throw std::logic_error("Error: bad input => " + buffer);
            }
            
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: "<< e.what() << '\n';
            buf.clear();
        }
        

    }
    in.close();
    // std::cout << "value : : " << l["2022-03-29"]   << std::endl;
    
}

BitcoinExchange::~BitcoinExchange()
{}



#endif