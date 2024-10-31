#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([@PACKAGE_NAME@],[@PACKAGE_VERSION@],[cschmit@luc.edu])
AC_CONFIG_AUX_DIR(admin)
AM_INIT_AUTOMAKE
#AC_CONFIG_SRCDIR([01-helloworld/helloWorld.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs used for compilation.
AC_PROG_CC

# Checks for libraries to support threads.
AC_CHECK_LIB([pthread], [main])

AC_CHECK_HEADERS([stdlib.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics
# that support threads.
AC_C_CONST
AC_TYPE_PID_T
AC_STRUCT_TM

# Checks for library functions for process creation and time.
AC_FUNC_FORK
AC_FUNC_STRFTIME

# List of all the local makefiles to create
AC_CONFIG_FILES([01-helloworld/makefile
                 02-function/makefile
                 03-arguments/makefile
                 04-user-input/makefile
                 05-integers/makefile
                 06-floats/makefile
                 07-advanced-input/makefile
                 08-cli-arguments/makefile
                 09-files/makefile
                 10-loops/makefile
                 11-conditions/makefile
                 12-time/makefile
                 13-structure/makefile
                 14-process/makefile
                 15-thread/makefile
                 16-sharedmem/makefile
                 17-semaphore/makefile
                 makefile])
AC_OUTPUT
