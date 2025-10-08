#pragma ones


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
    void logic(std::vector<int> &p);
    static void setup_algo(int ac, char **av);
};
long getTimeMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000L) + tv.tv_usec;
}
void PmergeMe::logic(std::vector<int> &l)
{
    if (l.size() <= 1)
        return;

    std::vector<int> ga; // smaller 
    std::vector<int> gb; // bigger 

    for (size_t i = 0; i + 1 < l.size(); i += 2) {
        std::pair<int, int> gro = std::minmax(l[i], l[i+1]);
        ga.push_back(gro.first);
        gb.push_back(gro.second);
    }
    if (l.size() % 2 != 0)
        ga.push_back(l.back());

    logic(gb);

    l.clear();
    for (size_t i = 0; i < gb.size(); ++i)
        l.push_back(gb[i]);

    for (size_t i = 0; i < ga.size(); ++i) {
        std::vector<int>::iterator pos = std::lower_bound(l.begin(), l.end(), ga[i]);
        l.insert(pos, ga[i]);
    }
}
void PmergeMe::parse(int ac, char **av)
{
    std::set<int> seen; 

    for (int i = 1; i < ac; i++) {
        std::stringstream ss(av[i]);
        int n;

        if (!(ss >> n) || n < 0) {
            throw std::runtime_error("Error: invalid positive integer");
        }
        if (!seen.insert(n).second) {
            throw std::runtime_error("Error: duplicate number found");
        }
        vec.push_back(n);
        deq.push_back(n);
    }

    if (vec.empty()) {
        throw std::runtime_error("Error: no valid numbers provided");
    }
    
}
void PmergeMe::setup_algo(int ac, char **av)
{
    try {
        PmergeMe pm;
        pm.parse(ac, av);
        // std::cout << "not sorted: ";
        // for (size_t i = 0; i < pm.vec.size(); ++i) std::cout << pm.vec[i] << " ";
        //     std::cout << std::endl;
            
            std::cout << std::endl;
            std::cout << std::endl;
         clock_t start = clock(); 
        pm.logic(pm.vec);
         clock_t end = clock(); 
         std::cout << "Time to process a range of "<< pm.vec.size()<< " elements with std::vector :" << std::fixed<<float(double(end -start) / CLOCKS_PER_SEC) * 10  << " us" << std::endl;
        // for (size_t i = 0; i < pm.vec.size(); ++i) std::cout << pm.vec[i] << " ";
        //     std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{
}
