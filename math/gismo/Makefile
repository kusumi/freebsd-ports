PORTNAME=	gismo
DISTVERSIONPREFIX=	v
DISTVERSION=	24.08.0
CATEGORIES=	math # geometry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for isogeometric analysis (IGA)
WWW=		https://gismo.github.io/ \
		https://github.com/gismo/gismo

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_FreeBSD_15=	compilation is broken with clang-19, see https://github.com/gismo/gismo/issues/741

USES=		cmake:testing compiler:c++14-lang
USE_GITHUB=	yes
USE_LDCONFIG=	yes

CMAKE_TESTING_ON=	GISMO_BUILD_UNITTESTS # one test is known to fail: https://github.com/gismo/gismo/issues/466

CXXFLAGS_powerpc64=	-mvsx

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64
CMAKE_ARGS+=	-DTARGET_ARCHITECTURE="cortex-a53"
.elif ${ARCH} == armv6
# Raspberry Pi 1, the only supported armv6 target
CMAKE_ARGS+=	-DTARGET_ARCHITECTURE="arm1176jzf-s"
.elif ${ARCH} == armv7
CMAKE_ARGS+=	-DTARGET_ARCHITECTURE="cortex-a7"
.endif

.include <bsd.port.post.mk>
