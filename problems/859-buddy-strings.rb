# Solved 2023-01-04
# Runtime: 104 ms (78.57%)
# Memory Usage: 211.2 MB (92.86%)

# @param {String} s
# @param {String} goal
# @return {Boolean}
def buddy_strings(s, goal)
  return false if s.length != goal.length

  swap = nil
  letter_count = ("a".."z").to_h { |ch| [ch, 0] }
  (0...s.length).each do |i|
    letter_count[s[i]] += 1
    next if s[i] == goal[i]

    return swap == [goal[i], s[i]] && s[i + 1..] == goal[i + 1..] unless swap.nil?

    swap = [s[i], goal[i]]
  end

  swap.nil? && letter_count.any? { |_ch, count| count > 1 }
end
