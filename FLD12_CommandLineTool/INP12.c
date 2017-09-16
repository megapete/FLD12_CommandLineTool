/* INP12.F -- translated by f2c (version 20100827).
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

// PCH: All global declarations (and references) have had their names changed by adding the prefix 'inp12_' to avoid namespace clashing. That way, they'll stay global, but will only be referred to within this file.

struct {
    real v[6300], seg[7800]	/* was [200][39] */, zu;
    integer nseg;
} inp12_block1_;

#define inp12_block1_1 inp12_block1_

/* Table of constant values */

static integer inp12_c__80 = 80;
static integer inp12_c__1 = 1;
static integer inp12_c__2 = 2;
static integer inp12_c__4 = 4;
static integer inp12_c__14 = 14;
static integer inp12_c__8 = 8;
static integer inp12_c__7 = 7;

/* --- INPUT PROGRAM FLD12 */
// PCH: I've changed the name from MAIN__ to INP12MAIN__ and then called it from the main() function. This seems to work
// PCH: I'm sending in the directory where the files are to be read/written
int INP12MAIN__(char *baseDirectory)
{
    /* Format strings */
    static char fmt_1[] = "(8f10.0/7f10.0/7f10.0)";
    static char fmt_2[] = "(4f10.0)";
    static char fmt_3[] = "(4f10.0/6f10.0)";
    static char fmt_4[] = "(5f10.0/4f10.0)";
    static char fmt_5[] = "(80a1)";
    static char fmt_10[] = "(10f7.2)";
    static char fmt_13[] = "(3f10.4)";
    static char fmt_16[] = "(3f10.4,f10.2,2f10.4)";
    static char fmt_18[] = "(8f10.4)";
    static char fmt_34[] = "(4f10.4/4f10.4/4f10.4)";
    static char fmt_68[] = "(8f10.4/8f10.4/8f10.4/8f10.4/8f10.4/8f10.4/8f10."
	    "4/8f10.4)";
    static char fmt_97[] = "(\002A z-coordinate is not in increasing order i"
	    "n segment no.\002,i3)";

    /* System generated locals */
    integer i__1, i__2;
    real r__1, r__2;
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer f_open(olist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(void);
    /* Subroutine */ int s_paus(char *, ftnlen);
    integer f_clos(cllist *), s_wsfe(cilist *), e_wsfe(void);
    double sqrt(doublereal), atan(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, n;
    static real w[8], e1, e2, e3, e4, e5;
    static integer j1, j2;
    static real e6, e7;
    static integer i1;
    static real z1, pi, zb;
    static integer out;
    static real sqr3, fleg, aseg, dpel, dzde, shld, freq, zang;
    static integer nlay;
    static real rmin, term[54]	/* was [6][9] */;
    static integer isht;
    static real zkvn, zopt, zkvr, zkvt, zmid1, zmid2, acond, fpeak, scale, 
	    dcore, fract, phase;
    static char ident[1*80];
    static real scgva, ftank, limbs, resal;
    static integer itank;
    static real layer[300]	/* was [30][10] */, fyoke, rtank, rescu;
    static integer iexit;
    static real flxln;
    static integer nterm;
    static real zsgmn, wntnk, units, zsgmx, vturn;
    extern /* Subroutine */ int adjlin_(integer *, integer *, real *);

    /* Fortran I/O blocks */
    static cilist io___7 = { 0, 1, 0, fmt_5, 0 };
    static cilist io___9 = { 0, 1, 0, fmt_1, 0 };
    static cilist io___33 = { 0, 1, 0, fmt_2, 0 };
    static cilist io___36 = { 0, 1, 0, fmt_3, 0 };
    static cilist io___38 = { 0, 1, 0, fmt_4, 0 };
    static cilist io___44 = { 0, 0, 0, fmt_97, 0 };
    static cilist io___69 = { 0, 2, 0, fmt_5, 0 };
    static cilist io___71 = { 0, 2, 0, fmt_18, 0 };
    static cilist io___72 = { 0, 2, 0, fmt_68, 0 };
    static cilist io___73 = { 0, 2, 0, fmt_10, 0 };
    static cilist io___74 = { 0, 2, 0, fmt_68, 0 };
    static cilist io___75 = { 0, 2, 0, fmt_34, 0 };
    static cilist io___76 = { 0, 2, 0, fmt_13, 0 };
    static cilist io___77 = { 0, 2, 0, fmt_16, 0 };
    static cilist io___78 = { 0, 2, 0, fmt_10, 0 };


/* L1: */
/* L2: */
/* L3: */
/* L4: */
/* L5: */
/* L10: */
/* L13: */
/* L16: */
/* L18: */
/* L34: */
/* L68: */
/* L97: */
    o__1.oerr = 0;
    o__1.ounit = 1;
    // o__1.ofnmlen = 58;
    // PCH: Next 5 lines by me
    char fName[255];
    strcpy(fName, baseDirectory);
    strcat(fName, "INP1.FIL");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    o__1.oerr = 0;
    o__1.ounit = 7;
    // o__1.ofnmlen = 56;
    strcpy(fName, baseDirectory);
    strcat(fName, "OUTPUT");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    out = 7;
    pi = 3.141593f;
    sqr3 = 1.732051f;
/* --- RESISTIVITIES, OHMS*MM */
    rescu = 2.1e-5f;
    resal = 3.44e-5f;
    for (i__ = 1; i__ <= 6300; ++i__) {
/* L100: */
	inp12_block1_1.v[i__ - 1] = 0.f;
    }
    s_rsfe(&io___7);
    do_fio(&inp12_c__80, ident, (ftnlen)1);
    e_rsfe();
    s_rsfe(&io___9);
    do_fio(&inp12_c__1, (char *)&units, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&phase, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&freq, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&limbs, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&fract, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&zb, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&inp12_block1_1.zu, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&dcore, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&wntnk, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&shld, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&scgva, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&zopt, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&fpeak, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&e1, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&e2, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&dpel, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&dzde, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&ftank, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&fleg, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&fyoke, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&scale, (ftnlen)sizeof(real));
    do_fio(&inp12_c__1, (char *)&flxln, (ftnlen)sizeof(real));
    e_rsfe();
/* --- NUMBER OF TERMINALS */
    nterm = e1;
/* --- NUMBER OF LAYERS */
    nlay = e2;
    s_rsfe(&io___33);
    i__1 = nterm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    do_fio(&inp12_c__1, (char *)&term[i__ + j * 6 - 7], (ftnlen)sizeof(real)
		    );
	}
    }
    e_rsfe();
    i__1 = nterm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (term[i__ + 17] <= 0.f) {
	    s_paus("kV is negative or zero", (ftnlen)22);
	}
/* L101: */
    }
    s_rsfe(&io___36);
    i__1 = nlay;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 10; ++j) {
	    do_fio(&inp12_c__1, (char *)&layer[i__ + j * 30 - 31], (ftnlen)sizeof(
		    real));
	}
    }
    e_rsfe();
    i__1 = nlay;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ == 1) {
	    goto L102;
	}
	if (layer[i__ - 1] != layer[i__ - 2] + 1.f) {
	    s_paus("Layer numbers are not in increasing order", (ftnlen)41);
	}
	if (layer[i__ + 29] <= layer[i__ + 28]) {
	    s_paus("Last segment numbers are not in increasing order", (
		    ftnlen)48);
	}
