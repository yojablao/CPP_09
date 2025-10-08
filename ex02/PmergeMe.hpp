#ifndef PmergeMe__HPP
#define PmergeMe__HPP


#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <sys/time.h>

class PmergeMe
{
private:
    std::vector<int> vec;   
    std::deque<int> deq; 
    PmergeMe();
public:
    ~PmergeMe();
    void parse(int ac, char **av);
    void veclogic(std::vector<int> &p);
    void deqlogic(std::deque<int> &l);
    static void setup_algo(int ac, char **av);
};
#endif
