set(    SOURCE_PHILO_ONE

		../../In_Progress/Philosophers/philo_one/main.c

		../../In_Progress/Philosophers/philo_one/utils/ft_atoi.c
		../../In_Progress/Philosophers/philo_one/utils/ft_milli_sleep.c
		../../In_Progress/Philosophers/philo_one/utils/a_malloc.c
		../../In_Progress/Philosophers/philo_one/utils/get_time_since.c
		../../In_Progress/Philosophers/philo_one/utils/time_to_milli.c

		../../In_Progress/Philosophers/philo_one/forks/forks.c
		../../In_Progress/Philosophers/philo_one/philos/philos.c
		../../In_Progress/Philosophers/philo_one/philos/philos_utils.c

		../../In_Progress/Philosophers/philo_one/philo_one.h
		../../In_Progress/Philosophers/philo_one/philos/philos_func.c)

add_executable(philo_one ${SOURCE_PHILO_ONE})
target_link_libraries(philo_one LINK_PUBLIC libpthread.so)
#set_target_properties (philosophers PROPERTIES COMPILE_FLAGS "-L /usr/lib/ -lbsd -lc -lpthread -I ./includes/")
