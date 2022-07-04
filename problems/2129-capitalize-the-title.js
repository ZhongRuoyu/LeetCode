// Solved 2022-07-04
// Runtime: 79 ms (67.84%)
// Memory Usage: 42.5 MB (67.40%)

/**
 * @param {string} title
 * @return {string}
 */
var capitalizeTitle = function (title) {
    return title.split(" ")
        .map(word => {
            if (word.length <= 2) {
                return word.toLowerCase();
            }
            arr = word.toLowerCase().split("");
            arr[0] = arr[0].toUpperCase();
            return arr.join("");
        })
        .join(" ");
};
