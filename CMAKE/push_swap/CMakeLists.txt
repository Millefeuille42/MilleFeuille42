set(    SOURCE_COMMONS

        ../../In_Progress/push_swap/commons/utils/ft_atoi.c
        ../../In_Progress/push_swap/commons/utils/ft_strncmp.c
        ../../In_Progress/push_swap/commons/utils/ft_isdigit.c
        ../../In_Progress/push_swap/commons/utils/ft_is_string_digit.c

        ../../In_Progress/push_swap/commons/gnl/gnl.c
        ../../In_Progress/push_swap/commons/gnl/gnl_utils.c

        ../../In_Progress/push_swap/commons/stack/stack.c
        ../../In_Progress/push_swap/commons/stack/swap.c
        ../../In_Progress/push_swap/commons/stack/push.c
        ../../In_Progress/push_swap/commons/stack/rotate.c
        ../../In_Progress/push_swap/commons/stack/reverse_rotate.c

        ../../In_Progress/push_swap/commons/utils/safe_free.c
        ../../In_Progress/push_swap/commons/stack/actions.c
        ../../In_Progress/push_swap/commons/utils/print_error.c

        ../../In_Progress/push_swap/commons/includes/commons.h
        )

set(    SOURCE_CHECKER
        ../../In_Progress/push_swap/f_checker/main.c
        )

set(    SOURCE_PUSH_SWAP
        ../../In_Progress/push_swap/f_push_swap/main.c
        ../../In_Progress/push_swap/f_push_swap/sort_utils.c ../../In_Progress/push_swap/f_push_swap/selection_sort.c ../../In_Progress/push_swap/f_push_swap/push_swap.h ../../In_Progress/push_swap/f_push_swap/insertion_sort.c ../../In_Progress/push_swap/f_push_swap/insertion_sort_get_actions.c)

add_executable(push_swap ${SOURCE_COMMONS} ${SOURCE_PUSH_SWAP})
add_executable(checker ${SOURCE_COMMONS} ${SOURCE_CHECKER})