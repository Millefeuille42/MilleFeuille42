######### Sources #########

SOURCES	=				main.cpp

HEADERS	=				vector.hpp \
						stack.hpp \
						map.hpp \
						includes/libs/algorithm.hpp \
                        includes/libs/stddef.hpp \
                        includes/libs/exceptions.hpp \
                        includes/libs/type_traits.hpp \
                        includes/libs/functional.hpp \
                        includes/libs/utility.hpp \
                        includes/iterators/iterator_traits.hpp \
                        includes/iterators/iterator.hpp \
                        includes/iterators/normal_iterators.hpp \
                        includes/iterators/reverse_iterator.hpp \
                        includes/utils/vector_iterator.hpp \
                        includes/utils/map_iterator.hpp \
                        includes/utils/Node.hpp \
                        includes/utils/Tree.hpp

HEADERS_DIRECTORIES	=	includes/iterators/ includes/libs/ includes/utils/

######### Details #########

FT_NAME		=	ft_containers
STD_NAME	=	std_containers

SOURCES_EXTENSION = cpp

######### Compilation #########

COMPILE		=	c++
DELETE		=	rm -f

FLAGS		=	-Wall -Werror -Wextra --pedantic --std=c++98

######### Additional Paths #########

vpath	%.h $(HEADERS_DIRECTORIES)

# ################################### #
#        DO NOT ALTER FURTHER!        #
# ################################### #

export SEED

ifdef SEED
DEFINE_SEED	= -D SEED=$(SEED)
endif

DEFINES		= $(DEFINE_SEED) $(DEFINE_VAL) $(DEFINE_KEY)

#########  Rules  #########

all		: $(FT_NAME) $(STD_NAME)

$(FT_NAME) : $(SOURCES)
	$(COMPILE) $(FLAGS) $(DEFINES) $^ -o $@

$(STD_NAME) : $(SOURCES)
	$(COMPILE) $(FLAGS) -D NAMESPACE=std $(DEFINES) $^ -o $@


test	:
			@make --no-print-directory $(FT_NAME)
			@make --no-print-directory $(STD_NAME)
			./$(FT_NAME) > .$(FT_NAME).log
			./$(STD_NAME) > .$(STD_NAME).log

help	:
		@echo "Syntax: make std_containers SEED=45454"
		@echo
		@echo "- make                           -> To compile both binaries at once"
		@echo "- make <namespace>_containers    -> To compile a select binary"
		@echo "- make test                      -> To run the tests"
		@echo "- make clean                     -> To delete test outputs"
		@echo "- make fclean                    -> To delete test outputs and both binaries"
		@echo "- make re                        -> fclean then all"
		@echo "- make help                      -> To print this message"
		@echo
		@echo "Flag: SEED=<15445>"
		@echo "    SEED=<15445>     -> Define a seed for the RNG"

clean	:
		$(DELETE) .$(FT_NAME).log
		$(DELETE) .$(STD_NAME).log

fclean	:	clean clean_bin

re		:	fclean
			@make --no-print-directory all

#########  Sub Rules  #########

clean_bin:
			$(DELETE) $(FT_NAME) $(STD_NAME)

.PHONY	:	all clean fclean re help test
