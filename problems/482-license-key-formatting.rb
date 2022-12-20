# Solved 2022-12-20
# Runtime: 113 ms (90.91%)
# Memory Usage: 215.6 MB (72.73%)

# @param {String} s
# @param {Integer} k
# @return {String}
def license_key_formatting(s, k)
  (s.delete!("-") || s).upcase!
  prefix_length = s.length % k
  groups = s[prefix_length...].chars.each_slice(k).map(&:join)
  groups.insert(0, s[0...prefix_length]) unless prefix_length.zero?
  groups.join("-")
end
