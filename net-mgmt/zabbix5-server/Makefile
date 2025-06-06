PORTNAME=	zabbix5
DISTVERSION=	5.0.47
PORTREVISION?=	0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://cdn.zabbix.com/zabbix/sources/stable/${DISTVERSION:R}/
PKGNAMESUFFIX?=	-server
DISTNAME=	zabbix-${DISTVERSION}

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Enterprise-class open source distributed monitoring (${PKGNAMESUFFIX:S/^-//}) LTS
WWW=		https://www.zabbix.com/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Upstream EOL reaches on 2025-05-31
EXPIRATION_DATE=	2025-06-30

LIB_DEPENDS=	libpcre.so:devel/pcre

CONFLICTS_INSTALL=	zabbix[0-9][0-9]${PKGNAMESUFFIX} zabbix[0-46-9]${PKGNAMESUFFIX}

PORTSCOUT=	limit:^5\.0\.

ZABBIX_BUILD=	${PKGNAMESUFFIX:S/^-//}

.if ${ZABBIX_BUILD} != "agent"
CONFIGURE_ARGS+=	--with-libevent=${LOCALBASE} --cache-file=${WRKSRC}/config.cache
LIB_DEPENDS+=	libevent.so:devel/libevent
USE_RC_SUBR=	zabbix_${ZABBIX_BUILD}
.else
USE_RC_SUBR=	zabbix_${ZABBIX_BUILD}d
.endif

USES=		pkgconfig iconv

USERS=		zabbix
GROUPS=		zabbix

.if ${ZABBIX_BUILD} != "proxy"
PLIST_SUB=	PROXY="@comment "
.else
PLIST_SUB=	PROXY=""
.endif

.if ${ZABBIX_BUILD} == "server"
PLIST_SUB+=	SERVER=""
.else
PLIST_SUB+=	SERVER="@comment "
.endif

PLIST_SUB+=	ZABBIX_BUILD=${ZABBIX_BUILD} DISTVERSION=${DISTVERSION}
SUB_LIST=	ZABBIX_BUILD=${ZABBIX_BUILD}

MAKE_ARGS+=	ARCH=freebsd
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS+=	--enable-${ZABBIX_BUILD} \
			--sysconfdir=${ETCDIR} \
			--datadir=${ETCDIR} \
			--with-iconv=${ICONV_PREFIX}

.if ${ZABBIX_BUILD} == "java"
USES+=		java
.endif

.if ${ZABBIX_BUILD} != "agent" && ${ZABBIX_BUILD} != "java"
CPPFLAGS+=	-I${LOCALBASE}/include

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		IPV6 FPING CURL LDAP IPMI SNMP SSH NMAP LIBXML2 UNIXODBC

OPTIONS_DEFAULT=	IPV6 FPING CURL SNMP SSH LIBXML2 MYSQL OPENSSL UNIXODBC
OPTIONS_SUB=		yes

FPING_DESC=		Build/install fping for ping checks
IPMI_DESC=		Support for IPMI checks
LDAP_DESC=		Support for LDAP server checks
NMAP_DESC=		Build/install nmap for o/s detection
SNMP_DESC=		Support for SNMP checks
SSH_DESC=		Support for SSH-based checks
UNIXODBC_DESC=		Support for database checks via ODBC
LIBXML2_DESC=		Support for libxml2 (required by monitoring VMware)

OPTIONS_SINGLE=		DB SSL
OPTIONS_SINGLE_DB?=	MYSQL PGSQL ORACLE
OPTIONS_SINGLE_SSL=	OPENSSL GNUTLS

MYSQL_CONFIGURE_WITH=	mysql
MYSQL_USES+=		compiler:c11 mysql

PGSQL_CONFIGURE_WITH=	postgresql
PGSQL_USES+=		pgsql

SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
SNMP_CONFIGURE_WITH=	net-snmp

SQLITE_CONFIGURE_WITH=	sqlite3
SQLITE_USES+=		sqlite:3

ORACLE_CONFIGURE_WITH=	oracle

LDAP_CONFIGURE_WITH=	ldap
LDAP_USES=		ldap

IPMI_CONFIGURE_WITH=	openipmi
IPMI_LIB_DEPENDS=	libOpenIPMI.so:sysutils/openipmi

FPING_RUN_DEPENDS=	fping:net/fping

SSH_CONFIGURE_WITH=	ssh2
SSH_LIB_DEPENDS=	libssh2.so:security/libssh2

UNIXODBC_CONFIGURE_WITH=unixodbc
UNIXODBC_LIB_DEPENDS=	libodbc.so:databases/unixODBC
.elif ${ZABBIX_BUILD} == "agent"
OPTIONS_SINGLE=	SSL
OPTIONS_SINGLE_SSL=	OPENSSL GNUTLS
.endif # if ${ZABBIX_BUILD} != "agent" && ${ZABBIX_BUILD} != "java"

CURL_DESC=		Support for web monitoring
CURL_CONFIGURE_WITH=	libcurl
CURL_LIB_DEPENDS=	libcurl.so:ftp/curl

IPV6_CONFIGURE_ENABLE=	ipv6

NMAP_RUN_DEPENDS=	nmap:security/nmap \
			sudo:security/sudo

LIBXML2_CONFIGURE_WITH=	libxml2=${LOCALBASE}
LIBXML2_LIB_DEPENDS=	libxml2.so:textproc/libxml2

OPENSSL_CONFIGURE_WITH=	openssl
OPENSSL_USES=		ssl
OPENSSL_VARS=		BROKEN_SSL="libressl libressl-devel" \
			BROKEN_SSL_REASON="PSK is not provided by LibreSSL"

GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -rl "/etc/zabbix" ${WRKSRC} \
	  | ${XARGS} ${REINPLACE_CMD} -e 's#/usr/local/etc#${ETCDIR}#g'

	@${REINPLACE_CMD} -e 's#/usr/sbin/fping#${LOCALBASE}/sbin/fping#g' \
		${WRKSRC}/conf/zabbix_*.conf \
		${WRKSRC}/src/zabbix_proxy/proxy.c \
		${WRKSRC}/src/zabbix_server/server.c

.if ${ZABBIX_BUILD} == "server"
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_server.pid#/var/run/zabbix/zabbix_server.pid#g' \
		${WRKSRC}/conf/zabbix_server.conf \
		${WRKSRC}/src/zabbix_server/server.c
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_server.log#/var/log/zabbix/zabbix_server.log#g' \
		${WRKSRC}/conf/zabbix_server.conf
.endif

.if ${ZABBIX_BUILD} == "proxy"
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_proxy.pid#/var/run/zabbix/zabbix_proxy.pid#g' \
		${WRKSRC}/conf/zabbix_proxy.conf \
		${WRKSRC}/src/zabbix_proxy/proxy.c
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_proxy.log#/var/log/zabbix/zabbix_proxy.log#g' \
		${WRKSRC}/conf/zabbix_proxy.conf
.endif

.if ${ZABBIX_BUILD} == "agent"
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_agentd.pid#/var/run/zabbix/zabbix_agentd.pid#g' \
		${WRKSRC}/conf/zabbix_agentd.conf \
		${WRKSRC}/src/zabbix_agent/zabbix_agentd.c
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_agentd.log#/var/log/zabbix/zabbix_agentd.log#g' \
		${WRKSRC}/conf/zabbix_agentd.conf
.endif

.if ${ZABBIX_BUILD} == "java"
	@${REINPLACE_CMD} -e 's#/tmp/zabbix_java.pid#/var/run/zabbix/zabbix_java.pid#g' \
		${WRKSRC}/src/zabbix_java/settings.sh
.endif

.if ${ZABBIX_BUILD} != "agent"
.  for d in mysql oracle postgresql sqlite3
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/traceroute|/usr/sbin/traceroute|g' \
		-e 's|sudo /usr/bin/nmap|sudo ${LOCALBASE}/bin/nmap|g' \
		${WRKSRC}/database/${d}/data.sql
.  endfor
.endif
	@${FIND} ${WRKSRC} -type f \( -name '*.bak' -or -name '*.orig' \) \
		-exec ${RM} {} +

pre-configure:
	@echo "ac_cv_env_PKG_CONFIG_set=${LOCALBASE}/bin/pkgconf" > ${WRKSRC}/config.cache

post-install:
.if ${ZABBIX_BUILD} == "java"
	${MV} ${STAGEDIR}${PREFIX}/sbin/zabbix_java/settings.sh \
		${STAGEDIR}${PREFIX}/sbin/zabbix_java/settings.sh.sample
	@${MKDIR} ${STAGEDIR}/var/run/zabbix
.endif

.if ${ZABBIX_BUILD} != "agent" && ${ZABBIX_BUILD} != "java"
	${MKDIR} ${STAGEDIR}${DATADIR}/${ZABBIX_BUILD:Q}/database
	@${RM} ${WRKSRC}/database/*/Makefile*
	(cd ${WRKSRC}/database/ && \
		${COPYTREE_SHARE} "mysql oracle postgresql sqlite3" \
		${STAGEDIR}${DATADIR}/${ZABBIX_BUILD:Q}/database/)

	${MV} ${STAGEDIR}${ETCDIR}/zabbix_${ZABBIX_BUILD}.conf \
		${STAGEDIR}${ETCDIR}/zabbix_${ZABBIX_BUILD}.conf.sample
.endif

.if ${ZABBIX_BUILD} == "agent"
	${MV} ${STAGEDIR}${ETCDIR}/zabbix_${ZABBIX_BUILD}d.conf \
		${STAGEDIR}${ETCDIR}/zabbix_${ZABBIX_BUILD}d.conf.sample
.endif

.if ${ZABBIX_BUILD} == "proxy"
	${MV} ${STAGEDIR}${LOCALBASE}/bin/zabbix_js \
		${STAGEDIR}${LOCALBASE}/bin/zabbix_proxy_js
.endif

.include <bsd.port.post.mk>
