#include "ppp.h"
#include <stdlib.h>
#include <stdio.h>
struct ppp
{
    int sum;
};

PPP_API void pp_add(void *p, int num)
{
    struct ppp *cur = (struct ppp *)p;
    cur->sum += num;
}

PPP_API int pp_sum(void *p)
{
    struct ppp *cur = (struct ppp *)p;
    return cur->sum;
}

PPP_API void *pp_alloc(void)
{
    struct ppp* cur = (struct ppp*)malloc(sizeof(struct ppp));
	cur->sum = 0;
    return cur;
}
