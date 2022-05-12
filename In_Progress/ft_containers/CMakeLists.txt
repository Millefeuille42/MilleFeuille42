add_executable( ft_containers
        main.cpp
        vector.hpp
        stack.hpp
        map.hpp

        includes/libs/algorithm.hpp
        includes/libs/stddef.hpp
        includes/libs/exceptions.hpp
        includes/libs/type_traits.hpp
        includes/libs/functional.hpp
        includes/libs/utility.hpp

        includes/iterators/iterator_traits.hpp
        includes/iterators/iterator.hpp
        includes/iterators/normal_iterators.hpp
        includes/iterators/reverse_iterator.hpp

        includes/utils/vector_iterator.hpp
        includes/utils/map_iterator.hpp
        includes/utils/Node.hpp
        includes/utils/Tree.hpp
        )