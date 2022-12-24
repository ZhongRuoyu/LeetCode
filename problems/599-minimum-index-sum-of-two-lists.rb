# Solved 2022-12-24
# Runtime: 122 ms (100.00%)
# Memory Usage: 212 MB (81.25%)

# @param {String[]} list1
# @param {String[]} list2
# @return {String[]}
def find_restaurant(list1, list2)
  return find_restaurant(list2, list1) if list1.length > list2.length

  lookup = list1.map.with_index { |str, i| [str, i] }.to_h
  result = []
  least_index = nil

  list2.each_with_index do |str, i|
    next unless lookup.key? str

    index_sum = lookup[str] + i
    next unless least_index.nil? || index_sum <= least_index

    if index_sum == least_index
      result << str
    else
      least_index = index_sum
      result = [str]
    end
  end

  result
end
