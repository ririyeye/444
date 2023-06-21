#ifndef __PPP_H__
#define __PPP_H__

#ifdef WIN32
#define PPP_API __declspec(dllexport)
#else
#define PPP_API
#endif


PPP_API void pp_add(void *p, int num);
PPP_API int pp_sum(void *p);
PPP_API void *pp_alloc(void);

#endif