L102:
	;
    }
/* --- NUMBER OF SEGMENTS */
    inp12_block1_1.nseg = layer[nlay + 29];
    s_rsfe(&io___38);
    i__1 = inp12_block1_1.nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 9; ++j) {
	    do_fio(&inp12_c__1, (char *)&inp12_block1_1.seg[i__ + j * 200 - 201], (ftnlen)
		    sizeof(real));
	}
    }
    e_rsfe();
    cl__1.cerr = 0;
    cl__1.cunit = 1;
    cl__1.csta = 0;
    f_clos(&cl__1);
    i__1 = inp12_block1_1.nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ == 1) {
	    goto L103;
	}
	if (inp12_block1_1.seg[i__ - 1] != inp12_block1_1.seg[i__ - 2] + 1.f) {
	    s_paus("Segment numbers are not in increasing order", (ftnlen)43);
	}
L103:
	;
    }
    if (units != 2.f) {
	goto L136;
    }
/* --- CONVERSION OF INCHES TO MM */
    zb *= 25.4f;
    inp12_block1_1.zu *= 25.4f;
    dcore *= 25.4f;
    wntnk *= 25.4f;
    dzde *= 25.4f;
    i__1 = nlay;
    for (i__ = 1; i__ <= i__1; ++i__) {
	layer[i__ + 59] *= 25.4f;
	layer[i__ + 89] *= 25.4f;
/* L134: */
	layer[i__ + 269] *= 25.4f;
    }
    i__1 = inp12_block1_1.nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	inp12_block1_1.seg[i__ + 199] *= 25.4f;
	inp12_block1_1.seg[i__ + 399] *= 25.4f;
	inp12_block1_1.seg[i__ + 1399] *= 25.4f;
/* L135: */
	inp12_block1_1.seg[i__ + 1599] *= 25.4f;
    }
L136:
    rmin = dcore * .5f;
    isht = 0;
    i__1 = inp12_block1_1.nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (inp12_block1_1.seg[i__ + 1599] >= 100.f) {
	    isht = 1;
	}
	inp12_block1_1.seg[i__ + 7399] = inp12_block1_1.seg[i__ + 199];
/* L137: */
	inp12_block1_1.seg[i__ + 7599] = inp12_block1_1.seg[i__ + 399];
    }
/* L138: */
    i__1 = inp12_block1_1.nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	e1 = (real) i__;
	i__2 = nlay;
	for (k = 1; k <= i__2; ++k) {
	    if (e1 > layer[k + 29]) {
		goto L140;
	    }
	    inp12_block1_1.seg[i__ + 1799] = (real) k;
	    if (layer[k + 179] == 0.f) {
		inp12_block1_1.seg[i__ + 799] = 0.f;
	    }
	    if (layer[k + 179] >= 0.f) {
		goto L141;
	    }
	    if (dpel != 2.f) {
		goto L139;
	    }
	    j1 = 1;
	    if (k > 1) {
		j1 = (integer) layer[k + 28] + 1;
	    }
	    j2 = layer[k + 29];
	    e1 = inp12_block1_1.seg[j1 + 7399];
	    e2 = inp12_block1_1.seg[j2 + 7599];
	    inp12_block1_1.seg[i__ + 199] = inp12_block1_1.seg[i__ + 7399] + dzde * (
		    inp12_block1_1.seg[i__ + 7399] - e1) / (e2 - e1);
	    inp12_block1_1.seg[i__ + 399] = inp12_block1_1.seg[i__ + 7599] + dzde * (
		    inp12_block1_1.seg[i__ + 7599] - e1) / (e2 - e1);
	    goto L141;
L139:
	    inp12_block1_1.seg[i__ + 199] = inp12_block1_1.seg[i__ + 7399] + dzde;
	    inp12_block1_1.seg[i__ + 399] = inp12_block1_1.seg[i__ + 7599] + dzde;
	    goto L141;
L140:
	    ;
	}
