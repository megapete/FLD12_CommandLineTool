/* OUTMET.F -- translated by f2c (version 20100827).
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

struct {
    integer lnver, ibit[30000];
} outmet_block1_;

#define outmet_block1_1 outmet_block1_

/* Table of constant values */

static integer outmet_c__80 = 80;
static integer outmet_c__1 = 1;
static integer outmet_c__2 = 2;
static integer outmet_c__3 = 3;
static real outmet_c_b360 = 1.f;

/* --- OUTPUT PROGRAM FLD12 */

/* Main program */ int __stdcall OUTMETMAIN__(char *baseDirectory)
{
	memset(&outmet_block1_1, 0, sizeof(outmet_block1_1));

	outmet_c__80 = 80;
	outmet_c__1 = 1;
	outmet_c__2 = 2;
	outmet_c__3 = 3;
	outmet_c_b360 = 1.f;

    /* Initialized data */

    static char strng[4*12] = " I  " " Y  " " D  " "AUTO" " ZN " " ZT " " P1 "
	     " P2 " "EDM " "EDT " "CU  " "AL  ";

    /* Format strings */
    static char fmt_1[] = "(8f10.0/7f10.0/7f10.0)";
    static char fmt_2[] = "(4f10.0)";
    static char fmt_3[] = "(4f10.0/6f10.0)";
    static char fmt_4[] = "(5f10.0/4f10.0)";
    static char fmt_6[] = "(80a1)";
    static char fmt_10[] = "(\002PROGRAM FLD12\002,7x,\002COMPLEX POTENTIAL "
	    "TRANSFORMER LEAKAGE FLUX\002//80a1///\002NUMBER OF PHASES\002,f4"
	    ".1,20x,\002SYSTEM SHORT CIRCUIT GVA\002,f8.3/\002FREQUENCY\002,f"
	    "7.2,24x,\002OPTIONAL PU IMPEDANCE\002,f7.4/\002NUMBER OF WOUND L"
	    "IMBS\002,f4.1,15x,\002PEAK FACTOR\002,f6.3/\002FRACTION OF WINDO"
	    "W HEIGHT CALC.\002,f4.1,5x,\002LOSS FACTORS\002/\002Z - LOWER BO"
	    "UNDARY\002,f8.1,16x,\002TANK\002,f7.2/\002Z - UPPER BOUNDARY\002"
	    ",f8.1,16x,\002LEG\002,f8.2/\002CORE DIAMETER\002,f7.1,22x,\002YO"
	    "KE\002,f7.2/\002DISTANCE WINDING-TANK\002,f7.1,12x,\002SCALE, FL"
	    "UX PLOT\002,f6.3/\002AL/CU SHIELD\002,f4.1,24x,\002NO. OF FLUX L"
	    "INES\002,f5.1//)";
    static char fmt_12[] = "(\002TERMINAL NUMBER\002,f6.1,5f10.1)";
    static char fmt_13[] = "(\002CONNECTION\002,8x,6(a4,6x))";
    static char fmt_14[] = "(\002MVA\002,f20.3,5f10.3)";
    static char fmt_15[] = "(\002KV\002,f21.3,5f10.3)";
    static char fmt_16[] = "(/\002LAYER   LAST    INNER   RADIAL   TERM.   P"
	    "AR.     DIR.   CU/AL   SPACER BLOCKS\002/\002NO.     SEGM.   RAD"
	    ".    WIDTH    NO. \r   GROUPS   CUR.\002,11x,\002NUMBER  WIDT"
	    "H\002)";
    static char fmt_17[] = "(f4.1,f8.1,f9.1,3f8.1,f9.1,4x,a2,f10.1,f8.1)";
    static char fmt_18[] = "(/\002SEGM.  LAYER  Z-COORDINATE   NO. OF TURNS "
	    "  NUMBER OF STRANDS   STRAND DIMENS.\002/\002NO.    NO.    MIN. "
	    "   MAX.   TOTAL  ACTIVE  PER TURN  RADIALLY  RAD.   AXIALLY\002)";
    static char fmt_19[] = "(f5.1,f6.1,f8.1,f8.1,2f7.1,f9.1,f10.1,f9.2,f8.2)";
    static char fmt_26[] = "(/\002RADIAL POSITIONS, VERTICAL GRID LINES\002)";
    static char fmt_27[] = "(/\002AXIAL POSITIONS, HORIZONTAL GRID LINES\002)"
	    ;
    static char fmt_28[] = "(i3,5x,10f7.1)";
    static char fmt_29[] = "(i3,\002-\002,i2,2x,10f7.1)";
    static char fmt_30[] = "(i3,\002-\002,i3,1x,10f7.1)";
    static char fmt_31[] = "(//\002'MIN. NUMBER OF SPACER BARS' IS TWICE THE"
	    " THEORETICAL MINIMUM CALCULATED FROM\002/\002TIMOSHENKO'S BUCKLI"
	    "NG FORMULA FOR COLUMNS WITH BUILT-IN ENDS, EQUATION 146.\002/"
	    "\002THIS IS THE RECOMMENDED MINIMUM NUMBER. IF THE WINDING IS MA"
	    "DE OF BONDED CTC,\002/\002THE NUMBER IS CALCULATED TOO HIGH, SIN"
	    "CE NO BONDING IS ASSUMED\rIN THE \002/\002CALCULATIONS.\002//"
	    "\002THE COMPRESSIVE STRESS IN THE SPACER BLOCKS IS CALCULATED DU"
	    "E TO ACCUMULATED\002/\002AXIAL FORCES WITHIN AND OUTSIDE OF THE "
	    "WINDING SEGMENT. IF THERE ARE NO\002/\002SPACERS, THE COMPRESSIV"
	    "E STRESS IN THE INSULATION IS CALCULATED IN THE SAME\002/\002WAY"
	    ". IN BOTH CASES, THE PROGRAM ASSUMES A RADIAL LENGTH OF CONTACT "
	    "EQUAL TO\002/\002THE SUM OF THE RADIAL STRAND DIMENSIONS.\002/)";
    static char fmt_32[] = "(\002STRESSES DUE TO COMBINED FORCES ARE BENDING"
	    " STRESSES DUE TO 'MAX. N/CUB.DM,\002/\002AXIALLY' COMBINED WITH "
	    "TENSION OR COMPRESSION DUE TO 'MIN. N/AXIAL MM,\002/\002RADIALLY"
	    "'. BENDING STRESS IS CALCULATED FOR A BUILT-IN BEAM WITH A LENGTH"
	    "\002/\002EQUAL TO THE AVERAGE SPACER PITCH MINUS HALF THE SPACER"
	    " WIDTH. IT IS CALCULATED\002/\002TOO HIGH FOR BONDED CTC, AGAIN "
	    "BECAUSE NO BONDING IS ASSUMED IN THE\002/\002CALCULATIONS.\002/)";
    static char fmt_33[] = "(/\002SEGMENT NUMBER\002,f6.1/\002  AMPERETURN"
	    "S\002,f11.1,12x,\002FORCES AT PEAK SHORT CIRCUIT CURRENT\002/"
	    "\002  KVA\002,f10.2,23x,\002TOTAL RADIALLY, NEWTON\002,f12.1/"
	    "\002DC LOSS\002,31x,\002TOTAL AXIALLY, NEWTON\002,f13.1/\002  KW"
	    "/CUB.DM GROSS VOLUME\002,f7.4,7x,\002MIN. N/AXIAL MM, RADIALL"
	    "Y\002,f9.1/\002  KW TOTAL\002,f8.3,20x,\002MAX. N/AXIAL MM, RADI"
	    "ALLY\002,f9.1/\002EDDY CURRENT LOSS\002,21x,\002MAX. ACCUM. AXIA"
	    "LLY, NEWTON\002,f12.1/\002  KW DUE TO AXIAL FLUX\002,f8.3,8x,"
	    "\002MAX. N/CUB.CM, AXIALLY\002,f8.2/\002  KW DUE TO RADIAL FLU"
	    "X\002,f7.3,6x,\002DUE TO RADIAL FORCES\002/\002  KW TOTAL\002,f7"
	    ".3,21x,\002N/SQ.MM TENSION/COMPRESSION\002,f8.2/\002  PER UNIT, "
	    "AVERAGE\002,f8.4,11x,\002MIN. NUMBER OF SPACER BARS\002,f5.1)";
    static char fmt_34[] = "(\002  PER UNIT, MAXIMUM\002,f8.4,9x,\002DUE TO "
	    "AXIAL FORCES\002)";
    static char fmt_35[] = "(\002MAX. PU CURRENT DENSITY\002,f7.4,6x,\002DUE"
	    " TO AXIAL FORCES\002)";
    static char fmt_36[] = "(\002  OCCURS BETWEEN\002,22x,\002N/SQ.MM IN SPA"
	    "CER BLOCKS\002,f7.2)";
    static char fmt_37[] = "(\002  OCCURS BETWEEN\002,22x,\002N/SQ.MM IN INS"
	    "ULATION\002,f7.2)";
    static char fmt_38[] = "(\002 R-MIN   R-MAX   Z-MIN   Z-MAX\002,6x,\002D"
	    "UE TO COMBINED FORCES\002/f6.1,3f8.1,8x,\002N/SQ.MM BENDING+TENS"
	    "./COMPR.\002,f8.2)";
    static char fmt_39[] = "(//\002CRITICAL STRESSES ETC. AT PEAK SHORT CIRC"
	    "UIT CURRENT:\002/\002DUE TO RADIAL FORCES\002,28x,\002SEGMENT NO."
	    "\002/\002  N/SQ.MM TENSION\002,f12.2,f26.1/\002  N/SQ.MM COMPRES"
	    "SION\002,f8.2,f26.1/\002  MIN. NUMBER OF SPACER BARS\002,f5.1,f2"
	    "2.1/\002DUE TO AXIAL FORCES\002/\002  N/SQ.MM IN SPACER BLOCKS O"
	    "R INSULATION\002,f7.2,f8.1/\002DUE TO COMBINED FORCES\002/\002  "
	    "N/SQ.MM BENDING+TENS./COMPR.\002,f8.2,f17.1)";
    static char fmt_41[] = "(/\002VOLTS PER TURN\002,f8.3/\002MAX. RADIAL FL"
	    "UX DENSITY AT TANK (PEAK, TESLA)\002,f7.4/\002MAX. RADIAL FLUX D"
	    "ENSITY AT CORE LEG\002,f7.4)";
    static char fmt_42[] = "(\002BASED ON MAGNETIC ENERGY AND TOTAL LOSSES, "
	    "WITH BASE MVA\002,f8.3/\002PU TRANSFORMER SHORT CIRCUIT REACTANCE"
	    "\002,f11.7/29x,\002RESISTANCE\002,f7.4/29x,\002IMPEDANCE\002,f8."
	    "4/\002PU SYSTEM IMPEDANCE\002,f7.4/\002PU TOTAL IMPEDANCE\002,f8"
	    ".4/\002PU IMPEDANCE USED IN CALCULATIONS OF FORCES AND STRESSE"
	    "S\002,f7.4//\002FOR THE WHOLE TRANSFORMER\002/\002EDDY CURRENT L"
	    "OSS\002/\002  KW WINDINGS\002,f8.3/\002  KW TANK\002,f12.3/\002 "
	    " KW LEG\002,f13.3/\002  KW YOKE\002,f12.3/\002  KW TOTAL\002,f11"
	    ".3/\002  PER UNIT, TOTAL\002,f7.4/\002DC LOSS, KW TOTAL\002,f9.3"
	    "//)";
    static char fmt_43[] = "(\002LOSSES REFERRED TO LAYERS ARE FOR ONE LIMB,"
	    " REFERRED TO\rTERMINALS FOR THE\002/\002WHOLE TRANSFORMER.\002/)";
    static char fmt_44[] = "(\002  FORCES AT PEAK SHORT CIRCUIT CURRENT, NEW"
	    "TON\002/\002   MAX. ACCUMULATED AXIALLY\002,f10.1/\002   OCCURS "
	    "IN SEGMENT NO.\002,i4)";
    static char fmt_45[] = "(/\002LAYER NUMBER\002,i3)";
    static char fmt_46[] = "(\002  DC LOSS, KW\002,f9.3/\002  EDDY CURRENT L"
	    "OSS, KW\002,f8.3/21x,\002PER UNIT\002,f7.4)";
    static char fmt_47[] = "(\002   ON UPPER SUPPORT\002,f10.1)";
    static char fmt_48[] = "(\002   ON LOWER SUPPORT\002,f10.1)";
    static char fmt_49[] = "(\002  FLUX LINKAGE, REFERRED TO ONE TURN\002,f1"
	    "2.8)";
    static char fmt_50[] = "(/\002TERMINAL NUMBER\002,i2)";
    static char fmt_51[] = "(\002  PERCENT DEVIATION, VOLTS/TURN\002,f7.3)";
    static char fmt_52[] = "(//\002TOTAL SHORT CIRCUIT FORCE FROM ALL THE LA"
	    "YERS, UPPER SUPPORT\002,f10.1)";
    static char fmt_53[] = "(47x,\002LOWER SUPPORT\002,f10.1)";
    static char fmt_64[] = "(\002   DC LOSS, KW\002,f9.3/\002  EDDY CURRENT "
	    "LOSS\002/\002   KW DUE TO AXIAL FLUX\002,f9.3/\002   KW DUE TO R"
	    "ADIAL FLUX\002,f8.3/\002   KW TOTAL\002,f8.3/\002   PER UNIT, AV"
	    "ERAGE\002,f8.4)";
    static char fmt_65[] = "(\002   PER UNIT, MAXIMUM\002,f8.4/\002   OCCURS"
	    " BETWEEN\002/\002  R-MIN   R-MAX   Z-MIN   Z-MAX\002/\002 \002,f"
	    "6.1,3f8.1)";
    static char fmt_66[] = "(\002  MAX. PU CURRENT DENSITY\002,f7.4/\002   O"
	    "CCURS BETWEEN\002/\002  R-MIN   R-MAX   Z-MIN   Z-MAX\002/\002"
	    " \002,f6.1,3f8.1)";
    static char fmt_76[] = "(/\002THE AMPERETURNS ARE NOT BALANCED\002)";
    static char fmt_81[] = "(30000e14.7)";
    static char fmt_82[] = "(30000i14)";
    static char fmt_98[] = "(\002The deviation in volts per turn is too high"
	    " for terminal\002,i2)";
    static char fmt_99[] = "(40(f14.4))";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    real r__1, r__2, r__3;
    complex q__1, q__2, q__3, q__4, q__5, q__6, q__7, q__8, q__9;
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer f_open(olist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(void), f_clos(cllist *), s_wsfe(cilist *), e_wsfe(
	    void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal), atan(doublereal), cos(doublereal), c_abs(complex 
	    *), r_imag(complex *);
    integer s_wsue(cilist *), do_uio(integer *, char *, ftnlen), e_wsue(void);

    /* Local variables */
    static real d__;
	d__ = 0.0;
    static integer i__, j, k, l, m, n;
	i__ = 0;
	j = 0;
	k = 0;
	l = 0;
	m = 0;
	n = 0;
    static real e1, e2, e3, e4;
	e1 = 0.0;
	e2 = 0.0;
	e3 = 0.0;
	e4 = 0.0;
    static integer i1, j1, j2, j3, i5, i6, j4, k4, k2, k8;
	i1 = 0;
	j1 = 0;
	j2 = 0;
	j3 = 0;
	i5 = 0;
	i6 = 0;
	j4 = 0;
	k4 = 0;
	k2 = 0;
	k8 = 0;
    static char s1[4];
	memset(s1, 0, 4 * sizeof(char));
    static integer k3, i2;
	k3 = 0;
	i2 = 0;
    static real e8, e5, e6, e7, e9;
	e8 = 0.0;
	e5 = 0.0;
	e6 = 0.0;
	e7 = 0.0;
	e9 = 0.0;
    static integer k1;
	k1 = 0;
    static complex ac;
	complex cmplZero = { 0.0, 0.0 };
	ac = cmplZero;
    static real e10;
	e10 = 0.0;
    static complex cd;
	cd = cmplZero;
    static real e12, e13;
	e12 = 0.0;
	e13 = 0.0;
    static complex bh;
	bh = cmplZero;
    static real e11, e14;
	e11 = 0.0;
	e14 = 0.0;
    static complex al, am, an;
	al = am = an = cmplZero;
    static real e15, e16, rc, fr, pi;
	e15 = e16 = rc = fr = pi = 0.0;
    static complex bz;
	bz = cmplZero;
    static real zb, rl, rm, rn, zc, fz, xl, yl, zl, zm, zn, xm, ws, ym, xn, 
	    yn, zu, eal, fsc, ecu, seg[8000]	/* was [200][40] */;
	zb = rl = rm = rn = zc = fz = xl = yl = zl = zm = zn = xm = ws = ym = xn = 0.0;
	yn = zu = eal = fsc = ecu = 0.0;
	memset(seg, 0, 8000 * sizeof(real));
    static shortint iln[150];
	memset(iln, 0, 150 * sizeof(shortint));
    static real rmn, vol, zmn, rpu;
	rmn = vol = zmn = rpu = 0.0;
    static shortint out;
	out = 0;
    static real rmx, xpu, zpu, zmx, tri2[59302], sqr2, sqr3, emag, fleg, aseg,
	     edax, dpel, linc[3000], dzde, amin, shld, amax;
	rmx = xpu = zpu = zmx = sqr2 = sqr3 = emag = fleg = aseg = edax = dpel = dzde = amin = shld = amax = 0.0;
	memset(tri2, 0, 59302 * sizeof(real));
	memset(linc, 0, 3000 * sizeof(real));
    static integer nseg;
	nseg = 0;
    static real freq;
	freq = 0.0;
    extern /* Subroutine */ int outmet_subd_(real *, real *, real *, real *, real *, 
	    real *, real *);
    static real zang, crit[10]	/* was [5][2] */, edpu;
	zang = edpu = 0.0;
	memset(crit, 0, 10 * sizeof(real));
    static integer nlay;
	nlay = 0;
    static real rmin;
	rmin = 0.0;
    static shortint warn;
	warn = 0;
    static real term[54]	/* was [6][9] */;
	memset(term, 0, 54 * sizeof(real));
    extern integer outmet_itri_(integer *, integer *);
    static real sumd, vert[60000]	/* was [30000][2] */, zsmn, zkvn, 
	    xpos[300], ypos[300];
	sumd = zsmn = zkvn = 0.0;
	memset(vert, 0, 60000 * sizeof(real));
	memset(xpos, 0, 300 * sizeof(real));
	memset(ypos, 0, 300 * sizeof(real));
    static char tstr[4*6];
	memset(tstr, 0, 24 * sizeof(char));
    static real zopt, zkvt, zkvr, ztot, zsmx, cdabs, bhabs, edrad, edleg, 
	    acond, cdavg, fpeak, scale;
	zopt = zkvt = zkvr = ztot = zsmx = cdabs = bhabs = edrad = edleg = acond = cdavg = fpeak = scale = 0.0;
    extern /* Subroutine */ int outmet_angle_(real *, real *, real *, real *, real *)
	    ;
    static real feddy, dcore, brleg, fract, phase, bzabs, datln[150];
	feddy = dcore = brleg = fract = phase = bzabs = 0.0;
	memset(datln, 0, 150 * sizeof(real));
    static char ident[1*80];
	memset(ident, 0, 80 * sizeof(char));
    static real scgva, ftank, limbs, resal, flaxi;
	scgva = ftank = limbs = resal = flaxi = 0.0;
    static integer nocol;
	nocol = 0;
    static real scond, layer[300]	/* was [30][10] */, fyoke, cpoti[
	    30000], dctot, edtot, rescu, newax, permo, flxln;
	scond = fyoke = dctot = edtot = rescu = newax = permo = flxln = 0.0;
	memset(layer, 0, 300 * sizeof(real));
	memset(cpoti, 0, 30000 * sizeof(real));
    static integer nterm;
	nterm = 0;
    static real cpotr[30000], mvamx;
	memset(cpotr, 0, 30000 * sizeof(real));
	mvamx = 0.0;
    static integer linto, lnhor;
	linto = lnhor = 0;
    static real thksh;
	thksh = 0.0;
    static integer nexit;
	nexit = 0;
    static real saxmn;
	saxmn = 0.0;
    static integer klast;
	klast = 0;
    static real saxmx, wntnk, twopi, units;
	saxmx = wntnk = twopi = units = 0.0;
    static integer iexit, kexit;
	iexit = kexit = 0;
    static real edwnd, edtnk, edyok, zused, brtnk, fsupu, fsupl, vturn, flink,
	     zsyst, cdensi[59302], cdensr[59302], newrad;
	edwnd = edtnk = edyok = zused = brtnk = fsupu = fsupl = vturn = flink = zsyst = newrad = 0.0;
	memset(cdensi, 0, 59302 * sizeof(real));
	memset(cdensr, 0, 59302 * sizeof(real));

    /* Fortran I/O blocks */
    static cilist io___10 = { 0, 2, 0, fmt_6, 0 };
    static cilist io___12 = { 0, 2, 0, fmt_1, 0 };
    static cilist io___37 = { 0, 2, 0, fmt_2, 0 };
    static cilist io___41 = { 0, 2, 0, fmt_3, 0 };
    static cilist io___44 = { 0, 2, 0, fmt_4, 0 };
    static cilist io___50 = { 0, 4, 0, fmt_82, 0 };
    static cilist io___56 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___60 = { 0, 4, 0, fmt_82, 0 };
    static cilist io___62 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___64 = { 0, 4, 0, fmt_6, 0 };
    static cilist io___65 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___74 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___76 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___77 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___78 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___79 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___80 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___81 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___82 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___83 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___85 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___86 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___87 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___88 = { 0, 4, 0, fmt_82, 0 };
    static cilist io___89 = { 0, 4, 0, fmt_82, 0 };
    static cilist io___90 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___92 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___93 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___94 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___95 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___96 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___97 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___98 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___99 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___100 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___101 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___102 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___103 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___104 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___105 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___106 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___107 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___109 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___110 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___111 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___112 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___114 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___115 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___116 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___117 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___118 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___119 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___120 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___121 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___123 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___124 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___125 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___126 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___127 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___128 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___129 = { 0, 4, 0, fmt_81, 0 };
    static cilist io___130 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___132 = { 0, 0, 0, fmt_12, 0 };
    static cilist io___133 = { 0, 0, 0, fmt_13, 0 };
    static cilist io___134 = { 0, 0, 0, fmt_14, 0 };
    static cilist io___135 = { 0, 0, 0, fmt_15, 0 };
    static cilist io___136 = { 0, 0, 0, fmt_16, 0 };
    static cilist io___138 = { 0, 0, 0, fmt_17, 0 };
    static cilist io___139 = { 0, 0, 0, fmt_18, 0 };
    static cilist io___140 = { 0, 0, 0, fmt_19, 0 };
    static cilist io___141 = { 0, 0, 0, fmt_26, 0 };
    static cilist io___142 = { 0, 0, 0, fmt_28, 0 };
    static cilist io___143 = { 0, 0, 0, fmt_29, 0 };
    static cilist io___144 = { 0, 0, 0, fmt_30, 0 };
    static cilist io___145 = { 0, 0, 0, fmt_27, 0 };
    static cilist io___146 = { 0, 0, 0, fmt_28, 0 };
    static cilist io___147 = { 0, 0, 0, fmt_29, 0 };
    static cilist io___148 = { 0, 0, 0, fmt_30, 0 };
    static cilist io___153 = { 0, 0, 0, fmt_31, 0 };
    static cilist io___154 = { 0, 0, 0, fmt_32, 0 };
    static cilist io___235 = { 0, 0, 0, fmt_33, 0 };
    static cilist io___236 = { 0, 0, 0, fmt_34, 0 };
    static cilist io___237 = { 0, 0, 0, fmt_35, 0 };
    static cilist io___238 = { 0, 0, 0, fmt_36, 0 };
    static cilist io___239 = { 0, 0, 0, fmt_37, 0 };
    static cilist io___240 = { 0, 0, 0, fmt_38, 0 };
    static cilist io___241 = { 0, 0, 0, fmt_39, 0 };
    static cilist io___242 = { 0, 0, 0, fmt_41, 0 };
    static cilist io___243 = { 0, 0, 0, fmt_42, 0 };
    static cilist io___244 = { 0, 0, 0, fmt_43, 0 };
    static cilist io___256 = { 0, 0, 0, fmt_45, 0 };
    static cilist io___257 = { 0, 0, 0, fmt_64, 0 };
    static cilist io___258 = { 0, 0, 0, fmt_65, 0 };
    static cilist io___259 = { 0, 0, 0, fmt_66, 0 };
    static cilist io___260 = { 0, 0, 0, fmt_44, 0 };
    static cilist io___261 = { 0, 0, 0, fmt_47, 0 };
    static cilist io___262 = { 0, 0, 0, fmt_48, 0 };
    static cilist io___271 = { 0, 0, 0, fmt_49, 0 };
    static cilist io___272 = { 0, 0, 0, fmt_50, 0 };
    static cilist io___273 = { 0, 0, 0, fmt_46, 0 };
    static cilist io___274 = { 0, 0, 0, fmt_98, 0 };
    static cilist io___275 = { 0, 0, 0, fmt_51, 0 };
    static cilist io___276 = { 0, 0, 0, fmt_52, 0 };
    static cilist io___277 = { 0, 0, 0, fmt_53, 0 };
    static cilist io___278 = { 0, 0, 0, fmt_76, 0 };
    static cilist io___279 = { 0, 3, 0, 0, 0 };
    static cilist io___280 = { 0, 4, 0, fmt_99, 0 };


/* L1: */
/* L2: */
/* L3: */
/* L4: */
/* L5: */
/* L6: */
/* L10: */
/* L12: */
/* L13: */
/* L14: */
/* L15: */
/* L16: */
/* L17: */
/* L18: */
/* L19: */
/* L26: */
/* L27: */
/* L28: */
/* L29: */
/* L30: */
/* L31: */
/* L32: */
/* L33: */
/* L34: */
/* L35: */
/* L36: */
/* L37: */
/* L38: */
/* L39: */
/* L41: */
/* L42: */
/* L43: */
/* L44: */
/* L45: */
/* L46: */
/* L47: */
/* L48: */
/* L49: */
/* L50: */
/* L51: */
/* L52: */
/* L53: */
/* L64: */
/* L65: */
/* L66: */
/* L76: */
/* L81: */
/* L82: */
/* L98: */
/* L99: */
    pi = 3.141593f;
    twopi = pi * 2.f;
    sqr2 = 1.414214f;
    sqr3 = 1.732051f;
/* --- PERMEABILITY OF FREE SPACE */
    permo = pi * 4.f * 1e-7f;
/* --- RESISTIVITIES, OHMS*MM */
    rescu = 2.1e-5f;
    resal = 3.44e-5f;
/* --- OPEN OUTPUT FILE */
    o__1.oerr = 0;
    o__1.ounit = 1;
    // o__1.ofnmlen = 6;
    char fName[255];
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
    out = 1;
/* --- OPEN INPUT FILE */
    o__1.oerr = 0;
    o__1.ounit = 2;
    // o__1.ofnmlen = 8;
    strcpy(fName, baseDirectory);
    strcat(fName, "INP1.FIL");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    // o__1.ofnm = "INP1.FIL";
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    o__1.oerr = 0;
    o__1.ounit = 3;
    // o__1.ofnmlen = 8;
    strcpy(fName, baseDirectory);
    strcat(fName, "INT2.FIL");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    // o__1.ofnm = "INT2.FIL";
    o__1.orl = 0;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    s_rsfe(&io___10);
    do_fio(&outmet_c__80, ident, (ftnlen)1);
    e_rsfe();
    s_rsfe(&io___12);
    do_fio(&outmet_c__1, (char *)&units, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&phase, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&freq, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&limbs, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&fract, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&zb, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&zu, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&dcore, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&wntnk, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&shld, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&scgva, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&zopt, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&fpeak, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&e1, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&e2, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&dpel, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&dzde, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&ftank, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&fleg, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&fyoke, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&scale, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&flxln, (ftnlen)sizeof(real));
    e_rsfe();
/* --- NUMBER OF TERMINALS */
    nterm = e1;
/* --- NUMBER OF LAYERS */
    nlay = e2;
    s_rsfe(&io___37);
    i__1 = nterm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 4; ++j) {
	    do_fio(&outmet_c__1, (char *)&term[i__ + j * 6 - 7], (ftnlen)sizeof(real)
		    );
	}
    }
    e_rsfe();
    s_rsfe(&io___41);
    i__1 = nlay;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 10; ++j) {
	    do_fio(&outmet_c__1, (char *)&layer[i__ + j * 30 - 31], (ftnlen)sizeof(
		    real));
	}
    }
    e_rsfe();
