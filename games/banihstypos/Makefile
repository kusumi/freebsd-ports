PORTNAME=	banihstypos
PORTVERSION=	0.2
CATEGORIES=	games
MASTER_SITES=	http://www.vanheusden.com/banihstypos/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple game to teach you typing, fast
WWW=		http://www.vanheusden.com/banihstypos/

USES=		ncurses tar:tgz
MAKE_ARGS=	LDFLAGS="${LDFLAGS} -lncurses"
SUB_FILES=	pkg-message
SUB_LIST=	PORTNAME=${PORTNAME}

PLIST_FILES=	bin/banihstypos

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
PORTDOCS=	readme.txt
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/banihstypos ${STAGEDIR}${PREFIX}/bin
.if ! ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
