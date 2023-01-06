# Solved 2023-01-06
# Runtime: 217 ms (71.43%)
# Memory Usage: 223.4 MB (78.57%)

# @param {Integer[]} nums
# @return {Boolean}
def is_monotonic(nums)
  is_increasing = is_decreasing = true
  nums.each_cons(2) do |x, y|
    is_increasing = false if x > y
    is_decreasing = false if x < y
  end
  is_increasing || is_decreasing
end
