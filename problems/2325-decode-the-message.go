// Solved 2022-07-24
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.4 MB (82.28%)

func decodeMessage(key string, message string) string {
	table := make(map[byte]byte)
	for i := range key {
		if key[i] == ' ' {
			continue
		}
		_, keyExists := table[key[i]]
		if keyExists {
			continue
		}
		table[key[i]] = "abcdefghijklmnopqrstuvwxyz"[len(table)]
	}

	result := make([]byte, len(message))
	for i := range message {
		if message[i] == ' ' {
			result[i] = ' '
		} else {
			result[i] = table[message[i]]
		}
	}

	return string(result)
}
