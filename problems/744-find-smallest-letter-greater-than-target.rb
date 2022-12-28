# Solved 2022-12-28
# Runtime: 78 ms (96.30%)
# Memory Usage: 212.1 MB (77.78%)

# @param {Character[]} letters
# @param {Character} target
# @return {Character}
def next_greatest_letter(letters, target)
  return letters.first if letters.last <= target

  letters.bsearch { |letter| letter > target }
end
