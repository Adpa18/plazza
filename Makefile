SRC_DIR		=	src/

SRC			=	$(SRC_DIR)main.cpp			\
                $(SRC_DIR)Plazza.cpp    	\
                $(SRC_DIR)Manager.cpp    	\
                $(SRC_DIR)Parser.cpp    	\
				$(SRC_DIR)Decrypt.cpp    	\

CC			=	g++

RM			=	rm -rf

NAME		=	plazza

CPPFLAGS	=	-W -Wall -Wextra -Werror -g

CPPFLAGS	+=	-I./inc/ -I./lib/IPC/inc -I./lib/Thread/inc -I./lib/Process/inc

CPPFLAGS	+=	-std=c++11

LDFLAGS		= 	-L./lib/ -lIPC -lthread -lProcess

LDFLAGS		+= 	-lpthread -pthread

OBJ			=	$(SRC:%cpp=%o)

%.o : %.cpp
	@echo -e "Compiling $<"
	@$(CC) -c $(CPPFLAGS) $< -o $@

$(NAME)	:	$(OBJ)
	@make --no-print-directory -C lib;
	@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo -e "\033[33mPlazza Compiled\033[00m"

all		:	$(NAME)

clean	:
	@echo -e "\033[31mRemoving Objects\033[00m"
	@$(RM) $(OBJ)
	@make clean -s -C lib

fclean	:	clean
	@echo -e "\033[31mRemoving ${NAME}\033[00m"
	@$(RM) $(NAME)
	@make fclean -s -C lib

re		: fclean all

.PHONY	: all clean fclean re
