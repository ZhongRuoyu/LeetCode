# Solved 2023-01-07
# Runtime: 157 ms (79.17%)
# Memory Usage: 212 MB (100.00%)

# @param {Integer} n
# @param {Integer[][]} trust
# @return {Integer}
def find_judge(n, trust)
  trusting = [0] * (n + 1)
  trusted = [0] * (n + 1)
  trust.each do |from, to|
    trusting[from] += 1
    trusted[to] += 1
  end
  (1..n).detect { |i| trusting[i].zero? && trusted[i] == n - 1 } || -1
end
