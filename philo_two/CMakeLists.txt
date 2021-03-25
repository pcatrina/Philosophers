cmake_minimum_required(VERSION 3.17)
project(philo_two C)

set(CMAKE_C_STANDARD 99)

add_executable(philo_one main.c philo_two.h ph_read_instructions.c ph_error.c ph_utils.c ph_init.c ph_destroy.c ph_treads.c ph_life.c ph_monitor.c ph_status.c ph_status_write.c ph_itoa.c ph_putstr_buf.c ph_open_sem.c ph_open_main_sem.c)