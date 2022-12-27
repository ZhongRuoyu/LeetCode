# Solved 2022-12-27
# Runtime: 130 ms (88.89%)
# Memory Usage: 212.7 MB (100.00%)

# @param {Integer[]} nums
# @return {Integer}
def find_shortest_sub_array(nums)
  degree = 0
  degree_nums = []
  lookup = Hash.new { |hash, num| hash[num] = [0, nil, nil] }
  nums.each_with_index do |num, i|
    entry = lookup[num]
    entry[0] += 1
    entry[1] = i if entry[1].nil?
    entry[2] = i if entry[2].nil? || entry[2] < i
    if entry[0] > degree
      degree = entry[0]
      degree_nums = [num]
    elsif entry[0] == degree
      degree_nums << num
    end
  end
  degree_nums.map { |num| lookup[num][2] - lookup[num][1] + 1 }.min
end
