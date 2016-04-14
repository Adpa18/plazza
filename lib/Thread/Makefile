SRC=    src/AThreadable.cpp         \
        src/CondVar.cpp             \
        src/CondVarException.cpp    \
        src/Exception.cpp           \
        src/Lockable.cpp            \
        src/LockableQueueTask.cpp   \
        src/Mutex.cpp               \
        src/MutexException.cpp      \
        src/Task.cpp                \
        src/ThreadException.cpp     \
        src/ThreadPool.cpp          \
        src/Worker.cpp              \








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
