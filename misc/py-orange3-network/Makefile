PORTNAME=	orange3-network
DISTVERSION=	1.5.1.20210224 # the 1.5.1 was forgotten
PORTREVISION=	4
CATEGORIES=	misc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Network analysis add-on for Orange data mining suite
WWW=		https://github.com/biolab/orange3-network

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on expiring misc/orange3
EXPIRATION_DATE=2025-06-21

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	orange3>0:misc/orange3 \
		${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}gensim>0:textproc/py-gensim@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyqtgraph>=0.9.10:graphics/py-pyqtgraph@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils cython autoplist

USE_GITHUB=	yes
GH_ACCOUNT=	biolab
GH_TAGNAME=	ec534c9

.include <bsd.port.mk>
