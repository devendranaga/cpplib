#ifndef __C_STRING_H__
#define __C_STRING_H__

#ifdef __cplusplus
extern "C" {
#endif

int c_strlen(const char *str);

int c_strcmp(const char *src, const char *dst);

int c_strcat(char *src, const char *dst);

int c_strcpy(const char *src, char *dst);

#ifdef __cplusplus
}
#endif

#endif

