ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = scheme

scheme_SOURCES = scheme.c type.c tokenizer.c
scheme_LDFLAGS =
scheme_LDADD =

noinst_HEADERS = tokenizer.h type.h

check_PROGRAMS = suite

suite_SOURCES = suite.c test_type.c type.c test_tokenizer.c tokenizer.c munit.c
suite_LDFLAGS =
suite_LDADD =

check_HEADERS = munit.h

EXTRA_DIST = configure.ac

CLEANFILES = *~

check-local:
	./suite
