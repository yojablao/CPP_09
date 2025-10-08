#include "PmergeMe.hpp"
 ;
void PmergeMe::deqlogic(std::deque<int> &l)
{
    if (l.size() <= 1)
        return;

    std::deque<int> ga; // smaller 
    std::deque<int> gb; //  bigger 
    // int first, second;

    for (size_t i = 0; i + 1 < l.size(); i += 2) {
        std::pair<int,int> gro;
        if (l[i] < l[i+1]) {
            gro.first = l[i];
            gro.second = l[i+1];
        } else {
            gro.first = l[i+1];
            gro.second = l[i];
        }

        ga.push_back(gro.first);
        gb.push_back(gro.second);
    }
    if (l.size() % 2 != 0)
        ga.push_back(l.back());

    deqlogic(gb);

    l.clear();
    for (size_t i = 0; i < gb.size(); ++i)
        l.push_back(gb[i]);

    for (size_t i = 0; i < ga.size(); ++i) {
        std::deque<int>::iterator pos = std::lower_bound(l.begin(), l.end(), ga[i]);
        l.insert(pos, ga[i]);
    }
}
void PmergeMe::veclogic(std::vector<int> &l)
{
    if (l.size() <= 1)
        return;

    std::vector<int> ga; // smaller 
    std::vector<int> gb; // bigger 

    for (size_t i = 0; i + 1 < l.size(); i += 2) {
        std::pair<int,int> gro;
        if (l[i] < l[i+1]) {
            gro.first = l[i];
            gro.second = l[i+1];
        } else {
            gro.first = l[i+1];
            gro.second = l[i];
        }
        ga.push_back(gro.first);
        gb.push_back(gro.second);
    }
    if (l.size() % 2 != 0)
        ga.push_back(l.back());
    veclogic(gb);
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
void printvec(std::vector<int> &l)
{
    for (size_t i = 0; i < l.size(); i++)
    {
        std::cout << l[i] << " ";
    }
    std::cout << std::endl;
}
void PmergeMe::setup_algo(int ac, char **av)
{
    try {
        PmergeMe pm;
        pm.parse(ac, av);
        std::cout << "Before:  " ;  printvec(pm.vec);
        clock_t start_vec = clock(); 
        
        pm.veclogic(pm.vec) ;   clock_t end_vec = clock();
 
        std::cout << "After:   " ;  printvec(pm.vec);
        std::cout << "Time to process a range of " << pm.vec.size()
                  << " elements with std::vector : " 
                  << std::fixed << double(end_vec - start_vec) / CLOCKS_PER_SEC << " us" << std::endl;
        clock_t start_deq = clock(); 
        pm.deqlogic(pm.deq);  
        clock_t end_deq = clock();  
        std::cout << "Time to process a range of " << pm.deq.size()
                  << " elements with std::deque : " 
                  <<std::fixed << double(end_deq - start_deq) / CLOCKS_PER_SEC << " us" << std::endl;

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