/* --- NUMBER OF SEGMENTS */
    nseg = layer[nlay + 29];
    s_rsfe(&io___44);
    i__1 = nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 9; ++j) {
	    do_fio(&outmet_c__1, (char *)&seg[i__ + j * 200 - 201], (ftnlen)sizeof(
		    real));
	}
    }
    e_rsfe();
    cl__1.cerr = 0;
    cl__1.cunit = 2;
    cl__1.csta = 0;
    f_clos(&cl__1);
    if (units != 2.f) {
	goto L136;
    }
/* --- CONVERSION OF INCHES TO MM */
    zb *= 25.4f;
    zu *= 25.4f;
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
    i__1 = nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	seg[i__ + 199] *= 25.4f;
	seg[i__ + 399] *= 25.4f;
	seg[i__ + 1399] *= 25.4f;
/* L135: */
	seg[i__ + 1599] *= 25.4f;
    }
L136:
    rmin = dcore * .5f;
    i__1 = nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	seg[i__ + 7399] = seg[i__ + 199];
/* L137: */
	seg[i__ + 7599] = seg[i__ + 399];
    }
/* L138: */
    i__1 = nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	e1 = (real) i__;
	i__2 = nlay;
	for (k = 1; k <= i__2; ++k) {
	    if (e1 > layer[k + 29]) {
		goto L140;
	    }
	    seg[i__ + 1799] = (real) k;
	    if (layer[k + 179] == 0.f) {
		seg[i__ + 799] = 0.f;
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
	    e1 = seg[j1 + 7399];
	    e2 = seg[j2 + 7599];
	    seg[i__ + 199] = seg[i__ + 7399] + dzde * (seg[i__ + 7399] - e1) /
		     (e2 - e1);
	    seg[i__ + 399] = seg[i__ + 7599] + dzde * (seg[i__ + 7599] - e1) /
		     (e2 - e1);
	    goto L141;
L139:
	    seg[i__ + 199] = seg[i__ + 7399] + dzde;
	    seg[i__ + 399] = seg[i__ + 7599] + dzde;
	    goto L141;
L140:
	    ;
	}
L141:
	;
    }
