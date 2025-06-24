#include <gmock/gmock.h>

class MockTurtle : public Turtle {
 public:
    MOCK_METHOD(void, PenUp, (), (override));
    MOCK_METHOD(void, PenDown, (), (override));
    MOCK_METHOD(void, Forward, (int distance), (override));
    MOCK_METHOD(void, Turn, (int degrees), (override));
    MOCK_METHOD(void, GoTo, (int x, int y), (override));
    MOCK_METHOD(int, GetX, (), (const, override));
    MOCK_METHOD(int, GetY, (), (const, override));
};

MockTurtle* mMockTurtle;

Turtle::Turtle() {
}

Turtle::~Turtle() {
}

void Turtle::PenUp() {      // For non-return function, we can left its definition empty
    mMockTurtle->PenUp();   // This also mean:
                            //    1. Our call to EXPECT_CALL and ON_CALL for this func is USELESS
                            //    2. We never get "Uninteresting mock function call" warning for this func
}

void Turtle::PenDown() {
    mMockTurtle->PenDown();
}

void Turtle::Forward(int distance) {
    mMockTurtle->Forward(distance);
}

void Turtle::Turn(int degrees) {
    mMockTurtle->Turn(degrees);
}

void Turtle::GoTo(int x, int y) {
    mMockTurtle->GoTo(x, y);
}

int Turtle::GetX() const {
    return mMockTurtle->GetX();
}

int Turtle::GetY() const {
    return mMockTurtle->GetY();
}
