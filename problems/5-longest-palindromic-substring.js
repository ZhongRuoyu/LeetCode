// Solved 2022-03-06
// Runtime: 127 ms (81.18%)
// Memory Usage: 44.4 MB (70.74%)

/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
    const n = s.length;
    let result = "";
    for (let i = 0; i < n; ++i) {
        for (let k of [0, 1]) {
            let l = i;
            let r = i + k;
            while (l >= 0 && r < n && s.charAt(l) == s.charAt(r)) {
                if (r - l + 1 > result.length) {
                    result = s.slice(l, r + 1);
                }
                --l;
                ++r;
            }
        }
    }
    return result;
};

// Good luck!

// See also: Problem 516 (Longest Palindromic Subsequence), Problem 647 (Palindromic Substrings), Problem 730 (Count Different Palindromic Subsequences)



/*

An O(n) approach:

var longestPalindrome = function (s) {
    // Manacher's algorithm
    // https://en.wikipedia.org/wiki/Longest_palindromic_substring#Manacher's_algorithm

    const sPrime = "|" + s.split("").join("|") + "|";

    // The radius of the longest palindrome centered on each place in sPrime
    const palindromeRadii = Array(sPrime.length).fill(0);

    let center = 1;
    let radius = 0;

    while (center < sPrime.length) {
        // At the start of the loop, radius is already set to a lower-bound for the longest radius.
        // In the first iteration, radius is 0, but it can be higher.

        // Determine the longest palindrome starting at center-radius and going to center+radius
        while (true) {
            let l = center - (radius + 1);
            let r = center + (radius + 1);
            if (l >= 0 && r < sPrime.length && sPrime.charAt(l) === sPrime.charAt(r)) {
                ++radius;
            } else {
                break;
            }
        }

        // Save the radius of the longest palindrome in the array
        palindromeRadii[center] = radius;

        // Below, Center is incremented.
        // If any precomputed values can be reused, they are.
        // Also, Radius may be set to a value greater than 0

        let oldCenter = center;
        let oldRadius = radius;
        ++center;
        // radius' default value will be 0, if we reach the end of the following loop. 
        radius = 0;
        while (center <= oldCenter + oldRadius) {
            // Because center lies inside the old palindrome and every character inside
            // a palindrome has a "mirrored" character reflected across its center, we
            // can use the data that was precomputed for the center's mirrored point.
            let mirroredCenter = oldCenter - (center - oldCenter);
            let maxMirroredRadius = oldCenter + oldRadius - center;
            if (palindromeRadii[mirroredCenter] < maxMirroredRadius) {
                palindromeRadii[center] = palindromeRadii[mirroredCenter];
                ++center;
            } else if (palindromeRadii[mirroredCenter] > maxMirroredRadius) {
                palindromeRadii[center] = maxMirroredRadius;
                ++center;
            } else {  // PalindromeRadii[MirroredCenter] = MaxMirroredRadius
                radius = maxMirroredRadius;
                break;  // exit while loop early
            }
        }
    }

    const centerSPrime =
        palindromeRadii.reduce((maxPos, x, pos, arr) => x > arr[maxPos] ? pos : maxPos, 0);
    const radiusSPrime = palindromeRadii[centerSPrime];
    const radiusS = Math.floor(radiusSPrime / 2);
    const centerS = Math.floor(centerSPrime / 2);

    return s.slice(centerS - radiusS, centerS + radiusS + centerSPrime % 2);
};

*/
