#pragma once

#include <boost/predef/architecture.h>
#include <boost/predef/os.h>
#include <boost/predef/platform.h>
#include <boost/predef/compiler.h>

//
// Macros for Processor Architecture detection:
//
//   - yARCH_ALPHA    -> DEC Alpha architecture
//   - yARCH_ARM      -> ARM architecture
//   - yARCH_BLACKFIN -> Blackfin Processors from Analog Devices
//   - yARCH_CONVEX   -> Convex Computer architecture
//   - yARCH_IA64     -> Intel Itanium 64 architecture
//   - yARCH_M68K     -> Motorola 68k architecture
//   - yARCH_MIPS     -> MIPS architecture
//   - yARCH_PARISC   -> HP/PA RISC architecture
//   - yARCH_PPC      -> PowerPC architecture
//   - yARCH_PYRAMID  -> Pyramid 9810 architecture
//   - yARCH_RS6000   -> RS/6000 architecture
//   - yARCH_SPARC    -> SPARC architecture
//   - yARCH_SH       -> SuperH architecture
//   - yARCH_SYS370   -> System/370 architecture
//   - yARCH_SYS390   -> System/390 architecture
//   - yARCH_X86      -> Intel x86 architecture
//   - yARCH_Z        -> z/Architecture architecture
//

#if defined(BOOST_ARCH_ALPHA_AVAILABLE)
#  define yARCH_ALPHA
#endif
#if defined(BOOST_ARCH_ARM_AVAILABLE)
#  define yARCH_ARM
#endif
#if defined(BOOST_ARCH_BLACKFIN_AVAILABLE)
#  define yARCH_BLACKFIN
#endif
#if defined(BOOST_ARCH_CONVEX_AVAILABLE)
#  define yARCH_CONVEX
#endif
#if defined(BOOST_ARCH_IA64_AVAILABLE)
#  define yARCH_IA64
#endif
#if defined(BOOST_ARCH_M68K_AVAILABLE)
#  define yARCH_M68K
#endif
#if defined(BOOST_ARCH_MIPS_AVAILABLE)
#  define yARCH_MIPS
#endif
#if defined(BOOST_ARCH_PARISC_AVAILABLE)
#  define yARCH_PARISC
#endif
#if defined(BOOST_ARCH_PPC_AVAILABLE)
#  define yARCH_PPC
#endif
#if defined(BOOST_ARCH_PYRAMID_AVAILABLE)
#  define yARCH_PYRAMID
#endif
#if defined(BOOST_ARCH_RS6000_AVAILABLE)
#  define yARCH_RS6000
#endif
#if defined(BOOST_ARCH_SPARC_AVAILABLE)
#  define yARCH_SPARC
#endif
#if defined(BOOST_ARCH_SH_AVAILABLE)
#  define yARCH_SH
#endif
#if defined(BOOST_ARCH_SYS370_AVAILABLE)
#  define yARCH_SYS370
#endif
#if defined(BOOST_ARCH_SYS390_AVAILABLE)
#  define yARCH_SYS390
#endif
#if defined(BOOST_ARCH_X86_AVAILABLE)
#  define yARCH_X86
#endif
#if defined(BOOST_ARCH_Z_AVAILABLE)
#  define yARCH_Z
#endif

#if !defined(yARCH_ALPHA) && !defined(yARCH_ARM) && !defined(yARCH_BLACKFIN) && !defined(yARCH_CONVEX) &&\
    !defined(yARCH_IA64) && !defined(yARCH_M68K) && !defined(yARCH_MIPS) && !defined(yARCH_PARISC) &&\
    !defined(yARCH_PPC) && !defined(yARCH_PYRAMID) && !defined(yARCH_RS6000) && !defined(yARCH_SPARC) &&\
    !defined(yARCH_SH) && !defined(yARCH_SYS370) && !defined(yARCH_SYS390) && !defined(yARCH_X86) &&\
    !defined(yARCH_Z)
// Test if we detect a processor otherwise print error message.
#  if !defined(yAVOID_CONFIG_WARNINGS)
#    pragma warning "Unknown processor architecture, please contact the team! (Defined yAVOID_CONFIG_WARNINGS to avoid this message)"
#  endif
#endif

//
// Macros for Endianness detection:
//
//   - yBIG_ENDIAN    -> Big Endian
//   - yLITTLE_ENDIAN -> Little Endian
//   - yBYTE_ORDER    -> Processor Architecture Byte Order (if is equal to yBIG_ENDIAN then is a big endian order,
//                                                          otherwise is a little endian order)
//

