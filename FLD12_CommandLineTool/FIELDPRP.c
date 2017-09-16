/* FIELDPRP.F -- translated by f2c (version 20100827).
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

#include <string.h>

/* Common Block Declarations */

struct {
    integer ibit[60000];
} fieldprp_block1_;

#define fieldprp_block1_1 fieldprp_block1_

struct {
    integer lnver;
} fieldprp_block2_;

#define fieldprp_block2_1 fieldprp_block2_

struct {
    integer lnhor;
} fieldprp_block3_;

#define fieldprp_block3_1 fieldprp_block3_

/* Table of constant values */

static integer fieldprp_c__1 = 1;
static integer fieldprp_c__80 = 80;
static real fieldprp_c_b125 = 0.f;
static integer fieldprp_c__2 = 2;
static integer fieldprp_c__3 = 3;

/* --- FORTRAN PROGRAM FOR FIELD PLOT */
/* --- GENERATES INPUT FOR PLOTTER PROGRAM IN BASIC */
/* Main program */ int FIELDPRPMAIN__(char *baseDirectory)
{
    /* Format strings */
    static char fmt_1[] = "(\002 \002,i5.5,2(9x,i5.5))";
    static char fmt_2[] = "(\002 \002,f8.2,600(6x,f8.2))";
    static char fmt_3[] = "(80a1)";
    static char fmt_4[] = "(60000e14.7)";
    static char fmt_5[] = "(60000i14)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    real r__1, r__2, r__3, r__4;
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer f_open(olist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(void), f_clos(cllist *);
    double sin(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void);
    double cos(doublereal);

    /* Local variables */
    static integer i__, j, k, l, m, n;
    static real e1, e2, e3, e4;
    static integer i1, i2, j2, j3, i5, i6, j4, k4, k2, k8, k3, n1, n2, n3, i3;
    static real x1, y1;
    static integer k1, j1, i10, i11;
    static real v11;
    static integer nn;
    static real vi, xi, yi, vk, vl, xy[8000]	/* was [2][4000] */, rad;
    static shortint iln[150];
    static integer inv;
    static real tri[119022], linc[3000], segm[20000]	/* was [4000][5] */;
    static integer imin;
    static real xend, yend;
    static integer imax;
    extern integer fieldprp_itri_(integer *, integer *);
    static real xmax, ymax;
    static integer lpnt;
    static real vert[180000]	/* was [60000][3] */, xctr, xpos[300], ypos[
	    300], alpha, scale, datln[150];
    static char ident[1*80];
    static real flaxi;
    static integer nline;
    static real eqlin;
    static shortint color;
    static real percv, ptcmn;
    static integer iexit, linto;
    static real ptcmx, yshft, typln, alpha1, aalpha, dalpha;
    static shortint points;

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 4, 0, fmt_5, 0 };
    static cilist io___6 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___13 = { 0, 4, 0, fmt_5, 0 };
    static cilist io___15 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___17 = { 0, 4, 0, fmt_3, 0 };
    static cilist io___19 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___28 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___30 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___31 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___32 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___33 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___34 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___35 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___36 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___37 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___38 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___39 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___40 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___41 = { 0, 4, 0, fmt_5, 0 };
    static cilist io___42 = { 0, 4, 0, fmt_5, 0 };
    static cilist io___43 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___45 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___46 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___47 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___48 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___49 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___50 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___51 = { 0, 4, 0, fmt_4, 0 };
    static cilist io___68 = { 0, 3, 0, fmt_3, 0 };
    static cilist io___69 = { 0, 3, 0, fmt_1, 0 };
    static cilist io___70 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___76 = { 0, 3, 0, fmt_1, 0 };
    static cilist io___77 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___78 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___79 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___80 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___81 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___82 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___83 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___84 = { 0, 3, 0, fmt_1, 0 };
    static cilist io___85 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___97 = { 0, 3, 0, fmt_1, 0 };
    static cilist io___98 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___99 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___100 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___101 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___102 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___103 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___104 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___124 = { 0, 3, 0, fmt_1, 0 };
    static cilist io___125 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___127 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___128 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___129 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___130 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___131 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___132 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___133 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___134 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___135 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___136 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___137 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___138 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___139 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___140 = { 0, 3, 0, fmt_2, 0 };
    static cilist io___141 = { 0, 3, 0, fmt_1, 0 };


/* --- OPEN FILE BAS.FIL */
/* L1: */
/* L2: */
/* L3: */
/* L4: */
/* L5: */
    o__1.oerr = 0;
    o__1.ounit = 3;
    // o__1.ofnmlen = 7;
    char fName[255];
    strcpy(fName, baseDirectory);
    strcat(fName, "BAS.FIL");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    // o__1.ofnm = "BAS.FIL";
    o__1.orl = 20000;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
/* --- READ FROM FILE FOR.FIL */
    o__1.oerr = 0;
    o__1.ounit = 4;
    // o__1.ofnmlen = 7;
    strcpy(fName, baseDirectory);
    strcat(fName, "FOR.FIL");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    // o__1.ofnm = "FOR.FIL";
    o__1.orl = 500000;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    s_rsfe(&io___1);
    do_fio(&fieldprp_c__1, (char *)&nn, (ftnlen)sizeof(integer));
    do_fio(&fieldprp_c__1, (char *)&i5, (ftnlen)sizeof(integer));
    do_fio(&fieldprp_c__1, (char *)&i6, (ftnlen)sizeof(integer));
    do_fio(&fieldprp_c__1, (char *)&linto, (ftnlen)sizeof(integer));
    do_fio(&fieldprp_c__1, (char *)&fieldprp_block2_1.lnver, (ftnlen)sizeof(integer));
    do_fio(&fieldprp_c__1, (char *)&fieldprp_block3_1.lnhor, (ftnlen)sizeof(integer));
    e_rsfe();
    s_rsfe(&io___6);
    do_fio(&fieldprp_c__1, (char *)&flaxi, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&eqlin, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&scale, (ftnlen)sizeof(real));
    for (i__ = 1; i__ <= 300; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&xpos[i__ - 1], (ftnlen)sizeof(real));
    }
    for (i__ = 1; i__ <= 300; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&ypos[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___13);
    for (i__ = 1; i__ <= 150; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&iln[i__ - 1], (ftnlen)sizeof(shortint));
    }
    e_rsfe();
    s_rsfe(&io___15);
    for (i__ = 1; i__ <= 3000; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&linc[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___17);
    do_fio(&fieldprp_c__80, ident, (ftnlen)1);
    e_rsfe();
    s_rsfe(&io___19);
    i__1 = linto;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&datln[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    j4 = i6 / 4;
    j2 = i6 / 2;
    j3 = j2 + j4;
    k8 = i5 / 8;
    k4 = i5 / 4;
    k2 = i5 / 2;
    k3 = k4 + k8;
/* --- NODE COORDINATES IN MILLIMETERS */
    s_rsfe(&io___28);
    i__1 = j4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___30);
    i__1 = j2;
    for (i__ = j4 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___31);
    i__1 = j3;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___32);
    i__1 = i6;
    for (i__ = j3 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___33);
    i__1 = j4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ + 59999], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___34);
    i__1 = j2;
    for (i__ = j4 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ + 59999], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___35);
    i__1 = j3;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ + 59999], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___36);
    i__1 = i6;
    for (i__ = j3 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ + 59999], (ftnlen)sizeof(real));
    }
    e_rsfe();
