PORTNAME=	Net-Curl
PORTVERSION=	0.52
PORTREVISION=	1
CATEGORIES=	www ftp perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrew.fengler@scaleengine.com
COMMENT=	Perl interface for libcurl
WWW=		https://search.cpan.org/dist/Net-Curl/

LICENSE=	MIT

BROKEN=		Fails to build with curl 8.11.0
EXPIRATION_DATE=2025-02-28

LIB_DEPENDS=	libcurl.so:ftp/curl
BUILD_DEPENDS=	p5-ExtUtils-PkgConfig>=1.16:devel/p5-ExtUtils-PkgConfig

USES=		perl5 localbase
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/Curl/Curl.so

.include <bsd.port.mk>
