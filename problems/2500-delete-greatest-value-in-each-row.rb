# Solved 2023-01-12
# Runtime: 75 ms (100.00%)
# Memory Usage: 213.1 MB (36.11%)

# @param {Integer[][]} grid
# @return {Integer}
def delete_greatest_value(grid)
  grid.map(&:sort).transpose.sum(&:max)
end
