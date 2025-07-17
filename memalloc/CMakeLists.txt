set(TARGET_NAME memalloc)
set(INCL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_library(${TARGET_NAME} STATIC "${INCL_DIR}/*.h" "${SRC_DIR}/*.cpp")

target_include_directories(${TARGET_NAME} PRIVATE ${INCL_DIR})
