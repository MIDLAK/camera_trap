# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(CameraTrap.out)

# Стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Поиск OpenCV
find_package(OpenCV REQUIRED)

# Заголовки находятся в директории headers
include_directories(${PROJECT_SOURCE_DIR}/headers)

# Исполняемые файлы
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(CameraTrap.out ${SOURCES})

# Связь OpenCV библиотеки с проектом
target_link_libraries(CameraTrap.out ${OpenCV_LIBS})

# Пути к заголовкам OpenCV
target_include_directories(CameraTrap.out PRIVATE ${OpenCV_INCLUDE_DIRS})
