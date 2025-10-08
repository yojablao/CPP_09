name  = PmergeMe

src = main.cpp  PmergeMe.cpp
head = PmergeMe.hpp
obj = $(src:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
%.o :%.cpp $(head)
	$(CXX) $(CXXFLAGS) $< -c -o $@

all:$(name)

$(name) : $(obj)
	$(CXX) $(CXXFLAGS) $(obj) -o $(name)

clean :
	rm -rf $(obj)
fclean : clean
	rm -rf $(name)
re : fclean all