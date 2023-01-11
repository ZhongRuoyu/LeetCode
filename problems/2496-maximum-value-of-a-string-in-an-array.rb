# Solved 2023-01-11
# Runtime: 87 ms (86.67%)
# Memory Usage: 210.9 MB (93.33%)

# @param {String[]} strs
# @return {Integer}
def maximum_value(strs)
  strs.map { |str| str.match?(/\D/) ? str.length : str.to_i }.max
end
