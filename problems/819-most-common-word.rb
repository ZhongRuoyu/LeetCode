# Solved 2023-01-03
# Runtime: 99 ms (92.31%)
# Memory Usage: 211 MB (92.31%)

# @param {String} paragraph
# @param {String[]} banned
# @return {String}
def most_common_word(paragraph, banned)
  paragraph
    .gsub(/[!?',;.]/, " ")
    .split
    .map(&:downcase)
    .select { |word| !banned.include?(word) }
    .tally
    .max_by { |_word, count| count }[0]
end
