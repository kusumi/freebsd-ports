PORTNAME=	redis-actionpack
PORTVERSION=	5.5.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Redis session store for ActionPack
WWW=		https://redis-store.org/redis-actionpack/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack5>=5:www/rubygem-actionpack5 \
		rubygem-redis-rack>=2.1.0<4:www/rubygem-redis-rack \
		rubygem-redis-store>=1.1.0<2:devel/rubygem-redis-store

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
