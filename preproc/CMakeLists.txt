set(TARGET_NAME preproc)

add_library(${TARGET_NAME} INTERFACE)

target_include_directories(${TARGET_NAME} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/include")