/* --- NODE POTENTIALS */
    s_rsfe(&io___37);
    i__1 = j4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ + 119999], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___38);
    i__1 = j2;
    for (i__ = j4 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ + 119999], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___39);
    i__1 = j3;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ + 119999], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___40);
    i__1 = i6;
    for (i__ = j3 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&vert[i__ + 119999], (ftnlen)sizeof(real));
    }
    e_rsfe();
/* --- INFORMATION ABOUT THE GRID, STORED IN INDIVIDUAL BITS */
    s_rsfe(&io___41);
    i__1 = j2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&fieldprp_block1_1.ibit[i__ - 1], (ftnlen)sizeof(integer)
		);
    }
    e_rsfe();
    s_rsfe(&io___42);
    i__1 = i6;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&fieldprp_block1_1.ibit[i__ - 1], (ftnlen)sizeof(integer)
		);
    }
    e_rsfe();
/* --- PERMITTIVITIES IN TRIANGLES */
    s_rsfe(&io___43);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&tri[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___45);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&tri[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___46);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&tri[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___47);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&tri[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___48);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&tri[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___49);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&tri[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___50);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&tri[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___51);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&tri[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    cl__1.cerr = 0;
    cl__1.cunit = 4;
    cl__1.csta = 0;
    f_clos(&cl__1);
/* --- CHANGE A TO A*R FOR AXI-SYMMETRIC MAGNETIC FIELDS */
    if (nn == 1 || flaxi != 2.f) {
	goto L142;
    }
    i__1 = i6;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L141: */
	vert[i__ + 119999] *= vert[i__ - 1];
    }
