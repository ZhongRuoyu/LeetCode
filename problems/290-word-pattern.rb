# Solved 2022-12-17
# Runtime: 66 ms (95.24%)
# Memory Usage: 211 MB (76.19%)

# @param {String} pattern
# @param {String} s
# @return {Boolean}
def word_pattern(pattern, s)
  words = s.split
  return false if pattern.length != words.length

  letter_to_word = {}
  word_to_letter = {}
  words.each_with_index do |word, i|
    letter = pattern[i]

    if ((letter_to_word.key? letter) && (letter_to_word[letter] != word)) ||
       ((word_to_letter.key? word) && (word_to_letter[word] != letter))
      return false
    end

    letter_to_word[letter] = word
    word_to_letter[word] = letter
  end

  true
end
