PORTNAME=	tinyows
PORTVERSION=	1.2.0
PORTREVISION=	5
CATEGORIES=	graphics www geography
MASTER_SITES=	https://download.osgeo.org/mapserver/

MAINTAINER=	joris.dedieu@gmail.com
COMMENT=	High Performance WFS-T server
WWW=		https://mapserver.org/tinyows/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Depends on expired databases/postgis31
EXPIRATION_DATE=2025-02-01

BUILD_DEPENDS=	${LOCALBASE}/share/postgresql/extension/postgis.control:databases/postgis31
RUN_DEPENDS=	${LOCALBASE}/share/postgresql/extension/postgis.control:databases/postgis31

USES=		autoreconf gnome pgsql
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	FASTCGI
OPTIONS_DEFAULT=FASTCGI

FASTCGI_LIB_DEPENDS=	libfcgi.so:www/fcgi
FASTCGI_CONFIGURE_WITH=	fastcgi=${LOCALBASE}

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}/cgi-bin/
	${INSTALL_PROGRAM} ${WRKSRC}/tinyows ${STAGEDIR}${WWWDIR}/cgi-bin/tinyows

.include <bsd.port.mk>
