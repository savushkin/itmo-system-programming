dnl $FreeBSD: releng/10.3/usr.bin/m4/tests/esyscmd.m4 234852 2012-04-30 22:00:34Z bapt $
changequote(`{',`}')dnl
dnl
esyscmd({sh -c "m4<<EOF
define(_bp,hi there a)
define(_comb,
_bp($1$2)
_bp($2$1)
)
define(bp,
_comb(aaaa,foo0)
_comb(bbbb,foo0)
_comb(cccc,foo0)
_comb(dddd,foo0)
_comb(aaaa,foo0)
_comb(bbbb,foo0)
_comb(cccc,foo0)
_comb(dddd,foo0)
)
bp(a00)
bp(b00)
bp(c00)
bp(d00)
bp(e00)
bp(f00)
bp(g00)
bp(h00)
bp(i00)
bp(j00)
bp(k00)
bp(l00)
bp(m00)
bp(n00)
bp(o00)
bp(p00)
bp(q00)
bp(r00)
bp(s00)
bp(t00)
bp(u00)
bp(v00)
bp(w00)
EOF"})dnl