L141:
	;
    }
/* --- ADJUSTMENT OF Z - UPPER AND LOWER BOUNDARIES */
    i__1 = inp12_block1_1.nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	inp12_block1_1.seg[i__ + 199] -= zb;
	inp12_block1_1.seg[i__ + 399] -= zb;
	if (inp12_block1_1.seg[i__ + 399] <= inp12_block1_1.seg[i__ + 199]) {
	    goto L149;
	}
	if (i__ == 1) {
	    goto L150;
	}
	if (inp12_block1_1.seg[i__ + 1799] != inp12_block1_1.seg[i__ + 1798]) {
	    goto L150;
	}
	if (inp12_block1_1.seg[i__ + 199] >= inp12_block1_1.seg[i__ + 398]) {
	    goto L150;
	}
L149:
	io___44.ciunit = out;
	s_wsfe(&io___44);
	do_fio(&inp12_c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	s_paus("", (ftnlen)0);
L150:
	;
    }
    inp12_block1_1.zu -= zb;
    zb = 0.f;
/* --- CORE RADIUS */
    inp12_block1_1.v[64] = rmin;
/* --- DISTANCE CORE LEG - TANK */
    e1 = layer[nlay + 59] + layer[nlay + 89] + wntnk - inp12_block1_1.v[64];
/* --- POSITIONS, AXIAL GRID LINES */
    inp12_block1_1.v[0] = 1.f;
/* --- MAX. LINE SPACING BETWEEN OUTER LAYER AND TANK */
    e2 = e1 * .1f;
/* --- BETWEEN INNER LAYER AND CORE, AND ALSO BETWEEN LAYERS */
    e3 = e1 * .05f;
/* --- WITHIN LAYERS */
    e4 = e1 * .025f;
/* --- LAST INPUT NUMBER */
    i__ = 65;
/* --- LAYER NUMBER */
    j = 1;
L153:
    if (j == 1) {
	goto L154;
    }
    if (layer[j + 59] < layer[j + 58] + layer[j + 88] * .5f) {
	goto L158;
    }
/* --- DISTANCE FROM LAST LINE TO INNER LAYER RADIUS */
L154:
    e5 = layer[j + 59] - inp12_block1_1.v[i__ - 1];
    l = layer[j + 29];
    e6 = 0.f;
    e7 = 0.f;
    if (inp12_block1_1.seg[l + 1599] < 100.f) {
	goto L155;
    }
/* --- SHEET WINDING */
/* --- TURN INSULATION THICKNESS */
    e6 = (layer[j + 89] - inp12_block1_1.seg[l + 599] * inp12_block1_1.seg[l + 999] * 
	    inp12_block1_1.seg[l + 1399]) / (inp12_block1_1.seg[l + 599] - 1.f);
    e7 = (inp12_block1_1.seg[l + 999] * inp12_block1_1.seg[l + 1399] - e6) * .25f;
    e5 += e7;
L155:
    k = (integer) (e5 / e3 + .999f);
/* --- AXIAL LINES UP TO INNER LAYER RADIUS */
    if (k > 0) {
	++i__;
    }
    inp12_block1_1.v[i__ - 1] = layer[j + 59] + e7;
    if (k > 0) {
	inp12_block1_1.v[i__ - 65] = inp12_block1_1.v[i__ - 66] + (real) k;
    }
    k = (integer) (layer[j + 89] / e4 + .999f);
    if (inp12_block1_1.seg[l + 1599] >= 100.f) {
	k = inp12_block1_1.seg[l + 599] * 2 - 1;
    }
/* --- AXIAL LINES UP TO OUTER LAYER RADIUS */
    ++i__;
    inp12_block1_1.v[i__ - 1] = inp12_block1_1.v[i__ - 2] + layer[j + 89] - e7 * 2.f;
    inp12_block1_1.v[i__ - 65] = inp12_block1_1.v[i__ - 66] + (real) k;
L158:
    ++j;
    if (j <= nlay) {
	goto L153;
    }
    k = (integer) (wntnk / e2 + .999f);
/* --- AXIAL LINES BETWEEN OUTER LAYER AND TANK */
    ++i__;
    inp12_block1_1.v[i__ - 1] = inp12_block1_1.v[i__ - 2] + wntnk;
    rtank = inp12_block1_1.v[i__ - 1];
    itank = i__ - 64;
    inp12_block1_1.v[itank - 1] = inp12_block1_1.v[i__ - 66] + (real) k;
/* --- FIND MIN AND MAX Z-COORDINATES FOR SEGMENTS (WITH SHEET WINDINGS) */
    i1 = 0;
L160:
    zsgmn = 9.9e9f;
    zsgmx = 0.f;
    zmid1 = 0.f;
    zmid2 = 9.9e9f;
    i__1 = inp12_block1_1.nseg;
    for (l = 1; l <= i__1; ++l) {
	if (inp12_block1_1.seg[l + 1599] < 100.f && i1 == 0) {
	    goto L161;
	}
	if (inp12_block1_1.seg[l + 199] < zsgmn) {
	    zsgmn = inp12_block1_1.seg[l + 199];
	}
	if (inp12_block1_1.seg[l + 199] > inp12_block1_1.zu * .4f && inp12_block1_1.seg[l + 199]
		 < zmid2) {
	    zmid2 = inp12_block1_1.seg[l + 199];
	}
	if (inp12_block1_1.seg[l + 399] > zsgmx) {
	    zsgmx = inp12_block1_1.seg[l + 399];
	}
	if (inp12_block1_1.seg[l + 399] < inp12_block1_1.zu * .6f && inp12_block1_1.seg[l + 399]
		 > zmid1) {
	    zmid1 = inp12_block1_1.seg[l + 399];
	}
L161:
	;
    }
    if (zsgmx > 0.f) {
	goto L162;
    }
    i1 = 1;
    goto L160;
