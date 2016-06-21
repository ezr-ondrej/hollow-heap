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

  void InsertDefault()
  {
    mainheap.Insert( 14, "any 14" );
    mainheap.Insert( 11, "any 11" );
    mainheap.Insert( 5, "any 5" );
    mainheap.Insert( 9, "any 9" );
    mainheap.Insert( 0, "any 0" );
    mainheap.Insert( 8, "any 8" );
    mainheap.Insert( 10, "any 10" );
    mainheap.Insert( 3, "any 3" );
    mainheap.Insert( 6, "any 6" );
    mainheap.Insert( 12, "any 12" );
    mainheap.Insert( 13, "any 13" );
    mainheap.Insert( 4, "any 4" );
  }

  CHollowHeap<int, std::string> * getSecondHeap()
  {
    CHollowHeap<int, std::string> * res = new CHollowHeap<int, std::string>;
    res->Insert( 2, "second 2" );
    res->Insert( 5, "second 5" );
    res->Insert( 6, "second 6" );
    return res;
  }

  CHollowHeap<int, std::string> * getThirdHeap()
  {
    CHollowHeap<int, std::string> * res = new CHollowHeap<int, std::string>;
    res->Insert( -1, "third -1" );
    res->Insert( 5, "third 8" );
    res->Insert( 6, "third 10" );
    return res;
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

// Tests that Insert does Insert some.
TEST_F(CHollowHeapTest, InsertSuccessive) {
  EXPECT_EQ( NULL, mainheap.m_root );
  InsertDefault();
  EXPECT_EQ( 0, mainheap.m_root->key );
  CHollowHeap<int, std::string>::TNode * node = mainheap.m_root->child;
  EXPECT_EQ( 4, node->key );
  node = node->next;
  EXPECT_EQ( 13, node->key );
  node = node->next;
  EXPECT_EQ( 12, node->key );
  node = node->next;
  EXPECT_EQ( 6, node->key );
  node = node->next;
  EXPECT_EQ( 3, node->key );
  node = node->next;
  EXPECT_EQ( 10, node->key );
  node = node->next;
  EXPECT_EQ( 8, node->key );
  node = node->next;
  EXPECT_EQ( 5, node->key );
  EXPECT_EQ( NULL, node->next );
  node = node->child;
  EXPECT_EQ( 9, node->key );
  node = node->next;
  EXPECT_EQ( 11, node->key );
  node = node->child;
  EXPECT_EQ( 14, node->key );
}

TEST_F(CHollowHeapTest, MeldWithHigherMax) {
  InsertDefault();
  CHollowHeap<int, std::string> * second = getSecondHeap();
  mainheap.Meld(*second);
  CHollowHeap<int, std::string>::TNode * node = mainheap.m_root;
  EXPECT_EQ( 0, node->key );
  node = node->child;
  CHollowHeap<int, std::string>::TNode * second_root = node;
  EXPECT_EQ( 2, node->key );
  node = node->next;
  EXPECT_EQ( 4, node->key );
  node = node->next;
  EXPECT_EQ( 13, node->key );
  node = second_root->child;
  EXPECT_EQ( 6, node->key );
  node = node->next;
  EXPECT_EQ( 5, node->key );
}

TEST_F(CHollowHeapTest, MeldWithLowerMax) {
  InsertDefault();
  CHollowHeap<int, std::string> * second = getThirdHeap();
  mainheap.Meld(*second);
  CHollowHeap<int, std::string>::TNode * node = mainheap.m_root;
  EXPECT_EQ( -1, node->key );
  node = node->child;
  CHollowHeap<int, std::string>::TNode * second_root = node;
  EXPECT_EQ( 0, node->key );
  node = node->next;
  EXPECT_EQ( 6, node->key );
  node = node->next;
  EXPECT_EQ( 5, node->key );
  node = second_root->child;
  EXPECT_EQ( 4, node->key );
  node = node->next;
  EXPECT_EQ( 13, node->key );
  node = node->next;
  EXPECT_EQ( 12, node->key );
}

TEST_F(CHollowHeapTest, DeleteMin) {
  InsertDefault();
  mainheap.DeleteMin();
  CHollowHeap<int, std::string>::TNode * node = mainheap.m_root;
  EXPECT_EQ( 3, node->key );
}

}  // namespace

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
