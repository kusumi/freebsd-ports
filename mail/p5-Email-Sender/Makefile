PORTNAME=	Email-Sender
DISTVERSION=	2.601
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:RJBS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Library for sending email
WWW=		https://metacpan.org/release/Email-Sender

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-Abstract>=3.006:mail/p5-Email-Abstract \
		p5-Email-Address-XS>=0:mail/p5-Email-Address-XS \
		p5-Email-Simple>=1.998:mail/p5-Email-Simple \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Module-Runtime>=0:devel/p5-Module-Runtime \
		p5-Moo>=2.000000:devel/p5-Moo \
		p5-MooX-Types-MooseLike>=0.15:devel/p5-MooX-Types-MooseLike \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Throwable>=0.200003:devel/p5-Throwable \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny
TEST_DEPENDS=	p5-Capture-Tiny>=0.08:devel/p5-Capture-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
