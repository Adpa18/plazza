SUBDIRS	=	Thread	\
			IPC

all:
	@echo -e "\033[32m=> Compiling Lib\033[00m"
	@for dir in $(SUBDIRS); do \
		echo -e "\t\033[32mCompiling $$dir\033[00m"; \
		make -C $$dir; \
	done

clean:
	@echo -e "\033[35m=> Removing Lib Objects\033[00m"
	@for dir in $(SUBDIRS); do \
		echo -e "\t\033[31mRemoving Objects from $$dir\033[0m"; \
		make -C $$dir clean; \
	done

fclean:
	@echo -e "\033[35m=> Removing Lib\033[00m"
	@for dir in $(SUBDIRS); do \
		echo -e "\t\033[31mRemoving $$dir\033[0m"; \
		make -C $$dir fclean; \
	done

re: fclean all

.PHONY: all clean fclean re