/* --- MIN. AND MAX. POTENTIAL */
L142:
    percv = 0.f;
    ptcmn = 9.9e9f;
    ptcmx = -9.9e9f;
    i__1 = i6;
    for (i__ = 1; i__ <= i__1; ++i__) {
	vi = vert[i__ + 119999];
	if (vi < ptcmn) {
	    ptcmn = vi;
	}
	if (vi > ptcmx) {
	    ptcmx = vi;
	}
/* L143: */
    }
    if (eqlin > .5f && ptcmn != ptcmx) {
	percv = 100.f / (eqlin + 1.f);
    }
/* --- SECTION BOUNDARIES */
    e1 = xpos[0];
    e2 = xpos[fieldprp_block2_1.lnver - 1];
    e3 = ypos[0];
    e4 = ypos[fieldprp_block3_1.lnhor - 1];
    if (flaxi != 0.f) {
	goto L145;
    }
    xctr = e4;
    yshft = 0.f;
    if (e2 > 3141.5927f && e2 < 4712.389f) {
	yshft = -e4 * sin(e2 * .001f);
    }
    if (e2 >= 4712.389f) {
	yshft = e4;
    }
    e1 = 9.9e9f;
    e2 = -9.9e9f;
    e3 = 9.9e9f;
    e4 = -9.9e9f;
    i__1 = i6;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x1 = vert[i__ - 1];
	y1 = vert[i__ + 59999];
	if (x1 < e1) {
	    e1 = x1;
	}
	if (x1 > e2) {
	    e2 = x1;
	}
	if (y1 < e3) {
	    e3 = y1;
	}
	if (y1 > e4) {
	    e4 = y1;
	}
/* L144: */
    }
    xpos[0] = e1;
    xpos[fieldprp_block2_1.lnver - 1] = e2;
    ypos[0] = e3;
    ypos[fieldprp_block3_1.lnhor - 1] = e4;
L145:
    xmax = e2 - e1;
    ymax = e4 - e3;
    points = 5;
    color = 1;
    i__ = 1;
    if (flaxi == 0.f) {
	i__ = 0;
    }
