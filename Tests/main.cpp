#include "tst_test1.h"
#include "GreeterTests.h"
#include "ShiTests.h"
#include "MaTests.h"
#include "XiangTests.h"
#include "ChessBoardTests.h"
#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
