# Solved 2023-01-21
# Runtime: 80 ms (91.89%)
# Memory Usage: 212.5 MB (86.49%)

# @param {Integer[]} nums
# @return {Integer}
def maximum_count(nums)
  positives = 0
  negatives = 0
  nums.each do |num|
    if num.positive?
      positives += 1
    elsif num.negative?
      negatives += 1
    end
  end
  [positives, negatives].max
end
