cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

# Опция для выбора типа библиотеки
option(USE_SHARED "Build shared library instead of static" OFF)

# Выводим в консоль тип библиотеки
message(STATUS "USE_SHARED: ${USE_SHARED}")

# Все исходники библиотеки
set(SOURCES
    lib/create_file.cpp
    lib/load_size.cpp
    lib/load_names.cpp
    lib/save_params.cpp
    lib/load_stats.cpp
    lib/save_stat.cpp
    lib/config_params.cpp
    lib/show_stats.cpp
    lib/display_board.cpp
    lib/is_valid_move.cpp
    lib/check_win.cpp
    lib/is_board_full.cpp
    lib/start_game.cpp
)

# Создание библиотеки
if(USE_SHARED)
    add_library(game SHARED ${SOURCES})
else()
    add_library(game STATIC ${SOURCES})
endif()

# Подключение заголовков (предполагается, что .h тоже в lib/)
target_include_directories(game PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Главный исполняемый файл
add_executable(tictactoe main.cpp)

# Линкуем библиотеку к main.cpp
target_link_libraries(tictactoe PRIVATE game)
