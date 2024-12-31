/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.8 */

#ifndef PB_MAIN_ENTRY_PB_H_INCLUDED
#define PB_MAIN_ENTRY_PB_H_INCLUDED
#include "../3rdparty/nanopb/pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Struct definitions */
typedef struct _MainEntry {
    int32_t argc;
    pb_callback_t argv;
} MainEntry;


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define MainEntry_init_default                   {0, {{NULL}, NULL}}
#define MainEntry_init_zero                      {0, {{NULL}, NULL}}

/* Field tags (for use in manual encoding/decoding) */
#define MainEntry_argc_tag                       1
#define MainEntry_argv_tag                       2

/* Struct field encoding specification for nanopb */
#define MainEntry_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, INT32,    argc,              1) \
X(a, CALLBACK, REPEATED, STRING,   argv,              2)
#define MainEntry_CALLBACK pb_default_field_callback
#define MainEntry_DEFAULT NULL

extern const pb_msgdesc_t MainEntry_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define MainEntry_fields &MainEntry_msg

/* Maximum encoded size of messages (where known) */
/* MainEntry_size depends on runtime parameters */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
