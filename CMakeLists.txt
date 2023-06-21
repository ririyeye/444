cmake_minimum_required(VERSION 3.20)

project(ops)

add_library(ppp SHARED ppp.c)

install(TARGETS ppp 
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION bin
)

#add swig python
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

find_package(PythonLibs)

swig_add_library(ppp_py
LANGUAGE python
SOURCES ppp.i
OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/python
#  OUTFILE_DIR ${PROJECT_SOURCE_DIR}/outfile
)

target_include_directories(ppp_py PRIVATE ${PYTHON_INCLUDE_PATH})
target_include_directories(ppp_py PRIVATE ./)
swig_link_libraries(ppp_py ${PYTHON_LIBRARIES} ppp)

# origin dll
install(TARGETS ppp 
        RUNTIME DESTINATION python
)

# wrap.pyd
install(TARGETS ppp_py 
        DESTINATION python
)

# test code
install(FILES test.py 
        DESTINATION python
)

# wrap.py
install(
    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/python
    DESTINATION .
    FILES_MATCHING 
    PATTERN "*.py"
)