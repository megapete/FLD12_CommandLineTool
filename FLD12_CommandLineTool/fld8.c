/* fld8.f -- translated by f2c (version 20100827).
   You must link the resulting object file with libf2c:
	on Microsoft Windows system, link with libf2c.lib;
	on Linux or Unix systems, link with .../path/to/libf2c.a -lm
	or, if you install libf2c.a in a standard place, with -lf2c -lm
	-- in that order, at the end of the command line, as in
		cc *.o -lf2c -lm
	Source for libf2c is in /netlib/f2c/libf2c.zip, e.g.,

		http://www.netlib.org/f2c/libf2c.zip
*/

#include "f2c.h"

// PCH: Added string.h to do some smarter stuff
#include <string.h>

/* Common Block Declarations */

// PCH: All global declarations (and references) have had their names changed by adding the prefix 'fld8_' to avoid namespace clashing. That way, they'll stay global, but will only be referred to within this file.


struct {
    real xpos[300], ypos[300];
    integer lnver, lnhor;
    real scale, flxln;
    integer linto;
    shortint iln[150];
    integer i5, i6;
    real tri[118604]	/* was [59302][2] */;
    complex cdens[59302], curvo[20]	/* was [10][2] */;
    integer nvolt;
    real flaxi;
    integer ncod3;
    real rmin, freq;
} fld8_block1_;

#define fld8_block1_1 fld8_block1_

struct {
    real linc[3000];
} fld8_block2_;

#define fld8_block2_1 fld8_block2_

struct {
    real vert[60000]	/* was [30000][2] */;
    complex cpot[30000];
    real datln[2250]	/* was [150][15] */;
} fld8_block3_;

#define fld8_block3_1 fld8_block3_

struct {
    shortint itri4[59302], itri5[59302];
} fld8_block4_;

#define fld8_block4_1 fld8_block4_

union {
    struct {
	real digln[300];
    } _1;
    struct {
	real conco[300];
    } _2;
} fld8_block5_;

#define fld8_block5_1 (fld8_block5_._1)
#define fld8_block5_2 (fld8_block5_._2)

struct {
    integer ntri[8];
} fld8_block6_;

#define fld8_block6_1 fld8_block6_

struct {
    integer nocol;
    shortint warn, out;
    integer point[1500], mass;
    real permo, per, displ, phas, phcur, pchv[64], pchh[64], pi, verf[3], 
	    verl[3], horf[3], horl[3];
} fld8_block7_;

#define fld8_block7_1 fld8_block7_

struct {
    integer ibit[30000];
} fld8_block8_;

#define fld8_block8_1 fld8_block8_

struct {
    complex buffa[175], buffb[1750]	/* was [175][10] */;
    integer n4, n5, n6, n7;
} fld8_block9_;

#define fld8_block9_1 fld8_block9_

struct {
    char ident[80];
} fld8_blck10_;

#define fld8_blck10_1 fld8_blck10_

struct {
    real atpcm[240]	/* was [20][12] */, relax;
    integer itmx;
    real dptmx, fact;
} fld8_blck11_;

#define fld8_blck11_1 fld8_blck11_

struct {
    integer itac, newit;
} fld8_blck12_;

#define fld8_blck12_1 fld8_blck12_

/* Table of constant values */

static integer fld8_c__1 = 1;
static complex fld8_c_b98 = {1.f,0.f};
static real fld8_c_b111 = 1.f;
static integer fld8_c__2 = 2;
static integer fld8_c__3 = 3;
static integer fld8_c__80 = 80;
static integer fld8_c__64 = 64;
static integer fld8_c__4 = 4;
static integer fld8_c__5 = 5;
static integer fld8_c__6 = 6;
static integer fld8_c__7 = 7;
static integer fld8_c__8 = 8;
static integer fld8_c__0 = 0;
static integer fld8_c__10 = 10;
static integer fld8_c__9 = 9;
static real fld8_c_b576 = -1.f;

