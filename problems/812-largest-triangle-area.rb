# Solved 2023-01-02
# Runtime: 137 ms (100.00%)
# Memory Usage: 211.1 MB (100.00%)

# @param {Integer[][]} points
# @return {Float}
def largest_triangle_area(points)
  # https://en.wikipedia.org/wiki/Shoelace_formula
  area = lambda { |i, j, k|
    x1, y1 = points[i]
    x2, y2 = points[j]
    x3, y3 = points[k]
    0.5 * (((x1 - x3) * (y2 - y1)) - ((x1 - x2) * (y3 - y1))).abs
  }

  max_area = 0.0
  (0...points.length).each do |i|
    (i + 1...points.length).each do |j|
      (j + 1...points.length).each do |k|
        max_area = [max_area, area.call(i, j, k)].max
      end
    end
  end
  max_area
end
