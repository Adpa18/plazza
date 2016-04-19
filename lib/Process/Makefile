CC 			= 	g++

RM			=	rm -rf

NAME 		= 	../libProcess.a

CPPFLAGS	=	-std=c++11 -O2 -Wall -Wextra -Werror

CPPFLAGS	+= 	-I./inc

SRC_DIR		=	src/

SRC			=	$(SRC_DIR)Process.cpp			\
				$(SRC_DIR)ProcessException.cpp	\

OBJS		=	$(SRC:%cpp=%o)

%.o : %.cpp
	@echo -e "Compiling $<"
	@$(CC) -c $(CPPFLAGS) $< -o $@

$(NAME)		:	$(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo -e "\033[33mlibProcess Compiled\033[00m"

all			:	$(NAME)

clean		:
	$(RM) $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all

.PHONY		: all clean fclean re
