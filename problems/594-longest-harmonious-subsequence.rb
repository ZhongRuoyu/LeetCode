# Solved 2022-12-23
# Runtime: 185 ms (57.14%)
# Memory Usage: 218.2 MB (57.14%)

# @param {Integer[]} nums
# @return {Integer}
def find_lhs(nums)
  lookup = Hash.new(0)
  result = 0
  nums.each do |num|
    lookup[num] += 1
    result = [result, lookup[num] + lookup[num - 1]].max if lookup.key?(num - 1)
    result = [result, lookup[num] + lookup[num + 1]].max if lookup.key?(num + 1)
  end
  result
end
