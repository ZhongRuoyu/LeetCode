# Solved 2022-12-22
# Runtime: 161 ms (100.00%)
# Memory Usage: 226.2 MB (80.00%)

# @param {Integer[]} candy_type
# @return {Integer}
def distribute_candies(candy_type)
  [candy_type.uniq.length, candy_type.length / 2].min
end
