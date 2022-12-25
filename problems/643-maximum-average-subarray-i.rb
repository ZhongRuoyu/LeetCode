# Solved 2022-12-25
# Runtime: 206 ms (93.94%)
# Memory Usage: 224.8 MB (92.42%)

# @param {Integer[]} nums
# @param {Integer} k
# @return {Float}
def find_max_average(nums, k)
  sum = 0
  (0...k).each { |i| sum += nums[i] }
  max_sum = sum
  (k...nums.length).each do |i|
    sum = sum - nums[i - k] + nums[i]
    max_sum = sum if sum > max_sum
  end
  max_sum.fdiv k
end
