NAME      = Animal

CPP       = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98  #-Wshadow

SRC       = main.cpp Animal.cpp Dog.cpp Cat.cpp
OBJ       = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Dog.hpp Cat.hpp Animal.hpp 
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean