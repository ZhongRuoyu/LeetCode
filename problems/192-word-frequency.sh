# Solved 2022-04-07
# Runtime: 131 ms (67.59%)
# Memory Usage: 3.8 MB (86.18%)

# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt | tr -s " " "\n" | sort | uniq -c | sort -r | awk '{ print $2, $1 }'