#if defined(__ORDER_BIG_ENDIAN__)
#  define yBIG_ENDIAN __ORDER_BIG_ENDIAN__
#else
#  define yBIG_ENDIAN 4321
#endif
#if defined(__ORDER_LITTLE_ENDIAN__)
#  define yLITTLE_ENDIAN __ORDER_LITTLE_ENDIAN__
#else
#  define yLITTLE_ENDIAN 1234
#endif

#if defined(__ARMEB__) || defined(__THUMBEB__) || defined(__AARCH64EB__) || defined(_MIPSEB) ||\
    defined(__MIPSEB) || defined(__MIPSEB__)
#  define yBYTE_ORDER yBIG_ENDIAN
#elif defined(__ARMEL__) || defined(__THUMBEL__) || defined(__AARCH64EL__) || defined(_MIPSEL) ||\
      defined(__MIPSEL) || defined(__MIPSEL__)
#  define yBYTE_ORDER yLITTLE_ENDIAN
#endif

#if !defined(yBYTE_ORDER)
#  if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == Q_BIG_ENDIAN || __BYTE_ORDER__ == Q_LITTLE_ENDIAN)
#    define yBYTE_ORDER __BYTE_ORDER
#  elif defined(__BIG_ENDIAN__) || defined(_big_endian__) || defined(_BIG_ENDIAN)
#    define yBYTE_ORDER yBIG_ENDIAN
#  elif defined(__LITTLE_ENDIAN__) || defined(_little_endian__) || defined(_LITTLE_ENDIAN)\
        || defined(WINAPI_FAMILY) // WinRT is always little-endian!
#    define yBYTE_ORDER yLITTLE_ENDIAN
#  else
#    if !defined(yAVOID_CONFIG_WARNINGS)
#      pragma warning "Unable to determine byte order, please contact the team! (Defined yAVOID_CONFIG_WARNINGS to avoid this message)"
#    endif
#  endif
#endif

// 
// Macros for Operating System detection:
// 
//   - yOS_AIX     -> IBM AIX operating system
//   - yOS_AMIGAOS -> AmigaOS operating system
//   - yOS_ANDROID -> Android operating system
//   - yOS_BEOS    -> BeOS operating system
//   - yOS_BSD     -> BSD operating system
//   - yOS_CYGWIN  -> Cygwin evironment
//   - yOS_HAIKU   -> Haiku operating system
//   - yOS_HPUX    -> HP-UX operating system
//   - yOS_IOS     -> iOS operating system
//   - yOS_IRIX    -> IRIX operating system
//   - yOS_LINUX   -> Linux operating system
//   - yOS_MACOS   -> Mac OS operating system
//   - yOS_OS400   -> IBM OS/400 operating system
//   - yOS_QNX     -> QNX operating system
//   - yOS_SOLARIS -> Solaris operating system
//   - yOS_UNIX    -> Unix Environment operating system
//   - yOS_SVR4    -> SVR4 Environment operating system
//   - yOS_VMS     -> VMS operating system
//   - yOS_BSDI    -> BSDi BSD/OS operating system
//   - yOS_WINDOWS -> Microsoft Windows operating system
// 

#if defined(BOOST_OS_AIX_AVAILABLE)
#  define yOS_AIX
#endif
#if defined(BOOST_OS_AMIGAOS_AVAILABLE)
#  define yOS_AMIGAOS
#endif
#if defined(BOOST_OS_ANDROID_AVAILABLE)
#  define yOS_ANDROID
#endif
#if defined(BOOST_OS_BEOS_AVAILABLE)
#  define yOS_BEOS
#endif
#if defined(BOOST_OS_BSD_AVAILABLE)
#  define yOS_BSD
#endif
#if defined(BOOST_OS_CYGWIN_AVAILABLE)
#  define yOS_CYGWIN
#endif
#if defined(BOOST_OS_HAIKU_AVAILABLE)
#  define yOS_HAIKU
#endif
#if defined(BOOST_OS_HPUX_AVAILABLE)
#  define yOS_HPUX
#endif
#if defined(BOOST_OS_IOS_AVAILABLE)
#  define yOS_IOS
#endif
#if defined(BOOST_OS_IRIX_AVAILABLE)
#  define yOS_IRIX
#endif
#if defined(BOOST_OS_LINUX_AVAILABLE)
#  define yOS_LINUX
#endif
#if defined(BOOST_OS_MACOS_AVAILABLE)
#  define yOS_MACOS
#endif
#if defined(BOOST_OS_OS400_AVAILABLE)
#  define yOS_OS400
#endif
#if defined(BOOST_OS_QNX_AVAILABLE)
#  define yOS_QNX
#endif
#if defined(BOOST_OS_SOLARIS_AVAILABLE)
#  define yOS_SOLARIS
#endif
#if defined(BOOST_OS_UNIX_AVAILABLE)
#  define yOS_UNIX
#endif
#if defined(BOOST_OS_SVR4_AVAILABLE)
#  define yOS_SVR4
#endif
#if defined(BOOST_OS_VMS_AVAILABLE)
#  define yOS_VMS
#endif
#if defined(BOOST_OS_BSD_BSDI_AVAILABLE)
#  define yOS_BSDI
#endif
#if defined(BOOST_OS_WINDOWS_AVAILABLE)
#  define yOS_WINDOWS
#endif

