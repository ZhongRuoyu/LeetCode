# Solved 2022-12-26
# Runtime: 156 ms (100.00%)
# Memory Usage: 213.8 MB (83.33%)

# # Definition for Employee.
# class Employee
#     attr_accessor :id, :importance, :subordinates
#     def initialize( id, importance, subordinates)
#         @id = id
#         @importance = importance
#         @subordinates = subordinates
#     end
# end

# @param {Employee} employees
# @param {Integer} id
# @return {Integer}
def get_importance(employees, id)
  employees = employees.to_h { |e| [e.id, e] }
  result = 0
  queue = [id]
  until queue.empty?
    subordinate = employees[queue.pop]
    queue += subordinate.subordinates
    result += subordinate.importance
  end
  result
end
