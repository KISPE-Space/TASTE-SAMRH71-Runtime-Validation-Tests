TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    samrh71.dv.xml \
    samrh71.dv.xml \
    samrh71.dv.xml
DISTFILES += model-max-tasks.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += model-max-tasks.asn
DISTFILES += model-max-tasks.acn
include(work/taste.pro)
message($$DISTFILES)

SOURCES +=

