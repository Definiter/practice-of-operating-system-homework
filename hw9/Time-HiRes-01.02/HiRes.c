/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.18 from the
 * contents of HiRes.xs. Do not edit this file, edit HiRes.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "HiRes.xs"
#ifdef __cplusplus
extern "C" {
#endif
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include <sys/time.h>
#ifdef __cplusplus
}
#endif


#line 23 "HiRes.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(pTHX_ const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
            Perl_croak(aTHX_ "Usage: %s::%s(%s)", hvname, gvname, params);
        else
            Perl_croak(aTHX_ "Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
        Perl_croak(aTHX_ "Usage: CODE(0x%"UVxf")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#ifdef PERL_IMPLICIT_CONTEXT
#define croak_xs_usage(a,b)    S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage        S_croak_xs_usage
#endif

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#line 165 "HiRes.c"

XS_EUPXS(XS_Time__HiRes_usleep); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Time__HiRes_usleep)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "useconds");
    {
	int	useconds = (int)SvIV(ST(0))
;

	usleep(useconds);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Time__HiRes_ualarm); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Time__HiRes_ualarm)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "useconds, interval");
    {
	int	useconds = (int)SvIV(ST(0))
;
	int	interval = (int)SvIV(ST(1))
;
	int	RETVAL;
	dXSTARG;

	RETVAL = ualarm(useconds, interval);
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Time__HiRes_gettimeofday); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Time__HiRes_gettimeofday)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
#line 29 "HiRes.xs"
        struct timeval Tp;
#line 215 "HiRes.c"
#line 31 "HiRes.xs"
	int status;
        status = gettimeofday (&Tp, NULL);
        EXTEND(sp, 2);
        PUSHs(sv_2mortal(newSViv(Tp.tv_sec)));
        PUSHs(sv_2mortal(newSViv(Tp.tv_usec)));
#line 222 "HiRes.c"
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Time__HiRes_sleep); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Time__HiRes_sleep)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "fseconds");
    {
	double	fseconds = (double)SvNV(ST(0))
;
#line 46 "HiRes.xs"
	int useconds = fseconds * 1000000;
	usleep (useconds);
#line 241 "HiRes.c"
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Time__HiRes_time); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Time__HiRes_time)
{
    dVAR; dXSARGS;
    if (items != 0)
       croak_xs_usage(cv,  "");
    {
#line 52 "HiRes.xs"
        struct timeval Tp;
#line 256 "HiRes.c"
	double	RETVAL;
	dXSTARG;
#line 54 "HiRes.xs"
	int status;
        status = gettimeofday (&Tp, NULL);
        RETVAL = (Tp.tv_sec + (Tp.tv_usec / 1000000.)) / 2;
#line 263 "HiRes.c"
	XSprePUSH; PUSHn((double)RETVAL);
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Time__HiRes); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Time__HiRes)
{
    dVAR; dXSARGS;
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#endif
    XS_VERSION_BOOTCHECK;

        newXS("Time::HiRes::usleep", XS_Time__HiRes_usleep, file);
        newXS("Time::HiRes::ualarm", XS_Time__HiRes_ualarm, file);
        newXS("Time::HiRes::gettimeofday", XS_Time__HiRes_gettimeofday, file);
        newXS("Time::HiRes::sleep", XS_Time__HiRes_sleep, file);
        newXS("Time::HiRes::time", XS_Time__HiRes_time, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

