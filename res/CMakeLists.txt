file (GLOB assets "*")
file (COPY ${assets} DESTINATION ${CMAKE_BINARY_DIR}/res)
