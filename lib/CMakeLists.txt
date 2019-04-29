message("-- Linking glfw")
add_library(glfw glfw3.dll)
set_target_properties(glfw PROPERTIES LINKER_LANGUAGE C)