/* --- SKIN EFFECT AND EDDY CURRENTS, FORTRAN 77 */
/* --- MAIN CALL PROGRAM */
/* Main program */ int FLD8MAIN__(char *baseDirectory)
{
    /* System generated locals */
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer f_open(olist *), f_clos(cllist *);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int ela_(void), elb_(void), elc_(void), outgn_(
	    void);

    o__1.oerr = 0;
    o__1.ounit = 3;
    // o__1.ofnmlen = 7;
    // PCH: Next 5 lines by me
    char fName[255];
    strcpy(fName, baseDirectory);
    strcat(fName, "SCRATCH");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    // o__1.ofnm = "SCRATCH";
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    o__1.oerr = 0;
    o__1.ounit = 4;
    // o__1.ofnmlen = 7;
    strcpy(fName, baseDirectory);
    strcat(fName, "FOR.FIL");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    //o__1.ofnm = "FOR.FIL";
    o__1.orl = 500000;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    o__1.oerr = 0;
    o__1.ounit = 2;
    // o__1.ofnmlen = 8;
    strcpy(fName, baseDirectory);
    strcat(fName, "INP2.FIL");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    // o__1.ofnm = "INP2.FIL";
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    o__1.oerr = 0;
    o__1.ounit = 7;
    // o__1.ofnmlen = 6;
    strcpy(fName, baseDirectory);
    strcat(fName, "OUTPUT");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    // o__1.ofnm = "OUTPUT";
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    o__1.oerr = 0;
    o__1.ounit = 8;
    // o__1.ofnmlen = 9;
    strcpy(fName, baseDirectory);
    strcat(fName, "ATPCM.FIL");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    //o__1.ofnm = "ATPCM.FIL";
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
/* --- ITERATION NUMBER, SATURABLE IRON */
    fld8_blck12_1.itac = 0;
    ela_();
/* --- BRANCH CODE, SATURABLE IRON */
L100:
    fld8_blck12_1.newit = 0;
    ++fld8_blck12_1.itac;
    elb_();
    if (fld8_blck12_1.newit == 1) {
	goto L100;
    }
/* --- ADDITIONAL PROGRAMMED OUTPUT */
    outgn_();
/* --- FLUX PLOT */
    elc_();
    cl__1.cerr = 0;
    cl__1.cunit = 3;
    cl__1.csta = "DELETE";
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 4;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 2;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 7;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 8;
    cl__1.csta = 0;
    f_clos(&cl__1);
    // s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

/* Subroutine */ int subd_(real *d__, real *xm, real *ym, real *xn, real *yn, 
	real *xl, real *yl)
{
    /* System generated locals */
    real r__1, r__2, r__3, r__4, r__5;

    /* Local variables */
    static real dxmax, dymax;

/* Computing MAX */
    r__4 = (r__1 = *xn - *xm, dabs(r__1)), r__5 = (r__2 = *xl - *xn, dabs(
	    r__2)), r__4 = max(r__4,r__5), r__5 = (r__3 = *xm - *xl, dabs(
	    r__3));
    dxmax = dmax(r__4,r__5);
/* Computing MAX */
    r__4 = (r__1 = *yn - *ym, dabs(r__1)), r__5 = (r__2 = *yl - *yn, dabs(
	    r__2)), r__4 = max(r__4,r__5), r__5 = (r__3 = *ym - *yl, dabs(
	    r__3));
    dymax = dmax(r__4,r__5);
    if (dxmax >= dymax) {
	*d__ = *xl * (*ym - *yn) + *xm * (*yn - *yl) + *xn * (*yl - *ym);
    }
    if (dxmax < dymax) {
	*d__ = *yl * (*xn - *xm) + *ym * (*xl - *xn) + *yn * (*xm - *xl);
    }
    return 0;
} /* subd_ */

/* Subroutine */ int asp_(integer *l, integer *m, integer *n, real *rat, real 
	*d__)
{
    /* System generated locals */
    real r__1, r__2, r__3, r__4, r__5, r__6, r__7, r__8;

    /* Local variables */
    static real xl, yl, xm, ym, xn, yn;
    extern /* Subroutine */ int subd_(real *, real *, real *, real *, real *, 
	    real *, real *);
    static real sidel;

/* --- ASPECT RATIO */
    xl = fld8_block3_1.vert[*l - 1];
    yl = fld8_block3_1.vert[*l + 29999];
    xm = fld8_block3_1.vert[*m - 1];
    ym = fld8_block3_1.vert[*m + 29999];
    xn = fld8_block3_1.vert[*n - 1];
    yn = fld8_block3_1.vert[*n + 29999];
    subd_(d__, &xm, &ym, &xn, &yn, &xl, &yl);
    if (*rat == -1.f) {
	goto L100;
    }
/* --- LONGEST SIDE SQUARED */
/* Computing MAX */
/* Computing 2nd power */
    r__3 = xm - xl;
/* Computing 2nd power */
    r__4 = ym - yl;
/* Computing 2nd power */
    r__5 = xn - xm;
/* Computing 2nd power */
    r__6 = yn - ym;
/* Computing 2nd power */
    r__7 = xl - xn;
/* Computing 2nd power */
    r__8 = yl - yn;
    r__1 = r__3 * r__3 + r__4 * r__4, r__2 = r__5 * r__5 + r__6 * r__6, r__1 =
	     max(r__1,r__2), r__2 = r__7 * r__7 + r__8 * r__8;
    sidel = dmax(r__1,r__2);
    *rat = *d__ / sidel;
L100:
    return 0;
} /* asp_ */

/* Subroutine */ int cooco_(integer *npnts, integer *in)
{
    /* Format strings */
    static char fmt_99[] = "(10f7.0)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);

    /* Local variables */
    static integer i1, i2, i3, i4, k1;

    /* Fortran I/O blocks */
    static cilist io___13 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___14 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___17 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___18 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___19 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___20 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___21 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___22 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___23 = { 0, 0, 0, fmt_99, 0 };


/* L99: */
    i1 = *npnts;
    i2 = 0;
L801:
    i3 = i1;
    if (i3 > 10) {
	i3 = 10;
    }
    if (i3 == 1) {
	io___13.ciunit = *in;
	s_rsfe(&io___13);
	do_fio(&fld8_c__1, (char *)&fld8_block5_2.conco[290], (ftnlen)sizeof(real));
	e_rsfe();
    }
    if (i3 == 2) {
	io___14.ciunit = *in;
	s_rsfe(&io___14);
	for (i4 = 291; i4 <= 292; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_2.conco[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 3) {
	io___16.ciunit = *in;
	s_rsfe(&io___16);
	for (i4 = 291; i4 <= 293; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_2.conco[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 4) {
	io___17.ciunit = *in;
	s_rsfe(&io___17);
	for (i4 = 291; i4 <= 294; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_2.conco[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 5) {
	io___18.ciunit = *in;
	s_rsfe(&io___18);
	for (i4 = 291; i4 <= 295; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_2.conco[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 6) {
	io___19.ciunit = *in;
	s_rsfe(&io___19);
	for (i4 = 291; i4 <= 296; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_2.conco[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 7) {
	io___20.ciunit = *in;
	s_rsfe(&io___20);
	for (i4 = 291; i4 <= 297; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_2.conco[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 8) {
	io___21.ciunit = *in;
	s_rsfe(&io___21);
	for (i4 = 291; i4 <= 298; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_2.conco[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 9) {
	io___22.ciunit = *in;
	s_rsfe(&io___22);
	for (i4 = 291; i4 <= 299; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_2.conco[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 10) {
	io___23.ciunit = *in;
	s_rsfe(&io___23);
	for (i4 = 291; i4 <= 300; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_2.conco[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    i__1 = i3;
    for (i4 = 1; i4 <= i__1; ++i4) {
	k1 = i4 + i2;
/* L802: */
	fld8_block5_2.conco[k1 - 1] = fld8_block5_2.conco[i4 + 289];
    }
    i1 += -10;
    if (i1 < 1) {
	goto L803;
    }
    i2 += 10;
    goto L801;
L803:
    return 0;
} /* cooco_ */

/* Subroutine */ int digit_(integer *npnts, integer *in, real *sorig, integer 
	*inpos)
{
    /* Format strings */
    static char fmt_51[] = "(2f7.0)";
    static char fmt_52[] = "(4f7.0)";
    static char fmt_53[] = "(6f7.0)";
    static char fmt_54[] = "(8f7.0)";
    static char fmt_55[] = "(10f7.0)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void);
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    static real e1, e2, e3;
    static integer i1, i2, i3, i4, k1, i7;
    static real xc, yc, ange, rarc, angs;
    static integer nparc;

    /* Fortran I/O blocks */
    static cilist io___28 = { 0, 0, 0, fmt_51, 0 };
    static cilist io___30 = { 0, 0, 0, fmt_52, 0 };
    static cilist io___31 = { 0, 0, 0, fmt_53, 0 };
    static cilist io___32 = { 0, 0, 0, fmt_54, 0 };
    static cilist io___33 = { 0, 0, 0, fmt_55, 0 };


/* L51: */
/* L52: */
/* L53: */
/* L54: */
/* L55: */
    if (*inpos == 0) {
	goto L800;
    }
    i2 = *npnts << 1;
    i__1 = i2;
    for (i1 = 1; i1 <= i__1; ++i1) {
	++(*inpos);
/* L799: */
	fld8_block5_1.digln[i1 - 1] = fld8_block1_1.tri[*inpos + 59301];
    }
    goto L803;
L800:
    i1 = *npnts;
    i2 = 0;
L801:
    i3 = i1;
    if (i3 > 5) {
	i3 = 5;
    }
    if (i3 == 1) {
	io___28.ciunit = *in;
	s_rsfe(&io___28);
	for (i4 = 291; i4 <= 292; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_1.digln[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 2) {
	io___30.ciunit = *in;
	s_rsfe(&io___30);
	for (i4 = 291; i4 <= 294; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_1.digln[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 3) {
	io___31.ciunit = *in;
	s_rsfe(&io___31);
	for (i4 = 291; i4 <= 296; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_1.digln[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 4) {
	io___32.ciunit = *in;
	s_rsfe(&io___32);
	for (i4 = 291; i4 <= 298; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_1.digln[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    if (i3 == 5) {
	io___33.ciunit = *in;
	s_rsfe(&io___33);
	for (i4 = 291; i4 <= 300; ++i4) {
	    do_fio(&fld8_c__1, (char *)&fld8_block5_1.digln[i4 - 1], (ftnlen)sizeof(
		    real));
	}
	e_rsfe();
    }
    for (i4 = 1; i4 <= 10; ++i4) {
	k1 = i4 + i2;
/* L802: */
	fld8_block5_1.digln[k1 - 1] = fld8_block5_1.digln[i4 + 289];
    }
    i1 += -5;
    if (i1 < 1) {
	goto L803;
    }
    i2 += 10;
    goto L801;
L803:
    i__1 = *npnts;
    for (i1 = 1; i1 <= i__1; ++i1) {
	if (fld8_block5_1.digln[(i1 << 1) - 2] == 9e3f) {
	    goto L807;
	}
/* L806: */
    }
    goto L897;
L807:
    if (fld8_block5_1.digln[(i1 << 1) - 1] != 1.f) {
	goto L824;
    }
/* --- CIRCULAR ARC */
/* --- NUMBER OF POINTS (GREATER OR EQUAL TO THREE) */
    nparc = fld8_block5_1.digln[i1 * 2];
/* --- RADIUS */
    rarc = fld8_block5_1.digln[(i1 << 1) + 1];
/* --- CENTER */
    xc = fld8_block5_1.digln[(i1 << 1) + 2];
    yc = fld8_block5_1.digln[(i1 << 1) + 3];
/* --- ANGLE, START AND END */
    angs = fld8_block5_1.digln[(i1 << 1) + 4] * 3.1415927f / 180.f;
    ange = fld8_block5_1.digln[(i1 << 1) + 5] * 3.1415927f / 180.f;
/* --- NEW TOTAL NUMBER OF POINTS */
    *npnts = *npnts + nparc - 4;
    if (*npnts > 150) {
	goto L899;
    }
    if (*npnts == i1 - 1 + nparc) {
	goto L822;
    }
    i2 = i1 + 4;
    i7 = *npnts - nparc + 4;
    if (nparc >= 5) {
	goto L809;
    }
    i__1 = i7;
    for (i3 = i2; i3 <= i__1; ++i3) {
	i4 = i3 + nparc - 4;
	fld8_block5_1.digln[(i4 << 1) - 2] = fld8_block5_1.digln[(i3 << 1) - 2];
/* L808: */
	fld8_block5_1.digln[(i4 << 1) - 1] = fld8_block5_1.digln[(i3 << 1) - 1];
    }
    goto L822;
L809:
    i__1 = i2;
    for (i3 = i7; i3 >= i__1; --i3) {
	i4 = i3 + nparc - 4;
	fld8_block5_1.digln[(i4 << 1) - 2] = fld8_block5_1.digln[(i3 << 1) - 2];
/* L821: */
	fld8_block5_1.digln[(i4 << 1) - 1] = fld8_block5_1.digln[(i3 << 1) - 1];
    }
/* --- ANGLE BETWEEN POINTS */
L822:
    e1 = (ange - angs) / ((real) nparc - 1.f);
    i__1 = nparc;
    for (i2 = 1; i2 <= i__1; ++i2) {
	i3 = i1 - 1 + i2;
	e2 = angs + ((real) i2 - 1.f) * e1;
	fld8_block5_1.digln[(i3 << 1) - 2] = xc + rarc * cos(e2);
/* L823: */
	fld8_block5_1.digln[(i3 << 1) - 1] = yc + rarc * sin(e2);
    }
    goto L803;
L824:
    if (fld8_block5_1.digln[1] != 2.f) {
	goto L826;
    }
/* --- RECTANGLES WITH HORIZONTAL AND VERTICAL SIDES */
    *npnts = 5;
    fld8_block5_1.digln[0] = fld8_block5_1.digln[2];
    fld8_block5_1.digln[1] = fld8_block5_1.digln[3];
    fld8_block5_1.digln[2] = fld8_block5_1.digln[4];
    fld8_block5_1.digln[6] = fld8_block5_1.digln[0];
    fld8_block5_1.digln[7] = fld8_block5_1.digln[5];
    fld8_block5_1.digln[8] = fld8_block5_1.digln[0];
    fld8_block5_1.digln[9] = fld8_block5_1.digln[1];
    goto L897;
L826:
    if (fld8_block5_1.digln[1] != 4.f) {
	goto L828;
    }
/* --- SHARP RIGHT ANGLE */
    *npnts = 7;
    e1 = 1.f;
    if (fld8_block5_1.digln[4] < fld8_block5_1.digln[2]) {
	e1 = -1.f;
    }
    e3 = 1.f;
    if (fld8_block5_1.digln[5] < fld8_block5_1.digln[3]) {
	e3 = -1.f;
    }
    fld8_block5_1.digln[0] = fld8_block5_1.digln[2];
    fld8_block5_1.digln[1] = fld8_block5_1.digln[3] + fld8_block5_1.digln[6] * e3;
    fld8_block5_1.digln[8] = fld8_block5_1.digln[4] - fld8_block5_1.digln[7] * e1;
    fld8_block5_1.digln[9] = fld8_block5_1.digln[5];
    fld8_block5_1.digln[6] = fld8_block5_1.digln[4];
    fld8_block5_1.digln[7] = fld8_block5_1.digln[5];
    fld8_block5_1.digln[4] = fld8_block5_1.digln[6];
    fld8_block5_1.digln[5] = fld8_block5_1.digln[3];
    fld8_block5_1.digln[10] = fld8_block5_1.digln[8];
    fld8_block5_1.digln[11] = fld8_block5_1.digln[1];
    fld8_block5_1.digln[12] = fld8_block5_1.digln[0];
    fld8_block5_1.digln[13] = fld8_block5_1.digln[1];
    goto L897;
L828:
    if (fld8_block5_1.digln[1] != 5.f) {
	goto L833;
    }
/* --- CURVED RIGHT ANGLE */
    *npnts = 20;
    e1 = 1.f;
    if (fld8_block5_1.digln[4] < fld8_block5_1.digln[2]) {
	e1 = -1.f;
    }
    e3 = 1.f;
    if (fld8_block5_1.digln[5] < fld8_block5_1.digln[3]) {
	e3 = -1.f;
    }
    e2 = fld8_block5_1.digln[6];
    fld8_block5_1.digln[0] = fld8_block5_1.digln[2];
    fld8_block5_1.digln[1] = fld8_block5_1.digln[3] + e2 * e3;
    fld8_block5_1.digln[20] = fld8_block5_1.digln[4];
    fld8_block5_1.digln[21] = fld8_block5_1.digln[5];
    fld8_block5_1.digln[22] = fld8_block5_1.digln[4] - e1 * e2;
    fld8_block5_1.digln[23] = fld8_block5_1.digln[5];
    fld8_block5_1.digln[38] = fld8_block5_1.digln[0];
    fld8_block5_1.digln[39] = fld8_block5_1.digln[1];
    rarc = fld8_block5_1.digln[7];
    xc = fld8_block5_1.digln[22] - rarc * e1;
    yc = fld8_block5_1.digln[1] + rarc * e3;
    for (i1 = 3; i1 <= 10; ++i1) {
	fld8_block5_1.digln[(i1 << 1) - 2] = xc + (rarc + e2) * e1 * sin((real) (
		i1 - 3) * .22439948f);
/* L829: */
	fld8_block5_1.digln[(i1 << 1) - 1] = yc - (rarc + e2) * e3 * cos((real) (
		i1 - 3) * .22439948f);
    }
    for (i1 = 13; i1 <= 19; ++i1) {
	fld8_block5_1.digln[(i1 << 1) - 2] = xc + rarc * e1 * cos((real) (i1 - 13) 
		* .26179939f);
/* L832: */
	fld8_block5_1.digln[(i1 << 1) - 1] = yc - rarc * e3 * sin((real) (i1 - 13) 
		* .26179939f);
    }
    goto L897;
/* --- OTHER PREPROGRAMMED LINES CAN BE ADDED HERE */
L833:
L897:
    i1 = *npnts << 1;
    i__1 = i1;
    for (i4 = 1; i4 <= i__1; ++i4) {
/* L898: */
	fld8_block5_1.digln[i4 - 1] /= *sorig;
    }
L899:
    return 0;
} /* digit_ */

/* Subroutine */ int inter_(integer *intor, integer *i1, integer *lpnt, real *
	x, real *y)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, n1, n3;
    static real x1, y1, x2, y2, x3, y3;

/* --- SETS INTOR=1 FOR INTERIOR POINTS, OTHERWISE INTOR=0 */
    *intor = 0;
    n3 = 0;
L810:
    for (i__ = 1; i__ <= 4; ++i__) {
/* L811: */
	fld8_block6_1.ntri[i__ - 1] = 0;
    }
    i__1 = *i1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	n1 = (*lpnt + i__) << 1;
	x1 = fld8_block2_1.linc[n1 - 2];
	y1 = fld8_block2_1.linc[n1 - 1];
	x2 = fld8_block2_1.linc[n1];
	y2 = fld8_block2_1.linc[n1 + 1];
	if (*y < dmin(y1,y2) || *y > dmax(y1,y2) || y1 == y2) {
	    goto L812;
	}
	x3 = (*y - y1) * (x2 - x1) / (y2 - y1) + x1;
	if (*x > x3 - .01f && *x < x3 + .01f) {
	    goto L816;
	}
	if (*y == y1) {
	    goto L812;
	}
	if (x3 < *x) {
	    ++fld8_block6_1.ntri[0];
	}
	if (x3 > *x) {
	    ++fld8_block6_1.ntri[1];
	}
L812:
	if (*x < dmin(x1,x2) || *x > dmax(x1,x2) || x1 == x2) {
	    goto L813;
	}
	y3 = (*x - x1) * (y2 - y1) / (x2 - x1) + y1;
	if (*y > y3 - .01f && *y < y3 + .01f) {
	    goto L816;
	}
	if (*x == x1) {
	    goto L813;
	}
	if (y3 < *y) {
	    ++fld8_block6_1.ntri[2];
	}
	if (y3 > *y) {
	    ++fld8_block6_1.ntri[3];
	}
L813:
	for (n1 = 1; n1 <= 4; ++n1) {
	    if (fld8_block6_1.ntri[n1 - 1] == 2) {
		fld8_block6_1.ntri[n1 - 1] = 0;
	    }
/* L814: */
	}
/* L815: */
    }
    n1 = fld8_block6_1.ntri[0] + fld8_block6_1.ntri[1] + fld8_block6_1.ntri[2] + 
	    fld8_block6_1.ntri[3];
    if (n1 >= 3) {
	goto L817;
    }
    if (n1 == 0 || n3 == 1) {
	goto L816;
    }
/* --- TEST INCONCLUSIVE. MOVE POINT SLIGHTLY AND TRY AGAIN. */
    *x += .01f;
    *y += .01f;
    n3 = 1;
    goto L810;
L817:
    *intor = 1;
L816:
    return 0;
} /* inter_ */

/* Subroutine */ int incur_(integer *msize, complex *amat, complex *ainv)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    complex q__1, q__2;

    /* Builtin functions */
    void c_div(complex *, complex *, complex *);

    /* Local variables */
    static integer in1, in2, in3, in4, in5;
    static complex emat;

/* --- INVERSION OF UP TO A 10*10 MATRIX WITH COMPLEX ELEMENTS */
/* --- BY ROW TRANSFORMATIONS (GE NUMERICAL ANALYSIS COURSE, CHAPTER 5) */
    /* Parameter adjustments */
    ainv -= 11;
    amat -= 11;

    /* Function Body */
    for (in1 = 1; in1 <= 10; ++in1) {
	for (in2 = 1; in2 <= 10; ++in2) {
/* L5: */
	    i__1 = in1 + in2 * 10;
	    ainv[i__1].r = 0.f, ainv[i__1].i = 0.f;
	}
/* L6: */
	i__1 = in1 + 10;
	ainv[i__1].r = -1.f, ainv[i__1].i = 0.f;
    }
    in1 = *msize - 1;
/* --- ROW NUMBER TO BE TRIANGULATED */
    in3 = 1;
/* --- FIRST ELEMENT */
L10:
    i__1 = in3 + 10;
    emat.r = amat[i__1].r, emat.i = amat[i__1].i;
/* --- DIVIDE BY FIRST ELEMENT */
    i__1 = in1;
    for (in4 = 1; in4 <= i__1; ++in4) {
/* L11: */
	i__2 = in3 + in4 * 10;
	c_div(&q__1, &amat[in3 + (in4 + 1) * 10], &emat);
	amat[i__2].r = q__1.r, amat[i__2].i = q__1.i;
    }
    i__2 = in3 + *msize * 10;
    c_div(&q__1, &fld8_c_b98, &emat);
    amat[i__2].r = q__1.r, amat[i__2].i = q__1.i;
/* --- ESTABLISH ZEROS IN COLUMN IN3 OF ROW NUMBER IN4 */
    in4 = in3 + 1;
    if (in4 > *msize) {
	goto L14;
    }
L12:
    i__2 = in4 + 10;
    q__1.r = -amat[i__2].r, q__1.i = -amat[i__2].i;
    emat.r = q__1.r, emat.i = q__1.i;
    i__2 = in1;
    for (in5 = 1; in5 <= i__2; ++in5) {
/* L13: */
	i__1 = in4 + in5 * 10;
	i__3 = in3 + in5 * 10;
	q__2.r = amat[i__3].r * emat.r - amat[i__3].i * emat.i, q__2.i = amat[
		i__3].r * emat.i + amat[i__3].i * emat.r;
	i__4 = in4 + (in5 + 1) * 10;
	q__1.r = q__2.r + amat[i__4].r, q__1.i = q__2.i + amat[i__4].i;
	amat[i__1].r = q__1.r, amat[i__1].i = q__1.i;
    }
    i__1 = in4 + *msize * 10;
    i__3 = in3 + *msize * 10;
    q__1.r = amat[i__3].r * emat.r - amat[i__3].i * emat.i, q__1.i = amat[
	    i__3].r * emat.i + amat[i__3].i * emat.r;
    amat[i__1].r = q__1.r, amat[i__1].i = q__1.i;
    ++in4;
    if (in4 <= *msize) {
	goto L12;
    }
/* --- ROW NUMBER IN ARRAY AINV */
L14:
    in4 = 1;
L15:
    i__1 = in4 + 10;
    q__1.r = -ainv[i__1].r, q__1.i = -ainv[i__1].i;
    emat.r = q__1.r, emat.i = q__1.i;
    i__1 = in1;
    for (in5 = 1; in5 <= i__1; ++in5) {
/* L16: */
	i__3 = in4 + in5 * 10;
	i__4 = in3 + in5 * 10;
	q__2.r = amat[i__4].r * emat.r - amat[i__4].i * emat.i, q__2.i = amat[
		i__4].r * emat.i + amat[i__4].i * emat.r;
	i__2 = in4 + (in5 + 1) * 10;
	q__1.r = q__2.r + ainv[i__2].r, q__1.i = q__2.i + ainv[i__2].i;
	ainv[i__3].r = q__1.r, ainv[i__3].i = q__1.i;
    }
    i__3 = in4 + *msize * 10;
    i__4 = in3 + *msize * 10;
    q__1.r = amat[i__4].r * emat.r - amat[i__4].i * emat.i, q__1.i = amat[
	    i__4].r * emat.i + amat[i__4].i * emat.r;
    ainv[i__3].r = q__1.r, ainv[i__3].i = q__1.i;
    ++in4;
    if (in4 <= in3) {
	goto L15;
    }
    ++in3;
    if (in3 <= *msize) {
	goto L10;
    }
    return 0;
} /* incur_ */

integer novx1_(integer *i__, integer *lnhor, integer *lnver, real *per)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer m5, n5;

/* --- CONVERSION FROM VERTEX NUMBER IN ARRAY COEFF TO THAT OF VERT */
    if (*per == 1.f || *per == 3.f) {
	goto L90;
    }
    if (*per == 0.f && *lnver <= *lnhor) {
	goto L90;
    }
    m5 = (integer) ((real) (*i__) / (real) (*lnhor) + .999f);
    n5 = *i__ - (m5 - 1) * *lnhor;
    ret_val = (*lnhor - n5) * *lnver + m5;
    return ret_val;
L90:
    ret_val = *i__;
    return ret_val;
} /* novx1_ */

integer novx2_(integer *i__, integer *lnhor, integer *lnver, real *per)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer m5, n5;

/* --- CONVERSION FROM VERTEX NUMBER IN ARRAY VERT TO THAT OF COEFF */
    if (*per == 1.f || *per == 3.f) {
	goto L91;
    }
    if (*per == 0.f && *lnver <= *lnhor) {
	goto L91;
    }
    m5 = (integer) ((real) (*i__) / (real) (*lnver) + .999f);
    n5 = *i__ - (m5 - 1) * *lnver;
    ret_val = n5 * *lnhor - m5 + 1;
    return ret_val;
L91:
    ret_val = *i__;
    return ret_val;
} /* novx2_ */

/* Subroutine */ int angle_(real *a1, real *b1, real *d1, real *angrd, real *
	pi)
{
    /* Builtin functions */
    double atan(doublereal);

    *angrd = 0.f;
    if (dabs(*a1) < 1e-9f && dabs(*b1) < 1e-9f) {
	goto L92;
    }
    *angrd = *pi / 2.f;
    if (*a1 < 0.f) {
	*angrd = -(*angrd);
    }
    if (dabs(*b1) > 1e-9f) {
	*angrd = atan(*a1 / *b1);
    }
    if (*b1 < 0.f) {
	*angrd += *pi;
    }
    *angrd = *d1 * *angrd;
L92:
    return 0;
} /* angle_ */

/* Subroutine */ int cmang_(complex *c1, real *ang, complex *c2, real *pi)
{
    /* System generated locals */
    complex q__1;

    /* Builtin functions */
    double r_imag(complex *), cos(doublereal), sin(doublereal);

    /* Local variables */
    static real ca, ci, cr;
    extern doublereal absc_(complex *);
    extern /* Subroutine */ int angle_(real *, real *, real *, real *, real *)
	    ;
    static real angrd;

/* --- ROTATES THE VECTOR C1 BY AN ANGLE ANG INTO C2 */
    cr = c1->r;
    ci = r_imag(c1);
    angle_(&ci, &cr, &fld8_c_b111, &angrd, pi);
    angrd += *ang;
    ca = absc_(c1);
    cr = ca * cos(angrd);
    ci = ca * sin(angrd);
    q__1.r = cr, q__1.i = ci;
    c2->r = q__1.r, c2->i = q__1.i;
    return 0;
} /* cmang_ */

doublereal absc_(complex *c2)
{
    /* System generated locals */
    real ret_val, r__1, r__2;

    /* Builtin functions */
    double r_imag(complex *), c_abs(complex *);

/* --- FINDS ABSOLUTE VALUE OF COMPLEX VARIABLE */
    ret_val = 0.f;
    if ((r__1 = c2->r, dabs(r__1)) > 1e-20f || (r__2 = r_imag(c2), dabs(r__2))
	     > 1e-20f) {
	ret_val = c_abs(c2);
    }
    return ret_val;
} /* absc_ */

/* Subroutine */ int bufr_(integer *n1, integer *n2, integer *n3, integer *
	mass)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    alist al__1;

    /* Builtin functions */
    integer s_wsue(cilist *), do_uio(integer *, char *, ftnlen), e_wsue(void),
	     f_back(alist *), s_rsue(cilist *), e_rsue(void);

    /* Local variables */
    static integer n8, n9;

    /* Fortran I/O blocks */
    static cilist io___69 = { 0, 0, 0, 0, 0 };
    static cilist io___71 = { 0, 0, 0, 0, 0 };


/* --- TRANSMITS N1 LINES TO OR FROM MASS STORAGE IN BLOCKS OF 10, WITH */
/* --- N2 WORDS PER LINE. N3=1 MEANS INFORMATION IN, N3=2 INFORMATION OUT */
/* --- READ FORWARDS, AND N3=3 INFORMATION OUT READ BACKWARDS. N4 IS A */
/* --- COUNTER WHICH KEEPS TRACK OF THE LINE NUMBER, AND N5 KEEPS TRACK */
/* --- OF THE NUMBER OF BLOCK TRANSFERS. N4 MUST BE INITIATED TO ONE */
/* --- BEFORE THE FIRST TIME THE SUBROUTINE IS CALLED. THE LINE TO BE */
/* --- TRANSMITTED IS PUT IN ARRAY BUFFA. */
    if (fld8_block9_1.n4 == 1) {
	fld8_block9_1.n5 = 0;
    }
/* --- N6 IS THE LINE NUMBER IN ARRAY BUFFB */
    if (fld8_block9_1.n4 == 1) {
	fld8_block9_1.n6 = 1;
    }
/* --- N7 IS A LIMIT WHICH TRIGGERS THE TRANSFER TO OR FROM MASS STORAGE */
    if (*n3 != 3) {
	fld8_block9_1.n7 = 10;
    }
    n8 = *n1 - fld8_block9_1.n4 + fld8_block9_1.n6;
    if (fld8_block9_1.n7 > n8) {
	fld8_block9_1.n7 = n8;
    }
    if (*n3 != 1) {
	goto L432;
    }
    i__1 = *n2;
    for (n8 = 1; n8 <= i__1; ++n8) {
/* L431: */
	i__2 = n8 + fld8_block9_1.n6 * 175 - 176;
	i__3 = n8 - 1;
	fld8_block9_1.buffb[i__2].r = fld8_block9_1.buffa[i__3].r, fld8_block9_1.buffb[i__2]
		.i = fld8_block9_1.buffa[i__3].i;
    }
    if (fld8_block9_1.n6 != fld8_block9_1.n7) {
	goto L436;
    }
    io___69.ciunit = *mass;
    s_wsue(&io___69);
    i__2 = fld8_block9_1.n7;
    for (n9 = 1; n9 <= i__2; ++n9) {
	i__3 = *n2;
	for (n8 = 1; n8 <= i__3; ++n8) {
	    do_uio(&fld8_c__2, (char *)&fld8_block9_1.buffb[n8 + n9 * 175 - 176], (
		    ftnlen)sizeof(real));
	}
    }
    e_wsue();
    ++fld8_block9_1.n5;
    fld8_block9_1.n6 = 0;
    goto L436;
L432:
    if (fld8_block9_1.n6 != 1) {
	goto L433;
    }
    if (*n3 == 3) {
	al__1.aerr = 0;
	al__1.aunit = *mass;
	f_back(&al__1);
    }
    io___71.ciunit = *mass;
    s_rsue(&io___71);
    i__3 = fld8_block9_1.n7;
    for (n9 = 1; n9 <= i__3; ++n9) {
	i__2 = *n2;
	for (n8 = 1; n8 <= i__2; ++n8) {
	    do_uio(&fld8_c__2, (char *)&fld8_block9_1.buffb[n8 + n9 * 175 - 176], (
		    ftnlen)sizeof(real));
	}
    }
    e_rsue();
    if (*n3 == 3) {
	al__1.aerr = 0;
	al__1.aunit = *mass;
	f_back(&al__1);
    }
    ++fld8_block9_1.n5;
L433:
    n9 = fld8_block9_1.n6;
    if (*n3 == 3) {
	n9 = fld8_block9_1.n7 + 1 - fld8_block9_1.n6;
    }
    i__2 = *n2;
    for (n8 = 1; n8 <= i__2; ++n8) {
/* L434: */
	i__3 = n8 - 1;
	i__1 = n8 + n9 * 175 - 176;
	fld8_block9_1.buffa[i__3].r = fld8_block9_1.buffb[i__1].r, fld8_block9_1.buffa[i__3]
		.i = fld8_block9_1.buffb[i__1].i;
    }
    if (fld8_block9_1.n6 == fld8_block9_1.n7) {
	fld8_block9_1.n6 = 0;
    }
    if (fld8_block9_1.n6 == 0) {
	fld8_block9_1.n7 = 10;
    }
L436:
    ++fld8_block9_1.n4;
    if (fld8_block9_1.n4 > *n1) {
	fld8_block9_1.n4 = 1;
    }
    ++fld8_block9_1.n6;
    return 0;
} /* bufr_ */

/* Subroutine */ int sivert_(integer *i__, integer *j, integer *l)
{
    static integer k;

/* --- SETS DATA IN ARRAY IBIT */
    k = *l;
    if (*j > 8) {
	goto L100;
    }
    if (k == 0) {
	fld8_block8_1.ibit[*i__ - 1] = bit_clear(fld8_block8_1.ibit[*i__ - 1],*j - 1);
    }
    if (k != 0) {
	fld8_block8_1.ibit[*i__ - 1] = bit_set(fld8_block8_1.ibit[*i__ - 1],*j - 1);
    }
    goto L200;
L100:
    if (*j != 9) {
	goto L150;
    }
    if (k < 16) {
	fld8_block8_1.ibit[*i__ - 1] = bit_clear(fld8_block8_1.ibit[*i__ - 1],12);
    }
    if (k >= 16) {
	fld8_block8_1.ibit[*i__ - 1] = bit_set(fld8_block8_1.ibit[*i__ - 1],12);
    }
    if (k >= 16) {
	k += -16;
    }
    if (k < 8) {
	fld8_block8_1.ibit[*i__ - 1] = bit_clear(fld8_block8_1.ibit[*i__ - 1],11);
    }
    if (k >= 8) {
	fld8_block8_1.ibit[*i__ - 1] = bit_set(fld8_block8_1.ibit[*i__ - 1],11);
    }
    if (k >= 8) {
	k += -8;
    }
    if (k < 4) {
	fld8_block8_1.ibit[*i__ - 1] = bit_clear(fld8_block8_1.ibit[*i__ - 1],10);
    }
    if (k >= 4) {
	fld8_block8_1.ibit[*i__ - 1] = bit_set(fld8_block8_1.ibit[*i__ - 1],10);
    }
    if (k >= 4) {
	k += -4;
    }
L150:
    if (k < 2) {
	fld8_block8_1.ibit[*i__ - 1] = bit_clear(fld8_block8_1.ibit[*i__ - 1],*j * 5 - 
		36);
    }
    if (k >= 2) {
	fld8_block8_1.ibit[*i__ - 1] = bit_set(fld8_block8_1.ibit[*i__ - 1],*j * 5 - 36)
		;
    }
    if (k >= 2) {
	k += -2;
    }
    if (k == 0) {
	fld8_block8_1.ibit[*i__ - 1] = bit_clear(fld8_block8_1.ibit[*i__ - 1],*j * 5 - 
		37);
    }
    if (k == 1) {
	fld8_block8_1.ibit[*i__ - 1] = bit_set(fld8_block8_1.ibit[*i__ - 1],*j * 5 - 37)
		;
    }
L200:
    return 0;
} /* sivert_ */

integer ivert_(integer *i__, integer *j)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static logical1 a1, a2, a3, a4, a5;

/* --- RECREATES VALUES IN THE OLD ARRAY IVERT */
    ret_val = 0;
    if (*j > 8) {
	goto L110;
    }
    a1 = bit_test(fld8_block8_1.ibit[*i__ - 1],*j - 1);
    if (a1) {
	goto L100;
    }
    goto L200;
L100:
    if (*j == 1) {
	ret_val = *i__ - 1;
    }
    if (*j == 2) {
	ret_val = *i__ - fld8_block1_1.lnver - 1;
    }
    if (*j == 3) {
	ret_val = *i__ - fld8_block1_1.lnver;
    }
    if (*j == 4) {
	ret_val = *i__ - fld8_block1_1.lnver + 1;
    }
    if (*j == 5) {
	ret_val = *i__ + 1;
    }
    if (*j == 6) {
	ret_val = *i__ + fld8_block1_1.lnver + 1;
    }
    if (*j == 7) {
	ret_val = *i__ + fld8_block1_1.lnver;
    }
    if (*j == 8) {
	ret_val = *i__ + fld8_block1_1.lnver - 1;
    }
    goto L200;
L110:
    if (*j != 9) {
	goto L150;
    }
    a1 = bit_test(fld8_block8_1.ibit[*i__ - 1],12);
    a2 = bit_test(fld8_block8_1.ibit[*i__ - 1],11);
    a3 = bit_test(fld8_block8_1.ibit[*i__ - 1],10);
    if (a1) {
	ret_val = 16;
    }
    if (a2) {
	ret_val += 8;
    }
    if (a3) {
	ret_val += 4;
    }
L150:
    a4 = bit_test(fld8_block8_1.ibit[*i__ - 1],*j * 5 - 36);
    a5 = bit_test(fld8_block8_1.ibit[*i__ - 1],*j * 5 - 37);
    if (a4) {
	ret_val += 2;
    }
    if (a5) {
	++ret_val;
    }
L200:
    return ret_val;
} /* ivert_ */

/* Subroutine */ int sitri_(integer *i__, integer *j)
{
    static integer k, l, m, n;

/* --- SETS DIRECTION OF DIAGONAL IN ARRAY IBIT */
/* --- SKIP IF THE SECOND TRIANGLE IN A MESH */
    if (*i__ / 2 << 1 == *i__) {
	goto L200;
    }
/* --- ROW NUMBER */
    k = *i__ - 1;
    m = k / ((fld8_block1_1.lnver - 1) << 1) + 1;
/* --- COLUMN NUMBER */
    n = k / 2 + fld8_block1_1.lnver - m * (fld8_block1_1.lnver - 1);
/* --- LOWER LEFT CORNER */
    l = n + (m - 1) * fld8_block1_1.lnver;
    if (*j == 0) {
	fld8_block8_1.ibit[l - 1] = bit_clear(fld8_block8_1.ibit[l - 1],15);
    }
    if (*j == 1) {
	fld8_block8_1.ibit[l - 1] = bit_set(fld8_block8_1.ibit[l - 1],15);
    }
L200:
    return 0;
} /* sitri_ */

integer itri_(integer *i__, integer *j)
{
    /* System generated locals */
    integer ret_val = 0;

    /* Local variables */
    static logical1 a;
    static integer l, m, n;

/* --- RECREATES VALUES IN THE OLD ARRAY ITRI */
/* --- ROW NUMBER */
    m = (*i__ - 1) / ((fld8_block1_1.lnver - 1) << 1) + 1;
/* --- COLUMN NUMBER */
    n = (*i__ - 1) / 2 + fld8_block1_1.lnver - m * (fld8_block1_1.lnver - 1);
/* --- LOWER LEFT CORNER */
    l = n + (m - 1) * fld8_block1_1.lnver;
    a = bit_test(fld8_block8_1.ibit[l - 1],15);
    if (a) {
	goto L120;
    }
/* --- NORMAL DIAGONAL */
    if (*j == 1) {
	ret_val = l;
    }
    if (*i__ / 2 << 1 == *i__) {
	goto L110;
    }
/* --- FIRST TRIANGLE */
    if (*j == 2) {
	ret_val = l + fld8_block1_1.lnver + 1;
    }
    if (*j == 3) {
	ret_val = l + fld8_block1_1.lnver;
    }
    goto L200;
/* --- SECOND TRIANGLE */
L110:
    if (*j == 2) {
	ret_val = l + 1;
    }
    if (*j == 3) {
	ret_val = l + fld8_block1_1.lnver + 1;
    }
    goto L200;
/* --- REVERSED DIAGONAL */
L120:
    if (*j == 1) {
	ret_val = l + fld8_block1_1.lnver;
    }
    if (*i__ / 2 << 1 == *i__) {
	goto L110;
    }
/* --- FIRST TRIANGLE */
    if (*j == 2) {
	ret_val = l;
    }
    if (*j == 3) {
	ret_val = l + 1;
    }
L200:
    return ret_val;
} /* itri_ */

/* Subroutine */ int inpgn_(void)
{
    /* Local variables */
    static integer i__;
#define v ((real *)&fld8_block1_1 + 59984)

/* --- FOR CERTAIN APPLICATIONS, THE GRID GENERATION CAN BE MADE */
/* --- COMPLETELY AUTOMATIC FROM A GEOMETRY WHICH IS SPECIFIED IN A */
/* --- SIMPLIFIED MANNER AS INPUT TO THE SUBROUTINE. THE DATA MUST BE */
/* --- STORED CONSECUTIVELY IN ARRAY V IN THE SAME SEQUENCE AS THEY */
/* --- WOULD NORMALLY APPEAR ON INPUT LINE 3 AND THE FOLLOWING LINES. */
    for (i__ = 1; i__ <= 6300; ++i__) {
/* L100: */
	v[i__ - 1] = 0.f;
    }
/* --- THE USER'S PROGRAM COMES HERE */
    return 0;
} /* inpgn_ */

#undef v


/* Subroutine */ int outgn_(void)
{
    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2, r__3;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7;

    /* Builtin functions */
    double c_abs(complex *), r_imag(complex *), sin(doublereal), cos(
	    doublereal), sqrt(doublereal);

    /* Local variables */
    static real b, d__;
    static integer i__, l, m, n;
    static real e1, e2;
    static complex ac, al, am, an;
    static real rc;
    static complex bx, by;
    static real xl, yl, xm, ym, xn, yn, bxi, byi, bxr, byr, beta;
    extern /* Subroutine */ int subd_(real *, real *, real *, real *, real *, 
	    real *, real *);
    extern integer itri_(integer *, integer *);
    extern /* Subroutine */ int angle_(real *, real *, real *, real *, real *)
	    ;
    static real bxabs, byabs;

/* --- CAN BE USED TO GENERATE ADDITIONAL OUTPUT */
/* --- REMOVE TO ACTIVATE THE SUBROUTINE */
    if (fld8_block1_1.flaxi < 20.f) {
	goto L200;
    }
/* --- THE USER'S PROGRAM COMES HERE */
/* --- CALCULATIONS THAT ARE OFTEN REQUIRED */
    i__1 = fld8_block1_1.i5;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* --- NODE NUMBERS FOR TRIANGLE I */
	l = itri_(&i__, &fld8_c__1);
	m = itri_(&i__, &fld8_c__2);
	n = itri_(&i__, &fld8_c__3);
/* --- NODE COORDINATES, METERS */
	xl = fld8_block3_1.vert[l - 1];
	yl = fld8_block3_1.vert[l + 29999];
	xm = fld8_block3_1.vert[m - 1];
	ym = fld8_block3_1.vert[m + 29999];
	xn = fld8_block3_1.vert[n - 1];
	yn = fld8_block3_1.vert[n + 29999];
/* --- TWICE THE TRIANGLE AREA D, SQ.M */
	subd_(&d__, &xm, &ym, &xn, &yn, &xl, &yl);
/* --- VECTOR POTENTIALS */
	i__2 = l - 1;
	al.r = fld8_block3_1.cpot[i__2].r, al.i = fld8_block3_1.cpot[i__2].i;
	i__2 = m - 1;
	am.r = fld8_block3_1.cpot[i__2].r, am.i = fld8_block3_1.cpot[i__2].i;
	i__2 = n - 1;
	an.r = fld8_block3_1.cpot[i__2].r, an.i = fld8_block3_1.cpot[i__2].i;
/* --- VECTOR POTENTIAL AND RADIUS AT CENTROID */
	q__3.r = al.r + am.r, q__3.i = al.i + am.i;
	q__2.r = q__3.r + an.r, q__2.i = q__3.i + an.i;
	q__1.r = q__2.r / 3.f, q__1.i = q__2.i / 3.f;
	ac.r = q__1.r, ac.i = q__1.i;
	rc = (xl + xm + xn) / 3.f;
/* --- FLUX DENSITIES */
	r__1 = xm - xn;
	q__5.r = r__1 * al.r, q__5.i = r__1 * al.i;
	r__2 = xn - xl;
	q__6.r = r__2 * am.r, q__6.i = r__2 * am.i;
	q__4.r = q__5.r + q__6.r, q__4.i = q__5.i + q__6.i;
	r__3 = xl - xm;
	q__7.r = r__3 * an.r, q__7.i = r__3 * an.i;
	q__3.r = q__4.r + q__7.r, q__3.i = q__4.i + q__7.i;
	q__2.r = q__3.r / d__, q__2.i = q__3.i / d__;
	q__1.r = q__2.r * 1.4142136f, q__1.i = q__2.i * 1.4142136f;
	bx.r = q__1.r, bx.i = q__1.i;
	r__1 = ym - yn;
	q__5.r = r__1 * al.r, q__5.i = r__1 * al.i;
	r__2 = yn - yl;
	q__6.r = r__2 * am.r, q__6.i = r__2 * am.i;
	q__4.r = q__5.r + q__6.r, q__4.i = q__5.i + q__6.i;
	r__3 = yl - ym;
	q__7.r = r__3 * an.r, q__7.i = r__3 * an.i;
	q__3.r = q__4.r + q__7.r, q__3.i = q__4.i + q__7.i;
	q__2.r = q__3.r / d__, q__2.i = q__3.i / d__;
	q__1.r = q__2.r * 1.4142136f, q__1.i = q__2.i * 1.4142136f;
	by.r = q__1.r, by.i = q__1.i;
	if (fld8_block1_1.flaxi > 1.5f) {
	    q__3.r = ac.r / rc, q__3.i = ac.i / rc;
	    q__2.r = q__3.r * 1.4142136f, q__2.i = q__3.i * 1.4142136f;
	    q__1.r = by.r + q__2.r, q__1.i = by.i + q__2.i;
	    by.r = q__1.r, by.i = q__1.i;
	}
	bxabs = c_abs(&bx);
	byabs = c_abs(&by);
	bxr = bx.r;
	byr = by.r;
	bxi = r_imag(&bx);
	byi = r_imag(&by);
	angle_(&byi, &byr, &fld8_c_b111, &e1, &fld8_block7_1.pi);
	angle_(&bxi, &bxr, &fld8_c_b111, &e2, &fld8_block7_1.pi);
	beta = e1 - e2;
	e1 = byabs / 2.f * sin(beta);
/* Computing 2nd power */
	r__1 = byabs / 2.f * cos(beta);
	e2 = r__1 * r__1;
/* Computing 2nd power */
	r__1 = bxabs / 2.f - e1;
/* Computing 2nd power */
	r__2 = bxabs / 2.f + e1;
	b = sqrt(r__1 * r__1 + e2) + sqrt(r__2 * r__2 + e2);
/* L100: */
    }
L200:
    return 0;
} /* outgn_ */

/* Subroutine */ int ela_(void)
{
    /* Format strings */
    static char fmt_1[] = "(80a1/8f10.0)";
    static char fmt_2[] = "(8f10.0/8f10.0/8f10.0/8f10.0/8f10.0/8f10.0/8f10.0"
	    "/8f10.0)";
    static char fmt_3[] = "(4f10.0/4f10.0/4f10.0/3f10.0)";
    static char fmt_4[] = "(6f10.0)";
    static char fmt_5[] = "(\002PROGRAM FLD8\002,7x,\002SKIN EFFECT AND EDDY"
	    " CURRENTS\002//80a1//)";
    static char fmt_6[] = "(\002FLAT, TWO DIMENSIONAL FIELD\002)";
    static char fmt_7[] = "(\002AXI-SYMMETRIC FIELD\002/\002MINIMUM RADIU"
	    "S\002,f8.2)";
    static char fmt_8[] = "(\002SCALE, INPUT DRAWING\002,f7.3/\002NUMBER OF "
	    "PHASES\002,f4.1/\002RMS PHASE CURRENT\002,f10.2/\002FREQUENCY"
	    "\002,f9.2)";
    static char fmt_9[] = "(\002PERIODICITY CONDITION: YES\002/\002ANGULAR D"
	    "ISPLACEMENT\002,f8.2)";
    static char fmt_10[] = "(/\002POSITIONS, VERTICAL GRID LINES\002)";
    static char fmt_11[] = "(/\002POSITIONS, HORIZONTAL GRID LINES\002)";
    static char fmt_12[] = "(/\002SCALE, FLUX PLOT\002,f7.3/\002NUMBER OF FL"
	    "UX LINES\002,f5.1)";
    static char fmt_14[] = "(4x,\002X\002,8x,\002Y\002)";
    static char fmt_15[] = "(4x,\002R\002,8x,\002Z\002)";
    static char fmt_16[] = "(f8.2,f9.2)";
    static char fmt_17[] = "(/\002RELATIVE PERMEABILITY\002,f12.5)";
    static char fmt_18[] = "(\002DIRECTION OF PHASE CURRENT:  POSITIVE\002)";
    static char fmt_19[] = "(\002DIRECTION OF PHASE CURRENT:  NEGATIVE\002)";
    static char fmt_20[] = "(\002VECTOR POTENTIAL\002,1pe10.3)";
    static char fmt_21[] = "(\002CODE\002,f5.1)";
    static char fmt_22[] = "(\002CONDUCTIVITY, M/OHM*SQ.MM\002,f9.3/\002PHAS"
	    "E CONNECTION\002,f4.1)";
    static char fmt_23[] = "(\002CONDUCTIVITY, M/OHM*SQ.MM\002,f9.3/\002TOTA"
	    "L CURRENT\002,f10.2/\002PHASE ANGLE, DEGREES\002,f8.2)";
    static char fmt_27[] = "(80a1)";
    static char fmt_28[] = "(12f6.0)";
    static char fmt_30[] = "(\002VECTOR POTENTIAL, FIRST POINT\002,1pe11.3)";
    static char fmt_31[] = "(\002VECTOR POTENTIAL, SECOND POINT\002,1pe10.3)";
    static char fmt_32[] = "(\002PHASE ANGLE, DEGREES\002,f8.2)";
    static char fmt_40[] = "(i3,5x,10f7.1)";
    static char fmt_41[] = "(i3,\002-\002,i2,2x,10f7.1)";
    static char fmt_42[] = "(i3,\002-\002,i3,1x,10f7.1)";
    static char fmt_49[] = "(\002THE INPUT IS FOR A CLOSED CURVE, BUT THE LA"
	    "ST POINT ON THE CONTOUR LINE IS NOT\002/\002EQUAL TO THE FIRST"
	    ".\002)";
    static char fmt_50[] = "(\002THE LINE FITTING WAS INTERRUPTED FOR LINE S"
	    "EGMENT\002/\002   X(R)     Y(Z)\002/f8.2,f9.2/f8.2,f9.2/\002NEA"
	    "R\002/f8.2,f9.2)";
    static char fmt_51[] = "(/\002THIS POINT IS TOO CLOSE TO THE PRECEDING P"
	    "OINT\002/\002   X(R)     Y(Z)\002/f8.2,f9.2)";
    static char fmt_55[] = "(\002THE PROGRAM HAS MOVED NODE NO.\002,i6)";
    static char fmt_56[] = "(\002FROM ONE LINE TO ANOTHER LINE WHICH IS TOO "
	    "CLOSE\002)";
    static char fmt_57[] = "(\002FLAT, TWO DIMENSIONAL FIELD WITH INPUT IN M"
	    "ODIFIED POLAR COORDINATES.\002/\002Y-COORDINATES CORRESPOND TO R"
	    "ADIUS DIRECTLY. X-COORDINATES CORRESPOND TO\002/\002TANGENTIAL D"
	    "ISTANCE FROM THE LEFT BOUNDARY, NORMALIZED TO A ONE METER RADIUS."
	    "\002/\002POINTS WITH THE SAME X-COORDINATE THEREFORE LIE ON THE "
	    "SAME RADIAL LINE. IN THE\002/\002DETAILED OUTPUT FOR THE NODES A"
	    "ND THE TRIANGLES, POLAR COORDINATES HAVE BEEN\002/\002CHANGED TO"
	    " CARTESIAN COORDINATES WITH THE ORIGIN IN\r THE BOTTOM LEFT CORN"
	    "ER.\002//)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    real r__1, r__2, r__3, r__4, r__5, r__6, r__7, r__8, r__9, r__10, r__11, 
	    r__12;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_wsfe(cilist *), e_wsfe(void);
    double sqrt(doublereal), atan(doublereal), sin(doublereal), cos(
	    doublereal);

    /* Local variables */
    static real d__;
    static integer i__, j, k, l, m, n;
    static real x, y;
    static complex c1;
    static real e1, e2, e3, e4;
    static integer i1, i2, k1, i3;
    static real e5, e6, e7;
    static integer i4, i8, i9, n2, m1, j1, j2, n5, n6, n7, n8, j3, j4, n4, 
	    i10, in;
    static real xf, yf, xi, yi, xj, xl, yl, xm, ym, xn, yn, yj, tj1, ti4, dir;
    extern /* Subroutine */ int asp_(integer *, integer *, integer *, real *, 
	    real *);
    static real xpk, xpl, ypl, ypk, sxl, syl, pio2, code, cond;
    static integer icol;
    extern /* Subroutine */ int magn_(real *, real *, real *);
    static real delx, conn, dely, perm;
    extern integer itri_(integer *, integer *);
    static real xmin;
    static integer lpnt;
    static real xmax, ymin, tolr, ymax, pnts;
    static integer irow;
    static real xctr;
    static integer icode;
    static real alpha, facti;
    static integer linac;
    static real calph, asinb;
    extern /* Subroutine */ int digit_(integer *, integer *, real *, integer *
	    ), cooco_(integer *, integer *);
    static real salph;
    extern /* Subroutine */ int inpgn_(void);
    static integer lasti;
    static real nolin, sorig;
    static integer itmxi, inpos;
    static real yshft, verln, horln, xcorr;
    static integer npnts, norow;
    static real ycorr;
    extern /* Subroutine */ int sitri_(integer *, integer *);
    extern integer ivert_(integer *, integer *);
    extern /* Subroutine */ int inter_(integer *, integer *, integer *, real *
	    , real *);
    static integer intor;
    static real relaxi, dptmxi;
    extern /* Subroutine */ int sivert_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___117 = { 0, 8, 0, fmt_27, 0 };
    static cilist io___118 = { 0, 8, 0, fmt_27, 0 };
    static cilist io___119 = { 0, 8, 0, fmt_28, 0 };
    static cilist io___121 = { 0, 8, 0, fmt_27, 0 };
    static cilist io___122 = { 0, 8, 0, fmt_28, 0 };
    static cilist io___124 = { 0, 8, 0, fmt_27, 0 };
    static cilist io___125 = { 0, 8, 0, fmt_28, 0 };
    static cilist io___128 = { 0, 8, 0, fmt_27, 0 };
    static cilist io___129 = { 0, 8, 0, fmt_28, 0 };
    static cilist io___131 = { 0, 8, 0, fmt_27, 0 };
    static cilist io___132 = { 0, 8, 0, fmt_28, 0 };
    static cilist io___137 = { 0, 0, 0, fmt_1, 0 };
    static cilist io___140 = { 0, 0, 0, fmt_2, 0 };
    static cilist io___142 = { 0, 0, 0, fmt_5, 0 };
    static cilist io___143 = { 0, 0, 0, fmt_57, 0 };
    static cilist io___144 = { 0, 0, 0, fmt_6, 0 };
    static cilist io___145 = { 0, 0, 0, fmt_7, 0 };
    static cilist io___146 = { 0, 0, 0, fmt_8, 0 };
    static cilist io___147 = { 0, 0, 0, fmt_9, 0 };
    static cilist io___148 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___152 = { 0, 0, 0, fmt_2, 0 };
    static cilist io___158 = { 0, 0, 0, fmt_3, 0 };
    static cilist io___159 = { 0, 0, 0, fmt_40, 0 };
    static cilist io___160 = { 0, 0, 0, fmt_41, 0 };
    static cilist io___161 = { 0, 0, 0, fmt_42, 0 };
    static cilist io___162 = { 0, 0, 0, fmt_11, 0 };
    static cilist io___163 = { 0, 0, 0, fmt_40, 0 };
    static cilist io___164 = { 0, 0, 0, fmt_41, 0 };
    static cilist io___165 = { 0, 0, 0, fmt_42, 0 };
    static cilist io___166 = { 0, 0, 0, fmt_12, 0 };
    static cilist io___178 = { 0, 0, 0, fmt_4, 0 };
    static cilist io___203 = { 0, 0, 0, fmt_17, 0 };
    static cilist io___204 = { 0, 0, 0, fmt_22, 0 };
    static cilist io___205 = { 0, 0, 0, fmt_23, 0 };
    static cilist io___206 = { 0, 0, 0, fmt_18, 0 };
    static cilist io___207 = { 0, 0, 0, fmt_19, 0 };
    static cilist io___208 = { 0, 0, 0, fmt_20, 0 };
    static cilist io___209 = { 0, 0, 0, fmt_32, 0 };
    static cilist io___210 = { 0, 0, 0, fmt_30, 0 };
    static cilist io___211 = { 0, 0, 0, fmt_32, 0 };
    static cilist io___212 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___213 = { 0, 0, 0, fmt_32, 0 };
    static cilist io___214 = { 0, 0, 0, fmt_21, 0 };
    static cilist io___216 = { 0, 0, 0, fmt_14, 0 };
    static cilist io___217 = { 0, 0, 0, fmt_15, 0 };
    static cilist io___218 = { 0, 0, 0, fmt_16, 0 };
    static cilist io___223 = { 0, 0, 0, fmt_51, 0 };
    static cilist io___224 = { 0, 0, 0, fmt_55, 0 };
    static cilist io___225 = { 0, 0, 0, fmt_14, 0 };
    static cilist io___226 = { 0, 0, 0, fmt_15, 0 };
    static cilist io___227 = { 0, 0, 0, fmt_16, 0 };
    static cilist io___228 = { 0, 0, 0, fmt_56, 0 };
    static cilist io___242 = { 0, 0, 0, fmt_50, 0 };
    static cilist io___244 = { 0, 0, 0, fmt_55, 0 };
    static cilist io___245 = { 0, 0, 0, fmt_14, 0 };
    static cilist io___246 = { 0, 0, 0, fmt_15, 0 };
    static cilist io___249 = { 0, 0, 0, fmt_16, 0 };
    static cilist io___250 = { 0, 0, 0, fmt_56, 0 };
    static cilist io___251 = { 0, 0, 0, fmt_49, 0 };


/* --- SKIN EFFECT AND EDDY CURRENTS, PART 1 */
/* L1: */
/* L2: */
/* L3: */
/* L4: */
/* L5: */
/* L6: */
/* L7: */
/* L8: */
/* L9: */
/* L10: */
/* L11: */
/* L12: */
/* L14: */
/* L15: */
/* L16: */
/* L17: */
/* L18: */
/* L19: */
/* L20: */
/* L21: */
/* L22: */
/* L23: */
/* L27: */
/* L28: */
/* L30: */
/* L31: */
/* L32: */
/* L40: */
/* L41: */
/* L42: */
/* L49: */
/* L50: */
/* L51: */
/* L55: */
/* L56: */
/* L57: */
    for (i__ = 1; i__ <= 8; ++i__) {
	s_rsfe(&io___117);
	do_fio(&fld8_c__80, fld8_blck10_1.ident, (ftnlen)1);
	e_rsfe();
/* L96: */
    }
    for (i__ = 1; i__ <= 20; ++i__) {
	s_rsfe(&io___118);
	do_fio(&fld8_c__80, fld8_blck10_1.ident, (ftnlen)1);
	e_rsfe();
	s_rsfe(&io___119);
	for (j = 1; j <= 12; ++j) {
	    do_fio(&fld8_c__1, (char *)&fld8_blck11_1.atpcm[i__ + j * 20 - 21], (ftnlen)
		    sizeof(real));
	}
	e_rsfe();
/* L97: */
    }
    s_rsfe(&io___121);
    do_fio(&fld8_c__80, fld8_blck10_1.ident, (ftnlen)1);
    e_rsfe();
    s_rsfe(&io___122);
    do_fio(&fld8_c__1, (char *)&relaxi, (ftnlen)sizeof(real));
    e_rsfe();
    s_rsfe(&io___124);
    do_fio(&fld8_c__80, fld8_blck10_1.ident, (ftnlen)1);
    e_rsfe();
    s_rsfe(&io___125);
    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
    e_rsfe();
    itmxi = e1;
    s_rsfe(&io___128);
    do_fio(&fld8_c__80, fld8_blck10_1.ident, (ftnlen)1);
    e_rsfe();
    s_rsfe(&io___129);
    do_fio(&fld8_c__1, (char *)&dptmxi, (ftnlen)sizeof(real));
    e_rsfe();
    s_rsfe(&io___131);
    do_fio(&fld8_c__80, fld8_blck10_1.ident, (ftnlen)1);
    e_rsfe();
    s_rsfe(&io___132);
    do_fio(&fld8_c__1, (char *)&facti, (ftnlen)sizeof(real));
    e_rsfe();
    fld8_blck11_1.relax = 0.f;
    fld8_blck11_1.itmx = 0;
    fld8_blck11_1.dptmx = 0.f;
    fld8_blck11_1.fact = 1.f;
    fld8_block7_1.warn = 0;
    fld8_block1_1.i5 = 0;
    fld8_block1_1.i6 = 0;
    fld8_block1_1.linto = 0;
    fld8_block7_1.pi = 3.1415927f;
    pio2 = fld8_block7_1.pi / 2.f;
    yshft = 0.f;
/* --- PERMEABILITY OF FREE SPACE */
    fld8_block7_1.permo = fld8_block7_1.pi * 4.f * 1e-7f;
/* --- LOGICAL UNIT NUMBERS */
    fld8_block7_1.mass = 3;
    in = 2;
    fld8_block7_1.out = 7;
/* --- INITIALIZE NUMBER OF INDEPENDENT VOLTAGES AND SET NCOD3=0 */
    fld8_block1_1.nvolt = 0;
    fld8_block1_1.ncod3 = 0;
/* --- READ LINES 1 TO 10 */
    io___137.ciunit = in;
    s_rsfe(&io___137);
    do_fio(&fld8_c__80, fld8_blck10_1.ident, (ftnlen)1);
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.flaxi, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.rmin, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&sorig, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block7_1.phas, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block7_1.phcur, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.freq, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block7_1.per, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block7_1.displ, (ftnlen)sizeof(real));
    e_rsfe();
    inpos = 0;
    if (fld8_block1_1.flaxi > 9.f) {
	inpos = 1;
    }
    if (fld8_block1_1.flaxi > 9.f) {
	fld8_block1_1.flaxi += -10.f;
    }
    if (inpos == 0) {
	goto L100;
    }
/* L98: */
    inpos = 1;
    inpgn_();
    for (i__ = 1; i__ <= 64; ++i__) {
/* L99: */
	fld8_block7_1.pchv[i__ - 1] = fld8_block1_1.tri[i__ + 59301];
    }
    goto L101;
L100:
    io___140.ciunit = in;
    s_rsfe(&io___140);
    do_fio(&fld8_c__64, (char *)&fld8_block7_1.pchv[0], (ftnlen)sizeof(real));
    e_rsfe();
L101:
    tolr = .0099f / sorig;
/* --- WRITE FIRST PART OF INPUT */
    io___142.ciunit = fld8_block7_1.out;
    s_wsfe(&io___142);
    do_fio(&fld8_c__80, fld8_blck10_1.ident, (ftnlen)1);
    e_wsfe();
    if (fld8_block1_1.flaxi < .5f) {
	io___143.ciunit = fld8_block7_1.out;
	s_wsfe(&io___143);
	e_wsfe();
    }
    if (fld8_block1_1.flaxi == 1.f) {
	io___144.ciunit = fld8_block7_1.out;
	s_wsfe(&io___144);
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___145.ciunit = fld8_block7_1.out;
	s_wsfe(&io___145);
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.rmin, (ftnlen)sizeof(real));
	e_wsfe();
    }
    io___146.ciunit = fld8_block7_1.out;
    s_wsfe(&io___146);
    do_fio(&fld8_c__1, (char *)&sorig, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block7_1.phas, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block7_1.phcur, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.freq, (ftnlen)sizeof(real));
    e_wsfe();
    if (fld8_block7_1.per == 1.f || fld8_block7_1.per == 2.f) {
	io___147.ciunit = fld8_block7_1.out;
	s_wsfe(&io___147);
	do_fio(&fld8_c__1, (char *)&fld8_block7_1.displ, (ftnlen)sizeof(real));
	e_wsfe();
    }
    fld8_block7_1.displ = fld8_block7_1.displ * fld8_block7_1.pi / 180.f;
    io___148.ciunit = fld8_block7_1.out;
    s_wsfe(&io___148);
    e_wsfe();
    npnts = 64;
L102:
    if (fld8_block7_1.pchv[npnts - 1] > .5f) {
	goto L103;
    }
    --npnts;
    if (npnts >= 2) {
	goto L102;
    }
/* --- NUMBER OF VERTICAL LINES */
L103:
    verln = fld8_block7_1.pchv[npnts - 1];
    fld8_block1_1.lnver = verln;
    if (fld8_block1_1.lnver > 300) {
	fld8_block7_1.warn = 57;
    }
    if (fld8_block1_1.lnver > 300) {
	goto L408;
    }
    fld8_block7_1.nocol = fld8_block1_1.lnver - 1;
    if (inpos == 0) {
	goto L1032;
    }
    i__1 = npnts;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1031: */
	fld8_block5_1.digln[i__ - 1] = fld8_block1_1.tri[i__ + 59365];
    }
    inpos = npnts + 64;
    goto L1033;
L1032:
    cooco_(&npnts, &in);
/* --- POSITIONS, VERTICAL LINES */
L1033:
    fld8_block1_1.xpos[0] = fld8_block5_1.digln[0] / sorig;
    i__ = 1;
    j = 2;
L104:
    if (i__ >= npnts) {
	goto L107;
    }
    k = fld8_block7_1.pchv[i__];
/* --- SPACING BETWEEN LINES */
    e1 = (fld8_block5_1.digln[i__] - fld8_block5_1.digln[i__ - 1]) / ((fld8_block7_1.pchv[
	    i__] - fld8_block7_1.pchv[i__ - 1]) * sorig);
L105:
    fld8_block1_1.xpos[j - 1] = fld8_block1_1.xpos[j - 2] + e1;
    ++j;
    if (j > k) {
	goto L106;
    }
    goto L105;
L106:
    ++i__;
    goto L104;
/* --- HORIZONTAL LINES */
L107:
    if (inpos == 0) {
	goto L1072;
    }
    for (i__ = 1; i__ <= 64; ++i__) {
	++inpos;
/* L1071: */
	fld8_block7_1.pchh[i__ - 1] = fld8_block1_1.tri[inpos + 59301];
    }
    goto L1073;
L1072:
    io___152.ciunit = in;
    s_rsfe(&io___152);
    do_fio(&fld8_c__64, (char *)&fld8_block7_1.pchh[0], (ftnlen)sizeof(real));
    e_rsfe();
L1073:
    npnts = 64;
L108:
    if (fld8_block7_1.pchh[npnts - 1] > .5f) {
	goto L109;
    }
    --npnts;
    if (npnts >= 2) {
	goto L108;
    }
L109:
    horln = fld8_block7_1.pchh[npnts - 1];
    fld8_block1_1.lnhor = horln;
    if (fld8_block1_1.lnhor > 300) {
	fld8_block7_1.warn = 57;
    }
    if (fld8_block1_1.lnhor > 300) {
	goto L408;
    }
    norow = fld8_block1_1.lnhor - 1;
    if (inpos == 0) {
	goto L1092;
    }
    i__1 = npnts;
    for (i__ = 1; i__ <= i__1; ++i__) {
	++inpos;
/* L1091: */
	fld8_block5_1.digln[i__ - 1] = fld8_block1_1.tri[inpos + 59301];
    }
    goto L1093;
L1092:
    cooco_(&npnts, &in);
L1093:
    fld8_block1_1.ypos[0] = fld8_block5_1.digln[0] / sorig;
    i__ = 1;
    j = 2;
L110:
    if (i__ >= npnts) {
	goto L113;
    }
    k = fld8_block7_1.pchh[i__];
    e1 = (fld8_block5_1.digln[i__] - fld8_block5_1.digln[i__ - 1]) / ((fld8_block7_1.pchh[
	    i__] - fld8_block7_1.pchh[i__ - 1]) * sorig);
L111:
    fld8_block1_1.ypos[j - 1] = fld8_block1_1.ypos[j - 2] + e1;
    ++j;
    if (j > k) {
	goto L112;
    }
    goto L111;
L112:
    ++i__;
    goto L110;
/* --- CORRECT COORDINATES */
L113:
    xcorr = fld8_block1_1.rmin - fld8_block1_1.xpos[0];
    i__1 = fld8_block1_1.lnver;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fld8_block1_1.xpos[i__ - 1] += xcorr;
	if (i__ == 1) {
	    goto L114;
	}
	if (fld8_block1_1.xpos[i__ - 1] <= fld8_block1_1.xpos[i__ - 2]) {
	    fld8_block7_1.warn = 59;
	}
L114:
	;
    }
    ycorr = -fld8_block1_1.ypos[0];
    if (fld8_block1_1.flaxi < .5f) {
	ycorr = 0.f;
    }
    i__1 = fld8_block1_1.lnhor;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fld8_block1_1.ypos[i__ - 1] += ycorr;
	if (i__ == 1) {
	    goto L1141;
	}
	if (fld8_block1_1.ypos[i__ - 1] <= fld8_block1_1.ypos[i__ - 2]) {
	    fld8_block7_1.warn = 59;
	}
L1141:
	;
    }
    if (fld8_block1_1.flaxi < .5f && fld8_block1_1.ypos[0] == 0.f) {
	fld8_block1_1.ypos[0] = .5f;
    }
    if (fld8_block1_1.flaxi < .5f && fld8_block1_1.xpos[fld8_block1_1.lnver - 1] > 6284.f) {
	fld8_block7_1.warn = 79;
    }
    if (fld8_block7_1.warn != 0) {
	goto L408;
    }
/* --- READ LINES 21, 22, 23 AND 24 */
    if (inpos == 0) {
	goto L1151;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	fld8_block7_1.horf[0] = fld8_block1_1.tri[inpos + 1 + ((i__ - 1) << 2) + 59301];
	fld8_block7_1.horl[0] = fld8_block1_1.tri[inpos + 2 + ((i__ - 1) << 2) + 59301];
	fld8_block7_1.verf[0] = fld8_block1_1.tri[inpos + 3 + ((i__ - 1) << 2) + 59301];
/* L115: */
	fld8_block7_1.verl[0] = fld8_block1_1.tri[inpos + 4 + ((i__ - 1) << 2) + 59301];
    }
    fld8_block1_1.scale = fld8_block1_1.tri[inpos + 59314];
    fld8_block1_1.flxln = fld8_block1_1.tri[inpos + 59315];
    nolin = fld8_block1_1.tri[inpos + 59316];
    inpos += 15;
    goto L1152;
L1151:
    io___158.ciunit = in;
    s_rsfe(&io___158);
    for (i__ = 1; i__ <= 3; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block7_1.horf[i__ - 1], (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&fld8_block7_1.horl[i__ - 1], (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&fld8_block7_1.verf[i__ - 1], (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&fld8_block7_1.verl[i__ - 1], (ftnlen)sizeof(real));
    }
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.scale, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.flxln, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&nolin, (ftnlen)sizeof(real));
    e_rsfe();
L1152:
    fld8_block1_1.linto = nolin;
    if (fld8_block1_1.linto > 150) {
	fld8_block7_1.warn = 46;
    }
    if (fld8_block1_1.linto > 150) {
	goto L408;
    }
/* --- WRITE SECOND PART OF INPUT */
    j = 1;
    k = 10;
L116:
    if (k > fld8_block1_1.lnver) {
	k = fld8_block1_1.lnver;
    }
    if (j == k) {
	io___159.ciunit = fld8_block7_1.out;
	s_wsfe(&io___159);
	do_fio(&fld8_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.xpos[j - 1], (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (k <= 99 && j != k) {
	io___160.ciunit = fld8_block7_1.out;
	s_wsfe(&io___160);
	do_fio(&fld8_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&fld8_c__1, (char *)&k, (ftnlen)sizeof(integer));
	i__1 = k;
	for (i__ = j; i__ <= i__1; ++i__) {
	    do_fio(&fld8_c__1, (char *)&fld8_block1_1.xpos[i__ - 1], (ftnlen)sizeof(
		    real));
	}
	e_wsfe();
    }
    if (k > 99 && j != k) {
	io___161.ciunit = fld8_block7_1.out;
	s_wsfe(&io___161);
	do_fio(&fld8_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&fld8_c__1, (char *)&k, (ftnlen)sizeof(integer));
	i__1 = k;
	for (i__ = j; i__ <= i__1; ++i__) {
	    do_fio(&fld8_c__1, (char *)&fld8_block1_1.xpos[i__ - 1], (ftnlen)sizeof(
		    real));
	}
	e_wsfe();
    }
    if (k == fld8_block1_1.lnver) {
	goto L117;
    }
    j += 10;
    k += 10;
    goto L116;
L117:
    io___162.ciunit = fld8_block7_1.out;
    s_wsfe(&io___162);
    e_wsfe();
    j = 1;
    k = 10;
L118:
    if (k > fld8_block1_1.lnhor) {
	k = fld8_block1_1.lnhor;
    }
    if (j == k) {
	io___163.ciunit = fld8_block7_1.out;
	s_wsfe(&io___163);
	do_fio(&fld8_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.ypos[j - 1], (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (k <= 99 && j != k) {
	io___164.ciunit = fld8_block7_1.out;
	s_wsfe(&io___164);
	do_fio(&fld8_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&fld8_c__1, (char *)&k, (ftnlen)sizeof(integer));
	i__1 = k;
	for (i__ = j; i__ <= i__1; ++i__) {
	    do_fio(&fld8_c__1, (char *)&fld8_block1_1.ypos[i__ - 1], (ftnlen)sizeof(
		    real));
	}
	e_wsfe();
    }
    if (k > 99 && j != k) {
	io___165.ciunit = fld8_block7_1.out;
	s_wsfe(&io___165);
	do_fio(&fld8_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&fld8_c__1, (char *)&k, (ftnlen)sizeof(integer));
	i__1 = k;
	for (i__ = j; i__ <= i__1; ++i__) {
	    do_fio(&fld8_c__1, (char *)&fld8_block1_1.ypos[i__ - 1], (ftnlen)sizeof(
		    real));
	}
	e_wsfe();
    }
    if (k == fld8_block1_1.lnhor) {
	goto L119;
    }
    j += 10;
    k += 10;
    goto L118;
L119:
    io___166.ciunit = fld8_block7_1.out;
    s_wsfe(&io___166);
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.scale, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.flxln, (ftnlen)sizeof(real));
    e_wsfe();
/* --- NUMBER OF TRIANGLES */
    fld8_block1_1.i5 = (fld8_block7_1.nocol << 1) * norow;
/* --- NUMBER OF VERTICES */
    fld8_block1_1.i6 = fld8_block1_1.lnver * fld8_block1_1.lnhor;
    if (fld8_block1_1.i6 > 30000) {
	fld8_block7_1.warn = 58;
    }
    if (fld8_block1_1.i6 > 30000) {
	goto L408;
    }
/* --- COORDINATES AND INITIALIZATION OF POTENTIAL */
    i__1 = fld8_block1_1.lnhor;
    for (m = 1; m <= i__1; ++m) {
	i__2 = fld8_block1_1.lnver;
	for (n = 1; n <= i__2; ++n) {
	    i__ = (m - 1) * fld8_block1_1.lnver + n;
	    fld8_block3_1.vert[i__ - 1] = fld8_block1_1.xpos[n - 1];
	    fld8_block3_1.vert[i__ + 29999] = fld8_block1_1.ypos[m - 1];
	    i__3 = i__ - 1;
	    fld8_block3_1.cpot[i__3].r = 0.f, fld8_block3_1.cpot[i__3].i = 0.f;
/* L120: */
	}
/* L121: */
    }
/* --- ADJOINING VERTEX NUMBERS */
    i__1 = fld8_block1_1.i6;
    for (i__ = 1; i__ <= i__1; ++i__) {
	xi = fld8_block3_1.vert[i__ - 1];
	fld8_block8_1.ibit[i__ - 1] = 0;
	j = i__ - 1;
	if (j < 1) {
	    goto L127;
	}
	if (fld8_block3_1.vert[j - 1] > xi) {
	    goto L127;
	}
	sivert_(&i__, &fld8_c__1, &fld8_c__1);
L127:
	j -= fld8_block1_1.lnver;
	if (j < 1) {
	    goto L128;
	}
	if (fld8_block3_1.vert[j - 1] > xi) {
	    goto L128;
	}
	sivert_(&i__, &fld8_c__2, &fld8_c__1);
L128:
	++j;
	if (j < 1) {
	    goto L129;
	}
	sivert_(&i__, &fld8_c__3, &fld8_c__1);
L129:
	++j;
	if (j < 1) {
	    goto L130;
	}
	if (fld8_block3_1.vert[j - 1] < xi) {
	    goto L130;
	}
	sivert_(&i__, &fld8_c__4, &fld8_c__1);
L130:
	j = i__ + 1;
	if (j > fld8_block1_1.i6) {
	    goto L131;
	}
	if (fld8_block3_1.vert[j - 1] < xi) {
	    goto L131;
	}
	sivert_(&i__, &fld8_c__5, &fld8_c__1);
L131:
	j += fld8_block1_1.lnver;
	if (j > fld8_block1_1.i6) {
	    goto L132;
	}
	if (fld8_block3_1.vert[j - 1] < xi) {
	    goto L132;
	}
	sivert_(&i__, &fld8_c__6, &fld8_c__1);
L132:
	--j;
	if (j > fld8_block1_1.i6) {
	    goto L133;
	}
	sivert_(&i__, &fld8_c__7, &fld8_c__1);
L133:
	--j;
	if (j > fld8_block1_1.i6) {
	    goto L134;
	}
	if (fld8_block3_1.vert[j - 1] > xi) {
	    goto L134;
	}
	sivert_(&i__, &fld8_c__8, &fld8_c__1);
L134:
	;
    }
/* --- INITIALIZATION */
    i__1 = fld8_block1_1.i5;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fld8_block1_1.tri[i__ - 1] = 1.f;
	fld8_block4_1.itri4[i__ - 1] = 0;
	fld8_block4_1.itri5[i__ - 1] = 0;
	i__2 = i__ - 1;
	fld8_block1_1.cdens[i__2].r = 0.f, fld8_block1_1.cdens[i__2].i = 0.f;
/* L135: */
    }
/* --- VERTEX NUMBERS, DIAGONAL FROM BOTTOM LEFT TO TOP RIGHT CORNER */
    i__1 = norow;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = fld8_block7_1.nocol;
	for (j = 1; j <= i__2; ++j) {
/* --- FIRST TRIANGLE NUMBER */
	    k = (((i__ - 1) * fld8_block7_1.nocol + j) << 1) - 1;
	    sitri_(&k, &fld8_c__0);
/* L136: */
	}
/* L137: */
    }
    linac = 1;
    lpnt = 0;
/* --- READ LINE */
L143:
    if (inpos == 0) {
	goto L1431;
    }
    pnts = fld8_block1_1.tri[inpos + 59302];
    perm = fld8_block1_1.tri[inpos + 59303];
    cond = fld8_block1_1.tri[inpos + 59304];
    conn = fld8_block1_1.tri[inpos + 59305];
    dir = fld8_block1_1.tri[inpos + 59306];
    code = fld8_block1_1.tri[inpos + 59307];
    inpos += 6;
    goto L1432;
L1431:
    io___178.ciunit = in;
    s_rsfe(&io___178);
    do_fio(&fld8_c__1, (char *)&pnts, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&perm, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&cond, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&conn, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&dir, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&code, (ftnlen)sizeof(real));
    e_rsfe();
L1432:
    icode = code;
    if (code == 1.f || code == 2.f) {
	perm = 0.f;
    }
    if (code == 3.f || code == 9.f) {
	fld8_block1_1.ncod3 = 1;
    }
    if ((code == 2.f && conn != 0.f) || code == 2.1f || code == 2.2f) {
	fld8_block1_1.ncod3 = 1;
    }
    npnts = pnts;
    digit_(&npnts, &in, &sorig, &inpos);
    if (npnts > 150) {
	fld8_block7_1.warn = 47;
    }
    if (npnts > 150) {
	goto L408;
    }
    i__1 = npnts;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fld8_block5_1.digln[(i__ << 1) - 2] += xcorr;
	if (fld8_block5_1.digln[(i__ << 1) - 2] < fld8_block1_1.rmin + tolr) {
	    fld8_block5_1.digln[(i__ << 1) - 2] = fld8_block1_1.rmin;
	}
	if (fld8_block5_1.digln[(i__ << 1) - 2] > fld8_block1_1.xpos[fld8_block1_1.lnver - 1]
		 - tolr) {
	    fld8_block5_1.digln[(i__ << 1) - 2] = fld8_block1_1.xpos[fld8_block1_1.lnver - 1]
		    ;
	}
	fld8_block5_1.digln[(i__ << 1) - 1] += ycorr;
	if (fld8_block5_1.digln[(i__ << 1) - 1] < tolr) {
	    fld8_block5_1.digln[(i__ << 1) - 1] = 0.f;
	}
	if (fld8_block5_1.digln[(i__ << 1) - 1] > fld8_block1_1.ypos[fld8_block1_1.lnhor - 1]
		 - tolr) {
	    fld8_block5_1.digln[(i__ << 1) - 1] = fld8_block1_1.ypos[fld8_block1_1.lnhor - 1]
		    ;
	}
/* L144: */
    }
/* --- IF A POINT IS WITHIN TOLR OF A PREVIOUS POINT, SET COORDINATES */
/* --- EQUAL TO THOSE OF THE PREVIOUS POINT */
    i__1 = npnts;
    for (k1 = 1; k1 <= i__1; ++k1) {
	l = npnts + 1 - k1;
	m = l - 1;
	if (m <= 0) {
	    goto L146;
	}
	i__2 = m;
	for (n = 1; n <= i__2; ++n) {
/* Computing 2nd power */
	    r__1 = fld8_block5_1.digln[(l << 1) - 2] - fld8_block5_1.digln[(n << 1) - 2]
		    ;
/* Computing 2nd power */
	    r__2 = fld8_block5_1.digln[(l << 1) - 1] - fld8_block5_1.digln[(n << 1) - 1]
		    ;
	    e1 = sqrt(r__1 * r__1 + r__2 * r__2);
	    if (e1 > tolr) {
		goto L145;
	    }
	    fld8_block5_1.digln[(l << 1) - 2] = fld8_block5_1.digln[(n << 1) - 2];
	    fld8_block5_1.digln[(l << 1) - 1] = fld8_block5_1.digln[(n << 1) - 1];
L145:
	    ;
	}
L146:
	if (linac <= 1) {
	    goto L152;
	}
	i1 = linac - 1;
	i__2 = i1;
	for (j = 1; j <= i__2; ++j) {
	    i2 = 1;
	    if (j > 1) {
		i2 = fld8_block1_1.iln[j - 2] + 1;
	    }
	    i3 = fld8_block1_1.iln[j - 1];
	    i__3 = i3;
	    for (i__ = i2; i__ <= i__3; ++i__) {
/* Computing 2nd power */
		r__1 = fld8_block5_1.digln[(l << 1) - 2] - fld8_block2_1.linc[(i__ << 1)
			 - 2];
/* Computing 2nd power */
		r__2 = fld8_block5_1.digln[(l << 1) - 1] - fld8_block2_1.linc[(i__ << 1)
			 - 1];
		e1 = sqrt(r__1 * r__1 + r__2 * r__2);
		if (e1 > tolr) {
		    goto L147;
		}
		fld8_block5_1.digln[(l << 1) - 2] = fld8_block2_1.linc[(i__ << 1) - 2];
		fld8_block5_1.digln[(l << 1) - 1] = fld8_block2_1.linc[(i__ << 1) - 1];
L147:
		;
	    }
/* L150: */
	}
/* L151: */
    }
/* --- TRANSFER TO ARRAYS DATLN, ILN AND LINC */
L152:
    fld8_block3_1.datln[linac - 1] = perm;
    fld8_block3_1.datln[linac + 149] = cond;
    fld8_block3_1.datln[linac + 299] = conn;
    fld8_block3_1.datln[linac + 449] = dir;
    fld8_block3_1.datln[linac + 599] = code;
    fld8_block3_1.datln[linac + 749] = 0.f;
    fld8_block3_1.datln[linac + 899] = 1.f;
    fld8_block3_1.datln[linac + 1649] = 0.f;
    fld8_block3_1.datln[linac + 2099] = 0.f;
    fld8_block1_1.iln[linac - 1] = (shortint) npnts;
    if (linac >= 2) {
	fld8_block1_1.iln[linac - 1] = (shortint) (fld8_block1_1.iln[linac - 2] + npnts)
		;
    }
    if (fld8_block1_1.iln[linac - 1] > 1500) {
	fld8_block7_1.warn = 48;
    }
    if (fld8_block1_1.iln[linac - 1] > 1500) {
	goto L408;
    }
    k = 0;
    if (linac >= 2) {
	k = fld8_block1_1.iln[linac - 2];
    }
    i__1 = npnts;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = i__ + k;
	fld8_block2_1.linc[(j << 1) - 2] = fld8_block5_1.digln[(i__ << 1) - 2];
/* L401: */
	fld8_block2_1.linc[(j << 1) - 1] = fld8_block5_1.digln[(i__ << 1) - 1];
    }
    ++linac;
    if (linac <= fld8_block1_1.linto) {
	goto L143;
    }
/* --- INITIALIZATION */
    i__1 = fld8_block1_1.i5;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fld8_block1_1.tri[i__ + 59301] = 0.f;
/* L4011: */
    }
/* --- INSERT NEW POINTS, WHERE REQUIRED */
/* --- POINTS ON LINE I ARE CHECKED AGAINST SEGMENTS IN LINE I1 */
    i__ = 1;
L402:
    j = 1;
    if (i__ >= 2) {
	j = fld8_block1_1.iln[i__ - 2] + 1;
    }
    k = fld8_block1_1.iln[i__ - 1];
/* --- POINT ON LINE I */
    l = j;
L403:
    x = fld8_block2_1.linc[(l << 1) - 2];
    y = fld8_block2_1.linc[(l << 1) - 1];
/* --- LINE I1 */
    i1 = 1;
L406:
    if (i1 == i__) {
	goto L413;
    }
    i2 = 1;
    if (i1 >= 2) {
	i2 = fld8_block1_1.iln[i1 - 2] + 1;
    }
    i3 = fld8_block1_1.iln[i1 - 1];
    if (i2 == i3) {
	goto L413;
    }
/* --- FIRST AND LAST POINT IN SEGMENT ON LINE I1 */
    m = i2;
L407:
    n = m + 1;
    xf = fld8_block2_1.linc[(m << 1) - 2];
    yf = fld8_block2_1.linc[(m << 1) - 1];
    xl = fld8_block2_1.linc[(n << 1) - 2];
    yl = fld8_block2_1.linc[(n << 1) - 1];
    if ((x == xf && y == yf) || (x == xl && y == yl)) {
	goto L413;
    }
    e1 = dmin(xf,xl);
    e2 = dmax(xf,xl);
    e3 = dmin(yf,yl);
    e4 = dmax(yf,yl);
/* --- ANGLE OF LINE SEGMENT XF,YF - XL,YL */
    alpha = pio2;
    if (yl < yf) {
	alpha = -pio2;
    }
    if (xl != xf) {
	alpha = atan((yl - yf) / (xl - xf));
    }
    if (xl < xf) {
	alpha += fld8_block7_1.pi;
    }
/* --- ANGLE OF LINE XF,YF - X,Y */
    e5 = pio2;
    if (y < yf) {
	e5 = -pio2;
    }
    if (x != xf) {
	e5 = atan((y - yf) / (x - xf));
    }
    if (x < xf) {
	e5 += fld8_block7_1.pi;
    }
/* --- LENGTH OF LINE XF,YF - X,Y */
/* Computing 2nd power */
    r__1 = x - xf;
/* Computing 2nd power */
    r__2 = y - yf;
    e6 = sqrt(r__1 * r__1 + r__2 * r__2);
/* --- DISTANCE OF X,Y FROM LINE SEGMENT */
    e7 = e6 * sin(e5 - alpha);
    if (dabs(e7) > tolr) {
	goto L412;
    }
/* --- PROJECTED POINT */
    xpl = x + e7 * sin(alpha);
    ypl = y - e7 * cos(alpha);
    if (xpl < e1 - .01f || xpl > e2 + .01f || ypl < e3 - .01f || ypl > e4 + 
	    .01f) {
	goto L412;
    }
/* --- INSERT NEW POINT */
    i4 = fld8_block1_1.iln[fld8_block1_1.linto - 1];
    if (i4 >= 1500) {
	fld8_block7_1.warn = 48;
    }
    if (i4 < 1500) {
	goto L409;
    }
L408:
    goto L999;
L409:
    i__1 = i4;
    for (i8 = n; i8 <= i__1; ++i8) {
	i9 = i4 + n - i8;
	fld8_block2_1.linc[i9 * 2] = fld8_block2_1.linc[(i9 << 1) - 2];
/* L410: */
	fld8_block2_1.linc[(i9 << 1) + 1] = fld8_block2_1.linc[(i9 << 1) - 1];
    }
    fld8_block2_1.linc[(n << 1) - 2] = x;
    fld8_block2_1.linc[(n << 1) - 1] = y;
    i__1 = fld8_block1_1.linto;
    for (i4 = i1; i4 <= i__1; ++i4) {
/* L411: */
	fld8_block1_1.iln[i4 - 1] = (shortint) (fld8_block1_1.iln[i4 - 1] + 1);
    }
    goto L402;
/* --- SEARCH AGAINST NEXT SEGMENT */
L412:
    ++m;
    if (m < i3) {
	goto L407;
    }
/* --- SEARCH AGAINST NEXT LINE */
L413:
    ++i1;
    if (i1 <= fld8_block1_1.linto) {
	goto L406;
    }
/* --- TAKE NEXT POINT ON LINE I */
    ++l;
    if (l <= k) {
	goto L403;
    }
/* --- TAKE POINTS FROM NEXT LINE */
    ++i__;
    if (i__ <= fld8_block1_1.linto) {
	goto L402;
    }
/* --- TRANSFER LINES BACK INTO ARRAY DIGLN */
    linac = 1;
    i__ = 1;
L416:
    if (linac >= 2) {
	i__ = fld8_block1_1.iln[linac - 2] + 1;
    }
    j = fld8_block1_1.iln[linac - 1];
    npnts = j - i__ + 1;
    i__1 = npnts;
    for (k = 1; k <= i__1; ++k) {
	l = i__ + k - 1;
	fld8_block5_1.digln[(k << 1) - 2] = fld8_block2_1.linc[(l << 1) - 2];
/* L417: */
	fld8_block5_1.digln[(k << 1) - 1] = fld8_block2_1.linc[(l << 1) - 1];
    }
    if (fld8_block7_1.warn != 0) {
	fld8_block7_1.warn = 1;
    }
    perm = fld8_block3_1.datln[linac - 1];
    cond = fld8_block3_1.datln[linac + 149];
    conn = fld8_block3_1.datln[linac + 299];
    dir = fld8_block3_1.datln[linac + 449];
    code = fld8_block3_1.datln[linac + 599];
    icode = code;
/* --- WRITE LINE */
    if (code == 2.1f) {
	goto L418;
    }
    io___203.ciunit = fld8_block7_1.out;
    s_wsfe(&io___203);
    do_fio(&fld8_c__1, (char *)&perm, (ftnlen)sizeof(real));
    e_wsfe();
    e1 = conn;
    if (code > 1.9f && code < 2.9f) {
	e1 = 0.f;
    }
    if (code < 8.f) {
	io___204.ciunit = fld8_block7_1.out;
	s_wsfe(&io___204);
	do_fio(&fld8_c__1, (char *)&cond, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (code >= 8.f) {
	io___205.ciunit = fld8_block7_1.out;
	s_wsfe(&io___205);
	do_fio(&fld8_c__1, (char *)&cond, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&conn, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&dir, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (code < 8.f && code != 2.f && code != 2.2f && dir > 0.f) {
	io___206.ciunit = fld8_block7_1.out;
	s_wsfe(&io___206);
	e_wsfe();
    }
    if (code < 8.f && code != 2.f && code != 2.2f && dir < 0.f) {
	io___207.ciunit = fld8_block7_1.out;
	s_wsfe(&io___207);
	e_wsfe();
    }
    if (code >= 2.f && code < 2.9f) {
	io___208.ciunit = fld8_block7_1.out;
	s_wsfe(&io___208);
	do_fio(&fld8_c__1, (char *)&conn, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (code >= 2.f && code < 2.9f) {
	io___209.ciunit = fld8_block7_1.out;
	s_wsfe(&io___209);
	do_fio(&fld8_c__1, (char *)&dir, (ftnlen)sizeof(real));
	e_wsfe();
    }
    goto L419;
L418:
    io___210.ciunit = fld8_block7_1.out;
    s_wsfe(&io___210);
    do_fio(&fld8_c__1, (char *)&perm, (ftnlen)sizeof(real));
    e_wsfe();
    io___211.ciunit = fld8_block7_1.out;
    s_wsfe(&io___211);
    do_fio(&fld8_c__1, (char *)&cond, (ftnlen)sizeof(real));
    e_wsfe();
    io___212.ciunit = fld8_block7_1.out;
    s_wsfe(&io___212);
    do_fio(&fld8_c__1, (char *)&conn, (ftnlen)sizeof(real));
    e_wsfe();
    io___213.ciunit = fld8_block7_1.out;
    s_wsfe(&io___213);
    do_fio(&fld8_c__1, (char *)&dir, (ftnlen)sizeof(real));
    e_wsfe();
    cond = cond * fld8_block7_1.pi / 180.f;
    dir = dir * fld8_block7_1.pi / 180.f;
L419:
    io___214.ciunit = fld8_block7_1.out;
    s_wsfe(&io___214);
    do_fio(&fld8_c__1, (char *)&code, (ftnlen)sizeof(real));
    e_wsfe();
/* --- N2=1 FOR CLOSED CURVE */
    n2 = 0;
    if (fld8_block5_1.digln[0] == fld8_block5_1.digln[(npnts << 1) - 2] && 
	    fld8_block5_1.digln[1] == fld8_block5_1.digln[(npnts << 1) - 1]) {
	n2 = 1;
    }
    if (fld8_block1_1.flaxi < 1.5f) {
	io___216.ciunit = fld8_block7_1.out;
	s_wsfe(&io___216);
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___217.ciunit = fld8_block7_1.out;
	s_wsfe(&io___217);
	e_wsfe();
    }
    i__1 = npnts;
    for (i2 = 1; i2 <= i__1; ++i2) {
	i3 = (i2 << 1) - 1;
	i4 = i3 + 1;
/* L160: */
	io___218.ciunit = fld8_block7_1.out;
	s_wsfe(&io___218);
	do_fio(&fld8_c__1, (char *)&fld8_block5_1.digln[i3 - 1], (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&fld8_block5_1.digln[i4 - 1], (ftnlen)sizeof(real));
	e_wsfe();
    }
/* --- MOVE THE CLOSEST POINTS IN THE GRID TO THE POINTS ON THE LINE */
/* L161: */
    lasti = 0;
    i__1 = npnts;
    for (l = 1; l <= i__1; ++l) {
	delx = 9.9e9f;
	dely = 9.9e9f;
	m = 1;
L153:
	e1 = (r__1 = fld8_block5_1.digln[(l << 1) - 2] - fld8_block1_1.xpos[m - 1], 
		dabs(r__1));
	if (e1 > delx) {
	    goto L154;
	}
	delx = e1;
	if (m >= fld8_block1_1.lnver) {
	    goto L155;
	}
	++m;
	goto L153;
L154:
	--m;
L155:
	n = 1;
L1551:
	e1 = (r__1 = fld8_block5_1.digln[(l << 1) - 1] - fld8_block1_1.ypos[n - 1], 
		dabs(r__1));
	if (e1 > dely) {
	    goto L157;
	}
	dely = e1;
	if (n >= fld8_block1_1.lnhor) {
	    goto L158;
	}
	++n;
	goto L1551;
L157:
	--n;
L158:
	i__ = m + fld8_block1_1.lnver * (n - 1);
	xi = fld8_block3_1.vert[i__ - 1];
	yi = fld8_block3_1.vert[i__ + 29999];
	if (i__ == lasti) {
	    fld8_block7_1.warn = 51;
	}
	if (i__ == lasti) {
	    io___223.ciunit = fld8_block7_1.out;
	    s_wsfe(&io___223);
	    do_fio(&fld8_c__1, (char *)&fld8_block5_1.digln[(l << 1) - 2], (ftnlen)
		    sizeof(real));
	    do_fio(&fld8_c__1, (char *)&fld8_block5_1.digln[(l << 1) - 1], (ftnlen)
		    sizeof(real));
	    e_wsfe();
	}
	if (i__ == lasti) {
	    goto L162;
	}
	if (ivert_(&i__, &fld8_c__10) == 0 || (xi == fld8_block5_1.digln[(l << 1) - 2] &&
		 yi == fld8_block5_1.digln[(l << 1) - 1])) {
	    goto L162;
	}
	fld8_block7_1.warn = 55;
	io___224.ciunit = fld8_block7_1.out;
	s_wsfe(&io___224);
	do_fio(&fld8_c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	if (fld8_block1_1.flaxi < 1.5f) {
	    io___225.ciunit = fld8_block7_1.out;
	    s_wsfe(&io___225);
	    e_wsfe();
	}
	if (fld8_block1_1.flaxi > 1.5f) {
	    io___226.ciunit = fld8_block7_1.out;
	    s_wsfe(&io___226);
	    e_wsfe();
	}
	io___227.ciunit = fld8_block7_1.out;
	s_wsfe(&io___227);
	do_fio(&fld8_c__1, (char *)&xi, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&yi, (ftnlen)sizeof(real));
	e_wsfe();
	io___228.ciunit = fld8_block7_1.out;
	s_wsfe(&io___228);
	e_wsfe();
L162:
	fld8_block7_1.point[lpnt + l - 1] = i__;
	fld8_block3_1.vert[i__ - 1] = fld8_block5_1.digln[(l << 1) - 2];
	fld8_block3_1.vert[i__ + 29999] = fld8_block5_1.digln[(l << 1) - 1];
	lasti = i__;
	if (ivert_(&i__, &fld8_c__9) == 2 || code == 1.f || code == 3.f || code == 
		9.f) {
	    goto L1480;
	}
	if (code == 2.f) {
	    sivert_(&i__, &fld8_c__9, &fld8_c__2);
	}
	if (code == 2.f) {
	    i__2 = i__ - 1;
	    r__1 = conn * cos(dir);
	    r__2 = conn * sin(dir);
	    q__1.r = r__1, q__1.i = r__2;
	    fld8_block3_1.cpot[i__2].r = q__1.r, fld8_block3_1.cpot[i__2].i = q__1.i;
	}
	if (code == 0.f || code >= 4.f) {
	    sivert_(&i__, &fld8_c__9, &fld8_c__0);
	}
	if (code == 10.f) {
	    sivert_(&i__, &fld8_c__9, &fld8_c__10);
	}
	if (code <= 2.f || code > 2.9f) {
	    goto L1480;
	}
	if (code == 2.1f && l == 1) {
	    i__2 = i__ - 1;
	    r__1 = perm * cos(cond);
	    r__2 = perm * sin(cond);
	    q__1.r = r__1, q__1.i = r__2;
	    fld8_block3_1.cpot[i__2].r = q__1.r, fld8_block3_1.cpot[i__2].i = q__1.i;
	}
	if ((code == 2.1f && l == 2) || (code == 2.2f && l == 1)) {
	    i__2 = i__ - 1;
	    r__1 = conn * cos(dir);
	    r__2 = conn * sin(dir);
	    q__1.r = r__1, q__1.i = r__2;
	    fld8_block3_1.cpot[i__2].r = q__1.r, fld8_block3_1.cpot[i__2].i = q__1.i;
	}
	if (code == 2.2f) {
	    e1 = conn * fld8_block5_1.digln[0] / fld8_block5_1.digln[2];
	}
	if (code == 2.2f && l == 2) {
	    i__2 = i__ - 1;
	    r__1 = e1 * cos(dir);
	    r__2 = e1 * sin(dir);
	    q__1.r = r__1, q__1.i = r__2;
	    fld8_block3_1.cpot[i__2].r = q__1.r, fld8_block3_1.cpot[i__2].i = q__1.i;
	}
	sivert_(&i__, &fld8_c__9, &fld8_c__2);
L1480:
	sivert_(&i__, &fld8_c__10, &fld8_c__2);
/* L148: */
    }
/* --- FIT GRID TO LINE SEGMENTS */
    if (npnts <= 1 || fld8_block7_1.warn == 51 || fld8_block7_1.warn == 55) {
	goto L185;
    }
    i1 = linac - 1;
    i2 = npnts - 1;
    i__1 = i2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	xf = fld8_block5_1.digln[(i__ << 1) - 2];
	yf = fld8_block5_1.digln[(i__ << 1) - 1];
	xl = fld8_block5_1.digln[i__ * 2];
	yl = fld8_block5_1.digln[(i__ << 1) + 1];
	if (linac <= 1) {
	    goto L166;
	}
/* --- CHECK IF XF,YF AND XL,YL ARE EQUAL TO SUCCESSIVE PREVIOUS POINTS */
	i__2 = i1;
	for (j = 1; j <= i__2; ++j) {
	    i3 = 1;
	    if (j > 1) {
		i3 = fld8_block1_1.iln[j - 2] + 1;
	    }
	    i4 = fld8_block1_1.iln[j - 1];
	    i__3 = i4;
	    for (k = i3; k <= i__3; ++k) {
		if (xf != fld8_block2_1.linc[(k << 1) - 2] || yf != fld8_block2_1.linc[(
			k << 1) - 1]) {
		    goto L164;
		}
		if (k <= i3) {
		    goto L163;
		}
		if (xl == fld8_block2_1.linc[(k << 1) - 4] && yl == fld8_block2_1.linc[(
			k << 1) - 3]) {
		    goto L173;
		}
L163:
		if (k >= i4) {
		    goto L164;
		}
		if (xl == fld8_block2_1.linc[k * 2] && yl == fld8_block2_1.linc[(k << 1)
			 + 1]) {
		    goto L173;
		}
L164:
		;
	    }
/* L165: */
	}
/* --- FIT GRID TO LINE SEGMENT XF,YF - XL,YL */
L166:
	x = xf;
	y = yf;
	k1 = lpnt + i__ + 1;
	j = fld8_block7_1.point[k1 - 2];
	sxl = 1.f;
	if (xl < xf) {
	    sxl = -1.f;
	}
	syl = 1.f;
	if (yl < yf) {
	    syl = -1.f;
	}
/* --- ANGLE OF LINE SEGMENT */
	alpha = pio2;
	if (yl < yf) {
	    alpha = -pio2;
	}
	if (xl != xf) {
	    alpha = atan((yl - yf) / (xl - xf));
	}
	if (xl < xf) {
	    alpha += fld8_block7_1.pi;
	}
	salph = sin(alpha);
	calph = cos(alpha);
L167:
	k = 0;
	asinb = 1e3f;
	for (l = 1; l <= 8; ++l) {
	    m = ivert_(&j, &l);
	    if (m == 0) {
		goto L168;
	    }
	    i10 = ivert_(&m, &fld8_c__10);
	    xm = fld8_block3_1.vert[m - 1];
	    ym = fld8_block3_1.vert[m + 29999];
	    if (i10 == 1) {
		goto L168;
	    }
	    if (i10 != 0 && m != fld8_block7_1.point[k1 - 1]) {
		goto L168;
	    }
/* --- ANGLE BETWEEN LINE SEGMENT AND ADJOINING POINT (BETA) */
	    e1 = pio2 - alpha;
	    if (ym < y) {
		e1 -= fld8_block7_1.pi;
	    }
	    if (xm != x) {
		e1 = atan((fld8_block3_1.vert[m + 29999] - y) / (fld8_block3_1.vert[m - 
			1] - x)) - alpha;
	    }
	    if (xm < x) {
		e1 += fld8_block7_1.pi;
	    }
	    if (cos(e1) < .001f) {
		goto L168;
	    }
/* --- DISTANCE TO ADJOINING POINT */
/* Computing 2nd power */
	    r__1 = ym - y;
/* Computing 2nd power */
	    r__2 = xm - x;
	    e2 = sqrt(r__1 * r__1 + r__2 * r__2);
	    e3 = e2 * sin(e1);
	    if (dabs(e3) > dabs(asinb)) {
		goto L168;
	    }
	    xpl = xm + e3 * salph;
	    ypl = ym - e3 * calph;
	    if ((xpl - xl) * sxl > .01f) {
		goto L168;
	    }
	    if ((ypl - yl) * syl > .01f) {
		goto L168;
	    }
	    asinb = e3;
	    k = l;
	    xpk = xpl;
	    ypk = ypl;
	    m1 = m;
L168:
	    ;
	}
/* --- ROW AND COLUMN NUMBERS */
	l = (m1 - 1) / fld8_block1_1.lnver + 1;
	m = m1 - (l - 1) * fld8_block1_1.lnver;
	if (k == 0) {
	    goto L1680;
	}
/* --- THE PROJECTION IS UNACCEPTABLE IF IT CUTS ACROSS GRID LINES */
/* --- OR COMES TOO CLOSE */
	if (m >= fld8_block1_1.lnver) {
	    goto L1671;
	}
	if (xpk > fld8_block1_1.xpos[m - 1] + (fld8_block3_1.vert[m1] - fld8_block1_1.xpos[m 
		- 1]) * .8f) {
	    k = 0;
	}
L1671:
	if (m <= 1) {
	    goto L1672;
	}
	if (xpk < fld8_block1_1.xpos[m - 1] - (fld8_block1_1.xpos[m - 1] - 
		fld8_block3_1.vert[m1 - 2]) * .8f) {
	    k = 0;
	}
L1672:
	if (l >= fld8_block1_1.lnhor) {
	    goto L1673;
	}
	if (ypk > fld8_block1_1.ypos[l - 1] + (fld8_block3_1.vert[m1 + fld8_block1_1.lnver + 
		29999] - fld8_block1_1.ypos[l - 1]) * .8f) {
	    k = 0;
	}
L1673:
	if (l <= 1) {
	    goto L1674;
	}
	if (ypk < fld8_block1_1.ypos[l - 1] - (fld8_block1_1.ypos[l - 1] - 
		fld8_block3_1.vert[m1 - fld8_block1_1.lnver + 29999]) * .8f) {
	    k = 0;
	}
L1674:
	if (k != 0) {
	    goto L1690;
	}
/* --- TRY TO MOVE AN ADJACENT POINT HORIZONTALLY OR VERTICALLY INSTEAD */
	asinb = 1e3f;
L1680:
	l = (j - 1) / fld8_block1_1.lnver + 1;
	m = j - (l - 1) * fld8_block1_1.lnver;
	xpl = 9.9e9f;
	ypl = 9.9e9f;
	if (syl < 0.f) {
	    goto L1682;
	}
	if (l >= fld8_block1_1.lnhor) {
	    goto L1684;
	}
	if (yl != yf) {
	    xpl = (xl - xf) * (fld8_block1_1.ypos[l] - yf) / (yl - yf) + xf;
	}
	if (sxl < 0.f) {
	    goto L1681;
	}
	if (m < fld8_block1_1.lnver) {
	    goto L1692;
	}
L1691:
	k = 7;
	goto L1690;
L1692:
	if (xpl > fld8_block1_1.xpos[m]) {
	    goto L1684;
	}
	j1 = ivert_(&j, &fld8_c__6);
	j2 = ivert_(&j, &fld8_c__7);
	if (ivert_(&j1, &fld8_c__10) == 0 || (ivert_(&j1, &fld8_c__10) == 2 && j1 == 
		fld8_block7_1.point[k1 - 1])) {
	    k = 6;
	}
	if ((ivert_(&j2, &fld8_c__10) == 0 || (ivert_(&j2, &fld8_c__10) == 2 && j2 == 
		fld8_block7_1.point[k1 - 1])) && (xpl - fld8_block1_1.xpos[m - 1] <
		fld8_block1_1.xpos[m] - xpl || k != 6)) {
	    k = 7;
	}
	goto L1689;
L1681:
	if (m <= 1) {
	    goto L1691;
	}
	if (xpl < fld8_block1_1.xpos[m - 2]) {
	    goto L1684;
	}
	j1 = ivert_(&j, &fld8_c__8);
	j2 = ivert_(&j, &fld8_c__7);
	if (ivert_(&j1, &fld8_c__10) == 0 || (ivert_(&j1, &fld8_c__10) == 2 && j1 == 
		fld8_block7_1.point[k1 - 1])) {
	    k = 8;
	}
	if ((ivert_(&j2, &fld8_c__10) == 0 || (ivert_(&j2, &fld8_c__10) == 2 && j2 == 
		fld8_block7_1.point[k1 - 1])) && (fld8_block1_1.xpos[m - 1] - xpl < xpl 
		- fld8_block1_1.xpos[m - 2] || k != 8)) {
	    k = 7;
	}
	goto L1689;
L1682:
	if (l <= 1) {
	    goto L1684;
	}
	if (yl != yf) {
	    xpl = (xl - xf) * (fld8_block1_1.ypos[l - 2] - yf) / (yl - yf) + xf;
	}
	if (sxl < 0.f) {
	    goto L1683;
	}
	if (m < fld8_block1_1.lnver) {
	    goto L1694;
	}
L1693:
	k = 3;
	goto L1690;
L1694:
	if (xpl > fld8_block1_1.xpos[m]) {
	    goto L1684;
	}
	j1 = ivert_(&j, &fld8_c__4);
	j2 = ivert_(&j, &fld8_c__3);
	if (ivert_(&j1, &fld8_c__10) == 0 || (ivert_(&j1, &fld8_c__10) == 2 && j1 == 
		fld8_block7_1.point[k1 - 1])) {
	    k = 4;
	}
	if ((ivert_(&j2, &fld8_c__10) == 0 || (ivert_(&j2, &fld8_c__10) == 2 && j2 == 
		fld8_block7_1.point[k1 - 1])) && (xpl - fld8_block1_1.xpos[m - 1] < 
		fld8_block1_1.xpos[m] - xpl || k != 4)) {
	    k = 3;
	}
	goto L1689;
L1683:
	if (m <= 1) {
	    goto L1693;
	}
	if (xpl < fld8_block1_1.xpos[m - 2]) {
	    goto L1684;
	}
	j1 = ivert_(&j, &fld8_c__2);
	j2 = ivert_(&j, &fld8_c__3);
	if (ivert_(&j1, &fld8_c__10) == 0 || (ivert_(&j1, &fld8_c__10) == 2 && j1 == 
		fld8_block7_1.point[k1 - 1])) {
	    k = 2;
	}
	if ((ivert_(&j2, &fld8_c__10) == 0 || (ivert_(&j2, &fld8_c__10) == 2 && j2 == 
		fld8_block7_1.point[k1 - 1])) && (fld8_block1_1.xpos[m - 1] - xpl < xpl
		- fld8_block1_1.xpos[m - 2] || k != 2)) {
	    k = 3;
	}
	goto L1689;
L1684:
	xpl = 9.9e9f;
	if (sxl < 0.f) {
	    goto L1686;
	}
	if (m >= fld8_block1_1.lnver) {
	    goto L1689;
	}
	if (xl != xf) {
	    ypl = (yl - yf) * (fld8_block1_1.xpos[m] - xf) / (xl - xf) + yf;
	}
	if (syl < 0.f) {
	    goto L1685;
	}
	if (l < fld8_block1_1.lnhor) {
	    goto L1696;
	}
L1695:
	k = 5;
	goto L1690;
L1696:
	if (ypl > fld8_block1_1.ypos[l]) {
	    goto L1688;
	}
	j1 = ivert_(&j, &fld8_c__6);
	j2 = ivert_(&j, &fld8_c__5);
	if (ivert_(&j1, &fld8_c__10) == 0 || (ivert_(&j1, &fld8_c__10) == 2 && j1 == 
		fld8_block7_1.point[k1 - 1])) {
	    k = 6;
	}
	if ((ivert_(&j2, &fld8_c__10) == 0 || (ivert_(&j2, &fld8_c__10) == 2 && j2 == 
		fld8_block7_1.point[k1 - 1])) && (ypl - fld8_block1_1.ypos[l - 1] < 
		fld8_block1_1.ypos[l] - ypl || k != 6)) {
	    k = 5;
	}
	goto L1689;
L1685:
	if (l <= 1) {
	    goto L1695;
	}
	if (ypl < fld8_block1_1.ypos[l - 2]) {
	    goto L1688;
	}
	j1 = ivert_(&j, &fld8_c__4);
	j2 = ivert_(&j, &fld8_c__5);
	if (ivert_(&j1, &fld8_c__10) == 0 || (ivert_(&j1, &fld8_c__10) == 2 && j1 == 
		fld8_block7_1.point[k1 - 1])) {
	    k = 4;
	}
	if ((ivert_(&j2, &fld8_c__10) == 0 || (ivert_(&j2, &fld8_c__10) == 2 && j2 == 
		fld8_block7_1.point[k1 - 1])) && (fld8_block1_1.ypos[l - 1] - ypl < ypl 
		- fld8_block1_1.ypos[l - 2] || k != 4)) {
	    k = 5;
	}
	goto L1689;
L1686:
	if (m <= 1) {
	    goto L1689;
	}
	if (xl != xf) {
	    ypl = (yl - yf) * (fld8_block1_1.xpos[m - 2] - xf) / (xl - xf) + yf;
	}
	if (syl < 0.f) {
	    goto L1687;
	}
	if (l < fld8_block1_1.lnhor) {
	    goto L1698;
	}
L1697:
	k = 1;
	goto L1690;
L1698:
	if (ypl > fld8_block1_1.ypos[l]) {
	    goto L1688;
	}
	j1 = ivert_(&j, &fld8_c__8);
	j2 = ivert_(&j, &fld8_c__1);
	if (ivert_(&j1, &fld8_c__10) == 0 || (ivert_(&j1, &fld8_c__10) == 2 && j1 == 
		fld8_block7_1.point[k1 - 1])) {
	    k = 8;
	}
	if ((ivert_(&j2, &fld8_c__10) == 0 || (ivert_(&j2, &fld8_c__10) == 2 && j2 == 
		fld8_block7_1.point[k1 - 1])) && (ypl - fld8_block1_1.ypos[l - 1] < 
		fld8_block1_1.ypos[l] - ypl || k != 8)) {
	    k = 1;
	}
	goto L1689;
L1687:
	if (l <= 1) {
	    goto L1697;
	}
	if (ypl < fld8_block1_1.ypos[l - 2]) {
	    goto L1688;
	}
	j1 = ivert_(&j, &fld8_c__2);
	j2 = ivert_(&j, &fld8_c__1);
	if (ivert_(&j1, &fld8_c__10) == 0 || (ivert_(&j1, &fld8_c__10) == 2 && j1 == 
		fld8_block7_1.point[k1 - 1])) {
	    k = 2;
	}
	if ((ivert_(&j2, &fld8_c__10) == 0 || (ivert_(&j2, &fld8_c__10) == 2 && j2 == 
		fld8_block7_1.point[k1 - 1])) && (fld8_block1_1.ypos[l - 1] - ypl < ypl 
		- fld8_block1_1.ypos[l - 2] || k != 2)) {
	    k = 1;
	}
	goto L1689;
L1688:
	ypl = 9.9e9f;
L1689:
	if (k == 0) {
	    fld8_block7_1.warn = 50;
	}
	if (k == 0) {
	    io___242.ciunit = fld8_block7_1.out;
	    s_wsfe(&io___242);
	    do_fio(&fld8_c__1, (char *)&xf, (ftnlen)sizeof(real));
	    do_fio(&fld8_c__1, (char *)&yf, (ftnlen)sizeof(real));
	    do_fio(&fld8_c__1, (char *)&xl, (ftnlen)sizeof(real));
	    do_fio(&fld8_c__1, (char *)&yl, (ftnlen)sizeof(real));
	    do_fio(&fld8_c__1, (char *)&x, (ftnlen)sizeof(real));
	    do_fio(&fld8_c__1, (char *)&y, (ftnlen)sizeof(real));
	    e_wsfe();
	}
	if (k == 0) {
	    goto L173;
	}
L1690:
	n = ivert_(&j, &k);
	if (k == 2) {
	    goto L301;
	}
	if (k == 6) {
	    goto L302;
	}
	if (k == 4) {
	    goto L304;
	}
	if (k == 8) {
	    goto L170;
	}
	goto L172;
/* --- NORMAL DIRECTION OF DIAGONAL */
/* --- FOR K=2, TRIANGLE ROW NUMBER */
L301:
	i8 = (j - 1) / fld8_block1_1.lnver;
/* --- COLUMN NUMBER */
	i9 = j - 1 - i8 * fld8_block1_1.lnver;
/* --- LOWER LEFT CORNER */
	i3 = j - 1 - fld8_block1_1.lnver;
	goto L303;
/* --- FOR K=6 */
L302:
	i8 = j / fld8_block1_1.lnver + 1;
	i9 = j - (i8 - 1) * fld8_block1_1.lnver;
	i3 = j;
/* --- FOR K=2 AND K=6, FIRST TRIANGLE NUMBER */
L303:
	i4 = (((i8 - 1) * fld8_block7_1.nocol + i9) << 1) - 1;
/* --- VERTEX NUMBERS */
	sitri_(&i4, &fld8_c__0);
	goto L1711;
/* --- REVERSE DIRECTION OF DIAGONAL */
/* --- FOR K=4, TRIANGLE ROW NUMBER */
L304:
	i8 = j / fld8_block1_1.lnver;
/* --- COLUMN NUMBER */
	i9 = j - i8 * fld8_block1_1.lnver;
/* --- UPPER LEFT CORNER */
	i3 = j;
	goto L171;
/* --- FOR K=8 */
L170:
	i8 = (j - 1) / fld8_block1_1.lnver + 1;
	i9 = j - 1 - (i8 - 1) * fld8_block1_1.lnver;
	i3 = j + fld8_block7_1.nocol;
/* --- FOR K=4 AND K=8, FIRST TRIANGLE NUMBER */
L171:
	i4 = (((i8 - 1) * fld8_block7_1.nocol + i9) << 1) - 1;
/* --- VERTEX NUMBERS */
	sitri_(&i4, &fld8_c__1);
/* --- SET PERMEABILITY NEGATIVE (PREVENTS REVERSAL OF DIAGONAL LATER) */
L1711:
	ti4 = fld8_block1_1.tri[i4 - 1];
	fld8_block1_1.tri[i4 - 1] = -ti4;
/* --- SKIP IF THE POINT EQUALS THE END POINT */
L172:
	k1 = lpnt + i__ + 1;
	if (n != fld8_block7_1.point[k1 - 1]) {
	    goto L1720;
	}
	sivert_(&n, &fld8_c__10, &fld8_c__1);
	goto L173;
L1720:
	if (ivert_(&n, &fld8_c__10) == 0) {
	    goto L1721;
	}
	fld8_block7_1.warn = 55;
	io___244.ciunit = fld8_block7_1.out;
	s_wsfe(&io___244);
	do_fio(&fld8_c__1, (char *)&n, (ftnlen)sizeof(integer));
	e_wsfe();
	if (fld8_block1_1.flaxi < 1.5f) {
	    io___245.ciunit = fld8_block7_1.out;
	    s_wsfe(&io___245);
	    e_wsfe();
	}
	if (fld8_block1_1.flaxi > 1.5f) {
	    io___246.ciunit = fld8_block7_1.out;
	    s_wsfe(&io___246);
	    e_wsfe();
	}
	xn = fld8_block3_1.vert[n - 1];
	yn = fld8_block3_1.vert[n + 29999];
	io___249.ciunit = fld8_block7_1.out;
	s_wsfe(&io___249);
	do_fio(&fld8_c__1, (char *)&xn, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&yn, (ftnlen)sizeof(real));
	e_wsfe();
	io___250.ciunit = fld8_block7_1.out;
	s_wsfe(&io___250);
	e_wsfe();
/* --- MOVE THE POINT TO THE LINE */
L1721:
	if (asinb > 999.9f) {
	    goto L1722;
	}
/* --- MOVE BY PROJECTION */
	xn = fld8_block3_1.vert[n - 1];
	yn = fld8_block3_1.vert[n + 29999];
	fld8_block3_1.vert[n - 1] = xn + asinb * salph;
	fld8_block3_1.vert[n + 29999] = yn - asinb * calph;
	goto L1723;
/* --- MOVE HORIZONTALLY OR VERTICALLY */
L1722:
	if (xpl < 9.8e9f) {
	    fld8_block3_1.vert[n - 1] = xpl;
	}
	if (ypl < 9.8e9f) {
	    fld8_block3_1.vert[n + 29999] = ypl;
	}
L1723:
	x = fld8_block3_1.vert[n - 1];
	y = fld8_block3_1.vert[n + 29999];
/* --- SET POTENTIAL AND CODE */
	if (ivert_(&n, &fld8_c__9) == 2 || code == 1.f || code == 3.f || code == 
		9.f) {
	    goto L1719;
	}
	if (code == 2.f) {
	    i__2 = n - 1;
	    r__1 = conn * cos(dir);
	    r__2 = conn * sin(dir);
	    q__1.r = r__1, q__1.i = r__2;
	    fld8_block3_1.cpot[i__2].r = q__1.r, fld8_block3_1.cpot[i__2].i = q__1.i;
	}
	if (code == 0.f || code >= 4.f) {
	    sivert_(&n, &fld8_c__9, &fld8_c__0);
	}
	if (code == 10.f) {
	    sivert_(&n, &fld8_c__9, &fld8_c__10);
	}
	if (code == 2.1f) {
	    i__2 = n - 1;
	    r__1 = perm * cos(cond);
	    r__2 = perm * sin(cond);
	    q__2.r = r__1, q__2.i = r__2;
	    r__3 = conn * cos(dir);
	    r__4 = conn * sin(dir);
	    q__6.r = r__3, q__6.i = r__4;
	    r__5 = perm * cos(cond);
	    r__6 = perm * sin(cond);
	    q__7.r = r__5, q__7.i = r__6;
	    q__5.r = q__6.r - q__7.r, q__5.i = q__6.i - q__7.i;
/* Computing 2nd power */
	    r__8 = fld8_block3_1.vert[n - 1] - xf;
/* Computing 2nd power */
	    r__9 = fld8_block3_1.vert[n + 29999] - yf;
	    r__7 = sqrt(r__8 * r__8 + r__9 * r__9);
	    q__4.r = r__7 * q__5.r, q__4.i = r__7 * q__5.i;
/* Computing 2nd power */
	    r__11 = xl - xf;
/* Computing 2nd power */
	    r__12 = yl - yf;
	    r__10 = sqrt(r__11 * r__11 + r__12 * r__12);
	    q__3.r = q__4.r / r__10, q__3.i = q__4.i / r__10;
	    q__1.r = q__2.r + q__3.r, q__1.i = q__2.i + q__3.i;
	    fld8_block3_1.cpot[i__2].r = q__1.r, fld8_block3_1.cpot[i__2].i = q__1.i;
	}
	if (code == 2.2f) {
	    i__2 = n - 1;
	    r__1 = conn * cos(dir);
	    r__2 = conn * sin(dir);
	    q__3.r = r__1, q__3.i = r__2;
	    q__2.r = xf * q__3.r, q__2.i = xf * q__3.i;
	    i__3 = n - 1;
	    q__1.r = q__2.r / fld8_block3_1.vert[i__3], q__1.i = q__2.i / 
		    fld8_block3_1.vert[i__3];
	    fld8_block3_1.cpot[i__2].r = q__1.r, fld8_block3_1.cpot[i__2].i = q__1.i;
	}
	if (code >= 2.f && code < 2.9f) {
	    sivert_(&n, &fld8_c__9, &fld8_c__2);
	}
/* --- MAKE THE POINT UNAVAILABLE */
L1719:
	sivert_(&n, &fld8_c__10, &fld8_c__1);
	j = n;
	goto L167;
L173:
	;
    }
    i2 = lpnt << 1;
    if (n2 == 0 && cond > 0.f && (code < 2.f || code > 2.9f)) {
	fld8_block7_1.warn = 49;
    }
    if (fld8_block7_1.warn == 49) {
	io___251.ciunit = fld8_block7_1.out;
	s_wsfe(&io___251);
	e_wsfe();
    }
    i1 = npnts - 1;
/* --- MIN AND MAX LIMITS */
    xmin = fld8_block2_1.linc[i2];
    xmax = xmin;
    ymin = fld8_block2_1.linc[i2 + 1];
    ymax = ymin;
    i__1 = npnts;
    for (i__ = 2; i__ <= i__1; ++i__) {
	k1 = i2 + (i__ << 1);
	if (fld8_block2_1.linc[k1 - 2] < xmin) {
	    xmin = fld8_block2_1.linc[k1 - 2];
	}
	if (fld8_block2_1.linc[k1 - 2] > xmax) {
	    xmax = fld8_block2_1.linc[k1 - 2];
	}
	if (fld8_block2_1.linc[k1 - 1] < ymin) {
	    ymin = fld8_block2_1.linc[k1 - 1];
	}
	if (fld8_block2_1.linc[k1 - 1] > ymax) {
	    ymax = fld8_block2_1.linc[k1 - 1];
	}
/* L175: */
    }
    fld8_block3_1.datln[linac + 1049] = xmin;
    fld8_block3_1.datln[linac + 1199] = xmax;
    fld8_block3_1.datln[linac + 1349] = ymin;
    fld8_block3_1.datln[linac + 1499] = ymax;
/* --- LIMITS FOR LINE NUMBERS */
    n5 = 1;
    i__1 = fld8_block1_1.lnhor;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (fld8_block1_1.ypos[i__ - 1] < ymin) {
	    n5 = i__;
	}
	if (fld8_block1_1.ypos[i__ - 1] > ymax) {
	    goto L180;
	}
/* L177: */
    }
L180:
    n6 = i__;
    if (n6 > fld8_block1_1.lnhor) {
	n6 = fld8_block1_1.lnhor;
    }
    n7 = 1;
    i__1 = fld8_block1_1.lnver;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (fld8_block1_1.xpos[i__ - 1] < xmin) {
	    n7 = i__;
	}
	if (fld8_block1_1.xpos[i__ - 1] > xmax) {
	    goto L182;
	}
/* L181: */
    }
L182:
    n8 = i__;
    if (n8 > fld8_block1_1.lnver) {
	n8 = fld8_block1_1.lnver;
    }
/* --- SET N2=0 IF ALL SECTION BOUNDARIES ARE SPECIFIED AS FLUX LINES */
    if (n5 == 1 && n6 == fld8_block1_1.lnhor && n7 == 1 && n8 == fld8_block1_1.lnver && 
	    code == 2.f) {
	n2 = 0;
    }
/* --- SET POTENTIAL AND CODE FOR INTERIOR POINTS */
    if (n2 != 1) {
	goto L188;
    }
    i__1 = n6;
    for (irow = n5; irow <= i__1; ++irow) {
	i__2 = n8;
	for (icol = n7; icol <= i__2; ++icol) {
/* --- VERTEX NUMBER */
	    j = (irow - 1) * fld8_block1_1.lnver + icol;
	    x = fld8_block3_1.vert[j - 1];
	    y = fld8_block3_1.vert[j + 29999];
	    inter_(&intor, &i1, &lpnt, &x, &y);
	    if (intor == 0) {
		goto L183;
	    }
	    if (code == 2.f) {
		i__3 = j - 1;
		r__1 = conn * cos(dir);
		r__2 = conn * sin(dir);
		q__1.r = r__1, q__1.i = r__2;
		fld8_block3_1.cpot[i__3].r = q__1.r, fld8_block3_1.cpot[i__3].i = 
			q__1.i;
	    }
	    if (ivert_(&j, &fld8_c__9) != 2) {
		sivert_(&j, &fld8_c__9, &icode);
	    }
	    if (code == 1.f) {
		sivert_(&j, &fld8_c__9, &fld8_c__2);
	    }
	    if (ivert_(&j, &fld8_c__9) == 20) {
		goto L183;
	    }
	    if (code >= 4.f) {
		sivert_(&j, &fld8_c__9, &fld8_c__0);
	    }
	    if (code == 9.f) {
		sivert_(&j, &fld8_c__9, &fld8_c__3);
	    }
	    if (code == 10.f) {
		sivert_(&j, &fld8_c__9, &fld8_c__10);
	    }
L183:
	    ;
	}
/* L184: */
    }
/* --- REVERSE DIAGONAL IF THIS GIVES BETTER TRIANGLES, AND */
/* --- SET PERMEABILITY AND CONDUCTIVITY FOR INTERIOR TRIANGLES */
L188:
    if (n5 > 1) {
	--n5;
    }
    if (n7 > 1) {
	--n7;
    }
    if (n6 > norow) {
	n6 = norow;
    }
    if (n8 > fld8_block7_1.nocol) {
	n8 = fld8_block7_1.nocol;
    }
    if (perm == 0.f) {
	perm = 9.9e9f;
    }
    i__1 = n6;
    for (irow = n5; irow <= i__1; ++irow) {
	i__2 = n8;
	for (icol = n7; icol <= i__2; ++icol) {
	    e3 = 0.f;
	    e4 = 0.f;
/* --- FOUR CORNERS, STARTING FROM BOTTOM LEFT */
	    j1 = (irow - 1) * fld8_block1_1.lnver + icol;
	    j2 = j1 + 1;
	    j3 = j1 + fld8_block1_1.lnver;
	    j4 = j3 + 1;
	    if (ivert_(&j1, &fld8_c__10) == 0 && ivert_(&j2, &fld8_c__10) == 0 && 
		    ivert_(&j3, &fld8_c__10) == 0 && ivert_(&j4, &fld8_c__10) == 0) {
		goto L169;
	    }
/* --- FIRST TRIANGLE NUMBER */
	    n4 = (((irow - 1) * fld8_block7_1.nocol + icol) << 1) - 1;
	    if (fld8_block1_1.tri[n4 - 1] < 0.f) {
		goto L169;
	    }
	    if (fld8_block7_1.per == 1.f && (icol == 1 || icol == fld8_block7_1.nocol)) 
		    {
		goto L169;
	    }
	    if (fld8_block7_1.per == 2.f && (irow == 1 || irow == norow)) {
		goto L169;
	    }
/* --- NORMAL DIAGONAL (FROM BOTTOM LEFT TO TOP RIGHT CORNER) */
	    asp_(&j1, &j4, &j3, &e1, &d__);
	    asp_(&j1, &j2, &j4, &e2, &d__);
	    e3 = dmin(e1,e2);
/* --- REVERSED DIAGONAL */
	    asp_(&j1, &j2, &j3, &e1, &d__);
	    asp_(&j2, &j4, &j3, &e2, &d__);
	    e4 = dmin(e1,e2);
L169:
	    j = 1;
/* --- TRIANGLE NUMBER */
L174:
	    n4 = (((irow - 1) * fld8_block7_1.nocol + icol) << 1) - j;
	    if (j == 1 && e4 < e3) {
		sitri_(&n4, &fld8_c__0);
	    }
	    if (j == 1 && e3 < e4) {
		sitri_(&n4, &fld8_c__1);
	    }
/* --- SKIP IF NOT A CLOSED CURVE */
	    if (n2 != 1) {
		goto L178;
	    }
	    l = itri_(&n4, &fld8_c__1);
	    m = itri_(&n4, &fld8_c__2);
	    n = itri_(&n4, &fld8_c__3);
	    x = (fld8_block3_1.vert[l - 1] + fld8_block3_1.vert[m - 1] + fld8_block3_1.vert[
		    n - 1]) / 3.f;
	    y = (fld8_block3_1.vert[l + 29999] + fld8_block3_1.vert[m + 29999] + 
		    fld8_block3_1.vert[n + 29999]) / 3.f;
	    inter_(&intor, &i1, &lpnt, &x, &y);
	    if (intor != 1) {
		goto L1741;
	    }
	    if (fld8_block1_1.tri[n4 - 1] > 0.f) {
		fld8_block1_1.tri[n4 - 1] = perm;
	    }
	    if (fld8_block1_1.tri[n4 - 1] < 0.f) {
		fld8_block1_1.tri[n4 - 1] = -perm;
	    }
	    fld8_block1_1.tri[n4 + 59301] = cond;
	    fld8_block4_1.itri4[n4 - 1] = (shortint) linac;
	    if (code < 14.5f) {
		goto L1741;
	    }
	    fld8_blck11_1.relax = relaxi;
	    fld8_blck11_1.itmx = itmxi;
	    fld8_blck11_1.dptmx = dptmxi;
	    fld8_blck11_1.fact = facti;
	    magn_(&fld8_c_b576, &code, &perm);
	    if (fld8_block1_1.tri[n4 - 1] > 0.f) {
		fld8_block1_1.tri[n4 - 1] = perm;
	    }
	    if (fld8_block1_1.tri[n4 - 1] < 0.f) {
		fld8_block1_1.tri[n4 - 1] = -perm;
	    }
L1741:
	    ++j;
	    if (j >= 2) {
		j = 0;
	    }
	    if (j == 0) {
		goto L174;
	    }
L178:
	    ;
	}
/* L179: */
    }
/* --- ENTER VOLTAGE NUMBERS IN DATLN(J,6) */
/* --- AND NUMBER OF PARALLEL CONDUCTORS IN DATLN(J,7) */
    if (linac != 1) {
	goto L1791;
    }
    if ((code >= 4.f && code <= 8.f) || (code == 0.f && conn != 0.f)) {
	fld8_block1_1.nvolt = 1;
    }
    if (fld8_block1_1.nvolt == 1) {
	fld8_block3_1.datln[750] = 1.f;
    }
    goto L1793;
L1791:
    if ((code >= 1.f && code <= 3.f) || code >= 9.f) {
	goto L185;
    }
    if (code == 0.f && conn == 0.f) {
	goto L185;
    }
    if (code == 6.f || code == 8.f) {
	goto L1795;
    }
    j1 = 0;
    j2 = linac - 1;
    i__1 = j2;
    for (j = 1; j <= i__1; ++j) {
	if (code == 7.f && fld8_block3_1.datln[j + 599] == 7.f) {
	    j1 = j;
	}
	if (code == 0.f && conn == fld8_block3_1.datln[j + 299] && dir == 
		fld8_block3_1.datln[j + 449]) {
	    j1 = j;
	}
/* L1792: */
    }
    if (j1 != 0) {
	fld8_block3_1.datln[linac + 749] = fld8_block3_1.datln[j1 + 749];
    }
    if (j1 != 0) {
	goto L185;
    }
L1795:
    ++fld8_block1_1.nvolt;
    fld8_block3_1.datln[linac + 749] = (real) fld8_block1_1.nvolt;
L1793:
    if (code != 4.f && code != 5.f) {
	goto L185;
    }
    e1 = 0.f;
    i__1 = fld8_block1_1.linto;
    for (j = 1; j <= i__1; ++j) {
	if (conn == fld8_block3_1.datln[j + 299] && dir == fld8_block3_1.datln[j + 449] 
		&& fld8_block3_1.datln[j + 599] == 4.f) {
	    e1 += 1.f;
	}
	if (conn == fld8_block3_1.datln[j + 299] && dir == fld8_block3_1.datln[j + 449] 
		&& fld8_block3_1.datln[j + 599] == 5.f) {
	    e1 += .5f;
	}
/* L1794: */
    }
    fld8_block3_1.datln[linac + 899] = e1;
/* --- TAKE NEXT LINE */
L185:
    ++linac;
    lpnt += npnts;
    if (linac <= fld8_block1_1.linto) {
	goto L416;
    }
/* --- ABORT IF THERE ARE MORE THAN TEN INDEPENDENT VOLTAGES */
/* L1851: */
    if (fld8_block1_1.nvolt > 10) {
	fld8_block7_1.warn = 84;
    }
    if (fld8_block1_1.nvolt > 10) {
	goto L999;
    }
    if (fld8_block1_1.nvolt == 0) {
	goto L1860;
    }
/* --- ENTER CURRENTS IN ARRAY CURVO(J1,1) */
    j1 = 1;
L1852:
    i__1 = fld8_block1_1.linto;
    for (j = 1; j <= i__1; ++j) {
	e1 = (real) j1;
	if (e1 != fld8_block3_1.datln[j + 749]) {
	    goto L1853;
	}
	goto L1854;
L1853:
	;
    }
    goto L1859;
L1854:
    if (fld8_block3_1.datln[j + 599] == 8.f) {
	goto L1857;
    }
    if (fld8_block7_1.phas == 0.f || fld8_block7_1.phas == 2.f) {
	goto L1856;
    }
    e2 = fld8_block7_1.pi * 2.f * (1.f - fld8_block3_1.datln[j + 299]) / fld8_block7_1.phas;
L1855:
    i__1 = j1 - 1;
    r__1 = fld8_block7_1.phcur * cos(e2) / fld8_block3_1.datln[j + 899];
    r__2 = fld8_block7_1.phcur * sin(e2) / fld8_block3_1.datln[j + 899];
    q__1.r = r__1, q__1.i = r__2;
    fld8_block1_1.curvo[i__1].r = q__1.r, fld8_block1_1.curvo[i__1].i = q__1.i;
    if (fld8_block3_1.datln[j + 599] == 5.f) {
	i__1 = j1 - 1;
	i__2 = j1 - 1;
	q__1.r = fld8_block1_1.curvo[i__2].r / 2.f, q__1.i = fld8_block1_1.curvo[i__2]
		.i / 2.f;
	fld8_block1_1.curvo[i__1].r = q__1.r, fld8_block1_1.curvo[i__1].i = q__1.i;
    }
    if (fld8_block3_1.datln[j + 599] >= 6.f) {
	i__1 = j1 - 1;
	fld8_block1_1.curvo[i__1].r = 0.f, fld8_block1_1.curvo[i__1].i = 0.f;
    }
    goto L1858;
L1857:
    e2 = fld8_block3_1.datln[j + 449] * fld8_block7_1.pi / 180.f;
    i__1 = j1 - 1;
    r__1 = fld8_block3_1.datln[j + 299] * cos(e2);
    r__2 = fld8_block3_1.datln[j + 299] * sin(e2);
    q__1.r = r__1, q__1.i = r__2;
    fld8_block1_1.curvo[i__1].r = q__1.r, fld8_block1_1.curvo[i__1].i = q__1.i;
    goto L1859;
L1856:
    e2 = pio2 * (1.f - fld8_block3_1.datln[j + 299]);
    goto L1855;
L1858:
    if (fld8_block3_1.datln[j + 449] < 0.f) {
	i__1 = j1 - 1;
	i__2 = j1 - 1;
	q__1.r = -fld8_block1_1.curvo[i__2].r, q__1.i = -fld8_block1_1.curvo[i__2].i;
	fld8_block1_1.curvo[i__1].r = q__1.r, fld8_block1_1.curvo[i__1].i = q__1.i;
    }
L1859:
    ++j1;
    if (j1 <= fld8_block1_1.nvolt) {
	goto L1852;
    }
/* --- CHANGE COORDINATES TO METERS */
/* --- AND CHANGE POLAR COORDINATES TO CARTESIAN COORDINATES */
L1860:
    xctr = fld8_block1_1.ypos[fld8_block1_1.lnhor - 1] * .001f;
    yshft = 0.f;
    if (fld8_block1_1.xpos[fld8_block1_1.lnver - 1] > 3141.5927f && fld8_block1_1.xpos[
	    fld8_block1_1.lnver - 1] < 4712.389f) {
	yshft = fld8_block1_1.ypos[fld8_block1_1.lnhor - 1] * -.001f * sin(
		fld8_block1_1.xpos[fld8_block1_1.lnver - 1] * .001f);
    }
    if (fld8_block1_1.xpos[fld8_block1_1.lnver - 1] >= 4712.389f) {
	yshft = fld8_block1_1.ypos[fld8_block1_1.lnhor - 1] * .001f;
    }
    i__1 = fld8_block1_1.i6;
    for (j = 1; j <= i__1; ++j) {
	xj = fld8_block3_1.vert[j - 1];
	yj = fld8_block3_1.vert[j + 29999];
	fld8_block3_1.vert[j - 1] = xj * .001f;
	fld8_block3_1.vert[j + 29999] = yj * .001f;
	if (fld8_block1_1.flaxi > .5f) {
	    goto L1861;
	}
	xj = fld8_block3_1.vert[j - 1];
	yj = fld8_block3_1.vert[j + 29999];
	fld8_block3_1.vert[j - 1] = xctr - yj * cos(xj);
	fld8_block3_1.vert[j + 29999] = yj * sin(xj) + yshft;
L1861:
	;
    }
/* --- PHASE NUMBER AND SIGN */
    if (fld8_block7_1.phas == 0.f) {
	goto L1873;
    }
    e1 = 1.f;
    e2 = 1.f;
L1862:
    i__1 = fld8_block1_1.linto;
    for (j = 1; j <= i__1; ++j) {
	if (fld8_block3_1.datln[j + 299] == e1 && fld8_block3_1.datln[j + 449] == e2 && 
		fld8_block3_1.datln[j + 599] == 3.f) {
	    goto L1864;
	}
/* L1863: */
    }
    goto L1871;
L1864:
    e3 = 0.f;
    i__1 = fld8_block1_1.i5;
    for (j1 = 1; j1 <= i__1; ++j1) {
/* --- LINE NUMBER */
	j2 = fld8_block4_1.itri4[j1 - 1];
	if (j2 == 0) {
	    goto L1865;
	}
/* --- ADD AREAS WHERE PHASE NUMBER AND SIGN MATCH */
	if (fld8_block3_1.datln[j2 + 299] != e1 || fld8_block3_1.datln[j2 + 449] != e2) 
		{
	    goto L1865;
	}
	l = itri_(&j1, &fld8_c__1);
	m = itri_(&j1, &fld8_c__2);
	n = itri_(&j1, &fld8_c__3);
	asp_(&l, &m, &n, &fld8_c_b576, &d__);
	e3 += d__ / 2.f;
L1865:
	;
    }
/* --- TOTAL CURRENT */
    if (fld8_block7_1.phas == 2.f) {
	goto L1867;
    }
    e4 = fld8_block7_1.pi * 2.f * (1.f - e1) / fld8_block7_1.phas;
L1866:
    r__1 = fld8_block7_1.phcur * cos(e4);
    r__2 = fld8_block7_1.phcur * sin(e4);
    q__1.r = r__1, q__1.i = r__2;
    c1.r = q__1.r, c1.i = q__1.i;
    goto L1868;
L1867:
    e4 = pio2 * (1.f - e1);
    goto L1866;
L1868:
    if (e2 < 0.f) {
	q__1.r = -c1.r, q__1.i = -c1.i;
	c1.r = q__1.r, c1.i = q__1.i;
    }
/* --- ENTER CURRENT DENSITY IN ARRAY CDENS */
    q__1.r = c1.r / e3, q__1.i = c1.i / e3;
    c1.r = q__1.r, c1.i = q__1.i;
    i__1 = fld8_block1_1.i5;
    for (j1 = 1; j1 <= i__1; ++j1) {
	j2 = fld8_block4_1.itri4[j1 - 1];
	if (j2 == 0) {
	    goto L1869;
	}
	if (fld8_block3_1.datln[j2 + 299] != e1 || fld8_block3_1.datln[j2 + 449] != e2) 
		{
	    goto L1869;
	}
	i__2 = j1 - 1;
	fld8_block1_1.cdens[i__2].r = c1.r, fld8_block1_1.cdens[i__2].i = c1.i;
L1869:
	;
    }
L1871:
    if (e1 >= fld8_block7_1.phas) {
	goto L1872;
    }
    e1 += 1.f;
    goto L1862;
L1872:
    if (e2 < 0.f) {
	goto L1873;
    }
    e1 = 1.f;
    e2 = -1.f;
    goto L1862;
/* --- ENTER CURRENT DENSITIES FOR CODE 9.0 */
L1873:
    i__1 = fld8_block1_1.linto;
    for (j = 1; j <= i__1; ++j) {
	if (fld8_block3_1.datln[j + 599] != 9.f) {
	    goto L1882;
	}
	e3 = 0.f;
	i__2 = fld8_block1_1.i5;
	for (j1 = 1; j1 <= i__2; ++j1) {
	    j2 = fld8_block4_1.itri4[j1 - 1];
	    if (j2 != j) {
		goto L1880;
	    }
	    l = itri_(&j1, &fld8_c__1);
	    m = itri_(&j1, &fld8_c__2);
	    n = itri_(&j1, &fld8_c__3);
	    asp_(&l, &m, &n, &fld8_c_b576, &d__);
	    e3 += d__ / 2.f;
L1880:
	    ;
	}
	e4 = fld8_block3_1.datln[j + 449] * fld8_block7_1.pi / 180.f;
	r__1 = fld8_block3_1.datln[j + 299] * cos(e4);
	r__2 = fld8_block3_1.datln[j + 299] * sin(e4);
	q__2.r = r__1, q__2.i = r__2;
	q__1.r = q__2.r / e3, q__1.i = q__2.i / e3;
	c1.r = q__1.r, c1.i = q__1.i;
	i__2 = fld8_block1_1.i5;
	for (j1 = 1; j1 <= i__2; ++j1) {
	    j2 = fld8_block4_1.itri4[j1 - 1];
	    if (j2 != j) {
		goto L1881;
	    }
	    i__3 = j1 - 1;
	    fld8_block1_1.cdens[i__3].r = c1.r, fld8_block1_1.cdens[i__3].i = c1.i;
L1881:
	    ;
	}
L1882:
	;
    }
/* --- ENTER VOLTAGE NUMBERS IN ITRI5(J1) AND CORRECT THE PERMEABILITY */
    i__1 = fld8_block1_1.i5;
    for (j1 = 1; j1 <= i__1; ++j1) {
	j2 = fld8_block4_1.itri4[j1 - 1];
	j3 = 0;
	if (j2 != 0) {
	    j3 = fld8_block3_1.datln[j2 + 749];
	}
	fld8_block4_1.itri5[j1 - 1] = (shortint) j3;
	tj1 = fld8_block1_1.tri[j1 - 1];
	fld8_block1_1.tri[j1 - 1] = dabs(tj1);
	if (fld8_block1_1.tri[j1 - 1] > 9.8e9f) {
	    fld8_block1_1.tri[j1 - 1] = 0.f;
	}
/* L1874: */
    }
/* --- CHECK THAT AT LEAST ONE FLUX LINE IS SPECIFIED */
    i__ = 0;
    i__1 = fld8_block1_1.linto;
    for (j = 1; j <= i__1; ++j) {
	if (fld8_block3_1.datln[j + 599] >= 2.f && fld8_block3_1.datln[j + 599] < 2.9f) 
		{
	    i__ = 1;
	}
/* L1875: */
    }
    if (i__ != 1) {
	fld8_block7_1.warn = 88;
    }
L999:
    return 0;
} /* ela_ */

/* Subroutine */ int elb_(void)
{
    /* Format strings */
    static char fmt_1[] = "(/\002FOR CONDUCTOR BETWEEN\002)";
    static char fmt_2[] = "(\002  X-MIN    X-MAX    Y-MIN    Y-MAX\002)";
    static char fmt_3[] = "(\002  R-MIN    R-MAX    Z-MIN    Z-MAX\002)";
    static char fmt_4[] = "(f8.2,3f9.2/\002WITH PHASE CONNECTION\002,f4.1)";
    static char fmt_5[] = "(\002  TOTAL CURRENT\002,f10.2)";
    static char fmt_6[] = "(4x,\002PHASE ANGLE, DEGREES\002,f8.2)";
    static char fmt_7[] = "(\002  AVERAGE CURRENT DENSITY, A/SQ.MM\002,f8.3)";
    static char fmt_8[] = "(\002  MAX. CURRENT DENSITY, A/SQ.MM\002,f8.3)";
    static char fmt_9[] = "(\002  MAX./AVERAGE CURRENT DENSITY\002,f7.3)";
    static char fmt_10[] = "(\002  UNIFORM CURRENT LOSS, KW/M\002,1pe10.3"
	    "/\002  ACTUAL LOSS, KW/M\002,1pe10.3)";
    static char fmt_11[] = "(\002  UNIFORM CURRENT LOSS, KW/CIRCLE\002,1pe10"
	    ".3/\002  ACTUAL LOSS, KW/CIRCLE\002,1pe10.3)";
    static char fmt_12[] = "(\002  ACTUAL/UNIFORM CURRENT LOSS\002,f7.3)";
    static char fmt_13[] = "(\002  MAX. FLUX DENSITY\002,f7.4)";
    static char fmt_14[] = "(\002  LOSS, KW/M\002,1pe10.3)";
    static char fmt_15[] = "(\002  LOSS, KW/CIRCLE\002,1pe10.3)";
    static char fmt_16[] = "(\002  VOLTS/M\002,1pe10.3)";
    static char fmt_17[] = "(\002  VOLTS/CIRCLE\002,1pe10.3)";
    static char fmt_18[] = "(/\002FOR PHASE\002,f4.1)";
    static char fmt_19[] = "(\002  VOLTS/M, POSITIVE CURRENT\002,1pe10.3)";
    static char fmt_20[] = "(\002  VOLTS/CIRCLE, POSITIVE CURRENT\002,1pe10."
	    "3)";
    static char fmt_21[] = "(\002  CALCULATED POSITIVE CURRENT\002,f10.2)";
    static char fmt_22[] = "(\002  VOLTS/M, NEGATIVE CURRENT\002,1pe10.3)";
    static char fmt_23[] = "(\002  VOLTS/CIRCLE, NEGATIVE CURRENT\002,1pe10."
	    "3)";
    static char fmt_24[] = "(\002  CALCULATED NEGATIVE CURRENT\002,f10.2)";
    static char fmt_25[] = "(\002   DC RESISTANCE, OHM/M\002,1pe10.3/\002  A"
	    "C RESISTANCE, OHM/M\002,1pe10.3/\002  REACTANCE, OHM/M\002,1pe14"
	    ".3/\002  IMPEDANCE, OHM/M\002,1pe14.3)";
    static char fmt_26[] = "(\002  DC RESISTANCE, OHM/CIRCLE\002,1pe10.3/"
	    "\002  AC RESISTANCE, OH\rM/CIRCLE\002,1pe10.3/\002  REACTANCE, O"
	    "HM/CIRCLE\002,1pe14.3/\002   IMPEDANCE, OHM/CIRCLE\002,1pe14.3)";
    static char fmt_31[] = "(//\002RMS VECTOR POTENTIALS AT EACH NODE\002)";
    static char fmt_32[] = "(/\002HORIZONTAL LINE   NODE      X        Y    "
	    "   POT. REAL\r    IMAG.       TOTAL\002)";
    static char fmt_33[] = "(/\002HORIZONTAL LINE   NODE      R        Z    "
	    "   POT. REAL\r    IMAG.       TOTAL\002)";
    static char fmt_34[] = "(i8,i14,f10.2,f9.2,1x,1p3e12.3)";
    static char fmt_36[] = "(//\002FOR EACH TRIANGLE\002)";
    static char fmt_37[] = "(//\002HORIZONTAL ROW\002,i4)";
    static char fmt_38[] = "(/\002  NODE NUMBERS   REL. PERM.   M/(OHM*SQ.MM"
	    ")   A/SQ.MM, REAL   IMAG.      TOTAL\002)";
    static char fmt_39[] = "(i5,2i5,f10.2,f14.3,1pe19.3,1p2e11.3)";
    static char fmt_40[] = "(\002 B-X, REAL  B-X, IMAG  B-Y, REAL  B-Y, IMAG"
	    "   B-TOTAL, PEAK\002,12x,\002KW/CUB.DM\002)";
    static char fmt_41[] = "(\002 B-R, REAL  B-R, IMAG  B-Z, REAL  B-Z, IMAG"
	    "   B-TOTAL, PEAK\002,12x,\002KW/CUB.DM\002)";
    static char fmt_42[] = "(1pe10.3,1p3e11.3,1pe15.3,1pe22.3)";
    static char fmt_43[] = "(\002DATA FOR EACH TRIANGLE ARE GIVEN ON ONE PAI"
	    "R OF LINES\002/)";
    static char fmt_45[] = "(\002ERRONEOUS INPUT\002)";
    static char fmt_46[] = "(\002THERE ARE MORE THAN 150 CONTOUR LINES\002)";
    static char fmt_47[] = "(\002THE CONTOUR LINE IS DESCRIBED BY MORE THAN "
	    "150 POINTS\002)";
    static char fmt_48[] = "(\002THE TOTAL NUMBER OF POINTS EXCEEDS 1500\002)"
	    ;
    static char fmt_57[] = "(\002THE NUMBER OF HORIZONTAL OR VERTICAL GRID L"
	    "INES IS MORE\rTHAN 300\002)";
    static char fmt_58[] = "(\002THE NUMBER OF NODES IN THE GRID IS MORE THA"
	    "N 30000\002)";
    static char fmt_59[] = "(\002COORDINATES OF GRID DENSITY BREAK LINES ARE"
	    " NOT IN INCREASING ORDER\002)";
    static char fmt_60[] = "(\002THERE ARE NUMERICAL PROBLEMS WITH THE GAUSS"
	    "IAN ELIMINATION AT\002//\002NODE NO.      X(R)      Y(Z)\002/i6,"
	    "f13.2,f10.2/\002SEE USER'S MANUAL\002)";
    static char fmt_63[] = "(\002DUE TO THE PERIODICITY CONDITION, HALF THE "
	    "BAND WIDTH CAME OUT MORE THAN 175\002)";
    static char fmt_78[] = "(/\002WITH CODE=10, HALF THE BAND WIDTH CAME OUT"
	    " MORE THAN 175\002)";
    static char fmt_79[] = "(/\002THE RADIAL LINES SPAN MORE THAN 360 DEGR"
	    "EES\002)";
    static char fmt_81[] = "(/\002THE AREA CAME OUT NEGATIVE OR ZERO FOR TRI"
	    "ANGLE WITH\002)";
    static char fmt_82[] = "(\002CHANGE LINE SEQUENCE OR MOVE GRID LINES\002)"
	    ;
    static char fmt_84[] = "(/\002THE PROGRAM IS LIMITED TO TEN APPLIED VOLT"
	    "AGES. IN THIS CSE THERE ARE\002,i3,\002.\002)";
    static char fmt_85[] = "(\002NODE NUMBERS\002,7x,\002X\002,8x,\002Y\002)";
    static char fmt_86[] = "(\002NODE NUMBERS\002,7x,\002R\002,8x,\002Z\002)";
    static char fmt_87[] = "(4x,i5,f13.1,f9.1)";
    static char fmt_88[] = "(/\002THERE IS NO SPECIFIED FLUX LINE\002)";
    static char fmt_89[] = "(//\002FOR EACH CONDUCTOR:\002/\002THE UNIFORM C"
	    "URRENT LOSS IS CALCULATED FOR A UNIFORM DISTRIBUTION OF THE TOTAL"
	    "\002/\002CURRENT IN THAT CONDUCTOR. THIS MEANS THAT IF THERE ARE"
	    " SEVERAL PARALLEL\002/\002CONDUCTORS NOT SHARING THE TOTAL PHAS"
	    "E\r CURRENT EQUALLY, THE UNIFORM CURRENT LOSS\002/\002WILL NOT B"
	    "E THE SAME IN EACH PARALLEL CONDUCTOR. THE ACTUAL LOSS IS CALCUL"
	    "ATED\002/\002BY A SUMMATION OF I-SQUARED TIMES R FOR EACH TRIANG"
	    "LE.\002//\002FOR EACH PHASE:\002/\002THE UNIFORM CURRENT LOSS IS"
	    " CALCULATED FOR\rA UNIFORM DISTRIBUTION OF THE TOTAL\002/\002PHA"
	    "SE CURRENT BETWEEN ALL PARALLEL CONDUCTORS (SAME CURRENT DENSITY"
	    "). THE ACTUAL\002/\002LOSS IS CALCULATED BY TAKING THE REAL PART"
	    " OF U TIMES I-CONJUGATE. BECAUSE\r LOS\002s/\002IN ONE PHASE MAY"
	    " BE PARTLY SUPPLIED BY ANOTHER PHASE, THE ACTUAL LOSS MAY BE\002/"
	    "\002LESS THAN THE UNIFORM CURRENT LOSS.\002)";
    static char fmt_90[] = "(\002  FORCE AT MAX. CURRENT, NEWTON/M, F-X\002,"
	    "1pe11.3/35x,\002F-Y\002,1pe11.3)";
    static char fmt_91[] = "(\002  FORCE AT MAX. CURRENT, NEWTON/CIRCLE, F-"
	    "R\002,1pe11.3/40x,\002F-Z\002,1pe11.3)";
    static char fmt_92[] = "(\002  FORCE AT T=0, NEWTON/M, F-X\002,1pe11.3/2"
	    "6x,\002F-Y\002,1pe11.3)";
    static char fmt_93[] = "(\002  FORCE AT T=0, NEWTON/CIRCLE, F-R\002,1pe1"
	    "1.3/31x,\002F-Z\002,1pe11.3)";
    static char fmt_94[] = "(\002FOR ALL THE PHASES:\002)";
    static char fmt_95[] = "(\002  UNIFORM CURRENT LOSS, KW/M\002,1pe10.3"
	    "/\002  ACTUAL LOSS, RE(U*I-CONJUGATE), KW/M\002,1pe10.3)";
    static char fmt_96[] = "(\002  UNIFORM CURRENT LOSS, KW/CIRCLE\002,1pe10"
	    ".3/\002  ACTUAL LOSS, RE(U*I-CONJUGATE), KW/CIRCLE\002,1pe10.3)";
    static char fmt_97[] = "(/\002FOR ALL THE CONDUCTORS:\002/\002  LOSS, RE"
	    "(U*I-CONJUGATE), KW/M\002,1pe10.3/\002  LOSS, I-SQUARED*R, KW/"
	    "M\002,1pe10.3)";
    static char fmt_98[] = "(/\002FOR ALL THE CONDUCTORS:\002/\002  LOSS, RE"
	    "(U*I-CONJUGATE), KW/CIRCLE\002,1pe10.3/\002  LOSS, I-SQUARED*R, "
	    "KW/CIRCLE\002,1pe10.3)";
    static char fmt_99[] = "(\002WITHIN NUMERICAL ACCURACY, THE LOSSES CALCU"
	    "LATED\002/\002BY THE TWO METHODS SHOULD BE THE SAME.\002)";
    static char fmt_100[] = "(\002  DEPTH OF PENETRATION\002,f8.3)";
    static char fmt_101[] = "(\002  SUM BX-SQUARED TIMES CUB.M\002,1pe10.3"
	    "/\002  SUM BY-SQUARED TIMES CUB.M\002,1pe10.3/\002  BX-MAX\002,1"
	    "pe10.3/\002  BY-MAX\002,1pe10.3)";
    static char fmt_102[] = "(\002  SUM BR-SQUARED TIMES CUB.M\002,1pe10.3"
	    "/\002  SUM BZ-SQUARED TIMES CUB.M\002,1pe10.3/\002  BR-MAX\002,1"
	    "pe10.3/\002  BZ-MAX\002,1pe10.3)";
    static char fmt_103[] = "(/\0021/2 H*B (PEAK VALUES) INTEGRATED OVER VOL"
	    "UME, WS/M\002,1pe13.6)";
    static char fmt_104[] = "(/\0021/2 H*B (PEAK VALUES) INTEGRATED OVER VOL"
	    "UME, WS/CIRCLE\002,1pe13.6)";
    static char fmt_114[] = "(//\002ITERATION NO.   MAX. PC CHANGE OF VECTOR"
	    " POTENTIAL\002)";
    static char fmt_115[] = "(5x,i2,f28.3)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;
    real r__1, r__2, r__3, r__4;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7;

    /* Builtin functions */
    double r_imag(complex *), sin(doublereal), cos(doublereal), sqrt(
	    doublereal), log(doublereal), exp(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    void c_div(complex *, complex *, complex *);
    double c_abs(complex *);
    void r_cnjg(complex *, complex *);

    /* Local variables */
    static real b, d__;
    static integer i__, j, k, l, m, n;
    static complex c1, c2, c3, c4, c5, c6;
    static real e1;
    static integer i1, i2, i3, i7, i4, l1, m1, n1;
    static real e2;
    static integer l2, l3, l4, l5, l6;
    static real e3;
    static integer j2, l7, l8, j3, j4, j1, k1;
    static real e5, e6, e7, e4;
    static integer i8, i9;
    static real t1, t2;
    static complex ac, cd;
    static real e11, e12;
    static integer i10;
    static complex ci, al, am, an;
    static integer i24, i41, i42, i43;
    static real rc, sd;
    static complex bx, by;
    static real fx, fy, xl, yl, xm, ym, xn, yn;
    static integer nx, ny, nz, it1, it2, iv1;
    static real tj2;
    static integer iv2, it3;
    static real sd10;
    static integer hbw;
    static complex sjd;
    static real bxi, byi, ti41, sdr;
    static complex sdu;
    static real bxr, byr, pio2, angc;
    extern doublereal absc_(complex *);
    static real code, beta;
    static complex cneg;
    extern /* Subroutine */ int magn_(real *, real *, real *);
    static integer icmn[150];
    static real cond, bmax, sdgn;
    static complex uneg;
    static integer icmx[150];
    static complex cpos;
    extern integer itri_(integer *, integer *);
    static complex curr[100]	/* was [10][10] */;
    extern /* Subroutine */ int subd_(real *, real *, real *, real *, real *, 
	    real *, real *);
    static real perm;
    extern /* Subroutine */ int bufr_(integer *, integer *, integer *, 
	    integer *);
    static real dpot, conn, phno, sdgp;
    static complex upos;
    static real wmag;
    extern integer novx1_(integer *, integer *, integer *, real *), novx2_(
	    integer *, integer *, integer *, real *);
    static real cdabs;
    static integer icod10;
    static real cdneg, cnega;
    static complex coeff[30625]	/* was [175][175] */;
    static integer icode;
    extern /* Subroutine */ int angle_(real *, real *, real *, real *, real *)
	    ;
    static complex cdatl[300]	/* was [150][2] */;
    static real omega;
    extern /* Subroutine */ int cmang_(complex *, real *, complex *, real *);
    static integer linac;
    static shortint avail[8];
    static real grrad, bxabs;
    static complex ccomp[350];
    static integer ivera[8];
    static real byabs;
    static complex ctemp;
    static integer ncode;
    static real cdmax, salph, bxmax;
    extern /* Subroutine */ int incur_(integer *, complex *, complex *);
    static complex curri[100]	/* was [10][10] */;
    extern integer ivert_(integer *, integer *);
    static integer jexit;
    static real bxvol, byvol, bymax, twopi, sloss, dloss, sulph, potmx, uloss,
	     sdpos, sdneg, cdpos, uposa, cposa, unega, aloss;
    extern /* Subroutine */ int sivert_(integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___327 = { 0, 0, 0, fmt_81, 0 };
    static cilist io___328 = { 0, 0, 0, fmt_85, 0 };
    static cilist io___329 = { 0, 0, 0, fmt_86, 0 };
    static cilist io___331 = { 0, 0, 0, fmt_87, 0 };
    static cilist io___332 = { 0, 0, 0, fmt_87, 0 };
    static cilist io___333 = { 0, 0, 0, fmt_87, 0 };
    static cilist io___334 = { 0, 0, 0, fmt_82, 0 };
    static cilist io___372 = { 0, 0, 0, fmt_114, 0 };
    static cilist io___373 = { 0, 0, 0, fmt_115, 0 };
    static cilist io___378 = { 0, 0, 0, fmt_89, 0 };
    static cilist io___382 = { 0, 0, 0, fmt_1, 0 };
    static cilist io___383 = { 0, 0, 0, fmt_2, 0 };
    static cilist io___384 = { 0, 0, 0, fmt_3, 0 };
    static cilist io___385 = { 0, 0, 0, fmt_4, 0 };
    static cilist io___406 = { 0, 0, 0, fmt_16, 0 };
    static cilist io___407 = { 0, 0, 0, fmt_17, 0 };
    static cilist io___408 = { 0, 0, 0, fmt_6, 0 };
    static cilist io___409 = { 0, 0, 0, fmt_13, 0 };
    static cilist io___410 = { 0, 0, 0, fmt_5, 0 };
    static cilist io___411 = { 0, 0, 0, fmt_6, 0 };
    static cilist io___412 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___413 = { 0, 0, 0, fmt_7, 0 };
    static cilist io___414 = { 0, 0, 0, fmt_8, 0 };
    static cilist io___415 = { 0, 0, 0, fmt_9, 0 };
    static cilist io___416 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___417 = { 0, 0, 0, fmt_11, 0 };
    static cilist io___418 = { 0, 0, 0, fmt_12, 0 };
    static cilist io___419 = { 0, 0, 0, fmt_14, 0 };
    static cilist io___420 = { 0, 0, 0, fmt_15, 0 };
    static cilist io___421 = { 0, 0, 0, fmt_90, 0 };
    static cilist io___422 = { 0, 0, 0, fmt_92, 0 };
    static cilist io___423 = { 0, 0, 0, fmt_91, 0 };
    static cilist io___424 = { 0, 0, 0, fmt_93, 0 };
    static cilist io___425 = { 0, 0, 0, fmt_101, 0 };
    static cilist io___426 = { 0, 0, 0, fmt_102, 0 };
    static cilist io___441 = { 0, 0, 0, fmt_18, 0 };
    static cilist io___443 = { 0, 0, 0, fmt_19, 0 };
    static cilist io___444 = { 0, 0, 0, fmt_20, 0 };
    static cilist io___445 = { 0, 0, 0, fmt_6, 0 };
    static cilist io___447 = { 0, 0, 0, fmt_21, 0 };
    static cilist io___448 = { 0, 0, 0, fmt_6, 0 };
    static cilist io___450 = { 0, 0, 0, fmt_22, 0 };
    static cilist io___451 = { 0, 0, 0, fmt_23, 0 };
    static cilist io___452 = { 0, 0, 0, fmt_6, 0 };
    static cilist io___454 = { 0, 0, 0, fmt_24, 0 };
    static cilist io___455 = { 0, 0, 0, fmt_6, 0 };
    static cilist io___457 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___458 = { 0, 0, 0, fmt_11, 0 };
    static cilist io___459 = { 0, 0, 0, fmt_12, 0 };
    static cilist io___460 = { 0, 0, 0, fmt_25, 0 };
    static cilist io___461 = { 0, 0, 0, fmt_26, 0 };
    static cilist io___462 = { 0, 0, 0, fmt_94, 0 };
    static cilist io___463 = { 0, 0, 0, fmt_95, 0 };
    static cilist io___464 = { 0, 0, 0, fmt_96, 0 };
    static cilist io___465 = { 0, 0, 0, fmt_12, 0 };
    static cilist io___466 = { 0, 0, 0, fmt_97, 0 };
    static cilist io___467 = { 0, 0, 0, fmt_98, 0 };
    static cilist io___468 = { 0, 0, 0, fmt_99, 0 };
    static cilist io___470 = { 0, 0, 0, fmt_103, 0 };
    static cilist io___471 = { 0, 0, 0, fmt_104, 0 };
    static cilist io___472 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___473 = { 0, 0, 0, fmt_32, 0 };
    static cilist io___474 = { 0, 0, 0, fmt_33, 0 };
    static cilist io___475 = { 0, 0, 0, fmt_34, 0 };
    static cilist io___476 = { 0, 0, 0, fmt_36, 0 };
    static cilist io___479 = { 0, 0, 0, fmt_37, 0 };
    static cilist io___480 = { 0, 0, 0, fmt_38, 0 };
    static cilist io___486 = { 0, 0, 0, fmt_39, 0 };
    static cilist io___487 = { 0, 0, 0, fmt_40, 0 };
    static cilist io___488 = { 0, 0, 0, fmt_41, 0 };
    static cilist io___489 = { 0, 0, 0, fmt_42, 0 };
    static cilist io___490 = { 0, 0, 0, fmt_43, 0 };
    static cilist io___491 = { 0, 0, 0, fmt_45, 0 };
    static cilist io___492 = { 0, 0, 0, fmt_46, 0 };
    static cilist io___493 = { 0, 0, 0, fmt_47, 0 };
    static cilist io___494 = { 0, 0, 0, fmt_48, 0 };
    static cilist io___495 = { 0, 0, 0, fmt_57, 0 };
    static cilist io___496 = { 0, 0, 0, fmt_58, 0 };
    static cilist io___497 = { 0, 0, 0, fmt_59, 0 };
    static cilist io___498 = { 0, 0, 0, fmt_63, 0 };
    static cilist io___499 = { 0, 0, 0, fmt_78, 0 };
    static cilist io___500 = { 0, 0, 0, fmt_79, 0 };
    static cilist io___501 = { 0, 0, 0, fmt_84, 0 };
    static cilist io___502 = { 0, 0, 0, fmt_88, 0 };
    static cilist io___503 = { 0, 0, 0, fmt_60, 0 };


/* --- SKIN EFFECT AND EDDY CURRENTS, PART 2 */
/* L1: */
/* L2: */
/* L3: */
/* L4: */
/* L5: */
/* L6: */
/* L7: */
/* L8: */
/* L9: */
/* L10: */
/* L11: */
/* L12: */
/* L13: */
/* L14: */
/* L15: */
/* L16: */
/* L17: */
/* L18: */
/* L19: */
/* L20: */
/* L21: */
/* L22: */
/* L23: */
/* L24: */
/* L25: */
/* L26: */
/* L31: */
/* L32: */
/* L33: */
/* L34: */
/* L36: */
/* L37: */
/* L38: */
/* L39: */
/* L40: */
/* L41: */
/* L42: */
/* L43: */
/* L45: */
/* L46: */
/* L47: */
/* L48: */
/* L57: */
/* L58: */
/* L59: */
/* L60: */
/* L63: */
/* L78: */
/* L79: */
/* L81: */
/* L82: */
/* L84: */
/* L85: */
/* L86: */
/* L87: */
/* L88: */
/* L89: */
/* L90: */
/* L91: */
/* L92: */
/* L93: */
/* L94: */
/* L95: */
/* L96: */
/* L97: */
/* L98: */
/* L99: */
/* L100: */
/* L101: */
/* L102: */
/* L103: */
/* L104: */
/* L114: */
/* L115: */
    if (fld8_block7_1.warn != 0) {
	goto L2151;
    }
    grrad = 180.f / fld8_block7_1.pi;
    pio2 = fld8_block7_1.pi / 2.f;
    twopi = fld8_block7_1.pi * 2.f;
    omega = twopi * fld8_block1_1.freq;
    q__1.r = 0.f, q__1.i = omega;
    c1.r = q__1.r, c1.i = q__1.i;
    fld8_block9_1.n4 = 1;
    i7 = 0;
    i10 = 0;
    angc = 0.f;
/* --- ESTABLISH PERMEABILITIES FOR SATURABLE IRON */
    if (fld8_blck11_1.itmx == 0 || fld8_blck12_1.itac <= 1) {
	goto L181;
    }
    i__ = 1;
L176:
    j = fld8_block4_1.itri4[i__ - 1];
    code = fld8_block3_1.datln[j + 599];
    icode = code;
    if (code < 14.5f || fld8_block1_1.tri[i__ - 1] <= 0.f) {
	goto L180;
    }
/* L177: */
    l = itri_(&i__, &fld8_c__1);
    m = itri_(&i__, &fld8_c__2);
    n = itri_(&i__, &fld8_c__3);
    xl = fld8_block3_1.vert[l - 1];
    yl = fld8_block3_1.vert[l + 29999];
    xm = fld8_block3_1.vert[m - 1];
    ym = fld8_block3_1.vert[m + 29999];
    xn = fld8_block3_1.vert[n - 1];
    yn = fld8_block3_1.vert[n + 29999];
    subd_(&d__, &xm, &ym, &xn, &yn, &xl, &yl);
    if (d__ > 0.f) {
	goto L178;
    }
    fld8_block7_1.warn = 81;
    goto L999;
L178:
    i__1 = l - 1;
    al.r = fld8_block3_1.cpot[i__1].r, al.i = fld8_block3_1.cpot[i__1].i;
    i__1 = m - 1;
    am.r = fld8_block3_1.cpot[i__1].r, am.i = fld8_block3_1.cpot[i__1].i;
    i__1 = n - 1;
    an.r = fld8_block3_1.cpot[i__1].r, an.i = fld8_block3_1.cpot[i__1].i;
    q__3.r = al.r + am.r, q__3.i = al.i + am.i;
    q__2.r = q__3.r + an.r, q__2.i = q__3.i + an.i;
    q__1.r = q__2.r / 3.f, q__1.i = q__2.i / 3.f;
    ac.r = q__1.r, ac.i = q__1.i;
    rc = (xl + xm + xn) / 3.f;
    r__1 = xm - xn;
    q__5.r = r__1 * al.r, q__5.i = r__1 * al.i;
    r__2 = xn - xl;
    q__6.r = r__2 * am.r, q__6.i = r__2 * am.i;
    q__4.r = q__5.r + q__6.r, q__4.i = q__5.i + q__6.i;
    r__3 = xl - xm;
    q__7.r = r__3 * an.r, q__7.i = r__3 * an.i;
    q__3.r = q__4.r + q__7.r, q__3.i = q__4.i + q__7.i;
    q__2.r = q__3.r / d__, q__2.i = q__3.i / d__;
    q__1.r = q__2.r * 1.4142136f, q__1.i = q__2.i * 1.4142136f;
    bx.r = q__1.r, bx.i = q__1.i;
    r__1 = ym - yn;
    q__5.r = r__1 * al.r, q__5.i = r__1 * al.i;
    r__2 = yn - yl;
    q__6.r = r__2 * am.r, q__6.i = r__2 * am.i;
    q__4.r = q__5.r + q__6.r, q__4.i = q__5.i + q__6.i;
    r__3 = yl - ym;
    q__7.r = r__3 * an.r, q__7.i = r__3 * an.i;
    q__3.r = q__4.r + q__7.r, q__3.i = q__4.i + q__7.i;
    q__2.r = q__3.r / d__, q__2.i = q__3.i / d__;
    q__1.r = q__2.r * 1.4142136f, q__1.i = q__2.i * 1.4142136f;
    by.r = q__1.r, by.i = q__1.i;
    if (fld8_block1_1.flaxi > 1.5f) {
	q__3.r = ac.r / rc, q__3.i = ac.i / rc;
	q__2.r = q__3.r * 1.4142136f, q__2.i = q__3.i * 1.4142136f;
	q__1.r = by.r + q__2.r, q__1.i = by.i + q__2.i;
	by.r = q__1.r, by.i = q__1.i;
    }
    bxabs = absc_(&bx);
    byabs = absc_(&by);
    bxr = bx.r;
    byr = by.r;
    bxi = r_imag(&bx);
    byi = r_imag(&by);
    bxabs = absc_(&bx);
    byabs = absc_(&by);
    angle_(&byi, &byr, &fld8_c_b111, &e11, &fld8_block7_1.pi);
    angle_(&bxi, &bxr, &fld8_c_b111, &e12, &fld8_block7_1.pi);
    beta = e11 - e12;
    e11 = byabs / 2.f * sin(beta);
/* Computing 2nd power */
    r__1 = byabs / 2.f * cos(beta);
    e12 = r__1 * r__1;
/* Computing 2nd power */
    r__1 = bxabs / 2.f - e11;
/* Computing 2nd power */
    r__2 = bxabs / 2.f + e11;
    b = sqrt(r__1 * r__1 + e12) + sqrt(r__2 * r__2 + e12);
    magn_(&b, &code, &perm);
    e1 = log(fld8_block1_1.tri[i__ - 1]);
    fld8_block1_1.tri[i__ - 1] = exp(e1 + fld8_blck11_1.relax * (log(perm) - e1));
    if (i__ != 1561) {
	goto L179;
    }
L179:
    if (b <= 1.f && fld8_blck12_1.itac >= 10) {
	fld8_block1_1.tri[i__ - 1] = perm;
    }
L180:
    ++i__;
    if (i__ <= fld8_block1_1.i5) {
	goto L176;
    }
    goto L2021;
/* --- ADJOINING VERTEX NUMBERS */
L181:
    i__1 = fld8_block1_1.lnhor;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = fld8_block1_1.lnver;
	for (j = 1; j <= i__2; ++j) {
/* --- VERTEX NUMBER */
	    l = (i__ - 1) * fld8_block1_1.lnver + j;
	    if (ivert_(&l, &fld8_c__9) == 2) {
		goto L202;
	    }
/* --- FIRST TRIANGLE, BOTTOM ROW */
	    m = (((i__ - 2) * fld8_block7_1.nocol + j) << 1) - 3;
/* --- TOP ROW */
	    n = m + (fld8_block7_1.nocol << 1);
	    for (k = 1; k <= 8; ++k) {
		avail[k - 1] = 0;
		fld8_block6_1.ntri[k - 1] = 0;
		i1 = ivert_(&l, &k);
		if (i1 == 0) {
		    goto L190;
		}
		i2 = m - 1;
L186:
		++i2;
		if (i2 > m + 3 && i2 < n) {
		    i2 = n;
		}
		if (i2 > n + 3 || i2 > fld8_block1_1.i5) {
		    goto L190;
		}
		if (i2 < 1) {
		    goto L186;
		}
		if (fld8_block1_1.tri[i2 - 1] <= 0.f) {
		    goto L186;
		}
		i3 = 0;
		for (i4 = 1; i4 <= 3; ++i4) {
		    i24 = itri_(&i2, &i4);
		    if (i24 == l || i24 == i1) {
			++i3;
		    }
/* L187: */
		}
		if (i3 != 2) {
		    goto L186;
		}
		avail[k - 1] = 1;
L190:
		;
	    }
/* --- REMOVE SUPERFLUOUS NUMBERS */
	    for (k = 1; k <= 8; ++k) {
		if (avail[k - 1] == 1) {
		    goto L191;
		}
		sivert_(&l, &k, &fld8_c__0);
L191:
		;
	    }
L202:
	    ;
	}
/* L203: */
    }
L2021:
    icod10 = 0;
    i__1 = fld8_block1_1.linto;
    for (i__ = 1; i__ <= i__1; ++i__) {
	icmn[i__ - 1] = 90000;
	icmx[i__ - 1] = 0;
	if (fld8_block3_1.datln[i__ + 599] == 10.f) {
	    i__2 = i__ - 1;
	    r__1 = fld8_block3_1.datln[i__ + 299] * cos(fld8_block3_1.datln[i__ + 449] /
		     grrad);
	    r__2 = fld8_block3_1.datln[i__ + 299] * sin(fld8_block3_1.datln[i__ + 449] /
		     grrad);
	    q__1.r = r__1, q__1.i = r__2;
	    cdatl[i__2].r = q__1.r, cdatl[i__2].i = q__1.i;
	}
	fld8_block3_1.datln[i__ + 1799] = 0.f;
/* L2031: */
	fld8_block3_1.datln[i__ + 1949] = 0.f;
    }
    i__1 = fld8_block1_1.i5;
    for (i__ = 1; i__ <= i__1; ++i__) {
	l = itri_(&i__, &fld8_c__1);
	m = itri_(&i__, &fld8_c__2);
	n = itri_(&i__, &fld8_c__3);
	j = fld8_block4_1.itri4[i__ - 1];
	if (j <= 0) {
	    goto L2032;
	}
	if (fld8_block3_1.datln[j + 599] != 10.f) {
	    goto L2032;
	}
	icod10 = 1;
	l1 = novx2_(&l, &fld8_block1_1.lnhor, &fld8_block1_1.lnver, &fld8_block7_1.per);
	m1 = novx2_(&m, &fld8_block1_1.lnhor, &fld8_block1_1.lnver, &fld8_block7_1.per);
	n1 = novx2_(&n, &fld8_block1_1.lnhor, &fld8_block1_1.lnver, &fld8_block7_1.per);
/* Computing MIN */
	i__2 = min(l1,m1);
	i1 = min(i__2,n1);
/* Computing MAX */
	i__2 = max(l1,m1);
	i2 = max(i__2,n1);
	if (i1 < icmn[j - 1]) {
	    icmn[j - 1] = i1;
	}
	if (i2 > icmx[j - 1]) {
	    icmx[j - 1] = i2;
	}
L2032:
	xl = fld8_block3_1.vert[l - 1];
	yl = fld8_block3_1.vert[l + 29999];
	xm = fld8_block3_1.vert[m - 1];
	ym = fld8_block3_1.vert[m + 29999];
	xn = fld8_block3_1.vert[n - 1];
	yn = fld8_block3_1.vert[n + 29999];
	subd_(&d__, &xm, &ym, &xn, &yn, &xl, &yl);
	if (d__ > 0.f) {
	    goto L2033;
	}
	fld8_block7_1.warn = 81;
	io___327.ciunit = fld8_block7_1.out;
	s_wsfe(&io___327);
	e_wsfe();
	if (fld8_block1_1.flaxi < 1.5f) {
	    io___328.ciunit = fld8_block7_1.out;
	    s_wsfe(&io___328);
	    e_wsfe();
	}
	if (fld8_block1_1.flaxi > 1.5f) {
	    io___329.ciunit = fld8_block7_1.out;
	    s_wsfe(&io___329);
	    e_wsfe();
	}
	e1 = xl * 1e3f;
	e2 = yl * 1e3f;
	io___331.ciunit = fld8_block7_1.out;
	s_wsfe(&io___331);
	do_fio(&fld8_c__1, (char *)&l, (ftnlen)sizeof(integer));
	do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
	e_wsfe();
	e1 = xm * 1e3f;
	e2 = ym * 1e3f;
	io___332.ciunit = fld8_block7_1.out;
	s_wsfe(&io___332);
	do_fio(&fld8_c__1, (char *)&m, (ftnlen)sizeof(integer));
	do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
	e_wsfe();
	e1 = xn * 1e3f;
	e2 = yn * 1e3f;
	io___333.ciunit = fld8_block7_1.out;
	s_wsfe(&io___333);
	do_fio(&fld8_c__1, (char *)&n, (ftnlen)sizeof(integer));
	do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
	e_wsfe();
	io___334.ciunit = fld8_block7_1.out;
	s_wsfe(&io___334);
	e_wsfe();
L2033:
	if (j <= 0) {
	    goto L2034;
	}
	if (fld8_block3_1.datln[j + 599] != 10.f) {
	    goto L2034;
	}
	fld8_block3_1.datln[j + 1799] += d__;
	rc = (xl + xm + xn) / 3.f;
	fld8_block3_1.datln[j + 1949] += d__ / rc;
L2034:
	;
    }
    if (fld8_block7_1.warn == 81) {
	goto L2151;
    }
    l1 = fld8_block1_1.lnver;
    if (fld8_block7_1.per == 1.f || fld8_block7_1.per == 3.f) {
/* Computing MIN */
	i__1 = (fld8_block1_1.lnver << 1) - 3;
	l1 = min(i__1,173);
    }
    if (fld8_block7_1.per == 2.f || fld8_block7_1.per == 4.f) {
/* Computing MIN */
	i__1 = (fld8_block1_1.lnhor << 1) - 3;
	l1 = min(i__1,173);
    }
    if (fld8_block1_1.lnver > fld8_block1_1.lnhor && fld8_block7_1.per < .5f) {
	l1 = fld8_block1_1.lnhor;
    }
    k = 0;
    if (icod10 == 0) {
	goto L2038;
    }
    i__1 = fld8_block1_1.linto;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = icmx[i__ - 1] - icmn[i__ - 1];
	if (j > k) {
	    k = j;
	}
/* L2037: */
    }
    if (k > l1) {
	l1 = k;
    }
    if (l1 > 173) {
	fld8_block7_1.warn = 78;
    }
    if (l1 > 173) {
	goto L2151;
    }
/* --- HALF BAND WIDTH, COEFFICIENT MATRIX */
L2038:
    hbw = l1 + 2;
    l2 = hbw << 1;
    l3 = hbw - 1;
    l4 = hbw + 1;
    if (fld8_block1_1.nvolt == 0) {
	goto L206;
    }
/* --- INITIALIZE APPLIED VOLTAGE NUMBER */
    iv1 = 1;
/* --- INITIALIZE CURRENTS IN ARRAY CURR */
    i__1 = fld8_block1_1.nvolt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = fld8_block1_1.nvolt;
	for (j = 1; j <= i__2; ++j) {
/* L193: */
	    i__3 = i__ + j * 10 - 11;
	    curr[i__3].r = 0.f, curr[i__3].i = 0.f;
	}
/* L194: */
    }
/* --- VOLTAGES IN ARRAY CURVO */
L204:
    i__1 = fld8_block1_1.nvolt;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L205: */
	i__3 = i__ + 9;
	fld8_block1_1.curvo[i__3].r = 0.f, fld8_block1_1.curvo[i__3].i = 0.f;
    }
    i__3 = iv1 + 9;
    fld8_block1_1.curvo[i__3].r = 1.f, fld8_block1_1.curvo[i__3].i = 0.f;
/* --- LINE NUMBER IN ARRAY COEFF */
L206:
    l5 = 1;
    i__3 = fld8_block1_1.i6;
    for (i__ = 1; i__ <= i__3; ++i__) {
/* --- VERTEX NUMBER IN ARRAY VERT */
	jexit = 1;
	l = novx1_(&i__, &fld8_block1_1.lnhor, &fld8_block1_1.lnver, &fld8_block7_1.per);
	xl = fld8_block3_1.vert[l - 1];
	yl = fld8_block3_1.vert[l + 29999];
/* --- INITIALIZE */
	i__1 = l2;
	for (k = 1; k <= i__1; ++k) {
/* L61: */
	    i__2 = k - 1;
	    ccomp[i__2].r = 0.f, ccomp[i__2].i = 0.f;
	}
	sd10 = 0.f;
	l6 = hbw - i__;
	if (ivert_(&l, &fld8_c__9) == 2) {
	    goto L62;
	}
L1941:
	i1 = 1;
	for (i2 = 1; i2 <= 8; ++i2) {
	    ivera[i2 - 1] = 0;
	    if (ivert_(&l, &i2) == 0) {
		goto L1942;
	    }
	    ivera[i1 - 1] = ivert_(&l, &i2);
	    ++i1;
L1942:
	    ;
	}
/* --- ROW AND COLUMN NUMBERS IN ARRAY VERT */
	m1 = (l - 1) / fld8_block1_1.lnver + 1;
	n1 = l - (m1 - 1) * fld8_block1_1.lnver;
/* --- FIRST TRIANGLE, BOTTOM ROW */
	m = (((m1 - 2) * fld8_block7_1.nocol + n1) << 1) - 3;
/* --- TOP ROW */
	n = m + (fld8_block7_1.nocol << 1);
	for (k = 1; k <= 8; ++k) {
	    i1 = k + 1;
	    if (i1 > 8) {
		i1 = 1;
	    }
	    if (ivera[i1 - 1] == 0) {
		i1 = 1;
	    }
	    if (ivera[k - 1] == 0) {
		goto L641;
	    }
	    i2 = ivera[k - 1];
	    i3 = ivera[i1 - 1];
/* --- FIND TRIANGLE */
	    i4 = m - 1;
L195:
	    ++i4;
	    if (i4 > m + 3 && i4 < n) {
		i4 = n;
	    }
	    if (i4 > n + 3 || i4 > fld8_block1_1.i5) {
		goto L198;
	    }
	    if (i4 < 1) {
		goto L195;
	    }
	    ti41 = fld8_block1_1.tri[i4 - 1];
	    if (ti41 <= 0.f) {
		goto L195;
	    }
	    i41 = itri_(&i4, &fld8_c__1);
	    i42 = itri_(&i4, &fld8_c__2);
	    i43 = itri_(&i4, &fld8_c__3);
	    if ((i41 == l && i42 == i2 && i43 == i3) || (i42 == l && i43 == i2 &&
		     i41 == i3) || (i43 == l && i41 == i2 && i42 == i3)) {
		goto L196;
	    }
	    goto L195;
L196:
	    xm = fld8_block3_1.vert[i2 - 1];
	    ym = fld8_block3_1.vert[i2 + 29999];
	    xn = fld8_block3_1.vert[i3 - 1];
	    yn = fld8_block3_1.vert[i3 + 29999];
	    subd_(&d__, &xm, &ym, &xn, &yn, &xl, &yl);
	    e1 = 1.f / (fld8_block7_1.permo * ti41);
	    e2 = e1 / (d__ * 2.f);
/* Computing 2nd power */
	    r__2 = ym - yn;
/* Computing 2nd power */
	    r__3 = xn - xm;
	    r__1 = e2 * (r__2 * r__2 + r__3 * r__3);
	    c2.r = r__1, c2.i = 0.f;
	    r__1 = e2 * ((ym - yn) * (yn - yl) + (xn - xm) * (xl - xn));
	    c3.r = r__1, c3.i = 0.f;
	    r__1 = e2 * ((ym - yn) * (yl - ym) + (xn - xm) * (xm - xl));
	    c4.r = r__1, c4.i = 0.f;
	    c5.r = 0.f, c5.i = 0.f;
	    nx = fld8_block4_1.itri4[i4 - 1];
	    ny = 0;
	    if (nx == 0) {
		goto L1961;
	    }
	    nz = nx;
	    if (fld8_block3_1.datln[nx + 599] == 3.f || fld8_block3_1.datln[nx + 599] ==
		     9.f || fld8_block1_1.tri[i4 + 59301] == 0.f) {
		ny = 1;
	    }
/* --- POISSON'S EQUATION, FLAT FIELD */
L1961:
	    if (ny == 1) {
		i__2 = i4 - 1;
		q__2.r = d__ * fld8_block1_1.cdens[i__2].r, q__2.i = d__ * 
			fld8_block1_1.cdens[i__2].i;
		q__1.r = q__2.r / 6.f, q__1.i = q__2.i / 6.f;
		c5.r = q__1.r, c5.i = q__1.i;
	    }
	    if (fld8_block1_1.flaxi < 1.5f) {
		goto L207;
	    }
/* --- AXI-SYMMETRIC FIELD */
	    rc = (xl + xm + xn) / 3.f;
	    e3 = d__ / (rc * 18.f);
	    q__2.r = rc * c2.r, q__2.i = rc * c2.i;
	    r__1 = e1 * ((ym - yn) / 3.f + e3);
	    q__1.r = q__2.r + r__1, q__1.i = q__2.i;
	    c2.r = q__1.r, c2.i = q__1.i;
	    q__2.r = rc * c3.r, q__2.i = rc * c3.i;
	    r__1 = e1 * ((ym - yl) / 6.f + e3);
	    q__1.r = q__2.r + r__1, q__1.i = q__2.i;
	    c3.r = q__1.r, c3.i = q__1.i;
	    q__2.r = rc * c4.r, q__2.i = rc * c4.i;
	    r__1 = e1 * ((yl - yn) / 6.f + e3);
	    q__1.r = q__2.r + r__1, q__1.i = q__2.i;
	    c4.r = q__1.r, c4.i = q__1.i;
	    if (ny == 1) {
		q__1.r = rc * c5.r, q__1.i = rc * c5.i;
		c5.r = q__1.r, c5.i = q__1.i;
	    }
L207:
	    if (ny == 1 || nx == 0) {
		goto L197;
	    }
	    if (fld8_block3_1.datln[nx + 599] != 10.f) {
		goto L2073;
	    }
	    if (fld8_block1_1.flaxi < 1.5f) {
		i__2 = nx - 1;
		q__2.r = d__ * cdatl[i__2].r, q__2.i = d__ * cdatl[i__2].i;
		r__1 = fld8_block3_1.datln[nx + 1799] * 3.f;
		q__1.r = q__2.r / r__1, q__1.i = q__2.i / r__1;
		c5.r = q__1.r, c5.i = q__1.i;
	    }
	    if (fld8_block1_1.flaxi > 1.5f) {
		i__2 = nx - 1;
		q__2.r = d__ * cdatl[i__2].r, q__2.i = d__ * cdatl[i__2].i;
		r__1 = fld8_block3_1.datln[nx + 1949] * 3.f;
		q__1.r = q__2.r / r__1, q__1.i = q__2.i / r__1;
		c5.r = q__1.r, c5.i = q__1.i;
	    }
	    sd10 += d__;
/* --- DIFFUSION EQUATION */
L2073:
	    r__1 = fld8_block1_1.tri[i4 + 59301] * 1e6f;
	    q__3.r = r__1 * c1.r, q__3.i = r__1 * c1.i;
	    q__2.r = d__ * q__3.r, q__2.i = d__ * q__3.i;
	    q__1.r = q__2.r / 18.f, q__1.i = q__2.i / 18.f;
	    c6.r = q__1.r, c6.i = q__1.i;
	    if (fld8_block1_1.flaxi > 1.5f) {
		q__1.r = rc * c6.r, q__1.i = rc * c6.i;
		c6.r = q__1.r, c6.i = q__1.i;
	    }
	    q__1.r = c2.r + c6.r, q__1.i = c2.i + c6.i;
	    c2.r = q__1.r, c2.i = q__1.i;
	    q__1.r = c3.r + c6.r, q__1.i = c3.i + c6.i;
	    c3.r = q__1.r, c3.i = q__1.i;
	    q__1.r = c4.r + c6.r, q__1.i = c4.i + c6.i;
	    c4.r = q__1.r, c4.i = q__1.i;
	    if (fld8_block3_1.datln[nx + 599] == 10.f) {
		goto L197;
	    }
	    j2 = fld8_block3_1.datln[nx + 749];
/* --- VOLTAGE */
	    c6.r = 0.f, c6.i = 0.f;
	    if (j2 != 0) {
		i__2 = j2 + 9;
		c6.r = fld8_block1_1.curvo[i__2].r, c6.i = fld8_block1_1.curvo[i__2].i;
	    }
	    r__1 = fld8_block1_1.tri[i4 + 59301] * 1e6f * d__;
	    q__2.r = r__1 * c6.r, q__2.i = r__1 * c6.i;
	    q__1.r = q__2.r / 6.f, q__1.i = q__2.i / 6.f;
	    c5.r = q__1.r, c5.i = q__1.i;
/* --- ALL TYPES */
/* --- SUM K1T PLUS DIFFUSION TERM */
L197:
	    i__2 = hbw - 1;
	    i__1 = hbw - 1;
	    q__1.r = ccomp[i__1].r + c2.r, q__1.i = ccomp[i__1].i + c2.i;
	    ccomp[i__2].r = q__1.r, ccomp[i__2].i = q__1.i;
/* --- VERTICES I2 AND I3 CONVERTED TO POSITIONS IN ARRAY CCOMP */
	    l7 = novx2_(&i2, &fld8_block1_1.lnhor, &fld8_block1_1.lnver, &fld8_block7_1.per) 
		    + l6;
	    l8 = novx2_(&i3, &fld8_block1_1.lnhor, &fld8_block1_1.lnver, &fld8_block7_1.per) 
		    + l6;
	    if (jexit == 2) {
		goto L1971;
	    }
/* --- SUM K2T AND K3T PLUS DIFFUSION TERM */
	    i__2 = l7 - 1;
	    i__1 = l7 - 1;
	    q__1.r = ccomp[i__1].r + c3.r, q__1.i = ccomp[i__1].i + c3.i;
	    ccomp[i__2].r = q__1.r, ccomp[i__2].i = q__1.i;
	    i__2 = l8 - 1;
	    i__1 = l8 - 1;
	    q__1.r = ccomp[i__1].r + c4.r, q__1.i = ccomp[i__1].i + c4.i;
	    ccomp[i__2].r = q__1.r, ccomp[i__2].i = q__1.i;
/* --- SUM CONSTANT TERM */
	    i__2 = l2 - 1;
	    i__1 = l2 - 1;
	    q__1.r = ccomp[i__1].r + c5.r, q__1.i = ccomp[i__1].i + c5.i;
	    ccomp[i__2].r = q__1.r, ccomp[i__2].i = q__1.i;
	    if (jexit == 1) {
		goto L198;
	    }
/* --- ONLY FOR PERIODICITY CONDITION */
L1971:
	    e1 = fld8_block7_1.displ;
	    if (fld8_block7_1.per == 1.f && n1 == fld8_block1_1.lnver) {
		e1 = -fld8_block7_1.displ;
	    }
	    if (fld8_block7_1.per == 2.f && m1 == fld8_block1_1.lnhor) {
		e1 = -fld8_block7_1.displ;
	    }
	    cmang_(&c5, &e1, &c6, &fld8_block7_1.pi);
	    i__2 = l2 - 1;
	    i__1 = l2 - 1;
	    q__1.r = ccomp[i__1].r + c6.r, q__1.i = ccomp[i__1].i + c6.i;
	    ccomp[i__2].r = q__1.r, ccomp[i__2].i = q__1.i;
	    j3 = 0;
	    j4 = 0;
	    if (fld8_block7_1.per == 2.f) {
		goto L1972;
	    }
	    if (i2 - (i2 - 1) / fld8_block1_1.lnver * fld8_block1_1.lnver == 1 && n1 == 
		    1) {
		j3 = 1;
	    }
	    if (i2 - (i2 - 1) / fld8_block1_1.lnver * fld8_block1_1.lnver == 
		    fld8_block1_1.lnver && n1 == fld8_block1_1.lnver) {
		j3 = 2;
	    }
	    if (i3 - (i3 - 1) / fld8_block1_1.lnver * fld8_block1_1.lnver == 1 && n1 == 
		    1) {
		j4 = 1;
	    }
	    if (i3 - (i3 - 1) / fld8_block1_1.lnver * fld8_block1_1.lnver == 
		    fld8_block1_1.lnver && n1 == fld8_block1_1.lnver) {
		j4 = 2;
	    }
	    if (j3 == 1) {
		l7 = l7 + fld8_block1_1.lnver - 1;
	    }
	    if (j3 == 2) {
		l7 = l7 - fld8_block1_1.lnver + 1;
	    }
	    if (j4 == 1) {
		l8 = l8 + fld8_block1_1.lnver - 1;
	    }
	    if (j4 == 2) {
		l8 = l8 - fld8_block1_1.lnver + 1;
	    }
	    goto L1973;
L1972:
	    if (i2 <= fld8_block1_1.lnver && m1 == 1) {
		j3 = 1;
	    }
	    if (i2 > fld8_block1_1.i6 - fld8_block1_1.lnver && m1 == fld8_block1_1.lnhor) {
		j3 = 2;
	    }
	    if (i3 <= fld8_block1_1.lnver && m1 == 1) {
		j4 = 1;
	    }
	    if (i3 > fld8_block1_1.i6 - fld8_block1_1.lnver && m1 == fld8_block1_1.lnhor) {
		j4 = 2;
	    }
	    if (j3 == 1) {
		l7 = l7 - fld8_block1_1.lnhor + 1;
	    }
	    if (j3 == 2) {
		l7 = l7 + fld8_block1_1.lnhor - 1;
	    }
	    if (j4 == 1) {
		l8 = l8 - fld8_block1_1.lnhor + 1;
	    }
	    if (j4 == 2) {
		l8 = l8 + fld8_block1_1.lnhor - 1;
	    }
L1973:
	    if (min(l7,l8) < 1 || max(l7,l8) >= hbw << 1) {
		fld8_block7_1.warn = 63;
	    }
	    if (fld8_block7_1.warn == 63) {
		goto L2151;
	    }
	    c6.r = c3.r, c6.i = c3.i;
	    if (j3 == 0) {
		cmang_(&c3, &e1, &c6, &fld8_block7_1.pi);
	    }
	    i__2 = l7 - 1;
	    i__1 = l7 - 1;
	    q__1.r = ccomp[i__1].r + c6.r, q__1.i = ccomp[i__1].i + c6.i;
	    ccomp[i__2].r = q__1.r, ccomp[i__2].i = q__1.i;
	    c6.r = c4.r, c6.i = c4.i;
	    if (j4 == 0) {
		cmang_(&c4, &e1, &c6, &fld8_block7_1.pi);
	    }
	    i__2 = l8 - 1;
	    i__1 = l8 - 1;
	    q__1.r = ccomp[i__1].r + c6.r, q__1.i = ccomp[i__1].i + c6.i;
	    ccomp[i__2].r = q__1.r, ccomp[i__2].i = q__1.i;
L198:
	    ;
	}
L641:
	if (jexit == 2 || fld8_block7_1.per < .5f || fld8_block7_1.per > 2.5f) {
	    goto L64;
	}
	if (fld8_block7_1.per == 1.f && n1 != 1 && n1 != fld8_block1_1.lnver) {
	    goto L64;
	}
	if (fld8_block7_1.per == 2.f && m1 != 1 && m1 != fld8_block1_1.lnhor) {
	    goto L64;
	}
	jexit = 2;
	if (fld8_block7_1.per == 1.f && n1 == 1) {
	    l = l + fld8_block1_1.lnver - 1;
	}
	if (fld8_block7_1.per == 1.f && n1 == fld8_block1_1.lnver) {
	    l = l - fld8_block1_1.lnver + 1;
	}
	if (fld8_block7_1.per == 2.f && m1 == 1) {
	    l += (fld8_block1_1.lnhor - 1) * fld8_block1_1.lnver;
	}
	if (fld8_block7_1.per == 2.f && m1 == fld8_block1_1.lnhor) {
	    l -= (fld8_block1_1.lnhor - 1) * fld8_block1_1.lnver;
	}
	xl = fld8_block3_1.vert[l - 1];
	yl = fld8_block3_1.vert[l + 29999];
	goto L1941;
/* --- VECTOR POTENTIAL CONSTANT */
L62:
	i__2 = hbw - 1;
	ccomp[i__2].r = 1.f, ccomp[i__2].i = 0.f;
	i__2 = l2 - 1;
	i__1 = l - 1;
	ccomp[i__2].r = fld8_block3_1.cpot[i__1].r, ccomp[i__2].i = fld8_block3_1.cpot[
		i__1].i;
	goto L645;
L64:
	if (ivert_(&l, &fld8_c__9) != 10) {
	    goto L645;
	}
	j = 1;
L631:
	j1 = 1;
L632:
	if (fld8_block4_1.itri4[j - 1] != nz) {
	    goto L644;
	}
	l = itri_(&j, &fld8_c__1);
	m = itri_(&j, &fld8_c__2);
	n = itri_(&j, &fld8_c__3);
	xl = fld8_block3_1.vert[l - 1];
	yl = fld8_block3_1.vert[l + 29999];
	xm = fld8_block3_1.vert[m - 1];
	ym = fld8_block3_1.vert[m + 29999];
	xn = fld8_block3_1.vert[n - 1];
	yn = fld8_block3_1.vert[n + 29999];
	subd_(&d__, &xm, &ym, &xn, &yn, &xl, &yl);
	j2 = l;
	k = 1;
	tj2 = fld8_block1_1.tri[j + 59301];
L643:
	l7 = novx2_(&j2, &fld8_block1_1.lnhor, &fld8_block1_1.lnver, &fld8_block7_1.per) + 
		l6;
	if (fld8_block1_1.flaxi < 1.5f) {
	    i__2 = l7 - 1;
	    i__1 = l7 - 1;
	    r__1 = tj2 * 1e6f;
	    q__5.r = r__1 * c1.r, q__5.i = r__1 * c1.i;
	    q__4.r = d__ * q__5.r, q__4.i = d__ * q__5.i;
	    q__3.r = sd10 * q__4.r, q__3.i = sd10 * q__4.i;
	    r__2 = fld8_block3_1.datln[nz + 1799] * 18.f;
	    q__2.r = q__3.r / r__2, q__2.i = q__3.i / r__2;
	    q__1.r = ccomp[i__1].r - q__2.r, q__1.i = ccomp[i__1].i - q__2.i;
	    ccomp[i__2].r = q__1.r, ccomp[i__2].i = q__1.i;
	}
	if (fld8_block1_1.flaxi > 1.5f) {
	    i__2 = l7 - 1;
	    i__1 = l7 - 1;
	    r__1 = tj2 * 1e6f;
	    q__5.r = r__1 * c1.r, q__5.i = r__1 * c1.i;
	    q__4.r = d__ * q__5.r, q__4.i = d__ * q__5.i;
	    q__3.r = sd10 * q__4.r, q__3.i = sd10 * q__4.i;
	    r__2 = fld8_block3_1.datln[nz + 1949] * 18.f;
	    q__2.r = q__3.r / r__2, q__2.i = q__3.i / r__2;
	    q__1.r = ccomp[i__1].r - q__2.r, q__1.i = ccomp[i__1].i - q__2.i;
	    ccomp[i__2].r = q__1.r, ccomp[i__2].i = q__1.i;
	}
	++k;
	if (k == 2) {
	    j2 = m;
	}
	if (k == 3) {
	    j2 = n;
	}
	if (k <= 3) {
	    goto L643;
	}
	++j1;
	if (j1 >= 3) {
	    j = j + (fld8_block7_1.nocol << 1) - 2;
	}
L644:
	++j;
	if (j > fld8_block1_1.i5) {
	    goto L645;
	}
	if (j1 == 2) {
	    goto L632;
	}
	goto L631;
/* --- ELIMINATE ELEMENTS TO THE LEFT OF THE DIAGONAL */
L645:
	i__2 = l3;
	for (k = 1; k <= i__2; ++k) {
	    i__1 = k - 1;
	    ctemp.r = ccomp[i__1].r, ctemp.i = ccomp[i__1].i;
	    if (ctemp.r == 0.f && ctemp.i == 0.f) {
		goto L67;
	    }
	    l6 = l5 - hbw + k;
	    if (l6 <= 0) {
		l6 += hbw;
	    }
	    i__1 = k - 1;
	    ccomp[i__1].r = 0.f, ccomp[i__1].i = 0.f;
	    i__1 = l2 - 1;
	    i__4 = l2 - 1;
	    i__5 = l6 + hbw * 175 - 176;
	    q__2.r = ctemp.r * coeff[i__5].r - ctemp.i * coeff[i__5].i, 
		    q__2.i = ctemp.r * coeff[i__5].i + ctemp.i * coeff[i__5]
		    .r;
	    q__1.r = ccomp[i__4].r - q__2.r, q__1.i = ccomp[i__4].i - q__2.i;
	    ccomp[i__1].r = q__1.r, ccomp[i__1].i = q__1.i;
	    i__1 = l3;
	    for (m = 1; m <= i__1; ++m) {
		i__4 = l6 + m * 175 - 176;
		if (coeff[i__4].r == 0.f && coeff[i__4].i == 0.f) {
		    goto L66;
		}
		l7 = m + k;
		i__4 = l7 - 1;
		i__5 = l7 - 1;
		i__6 = l6 + m * 175 - 176;
		q__2.r = ctemp.r * coeff[i__6].r - ctemp.i * coeff[i__6].i, 
			q__2.i = ctemp.r * coeff[i__6].i + ctemp.i * coeff[
			i__6].r;
		q__1.r = ccomp[i__5].r - q__2.r, q__1.i = ccomp[i__5].i - 
			q__2.i;
		ccomp[i__4].r = q__1.r, ccomp[i__4].i = q__1.i;
L66:
		;
	    }
L67:
	    ;
	}
/* --- DIVIDE BY COEFFICIENT ON MAIN DIAGONAL */
	i__2 = hbw - 1;
	ctemp.r = ccomp[i__2].r, ctemp.i = ccomp[i__2].i;
	if (ctemp.r != 0.f || ctemp.i != 0.f) {
	    c_div(&q__1, &fld8_c_b98, &ctemp);
	    ctemp.r = q__1.r, ctemp.i = q__1.i;
	}
	i__2 = l2;
	for (k = l4; k <= i__2; ++k) {
	    i__1 = k - 1;
	    if (ccomp[i__1].r == 0.f && ccomp[i__1].i == 0.f) {
		goto L68;
	    }
	    i__1 = k - 1;
	    i__4 = k - 1;
	    q__1.r = ccomp[i__4].r * ctemp.r - ccomp[i__4].i * ctemp.i, 
		    q__1.i = ccomp[i__4].r * ctemp.i + ccomp[i__4].i * 
		    ctemp.r;
	    ccomp[i__1].r = q__1.r, ccomp[i__1].i = q__1.i;
	    i__1 = k - 1;
	    if ((r__1 = ccomp[i__1].r, dabs(r__1)) < 1e-9f && (r__2 = r_imag(&
		    ccomp[k - 1]), dabs(r__2)) < 1e-9f) {
		i__4 = k - 1;
		ccomp[i__4].r = 0.f, ccomp[i__4].i = 0.f;
	    }
/* --- TRANSFER TO ARRAY COEFF */
L68:
	    m = k - hbw;
/* L69: */
	    i__1 = l5 + m * 175 - 176;
	    i__4 = k - 1;
	    coeff[i__1].r = ccomp[i__4].r, coeff[i__1].i = ccomp[i__4].i;
	}
/* --- TRANSFER TO MASS STORAGE */
	i__1 = hbw;
	for (k = 1; k <= i__1; ++k) {
/* L65: */
	    i__4 = k - 1;
	    i__2 = l5 + k * 175 - 176;
	    fld8_block9_1.buffa[i__4].r = coeff[i__2].r, fld8_block9_1.buffa[i__4].i = 
		    coeff[i__2].i;
	}
	i__4 = hbw - 1;
	ctemp.r = fld8_block9_1.buffa[i__4].r, ctemp.i = fld8_block9_1.buffa[i__4].i;
	if ((r__1 = ctemp.r, dabs(r__1)) < 9.9e9f && (r__2 = r_imag(&ctemp), 
		dabs(r__2)) < 9.9e9f) {
	    goto L651;
	}
	goto L711;
L651:
	bufr_(&fld8_block1_1.i6, &hbw, &fld8_c__1, &fld8_block7_1.mass);
	++l5;
	if (l5 > hbw) {
	    l5 -= hbw;
	}
/* L71: */
    }
    dpot = 0.f;
    potmx = 0.f;
    goto L712;
L711:
    fld8_block7_1.warn = 60;
    goto L2151;
/* --- BACK SUBSTITUTION */
L712:
    dpot = 0.f;
    potmx = 0.f;
    i__3 = fld8_block1_1.i6;
    for (i__ = 1; i__ <= i__3; ++i__) {
	bufr_(&fld8_block1_1.i6, &hbw, &fld8_c__3, &fld8_block7_1.mass);
	i__4 = hbw;
	for (k = 1; k <= i__4; ++k) {
/* L70: */
	    i__2 = k * 175 - 175;
	    i__1 = k - 1;
	    coeff[i__2].r = fld8_block9_1.buffa[i__1].r, coeff[i__2].i = 
		    fld8_block9_1.buffa[i__1].i;
	}
/* --- LINE NUMBER IN MASS STORAGE */
	j = fld8_block1_1.i6 - i__ + 1;
	i__2 = hbw * 175 - 175;
	ctemp.r = coeff[i__2].r, ctemp.i = coeff[i__2].i;
	i__2 = l3;
	for (k = 1; k <= i__2; ++k) {
	    i__1 = k * 175 - 175;
	    if (coeff[i__1].r == 0.f && coeff[i__1].i == 0.f) {
		goto L72;
	    }
/* --- VERTEX NUMBER IN ARRAY VERT */
	    k1 = j + k;
	    l = novx1_(&k1, &fld8_block1_1.lnhor, &fld8_block1_1.lnver, &fld8_block7_1.per);
	    i__1 = k * 175 - 175;
	    i__4 = l - 1;
	    q__2.r = coeff[i__1].r * fld8_block3_1.cpot[i__4].r - coeff[i__1].i * 
		    fld8_block3_1.cpot[i__4].i, q__2.i = coeff[i__1].r * 
		    fld8_block3_1.cpot[i__4].i + coeff[i__1].i * fld8_block3_1.cpot[
		    i__4].r;
	    q__1.r = ctemp.r - q__2.r, q__1.i = ctemp.i - q__2.i;
	    ctemp.r = q__1.r, ctemp.i = q__1.i;
L72:
	    ;
	}
/* --- STORE POTENTIAL */
	l = novx1_(&j, &fld8_block1_1.lnhor, &fld8_block1_1.lnver, &fld8_block7_1.per);
	if ((r__1 = ctemp.r, dabs(r__1)) < 9.9e9f && (r__2 = r_imag(&ctemp), 
		dabs(r__2)) < 9.9e9f) {
	    goto L721;
	}
	goto L711;
L721:
	e1 = c_abs(&ctemp);
	i__2 = l - 1;
	q__1.r = ctemp.r - fld8_block3_1.cpot[i__2].r, q__1.i = ctemp.i - 
		fld8_block3_1.cpot[i__2].i;
	e2 = c_abs(&q__1);
	if (e1 > potmx) {
	    potmx = e1;
	}
	if (e2 > dpot) {
	    dpot = e2;
	}
	i__2 = l - 1;
	fld8_block3_1.cpot[i__2].r = ctemp.r, fld8_block3_1.cpot[i__2].i = ctemp.i;
/* L73: */
    }
/* --- MAX. PERCENT CHANGE OF POTENTIAL */
    if ((real) fld8_blck11_1.itmx == 0.f) {
	goto L74;
    }
    if (potmx > 0.f) {
	dpot = dpot * 100.f / potmx;
    }
    if (fld8_blck12_1.itac == 1) {
	io___372.ciunit = fld8_block7_1.out;
	s_wsfe(&io___372);
	e_wsfe();
    }
    io___373.ciunit = fld8_block7_1.out;
    s_wsfe(&io___373);
    do_fio(&fld8_c__1, (char *)&fld8_blck12_1.itac, (ftnlen)sizeof(integer));
    do_fio(&fld8_c__1, (char *)&dpot, (ftnlen)sizeof(real));
    e_wsfe();
/* --- GO BACK TO THE MAIN PROGRAM IF A NEW ITERATION IS REQUIRED */
    if (dpot > fld8_blck11_1.dptmx && fld8_blck12_1.itac < fld8_blck11_1.itmx) {
	fld8_blck12_1.newit = 1;
    }
    if (fld8_blck12_1.newit == 1) {
	goto L612;
    }
L74:
    if (i7 == 2) {
	goto L214;
    }
/* --- IF THERE ARE NO APPLIED VOLTAGES, VECTOR POTENTIALS ARE FINAL */
    if (fld8_block1_1.nvolt == 0) {
	goto L214;
    }
/* --- ENTER TOTAL CURRENTS IN ARRAY CURR */
    i__3 = fld8_block1_1.i5;
    for (i__ = 1; i__ <= i__3; ++i__) {
/* --- VOLTAGE */
	iv2 = fld8_block4_1.itri5[i__ - 1];
	if (iv2 == 0) {
	    goto L208;
	}
	i__2 = iv2 + 9;
	c2.r = fld8_block1_1.curvo[i__2].r, c2.i = fld8_block1_1.curvo[i__2].i;
/* --- VECTOR POTENTIAL AT CENTROID */
	l = itri_(&i__, &fld8_c__1);
	m = itri_(&i__, &fld8_c__2);
	n = itri_(&i__, &fld8_c__3);
	i__2 = l - 1;
	i__1 = m - 1;
	q__3.r = fld8_block3_1.cpot[i__2].r + fld8_block3_1.cpot[i__1].r, q__3.i = 
		fld8_block3_1.cpot[i__2].i + fld8_block3_1.cpot[i__1].i;
	i__4 = n - 1;
	q__2.r = q__3.r + fld8_block3_1.cpot[i__4].r, q__2.i = q__3.i + 
		fld8_block3_1.cpot[i__4].i;
	q__1.r = q__2.r / 3.f, q__1.i = q__2.i / 3.f;
	c3.r = q__1.r, c3.i = q__1.i;
/* --- RADIUS TO CENTROID AND AREA */
	xl = fld8_block3_1.vert[l - 1];
	yl = fld8_block3_1.vert[l + 29999];
	xm = fld8_block3_1.vert[m - 1];
	ym = fld8_block3_1.vert[m + 29999];
	xn = fld8_block3_1.vert[n - 1];
	yn = fld8_block3_1.vert[n + 29999];
	if (fld8_block1_1.flaxi > 1.5f) {
	    rc = (xl + xn + xm) / 3.f;
	}
	subd_(&d__, &xm, &ym, &xn, &yn, &xl, &yl);
/* --- CURRENT */
	if (fld8_block1_1.flaxi > 1.5f) {
	    q__1.r = c2.r / rc, q__1.i = c2.i / rc;
	    c2.r = q__1.r, c2.i = q__1.i;
	}
	r__1 = fld8_block1_1.tri[i__ + 59301] * 1e6f;
	q__5.r = c1.r * c3.r - c1.i * c3.i, q__5.i = c1.r * c3.i + c1.i * 
		c3.r;
	q__4.r = c2.r - q__5.r, q__4.i = c2.i - q__5.i;
	q__3.r = r__1 * q__4.r, q__3.i = r__1 * q__4.i;
	q__2.r = d__ * q__3.r, q__2.i = d__ * q__3.i;
	q__1.r = q__2.r / 2.f, q__1.i = q__2.i / 2.f;
	c4.r = q__1.r, c4.i = q__1.i;
	if (i10 == 0) {
	    goto L2072;
	}
	i__2 = iv2 - 1;
	i__1 = iv2 - 1;
	q__1.r = fld8_block1_1.curvo[i__1].r - c4.r, q__1.i = fld8_block1_1.curvo[i__1]
		.i - c4.i;
	fld8_block1_1.curvo[i__2].r = q__1.r, fld8_block1_1.curvo[i__2].i = q__1.i;
	i__2 = fld8_block1_1.nvolt;
	for (k = 1; k <= i__2; ++k) {
/* L2071: */
	    i__1 = iv2 + k * 10 - 11;
	    i__4 = iv2 + k * 10 - 11;
	    q__1.r = curr[i__4].r - c4.r, q__1.i = curr[i__4].i - c4.i;
	    curr[i__1].r = q__1.r, curr[i__1].i = q__1.i;
	}
	goto L208;
L2072:
	i__1 = iv2 + iv1 * 10 - 11;
	i__4 = iv2 + iv1 * 10 - 11;
	q__1.r = curr[i__4].r + c4.r, q__1.i = curr[i__4].i + c4.i;
	curr[i__1].r = q__1.r, curr[i__1].i = q__1.i;
L208:
	;
    }
    if (i7 == 1) {
	goto L2132;
    }
    if (i10 == 1) {
	goto L2101;
    }
/* --- ADJUST VECTOR POTENTIALS IF THERE IS ONLY ONE APPLIED VOLTAGE */
/* --- IN A PHASE CONNECTED CONDUCTOR */
    if (fld8_block1_1.nvolt != 1) {
	goto L210;
    }
    if (absc_(fld8_block1_1.curvo) < .001f || fld8_block1_1.ncod3 == 1) {
	goto L2131;
    }
    c_div(&q__1, fld8_block1_1.curvo, curr);
    fld8_block1_1.curvo[10].r = q__1.r, fld8_block1_1.curvo[10].i = q__1.i;
    i__3 = fld8_block1_1.i6;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__1 = i__ - 1;
	ci.r = fld8_block3_1.cpot[i__1].r, ci.i = fld8_block3_1.cpot[i__1].i;
	i__1 = i__ - 1;
	q__1.r = ci.r * fld8_block1_1.curvo[10].r - ci.i * fld8_block1_1.curvo[10].i, 
		q__1.i = ci.r * fld8_block1_1.curvo[10].i + ci.i * fld8_block1_1.curvo[
		10].r;
	fld8_block3_1.cpot[i__1].r = q__1.r, fld8_block3_1.cpot[i__1].i = q__1.i;
/* L209: */
    }
    goto L214;
/* --- REPEAT THE CALCULATIONS WITH THE NEXT APPLIED VOLTAGE */
L210:
    ++iv1;
    if (iv1 <= fld8_block1_1.nvolt) {
	goto L204;
    }
    if (fld8_block1_1.ncod3 == 0) {
	goto L2101;
    }
/* --- REPEAT THE CALCULATIONS WITH ALL APPLIED VOLTAGES ZERO */
    i__3 = fld8_block1_1.nvolt + 9;
    fld8_block1_1.curvo[i__3].r = 0.f, fld8_block1_1.curvo[i__3].i = 0.f;
    i10 = 1;
    goto L206;
/* --- INVERT ARRAY CURR AND FIND APPLIED VOLTAGES */
L2101:
    incur_(&fld8_block1_1.nvolt, curr, curri);
    i__3 = fld8_block1_1.nvolt;
    for (i__ = 1; i__ <= i__3; ++i__) {
/* L211: */
	i__1 = i__ + 9;
	fld8_block1_1.curvo[i__1].r = 0.f, fld8_block1_1.curvo[i__1].i = 0.f;
    }
    i__1 = fld8_block1_1.nvolt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__3 = fld8_block1_1.nvolt;
	for (j = 1; j <= i__3; ++j) {
/* L212: */
	    i__4 = i__ + 9;
	    i__2 = i__ + 9;
	    i__5 = i__ + j * 10 - 11;
	    i__6 = j - 1;
	    q__2.r = curri[i__5].r * fld8_block1_1.curvo[i__6].r - curri[i__5].i * 
		    fld8_block1_1.curvo[i__6].i, q__2.i = curri[i__5].r * 
		    fld8_block1_1.curvo[i__6].i + curri[i__5].i * fld8_block1_1.curvo[
		    i__6].r;
	    q__1.r = fld8_block1_1.curvo[i__2].r + q__2.r, q__1.i = fld8_block1_1.curvo[
		    i__2].i + q__2.i;
	    fld8_block1_1.curvo[i__4].r = q__1.r, fld8_block1_1.curvo[i__4].i = q__1.i;
	}
/* L213: */
    }
/* --- FINALIZE CALCULATIONS OF VECTOR POTENTIALS */
    i7 = 2;
    goto L206;
/* --- NON PHASE CONNECTED CONDUCTOR WITH ZERO TOTAL CURRENT */
/* --- OR CURRENT IN BOTH DIRECTIONS, AND ONLY ONE WITH SKIN EFFECT */
L2131:
    curr[1].r = curr[0].r, curr[1].i = curr[0].i;
    curr[0].r = 0.f, curr[0].i = 0.f;
    fld8_block1_1.curvo[10].r = 0.f, fld8_block1_1.curvo[10].i = 0.f;
    i7 = 1;
    goto L206;
L2132:
    q__2.r = fld8_block1_1.curvo[0].r - curr[0].r, q__2.i = fld8_block1_1.curvo[0].i - 
	    curr[0].i;
    q__3.r = curr[1].r - curr[0].r, q__3.i = curr[1].i - curr[0].i;
    c_div(&q__1, &q__2, &q__3);
    fld8_block1_1.curvo[10].r = q__1.r, fld8_block1_1.curvo[10].i = q__1.i;
    i7 = 2;
    goto L206;
L214:
    if (icod10 == 0) {
	goto L2143;
    }
/* --- VOLTAGES U FOR CODE=10 */
    i__1 = fld8_block1_1.linto;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (fld8_block3_1.datln[i__ + 599] != 10.f) {
	    goto L2141;
	}
	r__1 = fld8_block3_1.datln[i__ + 299] * cos(fld8_block3_1.datln[i__ + 449] / 
		grrad);
	r__2 = fld8_block3_1.datln[i__ + 299] * sin(fld8_block3_1.datln[i__ + 449] / 
		grrad);
	q__3.r = r__1, q__3.i = r__2;
	q__2.r = q__3.r * 2.f, q__2.i = q__3.i * 2.f;
	r__3 = fld8_block3_1.datln[i__ + 149] * 1e6f;
	q__1.r = q__2.r / r__3, q__1.i = q__2.i / r__3;
	c2.r = q__1.r, c2.i = q__1.i;
	if (fld8_block1_1.flaxi < 1.5f) {
	    i__4 = i__ + 149;
	    i__2 = i__ + 1799;
	    q__1.r = c2.r / fld8_block3_1.datln[i__2], q__1.i = c2.i / 
		    fld8_block3_1.datln[i__2];
	    cdatl[i__4].r = q__1.r, cdatl[i__4].i = q__1.i;
	}
	if (fld8_block1_1.flaxi > 1.5f) {
	    i__4 = i__ + 149;
	    i__2 = i__ + 1949;
	    q__1.r = c2.r / fld8_block3_1.datln[i__2], q__1.i = c2.i / 
		    fld8_block3_1.datln[i__2];
	    cdatl[i__4].r = q__1.r, cdatl[i__4].i = q__1.i;
	}
L2141:
	;
    }
    i__1 = fld8_block1_1.i5;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = fld8_block4_1.itri4[i__ - 1];
	if (j == 0) {
	    goto L2142;
	}
	if (fld8_block3_1.datln[j + 599] != 10.f) {
	    goto L2142;
	}
	l = itri_(&i__, &fld8_c__1);
	m = itri_(&i__, &fld8_c__2);
	n = itri_(&i__, &fld8_c__3);
	xl = fld8_block3_1.vert[l - 1];
	yl = fld8_block3_1.vert[l + 29999];
	xm = fld8_block3_1.vert[m - 1];
	ym = fld8_block3_1.vert[m + 29999];
	xn = fld8_block3_1.vert[n - 1];
	yn = fld8_block3_1.vert[n + 29999];
	subd_(&d__, &xm, &ym, &xn, &yn, &xl, &yl);
	q__3.r = d__ * c1.r, q__3.i = d__ * c1.i;
	i__4 = l - 1;
	i__2 = m - 1;
	q__5.r = fld8_block3_1.cpot[i__4].r + fld8_block3_1.cpot[i__2].r, q__5.i = 
		fld8_block3_1.cpot[i__4].i + fld8_block3_1.cpot[i__2].i;
	i__5 = n - 1;
	q__4.r = q__5.r + fld8_block3_1.cpot[i__5].r, q__4.i = q__5.i + 
		fld8_block3_1.cpot[i__5].i;
	q__2.r = q__3.r * q__4.r - q__3.i * q__4.i, q__2.i = q__3.r * q__4.i 
		+ q__3.i * q__4.r;
	q__1.r = q__2.r / 3.f, q__1.i = q__2.i / 3.f;
	c2.r = q__1.r, c2.i = q__1.i;
	if (fld8_block1_1.flaxi < 1.5f) {
	    i__4 = j + 149;
	    i__2 = j + 149;
	    i__5 = j + 1799;
	    q__2.r = c2.r / fld8_block3_1.datln[i__5], q__2.i = c2.i / 
		    fld8_block3_1.datln[i__5];
	    q__1.r = cdatl[i__2].r + q__2.r, q__1.i = cdatl[i__2].i + q__2.i;
	    cdatl[i__4].r = q__1.r, cdatl[i__4].i = q__1.i;
	}
	if (fld8_block1_1.flaxi > 1.5f) {
	    i__4 = j + 149;
	    i__2 = j + 149;
	    i__5 = j + 1949;
	    q__2.r = c2.r / fld8_block3_1.datln[i__5], q__2.i = c2.i / 
		    fld8_block3_1.datln[i__5];
	    q__1.r = cdatl[i__2].r + q__2.r, q__1.i = cdatl[i__2].i + q__2.i;
	    cdatl[i__4].r = q__1.r, cdatl[i__4].i = q__1.i;
	}
L2142:
	;
    }
/* --- CURRENT DENSITIES */
L2143:
    i__1 = fld8_block1_1.i5;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = fld8_block4_1.itri4[i__ - 1];
	e1 = 0.f;
	if (j != 0) {
	    e1 = fld8_block3_1.datln[j + 599];
	}
	if ((e1 >= 1.f && e1 <= 3.f) || e1 == 9.f) {
	    goto L215;
	}
/* --- VOLTAGE */
	iv2 = fld8_block4_1.itri5[i__ - 1];
	c2.r = 0.f, c2.i = 0.f;
	if (iv2 != 0) {
	    i__4 = iv2 + 9;
	    c2.r = fld8_block1_1.curvo[i__4].r, c2.i = fld8_block1_1.curvo[i__4].i;
	}
	if (e1 == 10.f) {
	    i__4 = j + 149;
	    c2.r = cdatl[i__4].r, c2.i = cdatl[i__4].i;
	}
/* --- VECTOR POTENTIAL AT CENTROID */
	l = itri_(&i__, &fld8_c__1);
	m = itri_(&i__, &fld8_c__2);
	n = itri_(&i__, &fld8_c__3);
	i__4 = l - 1;
	i__2 = m - 1;
	q__3.r = fld8_block3_1.cpot[i__4].r + fld8_block3_1.cpot[i__2].r, q__3.i = 
		fld8_block3_1.cpot[i__4].i + fld8_block3_1.cpot[i__2].i;
	i__5 = n - 1;
	q__2.r = q__3.r + fld8_block3_1.cpot[i__5].r, q__2.i = q__3.i + 
		fld8_block3_1.cpot[i__5].i;
	q__1.r = q__2.r / 3.f, q__1.i = q__2.i / 3.f;
	c3.r = q__1.r, c3.i = q__1.i;
/* --- CURRENT DENSITY */
	if (fld8_block1_1.flaxi > 1.5f) {
	    q__2.r = c2.r * 3.f, q__2.i = c2.i * 3.f;
	    r__1 = fld8_block3_1.vert[l - 1] + fld8_block3_1.vert[m - 1] + 
		    fld8_block3_1.vert[n - 1];
	    q__1.r = q__2.r / r__1, q__1.i = q__2.i / r__1;
	    c2.r = q__1.r, c2.i = q__1.i;
	}
	r__1 = fld8_block1_1.tri[i__ + 59301] * 1e6f;
	q__3.r = c1.r * c3.r - c1.i * c3.i, q__3.i = c1.r * c3.i + c1.i * 
		c3.r;
	q__2.r = c2.r - q__3.r, q__2.i = c2.i - q__3.i;
	q__1.r = r__1 * q__2.r, q__1.i = r__1 * q__2.i;
	cd.r = q__1.r, cd.i = q__1.i;
	i__4 = i__ - 1;
	fld8_block1_1.cdens[i__4].r = cd.r, fld8_block1_1.cdens[i__4].i = cd.i;
	if ((r__1 = cd.r, dabs(r__1)) < 1e-15f && (r__2 = r_imag(&cd), dabs(
		r__2)) < 1e-15f) {
	    i__4 = i__ - 1;
	    fld8_block1_1.cdens[i__4].r = 0.f, fld8_block1_1.cdens[i__4].i = 0.f;
	}
L215:
	;
    }
    io___378.ciunit = fld8_block7_1.out;
    s_wsfe(&io___378);
    e_wsfe();
    linac = 1;
    goto L216;
L2151:
    goto L999;
L216:
    cond = fld8_block3_1.datln[linac + 149];
    conn = fld8_block3_1.datln[linac + 299];
    code = fld8_block3_1.datln[linac + 599];
    if (code >= 8.f) {
	conn = 0.f;
    }
    if ((code > .9f && code < 2.5f) || code > 10.f) {
	goto L2651;
    }
    io___382.ciunit = fld8_block7_1.out;
    s_wsfe(&io___382);
    e_wsfe();
    if (fld8_block1_1.flaxi < 1.5f) {
	io___383.ciunit = fld8_block7_1.out;
	s_wsfe(&io___383);
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___384.ciunit = fld8_block7_1.out;
	s_wsfe(&io___384);
	e_wsfe();
    }
    io___385.ciunit = fld8_block7_1.out;
    s_wsfe(&io___385);
    for (i__ = 8; i__ <= 11; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block3_1.datln[linac + i__ * 150 - 151], (
		ftnlen)sizeof(real));
    }
    do_fio(&fld8_c__1, (char *)&conn, (ftnlen)sizeof(real));
    e_wsfe();
    if (code == 6.f || code == 7.f) {
	goto L217;
    }
/* --- PHASE ANGLE OF TOTAL CURRENT */
    if (conn == 0.f && code < 8.f) {
	angc = 0.f;
    }
    if (conn == 0.f && code < 8.f) {
	goto L217;
    }
    if (code >= 8.f) {
	angc = fld8_block3_1.datln[linac + 449] / grrad;
    }
    if (code >= 8.f) {
	goto L217;
    }
    angc = twopi * (1.f - conn) / fld8_block7_1.phas;
    if (fld8_block7_1.phas == 2.f) {
	angc = pio2 * (1.f - conn);
    }
    if (fld8_block3_1.datln[linac + 449] < 0.f) {
	angc += fld8_block7_1.pi;
    }
    if (conn == 0.f) {
	angc = 0.f;
    }
L217:
    ncode = 1;
    if (conn == 0.f && code < 8.f) {
	ncode = 2;
    }
/* --- INITIALIZATION */
    sjd.r = 0.f, sjd.i = 0.f;
    sdu.r = 0.f, sdu.i = 0.f;
    sd = 0.f;
    sdr = 0.f;
    sloss = 0.f;
    fx = 0.f;
    fy = 0.f;
    cdmax = 0.f;
    bmax = 0.f;
    bxvol = 0.f;
    byvol = 0.f;
    bxmax = 0.f;
    bymax = 0.f;
/* --- TRIANGLE NUMBER */
    i__ = 1;
L218:
    if (fld8_block4_1.itri4[i__ - 1] != linac) {
	goto L257;
    }
L219:
    l = itri_(&i__, &fld8_c__1);
    m = itri_(&i__, &fld8_c__2);
    n = itri_(&i__, &fld8_c__3);
    xl = fld8_block3_1.vert[l - 1];
    xm = fld8_block3_1.vert[m - 1];
    xn = fld8_block3_1.vert[n - 1];
    yl = fld8_block3_1.vert[l + 29999];
    ym = fld8_block3_1.vert[m + 29999];
    yn = fld8_block3_1.vert[n + 29999];
    subd_(&d__, &xm, &ym, &xn, &yn, &xl, &yl);
/* --- SUM OF D AND D*RC */
    if (fld8_block1_1.flaxi > 1.5f) {
	rc = (xl + xm + xn) / 3.f;
    }
    if (ncode == 3) {
	goto L221;
    }
    if (ncode == 4) {
	goto L254;
    }
    sd += d__;
    if (fld8_block1_1.flaxi > 1.5f) {
	sdr += d__ * rc;
    }
/* --- CURRENT DENSITY, A/SQ.MM */
L221:
    i__1 = i__ - 1;
    q__1.r = fld8_block1_1.cdens[i__1].r * 1e-6f, q__1.i = fld8_block1_1.cdens[i__1].i *
	     1e-6f;
    cd.r = q__1.r, cd.i = q__1.i;
    cdabs = absc_(&cd);
/* --- LOSS DENSITY, KW/CUB.DM */
    dloss = 0.f;
    if (fld8_block1_1.tri[i__ + 59301] != 0.f) {
/* Computing 2nd power */
	r__1 = cdabs;
	dloss = r__1 * r__1 / fld8_block1_1.tri[i__ + 59301];
    }
    if (ncode == 3) {
	goto L254;
    }
    if (cdabs > cdmax) {
	cdmax = cdabs;
    }
/* --- LOSS (CORRECTED LATER) */
    if (fld8_block1_1.flaxi < 1.5f) {
	sloss += d__ * dloss;
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	sloss += d__ * rc * dloss;
    }
    q__2.r = d__ * cd.r, q__2.i = d__ * cd.i;
    q__1.r = sjd.r + q__2.r, q__1.i = sjd.i + q__2.i;
    sjd.r = q__1.r, sjd.i = q__1.i;
/* --- FLUX DENSITIES */
L254:
    i__1 = l - 1;
    al.r = fld8_block3_1.cpot[i__1].r, al.i = fld8_block3_1.cpot[i__1].i;
    i__1 = m - 1;
    am.r = fld8_block3_1.cpot[i__1].r, am.i = fld8_block3_1.cpot[i__1].i;
    i__1 = n - 1;
    an.r = fld8_block3_1.cpot[i__1].r, an.i = fld8_block3_1.cpot[i__1].i;
    q__3.r = al.r + am.r, q__3.i = al.i + am.i;
    q__2.r = q__3.r + an.r, q__2.i = q__3.i + an.i;
    q__1.r = q__2.r / 3.f, q__1.i = q__2.i / 3.f;
    ac.r = q__1.r, ac.i = q__1.i;
    if (code != 3.f && code != 9.f) {
	goto L255;
    }
    if (ncode == 3 || ncode == 4) {
	goto L255;
    }
    i__1 = i__ - 1;
    r__1 = fld8_block1_1.tri[i__ + 59301] * 1e6f;
    q__2.r = fld8_block1_1.cdens[i__1].r / r__1, q__2.i = fld8_block1_1.cdens[i__1].i / 
	    r__1;
    q__3.r = c1.r * ac.r - c1.i * ac.i, q__3.i = c1.r * ac.i + c1.i * ac.r;
    q__1.r = q__2.r + q__3.r, q__1.i = q__2.i + q__3.i;
    c2.r = q__1.r, c2.i = q__1.i;
    if (fld8_block1_1.flaxi < 1.5f) {
	q__2.r = d__ * c2.r, q__2.i = d__ * c2.i;
	q__1.r = sdu.r + q__2.r, q__1.i = sdu.i + q__2.i;
	sdu.r = q__1.r, sdu.i = q__1.i;
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	r__1 = d__ * rc;
	q__2.r = r__1 * c2.r, q__2.i = r__1 * c2.i;
	q__1.r = sdu.r + q__2.r, q__1.i = sdu.i + q__2.i;
	sdu.r = q__1.r, sdu.i = q__1.i;
    }
L255:
    r__1 = xm - xn;
    q__5.r = r__1 * al.r, q__5.i = r__1 * al.i;
    r__2 = xn - xl;
    q__6.r = r__2 * am.r, q__6.i = r__2 * am.i;
    q__4.r = q__5.r + q__6.r, q__4.i = q__5.i + q__6.i;
    r__3 = xl - xm;
    q__7.r = r__3 * an.r, q__7.i = r__3 * an.i;
    q__3.r = q__4.r + q__7.r, q__3.i = q__4.i + q__7.i;
    q__2.r = q__3.r / d__, q__2.i = q__3.i / d__;
    q__1.r = q__2.r * 1.4142136f, q__1.i = q__2.i * 1.4142136f;
    bx.r = q__1.r, bx.i = q__1.i;
    r__1 = ym - yn;
    q__5.r = r__1 * al.r, q__5.i = r__1 * al.i;
    r__2 = yn - yl;
    q__6.r = r__2 * am.r, q__6.i = r__2 * am.i;
    q__4.r = q__5.r + q__6.r, q__4.i = q__5.i + q__6.i;
    r__3 = yl - ym;
    q__7.r = r__3 * an.r, q__7.i = r__3 * an.i;
    q__3.r = q__4.r + q__7.r, q__3.i = q__4.i + q__7.i;
    q__2.r = q__3.r / d__, q__2.i = q__3.i / d__;
    q__1.r = q__2.r * 1.4142136f, q__1.i = q__2.i * 1.4142136f;
    by.r = q__1.r, by.i = q__1.i;
    if (fld8_block1_1.flaxi > 1.5f) {
	q__3.r = ac.r / rc, q__3.i = ac.i / rc;
	q__2.r = q__3.r * 1.4142136f, q__2.i = q__3.i * 1.4142136f;
	q__1.r = by.r + q__2.r, q__1.i = by.i + q__2.i;
	by.r = q__1.r, by.i = q__1.i;
    }
    bxabs = absc_(&bx);
    byabs = absc_(&by);
    if (ncode == 4) {
	goto L284;
    }
    bxr = bx.r;
    byr = by.r;
    bxi = r_imag(&bx);
    byi = r_imag(&by);
    bxabs = absc_(&bx);
    byabs = absc_(&by);
    angle_(&byi, &byr, &fld8_c_b111, &e11, &fld8_block7_1.pi);
    angle_(&bxi, &bxr, &fld8_c_b111, &e12, &fld8_block7_1.pi);
    if (ncode == 3) {
	goto L256;
    }
    if (code != 0.f && code != 3.f && code != 9.f) {
	goto L2551;
    }
    if (code == 0.f && cond != 0.f) {
	goto L2551;
    }
    if (fld8_block1_1.flaxi < 1.5f) {
/* Computing 2nd power */
	r__1 = bxabs;
	bxvol += d__ * .5f * (r__1 * r__1);
    }
    if (fld8_block1_1.flaxi < 1.5f) {
/* Computing 2nd power */
	r__1 = byabs;
	byvol += d__ * .5f * (r__1 * r__1);
    }
    if (fld8_block1_1.flaxi > 1.5f) {
/* Computing 2nd power */
	r__1 = bxabs;
	bxvol += fld8_block7_1.pi * d__ * rc * (r__1 * r__1);
    }
    if (fld8_block1_1.flaxi > 1.5f) {
/* Computing 2nd power */
	r__1 = byabs;
	byvol += fld8_block7_1.pi * d__ * rc * (r__1 * r__1);
    }
    if (bxabs > bxmax) {
	bxmax = bxabs;
    }
    if (byabs > bymax) {
	bymax = byabs;
    }
L2551:
    i__1 = i__ - 1;
    cd.r = fld8_block1_1.cdens[i__1].r, cd.i = fld8_block1_1.cdens[i__1].i;
    e5 = absc_(&cd) * .70710678f * d__;
    r__1 = r_imag(&cd);
    r__2 = cd.r;
    angle_(&r__1, &r__2, &fld8_c_b111, &e6, &fld8_block7_1.pi);
    e7 = e5 * cos(e6 - angc);
    e5 = e7 * byabs * cos(e11 - angc);
    if (fld8_block1_1.flaxi < 1.5f) {
	fx += e5;
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	fx += e5 * rc;
    }
    e6 = e7 * bxabs * cos(e12 - angc);
    if (fld8_block1_1.flaxi < 1.5f) {
	fy -= e6;
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	fy -= e6 * rc;
    }
    if (ncode == 1) {
	goto L257;
    }
L256:
    beta = e11 - e12;
    e11 = byabs / 2.f * sin(beta);
/* Computing 2nd power */
    r__1 = byabs / 2.f * cos(beta);
    e12 = r__1 * r__1;
/* Computing 2nd power */
    r__1 = bxabs / 2.f - e11;
/* Computing 2nd power */
    r__2 = bxabs / 2.f + e11;
    b = sqrt(r__1 * r__1 + e12) + sqrt(r__2 * r__2 + e12);
    if (ncode == 3) {
	goto L247;
    }
    if (b > bmax) {
	bmax = b;
    }
L257:
    ++i__;
    if (i__ <= fld8_block1_1.i5) {
	goto L218;
    }
/* --- COMPLETE CALCULATIONS AND PRINTOUT FOR EACH CONDUCTOR */
    if (code != 10.f) {
	i__1 = linac + 149;
	cdatl[i__1].r = sdu.r, cdatl[i__1].i = sdu.i;
    }
/* --- VOLTS/M AND PHASE ANGLE, CODES 3, 4, 5, 6, 7, 8, 9 AND 10 */
    if (code < 3.f) {
	goto L2571;
    }
    i__ = fld8_block3_1.datln[linac + 749];
    if (i__ != 0) {
	i__1 = i__ + 9;
	c2.r = fld8_block1_1.curvo[i__1].r, c2.i = fld8_block1_1.curvo[i__1].i;
    }
    if (code == 10.f) {
	i__1 = linac + 149;
	c2.r = cdatl[i__1].r, c2.i = cdatl[i__1].i;
    }
    if (code == 3.f || code == 9.f) {
	i__1 = linac + 149;
	q__1.r = cdatl[i__1].r / sd, q__1.i = cdatl[i__1].i / sd;
	c2.r = q__1.r, c2.i = q__1.i;
    }
    e1 = absc_(&c2);
    e2 = c2.r;
    e3 = r_imag(&c2);
    angle_(&e3, &e2, &grrad, &e4, &fld8_block7_1.pi);
    if (fld8_block1_1.flaxi < 1.5f) {
	io___406.ciunit = fld8_block7_1.out;
	s_wsfe(&io___406);
	do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
	e_wsfe();
    }
    e1 = twopi * e1;
    if (fld8_block1_1.flaxi > 1.5f) {
	io___407.ciunit = fld8_block7_1.out;
	s_wsfe(&io___407);
	do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
	e_wsfe();
    }
    io___408.ciunit = fld8_block7_1.out;
    s_wsfe(&io___408);
    do_fio(&fld8_c__1, (char *)&e4, (ftnlen)sizeof(real));
    e_wsfe();
/* --- CODES FOR CONDUCTOR CALCULATIONS */
L2571:
    if (conn == 0.f && code < 8.f) {
	io___409.ciunit = fld8_block7_1.out;
	s_wsfe(&io___409);
	do_fio(&fld8_c__1, (char *)&bmax, (ftnlen)sizeof(real));
	e_wsfe();
    }
/* --- TOTAL CURRENT AND PHASE ANGLE */
    q__1.r = sjd.r * 5e5f, q__1.i = sjd.i * 5e5f;
    c2.r = q__1.r, c2.i = q__1.i;
    i__1 = linac - 1;
    cdatl[i__1].r = c2.r, cdatl[i__1].i = c2.i;
    e1 = absc_(&c2);
    r__1 = r_imag(&c2);
    r__2 = c2.r;
    angle_(&r__1, &r__2, &grrad, &e2, &fld8_block7_1.pi);
    io___410.ciunit = fld8_block7_1.out;
    s_wsfe(&io___410);
    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
    e_wsfe();
    io___411.ciunit = fld8_block7_1.out;
    s_wsfe(&io___411);
    do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
    e_wsfe();
/* --- DEPTH OF PENETRATION */
    e4 = fld8_block3_1.datln[linac - 1] * fld8_block3_1.datln[linac + 149] * 
	    fld8_block1_1.freq;
    if (e4 != 0.f) {
	e3 = sqrt(1e7f / e4) / twopi;
    }
    if (e4 != 0.f) {
	io___412.ciunit = fld8_block7_1.out;
	s_wsfe(&io___412);
	do_fio(&fld8_c__1, (char *)&e3, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (ncode != 1) {
	goto L258;
    }
/* --- AVERAGE CURRENT DENSITY, A/SQ.MM */
    q__1.r = sjd.r / sd, q__1.i = sjd.i / sd;
    e1 = absc_(&q__1);
    io___413.ciunit = fld8_block7_1.out;
    s_wsfe(&io___413);
    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
    e_wsfe();
    fld8_block3_1.datln[linac + 1799] = sd;
/* --- MAX. CURRENT DENSITY */
L258:
    io___414.ciunit = fld8_block7_1.out;
    s_wsfe(&io___414);
    do_fio(&fld8_c__1, (char *)&cdmax, (ftnlen)sizeof(real));
    e_wsfe();
    if (ncode != 1) {
	goto L259;
    }
    e2 = 0.f;
    if (e1 != 0.f) {
	e2 = cdmax / e1;
    }
    io___415.ciunit = fld8_block7_1.out;
    s_wsfe(&io___415);
    do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
    e_wsfe();
/* --- LOSSES */
L259:
    e2 = sloss * 500.f;
    if (fld8_block1_1.flaxi > 1.5f) {
	e2 *= twopi;
    }
    if (ncode != 1) {
	goto L263;
    }
    e3 = 0.f;
    if (fld8_block3_1.datln[linac + 149] != 0.f) {
	e3 = e1 * e1 * 500.f / fld8_block3_1.datln[linac + 149];
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	goto L261;
    }
    e3 *= sd;
    io___416.ciunit = fld8_block7_1.out;
    s_wsfe(&io___416);
    do_fio(&fld8_c__1, (char *)&e3, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
    e_wsfe();
    goto L262;
L261:
    e3 = e3 * sdr * twopi;
    io___417.ciunit = fld8_block7_1.out;
    s_wsfe(&io___417);
    do_fio(&fld8_c__1, (char *)&e3, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
    e_wsfe();
L262:
    fld8_block3_1.datln[linac + 1649] = e3;
    e4 = 0.f;
    if (e3 != 0.f) {
	e4 = e2 / e3;
    }
    io___418.ciunit = fld8_block7_1.out;
    s_wsfe(&io___418);
    do_fio(&fld8_c__1, (char *)&e4, (ftnlen)sizeof(real));
    e_wsfe();
    goto L264;
L263:
    if (fld8_block1_1.flaxi < 1.5f) {
	io___419.ciunit = fld8_block7_1.out;
	s_wsfe(&io___419);
	do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___420.ciunit = fld8_block7_1.out;
	s_wsfe(&io___420);
	do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
	e_wsfe();
    }
L264:
    fld8_block3_1.datln[linac + 1949] = sdr;
    fld8_block3_1.datln[linac + 2099] = e2;
    if (cond == 0.f) {
	goto L265;
    }
/* --- FORCES */
    if (fld8_block1_1.flaxi > 1.5f) {
	goto L2641;
    }
    if (conn != 0.f || code >= 8.f) {
	io___421.ciunit = fld8_block7_1.out;
	s_wsfe(&io___421);
	do_fio(&fld8_c__1, (char *)&fx, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&fy, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (conn == 0.f && code < 8.f) {
	io___422.ciunit = fld8_block7_1.out;
	s_wsfe(&io___422);
	do_fio(&fld8_c__1, (char *)&fx, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&fy, (ftnlen)sizeof(real));
	e_wsfe();
    }
    goto L265;
L2641:
    fx *= twopi;
    fy *= twopi;
    if (conn != 0.f || code >= 8.f) {
	io___423.ciunit = fld8_block7_1.out;
	s_wsfe(&io___423);
	do_fio(&fld8_c__1, (char *)&fx, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&fy, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (conn == 0.f && code < 8.f) {
	io___424.ciunit = fld8_block7_1.out;
	s_wsfe(&io___424);
	do_fio(&fld8_c__1, (char *)&fx, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&fy, (ftnlen)sizeof(real));
	e_wsfe();
    }
L265:
    if (code != 0.f && code != 3.f && code != 9.f) {
	goto L2651;
    }
    if (code == 0.f && cond != 0.f) {
	goto L2651;
    }
    if (fld8_block1_1.flaxi < 1.5f) {
	io___425.ciunit = fld8_block7_1.out;
	s_wsfe(&io___425);
	do_fio(&fld8_c__1, (char *)&bxvol, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&byvol, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&bxmax, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&bymax, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___426.ciunit = fld8_block7_1.out;
	s_wsfe(&io___426);
	do_fio(&fld8_c__1, (char *)&bxvol, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&byvol, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&bxmax, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&bymax, (ftnlen)sizeof(real));
	e_wsfe();
    }
L2651:
    ++linac;
    if (linac <= fld8_block1_1.linto) {
	goto L216;
    }
/* --- FOR EACH PHASE */
/* --- INITIALIZE */
    sulph = 0.f;
    salph = 0.f;
    if (fld8_block7_1.phas == 0.f) {
	goto L277;
    }
    phno = 1.f;
L266:
    upos.r = 0.f, upos.i = 0.f;
    cpos.r = 0.f, cpos.i = 0.f;
    uneg.r = 0.f, uneg.i = 0.f;
    cneg.r = 0.f, cneg.i = 0.f;
    uloss = 0.f;
    sdpos = 0.f;
    sdneg = 0.f;
    sdgp = 0.f;
    sdgn = 0.f;
    cdpos = 0.f;
    cdneg = 0.f;
    i__1 = fld8_block1_1.linto;
    for (linac = 1; linac <= i__1; ++linac) {
	if (phno != fld8_block3_1.datln[linac + 299]) {
	    goto L271;
	}
	code = fld8_block3_1.datln[linac + 599];
	if (code >= 8.f) {
	    goto L271;
	}
	if (fld8_block3_1.datln[linac + 449] < 0.f) {
	    goto L268;
	}
/* --- POSITIVE CURRENT */
	i__4 = linac - 1;
	q__1.r = cpos.r + cdatl[i__4].r, q__1.i = cpos.i + cdatl[i__4].i;
	cpos.r = q__1.r, cpos.i = q__1.i;
	cdpos = code;
/* --- POSITIVE VOLTAGE */
	i__ = fld8_block3_1.datln[linac + 749];
	if (code != 0.f) {
	    goto L267;
	}
	i__4 = i__ + 9;
	upos.r = fld8_block1_1.curvo[i__4].r, upos.i = fld8_block1_1.curvo[i__4].i;
L267:
	if (code != 3.f) {
	    goto L270;
	}
	i__4 = linac + 149;
	q__1.r = upos.r + cdatl[i__4].r, q__1.i = upos.i + cdatl[i__4].i;
	upos.r = q__1.r, upos.i = q__1.i;
L270:
	if (code == 4.f) {
	    i__4 = i__ + 9;
	    i__2 = linac + 899;
	    q__2.r = fld8_block1_1.curvo[i__4].r / fld8_block3_1.datln[i__2], q__2.i = 
		    fld8_block1_1.curvo[i__4].i / fld8_block3_1.datln[i__2];
	    q__1.r = upos.r + q__2.r, q__1.i = upos.i + q__2.i;
	    upos.r = q__1.r, upos.i = q__1.i;
	}
	if (code == 5.f) {
	    i__4 = i__ + 9;
	    q__3.r = fld8_block1_1.curvo[i__4].r * .5f, q__3.i = fld8_block1_1.curvo[
		    i__4].i * .5f;
	    i__2 = linac + 899;
	    q__2.r = q__3.r / fld8_block3_1.datln[i__2], q__2.i = q__3.i / 
		    fld8_block3_1.datln[i__2];
	    q__1.r = upos.r + q__2.r, q__1.i = upos.i + q__2.i;
	    upos.r = q__1.r, upos.i = q__1.i;
	}
	sdpos += fld8_block3_1.datln[linac + 1799];
	if (fld8_block1_1.flaxi < 1.5f) {
	    sdgp += fld8_block3_1.datln[linac + 149] * fld8_block3_1.datln[linac + 1799]
		    ;
	}
	if (fld8_block1_1.flaxi > 1.5f) {
/* Computing 2nd power */
	    r__1 = fld8_block3_1.datln[linac + 1799];
	    sdgp += fld8_block3_1.datln[linac + 149] * (r__1 * r__1) / 
		    fld8_block3_1.datln[linac + 1949];
	}
	goto L271;
/* --- NEGATIVE CURRENT */
L268:
	i__4 = linac - 1;
	q__1.r = cneg.r + cdatl[i__4].r, q__1.i = cneg.i + cdatl[i__4].i;
	cneg.r = q__1.r, cneg.i = q__1.i;
	cdneg = code;
/* --- NEGATIVE VOLTAGE */
	i__ = fld8_block3_1.datln[linac + 749];
	if (code != 0.f) {
	    goto L269;
	}
	i__4 = i__ + 9;
	uneg.r = fld8_block1_1.curvo[i__4].r, uneg.i = fld8_block1_1.curvo[i__4].i;
L269:
	if (code != 3.f) {
	    goto L278;
	}
	i__4 = linac + 149;
	q__1.r = uneg.r + cdatl[i__4].r, q__1.i = uneg.i + cdatl[i__4].i;
	uneg.r = q__1.r, uneg.i = q__1.i;
L278:
	if (code == 4.f) {
	    i__4 = i__ + 9;
	    i__2 = linac + 899;
	    q__2.r = fld8_block1_1.curvo[i__4].r / fld8_block3_1.datln[i__2], q__2.i = 
		    fld8_block1_1.curvo[i__4].i / fld8_block3_1.datln[i__2];
	    q__1.r = uneg.r + q__2.r, q__1.i = uneg.i + q__2.i;
	    uneg.r = q__1.r, uneg.i = q__1.i;
	}
	if (code == 5.f) {
	    i__4 = i__ + 9;
	    q__3.r = fld8_block1_1.curvo[i__4].r * .5f, q__3.i = fld8_block1_1.curvo[
		    i__4].i * .5f;
	    i__2 = linac + 899;
	    q__2.r = q__3.r / fld8_block3_1.datln[i__2], q__2.i = q__3.i / 
		    fld8_block3_1.datln[i__2];
	    q__1.r = uneg.r + q__2.r, q__1.i = uneg.i + q__2.i;
	    uneg.r = q__1.r, uneg.i = q__1.i;
	}
	sdneg += fld8_block3_1.datln[linac + 1799];
	if (fld8_block1_1.flaxi < 1.5f) {
	    sdgn += fld8_block3_1.datln[linac + 149] * fld8_block3_1.datln[linac + 1799]
		    ;
	}
	if (fld8_block1_1.flaxi > 1.5f) {
/* Computing 2nd power */
	    r__1 = fld8_block3_1.datln[linac + 1799];
	    sdgn += fld8_block3_1.datln[linac + 149] * (r__1 * r__1) / 
		    fld8_block3_1.datln[linac + 1949];
	}
L271:
	;
    }
/* --- OUTPUT */
    if ((r__1 = upos.r, dabs(r__1)) < 1e-9f && (r__2 = r_imag(&upos), dabs(
	    r__2)) < 1e-9f && (r__3 = uneg.r, dabs(r__3)) < 1e-9f && (r__4 = 
	    r_imag(&uneg), dabs(r__4)) < 1e-9f) {
	goto L277;
    }
    io___441.ciunit = fld8_block7_1.out;
    s_wsfe(&io___441);
    do_fio(&fld8_c__1, (char *)&phno, (ftnlen)sizeof(real));
    e_wsfe();
/* --- VOLTAGES, CURRENTS AND PHASE ANGLES */
    if (sdpos != 0.f && cdpos == 3.f) {
	q__1.r = upos.r / sdpos, q__1.i = upos.i / sdpos;
	upos.r = q__1.r, upos.i = q__1.i;
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	q__1.r = twopi * upos.r, q__1.i = twopi * upos.i;
	upos.r = q__1.r, upos.i = q__1.i;
    }
    uposa = absc_(&upos);
    if (uposa < .001f) {
	goto L272;
    }
    r__1 = r_imag(&upos);
    r__2 = upos.r;
    angle_(&r__1, &r__2, &grrad, &e1, &fld8_block7_1.pi);
    if (fld8_block1_1.flaxi < 1.5f) {
	io___443.ciunit = fld8_block7_1.out;
	s_wsfe(&io___443);
	do_fio(&fld8_c__1, (char *)&uposa, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___444.ciunit = fld8_block7_1.out;
	s_wsfe(&io___444);
	do_fio(&fld8_c__1, (char *)&uposa, (ftnlen)sizeof(real));
	e_wsfe();
    }
    io___445.ciunit = fld8_block7_1.out;
    s_wsfe(&io___445);
    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
    e_wsfe();
L272:
    cposa = absc_(&cpos);
    if (cposa < .001f) {
	goto L273;
    }
    r__1 = r_imag(&cpos);
    r__2 = cpos.r;
    angle_(&r__1, &r__2, &grrad, &e1, &fld8_block7_1.pi);
    io___447.ciunit = fld8_block7_1.out;
    s_wsfe(&io___447);
    do_fio(&fld8_c__1, (char *)&cposa, (ftnlen)sizeof(real));
    e_wsfe();
    io___448.ciunit = fld8_block7_1.out;
    s_wsfe(&io___448);
    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
    e_wsfe();
L273:
    if (sdneg != 0.f && cdneg == 3.f) {
	q__1.r = uneg.r / sdneg, q__1.i = uneg.i / sdneg;
	uneg.r = q__1.r, uneg.i = q__1.i;
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	q__1.r = twopi * uneg.r, q__1.i = twopi * uneg.i;
	uneg.r = q__1.r, uneg.i = q__1.i;
    }
    unega = absc_(&uneg);
    if (unega < .001f) {
	goto L274;
    }
    r__1 = r_imag(&uneg);
    r__2 = uneg.r;
    angle_(&r__1, &r__2, &grrad, &e1, &fld8_block7_1.pi);
    if (fld8_block1_1.flaxi < 1.5f) {
	io___450.ciunit = fld8_block7_1.out;
	s_wsfe(&io___450);
	do_fio(&fld8_c__1, (char *)&unega, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___451.ciunit = fld8_block7_1.out;
	s_wsfe(&io___451);
	do_fio(&fld8_c__1, (char *)&unega, (ftnlen)sizeof(real));
	e_wsfe();
    }
    io___452.ciunit = fld8_block7_1.out;
    s_wsfe(&io___452);
    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
    e_wsfe();
L274:
    cnega = absc_(&cneg);
    if (cnega < .001f) {
	goto L275;
    }
    r__1 = r_imag(&cneg);
    r__2 = cneg.r;
    angle_(&r__1, &r__2, &grrad, &e1, &fld8_block7_1.pi);
    io___454.ciunit = fld8_block7_1.out;
    s_wsfe(&io___454);
    do_fio(&fld8_c__1, (char *)&cnega, (ftnlen)sizeof(real));
    e_wsfe();
    io___455.ciunit = fld8_block7_1.out;
    s_wsfe(&io___455);
    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
    e_wsfe();
/* --- UNIFORM CURRENT LOSS */
L275:
    uloss = 0.f;
    if (sdgp != 0.f) {
/* Computing 2nd power */
	r__1 = fld8_block7_1.phcur;
	uloss = r__1 * r__1 * 2e-9f / sdgp;
    }
    if (sdgn != 0.f) {
/* Computing 2nd power */
	r__1 = fld8_block7_1.phcur;
	uloss += r__1 * r__1 * 2e-9f / sdgn;
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	uloss = uloss * 2.f * fld8_block7_1.pi;
    }
/* --- ACTUAL LOSS, KW */
    r_cnjg(&q__3, &cpos);
    q__2.r = upos.r * q__3.r - upos.i * q__3.i, q__2.i = upos.r * q__3.i + 
	    upos.i * q__3.r;
    r_cnjg(&q__5, &cneg);
    q__4.r = uneg.r * q__5.r - uneg.i * q__5.i, q__4.i = uneg.r * q__5.i + 
	    uneg.i * q__5.r;
    q__1.r = q__2.r + q__4.r, q__1.i = q__2.i + q__4.i;
    aloss = q__1.r * .001f;
    if (fld8_block1_1.flaxi < 1.5f) {
	io___457.ciunit = fld8_block7_1.out;
	s_wsfe(&io___457);
	do_fio(&fld8_c__1, (char *)&uloss, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&aloss, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___458.ciunit = fld8_block7_1.out;
	s_wsfe(&io___458);
	do_fio(&fld8_c__1, (char *)&uloss, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&aloss, (ftnlen)sizeof(real));
	e_wsfe();
    }
    sulph += uloss;
    salph += aloss;
    e1 = 0.f;
    if (uloss != 0.f) {
	e1 = aloss / uloss;
    }
    io___459.ciunit = fld8_block7_1.out;
    s_wsfe(&io___459);
    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
    e_wsfe();
/* --- DC AND AC RESISTANCES */
/* Computing 2nd power */
    r__1 = fld8_block7_1.phcur;
    e1 = uloss * 1e3f / (r__1 * r__1);
/* Computing 2nd power */
    r__1 = fld8_block7_1.phcur;
    e2 = aloss * 1e3f / (r__1 * r__1);
/* --- IMPEDANCE */
    c2.r = 0.f, c2.i = 0.f;
    if (cposa > .001f) {
	c_div(&q__1, &upos, &cpos);
	c2.r = q__1.r, c2.i = q__1.i;
    }
    if (cnega > .001f) {
	c_div(&q__2, &uneg, &cneg);
	q__1.r = c2.r + q__2.r, q__1.i = c2.i + q__2.i;
	c2.r = q__1.r, c2.i = q__1.i;
    }
    e3 = absc_(&c2);
/* --- REACTANCE */
    e4 = 0.f;
    if (e2 < e3) {
/* Computing 2nd power */
	r__1 = e3;
/* Computing 2nd power */
	r__2 = e2;
	e4 = sqrt(r__1 * r__1 - r__2 * r__2);
    }
    if (fld8_block1_1.flaxi < 1.5f) {
	io___460.ciunit = fld8_block7_1.out;
	s_wsfe(&io___460);
	do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e4, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e3, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___461.ciunit = fld8_block7_1.out;
	s_wsfe(&io___461);
	do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e4, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e3, (ftnlen)sizeof(real));
	e_wsfe();
    }
/* --- NEXT PHASE */
    phno += 1.f;
    if (phno <= fld8_block7_1.phas) {
	goto L266;
    }
/* --- FOR ALL THE PHASES */
    io___462.ciunit = fld8_block7_1.out;
    s_wsfe(&io___462);
    e_wsfe();
    if (fld8_block1_1.flaxi < 1.5f) {
	io___463.ciunit = fld8_block7_1.out;
	s_wsfe(&io___463);
	do_fio(&fld8_c__1, (char *)&sulph, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&salph, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___464.ciunit = fld8_block7_1.out;
	s_wsfe(&io___464);
	do_fio(&fld8_c__1, (char *)&sulph, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&salph, (ftnlen)sizeof(real));
	e_wsfe();
    }
    e1 = salph / sulph;
    io___465.ciunit = fld8_block7_1.out;
    s_wsfe(&io___465);
    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
    e_wsfe();
/* --- FOR ALL THE CONDUCTORS */
L277:
    e1 = 0.f;
    i__1 = fld8_block1_1.linto;
    for (linac = 1; linac <= i__1; ++linac) {
	if (fld8_block3_1.datln[linac + 599] != 8.f) {
	    goto L280;
	}
	i__ = fld8_block3_1.datln[linac + 749];
	i__4 = i__ + 9;
	c2.r = fld8_block1_1.curvo[i__4].r, c2.i = fld8_block1_1.curvo[i__4].i;
L280:
	if (fld8_block3_1.datln[linac + 599] == 9.f) {
	    i__4 = linac + 149;
	    i__2 = linac + 1799;
	    q__1.r = cdatl[i__4].r / fld8_block3_1.datln[i__2], q__1.i = cdatl[
		    i__4].i / fld8_block3_1.datln[i__2];
	    c2.r = q__1.r, c2.i = q__1.i;
	}
	if (fld8_block3_1.datln[linac + 599] == 10.f) {
	    i__4 = linac + 149;
	    c2.r = cdatl[i__4].r, c2.i = cdatl[i__4].i;
	}
	if (fld8_block3_1.datln[linac + 599] < 8.f) {
	    goto L282;
	}
	if (fld8_block1_1.flaxi > 1.5f) {
	    q__1.r = twopi * c2.r, q__1.i = twopi * c2.i;
	    c2.r = q__1.r, c2.i = q__1.i;
	}
	r_cnjg(&q__2, &cdatl[linac - 1]);
	q__1.r = c2.r * q__2.r - c2.i * q__2.i, q__1.i = c2.r * q__2.i + c2.i 
		* q__2.r;
	salph += q__1.r * .001f;
L282:
	e1 += fld8_block3_1.datln[linac + 2099];
    }
    if (fld8_block1_1.flaxi < 1.5f) {
	io___466.ciunit = fld8_block7_1.out;
	s_wsfe(&io___466);
	do_fio(&fld8_c__1, (char *)&salph, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___467.ciunit = fld8_block7_1.out;
	s_wsfe(&io___467);
	do_fio(&fld8_c__1, (char *)&salph, (ftnlen)sizeof(real));
	do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
	e_wsfe();
    }
    io___468.ciunit = fld8_block7_1.out;
    s_wsfe(&io___468);
    e_wsfe();
/* --- MAGNETIC ENERGY */
    ncode = 4;
    wmag = 0.f;
    i__ = 1;
    goto L219;
L284:
    j = fld8_block4_1.itri4[i__ - 1];
    e1 = 1.f;
    if (j != 0) {
	e1 = fld8_block3_1.datln[j - 1];
    }
    e2 = 0.f;
    if (e1 != 0.f) {
/* Computing 2nd power */
	r__1 = bxabs;
/* Computing 2nd power */
	r__2 = byabs;
	e2 = (r__1 * r__1 + r__2 * r__2) * d__ / (e1 * 4.f * fld8_block7_1.permo);
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	e2 = e2 * twopi * rc;
    }
    wmag += e2;
    ++i__;
    if (i__ <= fld8_block1_1.i5) {
	goto L219;
    }
    if (fld8_block1_1.flaxi < 1.5f) {
	io___470.ciunit = fld8_block7_1.out;
	s_wsfe(&io___470);
	do_fio(&fld8_c__1, (char *)&wmag, (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___471.ciunit = fld8_block7_1.out;
	s_wsfe(&io___471);
	do_fio(&fld8_c__1, (char *)&wmag, (ftnlen)sizeof(real));
	e_wsfe();
    }
/* --- DETAILED OUTPUT OF VECTOR POTENTIALS */
/* L2211: */
    k = 1;
L222:
    i1 = fld8_block7_1.verf[k - 1];
    i2 = fld8_block7_1.verl[k - 1];
    i3 = fld8_block7_1.horf[k - 1];
    i4 = fld8_block7_1.horl[k - 1];
    if (i2 <= i1 || i4 <= i3) {
	goto L2271;
    }
    if (k != 1) {
	goto L241;
    }
    io___472.ciunit = fld8_block7_1.out;
    s_wsfe(&io___472);
    e_wsfe();
    if (fld8_block1_1.flaxi < 1.5f) {
	io___473.ciunit = fld8_block7_1.out;
	s_wsfe(&io___473);
	e_wsfe();
    }
    if (fld8_block1_1.flaxi > 1.5f) {
	io___474.ciunit = fld8_block7_1.out;
	s_wsfe(&io___474);
	e_wsfe();
    }
L241:
    i__1 = i4;
    for (i__ = i3; i__ <= i__1; ++i__) {
	i__4 = i2;
	for (j = i1; j <= i__4; ++j) {
	    l = (i__ - 1) * fld8_block1_1.lnver + j;
	    e1 = fld8_block3_1.vert[l - 1] * 1e3f;
	    e2 = fld8_block3_1.vert[l + 29999] * 1e3f;
	    i__2 = l - 1;
	    al.r = fld8_block3_1.cpot[i__2].r, al.i = fld8_block3_1.cpot[i__2].i;
	    e3 = al.r;
	    e4 = r_imag(&al);
	    e5 = absc_(&al);
	    io___475.ciunit = fld8_block7_1.out;
	    s_wsfe(&io___475);
	    do_fio(&fld8_c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&fld8_c__1, (char *)&l, (ftnlen)sizeof(integer));
	    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
	    do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
	    do_fio(&fld8_c__1, (char *)&e3, (ftnlen)sizeof(real));
	    do_fio(&fld8_c__1, (char *)&e4, (ftnlen)sizeof(real));
	    do_fio(&fld8_c__1, (char *)&e5, (ftnlen)sizeof(real));
	    e_wsfe();
/* L226: */
	}
/* L227: */
    }
    ++k;
    if (k <= 3) {
	goto L222;
    }
L2271:
    k = 1;
L242:
    i1 = fld8_block7_1.verf[k - 1];
    i2 = fld8_block7_1.verl[k - 1] - 1;
    i3 = fld8_block7_1.horf[k - 1];
    i4 = fld8_block7_1.horl[k - 1] - 1;
    if (i2 < i1 || i4 < i3) {
	goto L612;
    }
/* --- DETAILED OUTPUT FOR EACH TRIANGLE */
    if (k == 1) {
	io___476.ciunit = fld8_block7_1.out;
	s_wsfe(&io___476);
	e_wsfe();
    }
    ncode = 3;
    k1 = 0;
/* L243: */
    i8 = i3;
L235:
    i9 = i1;
L236:
    j = 0;
/* --- TRIANGLE NUMBER */
L230:
    i__ = (((i8 - 1) * fld8_block7_1.nocol + i9) << 1) - 1 + j;
    cd.r = 0.f, cd.i = 0.f;
    cdabs = 0.f;
    bxr = 0.f;
    bxi = 0.f;
    byr = 0.f;
    byi = 0.f;
    b = 0.f;
    dloss = 0.f;
    if (fld8_block1_1.tri[i__ - 1] > .001f) {
	goto L219;
    }
L247:
    e1 = cd.r;
    e2 = r_imag(&cd);
    if (k1 != i8) {
	io___479.ciunit = fld8_block7_1.out;
	s_wsfe(&io___479);
	do_fio(&fld8_c__1, (char *)&i8, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (k1 == 0) {
	io___480.ciunit = fld8_block7_1.out;
	s_wsfe(&io___480);
	e_wsfe();
    }
    it1 = itri_(&i__, &fld8_c__1);
    it2 = itri_(&i__, &fld8_c__2);
    it3 = itri_(&i__, &fld8_c__3);
    t1 = fld8_block1_1.tri[i__ - 1];
    t2 = fld8_block1_1.tri[i__ + 59301];
    io___486.ciunit = fld8_block7_1.out;
    s_wsfe(&io___486);
    do_fio(&fld8_c__1, (char *)&it1, (ftnlen)sizeof(integer));
    do_fio(&fld8_c__1, (char *)&it2, (ftnlen)sizeof(integer));
    do_fio(&fld8_c__1, (char *)&it3, (ftnlen)sizeof(integer));
    do_fio(&fld8_c__1, (char *)&t1, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&t2, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&cdabs, (ftnlen)sizeof(real));
    e_wsfe();
    if (k1 == 0 && fld8_block1_1.flaxi < 1.5f) {
	io___487.ciunit = fld8_block7_1.out;
	s_wsfe(&io___487);
	e_wsfe();
    }
    if (k1 == 0 && fld8_block1_1.flaxi > 1.5f) {
	io___488.ciunit = fld8_block7_1.out;
	s_wsfe(&io___488);
	e_wsfe();
    }
    io___489.ciunit = fld8_block7_1.out;
    s_wsfe(&io___489);
    do_fio(&fld8_c__1, (char *)&bxr, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&bxi, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&byr, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&byi, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&b, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&dloss, (ftnlen)sizeof(real));
    e_wsfe();
    if (k1 == 0) {
	io___490.ciunit = fld8_block7_1.out;
	s_wsfe(&io___490);
	e_wsfe();
    }
    k1 = i8;
    ++j;
    if (j == 1) {
	goto L230;
    }
    ++i9;
    if (i9 <= i2) {
	goto L236;
    }
    ++i8;
    if (i8 <= i4) {
	goto L235;
    }
    ++k;
    if (k <= 3) {
	goto L242;
    }
    goto L612;
/* --- ABORT */
L999:
    io___491.ciunit = fld8_block7_1.out;
    s_wsfe(&io___491);
    e_wsfe();
    if (fld8_block7_1.warn == 46) {
	io___492.ciunit = fld8_block7_1.out;
	s_wsfe(&io___492);
	e_wsfe();
    }
    if (fld8_block7_1.warn == 47) {
	io___493.ciunit = fld8_block7_1.out;
	s_wsfe(&io___493);
	e_wsfe();
    }
    if (fld8_block7_1.warn == 48) {
	io___494.ciunit = fld8_block7_1.out;
	s_wsfe(&io___494);
	e_wsfe();
    }
    if (fld8_block7_1.warn == 57) {
	io___495.ciunit = fld8_block7_1.out;
	s_wsfe(&io___495);
	e_wsfe();
    }
    if (fld8_block7_1.warn == 58) {
	io___496.ciunit = fld8_block7_1.out;
	s_wsfe(&io___496);
	e_wsfe();
    }
    if (fld8_block7_1.warn == 59) {
	io___497.ciunit = fld8_block7_1.out;
	s_wsfe(&io___497);
	e_wsfe();
    }
    if (fld8_block7_1.warn == 63) {
	io___498.ciunit = fld8_block7_1.out;
	s_wsfe(&io___498);
	e_wsfe();
    }
    if (fld8_block7_1.warn == 78) {
	io___499.ciunit = fld8_block7_1.out;
	s_wsfe(&io___499);
	e_wsfe();
    }
    if (fld8_block7_1.warn == 79) {
	io___500.ciunit = fld8_block7_1.out;
	s_wsfe(&io___500);
	e_wsfe();
    }
    if (fld8_block7_1.warn == 84) {
	io___501.ciunit = fld8_block7_1.out;
	s_wsfe(&io___501);
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.nvolt, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (fld8_block7_1.warn == 88) {
	io___502.ciunit = fld8_block7_1.out;
	s_wsfe(&io___502);
	e_wsfe();
    }
    if (fld8_block7_1.warn != 60) {
	goto L611;
    }
    e1 = fld8_block3_1.vert[l - 1] * 1e3f;
    e2 = fld8_block3_1.vert[l + 29999] * 1e3f;
    io___503.ciunit = fld8_block7_1.out;
    s_wsfe(&io___503);
    do_fio(&fld8_c__1, (char *)&l, (ftnlen)sizeof(integer));
    do_fio(&fld8_c__1, (char *)&e1, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&e2, (ftnlen)sizeof(real));
    e_wsfe();
L611:
    fld8_block1_1.flxln = 0.f;
L612:
    return 0;
} /* elb_ */

/* Subroutine */ int magn_(real *binp, real *code, real *perm)
{
    /* Builtin functions */
    double log(doublereal), exp(doublereal);

    /* Local variables */
    static real b;
    static integer i2, i3, i2max;

/* --- SATURATION CURVES ARE IN ATPCM(20,12), TAKEN FROM FILE ATPCM.FIL */
    b = *binp * fld8_blck11_1.fact;
    for (i2max = 1; i2max <= 20; ++i2max) {
	if (fld8_blck11_1.atpcm[i2max - 1] == 0.f) {
	    goto L799;
	}
/* L798: */
    }
    i2max = 20;
    goto L800;
L799:
    --i2max;
L800:
    *perm = 1.f;
/* --- I2MAX IS THE NUMBER OF SATURATION CURVES */
    i2 = (integer) (*code) - 14;
    if (i2 > i2max) {
	goto L802;
    }
    *perm = 100.f;
    if (b < 0.f) {
	goto L802;
    }
/* L801: */
    *perm = 1.f / (fld8_blck11_1.atpcm[i2 - 1] * 1.2566371e-4f);
    if (b <= 1.f) {
	goto L802;
    }
    i3 = (integer) ((b - .9f) * 10.f + .999f);
    if (i3 < 2) {
	i3 = 2;
    }
    if (i3 > 12) {
	i3 = 12;
    }
    *perm = b / (exp(log(fld8_blck11_1.atpcm[i2 + (i3 - 1) * 20 - 21]) + (log(
	    fld8_blck11_1.atpcm[i2 + i3 * 20 - 21]) - log(fld8_blck11_1.atpcm[i2 + (i3 
	    - 1) * 20 - 21])) * (b * 10.f - 10.f - (real) (i3 - 2))) * 
	    1.2566371e-4f);
    if (b > 2.1f) {
	*perm = b / (fld8_blck11_1.atpcm[i2 + 219] * 1.2566371e-4f + b - 2.1f);
    }
L802:
    return 0;
} /* magn_ */

/* Subroutine */ int elc_(void)
{
    /* Format strings */
    static char fmt_81[] = "(30000e14.7)";
    static char fmt_82[] = "(30000i14)";
    static char fmt_83[] = "(80a1)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double r_imag(complex *);

    /* Local variables */
    static integer i__, n, j2, j3, j4, k4, k2, k8, k3;

    /* Fortran I/O blocks */
    static cilist io___509 = { 0, 4, 0, fmt_82, 0 };
    static cilist io___510 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___512 = { 0, 4, 0, fmt_82, 0 };
    static cilist io___513 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___514 = { 0, 4, 0, fmt_83, 0 };
    static cilist io___515 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___523 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___524 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___525 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___526 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___527 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___528 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___529 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___530 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___531 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___532 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___533 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___534 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___535 = { 0, 4, 0, fmt_82, 0 };
    static cilist io___536 = { 0, 4, 0, fmt_82, 0 };
    static cilist io___537 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___538 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___539 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___540 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___541 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___542 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___543 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___544 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___545 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___546 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___547 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___548 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___549 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___550 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___551 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___552 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___553 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___554 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___555 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___556 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___557 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___558 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___559 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___560 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___561 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___562 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___563 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___564 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___565 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___566 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___567 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___568 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___569 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___570 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___571 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___572 = { 0, 4, 0, fmt_81, 0 };


/* --- PLOT PREPARATION */
/* --- WRITE TO GRAPHICS FILE */
/* L81: */
/* L82: */
/* L83: */
    n = 2;
    s_wsfe(&io___509);
    do_fio(&fld8_c__1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.i5, (ftnlen)sizeof(integer));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.i6, (ftnlen)sizeof(integer));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.linto, (ftnlen)sizeof(integer));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.lnver, (ftnlen)sizeof(integer));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.lnhor, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___510);
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.flaxi, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.flxln, (ftnlen)sizeof(real));
    do_fio(&fld8_c__1, (char *)&fld8_block1_1.scale, (ftnlen)sizeof(real));
    for (i__ = 1; i__ <= 300; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.xpos[i__ - 1], (ftnlen)sizeof(real));
    }
    for (i__ = 1; i__ <= 300; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.ypos[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___512);
    for (i__ = 1; i__ <= 150; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.iln[i__ - 1], (ftnlen)sizeof(shortint)
		);
    }
    e_wsfe();
    s_wsfe(&io___513);
    for (i__ = 1; i__ <= 3000; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block2_1.linc[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___514);
    do_fio(&fld8_c__80, fld8_blck10_1.ident, (ftnlen)1);
    e_wsfe();
    i__1 = fld8_block1_1.linto;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fld8_block3_1.datln[i__ + 299] = 1.f;
	if (fld8_block3_1.datln[i__ + 149] != 0.f) {
	    fld8_block3_1.datln[i__ + 299] = 2.f;
	}
	if (fld8_block3_1.datln[i__ + 149] != 0.f && fld8_block3_1.datln[i__ + 1649] == 
		0.f) {
	    fld8_block3_1.datln[i__ + 299] = 0.f;
	}
	if (fld8_block3_1.datln[i__ - 1] > 1.f) {
	    fld8_block3_1.datln[i__ + 299] = 0.f;
	}
/* L201: */
    }
    s_wsfe(&io___515);
    i__1 = fld8_block1_1.linto;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block3_1.datln[i__ + 299], (ftnlen)sizeof(real)
		);
    }
    e_wsfe();
    j4 = fld8_block1_1.i6 / 4;
    j2 = fld8_block1_1.i6 / 2;
    j3 = j2 + j4;
    k8 = fld8_block1_1.i5 / 8;
    k4 = fld8_block1_1.i5 / 4;
    k2 = fld8_block1_1.i5 / 2;
    k3 = k4 + k8;
/* --- NODE COORDINATES IN MILLIMETERS */
    s_wsfe(&io___523);
    i__1 = j4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	r__1 = fld8_block3_1.vert[i__ - 1] * 1e3f;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___524);
    i__1 = j2;
    for (i__ = j4 + 1; i__ <= i__1; ++i__) {
	r__1 = fld8_block3_1.vert[i__ - 1] * 1e3f;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___525);
    i__1 = j3;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	r__1 = fld8_block3_1.vert[i__ - 1] * 1e3f;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___526);
    i__1 = fld8_block1_1.i6;
    for (i__ = j3 + 1; i__ <= i__1; ++i__) {
	r__1 = fld8_block3_1.vert[i__ - 1] * 1e3f;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___527);
    i__1 = j4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	r__1 = fld8_block3_1.vert[i__ + 29999] * 1e3f;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___528);
    i__1 = j2;
    for (i__ = j4 + 1; i__ <= i__1; ++i__) {
	r__1 = fld8_block3_1.vert[i__ + 29999] * 1e3f;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___529);
    i__1 = j3;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	r__1 = fld8_block3_1.vert[i__ + 29999] * 1e3f;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___530);
    i__1 = fld8_block1_1.i6;
    for (i__ = j3 + 1; i__ <= i__1; ++i__) {
	r__1 = fld8_block3_1.vert[i__ + 29999] * 1e3f;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
/* --- VECTOR POTENTIALS */
    s_wsfe(&io___531);
    i__1 = j4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__ - 1;
	r__1 = fld8_block3_1.cpot[i__2].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___532);
    i__2 = j2;
    for (i__ = j4 + 1; i__ <= i__2; ++i__) {
	i__1 = i__ - 1;
	r__1 = fld8_block3_1.cpot[i__1].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___533);
    i__1 = j3;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	i__2 = i__ - 1;
	r__1 = fld8_block3_1.cpot[i__2].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___534);
    i__2 = fld8_block1_1.i6;
    for (i__ = j3 + 1; i__ <= i__2; ++i__) {
	i__1 = i__ - 1;
	r__1 = fld8_block3_1.cpot[i__1].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
/* --- INFORMATION ABOUT THE GRID, STORED IN INDIVIDUAL BITS */
    s_wsfe(&io___535);
    i__1 = j2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block8_1.ibit[i__ - 1], (ftnlen)sizeof(integer)
		);
    }
    e_wsfe();
    s_wsfe(&io___536);
    i__1 = fld8_block1_1.i6;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block8_1.ibit[i__ - 1], (ftnlen)sizeof(integer)
		);
    }
    e_wsfe();
/* --- PERMEABILITIES */
    s_wsfe(&io___537);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___538);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___539);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___540);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___541);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + k2 - 1], (ftnlen)sizeof(
		real));
    }
    e_wsfe();
    s_wsfe(&io___542);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + k2 - 1], (ftnlen)sizeof(
		real));
    }
    e_wsfe();
    s_wsfe(&io___543);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + k2 - 1], (ftnlen)sizeof(
		real));
    }
    e_wsfe();
    s_wsfe(&io___544);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + k2 - 1], (ftnlen)sizeof(
		real));
    }
    e_wsfe();
/* --- CONDUCTIVITIES */
    s_wsfe(&io___545);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + 59301], (ftnlen)sizeof(real)
		);
    }
    e_wsfe();
    s_wsfe(&io___546);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + 59301], (ftnlen)sizeof(real)
		);
    }
    e_wsfe();
    s_wsfe(&io___547);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + 59301], (ftnlen)sizeof(real)
		);
    }
    e_wsfe();
    s_wsfe(&io___548);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + 59301], (ftnlen)sizeof(real)
		);
    }
    e_wsfe();
    s_wsfe(&io___549);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + k2 + 59301], (ftnlen)sizeof(
		real));
    }
    e_wsfe();
    s_wsfe(&io___550);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + k2 + 59301], (ftnlen)sizeof(
		real));
    }
    e_wsfe();
    s_wsfe(&io___551);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + k2 + 59301], (ftnlen)sizeof(
		real));
    }
    e_wsfe();
    s_wsfe(&io___552);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&fld8_c__1, (char *)&fld8_block1_1.tri[i__ + k2 + 59301], (ftnlen)sizeof(
		real));
    }
    e_wsfe();
