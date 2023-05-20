#ifndef S4_ROTATABLE_BINARY_SEARCH_TREE_HPP
#define S4_ROTATABLE_BINARY_SEARCH_TREE_HPP
#include "unbalanced-binary-search-tree.hpp"

namespace chemodurov
{
  template< typename T, typename Compare >
  class RotatableBinarySearchTree
  {
   public:
    using value_type = T;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;
    using value_compare = Compare;
    using reference = value_type &;
    using const_reference = const value_type &;
    using iterator = typename UnbalancedBinarySearchTree< value_type, value_compare >::iterator;
    using const_iterator = typename UnbalancedBinarySearchTree< value_type, value_compare >::const_iterator;
    using this_t = RotatableBinarySearchTree< value_type, value_compare >;
    RotatableBinarySearchTree();
    RotatableBinarySearchTree(const this_t & other);
    RotatableBinarySearchTree(this_t && other);
    explicit RotatableBinarySearchTree(const value_compare & comp);
    template< typename InputIt >
    RotatableBinarySearchTree(InputIt first, InputIt last, const value_compare & comp = value_compare());
    RotatableBinarySearchTree(std::initializer_list< value_type > init, const value_compare & comp = value_compare());
    ~RotatableBinarySearchTree();
    this_t & operator=(const this_t & other);
    this_t & operator=(this_t && other);
    this_t & operator=(std::initializer_list< value_type > init);
    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;
    bool empty() const noexcept;
    size_t size() const noexcept;
    void clear() noexcept;
    std::pair< iterator, bool > insert(const_reference value);
    template< typename P >
    std::pair< iterator, bool > insert(P && value);
    iterator insert(const_iterator pos, const_reference value);
    template< typename P >
    iterator insert(const_iterator pos, P && value);
    template< typename InputIt >
    void insert(InputIt first, InputIt last);
    void insert(std::initializer_list< value_type > init);
    template< typename... Args >
    std::pair< iterator, bool > emplace(Args && ... args);
    template< typename... Args >
    iterator emplace_hint(const_iterator hint, Args && ... args);
    reference at(const_reference value);
    const_reference at(const_reference value) const;
    reference operator[](const_reference value);
    reference operator[](value_type && value);
    iterator erase(iterator pos);
    iterator erase(const_iterator pos);
    iterator erase(const_iterator first, const_iterator last);
    size_type erase(const_reference value);
    void swap(this_t & other);
    size_type count(const_reference value) const;
    iterator find(const_reference value);
    const_iterator find(const_reference value) const;
    std::pair< iterator, iterator > equal_range(const_reference value);
    std::pair< const_iterator, const_iterator > equal_range(const_reference value) const;
    iterator lower_bound(const_reference value);
    const_iterator lower_bound(const_reference value) const;
    iterator upper_bound(const_reference value);
    const_iterator upper_bound(const_reference value) const;
    value_compare value_comp() const;
   private:
    UnbalancedBinarySearchTree< T, Compare > data;
  };
}

#endif
