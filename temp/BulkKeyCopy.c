/*
 * This file was generated automatically by ExtUtils::ParseXS version 2.2203 from the
 * contents of BulkKeyCopy.xs. Do not edit this file, edit BulkKeyCopy.xs instead.
 *
 *	ANY CHANGES MADE HERE WILL BE LOST! 
 *
 */

#line 1 "lib/Hash/BulkKeyCopy.xs"
#ifdef __cplusplus
extern "C" {
#endif

#define PERL_NO_GET_CONTEXT /* we want efficiency */
#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>

#ifdef __cplusplus
} /* extern "C" */
#endif

#line 24 "temp/BulkKeyCopy.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
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
#define croak_xs_usage(a,b)	S_croak_xs_usage(aTHX_ a,b)
#else
#define croak_xs_usage		S_croak_xs_usage
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

#line 76 "temp/BulkKeyCopy.c"

XS(XS_Hash__BulkKeyCopy_hash_bulk_keycopy); /* prototype to pass -Wmissing-prototypes */
XS(XS_Hash__BulkKeyCopy_hash_bulk_keycopy)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
    if (items != 4)
       croak_xs_usage(cv,  "hash_target, hash_src, hash_target_keyarr, hash_src_keyarr");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	HV*	hash_target;
	HV*	hash_src;
	AV*	hash_target_keyarr;
	AV*	hash_src_keyarr;
#line 25 "lib/Hash/BulkKeyCopy.xs"
    int ht_kl,hs_kl,i;
    char *k1, *k2;
    SV **ptr1, **ptr2, **src_value;
    STRLEN k1size,k2size;
#line 100 "temp/BulkKeyCopy.c"

	if (SvROK(ST(0)) && SvTYPE(SvRV(ST(0)))==SVt_PVHV)
	    hash_target = (HV*)SvRV(ST(0));
	else
	    Perl_croak(aTHX_ "%s: %s is not a hash reference",
			"Hash::BulkKeyCopy::hash_bulk_keycopy",
			"hash_target");

	if (SvROK(ST(1)) && SvTYPE(SvRV(ST(1)))==SVt_PVHV)
	    hash_src = (HV*)SvRV(ST(1));
	else
	    Perl_croak(aTHX_ "%s: %s is not a hash reference",
			"Hash::BulkKeyCopy::hash_bulk_keycopy",
			"hash_src");

	if (SvROK(ST(2)) && SvTYPE(SvRV(ST(2)))==SVt_PVAV)
	    hash_target_keyarr = (AV*)SvRV(ST(2));
	else
	    Perl_croak(aTHX_ "%s: %s is not an array reference",
			"Hash::BulkKeyCopy::hash_bulk_keycopy",
			"hash_target_keyarr");

	if (SvROK(ST(3)) && SvTYPE(SvRV(ST(3)))==SVt_PVAV)
	    hash_src_keyarr = (AV*)SvRV(ST(3));
	else
	    Perl_croak(aTHX_ "%s: %s is not an array reference",
			"Hash::BulkKeyCopy::hash_bulk_keycopy",
			"hash_src_keyarr");
#line 30 "lib/Hash/BulkKeyCopy.xs"
    ht_kl = av_len(hash_target_keyarr) + 1;
    hs_kl = av_len(hash_src_keyarr) + 1;
    if (hs_kl == 0 || (ht_kl > 0 && hs_kl != ht_kl)) return;
    for(i=0;i<hs_kl;i++) {
        ptr1 = av_fetch(hash_target_keyarr, i, 0);
        ptr2 = av_fetch(hash_src_keyarr, i, 0);
        k1 = ptr1 == NULL ? NULL : SvPV(*ptr1, k1size);
        k2 = SvPV(*ptr2, k2size);
        src_value = hv_fetch(hash_src, k2, k2size, 0);
        if (src_value) {
            (void)hv_store(hash_target, k1?k1:k2, k1?k1size:k2size, newSVsv(*src_value), 0);
        }
    }
#line 143 "temp/BulkKeyCopy.c"
	PUTBACK;
	return;
    }
}

#ifdef __cplusplus
extern "C"
#endif
XS(boot_Hash__BulkKeyCopy); /* prototype to pass -Wmissing-prototypes */
XS(boot_Hash__BulkKeyCopy)
{
#ifdef dVAR
    dVAR; dXSARGS;
#else
    dXSARGS;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
    XS_VERSION_BOOTCHECK ;

        newXS("Hash::BulkKeyCopy::hash_bulk_keycopy", XS_Hash__BulkKeyCopy_hash_bulk_keycopy, file);
#if (PERL_REVISION == 5 && PERL_VERSION >= 9)
  if (PL_unitcheckav)
       call_list(PL_scopestack_ix, PL_unitcheckav);
#endif
    XSRETURN_YES;
}

