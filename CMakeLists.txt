

add_library(aes128 STATIC aes128.c)
target_include_directories(aes128 PUBLIC .)
target_compile_options(aes128 PUBLIC -Wall)

add_executable(aes_test main.c)
target_link_libraries(aes_test PUBLIC aes128)

