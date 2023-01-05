# Solved 2023-01-05
# Runtime: 85 ms (85.71%)
# Memory Usage: 211 MB (100.00%)

# @param {Integer} n
# @return {Integer}
def binary_gap(n)
  (0...32)
    .select { |i| (n & (1 << i)).nonzero? }
    .each_cons(2)
    .map { |x, y| y - x }
    .max || 0
end
