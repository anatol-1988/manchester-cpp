ENABLE_TESTING()
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(Qt5Test REQUIRED)

ADD_DEFINITIONS(
    -std=c++11
)

SET(DIF_LIBS dif-decoder-lib dif-encoder-lib)
SET(MAN_LIBS man-decoder-lib man-encoder-lib)
INCLUDE_DIRECTORIES("../include")

SET(ENCODER_TEST_SRC test-dif-encoder.cpp)
ADD_EXECUTABLE(test-dif-encoder ${ENCODER_TEST_SRC})
QT5_USE_MODULES(test-dif-encoder Test)
TARGET_LINK_LIBRARIES(test-dif-encoder ${DIF_LIBS})
ADD_TEST(NAME test-dif-encoder COMMAND test-dif-encoder)

SET(DECODER_TEST_SRC test-dif-decoder.cpp)
ADD_EXECUTABLE(test-dif-decoder ${DECODER_TEST_SRC})
QT5_USE_MODULES(test-dif-decoder Test)
TARGET_LINK_LIBRARIES(test-dif-decoder ${DIF_LIBS})
ADD_TEST(NAME test-dif-decoder COMMAND test-dif-decoder)

SET(MAN_ENCODER_TEST_SRC test-man-encoder.cpp)
ADD_EXECUTABLE(test-man-encoder ${MAN_ENCODER_TEST_SRC})
QT5_USE_MODULES(test-man-encoder Test)
TARGET_LINK_LIBRARIES(test-man-encoder ${MAN_LIBS})
ADD_TEST(NAME test-man-encoder COMMAND test-man-encoder)

SET(MAN_DECODER_TEST_SRC test-man-decoder.cpp)
ADD_EXECUTABLE(test-man-decoder ${MAN_DECODER_TEST_SRC})
QT5_USE_MODULES(test-man-decoder Test)
TARGET_LINK_LIBRARIES(test-man-decoder ${MAN_LIBS})
ADD_TEST(NAME test-man-decoder COMMAND test-man-decoder)
