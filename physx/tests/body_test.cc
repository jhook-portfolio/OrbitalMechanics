#include <gtest/gtest.h>
#include "../src/Body.h"

TEST(BodyTest, DefaultInitialization) {
    Body b;

    EXPECT_DOUBLE_EQ(b.mass, 0);
    EXPECT_DOUBLE_EQ(b.x, 0);
    EXPECT_DOUBLE_EQ(b.y, 0);
    EXPECT_DOUBLE_EQ(b.vx, 0);
    EXPECT_DOUBLE_EQ(b.vy, 0);
}

TEST(BodyTest, CustomInitialization) {
    Body b(1.0,2.1,3.2,4.3,5.4);

    EXPECT_DOUBLE_EQ(b.mass, 1.0);
    EXPECT_DOUBLE_EQ(b.x, 2.1);
    EXPECT_DOUBLE_EQ(b.y, 3.2);
    EXPECT_DOUBLE_EQ(b.vx, 4.3);
    EXPECT_DOUBLE_EQ(b.vy, 5.4);
}

TEST(BodyTest, AttributeModification) {
    Body b(1,2,3,4,5);

    b.mass = b.mass * 2;
    b.x = b.x * 2;
    b.y = b.y * 2;
    b.vx = b.vx * 2;
    b.vy = b.vy * 2;

    EXPECT_DOUBLE_EQ(b.mass, 2);
    EXPECT_DOUBLE_EQ(b.x, 4);
    EXPECT_DOUBLE_EQ(b.y, 6);
    EXPECT_DOUBLE_EQ(b.vx, 8);
    EXPECT_DOUBLE_EQ(b.vy, 10);
}