/* --- ADJUSTMENT OF Z - UPPER AND LOWER BOUNDARIES */
    i__1 = nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	seg[i__ + 199] -= zb;
/* L150: */
	seg[i__ + 399] -= zb;
    }
/* --- READ FROM GRAPHICS FILE */
    o__1.oerr = 0;
    o__1.ounit = 4;
    // o__1.ofnmlen = 7;
    strcpy(fName, baseDirectory);
    strcat(fName, "FOR.FIL");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    // o__1.ofnm = "FOR.FIL";
    o__1.orl = 500000;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    s_rsfe(&io___50);
    do_fio(&outmet_c__1, (char *)&n, (ftnlen)sizeof(integer));
    do_fio(&outmet_c__1, (char *)&i5, (ftnlen)sizeof(integer));
    do_fio(&outmet_c__1, (char *)&i6, (ftnlen)sizeof(integer));
    do_fio(&outmet_c__1, (char *)&linto, (ftnlen)sizeof(integer));
    do_fio(&outmet_c__1, (char *)&outmet_block1_1.lnver, (ftnlen)sizeof(integer));
    do_fio(&outmet_c__1, (char *)&lnhor, (ftnlen)sizeof(integer));
    e_rsfe();
    s_rsfe(&io___56);
    do_fio(&outmet_c__1, (char *)&flaxi, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&flxln, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&scale, (ftnlen)sizeof(real));
    for (i__ = 1; i__ <= 300; ++i__) {
	do_fio(&outmet_c__1, (char *)&xpos[i__ - 1], (ftnlen)sizeof(real));
    }
    for (i__ = 1; i__ <= 300; ++i__) {
	do_fio(&outmet_c__1, (char *)&ypos[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___60);
    for (i__ = 1; i__ <= 150; ++i__) {
	do_fio(&outmet_c__1, (char *)&iln[i__ - 1], (ftnlen)sizeof(shortint));
    }
    e_rsfe();
    s_rsfe(&io___62);
    for (i__ = 1; i__ <= 3000; ++i__) {
	do_fio(&outmet_c__1, (char *)&linc[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___64);
    do_fio(&outmet_c__80, ident, (ftnlen)1);
    e_rsfe();
    s_rsfe(&io___65);
    i__1 = linto;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&datln[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    nocol = outmet_block1_1.lnver - 1;
    j4 = i6 / 4;
    j2 = i6 / 2;
    j3 = j2 + j4;
    k8 = i5 / 8;
    k4 = i5 / 4;
    k2 = i5 / 2;
    k3 = k4 + k8;
/* --- NODE COORDINATES IN MILLIMETERS */
    s_rsfe(&io___74);
    i__1 = j4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&vert[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___76);
    i__1 = j2;
    for (i__ = j4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&vert[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___77);
    i__1 = j3;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&vert[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___78);
    i__1 = i6;
    for (i__ = j3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&vert[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___79);
    i__1 = j4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&vert[i__ + 29999], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___80);
    i__1 = j2;
    for (i__ = j4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&vert[i__ + 29999], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___81);
    i__1 = j3;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&vert[i__ + 29999], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___82);
    i__1 = i6;
    for (i__ = j3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&vert[i__ + 29999], (ftnlen)sizeof(real));
    }
    e_rsfe();
/* --- CONVERT TO METERS */
    i__1 = i6;
    for (i__ = 1; i__ <= i__1; ++i__) {
	vert[i__ - 1] *= .001f;
/* L151: */
	vert[i__ + 29999] *= .001f;
    }
/* --- REAL COMPONENTS OF ARRAY CPOT, COMPLEX VECTOR POTENTIALS */
    s_rsfe(&io___83);
    i__1 = j4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cpotr[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___85);
    i__1 = j2;
    for (i__ = j4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cpotr[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___86);
    i__1 = j3;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cpotr[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___87);
    i__1 = i6;
    for (i__ = j3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cpotr[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
/* --- INFORMATION ABOUT THE GRID, STORED IN INDIVIDUAL BITS */
    s_rsfe(&io___88);
    i__1 = j2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&outmet_block1_1.ibit[i__ - 1], (ftnlen)sizeof(integer)
		);
    }
    e_rsfe();
    s_rsfe(&io___89);
    i__1 = i6;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&outmet_block1_1.ibit[i__ - 1], (ftnlen)sizeof(integer)
		);
    }
    e_rsfe();
/* --- PERMEABILITIES */
    s_rsfe(&io___90);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___92);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___93);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___94);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___95);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___96);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___97);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___98);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
