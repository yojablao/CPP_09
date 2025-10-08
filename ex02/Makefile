name  = btc

src = main.cpp   PmergeMe.cpp
head =   BitcPmergeMe.hpp
obj = $(src:%.cpp=%.o)

CCXX = c++ -Wall -Wextra -Werror 
CflagXX = -fsanitize=address -std=c++98 
%.o :%.cpp $(head)
	$(CCXX) $(CflagXX) $< -c -o $@

all:$(name)

$(name) : $(obj)
	$(CCXX) $(CflagXX) $(obj) -o $(name)

clean :
	rm -rf $(obj)
fclean : clean
	rm -rf $(name)
re : fclean all