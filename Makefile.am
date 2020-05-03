ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = factor

factor_SOURCES = factor.c tokenizer.c
factor_LDFLAGS =
factor_LDADD =

noinst_HEADERS = tokenizer.h

check_PROGRAMS = suite

suite_SOURCES = suite.c test_tokenizer.c tokenizer.c munit.c
suite_LDFLAGS =
suite_LDADD =

check_HEADERS = munit.h

EXTRA_DIST = configure.ac

CLEANFILES = *~

check-local:
	./suite