#if !defined(yOS_AIX) && !defined(yOS_AMIGAOS) && !defined(yOS_ANDROID) && !defined(yOS_BEOS) &&\
    !defined(yOS_BSD) && !defined(yOS_CYGWIN) && !defined(yOS_HAIKU) && !defined(yOS_HPUX) &&\
    !defined(yOS_IOS) && !defined(yOS_IRIX) && !defined(yOS_LINUX) && !defined(yOS_MACOS) &&\
    !defined(yOS_OS400) && !defined(yOS_QNX) && !defined(yOS_SOLARIS) && !defined(yOS_UNIX) &&\
    !defined(yOS_SVR4) && !defined(yOS_VMS) && !defined(yOS_BSDI) && !defined(yOS_WINDOWS)
// Test if we detect a operating system otherwise print error message.
#  if !defined(yAVOID_CONFIG_WARNINGS)
#    pragma warning "Unknown operating system, please contact the team! (Defined yAVOID_CONFIG_WARNINGS to avoid this message)"
#  endif
#endif

//
// Macros for Compiler detection:
//
//   - yCC_BORLAND -> Borland C++ compiler
//   - yCC_CLANG   -> Clang compiler
//   - yCC_COMO	   -> Comeau C++ compiler
//   - yCC_DEC	   -> Compaq C/C++ compiler
//   - yCC_DIAB	   -> Diab C/C++ compiler
//   - yCC_DMC	   -> Digital Mars compiler
//   - yCC_SYSC	   -> Dignus Systems/C++ compiler
//   - yCC_EDG	   -> EDG C++ Frontend compiler
//   - yCC_PATH	   -> EKOpath compiler
//   - yCC_GNUC	   -> Gnu GCC C/C++ compiler
//   - yCC_GHS	   -> Green Hills C/C++ compiler
//   - yCC_HPACC   -> HP aC++ compiler
//   - yCC_IAR	   -> IAR C/C++ compiler
//   - yCC_IBM	   -> IBM XL C/C++ compiler
//   - yCC_INTEL   -> Intel C/C++ compiler
//   - yCC_KCC	   -> Kai C++ compiler
//   - yCC_LLVM	   -> LLVM compiler
//   - yCC_HIGHC   -> MetaWare High C/C++ compiler
//   - yCC_MWERKS  -> Metrowerks CodeWarrior compiler
//   - yCC_MRI	   -> Microtec C/C++ compiler
//   - yCC_MPW	   -> MPW C++ compiler
//   - yCC_PALM	   -> Palm C/C++ compiler
//   - yCC_PGI	   -> Portland Group C/C++ compiler
//   - yCC_SGI	   -> SGI MIPSpro compiler
//   - yCC_SUNPRO  -> Oracle Solaris Studio compiler
//   - yCC_TENDRA  -> TenDRA C/C++ compiler
//   - yCC_MSVC	   -> Microsoft Visual C/C++ compiler
//   - yCC_WATCOM  -> Watcom C++ compiler
//

