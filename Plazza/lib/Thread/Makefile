SRC=    src/Thread.cpp          \
		src/ThreadPool.cpp      \
		src/ThreadException.cpp \
		src/AThreadable.cpp     \
		src/Mutex.cpp           \


OBJS= $(SRC:%cpp=%o)

RM= rm -rf

NAME= ../libthread.a

CPPFLAGS= -std=c++11 -g -O2 -I ./include

LDFLAGS= -lpthread

CC= g++

$(NAME):    $(OBJS)
	ar  rcs $(NAME) $(OBJS)

all:    $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all