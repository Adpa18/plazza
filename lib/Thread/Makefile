SRC=    src/Thread.cpp          \
				src/ThreadPool.cpp      \
				src/ThreadException.cpp \
				src/AThreadable.cpp     \
				src/Mutex.cpp           \
				src/Lockable.cpp        \
				src/LockableQueue.cpp   \


OBJS= $(SRC:%cpp=%o)

RM= rm -rf

NAME= ../libthread.a

CPPFLAGS= -std=c++11 -g -O2 -I ./include -Wall -Wextra -Werror

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
