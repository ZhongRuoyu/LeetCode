# Solved 2022-12-30
# Runtime: 99 ms (100.00%)
# Memory Usage: 211 MB (90.00%)

# @param {String} license_plate
# @param {String[]} words
# @return {String}
def shortest_completing_word(license_plate, words)
  plate_letters = license_plate
                  .chars
                  .grep(/[[:alpha:]]/)
                  .map(&:downcase)
                  .tally
  words
    .sort_by(&:length)
    .detect do |word|
      word_letters = word.chars.tally
      plate_letters.all? do |ch, count|
        word_letters.key?(ch) && word_letters[ch] >= count
      end
    end
end
