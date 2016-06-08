#include "gtest/gtest.h"
#include <string>

#define private public
#define protected public
#include "../hollow_heap.hpp"


namespace {

// The fixture for testing class Foo.
class CHollowHeapTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  CHollowHeapTest() {
    // You can do set-up work for each test here.
  }

  virtual ~CHollowHeapTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for HollowHeap.
  CHollowHeap<int, std::string> mainheap;
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(CHollowHeapTest, MethodInsertWorks) {
  mainheap.Insert( 3, "ahoj jsem sasek" );
  EXPECT_EQ(3, mainheap.m_root->key);
  EXPECT_EQ("ahoj jsem sasek", mainheap.m_root->item);
}

// Tests that Foo does Xyz.
TEST_F(CHollowHeapTest, DoesXyz) {
  // Exercises the Xyz feature of Foo.
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
