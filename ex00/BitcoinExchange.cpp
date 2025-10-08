#include "BitcoinExchange.hpp"

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
            database[buffer] = p;
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
}
float BitcoinExchange::get_close_one(const std::string &str) 
{
    std::map<std::string,float>::iterator it = database.lower_bound(str);
    if (it != database.end() && it->first == str)
        return it->second;
    else if(it != database.begin())
    {--it;
    return it->second;}
    throw std::logic_error("bad input => " + str);
}
BitcoinExchange BitcoinExchange::create() {
    return BitcoinExchange();
}
void BitcoinExchange::check_num(float p)
{
    if(p > 1000)throw std::logic_error ("too large a number.");
    if(p < 0)throw std::logic_error ("not a positive number.");
}
void BitcoinExchange::file_transaction(char *file)
{
    std::ifstream in (file);
    if(!in.is_open())
        throw std::logic_error("could not open file.");

    std::string buffer;
    std::string date;
    std::stringstream buf;
    float value;
    while(std::getline(in,buffer))
    {
        try
        {
             if (buffer.find("date") != std::string::npos && buffer.find("value") != std::string::npos)
                continue;
            buf << (buffer) ;
            if (std::getline(buf, date, '|') && (buf >> value) )
            {
                check_num(value);
                print_it(date,value);
                    buffer.clear();
                    buf.clear();
            } else {
                if(buffer == "date " || buffer == "value" )
                {
                    buf.clear();
                    continue;
                }
               throw std::logic_error("bad input => " + buffer);
            }
            
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: "<< e.what() << '\n';
            buf.clear();
        }
        

    }
    in.close();
}

BitcoinExchange::~BitcoinExchange()
{
    database.clear();
}
