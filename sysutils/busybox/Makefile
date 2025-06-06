PORTNAME=	busybox
PORTVERSION=	1.37.0
CATEGORIES=	sysutils misc shells
MASTER_SITES=	https://busybox.net/downloads/

MAINTAINER=	samm@FreeBSD.org
COMMENT=	Set of common utilities built as single binary
WWW=		https://www.busybox.net/

LICENSE=	GPLv2

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		cpe gmake perl5 tar:bzip2
USE_PERL5=	build

OPTIONS_DEFINE=	DOCS STATIC
STATIC_LDFLAGS=	-static

PIE_UNSAFE=	yes

.include <bsd.port.options.mk>
# fix ash crash on arm, see shell/ash.c
.if ${ARCH} == "armv6"
CFLAGS+=	-DBB_GLOBAL_CONST=''
.endif
.if ${ARCH} == "i386"
# clang doesn't swallow some inline assembly
USE_GCC=	yes
.endif

MAKE_ARGS=	CC="${CC}" HOSTCC="${CC}" CXX="${CXX}" HOSTCXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		SKIP_STRIP=y V=1
PLIST_FILES=	bin/busybox share/man/man1/busybox.1.gz
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e \
		's|\([[:<:]]\)sed\([[:blank:]]-n\)|\1gsed\2|' \
		${WRKSRC}/scripts/gen_build_files.sh
	@${FIND} ${WRKSRC} -name "*.c" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|<alloca.h>|<stdlib.h>| ; \
		 s|<malloc.h>|<stdlib.h>|'
	@${FIND} ${WRKSRC} -name "*.[ch]" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|"/proc|"/compat/linux/proc|'

do-configure:
	@${CP} ${FILESDIR}/data-.config ${WRKSRC}/.config
	@(cd ${WRKSRC} && ${DO_MAKE_BUILD} oldconfig)

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} busybox \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/docs && ${INSTALL_MAN} busybox.1 \
		${STAGEDIR}${PREFIX}/share/man/man1)

post-install-DOCS-on:
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR} "! -name busybox.1")

.include <bsd.port.mk>
