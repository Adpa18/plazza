SRC=    main.cpp          \

OBJS= $(SRC:%cpp=%o)

RM= rm -rf

NAME= ../plazza

CPPFLAGS= -std=c++11 -g -O2 -I ../include -I ../lib/Thread/include/ -Wall -Wextra -Werror

LDFLAGS= -static -lpthread -pthread -L../lib/ -lthread

CC= g++

$(NAME):    $(OBJS)
	$(CC) $(CPPFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

all:    $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
