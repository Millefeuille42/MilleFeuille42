cmake_minimum_required(VERSION 3.17)
project(philosophers C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

add_executable(f_philo_one philo/philo_one
        philo/philo_one/main.c philo/philo_one/args.c philo/philo_one/philo_one.h philo/philo_one/init_app.c philo/philo_one/philo_setup.c philo/philo_one/philo.c philo/philo_one/philo_actions.c philo/philo_one/philo_take_fork.c philo/philo_one/philo_utils.c philo/philo_one/timeval_to_ms.c philo/philo_one/ft_atoi.c)
target_link_libraries(f_philo_one LINK_PUBLIC libpthread.so)

add_executable(f_philo_two philo/philo_two philo/philo_two/main.c philo/philo_two/args.c philo/philo_two/philo_two.h philo/philo_two/init_app.c philo/philo_two/philo_setup.c philo/philo_two/philo.c philo/philo_two/philo_actions.c philo/philo_two/philo_take_fork.c philo/philo_two/philo_utils.c philo/philo_two/timeval_to_ms.c philo/philo_two/ft_atoi.c)
target_link_libraries(f_philo_two LINK_PUBLIC libpthread.so)

add_executable(f_philo_three philo/philo_three philo/philo_three/main.c philo/philo_three/args.c philo/philo_three/philo_three.h philo/philo_three/init_app.c philo/philo_three/philo_setup.c philo/philo_three/philo.c philo/philo_three/philo_actions.c philo/philo_three/philo_take_fork.c philo/philo_three/philo_utils.c philo/philo_three/timeval_to_ms.c philo/philo_three/ft_atoi.c)
target_link_libraries(f_philo_three LINK_PUBLIC libpthread.so)