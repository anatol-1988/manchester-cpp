ENABLE_TESTING()
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(Qt5Test REQUIRED)

ADD_DEFINITIONS(
    -std=c++11
)

SET(MAN_LIBS man-decoder-lib man-encoder-lib)
INCLUDE_DIRECTORIES("../include")

SET(ENCODER_TEST_SRC test-encoder.cpp)
ADD_EXECUTABLE(test-encoder ${ENCODER_TEST_SRC})
QT5_USE_MODULES(test-encoder Test)
TARGET_LINK_LIBRARIES(test-encoder ${MAN_LIBS})
ADD_TEST(NAME test-encoder COMMAND test-encoder)

SET(DECODER_TEST_SRC test-decoder.cpp)
ADD_EXECUTABLE(test-decoder ${DECODER_TEST_SRC})
QT5_USE_MODULES(test-decoder Test)
TARGET_LINK_LIBRARIES(test-decoder ${MAN_LIBS})
ADD_TEST(NAME test-decoder COMMAND test-decoder)
