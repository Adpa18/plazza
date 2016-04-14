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

CPPFLAGS= -std=c++11 -g -O2 -I ./inc -Wall -Wextra -Werror

LDFLAGS= -lpthread

CC= g++

%.o : %.cpp
	@echo -e "Compiling $<"
	@$(CC) -c $(CPPFLAGS) $< -o $@

$(NAME):    $(OBJS)
	@ar  rcs $(NAME) $(OBJS)
	@echo -e "\033[33mlibthread Compiled\033[00m"

all:    $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