/* --- CONDUCTIVITIES */
    s_rsfe(&io___99);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___100);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___101);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___102);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___103);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___104);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___105);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___106);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&tri2[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
/* --- IMAGINARY COMPONENTS OF ARRAY CPOT, COMPLEX VECTOR POTENTIALS */
    s_rsfe(&io___107);
    i__1 = j4;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cpoti[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___109);
    i__1 = j2;
    for (i__ = j4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cpoti[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___110);
    i__1 = j3;
    for (i__ = j2 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cpoti[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___111);
    i__1 = i6;
    for (i__ = j3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cpoti[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
/* --- REAL AND IMAGINARY COMPONENTS OF ARRAY CDENS, CURRENT DENSITIES, A/SQ.M */
    s_rsfe(&io___112);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensr[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___114);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensr[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___115);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensr[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___116);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensr[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___117);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensr[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___118);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensr[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___119);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensr[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___120);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensr[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___121);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensi[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___123);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensi[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___124);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensi[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___125);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensi[i__ - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___126);
    i__1 = k8;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensi[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___127);
    i__1 = k4;
    for (i__ = k8 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensi[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___128);
    i__1 = k3;
    for (i__ = k4 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensi[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    s_rsfe(&io___129);
    i__1 = k2;
    for (i__ = k3 + 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&cdensi[i__ + k2 - 1], (ftnlen)sizeof(real));
    }
    e_rsfe();
    cl__1.cerr = 0;
    cl__1.cunit = 4;
    cl__1.csta = 0;
    f_clos(&cl__1);
/* --- WRITE PART OF INPUT */
    io___130.ciunit = out;
    s_wsfe(&io___130);
    do_fio(&outmet_c__80, ident, (ftnlen)1);
    do_fio(&outmet_c__1, (char *)&phase, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&scgva, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&freq, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&zopt, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&limbs, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&fpeak, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&fract, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&zb, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&ftank, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&zu, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&fleg, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&dcore, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&fyoke, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&wntnk, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&scale, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&shld, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&flxln, (ftnlen)sizeof(real));
    e_wsfe();
/* --- TERMINAL DATA */
    i__1 = nterm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	e1 = term[i__ + 5];
	if (e1 <= 4.f) {
	    goto L1831;
	}
	if (e1 == 5.f || e1 == 7.f || e1 == 9.f) {
	    term[i__ + 41] = term[i__ + 17];
	}
	if (e1 == 5.f || e1 == 7.f || e1 == 9.f) {
	    term[i__ + 42] = term[i__ + 17];
	}
	if (e1 == 6.f || e1 == 8.f || e1 == 10.f) {
	    term[i__ + 47] = term[i__ + 17];
	}
	if (e1 == 6.f || e1 == 8.f || e1 == 10.f) {
	    term[i__ + 46] = term[i__ + 17];
	}
L1831:
	s_copy(tstr + ((i__ - 1) << 2), strng + 8, (ftnlen)4, (ftnlen)4);
	if (e1 < 1.5f && phase < 1.5f) {
	    s_copy(tstr + ((i__ - 1) << 2), strng, (ftnlen)4, (ftnlen)4);
	}
	if (e1 < 1.5f && phase > 2.5f) {
	    s_copy(tstr + ((i__ - 1) << 2), strng + 4, (ftnlen)4, (ftnlen)4);
	}
	if (e1 == 3.f) {
	    s_copy(tstr + ((i__ - 1) << 2), strng + 12, (ftnlen)4, (ftnlen)4);
	}
	if (e1 == 5.f) {
	    s_copy(tstr + ((i__ - 1) << 2), strng + 16, (ftnlen)4, (ftnlen)4);
	}
	if (e1 == 6.f) {
	    s_copy(tstr + ((i__ - 1) << 2), strng + 20, (ftnlen)4, (ftnlen)4);
	}
	if (e1 == 7.f) {
	    s_copy(tstr + ((i__ - 1) << 2), strng + 24, (ftnlen)4, (ftnlen)4);
	}
	if (e1 == 8.f) {
	    s_copy(tstr + ((i__ - 1) << 2), strng + 28, (ftnlen)4, (ftnlen)4);
	}
	if (e1 == 9.f) {
	    s_copy(tstr + ((i__ - 1) << 2), strng + 32, (ftnlen)4, (ftnlen)4);
	}
	if (e1 == 10.f) {
	    s_copy(tstr + ((i__ - 1) << 2), strng + 36, (ftnlen)4, (ftnlen)4);
	}
/* L184: */
    }
    io___132.ciunit = out;
    s_wsfe(&io___132);
    i__1 = nterm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&term[i__ - 1], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___133.ciunit = out;
    s_wsfe(&io___133);
    i__1 = nterm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, tstr + ((i__ - 1) << 2), (ftnlen)4);
    }
    e_wsfe();
    io___134.ciunit = out;
    s_wsfe(&io___134);
    i__1 = nterm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&term[i__ + 11], (ftnlen)sizeof(real));
    }
    e_wsfe();
    io___135.ciunit = out;
    s_wsfe(&io___135);
    i__1 = nterm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&outmet_c__1, (char *)&term[i__ + 17], (ftnlen)sizeof(real));
    }
    e_wsfe();
/* --- LAYER DATA */
    io___136.ciunit = out;
    s_wsfe(&io___136);
    e_wsfe();
    i__1 = nlay;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s_copy(s1, strng + 40, (ftnlen)4, (ftnlen)4);
	if (layer[i__ + 209] > 1.5f) {
	    s_copy(s1, strng + 44, (ftnlen)4, (ftnlen)4);
	}
/* L186: */
	io___138.ciunit = out;
	s_wsfe(&io___138);
	for (j = 1; j <= 7; ++j) {
	    do_fio(&outmet_c__1, (char *)&layer[i__ + j * 30 - 31], (ftnlen)sizeof(
		    real));
	}
	do_fio(&outmet_c__1, s1, (ftnlen)4);
	do_fio(&outmet_c__1, (char *)&layer[i__ + 239], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&layer[i__ + 269], (ftnlen)sizeof(real));
	e_wsfe();
    }
/* --- SEGMENT DATA */
    io___139.ciunit = out;
    s_wsfe(&io___139);
    e_wsfe();
    i__1 = nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L191: */
	io___140.ciunit = out;
	s_wsfe(&io___140);
	do_fio(&outmet_c__1, (char *)&seg[i__ - 1], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 1799], (ftnlen)sizeof(real));
	for (j = 2; j <= 9; ++j) {
	    do_fio(&outmet_c__1, (char *)&seg[i__ + j * 200 - 201], (ftnlen)sizeof(
		    real));
	}
	e_wsfe();
    }
/* --- WRITE POSITIONS OF GRID LINES */
    io___141.ciunit = out;
    s_wsfe(&io___141);
    e_wsfe();
    j = 1;
    k = 10;