/* --- WRITE TO FILE BAS.FIL */
    s_wsfe(&io___68);
    do_fio(&fieldprp_c__80, ident, (ftnlen)1);
    e_wsfe();
    s_wsfe(&io___69);
    do_fio(&fieldprp_c__1, (char *)&nn, (ftnlen)sizeof(integer));
    do_fio(&fieldprp_c__1, (char *)&i__, (ftnlen)sizeof(integer));
    do_fio(&fieldprp_c__1, (char *)&fieldprp_block2_1.lnver, (ftnlen)sizeof(integer));
    do_fio(&fieldprp_c__1, (char *)&fieldprp_block3_1.lnhor, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___70);
    do_fio(&fieldprp_c__1, (char *)&scale, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&percv, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&xmax, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&ymax, (ftnlen)sizeof(real));
    i__1 = fieldprp_block2_1.lnver;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&xpos[i__ - 1], (ftnlen)sizeof(real));
    }
    i__2 = fieldprp_block3_1.lnhor;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_fio(&fieldprp_c__1, (char *)&ypos[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
/* --- CHANGE COORDINATES */
    i__1 = i6;
    for (i__ = 1; i__ <= i__1; ++i__) {
	xi = vert[i__ - 1];
	yi = vert[i__ + 59999];
	vert[i__ - 1] = xi - e1;
/* L146: */
	vert[i__ + 59999] = yi - e3;
    }
    if (flaxi != 0.f) {
	goto L149;
    }
    i__1 = fieldprp_block2_1.lnver;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = i6 - fieldprp_block2_1.lnver + i__;
	xy[(i__ << 1) - 2] = vert[j - 1];
/* L147: */
	xy[(i__ << 1) - 1] = vert[j + 59999];
    }
    i__1 = fieldprp_block2_1.lnver;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = fieldprp_block2_1.lnver + 1 - i__;
	xy[((fieldprp_block2_1.lnver + i__) << 1) - 2] = vert[j - 1];
/* L148: */
	xy[((fieldprp_block2_1.lnver + i__) << 1) - 1] = vert[j + 59999];
    }
    n = (fieldprp_block2_1.lnver << 1) + 1;
    xy[(n << 1) - 2] = xy[0];
    xy[(n << 1) - 1] = xy[1];
    s_wsfe(&io___76);
    do_fio(&fieldprp_c__1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&fieldprp_c__1, (char *)&color, (ftnlen)sizeof(shortint));
    e_wsfe();
    if (n > 300) {
	goto L1481;
    }
    s_wsfe(&io___77);
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 2], (ftnlen)sizeof(real));
    }
    i__2 = n;
    for (j = 1; j <= i__2; ++j) {
	do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    goto L150;
L1481:
    if (n > 600) {
	goto L1482;
    }
    s_wsfe(&io___78);
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 2], (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___79);
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    goto L150;
L1482:
    s_wsfe(&io___80);
    i__1 = n / 2;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 2], (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___81);
    i__1 = n;
    for (j = n / 2 + 1; j <= i__1; ++j) {
	do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 2], (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___82);
    i__1 = n / 2;
    for (j = 1; j <= i__1; ++j) {
	do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    s_wsfe(&io___83);
    i__1 = n;
    for (j = n / 2 + 1; j <= i__1; ++j) {
	do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    goto L150;
L149:
    s_wsfe(&io___84);
    do_fio(&fieldprp_c__1, (char *)&points, (ftnlen)sizeof(shortint));
    do_fio(&fieldprp_c__1, (char *)&color, (ftnlen)sizeof(shortint));
    e_wsfe();
    s_wsfe(&io___85);
    do_fio(&fieldprp_c__1, (char *)&fieldprp_c_b125, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&xmax, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&xmax, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&fieldprp_c_b125, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&fieldprp_c_b125, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&fieldprp_c_b125, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&fieldprp_c_b125, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&ymax, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&ymax, (ftnlen)sizeof(real));
    do_fio(&fieldprp_c__1, (char *)&fieldprp_c_b125, (ftnlen)sizeof(real));
    e_wsfe();
/* --- ELECTRODES AND DIELECTRIC MATERIALS */
L150:
    for (k = 1; k <= 3; ++k) {
	if (k == 1) {
	    typln = 1.f;
	}
	if (k == 1) {
	    color = 1;
	}
	if (k == 2) {
	    typln = 0.f;
	}
	if (k == 2) {
	    color = 2;
	}
	if (k == 3) {
	    typln = 2.f;
	}
	if (k == 3) {
	    color = 3;
	}
	i__1 = linto;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    lpnt = 0;
	    if (i__ > 1) {
		lpnt = iln[i__ - 2];
	    }
	    n = iln[i__ - 1] - lpnt;
	    if (datln[i__ - 1] > 2.f) {
		datln[i__ - 1] = 0.f;
	    }
	    if (typln != datln[i__ - 1] || n <= 1) {
		goto L242;
	    }
	    points = 0;
	    i__2 = n;
	    for (j = 1; j <= i__2; ++j) {
		n1 = (lpnt + j) << 1;
		points = (shortint) (points + 1);
		xy[(points << 1) - 2] = linc[n1 - 2] - e1;
		xy[(points << 1) - 1] = linc[n1 - 1] - e3;
		if (flaxi != 0.f) {
		    goto L241;
		}
		alpha1 = linc[n1 - 2] * .001f;
		xy[(points << 1) - 2] = xctr - linc[n1 - 1] * cos(alpha1);
		xy[(points << 1) - 1] = linc[n1 - 1] * sin(alpha1) + yshft;
		if (j == n) {
		    goto L241;
		}
		dalpha = (linc[n1] - linc[n1 - 2]) * .001f;
		if (dabs(dalpha) <= .02f) {
		    goto L241;
		}
		n2 = (integer) (dabs(dalpha) * 50.f) + 1;
		aalpha = dalpha / (real) n2;
		alpha = alpha1;
		i__3 = n2 - 1;
		for (n3 = 1; n3 <= i__3; ++n3) {
		    alpha += aalpha;
		    points = (shortint) (points + 1);
		    rad = linc[n1 - 1] + (linc[n1 + 1] - linc[n1 - 1]) * (
			    alpha - alpha1) / dalpha;
		    xy[(points << 1) - 2] = xctr - rad * cos(alpha);
/* L151: */
		    xy[(points << 1) - 1] = rad * sin(alpha) + yshft;
		}
L241:
		;
	    }
	    s_wsfe(&io___97);
	    do_fio(&fieldprp_c__1, (char *)&points, (ftnlen)sizeof(shortint));
	    do_fio(&fieldprp_c__1, (char *)&color, (ftnlen)sizeof(shortint));
	    e_wsfe();
	    if (points > 300) {
		goto L2411;
	    }
	    s_wsfe(&io___98);
	    i__2 = points;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 2], (ftnlen)sizeof(real))
			;
	    }
	    i__3 = points;
	    for (j = 1; j <= i__3; ++j) {
		do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 1], (ftnlen)sizeof(real))
			;
	    }
	    e_wsfe();
	    goto L242;
