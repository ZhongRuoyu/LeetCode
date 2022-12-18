# Solved 2022-12-18
# Runtime: 154 ms (87.57%)
# Memory Usage: 211.4 MB (89.83%)

# @param {String} s
# @return {String}
def reverse_vowels(s)
  is_vowel = ->(ch) { "AEIOUaeiou".include?(ch) }
  l = 0
  r = s.length - 1
  while l < r
    if is_vowel.call(s[l]) && is_vowel.call(s[r])
      s[l], s[r] = s[r], s[l]
      l += 1
      r -= 1
    end
    l += 1 unless is_vowel.call(s[l])
    r -= 1 unless is_vowel.call(s[r])
  end
  s
end
