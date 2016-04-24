SRC_DIR		=	src/

SRC			=	$(SRC_DIR)main.cpp			\
				$(SRC_DIR)Plazza.cpp    	\
          		$(SRC_DIR)Manager.cpp    	\
          		$(SRC_DIR)Parser.cpp    	\
				$(SRC_DIR)Decrypt.cpp    	\
				$(SRC_DIR)Find.cpp    		\


SRC_UI	=		$(SRC)						\
				$(SRC_DIR)exp.cpp			\
				$(SRC_DIR)Explorer.cpp 		\
				$(SRC_DIR)Menu.cpp    		\
				$(SRC_DIR)MenuRight.cpp   	\
				$(SRC_DIR)MenuLeft.cpp   	\

CC			=	g++

RM			=	rm -rf

NAME		=	plazza

CPPFLAGS	=	-W -Wall -Wextra -Werror

CPPFLAGS	+=	-I./inc/ -I./lib/IPC/inc -I./lib/Thread/inc -I./lib/Process/inc

CPPFLAGS	+=	-I./lib/ncurses/include

CPPFLAGS	+=	-std=c++11

LDFLAGS		= 	-L./lib/ -lIPC -lthread -lProcess

LDFLAGS		+= 	-lpthread -pthread

OBJ			=	$(SRC:%cpp=%o)
OBJ_UI	=	$(SRC_UI:%cpp=%o)

%.o : %.cpp
	@echo -e "Compiling $<"
	@$(CC) -c $(CPPFLAGS) $< -o $@

ui:CPPFLAGS	+= -DPLAZZA_GUI
ui:LDFLAGS	+= -L./lib/ncurses/lib -lpanelw -lmenuw -lncursesw

$(NAME)	:	$(OBJ)
	@make --no-print-directory -C lib;
	@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo -e "\033[33mPlazza Compiled\033[00m"

ui		:	$(OBJ_UI)
	@make --no-print-directory -C lib;
	@$(CC) $(OBJ_UI) $(LDFLAGS) -o $(NAME)
	@echo -e "\033[33mPlazza Compiled\033[00m"

all		:	$(NAME)

clean	:
	@echo -e "\033[31mRemoving Objects\033[00m"
	@$(RM) $(OBJ) $(OBJ_UI)
	@make clean -s -C lib

fclean	:	clean
	@echo -e "\033[31mRemoving ${NAME}\033[00m"
	@$(RM) $(NAME)
	@make fclean -s -C lib

re		: fclean all

reui		: fclean ui

.PHONY	: all clean fclean re
