// Solved 2020-11-20 22:23
// Runtime: 12 ms (67.74%)
// Memory Usage: 6.9 MB (83.87%)

#define MAX 96

typedef struct {
    unsigned long local, domain;
} emailhash;

unsigned long djb2(char *str) {
    unsigned long hash = 5381UL;
    char c;
    while (c = *str++) hash = ((hash << 5) + hash) + c;  // hash * 33 + c
    return hash;
}

void resolve(char **s, emailhash *t, int n) {
    char l[MAX], d[MAX], *p;
    int x;
    for (int i = 0; i < n; i++) {
        p = s[i];
        x = 0;
        while (*p != '@' && *p != '+') {
            if (*p != '.') l[x++] = *p;
            p++;
        }
        l[x] = '\0';
        while (*(p++) != '@') continue;
        x = 0;
        while (d[x++] = *(++p)) continue;
        t[i].local = djb2(l);
        t[i].domain = djb2(d);
    }
}

int locateUnique(emailhash *u, emailhash *cmp, int c) {
    if (!c) return -1;
    for (int i = 0; i < c; i++) {
        if ((u[i].local == cmp->local) &&
            (u[i].domain == cmp->domain)) {
            return i;
        }
    }
    return -1;
}

int countUnique(emailhash *x, int n) {
    for (int i = 1; i < n; i++) {
        if ((locateUnique(x, x + i, i)) != -1) {
            x[i--] = x[--n];
        }
    }
    return n;
}

int numUniqueEmails(char **words, int wordsSize) {
    emailhash x[wordsSize];
    resolve(words, x, wordsSize);
    return countUnique(x, wordsSize);
}
