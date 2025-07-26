set(TARGET_NAME memalloc)
set(HEADER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB_RECURSE HEADERS "${HEADER_DIR}/*.h")
file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

add_library(${TARGET_NAME} STATIC ${HEADERS} ${SOURCES})

target_include_directories(${TARGET_NAME} PRIVATE ${INCL_DIR})

target_link_libraries(${TARGET_NAME} PRIVATE preproc)