/* --- VECTOR POTENTIALS */
    s_wsfe(&io___553);
    i__1 = j4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block3_1.cpot[i__ - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___554);
    i__1 = j2;
    for (i__ = j4 + 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block3_1.cpot[i__ - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___555);
    i__1 = j3;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block3_1.cpot[i__ - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___556);
    i__1 = fld8_block1_1.i6;
    for (i__ = j3 + 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block3_1.cpot[i__ - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
/* --- CURRENT DENSITIES */
    s_wsfe(&io___557);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__ - 1;
	r__1 = fld8_block1_1.cdens[i__2].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___558);
    i__2 = k4;
    for (i__ = k8 + 1; i__ <= i__2; ++i__) {
	i__1 = i__ - 1;
	r__1 = fld8_block1_1.cdens[i__1].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___559);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	i__2 = i__ - 1;
	r__1 = fld8_block1_1.cdens[i__2].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___560);
    i__2 = k2;
    for (i__ = k3 + 1; i__ <= i__2; ++i__) {
	i__1 = i__ - 1;
	r__1 = fld8_block1_1.cdens[i__1].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___561);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__ + k2 - 1;
	r__1 = fld8_block1_1.cdens[i__2].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___562);
    i__2 = k4;
    for (i__ = k8 + 1; i__ <= i__2; ++i__) {
	i__1 = i__ + k2 - 1;
	r__1 = fld8_block1_1.cdens[i__1].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___563);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	i__2 = i__ + k2 - 1;
	r__1 = fld8_block1_1.cdens[i__2].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___564);
    i__2 = k2;
    for (i__ = k3 + 1; i__ <= i__2; ++i__) {
	i__1 = i__ + k2 - 1;
	r__1 = fld8_block1_1.cdens[i__1].r;
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___565);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block1_1.cdens[i__ - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___566);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block1_1.cdens[i__ - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___567);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block1_1.cdens[i__ - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___568);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block1_1.cdens[i__ - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___569);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block1_1.cdens[i__ + k2 - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___570);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block1_1.cdens[i__ + k2 - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___571);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block1_1.cdens[i__ + k2 - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___572);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	r__1 = r_imag(&fld8_block1_1.cdens[i__ + k2 - 1]);
	do_fio(&fld8_c__1, (char *)&r__1, (ftnlen)sizeof(real));
    }
    e_wsfe();
    return 0;
} /* elc_ */

