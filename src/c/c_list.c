#include <stdlib.h>
#include <c_list.h>

struct c_list {
    void *data;
    struct c_list *next;
};

static struct c_list *head;
static struct c_list *tail;
static size_t length = 0;

void c_list_init()
{
    head = tail = NULL;
    length = 0;
}

int c_list_add_head(void *data)
{
    struct c_list *t;

    t = calloc(1, sizeof(*t));
    if (!t) {
        return -1;
    }

    t->data = data;
    if (!head) {
        head = t;
        tail = t;
    } else {
        t->next = head;
        head = t;
    }

    return 0;
}

void c_list_deinit()
{
    struct c_list *t;

    while (head) {
        t = head;
        head = head->next;
        free(t);
    }
    length = 0;
}

