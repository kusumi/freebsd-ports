PORTNAME=	dijo
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.7
PORTREVISION=	23
CATEGORIES=	misc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Scriptable, curses-based, digital habit tracker
WWW=		https://github.com/NerdyPepper/dijo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	NerdyPepper

CARGO_CRATES=	ahash-0.6.3 \
		ansi_term-0.11.0 \
		array-macro-1.0.5 \
		arrayref-0.3.6 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		base64-0.13.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.11 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		constant_time_eq-0.1.5 \
		crossbeam-channel-0.5.0 \
		crossbeam-utils-0.8.1 \
		crossterm-0.19.0 \
		crossterm_winapi-0.7.0 \
		ctor-0.1.17 \
		cursive-0.16.3 \
		cursive_core-0.2.2 \
		darling-0.10.2 \
		darling_core-0.10.2 \
		darling_macro-0.10.2 \
		directories-3.0.1 \
		dirs-sys-0.3.5 \
		enum-map-0.6.4 \
		enum-map-derive-0.4.6 \
		erased-serde-0.3.13 \
		filetime-0.2.13 \
		fnv-1.0.7 \
		fsevent-0.4.0 \
		fsevent-sys-2.0.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		getrandom-0.1.16 \
		getrandom-0.2.1 \
		ghost-0.1.2 \
		hermit-abi-0.1.17 \
		ident_case-1.0.1 \
		inotify-0.7.1 \
		inotify-sys-0.1.4 \
		instant-0.1.9 \
		inventory-0.1.10 \
		inventory-impl-0.1.10 \
		iovec-0.1.4 \
		itoa-0.4.7 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.82 \
		lock_api-0.4.2 \
		log-0.4.11 \
		mio-0.6.23 \
		mio-0.7.7 \
		mio-extras-2.0.6 \
		miow-0.2.2 \
		miow-0.3.6 \
		net2-0.2.37 \
		notify-4.0.15 \
		ntapi-0.3.6 \
		num-0.3.1 \
		num-complex-0.3.1 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.3.2 \
		num-traits-0.2.14 \
		numtoa-0.1.0 \
		once_cell-1.5.2 \
		owning_ref-0.4.1 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.2 \
		proc-macro2-1.0.24 \
		quote-1.0.8 \
		redox_syscall-0.1.57 \
		redox_termios-0.1.1 \
		redox_users-0.3.5 \
		rust-argon2-0.8.3 \
		ryu-1.0.5 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		serde-1.0.118 \
		serde_derive-1.0.118 \
		serde_json-1.0.61 \
		signal-hook-0.1.17 \
		signal-hook-0.3.4 \
		signal-hook-registry-1.3.0 \
		slab-0.4.2 \
		smallvec-1.6.1 \
		socket2-0.3.19 \
		stable_deref_trait-1.2.0 \
		strsim-0.8.0 \
		strsim-0.9.3 \
		syn-1.0.57 \
		termion-1.5.5 \
		textwrap-0.11.0 \
		time-0.1.43 \
		toml-0.5.8 \
		typetag-0.1.6 \
		typetag-impl-0.1.6 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		walkdir-2.3.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.1+wasi-snapshot-preview1 \
		wasmer_enumset-1.0.1 \
		wasmer_enumset_derive-0.5.0 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1 \
		xi-unicode-0.3.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
