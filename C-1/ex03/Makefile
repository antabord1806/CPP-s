NAME = unnecessary_violence

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re