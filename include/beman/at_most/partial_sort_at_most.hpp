// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef BEMAN_AT_MOST_PARTIAL_SORT_AT_MOST_HPP
#define BEMAN_AT_MOST_PARTIAL_SORT_AT_MOST_HPP

#include <algorithm>
#include <iterator>
#include <ranges>

namespace beman::at_most {

template <typename RandomAccessIterator, typename Compare = std::less<>>
constexpr void partial_sort_at_most(RandomAccessIterator                                                 first,
                                    RandomAccessIterator                                                 last,
                                    typename std::iterator_traits<RandomAccessIterator>::difference_type n,
                                    Compare                                                              comp = {}) {
    if (n <= 0) {
        return;
    }
    auto dist = std::distance(first, last);
    auto k    = std::min(n, dist);
    auto mid  = std::next(first, k);
    std::ranges::partial_sort(first, mid, last, comp);
}

} // namespace beman::at_most

#endif // BEMAN_AT_MOST_PARTIAL_SORT_AT_MOST_HPP
