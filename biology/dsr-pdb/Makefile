PORTNAME=	dsr-pdb
DISTVERSION=	1.0.3
PORTREVISION=	16
CATEGORIES=	biology
MASTER_SITES=	https://graphics.stanford.edu/~drussel/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Simple C++ PDB reader (reads the protein description format)
WWW=		https://graphics.stanford.edu/~drussel/pdb/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BROKEN_aarch64=	ld: error: undefined symbol: .mcount (see bug#262709)

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USES=		compiler:c++11-lang gmake libtool localbase:ldflags tar:tgz
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CXXFLAGS+=	-fPIC --std=c++11 # libboost_program_options.so isn't found without --std=c++11

post-patch:
.for dir in lib tools test
	@cd ${WRKSRC}/${dir} && ${LN} -s ../ dsrpdb
.endfor

post-build: # the project itself doesn't support shared libraries in a regular way
	@cd ${WRKSRC}/lib && ${CXX} ${LDFLAGS} --shared -Wl,-soname,libdsrpdb.so -o libdsrpdb.so *.o

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.h ${STAGEDIR}${PREFIX}/include/dsrpdb
	${INSTALL_LIB} ${WRKSRC}/lib/libdsrpdb.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
