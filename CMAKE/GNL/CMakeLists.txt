set(    SOURCE_GNL

        ../../Finished/get_next_line/get_next_line.c
		../../Finished/get_next_line/get_next_line_utils.c
        ../../Finished/get_next_line/get_next_line_bonus.c
		../../Finished/get_next_line/get_next_line_utils_bonus.c
        
        PARENT_SCOPE)

add_executable(get_next_line ${SOURCE_GNL} ../../main.c)

set_target_properties(get_next_line PROPERTIES COMPILE_FLAGS "-D BUFFER_SIZE=12")