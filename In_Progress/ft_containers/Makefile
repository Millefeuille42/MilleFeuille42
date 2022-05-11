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

NAME	=	ft_containers
TEST_NAME = ft_containers_test
SOURCES_EXTENSION = cpp
LIB_EXTENSION	= a

######### Compilation #########

COMPILE		=	c++
LIB			=	ar rc
DELETE		=	rm -f

FLAGS		=	-Wall -Werror -Wextra --pedantic --std=c++98

######### Additional Paths #########

vpath	%.h $(HEADERS_DIRECTORIES)

# ################################### #
#        DO NOT ALTER FURTHER!        #
# ################################### #

#########  Rules  #########

all		: $(TEST_NAME)

$(NAME) :
			$(LIB) lib$(NAME).$(LIB_EXTENSION) $(HEADERS)
			ranlib lib$(NAME).$(LIB_EXTENSION)

$(TEST_NAME): $(NAME) $(SOURCES)
			$(COMPILE) $(FLAGS) -L./ -l$(NAME) $(SOURCES) -o $@

clean	:

fclean	:	clean clean_bin

re		:	fclean
			@make --no-print-directory all

#########  Sub Rules  #########

objs	:	$(OBJS_DIR) $(OBJS)

clean_bin:
			$(DELETE) $(NAME)

.PHONY	:	all clean fclean re

#########  Includes  #########

-include $(DEPS)