L162:
    e1 = inp12_block1_1.zu - zsgmx;
/* --- POSITIONS, RADIAL GRID LINES */
    inp12_block1_1.v[i__] = 1.f;
    i__ += 65;
/* --- LAST LINE NUMBER */
    j = 1;
    if (isht == 1) {
	goto L182;
    }
/* --- CALCULATIONS WITH FULL DEPTH */
    if (fract < .7f) {
	goto L170;
    }
/* --- MAX. LINE SPACING BETWEEN YOKE AND WINDING */
    e3 = inp12_block1_1.zu * .025f;
    k = (integer) (zsgmn / e3 + .999f);
    if (k < 4) {
	k = 4;
    }
/* --- RADIAL LINES UP TO ZSGMN */
    ++i__;
    inp12_block1_1.v[i__ - 1] = zsgmn;
    inp12_block1_1.v[i__ - 65] = (real) k + 1.f;
/* --- RADIAL LINES UP TO ZSGMX */
    e4 = zsgmx - zsgmn;
    if (e4 < inp12_block1_1.zu / 3.f) {
	goto L166;
    }
/* --- THE WINDING TAKES UP MORE THAN 1/3 OF THE SECTION DEPTH */
    r__1 = inp12_block1_1.v[i__ - 1] + e4 * .01f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e4 * .02f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e4 * .03f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e4 * .04f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e4 * .12f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e4 * .56f;
    adjlin_(&i__, &inp12_c__14, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e4 * .12f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e4 * .04f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e4 * .03f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e4 * .02f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    adjlin_(&i__, &inp12_c__2, &zsgmx);
    goto L168;
/* --- THE WINDING TAKES UP LESS THAN 1/3 OF THE SECTION DEPTH */
L166:
    e5 = inp12_block1_1.zu * .01f;
    k = (integer) (e4 / e5 + .999f);
    adjlin_(&i__, &k, &zsgmx);
/* --- REMAINING RADIAL LINES */
L168:
    k = (integer) (e1 / e3 + .999f);
    if (k < 4) {
	k = 4;
    }
    ++i__;
    inp12_block1_1.v[i__ - 1] = inp12_block1_1.zu;
    inp12_block1_1.v[i__ - 65] = inp12_block1_1.v[i__ - 66] + (real) k;
    goto L197;
/* --- CALCULATIONS WITH HALF DEPTH FOR TRANSFORMERS WITH AXIAL SYMMETRY */
/* --- AND NO SHEET WINDINGS */
/* --- (ADDITIONAL LINES MAY BE PUT IN LATER) */
L170:
    z1 = inp12_block1_1.zu;
    i__1 = inp12_block1_1.nseg;
    for (l = 1; l <= i__1; ++l) {
	if (inp12_block1_1.seg[l + 199] != 0.f && inp12_block1_1.seg[l + 199] < z1) {
	    z1 = inp12_block1_1.seg[l + 199];
	}
/* L171: */
    }
    if (z1 > zsgmx * .0375f) {
	goto L172;
    }
    ++i__;
    inp12_block1_1.v[i__ - 1] = z1;
    inp12_block1_1.v[i__ - 65] = inp12_block1_1.v[i__ - 66] + 1.f;
L172:
    if (zsgmx < inp12_block1_1.zu / 3.f) {
	goto L173;
    }
/* --- THE WINDING TAKES UP MORE THAN 1/3 OF THE SECTION DEPTH */
    r__1 = zsgmx * .3f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = zsgmx * .7f;
    adjlin_(&i__, &inp12_c__8, &r__1);
    r__1 = zsgmx * .78f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    r__1 = zsgmx * .84f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    r__1 = zsgmx * .89f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    r__1 = zsgmx * .93f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    r__1 = zsgmx * .96f;
    adjlin_(&i__, &inp12_c__2, &r__1);
    adjlin_(&i__, &inp12_c__4, &zsgmx);
    goto L195;
/* --- THE WINDING TAKES UP LESS THAN 1/3 OF THE SECTION DEPTH */
L173:
    e5 = inp12_block1_1.zu * .015f;
    k = (integer) (zsgmx / e5 + .999f);
    adjlin_(&i__, &k, &zsgmx);
    goto L195;
L182:
    if (fract > .7f) {
	goto L184;
    }
    if (zsgmn > 0.f) {
	goto L183;
    }
/* --- CALCULATIONS WITH HALF DEPTH FOR TRANSFORMERS WITH AXIAL SYMMETRY */
/* --- AND SHEET WINDINGS. ONE SHEET AXIALLY. */
    e5 = 0.f;
    r__1 = zsgmx * .7f;
    adjlin_(&i__, &inp12_c__7, &r__1);
    r__1 = zsgmx * .86f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = zsgmx * .94f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = zsgmx * .98f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    adjlin_(&i__, &inp12_c__4, &zsgmx);
    goto L195;
/* --- TWO SHEETS AXIALLY */
L183:
    e2 = inp12_block1_1.zu * .05f;
    k = (integer) (zsgmn / e2 + .999f);
    if (k < 2) {
	k = 2;
    }
    e5 = (real) k;
    adjlin_(&i__, &k, &zsgmn);
    e3 = zsgmx - zsgmn;
    r__1 = zsgmn + e3 * .02f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = zsgmn + e3 * .1f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = zsgmn + e3 * .3f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = zsgmn + e3 * .7f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = zsgmn + e3 * .9f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = zsgmn + e3 * .98f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    adjlin_(&i__, &inp12_c__4, &zsgmx);
    goto L195;
/* --- CALCULATIONS WITH FULL DEPTH FOR TRANSFORMERS WITH SHEET WINDINGS. */
/* --- MAX. LINE SPACING BETWEEN YOKE AND WINDING */
L184:
    e3 = inp12_block1_1.zu * .025f;
    k = (integer) (zsgmn / e3 + .999f);
    if (k < 4) {
	k = 4;
    }
/* --- RADIAL LINES UP TO ZSGMN */
    ++i__;
    inp12_block1_1.v[i__ - 1] = zsgmn;
    inp12_block1_1.v[i__ - 65] = (real) k + 1.f;
    if (zmid1 > 0.f) {
	goto L186;
    }
/* --- ONE SHEET AXIALLY */
    e6 = zsgmx - zsgmn;
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .01f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .02f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .04f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .08f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .7f;
    adjlin_(&i__, &inp12_c__14, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .08f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .04f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .02f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    adjlin_(&i__, &inp12_c__4, &zsgmx);
    goto L195;
/* --- TWO SHEETS AXIALLY */
L186:
    e6 = zmid1 - zsgmn;
    iexit = 0;
L187:
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .02f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .08f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .2f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .4f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .2f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .08f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    r__1 = inp12_block1_1.v[i__ - 1] + e6 * .02f;
    adjlin_(&i__, &inp12_c__4, &r__1);
    if (iexit == 1) {
	goto L195;
    }
    e6 = zmid2 - zmid1;
    k = (integer) (e6 / e3 + .999f);
    if (k < 4) {
	k = 4;
    }
/* --- RADIAL LINES UP TO ZMID2 */
    ++i__;
    inp12_block1_1.v[i__ - 1] = zmid2;
    inp12_block1_1.v[i__ - 65] = inp12_block1_1.v[i__ - 66] + (real) k;
    e6 = zsgmx - zmid2;
    iexit = 1;
    goto L187;
/* --- REMAINING RADIAL LINES */
L195:
    e2 = inp12_block1_1.zu * .05f;
    if (fract > .7f) {
	e2 = inp12_block1_1.zu * .025f;
    }
    k = (integer) (e1 / e2 + .999f);
    if (k < 4) {
	k = 4;
    }
    ++i__;
    inp12_block1_1.v[i__ - 1] = inp12_block1_1.zu;
    inp12_block1_1.v[i__ - 65] = inp12_block1_1.v[i__ - 66] + (real) k;
    e5 = inp12_block1_1.v[i__ - 66] - e5;
    if (inp12_block1_1.v[i__ - 65] > 174.f - e5) {
	inp12_block1_1.v[i__ - 65] = 174.f - e5;
    }
/* --- SCALE, NO. OF FLUX LINES AND CONTOUR LINES */
L197:
    i__ += 13;
    inp12_block1_1.v[i__ - 1] = scale;
    inp12_block1_1.v[i__] = flxln;
    inp12_block1_1.v[i__ + 1] = (real) (inp12_block1_1.nseg + 1);
    i1 = i__ + 2;
    i__ += 3;
/* --- INITIALIZE NUMBER OF TURNS IN SERIES FOR EACH TERMINAL */
    i__1 = nterm;
    for (l = 1; l <= i__1; ++l) {
/* L201: */
	term[l + 23] = 0.f;
    }
    i__1 = inp12_block1_1.nseg;
    for (l = 1; l <= i__1; ++l) {
/* --- LAYER NUMBER */
	j = inp12_block1_1.seg[l + 1799];
/* --- TERMINAL NUMBER */
	k = layer[j + 119];
/* --- NUMBER OF ACTIVE TURNS IN SERIES (WITH SIGN) */
	e1 = inp12_block1_1.seg[l + 799] * layer[j + 179];
	if (layer[j + 149] == 1.f) {
	    term[k + 23] += e1;
	}
	if (layer[j + 149] >= 2.f) {
	    term[k + 23] += e1 * .5f;
	}
/* L202: */
    }
/* --- DIMENSIONING KVA */
    i__1 = nterm;
    for (l = 1; l <= i__1; ++l) {
	term[l + 29] = term[l + 11] * 1e3f;
/* --- DATA FOR PHASE SHIFT WINDINGS */
	e1 = term[l + 5];
	if (e1 <= 4.f) {
	    goto L203;
	}
	if (e1 == 5.f || e1 == 7.f || e1 == 9.f) {
	    term[l + 41] = term[l + 17];
	}
	if (e1 == 5.f || e1 == 7.f || e1 == 9.f) {
	    term[l + 42] = term[l + 17];
	}
	if (e1 == 6.f || e1 == 8.f || e1 == 10.f) {
	    term[l + 47] = term[l + 17];
	}
	if (e1 == 6.f || e1 == 8.f || e1 == 10.f) {
	    term[l + 46] = term[l + 17];
	}
L203:
	;
    }
/* --- CORRECTION FOR AUTO CONNECTION */
    if (term[6] != 3.f) {
	goto L204;
    }
    e1 = term[30];
    e3 = term[24] - term[25];
    if (term[18] < term[19]) {
	e3 = term[24] + term[25];
    }
    term[30] *= (r__1 = term[24] / e3, dabs(r__1));
    term[31] = term[30] - e1 + term[31];
L204:
    i__1 = inp12_block1_1.nseg;
    for (l = 1; l <= i__1; ++l) {
	j = inp12_block1_1.seg[l + 1799];
	k = layer[j + 119];
	e1 = term[k + 5];
/* --- MIN AND MAX RADIUS */
	inp12_block1_1.seg[l + 1999] = layer[j + 59];
	inp12_block1_1.seg[l + 2199] = layer[j + 89] + inp12_block1_1.seg[l + 1999];
/* --- KVA PER SEGMENT */
	inp12_block1_1.seg[l + 2399] = 0.f;
	if (term[k + 23] != 0.f) {
	    inp12_block1_1.seg[l + 2399] = term[k + 29] * fract * inp12_block1_1.seg[l + 
		    799] * layer[j + 179] / ((r__1 = term[k + 23], dabs(r__1))
		     * limbs);
	}
	if (layer[j + 149] >= 2.f) {
	    inp12_block1_1.seg[l + 2399] *= .5f;
	}
	if (e1 < 4.5f) {
	    goto L205;
	}
	zkvn = term[k + 41];
	zkvt = term[k + 47];
	if (e1 < 8.5f) {
/* Computing 2nd power */
	    r__1 = zkvn + zkvt * .5f;
/* Computing 2nd power */
	    r__2 = zkvt * .5f;
	    zkvr = sqrt(r__1 * r__1 + r__2 * r__2 * 3.f);
	}
	if (e1 > 8.5f) {
/* Computing 2nd power */
	    r__1 = zkvn + zkvt * 1.5f;
/* Computing 2nd power */
	    r__2 = zkvt * .5f;
	    zkvr = sqrt(r__1 * r__1 + r__2 * r__2 * 3.f);
	}
	if (zkvr == 0.f) {
	    goto L205;
	}
	inp12_block1_1.seg[l + 2399] = inp12_block1_1.seg[l + 2399] * term[k + 17] / zkvr;
	if (term[k + 5] == 10.f) {
	    inp12_block1_1.seg[l + 2399] = sqr3 * inp12_block1_1.seg[l + 2399];
	}
L205:
	;
    }
/* --- MIN KV */
    e1 = 9.9e9f;
    i__1 = nterm;
    for (l = 1; l <= i__1; ++l) {
	if (term[l + 17] > e1 || term[l + 17] == 0.f || term[l + 11] == 0.f) {
	    goto L206;
	}
	e1 = term[l + 17];
	j = l;
/* --- VOLTS PER PHASE */
L206:
	e2 = term[l + 17] * 1e3f;
	if (phase < 1.5f) {
	    goto L207;
	}
	if (term[l + 5] != 2.f && term[l + 5] < 6.5f) {
	    e2 /= 1.732051f;
	}
/* --- VOLTS PER TURN */
L207:
	term[l + 35] = e2 * phase * fract / (limbs * (r__1 = term[l + 23], 
		dabs(r__1)));
    }
    if (term[6] == 3.f) {
	term[36] *= (r__1 = term[24] / e3, dabs(r__1));
    }
    vturn = term[j + 35];
/* --- WINDING SEGMENTS */
    i__1 = inp12_block1_1.nseg;
    for (l = 1; l <= i__1; ++l) {
/* --- AREA OF CONDUCTOR */
	acond = inp12_block1_1.seg[l + 1399] * inp12_block1_1.seg[l + 1599];
/* --- LAYER NO. */
	j = inp12_block1_1.seg[l + 1799];
/* --- TERMINAL NO. */
	m = layer[j + 119];
	e2 = term[m + 5];
	zkvn = term[m + 41];
	zkvt = term[m + 47];
	if (e2 < 4.5f) {
	    goto L2071;
	}
	if (e2 < 8.5f) {
	    zang = 180.f / pi * atan(zkvt * .5f * sqr3 / (zkvn + zkvt * .5f));
	}
	if (e2 > 8.5f) {
	    zang = 180.f / pi * atan(zkvt * .5f * sqr3 / (zkvn + zkvt * 1.5f))
		    ;
	}
/* --- PHASE ANGLE OF CURRENT */
	if (e2 == 5.f || e2 == 7.f || e2 == 9.f) {
	    inp12_block1_1.v[i__ + 3] = -zang;
	}
	if (e2 == 6.f || e2 == 8.f) {
	    inp12_block1_1.v[i__ + 3] = -zang + 60.f;
	}
	if (e2 == 10.f) {
	    inp12_block1_1.v[i__ + 3] = -zang + 30.f;
	}
L2071:
	if (inp12_block1_1.seg[l + 1599] >= 100.f) {
	    goto L2081;
	}
	inp12_block1_1.v[i__ - 1] = 3.f;
	inp12_block1_1.v[i__] = 1.f;
/* --- AREA OF SEGMENT, SQ.MM */
	aseg = (inp12_block1_1.seg[l + 399] - inp12_block1_1.seg[l + 199]) * (
		inp12_block1_1.seg[l + 2199] - inp12_block1_1.seg[l + 1999]);
	if (acond > .25f) {
	    acond += -.25f;
	}
	if (acond > 14.75f) {
	    acond += -.25f;
	}
	if (inp12_block1_1.seg[l + 1399] == inp12_block1_1.seg[l + 1599] && inp12_block1_1.seg[
		l + 1399] <= 4.f) {
/* Computing 2nd power */
	    r__1 = inp12_block1_1.seg[l + 1399];
	    acond = pi / 4.f * (r__1 * r__1);
	}
/* --- FILL FACTOR */
/* L208: */
	inp12_block1_1.seg[l + 5999] = acond * inp12_block1_1.seg[l + 599] * inp12_block1_1.seg[
		l + 999] / aseg;
	if (layer[j + 149] >= 2.f) {
	    inp12_block1_1.seg[l + 5999] = layer[j + 149] * .5f * inp12_block1_1.seg[l + 
		    5999];
	}
	inp12_block1_1.v[i__ + 1] = inp12_block1_1.seg[l + 5999] * .001f * inp12_block1_1.seg[l 
		+ 799] / (rescu * inp12_block1_1.seg[l + 599]);
	if (layer[j + 209] == 2.f) {
	    inp12_block1_1.v[i__ + 1] = inp12_block1_1.v[i__ + 1] * rescu / resal;
	}
	if (inp12_block1_1.v[i__ + 1] == 0.f) {
	    inp12_block1_1.v[i__ + 1] = 1.f;
	}
/* --- TOTAL CURRENT */
	inp12_block1_1.v[i__ + 2] = inp12_block1_1.seg[l + 2399] * 1e3f / vturn;
	inp12_block1_1.v[i__ + 4] = 9.f;
	inp12_block1_1.v[i__ + 5] = 9e3f;
	inp12_block1_1.v[i__ + 6] = 2.f;
	inp12_block1_1.v[i__ + 7] = inp12_block1_1.seg[l + 1999];
	inp12_block1_1.v[i__ + 8] = inp12_block1_1.seg[l + 199];
	inp12_block1_1.v[i__ + 9] = inp12_block1_1.seg[l + 2199];
	inp12_block1_1.v[i__ + 10] = inp12_block1_1.seg[l + 399];
	i__ += 12;
	goto L209;
L2081:
	acond *= inp12_block1_1.seg[l + 999];
/* --- CURRENT PER TURN */
	e1 = inp12_block1_1.seg[l + 2399] * 1e3f / (vturn * inp12_block1_1.seg[l + 599]);
/* --- TURN INSULATION THICKNESS */
	e6 = (layer[j + 89] - inp12_block1_1.seg[l + 599] * inp12_block1_1.seg[l + 999] * 
		inp12_block1_1.seg[l + 1399]) / (inp12_block1_1.seg[l + 599] - 1.f);
	k = inp12_block1_1.seg[l + 599];
	inp12_block1_1.v[i1 - 1] += (real) (k - 1);
	i__2 = k;
	for (n = 1; n <= i__2; ++n) {
	    inp12_block1_1.v[i__ - 1] = 3.f;
	    inp12_block1_1.v[i__] = 1.f;
	    inp12_block1_1.v[i__ + 1] = .001f / rescu;
	    if (layer[j + 209] == 2.f) {
		inp12_block1_1.v[i__ + 1] = .001f / resal;
	    }
	    inp12_block1_1.v[i__ + 2] = e1;
	    if (n > 1) {
		inp12_block1_1.v[i__ + 3] = inp12_block1_1.v[i__ - 9];
	    }
	    inp12_block1_1.v[i__ + 4] = 10.f;
	    inp12_block1_1.v[i__ + 5] = 9e3f;
	    inp12_block1_1.v[i__ + 6] = 2.f;
	    inp12_block1_1.v[i__ + 7] = inp12_block1_1.seg[l + 1999] + (real) (n - 1) * (
		    inp12_block1_1.seg[l + 999] * inp12_block1_1.seg[l + 1399] + e6);
	    inp12_block1_1.v[i__ + 8] = inp12_block1_1.seg[l + 199];
	    inp12_block1_1.v[i__ + 9] = inp12_block1_1.v[i__ + 7] + inp12_block1_1.seg[l + 999] 
		    * inp12_block1_1.seg[l + 1399];
	    inp12_block1_1.v[i__ + 10] = inp12_block1_1.seg[l + 399];
	    i__ += 12;
/* L2082: */
	}
L209:
	;
    }
/* --- FLUX LINE OR REFERENCE POINT */
    inp12_block1_1.v[i__ - 1] = 1.f;
    inp12_block1_1.v[i__ + 4] = 2.f;
    inp12_block1_1.v[i__ + 5] = rtank;
    if (shld > .7f) {
	goto L210;
    }
    if (fract > .7f) {
	inp12_block1_1.v[i__ + 6] = inp12_block1_1.zu * .5f;
    }
    goto L211;
L210:
    inp12_block1_1.v[i__ - 1] = 2.f;
    inp12_block1_1.v[i__ + 7] = rtank;
    inp12_block1_1.v[i__ + 8] = inp12_block1_1.zu;
L211:
    o__1.oerr = 0;
    o__1.ounit = 2;
    // o__1.ofnmlen = 58;
    // o__1.ofnm = "/Users/peterhub/Documents/MyProjects/Andersen_F2C/INP2.FIL";
    strcpy(fName, baseDirectory);
    strcat(fName, "INP2.FIL");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    s_wsfe(&io___69);
    do_fio(&inp12_c__80, ident, (ftnlen)1);
    e_wsfe();
    w[0] = 2.f;
    w[1] = rmin;
    w[2] = 1.f;
    for (i__ = 4; i__ <= 8; ++i__) {
/* L212: */
	w[i__ - 1] = 0.f;
    }
    w[5] = freq;
    if (isht == 1) {
	w[6] = 4.f;
    }
    s_wsfe(&io___71);
    for (i__ = 1; i__ <= 8; ++i__) {
	do_fio(&inp12_c__1, (char *)&w[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___72);
    for (i__ = 1; i__ <= 64; ++i__) {
	do_fio(&inp12_c__1, (char *)&inp12_block1_1.v[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    j = 65;
    k = 1;
L213:
    n = 64;
L214:
    if (inp12_block1_1.v[j + n - 66] > .5f) {
	goto L215;
    }
    --n;
    if (n >= 2) {
	goto L214;
    }
L215:
    s_wsfe(&io___73);
    i__1 = j + n - 1;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_fio(&inp12_c__1, (char *)&inp12_block1_1.v[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    j += n;
    switch (k) {
	case 1:  goto L216;
	case 2:  goto L217;
    }
L216:
    s_wsfe(&io___74);
    i__1 = j + 63;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_fio(&inp12_c__1, (char *)&inp12_block1_1.v[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    j += 64;
    k = 2;
    goto L213;
L217:
    s_wsfe(&io___75);
    i__1 = j + 11;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_fio(&inp12_c__1, (char *)&inp12_block1_1.v[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    j += 12;
    s_wsfe(&io___76);
    i__1 = j + 2;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_fio(&inp12_c__1, (char *)&inp12_block1_1.v[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    j += 3;
    n = inp12_block1_1.v[j - 2];
L219:
    m = inp12_block1_1.v[j - 1] * 2.f;
    s_wsfe(&io___77);
    i__1 = j + 5;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_fio(&inp12_c__1, (char *)&inp12_block1_1.v[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    j += 6;
    s_wsfe(&io___78);
    i__1 = j + m - 1;
    for (i__ = j; i__ <= i__1; ++i__) {
	do_fio(&inp12_c__1, (char *)&inp12_block1_1.v[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    j += m;
    --n;
    if (n > 0) {
	goto L219;
    }
    cl__1.cerr = 0;
    cl__1.cunit = 1;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 2;
    cl__1.csta = 0;
    f_clos(&cl__1);
    // s_stop("", (ftnlen)0);
    return 0;
} /* MAIN__ */

/* Subroutine */ int adjlin_(integer *i__, integer *k, real *znew)
{
    /* System generated locals */
    integer i__1;
    real r__1;

    /* Builtin functions */
    double r_int(real *);

    /* Local variables */
    static integer l;
    static real e1, z1, z2, z3, dz, zp;

/* --- ADJUSTS RADIAL GRID LINES, IF NECESSARY */
    dz = (*znew - inp12_block1_1.v[*i__ - 1]) / (real) (*k);
    e1 = dz;
L300:
    zp = inp12_block1_1.zu;
    i__1 = inp12_block1_1.nseg;
    for (l = 1; l <= i__1; ++l) {
	z1 = inp12_block1_1.seg[l + 199];
	z2 = inp12_block1_1.seg[l + 399];
	if (inp12_block1_1.v[*i__ - 1] >= z2 || *znew <= z1) {
	    goto L380;
	}
	if (l == 1 || inp12_block1_1.v[*i__ - 1] >= z1) {
	    goto L340;
	}
	if (z1 > inp12_block1_1.seg[l + 398] && z1 - inp12_block1_1.v[*i__ - 1] < e1 && 
		z1 < zp) {
	    zp = z1;
	}
L340:
	if (z2 - z1 >= e1) {
	    goto L370;
	}
	if (z2 - z1 >= dz * .25f) {
	    e1 = z2 - z1;
	}
	if (z2 - z1 >= dz * .25f) {
	    goto L370;
	}
	if (z1 < zp && z1 > inp12_block1_1.v[*i__ - 1]) {
	    zp = z1;
	}
	if (z2 < zp && z2 > inp12_block1_1.v[*i__ - 1] && z2 <= *znew) {
	    zp = z2;
	}
L370:
	if (l == inp12_block1_1.nseg) {
	    goto L380;
	}
	z3 = inp12_block1_1.seg[l + 200];
	if (z3 - z2 <= 0.f || z3 - z2 >= e1) {
	    goto L380;
	}
	if (z2 > inp12_block1_1.v[*i__ - 1] && z2 < zp && z2 <= *znew) {
	    zp = z2;
	}
	if (z3 > inp12_block1_1.v[*i__ - 1] && z3 < zp && z3 <= *znew) {
	    zp = z3;
	}
L380:
	;
    }
    ++(*i__);
    if (zp == inp12_block1_1.zu) {
	goto L390;
    }
    inp12_block1_1.v[*i__ - 1] = zp;
    if (zp - inp12_block1_1.v[*i__ - 2] > e1) {
	goto L400;
    }
    inp12_block1_1.v[*i__ - 65] = inp12_block1_1.v[*i__ - 66] + 1.f;
    goto L410;
L390:
    inp12_block1_1.v[*i__ - 1] = *znew;
L400:
    r__1 = (inp12_block1_1.v[*i__ - 1] - inp12_block1_1.v[*i__ - 2]) / e1 + .999f;
    inp12_block1_1.v[*i__ - 65] = inp12_block1_1.v[*i__ - 66] + r_int(&r__1);
L410:
    if (inp12_block1_1.v[*i__ - 1] < *znew) {
	goto L300;
    }
    return 0;
} /* adjlin_ */