#if defined(BOOST_COMP_BORLAND_AVAILABLE)
#  define yCC_BORLAND
#endif
#if defined(BOOST_COMP_CLANG_AVAILABLE)
#  define yCC_CLANG
#endif
#if defined(BOOST_COMP_COMO_AVAILABLE)
#  define yCC_COMO
#endif
#if defined(BOOST_COMP_DEC_AVAILABLE)
#  define yCC_DEC
#endif
#if defined(BOOST_COMP_DIAB_AVAILABLE)
#  define yCC_DIAB
#endif
#if defined(BOOST_COMP_DMC_AVAILABLE)
#  define yCC_DMC
#endif
#if defined(BOOST_COMP_SYSC_AVAILABLE)
#  define yCC_SYSC
#endif
#if defined(BOOST_COMP_EDG_AVAILABLE)
#  define yCC_EDG
#endif
#if defined(BOOST_COMP_PATH_AVAILABLE)
#  define yCC_PATH 
#endif
#if defined(BOOST_COMP_GNUC_AVAILABLE)
#  define yCC_GNUC
#endif
#if defined(BOOST_COMP_GHS_AVAILABLE)
#  define yCC_GHS
#endif
#if defined(BOOST_COMP_HPACC_AVAILABLE)
#  define yCC_HPACC
#endif
#if defined(BOOST_COMP_IAR_AVAILABLE)
#  define yCC_IAR
#endif
#if defined(BOOST_COMP_IBM_AVAILABLE)
#  define yCC_IBM
#endif
#if defined(BOOST_COMP_INTEL_AVAILABLE)
#  define yCC_INTEL
#endif
#if defined(BOOST_COMP_KCC_AVAILABLE)
#  define yCC_KCC
#endif
#if defined(BOOST_COMP_LLVM_AVAILABLE)
#  define yCC_LLVM
#endif
#if defined(BOOST_COMP_HIGHC_AVAILABLE)
#  define yCC_HIGHC
#endif
#if defined(BOOST_COMP_MWERKS_AVAILABLE)
#  define yCC_MWERKS
#endif
#if defined(BOOST_COMP_MRI_AVAILABLE)
#  define yCC_MRI
#endif
#if defined(BOOST_COMP_MPW_AVAILABLE)
#  define yCC_MPW
#endif
#if defined(BOOST_COMP_PALM_AVAILABLE)
#  define yCC_PALM
#endif
#if defined(BOOST_COMP_PGI_AVAILABLE)
#  define yCC_PGI
#endif
#if defined(BOOST_COMP_SGI_AVAILABLE)
#  define yCC_SGI
#endif
#if defined(BOOST_COMP_SUNPRO_AVAILABLE)
#  define yCC_SUNPRO
#endif
#if defined(BOOST_COMP_TENDRA_AVAILABLE)
#  define yCC_TENDRA
#endif
#if defined(BOOST_COMP_MSVC_AVAILABLE)
#  define yCC_MSVC
#endif
#if defined(BOOST_COMP_WATCOM_AVAILABLE)
#  define yCC_WATCOM
#endif

#if !defined(yCC_BORLAND) && !defined(yCC_CLANG) && !defined(yCC_COMO) && !defined(yCC_DEC) &&\
    !defined(yCC_DIAB) && !defined(yCC_DMC) && !defined(yCC_SYSC) && !defined(yCC_EDG) &&\
    !defined(yCC_PATH) && !defined(yCC_GNUC) && !defined(yCC_GHS) && !defined(yCC_HPACC) &&\
    !defined(yCC_IAR) && !defined(yCC_IBM) && !defined(yCC_INTEL) && !defined(yCC_KCC) &&\
    !defined(yCC_LLVM) && !defined(yCC_HIGHC) && !defined(yCC_MWERKS) && !defined(yCC_MRI) &&\
    !defined(yCC_MPW) && !defined(yCC_PALM) && !defined(yCC_PGI) && !defined(yCC_SGI) &&\
    !defined(yCC_SUNPRO) && !defined(yCC_TENDRA) && !defined(yCC_MSVC) && !defined(yCC_WATCOM)
// Test if we detect a compiler otherwise print error message.
#  if !defined(yAVOID_CONFIG_WARNINGS)
#    pragma warning "Unknown c++ compiler, please contact the team! (Defined yAVOID_CONFIG_WARNINGS to avoid this message)"
#  endif
#endif

//
// Shared library Export/Import Macro
//

#if defined(yCC_MSVC)
#  define yDECL_EXPORT __declspec(dllexport)
#  define yDECL_IMPORT __declspec(dllimport)
#elif defined(yCC_GNUC)
#  define yDECL_EXPORT __attribute__((visibility("default")))
#  define yDECL_IMPORT __attribute__((visibility("default")))
#else
#  define yDECL_EXPORT
#  define yDECL_IMPORT
#  if !defined(yAVOID_CONFIG_WARNINGS)
#    pragma warning "Unknown dynamic link semantics, please contact team! (Defined yAVOID_CONFIG_WARNINGS to avoid this message)"
#  endif
#endif

//
// Portable Debug Macro
//

#if (defined(yCC_MSVC) && defined(_DEBUG)) || !defined(NDEBUG)
#  define yDEBUG
#  if defined(yNO_DEBUG)
#    undef yNO_DEBUG
#  endif
#else
#  define yNO_DEBUG
#  if defined(yDEBUG)
#    undef yDEBUG
#  endif
#endif

