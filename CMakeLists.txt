cmake_minimum_required(VERSION 3.10)

project(Tic-tac-toe)

set(SOME_CACHE_VALUE CACHE STRING "Hello world")

message("${GLOBE}")
message("${PROJECT_NAME}")
message("Some value here -> ${SOME_CACHE_VALUE}")

set(GLOBE
    main.cpp
    create_file.cpp
    load_size.cpp
    load_names.cpp
    save_params.cpp
    load_stats.cpp
    save_stat.cpp
    config_params.cpp
    show_stats.cpp
    display_board.cpp
    is_valid_move.cpp
    check_win.cpp
    is_board_full.cpp
    start_game.cpp
)

add_executable(${PROJECT_NAME} ${GLOBE})
