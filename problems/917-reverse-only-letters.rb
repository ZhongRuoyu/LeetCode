# Solved 2022-12-19
# Runtime: 103 ms (93.75%)
# Memory Usage: 210.9 MB (93.75%)

# @param {String} s
# @return {String}
def reverse_only_letters(s)
  is_letter = ->(ch) { /[[:alpha:]]/.match(ch) }
  l = 0
  r = s.length - 1
  while l < r
    if is_letter.call(s[l]) && is_letter.call(s[r])
      s[l], s[r] = s[r], s[l]
      l += 1
      r -= 1
    end
    l += 1 unless is_letter.call(s[l])
    r -= 1 unless is_letter.call(s[r])
  end
  s
end
