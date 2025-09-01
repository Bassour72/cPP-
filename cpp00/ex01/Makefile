NAME      = Phonebook

CPP       = c++
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC       = Contact.cpp  PhoneBook.cpp  main.cpp
OBJ       = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Contact.hpp PhoneBook.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
