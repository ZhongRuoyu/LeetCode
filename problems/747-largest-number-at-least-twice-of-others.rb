# Solved 2022-12-29
# Runtime: 87 ms (82.61%)
# Memory Usage: 211 MB (91.30%)

# @param {Integer[]} nums
# @return {Integer}
def dominant_index(nums)
  largest = nil
  second_largest = nil
  largest_index = nil

  nums.each_with_index do |num, i|
    next unless second_largest.nil? || num > second_largest

    if largest.nil? || num > largest
      second_largest = largest
      largest = num
      largest_index = i
    else
      second_largest = num
    end
  end

  largest >= second_largest * 2 ? largest_index : -1
end
