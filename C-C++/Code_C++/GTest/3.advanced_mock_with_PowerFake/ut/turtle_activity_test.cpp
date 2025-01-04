#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Include code-under-test here
#include "turtle_activity.cpp"

// Include mock code here
#include "mock_turtle.h"

using ::testing::_;
using ::testing::Return;

class TurtleActivityChild : public TurtleActivity {
 public:
    bool IsOutside() override;
};

class MockTurtleActivity : public TurtleActivityChild {
 public:
    MOCK_METHOD(bool, IsOutside, ());
};
MockTurtleActivity mMockTurtleActivity;

bool TurtleActivityChild::IsOutside() {
    std::cout << "TurtleActivityChild::IsOutside" << std::endl;
    return mMockTurtleActivity.IsOutside();
}

class TurtleActivityTest : public testing::Test {
 protected:
    TurtleActivity* testObj;

    TurtleActivityTest() {
    }

    ~TurtleActivityTest() override {
    }

    void SetUp() override {
        std::cout << "SetUp" << std::endl;
        testObj = new TurtleActivity();
        mMockTurtle = new MockTurtle();
    }

    void TearDown() override {
        std::cout << "TearDown" << std::endl;
        delete mMockTurtle;
        delete testObj;
    }
};

// PASS - no warning
TEST_F(TurtleActivityTest, Hide_001) {
    EXPECT_CALL(*mMockTurtle, PenDown()).Times(1);
    EXPECT_CALL(*mMockTurtle, Forward(_)).Times(2);
    EXPECT_CALL(*mMockTurtle, Turn(_)).Times(1);

    TurtleActivity turtleActivity;
    EXPECT_NO_THROW(turtleActivity.Hide());
}

// PASS - but contain "Uninteresting mock function call" warning
TEST_F(TurtleActivityTest, Hide_002) {
    EXPECT_CALL(*mMockTurtle, PenDown()).Times(1);
    EXPECT_CALL(*mMockTurtle, Forward(_)).Times(2);
    // EXPECT_CALL(*mMockTurtle, Turn(_)).Times(1);     // Comment this line to generate "Uninteresting mock function call" warning

    TurtleActivity turtleActivity;
    EXPECT_NO_THROW(turtleActivity.Hide());
}

// PASS - use member test object - no warning
TEST_F(TurtleActivityTest, IsOutside_001) {
    EXPECT_CALL(*mMockTurtle, GetX()).WillOnce(Return(1));
    EXPECT_TRUE(testObj->IsOutside());
}

// PASS - use member test object - but contain "Uninteresting mock function call" warning
TEST_F(TurtleActivityTest, IsOutside_002) {
    ON_CALL(*mMockTurtle, GetX()).With(_).WillByDefault(Return(1));
    EXPECT_TRUE(testObj->IsOutside());
}

// FAIL - use member test object
TEST_F(TurtleActivityTest, IsOutside_003) {
    EXPECT_CALL(*mMockTurtle, GetX()).WillOnce(Return(0));
    EXPECT_TRUE(testObj->IsOutside());
}

TEST_F(TurtleActivityTest, IsInside_001) {
    MockTurtleActivity mockTurtleActivity;
    EXPECT_CALL(mockTurtleActivity, IsOutside()).WillOnce(Return(true));

    TurtleActivityChild testObj;
    EXPECT_FALSE(testObj.IsInside());
}
