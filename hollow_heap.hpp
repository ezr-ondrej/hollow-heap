#ifndef ___HOLLOW_HEAP__EZRONDRE__AEF596DS___
#define ___HOLLOW_HEAP__EZRONDRE__AEF596DS___

#ifndef NULL
  #define NULL 0
#endif

template<typename K, typename T>
class CHollowHeap
{
public:
  struct TNode {
    TNode * next;
    TNode * child;
    int rank;
    K key;
    T item;
  };

public:
  /**
   * @brief      Creates a new Hollow Heap structure
   */
  CHollowHeap();


  ~CHollowHeap();


  T FindMin();

  /**
   * @brief      Insert key / item pair into the heap
   *
   * @param[in]  key    The key
   * @param[in]  item  The item
   */
  void Insert( const K & key, const T & item );


  T DeleteMin();


  CHollowHeap & Meld( CHollowHeap & other );


  void DecreaseKey( const K & key, const T & item );


  void Delete( const T & item );


protected:
  CHollowHeap & Meld( TNode * other );

private:

  TNode * makeNode( const K & key, const T & item );

  TNode * link( TNode * first, TNode * second);

  void addChild( TNode * child, TNode * parent );

private:
  TNode * m_root;
};

#include "hollow_heap.cpp"

#endif //___HOLLOW_HEAP__EZRONDRE__AEF596DS___
