# Solved 2023-01-08
# Runtime: 285 ms (100.00%)
# Memory Usage: 229 MB (100.00%)

# @param {Integer[][]} rectangles
# @return {Integer}
def interchangeable_rectangles(rectangles)
  rectangles
    .map { |r| r[0].fdiv r[1] }
    .tally
    .sum { |_ratio, count| count * (count - 1) / 2 }
end
