/* Generated by ./xlat/gen.sh from ./xlat/multicast_router_types.in; do not edit. */
#if !(defined(MDB_RTR_TYPE_DISABLED) || (defined(HAVE_DECL_MDB_RTR_TYPE_DISABLED) && HAVE_DECL_MDB_RTR_TYPE_DISABLED))
# define MDB_RTR_TYPE_DISABLED 0
#endif
#if !(defined(MDB_RTR_TYPE_TEMP_QUERY) || (defined(HAVE_DECL_MDB_RTR_TYPE_TEMP_QUERY) && HAVE_DECL_MDB_RTR_TYPE_TEMP_QUERY))
# define MDB_RTR_TYPE_TEMP_QUERY 1
#endif
#if !(defined(MDB_RTR_TYPE_PERM) || (defined(HAVE_DECL_MDB_RTR_TYPE_PERM) && HAVE_DECL_MDB_RTR_TYPE_PERM))
# define MDB_RTR_TYPE_PERM 2
#endif
#if !(defined(MDB_RTR_TYPE_TEMP) || (defined(HAVE_DECL_MDB_RTR_TYPE_TEMP) && HAVE_DECL_MDB_RTR_TYPE_TEMP))
# define MDB_RTR_TYPE_TEMP 3
#endif

#ifdef IN_MPERS

# error static const struct xlat multicast_router_types in mpers mode

#else

static
const struct xlat multicast_router_types[] = {
 XLAT(MDB_RTR_TYPE_DISABLED),
 XLAT(MDB_RTR_TYPE_TEMP_QUERY),
 XLAT(MDB_RTR_TYPE_PERM),
 XLAT(MDB_RTR_TYPE_TEMP),
 XLAT_END
};

#endif /* !IN_MPERS */