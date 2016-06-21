#include "hollow_heap.hpp"

#include <iostream>


template<typename K, typename T>
CHollowHeap<K,T>::CHollowHeap()
: m_root( NULL ), m_count(0)
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
  m_count++;
}


template<typename K, typename T>
T CHollowHeap<K,T>::DeleteMin()
{
  T result = m_root->item;
  Delete( m_root );
  return result;
}


template<typename K, typename T>
CHollowHeap<K,T> & CHollowHeap<K,T>::Meld( CHollowHeap<K,T> & other )
{
  TNode * other_root = other.m_root;
  other.m_root = NULL;
  return Meld( other_root );
}


template<typename K, typename T>
void CHollowHeap<K,T>::DecreaseKey( const K & key, const T & item )
{

}


template<typename K, typename T>
CHollowHeap<K,T> & CHollowHeap<K,T>::Delete( CHollowHeap<K,T>::TNode * to_delete )
{
  delete_node(to_delete);
  m_count--;
  return *this;
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

//------------------------ PRIVATE METHODS ------------------------

template<typename K, typename T>
typename CHollowHeap<K,T>::TNode * CHollowHeap<K,T>::makeNode( const K & key, const T & item )
{
  TNode * node = new TNode;
  node->key = key;
  node->item = item;
  node->child = NULL;
  node->next = NULL;
  node->second_parent = NULL;
  node->rank = 0;
  node->hollow = false;
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

template<typename K, typename T>
void CHollowHeap<K,T>::delete_node( CHollowHeap<K,T>::TNode * node )
{
  node->second_parent = NULL;
  node->hollow = true;
  if( node != m_root )
    return;
  int max_rank = 0;
  m_root->next = NULL;
  TNode ** A = new TNode*[m_count];
  for (int i = 0; i < m_count; ++i)
  {
    A[i] = NULL;
  }

  while( m_root ) {
    TNode * current = m_root->child;
    TNode * parent = m_root;
    TNode * previous;
    m_root = m_root->next;

    while( current ) {
      previous = current;
      current = current->next;
      if( previous->hollow ) {
        if( ! previous->second_parent ) {
          previous->next = m_root;
          m_root = previous;
        } else {
          if( previous->second_parent == parent )
            current = NULL;
          else
            previous->next = NULL;
          previous->second_parent = NULL;
        }
      } else {
        while( A[previous->rank] ) {
          previous = link( previous, A[previous->rank] );
          A[previous->rank++] = NULL;
        }
        A[previous->rank] = previous;
        if( previous->rank > max_rank) {
          max_rank = previous->rank;
        }
      }
    }
    delete parent;
  }
  for (int i = 0; i <= max_rank; ++i)
  {
    if( A[i] ) {
      if( !m_root )
        m_root = A[i];
      else
        m_root = link( m_root, A[i] );
      A[i] = NULL;
    }
  }
}
