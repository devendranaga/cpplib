#include <c_string.h>

int c_strlen(const char *str)
{
    int len = 0;

    if (!str) {
        return -1;
    }

    while (str[len] != '\0') { len ++; }

    return len;
}

int c_strcmp(const char *src, const char *dst)
{
    int src_len;
    int dst_len;
    int i;

    if (!src || !dst) {
        return -1;
    }

    src_len = c_strlen(src);
    dst_len = c_strlen(dst);

    if (src_len != dst_len) {
        return -1;
    }

    for (i = 0; i < dst_len; i ++) {
        if (src[i] != dst[i]) {
            return src[i] - dst[i];
        }
    }

    return 0;
}

int c_strcat(char *src, const char *dst)
{
    int src_len;
    int dst_len;
    int i;
    int j;

    if (!src || !dst) {
        return -1;
    }

    src_len = c_strlen(src);
    dst_len = c_strlen(dst);
    for (i = src_len, j = 0; j < dst_len; i ++, j ++) { src[i] = dst[j]; }

    src[i] = '\0';
    return i;
}

int c_strcpy(const char *src, char *dst)
{
    int i = 0;

    if (!src || !dst) {
        return -1;
    }

    while ((dst[i] = src[i]) != '\0');

    dst[i] = '\0';
    return i;
}

