#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int longestIncSeq(int *seq, size_t len, int *subSeq) {
    int maxSubStart = 0;
    int maxSubLen = 1;
    int subStart = 0;
    int subLen = 1;
    // Find max subsequence
    for (int i = 1; i < len; ++i) {
        if (seq[i] - seq[i - 1] == 1) {
            subLen++;
        } else {
            if (subLen > maxSubLen) {
                maxSubLen = subLen;
                maxSubStart = subStart;
            }
            subStart = i;
            subLen = 1;
        }
    }
    // If the original sequence is already ordered
    if (subLen > maxSubLen) {
        maxSubLen = subLen;
        maxSubStart = subStart;
    }
    // If found subsequence with only one element return 0 (task-specific condition)
    if (maxSubLen == 1) return 0;
    // Put found subsequence into result
    for (int i = 0; i < maxSubLen; ++i) {
        subSeq[i] = seq[maxSubStart + i];
    }
    return maxSubLen;
}

int main() {
    int len;
    scanf("%d", &len);
    if (len < 0) printf("[error]");
    else if (len < 2) printf("0");
    else {
        int *seq = (int *) malloc(len * sizeof(seq));
        for (int i = 0; i < len; i++) {
            if (scanf("%d", &seq[i]) == 0) {
                printf("[error]");
                free(seq);
                return 0;
            }
        }

        int *subSeq = (int *) malloc(len * sizeof(subSeq));
        int subSeqLen = longestIncSeq(seq, len, subSeq);

        printf("%d\n", subSeqLen);
        for (int i = 0; i < subSeqLen; i++) {
            printf("%d ", subSeq[i]);
        }
        printf("\n");
        free(seq);
        free(subSeq);
    }
    return 0;
}