// A helper file for: Rewriting all SVCALLs to properly declare to the compiler which ARM registers are used with SVC calls.
// Taken from: https://github.com/eblot/nrf5-llvm#nrfsvcpy
// This will be included in other files so they can still point to their usual locations, with this appended.

// prevent from upgrading nRF52 header files more than once
#define NRF_CLANG_SUPPORT 1

// define system call macros only once
#ifndef _SYSCALL_ARGS

#define _SYSCALL_ARGS(_SC_, ...) \
   __asm__ __volatile__ ( \
      "svc %[SC]" \
         : "=r"(r0) : [SC]"I" ((uint16_t)_SC_), ##__VA_ARGS__ : "memory"); \
   return r0; \

#define _SCC(X) ((long) (X))

#define _SYSCALL0(_SC_) \
   register long r0 __asm__("r0"); \
   _SYSCALL_ARGS(_SC_); \

#define _SYSCALL1(_SC_, _a_) \
   register long r0 __asm__("r0") = _SCC(_a_); \
   _SYSCALL_ARGS(_SC_, "0"(r0)); \

#define _SYSCALL2(_SC_, _a_, _b_) \
   register long r0 __asm__("r0") = _SCC(_a_); \
   register long r1 __asm__("r1") = _SCC(_b_); \
   _SYSCALL_ARGS(_SC_, "0"(r0), "r"(r1)); \

#define _SYSCALL3(_SC_, _a_, _b_, _c_) \
   register long r0 __asm__("r0") = _SCC(_a_); \
   register long r1 __asm__("r1") = _SCC(_b_); \
   register long r2 __asm__("r2") = _SCC(_c_); \
   _SYSCALL_ARGS(_SC_, "0"(r0), "r"(r1), "r"(r2)); \

#define _SYSCALL4(_SC_, _a_, _b_, _c_, _d_) \
   register long r0 __asm__("r0") = _SCC(_a_); \
   register long r1 __asm__("r1") = _SCC(_b_); \
   register long r2 __asm__("r2") = _SCC(_c_); \
   register long r3 __asm__("r3") = _SCC(_d_); \
   _SYSCALL_ARGS(_SC_, "0"(r0), "r"(r1), "r"(r2), "r"(r3)); \

#endif // SYSCALL_CP