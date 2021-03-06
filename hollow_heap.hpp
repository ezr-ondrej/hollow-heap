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
    TNode * second_parent;
    TNode * next;
    TNode * child;
    int rank;
    K key;
    T item;
    bool hollow;
  };

public:
  /**
   * @brief      Creates a new Hollow Heap structure
   */
  CHollowHeap();


  ~CHollowHeap();

  /**
   * @brief      Find minimum in heap
   *
   * @return     Returns an value with a minimum key
   */
  T * FindMin();

  /**
   * @brief      Insert key / item pair into the heap
   *
   * @param[in]  key    The key
   * @param[in]  item  The item
   */
  void Insert( const K & key, const T & item );


  /**
   * @brief      DeleteMin
   *
   * Deletes a minimum from a heap
   *
   * @return     returns deleted value
   */
  T DeleteMin();

  /**
   * @brief      Melds two heaps into one.
   *
   * @param      other  heap with same types to meld from.
   *
   * @return     returns self
   */
  CHollowHeap & Meld( CHollowHeap & other );


  /**
   * @brief      DecreaseKey of given node
   *
   * @param      to_decrease  node, witch key shold be decreased
   * @param[in]  key          to decrease to
   */
  void DecreaseKey( CHollowHeap<K,T>::TNode * to_decrease, const K & key );

  /**
   * @brief      Delete a given node from a Heap
   *
   * @param      to_delete  node to delete
   *
   * @return     self
   */
  CHollowHeap & Delete( TNode * to_delete );


protected:
  CHollowHeap & Meld( TNode * other );

private:

  TNode * makeNode( const K & key, const T & item );

  TNode * link( TNode * first, TNode * second);

  void addChild( TNode * child, TNode * parent );

  void delete_node( TNode * to_delete );

private:
  TNode * m_root;
  int m_count;
};

#include "hollow_heap.cpp"

#endif //___HOLLOW_HEAP__EZRONDRE__AEF596DS___
