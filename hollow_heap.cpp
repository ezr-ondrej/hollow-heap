#include "hollow_heap.hpp"


template<typename K, typename T>
CHollowHeap<K,T>::CHollowHeap()
: m_root( NULL )
{

}


template<typename K, typename T>
CHollowHeap<K,T>::~CHollowHeap()
{
  delete m_root;
}


template<typename K, typename T>
T CHollowHeap<K,T>::FindMin()
{

}


template<typename K, typename T>
void CHollowHeap<K,T>::Insert( const K & key, const T & item )
{
  Meld( makeNode(key, item) );
}


template<typename K, typename T>
T CHollowHeap<K,T>::DeleteMin()
{

}


template<typename K, typename T>
CHollowHeap<K,T> & CHollowHeap<K,T>::Meld( CHollowHeap<K,T> & other )
{
  TNode * other_root = other.m_root;
  other.m_root = NULL;
  return Meld( other_root );
}

template<typename K, typename T>
CHollowHeap<K,T> & CHollowHeap<K,T>::Meld( CHollowHeap<K,T>::TNode * other )
{
  if( !other ) { // second is empty
    return *this;
  }
  if( !m_root ) { // I am empty, second is not
    m_root = other;
  } else { // none is empty
    m_root = link(m_root, other);
  }
  return *this;
}



template<typename K, typename T>
void CHollowHeap<K,T>::DecreaseKey( const K & key, const T & item )
{

}


template<typename K, typename T>
void CHollowHeap<K,T>::Delete( const T & item )
{

}


//------------------------ PRIVATE METHODS ------------------------

template<typename K, typename T>
typename CHollowHeap<K,T>::TNode * CHollowHeap<K,T>::makeNode( const K & key, const T & item )
{
  TNode * node = new TNode;
  node->key = key;
  node->item = item;
  node->child = NULL;
  node->next = NULL;
  node->rank = 0;
  return node;
}

template<typename K, typename T>
typename CHollowHeap<K,T>::TNode * CHollowHeap<K,T>::link( CHollowHeap<K,T>::TNode * first, CHollowHeap<K,T>::TNode * second )
{
  if( first->key >= second->key ) {
    addChild( first, second );
    return second;
  } else {
    addChild( second, first );
    return first;
  }
}

template<typename K, typename T>
void CHollowHeap<K,T>::addChild( CHollowHeap<K,T>::TNode * child, CHollowHeap<K,T>::TNode * parent )
{
  child->next = parent->child;
  parent->child = child;
}
