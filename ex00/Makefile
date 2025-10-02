name  = btc

src = main.cpp   BitcoinExchange.cpp
head =   BitcoinExchange.hpp
obj = $(src:.cpp=.o)

CC = c++ -Wall -Wextra -Werror -std=c++98
%.o :%.cpp $(head)
	$(CC) $< -c -o $@

all:$(name)

$(name) : $(obj)
	$(CC) $(obj) -o $(name)

clean :
	rm -rf $(obj)
fclean : clean
	rm -rf $(name)
re : fclean all