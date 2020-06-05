#ifndef TST_TESTDIVISIONBYZERO_H
#define TST_TESTDIVISIONBYZERO_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <../Lab9_Project_for_tests/lockcontroller.h>
#include "_test.cc"

using namespace testing;
using ::testing::AtLeast;

//TEST(Calculator, Test1)
//{
//    MockIKeypad keypad;
//    EXPECT_CALL(keypad, wait()).Times(AtLeast(1));
//    MockILatch latch;
//    LockController door (&keypad, &latch);
//    door.wait();
//}

//TEST(Calculator, Test2)
//{
//    MockIKeypad keypad;
//    MockILatch latch;
//    LockController door (&keypad, &latch);
//    EXPECT_CALL(latch, getDoorStatus()).Times(AtLeast(1)).WillRepeatedly(Return(DoorStatus::CLOSE));
//    ASSERT_FALSE(door.isDoorOpen());
//}

//TEST(Calculator, Test3)
//{
//    MockIKeypad keypad;
//    MockILatch latch;
//    LockController door (&keypad, &latch);
//    door.unlockDoor();
//    EXPECT_CALL(latch, getDoorStatus()).Times(AtLeast(1));
//    ASSERT_TRUE(door.isDoorOpen());
//}

//TEST(Calculator, Test4)
//{
//    MockIKeypad keypad;
//    MockILatch latch;
//    LockController door (&keypad, &latch);
//    EXPECT_CALL(latch, open()).Times(AtLeast(1));
//    ASSERT_EQ(door.unlockDoor(), DoorStatus::OPEN);
//}

//TEST(Calculator, Test5)
//{
//    MockIKeypad keypad;
//    MockILatch latch;
//    LockController door (&keypad, &latch);
//    EXPECT_CALL(latch, close()).Times(AtLeast(1)).WillRepeatedly(Return(DoorStatus::CLOSE));
//    ASSERT_EQ(door.lockDoor(), DoorStatus::CLOSE);
//}

//TEST(Calculator, Test6)
//{
//    MockIKeypad keypad;
//    MockILatch latch;
//    LockController door (&keypad, &latch);
//    EXPECT_CALL(keypad, isActive()).Times(AtLeast(1)).WillRepeatedly(Return(true));
//    EXPECT_CALL(latch, isActive()).Times(AtLeast(1)).WillRepeatedly(Return(true));
//    ASSERT_EQ(door.hardWareCheck(), HardWareStatus::OK);
//}

//TEST(Calculator, Test7)
//{
//    MockILatch latch;
//    MockIKeypad keypad;
//    LockController door (nullptr, &latch);
//    EXPECT_CALL(keypad, isActive()).Times(AnyNumber());
//    EXPECT_CALL(latch, isActive()).Times(AnyNumber()).WillRepeatedly(Return(true));
//    ASSERT_EQ(door.hardWareCheck(), HardWareStatus::ERROR);
//}

//TEST(Calculator, Test8)
//{
//    MockIKeypad keypad;
//    MockILatch latch;
//    LockController door (&keypad, &latch);
//    EXPECT_CALL(keypad, isActive()).Times(AtLeast(1)).WillRepeatedly(Return(true));
//    EXPECT_CALL(latch, isActive()).Times(AtLeast(1)).WillRepeatedly(Return(false));
//    ASSERT_EQ(door.hardWareCheck(), HardWareStatus::ERROR);
//}

//TEST(Calculator, Test9)
//{
//    MockIKeypad keypad;
//    MockILatch latch;
//    LockController door (&keypad, &latch);
//    EXPECT_CALL(keypad, requestPassword()).Times(AtLeast(1)).WillRepeatedly(Return(PasswordResponse{PasswordResponse::Status::OK, "0000"}));
//    ASSERT_TRUE(door.isCorrectPassword());
//}

//TEST(Calculator, Test10)
//{
//    MockIKeypad keypad;
//    MockILatch latch;
//    LockController door (&keypad, &latch);
//    EXPECT_CALL(keypad, requestPassword()).Times(AtLeast(1)).WillRepeatedly(Return(PasswordResponse{PasswordResponse::Status::OK, "1337"}));
//    ASSERT_FALSE(door.isCorrectPassword());
//}

//TEST(Calculator, Test11)
//{
//    MockIKeypad keypad;
//    MockILatch latch;
//    LockController door (&keypad, &latch);
//    EXPECT_CALL(keypad, requestPassword()).Times(AtLeast(3))
//            .WillOnce(Return(PasswordResponse{PasswordResponse::Status::OK, "0000"}))
//            .WillRepeatedly(Return(PasswordResponse{PasswordResponse::Status::OK, "1337"}));
//    door.resetPassword();
//    ASSERT_TRUE(door.isCorrectPassword());
//}

//TEST(Calculator, Test12)
//{
//    MockIKeypad keypad;
//    MockILatch latch;
//    LockController door (&keypad, &latch);
//    EXPECT_CALL(keypad, requestPassword()).Times(AtLeast(3))
//            .WillOnce(Return(PasswordResponse{PasswordResponse::Status::OK, "0000"}))
//            .WillOnce(Return(PasswordResponse{PasswordResponse::Status::OK, "9876"}))
//            .WillOnce(Return(PasswordResponse{PasswordResponse::Status::OK, "9876"}))
//            .WillRepeatedly(Return(PasswordResponse{PasswordResponse::Status::OK, "1337"}));
//    door.resetPassword();  // меняем на 9876
//    door.resetPassword();  // пользлватель вводит пароль
//    ASSERT_TRUE(door.isCorrectPassword());  // сравниваемся
//}

#endif // TST_TESTDIVISIONBYZERO_H
