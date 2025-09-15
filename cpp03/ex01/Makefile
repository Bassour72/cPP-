NAME      = ScavTrap

CPP       = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC       = main.cpp ClapTrap.cpp ScavTrap.cpp 
OBJ       = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean