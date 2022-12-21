# Solved 2022-12-21
# Runtime: 103 ms (77.78%)
# Memory Usage: 212.5 MB (55.56%)

# @param {String} s
# @param {Integer} k
# @return {String}
def reverse_str(s, k)
  s.chars
   .each_slice(k)
   .map
   .with_index { |slice, i| i.even? ? slice.reverse : slice }
   .join
end
