# Solved 2023-01-10
# Runtime: 111 ms (84.62%)
# Memory Usage: 210.9 MB (87.18%)

# @param {String} secret
# @param {String} guess
# @return {String}
def get_hint(secret, guess)
  bulls = (0...secret.length).count { |i| secret[i] == guess[i] }
  guess_count = guess.chars.tally
  cows = -bulls
  secret.chars.each do |g|
    next unless guess_count.key?(g) && guess_count[g].positive?

    guess_count[g] -= 1
    cows += 1
  end
  "#{bulls}A#{cows}B"
end
