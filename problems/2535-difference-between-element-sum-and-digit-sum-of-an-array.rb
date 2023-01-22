# Solved 2023-01-22
# Runtime: 111 ms (75.76%)
# Memory Usage: 211.2 MB (78.79%)

# @param {Integer[]} nums
# @return {Integer}
def difference_of_sum(nums)
  sum_digits = lambda { |num|
    result = 0
    while num.positive?
      num, rem = num.divmod(10)
      result += rem
    end
    result
  }

  element_sum = 0
  digit_sum = 0
  nums.each do |num|
    element_sum += num
    digit_sum += sum_digits.call(num)
  end
  (element_sum - digit_sum).abs
end

# Happy New Year :D
