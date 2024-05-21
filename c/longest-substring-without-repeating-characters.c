# include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int begin = 0;
    int len = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        for (int j = begin; j < i; j++) {
            if (s[j] == s[i]) {
                begin = j + 1;
            }

        }

        len = len > i - begin + 1 ? len : i - begin + 1;
    }

    return len;
}

int main() {
    char s1[9] = "abcabcbb";
    printf("Case1 : %d\n", lengthOfLongestSubstring(s1));
    char s2[6] = "bbbbb";
    printf("Case2 : %d\n", lengthOfLongestSubstring(s2));
    char s3[7] = "pwwkew";
    printf("Case3 : %d\n", lengthOfLongestSubstring(s3));
    char s4[5] = "dvdf";
    printf("Case4 : %d\n", lengthOfLongestSubstring(s4));
}
