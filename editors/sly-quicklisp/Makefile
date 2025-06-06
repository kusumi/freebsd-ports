PORTNAME=	sly-quicklisp
PORTVERSION=	20211206
PORTREVISION=	6
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	olce.freebsd.ports@certner.fr
COMMENT=	Basic Quicklisp support for SLY
WWW=		https://github.com/joaotavora/sly-quicklisp

LICENSE=	PD

MY_DEPENDS=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/sly/sly.el:editors/sly@${EMACS_FLAVOR}
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	joaotavora
GH_TAGNAME=	34c73d43dd9066262387c626c17a9b486db07b2d

NO_ARCH=	yes

EMACS_COMPILE=	${EMACS_CMD} --batch --no-site-file -L ${WRKSRC} -f batch-byte-compile

PLIST_THIS_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
THIS_LISPDIR=		${PREFIX}/${PLIST_THIS_LISPDIR}
PLIST_SUB+=		THIS_LISPDIR=${PLIST_THIS_LISPDIR}

# File is buggy and can't be used as documented upstream
EXCLUDED_FILES=	${PORTNAME}-autoloads.el

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md screenshot.png

do-build:
	cd ${WRKSRC} && ${EMACS_COMPILE} sly-*.el

do-install:
	@${MKDIR} ${STAGEDIR}${THIS_LISPDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${THIS_LISPDIR} \
		"! ( -depth 1 ( ${EXCLUDED_FILES:C/^(.*)$/-name \1 -o/} \
			${PORTDOCS:C/^(.*)$/-name \1 -o/} \
			-name LICENSE -o -name *\.md -o -name \.[^.]* ) )")

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:%=${WRKSRC}/%} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