L2411:
	    if (points > 600) {
		goto L2412;
	    }
	    s_wsfe(&io___99);
	    i__2 = points;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 2], (ftnlen)sizeof(real))
			;
	    }
	    e_wsfe();
	    s_wsfe(&io___100);
	    i__2 = points;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 1], (ftnlen)sizeof(real))
			;
	    }
	    e_wsfe();
	    goto L242;
L2412:
	    s_wsfe(&io___101);
	    i__2 = points / 2;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 2], (ftnlen)sizeof(real))
			;
	    }
	    e_wsfe();
	    s_wsfe(&io___102);
	    i__2 = points;
	    for (j = points / 2 + 1; j <= i__2; ++j) {
		do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 2], (ftnlen)sizeof(real))
			;
	    }
	    e_wsfe();
	    s_wsfe(&io___103);
	    i__2 = points / 2;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 1], (ftnlen)sizeof(real))
			;
	    }
	    e_wsfe();
	    s_wsfe(&io___104);
	    i__2 = points;
	    for (j = points / 2 + 1; j <= i__2; ++j) {
		do_fio(&fieldprp_c__1, (char *)&xy[(j << 1) - 1], (ftnlen)sizeof(real))
			;
	    }
	    e_wsfe();
L242:
	    ;
	}
/* L243: */
    }
/* --- EQUIPOTENTIAL LINES */
    color = 4;
    nline = eqlin;
    if (nline < 1) {
	goto L611;
    }
    xend = 0.f;
    yend = 0.f;
    if (ptcmn == ptcmx) {
	goto L611;
    }
    e1 = (eqlin + 1.f) / (ptcmx - ptcmn);
    i__1 = i6;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L602: */
	vert[i__ + 119999] = e1 * (vert[i__ + 119999] - ptcmn);
    }
    for (n1 = nline; n1 >= 1; --n1) {
	j = 0;
	e1 = (real) n1;
	i__1 = i5;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (tri[i__ - 1] < .001f) {
		goto L609;
	    }
	    i10 = 0;
	    i1 = fieldprp_itri_(&i__, &fieldprp_c__1);
	    i2 = fieldprp_itri_(&i__, &fieldprp_c__2);
	    i3 = fieldprp_itri_(&i__, &fieldprp_c__3);
	    k = i1;
	    l = i2;
	    m = 1;
L603:
	    vk = vert[k + 119999];
	    vl = vert[l + 119999];
	    if (vk > vl) {
		goto L604;
	    }
	    imin = k;
	    imax = l;
	    ptcmn = vk;
	    ptcmx = vl;
	    goto L605;
L604:
	    imin = l;
	    imax = k;
	    ptcmn = vl;
	    ptcmx = vk;
L605:
	    if (e1 < ptcmn || e1 > ptcmx) {
		goto L607;
	    }
	    e2 = 0.f;
	    if (ptcmn < ptcmx) {
		e2 = (e1 - ptcmn) / (ptcmx - ptcmn);
	    }
	    if (i10 == 0) {
		++j;
	    }
	    for (i11 = 1; i11 <= 2; ++i11) {
		k1 = i10 + i11;
		v11 = vert[imin + i11 * 60000 - 60001];
/* L606: */
		segm[j + k1 * 4000 - 4001] = v11 + e2 * (vert[imax + i11 * 
			60000 - 60001] - v11);
	    }
	    segm[j + 15999] = 0.f;
	    i10 = 2;
L607:
	    if (m >= 2) {
		goto L608;
	    }
	    k = i2;
	    l = i3;
	    m = 2;
	    goto L603;
L608:
	    if (m == 3) {
		goto L609;
	    }
	    k = i3;
	    l = i1;
	    m = 3;
	    goto L603;
L609:
	    ;
	}
	if (j == 0) {
	    goto L610;
	}
