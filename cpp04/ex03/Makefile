NAME      = DiamondTrap

CPP       = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98  -Wshadow

SRC       = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp 
OBJ       = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp ClapTrap.hpp FragTrap.hpp ScavTrap.hpp  DiamondTrap.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean