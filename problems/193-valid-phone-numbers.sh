# Solved 2022-04-08
# Runtime: 109 ms (76.26%)
# Memory Usage: 3.1 MB (53.33%)

# Read from the file file.txt and output all valid phone numbers to stdout.
grep "^([0-9]\{3\})[ ]\{1\}[0-9]\{3\}-[0-9]\{4\}$\|^[0-9]\{3\}-[0-9]\{3\}-[0-9]\{4\}$" file.txt