L700:
	inv = 0;
/* --- FIRST LINE SEGMENT INTO ARRAY XY */
	for (i__ = 1; i__ <= 2; ++i__) {
	    xy[(i__ << 1) - 2] = segm[((i__ << 1) - 1) * 4000 - 4000];
/* L701: */
	    xy[(i__ << 1) - 1] = segm[i__ * 8000 - 4000];
	}
	n = 2;
	if (j == 1) {
	    goto L708;
	}
/* --- LOOK FOR CONNECTING LINE SEGMENT */
L702:
	i__1 = j;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    if (segm[i__ + 15999] > .5f) {
		goto L706;
	    }
	    if ((r__1 = xy[(n << 1) - 2] - segm[i__ - 1], dabs(r__1)) < 1e-4f 
		    && (r__2 = xy[(n << 1) - 1] - segm[i__ + 3999], dabs(r__2)
		    ) < 1e-4f) {
		goto L703;
	    }
	    if ((r__1 = xy[(n << 1) - 2] - segm[i__ + 7999], dabs(r__1)) < 
		    1e-4f && (r__2 = xy[(n << 1) - 1] - segm[i__ + 11999], 
		    dabs(r__2)) < 1e-4f) {
		goto L704;
	    }
	    goto L706;
L703:
	    ++n;
	    xy[(n << 1) - 2] = segm[i__ + 7999];
	    xy[(n << 1) - 1] = segm[i__ + 11999];
	    segm[i__ + 15999] = 1.f;
	    goto L705;
L704:
	    ++n;
	    xy[(n << 1) - 2] = segm[i__ - 1];
	    xy[(n << 1) - 1] = segm[i__ + 3999];
	    segm[i__ + 15999] = 1.f;
L705:
	    if (n <= j) {
		goto L702;
	    }
	    goto L708;
L706:
	    ;
	}
/* --- INVERT LINE AND TRY AGAIN */
	if (inv == 1) {
	    goto L708;
	}
	iexit = 1;
	goto L714;
L712:
	inv = 1;
	goto L702;
/* --- DRAW LINE */
L708:
	inv = 0;
	iexit = 2;
/* Computing 2nd power */
	r__1 = xy[0] - xend;
/* Computing 2nd power */
	r__2 = xy[1] - yend;
/* Computing 2nd power */
	r__3 = xy[(n << 1) - 2] - xend;
/* Computing 2nd power */
	r__4 = xy[(n << 1) - 1] - yend;
	if (r__1 * r__1 + r__2 * r__2 > r__3 * r__3 + r__4 * r__4) {
	    goto L714;
	}
L713:
	xend = xy[(n << 1) - 2];
	yend = xy[(n << 1) - 1];
