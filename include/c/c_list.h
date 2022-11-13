#ifndef __C_LIST_H__
#define __C_LIST_H__

#ifdef __cplusplus
extern "C" {
#endif

typedef void for_each_cb(void *data);

void c_list_init();
int c_list_add_head(void *data);
int c_list_add_tail(void *data);
void c_list_for_each(for_each_cb cb);
int c_list_delete(void *data);
int c_list_length();
void c_list_deinit();

#ifdef __cplusplus
}
#endif

#endif

