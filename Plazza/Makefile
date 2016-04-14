SUBDIRS= $(shell find -mindepth 1 -maxdepth 1 -type d)

all:
	@for dir in $(SUBDIRS); do \
		make -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		make -C $$dir clean; \
	done

fclean:
	@for dir in $(SUBDIRS); do \
		make -C $$dir fclean; \
	done

re: fclean all

.PHONY: all clean fclean re