/* --- WRITE TO FILE BAS.FIL */
	s_wsfe(&io___124);
	do_fio(&fieldprp_c__1, (char *)&n, (ftnlen)sizeof(integer));
	do_fio(&fieldprp_c__1, (char *)&color, (ftnlen)sizeof(shortint));
	e_wsfe();
	if (n > 285) {
	    goto L7131;
	}
	s_wsfe(&io___125);
	i__1 = n;
	for (j1 = 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 2], (ftnlen)sizeof(real));
	}
	i__2 = n;
	for (j1 = 1; j1 <= i__2; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
	goto L7134;
L7131:
	if (n > 570) {
	    goto L7132;
	}
	s_wsfe(&io___127);
	i__1 = n;
	for (j1 = 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 2], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___128);
	i__1 = n;
	for (j1 = 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
	goto L7134;
L7132:
	if (n > 1140) {
	    goto L7133;
	}
	s_wsfe(&io___129);
	i__1 = n / 2;
	for (j1 = 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 2], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___130);
	i__1 = n;
	for (j1 = n / 2 + 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 2], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___131);
	i__1 = n / 2;
	for (j1 = 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___132);
	i__1 = n;
	for (j1 = n / 2 + 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
	goto L7134;
L7133:
	s_wsfe(&io___133);
	i__1 = n / 4;
	for (j1 = 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 2], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___134);
	i__1 = n / 2;
	for (j1 = n / 4 + 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 2], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___135);
	i__1 = n * 3 / 4;
	for (j1 = n / 2 + 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 2], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___136);
	i__1 = n;
	for (j1 = n * 3 / 4 + 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 2], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___137);
	i__1 = n / 4;
	for (j1 = 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___138);
	i__1 = n / 2;
	for (j1 = n / 4 + 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___139);
	i__1 = n * 3 / 4;
	for (j1 = n / 2 + 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
	s_wsfe(&io___140);
	i__1 = n;
	for (j1 = n * 3 / 4 + 1; j1 <= i__1; ++j1) {
	    do_fio(&fieldprp_c__1, (char *)&xy[(j1 << 1) - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
L7134:
	if (j >= 2) {
	    goto L709;
	}
	goto L610;
/* --- REMAINING LINE SEGMENTS */
L709:
	m = 0;
	i__1 = j;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    if (segm[i__ + 15999] > .5f) {
		goto L711;
	    }
	    ++m;
	    for (k = 1; k <= 5; ++k) {
/* L710: */
		segm[m + k * 4000 - 4001] = segm[i__ + k * 4000 - 4001];
	    }
L711:
	    ;
	}
	j = m;
	if (j >= 1) {
	    goto L700;
	}
	goto L610;
/* --- INVERT LINE */
L714:
	m = n / 2;
	i__1 = m;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    e1 = xy[(i__ << 1) - 2];
	    e2 = xy[(i__ << 1) - 1];
	    k = n - i__ + 1;
	    xy[(i__ << 1) - 2] = xy[(k << 1) - 2];
	    xy[(i__ << 1) - 1] = xy[(k << 1) - 1];
	    xy[(k << 1) - 2] = e1;
/* L707: */
	    xy[(k << 1) - 1] = e2;
	}
	switch (iexit) {
	    case 1:  goto L712;
	    case 2:  goto L713;
	}
L610:
	;
    }
L611:
    points = 0;
    color = 0;
    s_wsfe(&io___141);
    do_fio(&fieldprp_c__1, (char *)&points, (ftnlen)sizeof(shortint));
    do_fio(&fieldprp_c__1, (char *)&color, (ftnlen)sizeof(shortint));
    e_wsfe();
/* --- CLOSE FILES */
    cl__1.cerr = 0;
    cl__1.cunit = 3;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
} /* MAIN__ */

integer fieldprp_itri_(integer *i__, integer *j)
{
    /* System generated locals */
    integer ret_val = 0;

    /* Local variables */
    static logical1 a;
    static integer l, m, n;

/* --- RECREATES VALUES IN THE OLD ARRAY ITRI */
/* --- ROW NUMBER */
    m = (*i__ - 1) / ((fieldprp_block2_1.lnver - 1) << 1) + 1;
/* --- COLUMN NUMBER */
    n = (*i__ - 1) / 2 + fieldprp_block2_1.lnver - m * (fieldprp_block2_1.lnver - 1);
/* --- LOWER LEFT CORNER */
    l = n + (m - 1) * fieldprp_block2_1.lnver;
    a = bit_test(fieldprp_block1_1.ibit[l - 1],15);
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
	ret_val = l + fieldprp_block2_1.lnver + 1;
    }
    if (*j == 3) {
	ret_val = l + fieldprp_block2_1.lnver;
    }
    goto L200;
/* --- SECOND TRIANGLE */
L110:
    if (*j == 2) {
	ret_val = l + 1;
    }
    if (*j == 3) {
	ret_val = l + fieldprp_block2_1.lnver + 1;
    }
    goto L200;
/* --- REVERSED DIAGONAL */
L120:
    if (*j == 1) {
	ret_val = l + fieldprp_block2_1.lnver;
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
} /* fieldprp_itri_ */

integer fieldprp_novx2_(integer *i__, integer *lnhor, integer *lnver)
{
    /* System generated locals */
    integer ret_val;

    /* Local variables */
    static integer k5, m5;

/* --- CONVERSION FROM VERTEX NUMBER IN ARRAY VERT TO THAT OF COEFF */
    if (*lnver <= *lnhor) {
	goto L91;
    }
    m5 = (*i__ - 1) / *lnver + 1;
    k5 = *i__ - (m5 - 1) * *lnver;
    ret_val = k5 * *lnhor - m5 + 1;
    return ret_val;
L91:
    ret_val = *i__;
    return ret_val;
} /* fieldprp_novx2_ */

