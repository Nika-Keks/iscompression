set(ISCOMP_NAME iscomp)

add_executable(${ISCOMP_NAME}
    main.cpp)

target_link_libraries(${ISCOMP_NAME} FLAC++) # TODO: add libarchive

