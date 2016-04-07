SRC_DIR		=	src/

SRC			=	$(SRC_DIR)main.cpp			\
				$(SRC_DIR)CondVar.cpp		\
				$(SRC_DIR)Plazza.cpp		\
				$(SRC_DIR)InternetSocket.cpp\
				$(SRC_DIR)Mutex.cpp			\
				$(SRC_DIR)NamedPipe.cpp		\
				$(SRC_DIR)Process.cpp		\
				$(SRC_DIR)Thread.cpp		\
				$(SRC_DIR)UnixSocket.cpp	\

CC			=	g++

RM			=	rm -rf

NAME		=	plazza

CPPFLAGS	=	-W -Wall -Wextra -Werror -fPIC

CPPFLAGS	+=	-I./inc/

CPPFLAGS	+=	-std=c++11

OBJ			=	$(SRC:%cpp=%o)

%.o : %.cpp
	@echo -e "Compiling $<"
	@$(CC) -c $(CPPFLAGS) $< -o $@

$(NAME)	:	$(OBJ)
	@$(CC) $(OBJ) -o $(NAME) $(LFLAGS)
	@echo -e "\033[33mPlazza Compiled\033[00m"

all		:	$(NAME)

clean	:
	@echo -e "\033[31mRemoving Objects\033[00m"
	@$(RM) $(OBJ)

fclean	:	clean
	@echo -e "\033[31mRemoving ${NAME}\033[00m"
	@$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
