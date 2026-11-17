PORTNAME=	freebsd_exfat
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	filesystems

MAINTAINER=	tkusumi@netbsd.org
COMMENT=	exFAT file system for FreeBSD
WWW=		https://github.com/gensrc/freebsd_exfat

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	gensrc
GH_PROJECT=	freebsd_exfat

do-install:
	${INSTALL_KLD} ${WRKSRC}/src/sys/fs/exfat/exfat.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_MAN} ${WRKSRC}/src/share/man/man4/exfat.4 ${STAGEDIR}${PREFIX}/share/man/man4
	${INSTALL_PROGRAM} ${WRKSRC}/src/sbin/newfs_exfat/newfs_exfat ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/sbin/mount_exfat/mount_exfat ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/sbin/fsck_exfat/fsck_exfat ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/src/sbin/newfs_exfat/newfs_exfat.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/src/sbin/mount_exfat/mount_exfat.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/src/sbin/fsck_exfat/fsck_exfat.8 ${STAGEDIR}${PREFIX}/share/man/man8

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/newfs_exfat
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/mount_exfat
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/fsck_exfat

.include <bsd.port.mk>
