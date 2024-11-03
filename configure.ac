#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([@PACKAGE_NAME@],[@PACKAGE_VERSION@],[cschmit@luc.edu])
# AC_CONFIG_AUX_DIR(admin)
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
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
AC_CONFIG_FILES([src/01-helloworld/Makefile
                 src/02-function/Makefile
                 src/03-arguments/Makefile
                 src/04-user-input/Makefile
                 src/05-integers/Makefile
                 src/06-floats/Makefile
                 src/07-advanced-input/Makefile
                 src/08-cli-arguments/Makefile
                 src/09-files/Makefile
                 src/10-loops/Makefile
                 src/11-conditions/Makefile
                 src/12-time/Makefile
                 src/13-structure/Makefile
                 src/14-process/Makefile
                 src/15-thread/Makefile
                 src/16-sharedmem/Makefile
                 src/17-semaphore/Makefile
                 src/Makefile
		 Makefile])
AC_OUTPUT
