NAME      = InterfaceRecap

CPP       = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98  -Wshadow

SRC       = main.cpp Character.cpp AMateria.cpp Cure.cpp Ice.cpp MateriaSource.cpp 
OBJ       = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp AMateria.hpp Character.hpp Cure.hpp Ice.hpp  ICharacter.hpp  IMateriaSource.hpp MateriaSource.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean