PORTNAME=	openttd
DISTVERSION=	14.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://cdn.openttd.org/openttd-releases/${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-source

PATCH_SITES=	https://github.com/OpenTTD/OpenTTD/commit/
PATCHFILES=	db36e61807955c896267d6585de0577efd30465d.patch:-p1 \
		14fac2ad37bfb9cec56b4f9169d864f6f1c7b96e.patch:-p1

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Open source clone of Microprose Transport Tycoon Deluxe
WWW=		https://www.openttd.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		liblzo2.so:archivers/lzo2 \
		libpng.so:graphics/png

USES=		cmake compiler:c++17-lang cpe pkgconfig tar:xz
CMAKE_ARGS=	-DCMAKE_INSTALL_BINDIR:PATH=bin \
		-DCMAKE_INSTALL_DATADIR:PATH=share

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

OPTIONS_DEFINE=	DOCS FLUIDSYNTH SAVE_PASSWORDS SDL1 SERVER
SERVER_PREVENTS=	FLUIDSYNTH

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_CMAKE_ON=	-DWITH_FLUIDSYNTH:BOOL=ON

SAVE_PASSWORDS_DESC=	Save passwords between server restarts
SAVE_PASSWORDS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-save-passwords

SDL1_DESC=	Use SDL v1.2 instead of v2 for GUI
SDL1_VARS=	_SDL_VERSION=sdl
SDL1_CMAKE_OFF=	-DWITH_SDL2:BOOL=ON
SDL1_VARS_OFF=	_SDL_VERSION=sdl2

SERVER_DESC=		Build dedicated server only (no GUI)
SERVER_USES_OFF=	sdl
SERVER_USE_OFF=		SDL=${_SDL_VERSION}
SERVER_CMAKE_ON=	-DOPTION_DEDICATED:BOOL=ON
SERVER_LIB_DEPENDS_OFF=	libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2 \
			libharfbuzz.so:print/harfbuzz \
			libicui18n.so:devel/icu
SERVER_VARS=		USE_RC_SUBR=${PORTNAME}

post-install-SERVER-on:
	@${REINPLACE_CMD} -E '/\.desktop|icons|pixmaps/d' ${TMPPLIST}

do-test:
	@cd ${TEST_WRKSRC} && ctest -C ${CMAKE_BUILD_TYPE} ${_MAKE_JOBS}

.include <bsd.port.mk>
