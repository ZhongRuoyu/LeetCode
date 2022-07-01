# Solved 2022-07-01
# Runtime: 88 ms (97.41%)
# Memory Usage: 3.9 MB (71.46%)

# Read from the file file.txt and print its transposed content to stdout.
awk '
{
    for (i = 1; i <= NF; ++i) {
        if (NR == 1) {
            row[i] = $i
        } else {
            row[i] = row[i] " " $i
        }
    }
}
END {
    for (i = 1; row[i] != ""; ++i) {
        print row[i]
    }
}
' file.txt