L195:
    if (k > outmet_block1_1.lnver) {
	k = outmet_block1_1.lnver;
    }
    if (j == k) {
	io___142.ciunit = out;
	s_wsfe(&io___142);
	do_fio(&outmet_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&outmet_c__1, (char *)&xpos[j - 1], (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (k <= 99 && j != k) {
	io___143.ciunit = out;
	s_wsfe(&io___143);
	do_fio(&outmet_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&outmet_c__1, (char *)&k, (ftnlen)sizeof(integer));
	i__1 = k;
	for (i__ = j; i__ <= i__1; ++i__) {
	    do_fio(&outmet_c__1, (char *)&xpos[i__ - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
    }
    if (k > 99 && j != k) {
	io___144.ciunit = out;
	s_wsfe(&io___144);
	do_fio(&outmet_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&outmet_c__1, (char *)&k, (ftnlen)sizeof(integer));
	i__1 = k;
	for (i__ = j; i__ <= i__1; ++i__) {
	    do_fio(&outmet_c__1, (char *)&xpos[i__ - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
    }
    if (k == outmet_block1_1.lnver) {
	goto L198;
    }
    j += 10;
    k += 10;
    goto L195;
L198:
    io___145.ciunit = out;
    s_wsfe(&io___145);
    e_wsfe();
    j = 1;
    k = 10;
L199:
    if (k > lnhor) {
	k = lnhor;
    }
    if (j == k) {
	io___146.ciunit = out;
	s_wsfe(&io___146);
	do_fio(&outmet_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&outmet_c__1, (char *)&ypos[j - 1], (ftnlen)sizeof(real));
	e_wsfe();
    }
    if (k <= 99 && j != k) {
	io___147.ciunit = out;
	s_wsfe(&io___147);
	do_fio(&outmet_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&outmet_c__1, (char *)&k, (ftnlen)sizeof(integer));
	i__1 = k;
	for (i__ = j; i__ <= i__1; ++i__) {
	    do_fio(&outmet_c__1, (char *)&ypos[i__ - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
    }
    if (k > 99 && j != k) {
	io___148.ciunit = out;
	s_wsfe(&io___148);
	do_fio(&outmet_c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&outmet_c__1, (char *)&k, (ftnlen)sizeof(integer));
	i__1 = k;
	for (i__ = j; i__ <= i__1; ++i__) {
	    do_fio(&outmet_c__1, (char *)&ypos[i__ - 1], (ftnlen)sizeof(real));
	}
	e_wsfe();
    }
    if (k == lnhor) {
	goto L200;
    }
    j += 10;
    k += 10;
    goto L199;
L200:
/* --- MODULUS OF ELASTICITY, N/SQ.MM */
    ecu = 127530.f;
    eal = 70632.f;
/* --- MAX. MVA */
    mvamx = 0.f;
    i__1 = nterm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ == 2 && term[i__ + 5] == 3.f) {
	    goto L500;
	}
	if (term[i__ + 11] > mvamx) {
	    mvamx = term[i__ + 11];
	}
L500:
	;
    }
/* --- PU SYSTEM IMPEDANCE */
    zsyst = 0.f;
    if (scgva > 0.f) {
	zsyst = mvamx * .001f / scgva;
    }
/* --- WRITE HEADING FOR SEGMENT OUTPUT */
    io___153.ciunit = out;
    s_wsfe(&io___153);
    e_wsfe();
    io___154.ciunit = out;
    s_wsfe(&io___154);
    e_wsfe();
/* --- INITIALIZE NUMBER OF TURNS IN SERIES FOR EACH TERMINAL */
    i__1 = nterm;
    for (l = 1; l <= i__1; ++l) {
/* L201: */
	term[l + 23] = 0.f;
    }
    i__1 = nseg;
    for (l = 1; l <= i__1; ++l) {
/* --- LAYER NUMBER */
	j = seg[l + 1799];
/* --- TERMINAL NUMBER */
	k = layer[j + 119];
/* --- NUMBER OF ACTIVE TURNS IN SERIES (WITH SIGN) */
	e1 = seg[l + 799] * layer[j + 179];
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
/* L203: */
	term[l + 29] = term[l + 11] * 1e3f;
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
    i__1 = nseg;
    for (l = 1; l <= i__1; ++l) {
	j = seg[l + 1799];
	k = layer[j + 119];
	e1 = term[k + 5];
/* --- MIN AND MAX RADIUS */
	seg[l + 1999] = layer[j + 59];
	seg[l + 2199] = layer[j + 89] + seg[l + 1999];
/* --- KVA PER SEGMENT */
	seg[l + 2399] = 0.f;
	if (term[k + 23] != 0.f) {
	    seg[l + 2399] = term[k + 29] * fract * seg[l + 799] * layer[j + 
		    179] / ((r__1 = term[k + 23], dabs(r__1)) * limbs);
	}
	if (layer[j + 149] >= 2.f) {
	    seg[l + 2399] *= .5f;
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
	seg[l + 2399] = seg[l + 2399] * term[k + 17] / zkvr;
	if (term[k + 5] == 10.f) {
	    seg[l + 2399] = sqr3 * seg[l + 2399];
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
    i__1 = nseg;
    for (l = 1; l <= i__1; ++l) {
/* --- LAYER NO. */
	j = seg[l + 1799];
/* --- AREA OF SEGMENT, SQ.MM */
	aseg = (seg[l + 399] - seg[l + 199]) * (seg[l + 2199] - seg[l + 1999])
		;
/* --- AREA OF CONDUCTOR */
	acond = seg[l + 1399] * seg[l + 1599];
	if (seg[l + 1599] > 50.f) {
	    goto L208;
	}
	if (acond > .25f) {
	    acond += -.25f;
	}
	if (acond > 14.75f) {
	    acond += -.25f;
	}
	if (seg[l + 1399] == seg[l + 1599] && seg[l + 1399] <= 4.f) {
/* Computing 2nd power */
	    r__1 = seg[l + 1399];
	    acond = pi / 4.f * (r__1 * r__1);
	}
/* --- FILL FACTOR */
L208:
	seg[l + 5999] = acond * seg[l + 599] * seg[l + 999] / aseg;
	if (layer[j + 149] >= 2.f) {
	    seg[l + 5999] = layer[j + 149] * .5f * seg[l + 5999];
	}
/* L209: */
    }
/* --- SEGMENT CALCULATIONS */
    e1 = 0.f;
    i__1 = nseg;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = seg[i__ + 1799];
	k = layer[j + 119];
	e4 = term[k + 5];
	zkvn = term[k + 41];
	zkvt = term[k + 47];
/* --- SUM OF KVA */
	if (e4 < 4.5f) {
	    e1 += seg[i__ + 2399];
	}
	if (e4 < 4.5f) {
	    goto L210;
	}
/* --- PHASE ANGLE OF CURRENT */
	if (e4 < 8.5f) {
	    zang = atan(zkvt * .5f * sqr3 / (zkvn + zkvt * .5f));
	}
	if (e4 > 8.5f) {
	    zang = atan(zkvt * .5f * sqr3 / (zkvn + zkvt * 1.5f));
	}
	if (e4 == 5.f || e4 == 7.f || e4 == 9.f) {
	    e1 += seg[i__ + 2399] * cos(zang);
	}
	if (e4 == 6.f || e4 == 8.f) {
	    e1 += seg[i__ + 2399] * cos(pi / 3.f - zang);
	}
	if (e4 == 10.f) {
	    e1 += seg[i__ + 2399] * cos(pi / 6.f - zang);
	}
/* --- AREA OF SEGMENT, SQ.MM */
L210:
	aseg = (seg[i__ + 399] - seg[i__ + 199]) * (seg[i__ + 2199] - seg[i__ 
		+ 1999]);
/* --- CURRENT DENSITY IN SEGMENT REFERRED TO GROSS AREA, A/SQ.MM */
	e2 = (r__1 = seg[i__ + 2399] * 1e3f / (vturn * aseg), dabs(r__1));
/* --- CURRENT DENSITY IN CONDUCTOR, A/SQ.MM */
	scond = 0.f;
	if (seg[i__ + 1599] >= 50.f) {
	    seg[i__ + 5999] = seg[i__ + 799] * seg[i__ + 999] * seg[i__ + 
		    1399] * seg[i__ + 1599] / aseg;
	}
	e3 = seg[i__ + 799] * seg[i__ + 5999];
	if (e3 > .001f) {
	    scond = e2 * seg[i__ + 599] / e3;
	}
	if (seg[i__ + 1599] < 50.f) {
	    goto L501;
	}
	seg[i__ + 7799] = scond;
	cdavg = scond;
	thksh = seg[i__ + 999] * seg[i__ + 1399];
/* --- DC LOSS, KW/CUB.DM GROSS VOLUME */
/* --- COPPER CONDUCTORS (NOT INCLUDING LEADS AND CONNECTIONS) */
L501:
/* Computing 2nd power */
	r__1 = scond;
	seg[i__ + 4599] = rescu * 1e3f * seg[i__ + 5999] * seg[i__ + 799] * (
		r__1 * r__1) / seg[i__ + 599];
/* --- ALUMINUM CONDUCTORS */
	if (layer[j + 209] > 1.5f) {
	    seg[i__ + 4599] = seg[i__ + 4599] * resal / rescu;
	}
/* --- DC LOSS, TOTAL */
	seg[i__ + 4799] = seg[i__ + 4599] * pi * aseg * (seg[i__ + 1999] + 
		seg[i__ + 2199]) * 1e-6f;
/* L502: */
    }
/* --- ABORT IF AMPERETURNS ARE NOT BALANCED */
    if (dabs(e1) > mvamx * 5.f) {
	warn = 76;
    }
    if (dabs(e1) > mvamx * 5.f) {
	goto L998;
    }
/* --- INITIALIZATION */
    dctot = 0.f;
    edtot = 0.f;
/* --- SEGMENT NUMBER */
    i__ = 1;
    nexit = 1;
L503:
    i2 = 0;
    zsmn = seg[i__ + 199] * .001f;
    zsmx = seg[i__ + 399] * .001f;
/* --- FACTOR FOR EDDY CURRENT LOSSES (FEDDY*(MM*TESLA)**2=KW/CUB.DM) */
/* Computing 2nd power */
    r__1 = pi * freq;
    feddy = r__1 * r__1 / (rescu * 6e9f);
    if (seg[i__ + 1599] <= 50.f) {
	feddy = seg[i__ + 5999] * feddy;
    }
/* --- CORRECTION FOR ROUND WIRE */
    if (seg[i__ + 1399] == seg[i__ + 1599] && seg[i__ + 1399] <= 4.f) {
	feddy *= .7427f;
    }
/* --- LAYER NUMBER */
    j = seg[i__ + 1799];
/* --- TERMINAL NUMBER */
    k = layer[j + 119];
/* --- CONNECTION CODE */
    e12 = term[k + 5];
    if (layer[j + 209] > 1.5f) {
	feddy = feddy * rescu / resal;
    }
    if (nexit == 2) {
	goto L512;
    }
/* --- INITIALIZATION */
    seg[i__ + 2599] = 0.f;
    seg[i__ + 2799] = 0.f;
    seg[i__ + 2999] = 9.9e9f;
    seg[i__ + 3199] = 0.f;
    seg[i__ + 3599] = 0.f;
    seg[i__ + 4999] = 0.f;
    seg[i__ + 5199] = 0.f;
    seg[i__ + 5799] = 0.f;
    for (i1 = 32; i1 <= 35; ++i1) {
/* L507: */
	seg[i__ + i1 * 200 - 201] = 0.f;
    }
    saxmn = 0.f;
    saxmx = 0.f;
/* --- TRIANGLE NUMBER */
    k = 1;
    klast = 0;
    iexit = 1;
/* --- NODE NUMBERS */
L508:
    l = outmet_itri_(&k, &outmet_c__1);
    m = outmet_itri_(&k, &outmet_c__2);
    n = outmet_itri_(&k, &outmet_c__3);
    rl = vert[l - 1];
    zl = vert[l + 29999];
    rm = vert[m - 1];
    zm = vert[m + 29999];
    rn = vert[n - 1];
    zn = vert[n + 29999];
    rc = (rl + rm + rn) / 3.f;
    if (nexit == 2) {
	goto L509;
    }
    e8 = rc * 1e3f;
    if (e8 < seg[i__ + 1999] || e8 > seg[i__ + 2199]) {
	goto L517;
    }
/* --- CURRENT DENSITY, A/SQ.MM */
    i__1 = k - 1;
    i__2 = k - 1;
    q__2.r = cdensr[i__1], q__2.i = cdensi[i__2];
    q__1.r = q__2.r * 1e-6f, q__1.i = q__2.i * 1e-6f;
    cd.r = q__1.r, cd.i = q__1.i;
    cdabs = c_abs(&cd);
    if (cdabs == 0.f && seg[i__ + 1599] > 50.f) {
	goto L517;
    }
L509:
    zc = (zl + zm + zn) / 3.f;
    outmet_subd_(&d__, &rm, &zm, &rn, &zn, &rl, &zl);
/* --- FLUX DENSITIES */
    i__1 = l - 1;
    i__2 = l - 1;
    q__1.r = cpotr[i__1], q__1.i = cpoti[i__2];
    al.r = q__1.r, al.i = q__1.i;
    i__1 = m - 1;
    i__2 = m - 1;
    q__1.r = cpotr[i__1], q__1.i = cpoti[i__2];
    am.r = q__1.r, am.i = q__1.i;
    i__1 = n - 1;
    i__2 = n - 1;
    q__1.r = cpotr[i__1], q__1.i = cpoti[i__2];
    an.r = q__1.r, an.i = q__1.i;
    q__3.r = al.r + am.r, q__3.i = al.i + am.i;
    q__2.r = q__3.r + an.r, q__2.i = q__3.i + an.i;
    q__1.r = q__2.r / 3.f, q__1.i = q__2.i / 3.f;
    ac.r = q__1.r, ac.i = q__1.i;
    r__1 = rm - rn;
    q__5.r = r__1 * al.r, q__5.i = r__1 * al.i;
    r__2 = rn - rl;
    q__6.r = r__2 * am.r, q__6.i = r__2 * am.i;
    q__4.r = q__5.r + q__6.r, q__4.i = q__5.i + q__6.i;
    r__3 = rl - rm;
    q__7.r = r__3 * an.r, q__7.i = r__3 * an.i;
    q__3.r = q__4.r + q__7.r, q__3.i = q__4.i + q__7.i;
    q__2.r = q__3.r / d__, q__2.i = q__3.i / d__;
    q__1.r = sqr2 * q__2.r, q__1.i = sqr2 * q__2.i;
    bh.r = q__1.r, bh.i = q__1.i;
    r__1 = zm - zn;
    q__6.r = r__1 * al.r, q__6.i = r__1 * al.i;
    r__2 = zn - zl;
    q__7.r = r__2 * am.r, q__7.i = r__2 * am.i;
    q__5.r = q__6.r + q__7.r, q__5.i = q__6.i + q__7.i;
    r__3 = zl - zm;
    q__8.r = r__3 * an.r, q__8.i = r__3 * an.i;
    q__4.r = q__5.r + q__8.r, q__4.i = q__5.i + q__8.i;
    q__3.r = q__4.r / d__, q__3.i = q__4.i / d__;
    q__9.r = ac.r / rc, q__9.i = ac.i / rc;
    q__2.r = q__3.r + q__9.r, q__2.i = q__3.i + q__9.i;
    q__1.r = sqr2 * q__2.r, q__1.i = sqr2 * q__2.i;
    bz.r = q__1.r, bz.i = q__1.i;
    bhabs = c_abs(&bh);
    bzabs = c_abs(&bz);
    if (nexit == 2) {
	switch (kexit) {
	    case 1:  goto L552;
	    case 2:  goto L554;
	    case 3:  goto L536;
	}
    }
    r__1 = r_imag(&bh);
    r__2 = bh.r;
    outmet_angle_(&r__1, &r__2, &outmet_c_b360, &e5, &pi);
    r__1 = r_imag(&bz);
    r__2 = bz.r;
    outmet_angle_(&r__1, &r__2, &outmet_c_b360, &e6, &pi);
    outmet_angle_(&cdensi[k - 1], &cdensr[k - 1], &outmet_c_b360, &e7, &pi);
    e13 = cdabs * 1e6f * sqr2;
    if (e12 < 4.5f) {
	fr = e13 * bzabs * cos(e6) * cos(e7);
    }
    if (e12 < 4.5f) {
	fz = e13 * bhabs * cos(e5) * cos(e7);
    }
    if (e12 > 4.5f) {
	fr = e13 * bzabs * cos(e6 - e7);
    }
    if (e12 > 4.5f) {
	fz = e13 * bhabs * cos(e5 - e7);
    }
    j1 = k - klast;
    if (klast == 0 || j1 <= 3 || i2 == 0) {
	goto L510;
    }
    if (e3 < seg[i__ + 2999]) {
	seg[i__ + 2999] = e3;
    }
    if (e3 > seg[i__ + 3199]) {
	seg[i__ + 3199] = e3;
    }
    i2 = 0;
L510:
    if (iexit == 1 && zc > zsmx) {
	i2 = 0;
    }
    if (iexit == 1 && zc > zsmx) {
	goto L5152;
    }
    if (iexit == 2 && zc < zsmn) {
	goto L529;
    }
/* --- AXIAL FORCE PER CUB.DM AT PEAK RATED CURRENT */
L512:
    newax = -fz * .001f;
    if (nexit == 2) {
	goto L516;
    }
/* --- CUB.DM OF ELEMENT */
    vol = pi * 1e3f * rc * d__;
    e4 = newax * vol;
    if (iexit == 2) {
	goto L513;
    }
/* --- FORCE FROM BOTTOM OF LAYER UP TO TOP OF SEGMENT (POSITIVE) */
    e5 = seg[i__ + 6399];
    seg[i__ + 6399] += e4;
    if (seg[i__ + 6399] < 0.f) {
	seg[i__ + 6399] = 0.f;
    }
/* --- FORCE FROM BOTTOM OF LAYER UP TO MAXIMUM IN SEGMENT */
    if (zc < zsmn) {
	goto L518;
    }
    if (e5 > seg[i__ + 6199]) {
	seg[i__ + 6199] = e5;
    }
    if (seg[i__ + 6399] > seg[i__ + 6199]) {
	seg[i__ + 6199] = seg[i__ + 6399];
    }
    goto L516;
/* --- FORCE FROM TOP OF LAYER DOWN TO BOTTOM OF SEGMENT (NEGATIVE) */
L513:
    e5 = seg[i__ + 6799];
    seg[i__ + 6799] += e4;
    if (seg[i__ + 6799] > 0.f) {
	seg[i__ + 6799] = 0.f;
    }
/* --- FORCE FROM TOP OF LAYER DOWN TO MAXIMUM IN SEGMENT */
    if (zc > zsmx) {
	goto L527;
    }
    if (e5 < seg[i__ + 6599]) {
	seg[i__ + 6599] = e5;
    }
    if (seg[i__ + 6799] < seg[i__ + 6599]) {
	seg[i__ + 6599] = seg[i__ + 6799];
    }
    goto L527;
/* --- RADIAL FORCE AND EDDY CURRENT LOSSES PER CUB.DM */
L516:
    newrad = fr * .001f;
    edrad = 0.f;
    if (seg[i__ + 1599] <= 50.f) {
/* Computing 2nd power */
	r__1 = seg[i__ + 1599] * bhabs;
	edrad = feddy * (r__1 * r__1);
    }
    if (seg[i__ + 1599] > 50.f) {
/* Computing 2nd power */
	r__1 = cdabs;
	edrad = r__1 * r__1 / tri2[k - 1] - seg[i__ + 4599] / seg[i__ + 5999];
    }
/* Computing 2nd power */
    r__1 = seg[i__ + 1399] * bzabs;
    edax = feddy * (r__1 * r__1);
    if (seg[i__ + 1599] > 50.f) {
/* Computing 2nd power */
	r__1 = seg[i__ + 999];
	edax *= r__1 * r__1;
    }
    e1 = edrad + edax;
    e7 = e1;
    if (seg[i__ + 1599] > 50.f) {
	e7 = cdabs / seg[i__ + 7799];
    }
    if (e7 <= seg[i__ + 5799]) {
	goto L515;
    }
    seg[i__ + 5799] = e7;
/* Computing MIN */
    r__1 = min(rl,rm);
    seg[i__ + 6999] = dmin(r__1,rn) * 1e3f;
/* Computing MAX */
    r__1 = max(rl,rm);
    seg[i__ + 7199] = dmax(r__1,rn) * 1e3f;
/* Computing MIN */
    r__1 = min(zl,zm);
    seg[i__ + 7399] = dmin(r__1,zn) * 1e3f;
/* Computing MAX */
    r__1 = max(zl,zm);
    seg[i__ + 7599] = dmax(r__1,zn) * 1e3f;
L515:
    e1 = newrad * vol;
    seg[i__ + 2599] += e1;
    seg[i__ + 2799] += e4;
    seg[i__ + 4999] += edax * vol;
    seg[i__ + 5199] += edrad * vol;
/* Computing MIN */
    r__1 = min(rl,rm);
    e10 = dmin(r__1,rn);
/* Computing MAX */
    r__1 = max(rl,rm);
    e11 = dmax(r__1,rn);
    if (e10 * 1e3f - .1f < seg[i__ + 1999] && rc - e10 < e11 - rc) {
	i2 = 1;
    }
/* Computing MAX */
    r__1 = max(zl,zm);
/* Computing MIN */
    r__2 = min(zl,zm);
    e6 = e1 / (dmax(r__1,zn) - dmin(r__2,zn));
    if (j1 > 3) {
	e2 = e6;
    }
    if (j1 <= 3) {
	e2 += e6;
    }
    if (j1 <= 3) {
	e3 = dabs(e2) * .001f;
    }
    if (dabs(newax) > (r__1 = seg[i__ + 3599], dabs(r__1))) {
	seg[i__ + 3599] = newax;
    }
    if (seg[i__ + 2799] < saxmn) {
	saxmn = seg[i__ + 2799];
    }
    if (seg[i__ + 2799] > saxmx) {
	saxmx = seg[i__ + 2799];
    }
L5152:
    klast = k;
L517:
    if (iexit == 2) {
	goto L527;
    }
L518:
    ++k;
    if (k <= i5) {
	goto L508;
    }
/* --- TOTALS FOR SEGMENTS */
/* L523: */
    seg[i__ + 5399] = seg[i__ + 4999] + seg[i__ + 5199];
    seg[i__ + 5599] = 0.f;
    if (seg[i__ + 4799] > 1e-10f) {
	seg[i__ + 5599] = seg[i__ + 5399] / seg[i__ + 4799];
    }
    if (seg[i__ + 4599] > 1e-10f && seg[i__ + 1599] <= 50.f) {
	seg[i__ + 5799] /= seg[i__ + 4599];
    }
    if (seg[i__ + 4599] < 1e-10f) {
	seg[i__ + 5799] = 0.f;
    }
    if (seg[i__ + 2599] >= 0.f) {
	goto L524;
    }
    seg[i__ + 2999] = -seg[i__ + 2999];
    seg[i__ + 3199] = -seg[i__ + 3199];
L524:
    seg[i__ + 3399] = saxmx - saxmn;
    if (seg[i__ + 2799] < 0.f) {
	seg[i__ + 3399] = -seg[i__ + 3399];
    }
/* --- TOTALS FOR TRANSFORMER SECTION */
    dctot += seg[i__ + 4799];
    edwnd += seg[i__ + 5399];
    iexit = 2;
    k = i5 - (outmet_block1_1.lnver << 1);
L527:
    --k;
    if (k <= 0) {
	goto L529;
    }
    goto L508;
L529:
    ++i__;
    if (i__ <= nseg) {
	goto L503;
    }
    edtnk = 0.f;
    edleg = 0.f;
    edyok = 0.f;
/* --- KW EDDY CURRENT LOSS, TANK */
    e1 = pi * .002f * (ypos[lnhor - 1] - ypos[0]);
    if (shld > .5f) {
	goto L533;
    }
    i__1 = i6 - 1;
    i__2 = i6 - 1;
    q__1.r = cpotr[i__1], q__1.i = cpoti[i__2];
    amin = sqr2 * c_abs(&q__1);
    amax = amin;
    i__ = outmet_block1_1.lnver;
L532:
    i__1 = i__ - 1;
    i__2 = i__ - 1;
    q__1.r = cpotr[i__1], q__1.i = cpoti[i__2];
    e2 = sqr2 * c_abs(&q__1);
    if (e2 < amin) {
	amin = e2;
    }
    if (e2 > amax) {
	amax = e2;
    }
    i__ += outmet_block1_1.lnver;
    if (i__ <= i6) {
	goto L532;
    }
/* Computing 2nd power */
    r__1 = amax - amin;
    edtnk = ftank * xpos[outmet_block1_1.lnver - 1] * e1 * (r__1 * r__1);
/* --- LEG */
L533:
    q__1.r = cpotr[0], q__1.i = cpoti[0];
    amin = sqr2 * c_abs(&q__1);
    amax = amin;
    i1 = i6 - outmet_block1_1.lnver + 1;
    i__1 = i1;
    i__2 = outmet_block1_1.lnver;
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
	i__3 = i__ - 1;
	i__4 = i__ - 1;
	q__1.r = cpotr[i__3], q__1.i = cpoti[i__4];
	e2 = sqr2 * c_abs(&q__1);
	if (e2 < amin) {
	    amin = e2;
	}
	if (e2 > amax) {
	    amax = e2;
	}
/* L534: */
    }
/* Computing 2nd power */
    r__1 = amax - amin;
    edleg = fleg * xpos[0] * e1 * (r__1 * r__1);
/* --- UPPER YOKE */
/* Computing 2nd power */
    r__1 = xpos[outmet_block1_1.lnver - 1] + xpos[0];
    e1 = fyoke * .008f * xpos[0] * (xpos[outmet_block1_1.lnver - 1] - xpos[0]) / (
	    r__1 * r__1);
    i__2 = i6 - 1;
    i__1 = i6 - 1;
    q__1.r = cpotr[i__2], q__1.i = cpoti[i__1];
    e2 = sqr2 * c_abs(&q__1);
    i__2 = i1 - 1;
    i__1 = i1 - 1;
    q__1.r = cpotr[i__2], q__1.i = cpoti[i__1];
    e3 = sqr2 * c_abs(&q__1);
/* Computing 2nd power */
    r__1 = xpos[outmet_block1_1.lnver - 1] * e2 - xpos[0] * e3;
    edyok = e1 * (r__1 * r__1);
/* --- TOTAL KW EDDY CURRENT LOSS */
    edtot = edwnd + edtnk + edleg + edyok;
/* --- PER UNIT */
    edpu = edtot / dctot;
    kexit = 3;
    nexit = 2;
    k = 0;
    emag = 0.f;
L535:
    ++k;
    if (k > i5) {
	goto L537;
    }
    goto L508;
/* --- ACCUMULATED MAGNETIC ENERGY, WATTS*SEC */
L536:
/* Computing 2nd power */
    r__1 = bhabs;
/* Computing 2nd power */
    r__2 = bzabs;
    ws = (r__1 * r__1 + r__2 * r__2) * d__ / (permo * 4.f) * twopi * rc;
    emag += ws;
    goto L535;
/* --- PER UNIT SHORT CIRCUIT REACTANCE */
L537:
    e1 = mvamx * 1e3f * fract / limbs;
    xpu = pi * .002f * freq * emag / e1;
/* --- RESISTANCE */
    rpu = (dctot + edtot) / e1;
/* --- IMPEDANCE */
    zpu = 0.f;
/* Computing 2nd power */
    r__1 = xpu;
/* Computing 2nd power */
    r__2 = rpu;
    e1 = r__1 * r__1 + r__2 * r__2;
    if (e1 > 0.f) {
/* Computing 2nd power */
	r__1 = xpu;
/* Computing 2nd power */
	r__2 = rpu;
	zpu = sqrt(r__1 * r__1 + r__2 * r__2);
    }
    ztot = zpu + zsyst;
    zused = ztot;
    if (zopt > 0.f) {
	zused = zopt;
    }
/* --- FACTOR FOR SHORT CIRCUIT FORCES AND STRESSES */
/* Computing 2nd power */
    r__1 = fpeak / zused;
    fsc = r__1 * r__1;
/* --- INITIALIZATION */
    for (i__ = 1; i__ <= 5; ++i__) {
	crit[i__ - 1] = 0.f;
/* L538: */
	crit[i__ + 4] = 0.f;
    }
    i__2 = nseg;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* --- FORCES CORRECTED TO PEAK SHORT CIRCUIT CURRENT */
	for (j = 14; j <= 19; ++j) {
/* L542: */
	    seg[i__ + j * 200 - 201] = fsc * seg[i__ + j * 200 - 201];
	}
/* --- MAX. N/CUB.CM, AXIALLY */
	seg[i__ + 3599] *= .001f;
/* --- LAYER NUMBER */
	j = seg[i__ + 1799];
/* --- TOTAL CONDUCTOR AREA */
	e1 = seg[i__ + 599] * seg[i__ + 999] * seg[i__ + 1399] * seg[i__ + 
		1599];
	if (layer[j + 149] > 2.f) {
	    e1 = e1 * layer[j + 149] * fract;
	}
/* --- STRESS DUE TO RADIAL FORCES */
	seg[i__ + 3799] = seg[i__ + 3199] * (seg[i__ + 399] - seg[i__ + 199]) 
		/ (twopi * e1);
	if (seg[i__ + 799] > .1f) {
	    seg[i__ + 3799] = seg[i__ + 3799] * seg[i__ + 599] / seg[i__ + 
		    799];
	}
	seg[i__ + 3999] = 0.f;
	if (seg[i__ + 3199] >= 0.f) {
	    goto L543;
	}
/* --- MOMENT OF INERTIA OF ONE CONDUCTOR */
/* Computing 3rd power */
	r__1 = seg[i__ + 1399];
	e2 = r__1 * (r__1 * r__1) * seg[i__ + 1599] / 12.f;
	e3 = ecu;
	if (layer[j + 209] > 1.5f) {
	    e3 = eal;
	}
/* --- CRITICAL LENGTH FOR BUCKLING (TIMOSHENKO EQ.146) */
	e7 = e3 * e2 / (-seg[i__ + 3799] * seg[i__ + 1399] * seg[i__ + 1599]);
	if (e7 < 0.f) {
	    goto L543;
	}
	e4 = twopi * sqrt(e7);
/* --- MIN. NUMBER OF SPACER BARS */
	seg[i__ + 3999] = twopi * (seg[i__ + 1999] + seg[i__ + 2199]) / e4;
L543:
	seg[i__ + 4199] = 0.f;
	seg[i__ + 4399] = 0.f;
	if (seg[i__ + 2399] == 0.f) {
	    goto L544;
	}
/* --- MAXIMUM AXIAL COMPRESSIVE FORCE AT SHORT CIRCUIT */
/* Computing MAX */
	r__1 = seg[i__ + 6199], r__2 = -seg[i__ + 6599];
	e4 = fsc * dmax(r__1,r__2);
/* --- AVERAGE CIRCUMFERENCE */
	e2 = pi * (seg[i__ + 1999] + seg[i__ + 2199]);
/* --- COMPRESSIVE STRESS IN INSULATION, IF NO SPACERS */
	if (seg[i__ + 1599] <= 50.f) {
	    seg[i__ + 4199] = e4 / (e2 * seg[i__ + 1199] * seg[i__ + 1399]);
	}
	if (layer[j + 239] < .5f) {
	    goto L544;
	}
/* --- COMPRESSIVE STRESS IN SPACERS */
	seg[i__ + 4199] = seg[i__ + 4199] * e2 / (layer[j + 239] * layer[j + 
		269]);
/* --- SPACER PITCH AT AVERAGE DIAMETER MINUS HALF THE SPACER WIDTH (MM) */
	e4 = pi * (seg[i__ + 1999] + seg[i__ + 2199]) / layer[j + 239] - 
		layer[j + 269] / 2.f;
/* --- CUB.CM GROSS VOLUME TAKEN UP BY ONE STRAND WITH LENGTH E4 */
	e2 = (seg[i__ + 2199] - seg[i__ + 1999]) * .001f * (seg[i__ + 399] - 
		seg[i__ + 199]) * e4 * (seg[i__ + 1399] * seg[i__ + 1599]) / 
		e1;
/* --- BENDING STRESS+TENSION/COMPRESSION */
/* Computing 2nd power */
	r__2 = seg[i__ + 1599];
	seg[i__ + 4399] = (r__1 = seg[i__ + 3599], dabs(r__1)) * e2 * e4 / (
		seg[i__ + 1399] * 2.f * (r__2 * r__2));
	if (seg[i__ + 799] > 0.f) {
	    seg[i__ + 4399] = seg[i__ + 4399] * seg[i__ + 599] / seg[i__ + 
		    799];
	}
	seg[i__ + 4399] += (r__1 = seg[i__ + 3799] * seg[i__ + 2999] / seg[
		i__ + 3199], dabs(r__1));
/* --- ESTABLISH CRITICAL STRESSES ETC. */
L544:
	if (seg[i__ + 3799] < crit[0]) {
	    goto L545;
	}
	crit[0] = seg[i__ + 3799];
	crit[5] = (real) i__;
L545:
	if (seg[i__ + 3799] > crit[1]) {
	    goto L547;
	}
	crit[1] = seg[i__ + 3799];
	crit[6] = (real) i__;
L547:
	for (k = 3; k <= 5; ++k) {
	    if (seg[i__ + (k + 18) * 200 - 201] < crit[k - 1]) {
		goto L548;
	    }
	    crit[k - 1] = seg[i__ + (k + 18) * 200 - 201];
	    crit[k + 4] = (real) i__;
L548:
	    ;
	}
/* L549: */
    }
/* --- CALCULATE MAX RADIAL DENSITY FOR FLUX AT CORE LEG */
    kexit = 1;
    brleg = 0.f;
    k = 1;
    goto L508;
L552:
    if (bhabs > brleg) {
	brleg = bhabs;
    }
L553:
    k += nocol << 1;
    if (k <= i5) {
	goto L508;
    }
    if (kexit == 2) {
	goto L556;
    }
/* --- CALCULATE MAX RADIAL DENSITY FOR FLUX AT TANK */
    kexit = 2;
    brtnk = 0.f;
    k = nocol << 1;
    goto L508;
L554:
    if (bhabs > brtnk) {
	brtnk = bhabs;
    }
    goto L553;
/* --- LOSSES APPLIED TO THE WHOLE TRANSFORMER */
L556:
    e1 = limbs / fract;
    edwnd *= e1;
    edtnk *= e1;
    edleg *= e1;
    edyok *= e1;
    edtot *= e1;
    dctot *= e1;
/* --- WRITE OUTPUT */
    i__2 = nseg;
    for (i__ = 1; i__ <= i__2; ++i__) {
	e1 = seg[i__ + 2399] * 1e3f / vturn;
	if (seg[i__ + 2999] >= 9.9e9f) {
	    seg[i__ + 2999] = 0.f;
	}
	io___235.ciunit = out;
	s_wsfe(&io___235);
	do_fio(&outmet_c__1, (char *)&seg[i__ - 1], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&e1, (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 2399], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 2599], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 2799], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 4599], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 2999], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 4799], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 3199], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 3399], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 4999], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 3599], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 5199], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 5399], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 3799], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 5599], (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&seg[i__ + 3999], (ftnlen)sizeof(real));
	e_wsfe();
	if (seg[i__ + 1599] <= 50.f) {
	    io___236.ciunit = out;
	    s_wsfe(&io___236);
	    do_fio(&outmet_c__1, (char *)&seg[i__ + 5799], (ftnlen)sizeof(real));
	    e_wsfe();
	}
	if (seg[i__ + 1599] > 50.f) {
	    io___237.ciunit = out;
	    s_wsfe(&io___237);
	    do_fio(&outmet_c__1, (char *)&seg[i__ + 5799], (ftnlen)sizeof(real));
	    e_wsfe();
	}
	j = seg[i__ + 1799];
	if (layer[j + 239] > .5f) {
	    io___238.ciunit = out;
	    s_wsfe(&io___238);
	    do_fio(&outmet_c__1, (char *)&seg[i__ + 4199], (ftnlen)sizeof(real));
	    e_wsfe();
	}
	if (layer[j + 239] < .5f) {
	    io___239.ciunit = out;
	    s_wsfe(&io___239);
	    do_fio(&outmet_c__1, (char *)&seg[i__ + 4199], (ftnlen)sizeof(real));
	    e_wsfe();
	}
