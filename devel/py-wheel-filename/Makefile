PORTNAME=	wheel-filename
PORTVERSION=	1.4.2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	wheel_filename-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Parse wheel filenames
WWW=		https://github.com/wheelodex/wheel-filename

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