/* L558: */
	io___240.ciunit = out;
	s_wsfe(&io___240);
	for (j = 36; j <= 39; ++j) {
	    do_fio(&outmet_c__1, (char *)&seg[i__ + j * 200 - 201], (ftnlen)sizeof(
		    real));
	}
	do_fio(&outmet_c__1, (char *)&seg[i__ + 4399], (ftnlen)sizeof(real));
	e_wsfe();
    }
    io___241.ciunit = out;
    s_wsfe(&io___241);
    for (i__ = 1; i__ <= 5; ++i__) {
	for (j = 1; j <= 2; ++j) {
	    do_fio(&outmet_c__1, (char *)&crit[i__ + j * 5 - 6], (ftnlen)sizeof(real)
		    );
	}
    }
    e_wsfe();
    io___242.ciunit = out;
    s_wsfe(&io___242);
    do_fio(&outmet_c__1, (char *)&vturn, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&brtnk, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&brleg, (ftnlen)sizeof(real));
    e_wsfe();
    io___243.ciunit = out;
    s_wsfe(&io___243);
    do_fio(&outmet_c__1, (char *)&mvamx, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&xpu, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&rpu, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&zpu, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&zsyst, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&ztot, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&zused, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&edwnd, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&edtnk, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&edleg, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&edyok, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&edtot, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&edpu, (ftnlen)sizeof(real));
    do_fio(&outmet_c__1, (char *)&dctot, (ftnlen)sizeof(real));
    e_wsfe();
    io___244.ciunit = out;
    s_wsfe(&io___244);
    e_wsfe();
/* --- INITIALIZE */
    fsupu = 0.f;
    fsupl = 0.f;
/* --- LOSSES REFERRED TO LAYERS AND TERMINALS */
    i__2 = nterm;
    for (i__ = 1; i__ <= i__2; ++i__) {
	e1 = 0.f;
	e2 = 0.f;
	i__1 = nlay;
	for (j = 1; j <= i__1; ++j) {
	    e3 = 0.f;
	    e4 = 0.f;
	    e6 = 0.f;
	    e8 = 0.f;
	    e9 = 0.f;
	    e10 = 0.f;
	    e11 = 0.f;
	    e12 = 0.f;
	    e13 = 0.f;
	    e14 = 0.f;
	    e15 = 0.f;
	    if (i__ != (integer) (layer[j + 119] + .1f)) {
		goto L572;
	    }
	    k1 = layer[j + 29];
	    rmn = seg[k1 + 1999] * .001f;
	    rmx = seg[k1 + 2199] * .001f;
	    zmx = seg[k1 + 399] * .001f;
	    if (j == nlay) {
		goto L559;
	    }
	    if (layer[j + 60] < layer[j + 59] + layer[j + 89] * .5f) {
		goto L562;
	    }
/* --- AXIAL SHORT CIRCUIT FORCE, UPPER SUPPORT, NEWTON */
L559:
	    e6 = fsc * seg[k1 + 6399];
	    fsupu += e6;
/* --- LOWER SUPPORT */
L562:
	    e7 = 0.f;
/* --- FIRST SEGMENT NUMBER */
	    if (j == 1) {
		k1 = 1;
	    }
	    if (j != 1) {
		k1 = (integer) (layer[j + 28] + 1.1f);
	    }
	    zmn = seg[k1 + 199] * .001f;
	    if (fract < .7f) {
		goto L564;
	    }
	    if (j == 1) {
		goto L563;
	    }
	    if (layer[j + 58] + layer[j + 88] * .5f > layer[j + 59]) {
		goto L564;
	    }
L563:
	    e7 = -fsc * seg[k1 + 6799];
	    fsupl += e7;
	    l = 0;
L564:
	    i__3 = nseg;
	    for (k = 1; k <= i__3; ++k) {
		if (seg[k - 1] > layer[j + 29]) {
		    goto L569;
		}
		if (j == 1) {
		    goto L567;
		}
		if (seg[k - 1] > layer[j + 28]) {
		    goto L567;
		}
		goto L568;
/* --- DC LOSS, KW */
L567:
		e3 += seg[k + 4799] / fract;
/* --- EDDY CURRENT LOSS, KW */
		e4 += seg[k + 5399] / fract;
		e8 += seg[k + 4999] / fract;
		e9 += seg[k + 5199] / fract;
		if (seg[k + 5799] <= e10) {
		    goto L5671;
		}
		e10 = seg[k + 5799];
		e11 = seg[k + 6999];
		e12 = seg[k + 7199];
		e13 = seg[k + 7399];
		e14 = seg[k + 7599];
L5671:
/* Computing MAX */
		r__1 = seg[k + 6199], r__2 = -seg[k + 6599];
		e16 = fsc * dmax(r__1,r__2);
		if (e16 <= e15) {
		    goto L568;
		}
		e15 = e16;
		l = k;
L568:
		;
	    }
L569:
	    io___256.ciunit = out;
	    s_wsfe(&io___256);
	    do_fio(&outmet_c__1, (char *)&j, (ftnlen)sizeof(integer));
	    e_wsfe();
	    e5 = 0.f;
/* --- EDDY CURRENT LOSS, PER UNIT */
	    if (e3 > 0.f) {
		e5 = e4 / e3;
	    }
	    io___257.ciunit = out;
	    s_wsfe(&io___257);
	    do_fio(&outmet_c__1, (char *)&e3, (ftnlen)sizeof(real));
	    do_fio(&outmet_c__1, (char *)&e8, (ftnlen)sizeof(real));
	    do_fio(&outmet_c__1, (char *)&e9, (ftnlen)sizeof(real));
	    do_fio(&outmet_c__1, (char *)&e4, (ftnlen)sizeof(real));
	    do_fio(&outmet_c__1, (char *)&e5, (ftnlen)sizeof(real));
	    e_wsfe();
	    if (seg[l + 1599] <= 50.f) {
		io___258.ciunit = out;
		s_wsfe(&io___258);
		do_fio(&outmet_c__1, (char *)&e10, (ftnlen)sizeof(real));
		do_fio(&outmet_c__1, (char *)&e11, (ftnlen)sizeof(real));
		do_fio(&outmet_c__1, (char *)&e12, (ftnlen)sizeof(real));
		do_fio(&outmet_c__1, (char *)&e13, (ftnlen)sizeof(real));
		do_fio(&outmet_c__1, (char *)&e14, (ftnlen)sizeof(real));
		e_wsfe();
	    }
	    if (seg[l + 1599] > 50.f) {
		io___259.ciunit = out;
		s_wsfe(&io___259);
		do_fio(&outmet_c__1, (char *)&e10, (ftnlen)sizeof(real));
		do_fio(&outmet_c__1, (char *)&e11, (ftnlen)sizeof(real));
		do_fio(&outmet_c__1, (char *)&e12, (ftnlen)sizeof(real));
		do_fio(&outmet_c__1, (char *)&e13, (ftnlen)sizeof(real));
		do_fio(&outmet_c__1, (char *)&e14, (ftnlen)sizeof(real));
		e_wsfe();
	    }
	    io___260.ciunit = out;
	    s_wsfe(&io___260);
	    do_fio(&outmet_c__1, (char *)&e15, (ftnlen)sizeof(real));
	    do_fio(&outmet_c__1, (char *)&l, (ftnlen)sizeof(integer));
	    e_wsfe();
	    io___261.ciunit = out;
	    s_wsfe(&io___261);
	    do_fio(&outmet_c__1, (char *)&e6, (ftnlen)sizeof(real));
	    e_wsfe();
	    if (fract > .7f) {
		io___262.ciunit = out;
		s_wsfe(&io___262);
		do_fio(&outmet_c__1, (char *)&e7, (ftnlen)sizeof(real));
		e_wsfe();
	    }
	    flink = 0.f;
	    sumd = 0.f;
	    i__3 = i5;
	    for (k = 1; k <= i__3; ++k) {
		l = outmet_itri_(&k, &outmet_c__1);
		m = outmet_itri_(&k, &outmet_c__2);
		n = outmet_itri_(&k, &outmet_c__3);
		xl = vert[l - 1];
		yl = vert[l + 29999];
		xm = vert[m - 1];
		ym = vert[m + 29999];
		xn = vert[n - 1];
		yn = vert[n + 29999];
		rc = (xl + xm + xn) / 3.f;
		zc = (yl + ym + yn) / 3.f;
		if (rc < rmn || rc > rmx || zc < zmn || zc > zmx) {
		    goto L570;
		}
		outmet_subd_(&d__, &xm, &ym, &xn, &yn, &xl, &yl);
		i__4 = l - 1;
		i__5 = l - 1;
		q__1.r = cpotr[i__4], q__1.i = cpoti[i__5];
		al.r = q__1.r, al.i = q__1.i;
		i__4 = m - 1;
		i__5 = m - 1;
		q__1.r = cpotr[i__4], q__1.i = cpoti[i__5];
		am.r = q__1.r, am.i = q__1.i;
		i__4 = n - 1;
		i__5 = n - 1;
		q__1.r = cpotr[i__4], q__1.i = cpoti[i__5];
		an.r = q__1.r, an.i = q__1.i;
		q__3.r = al.r + am.r, q__3.i = al.i + am.i;
		q__2.r = q__3.r + an.r, q__2.i = q__3.i + an.i;
		q__1.r = q__2.r / 3.f, q__1.i = q__2.i / 3.f;
		ac.r = q__1.r, ac.i = q__1.i;
		flink += d__ * rc * ac.r;
		sumd += d__;
L570:
		;
	    }
	    flink = twopi * 1.414214f * flink / sumd;
	    io___271.ciunit = out;
	    s_wsfe(&io___271);
	    do_fio(&outmet_c__1, (char *)&flink, (ftnlen)sizeof(real));
	    e_wsfe();
/* --- DC LOSS REFERRED TO TERMINAL */
	    e1 += e3 * limbs;
/* --- EDDY CURRENT LOSS REFERRED TO TERMINAL */
	    e2 += e4 * limbs;
L572:
	    ;
	}
	io___272.ciunit = out;
	s_wsfe(&io___272);
	do_fio(&outmet_c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	e5 = 0.f;
	if (e1 > 0.f) {
	    e5 = e2 / e1;
	}
	io___273.ciunit = out;
	s_wsfe(&io___273);
	do_fio(&outmet_c__1, (char *)&e1, (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&e2, (ftnlen)sizeof(real));
	do_fio(&outmet_c__1, (char *)&e5, (ftnlen)sizeof(real));
	e_wsfe();
/* --- PERCENT DEVIATION, VOLTS/TURN */
	e5 = (term[i__ + 35] - vturn) * 100.f / vturn;
	if (dabs(e5) <= 1.f) {
	    goto L573;
	}
	io___274.ciunit = out;
	s_wsfe(&io___274);
	do_fio(&outmet_c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
L573:
	io___275.ciunit = out;
	s_wsfe(&io___275);
	do_fio(&outmet_c__1, (char *)&e5, (ftnlen)sizeof(real));
	e_wsfe();
    }
/* --- END THRUSTS FROM ALL THE LAYERS, UPPER AND LOWER SUPPORTS */
    io___276.ciunit = out;
    s_wsfe(&io___276);
    do_fio(&outmet_c__1, (char *)&fsupu, (ftnlen)sizeof(real));
    e_wsfe();
    if (fract > .7f) {
	io___277.ciunit = out;
	s_wsfe(&io___277);
	do_fio(&outmet_c__1, (char *)&fsupl, (ftnlen)sizeof(real));
	e_wsfe();
    }
L998:
    if (warn == 76) {
	io___278.ciunit = out;
	s_wsfe(&io___278);
	e_wsfe();
    }
    s_wsue(&io___279);
    do_uio(&outmet_c__1, (char *)&thksh, (ftnlen)sizeof(real));
    do_uio(&outmet_c__1, (char *)&cdavg, (ftnlen)sizeof(real));
    do_uio(&outmet_c__1, (char *)&freq, (ftnlen)sizeof(real));
    e_wsue();
    o__1.oerr = 0;
    o__1.ounit = 4;
    // o__1.ofnmlen = 11;
    strcpy(fName, baseDirectory);
    strcat(fName, "SEGMENT.FIL");
    o__1.ofnm = fName;
    o__1.ofnmlen = strlen(o__1.ofnm);
    // o__1.ofnm = "SEGMENT.FIL";
    o__1.orl = 20000;
    o__1.osta = 0;
    o__1.oacc = 0;
    o__1.ofm = "FORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    i__2 = nseg;
    for (i__ = 1; i__ <= i__2; ++i__) {
	s_wsfe(&io___280);
	for (j = 1; j <= 40; ++j) {
	    do_fio(&outmet_c__1, (char *)&seg[i__ + j * 200 - 201], (ftnlen)sizeof(
		    real));
	}
	e_wsfe();
/* L999: */
    }
    cl__1.cerr = 0;
    cl__1.cunit = 1;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 2;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 3;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 4;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
} /* MAIN__ */

/* Subroutine */ int outmet_subd_(real *d__, real *xm, real *ym, real *xn, real *yn, 
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
} /* outmet_subd_ */

integer outmet_itri_(integer *i__, integer *j)
{
    /* System generated locals */
    integer ret_val = 0;

    /* Local variables */
    static logical1 a;
    static integer l, m, n;

/* --- RECREATES VALUES IN THE OLD ARRAY ITRI */
/* --- ROW NUMBER */
    m = (*i__ - 1) / ((outmet_block1_1.lnver - 1) << 1) + 1;
/* --- COLUMN NUMBER */
    n = (*i__ - 1) / 2 + outmet_block1_1.lnver - m * (outmet_block1_1.lnver - 1);
/* --- LOWER LEFT CORNER */
    l = n + (m - 1) * outmet_block1_1.lnver;
    a = bit_test(outmet_block1_1.ibit[l - 1],15);
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
	ret_val = l + outmet_block1_1.lnver + 1;
    }
    if (*j == 3) {
	ret_val = l + outmet_block1_1.lnver;
    }
    goto L200;
/* --- SECOND TRIANGLE */
L110:
    if (*j == 2) {
	ret_val = l + 1;
    }
    if (*j == 3) {
	ret_val = l + outmet_block1_1.lnver + 1;
    }
    goto L200;
/* --- REVERSED DIAGONAL */
L120:
    if (*j == 1) {
	ret_val = l + outmet_block1_1.lnver;
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
} /* outmet_itri_ */

/* Subroutine */ int outmet_angle_(real *a1, real *b1, real *d1, real *angrd, real *
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
} /* outmet_angle_ */

