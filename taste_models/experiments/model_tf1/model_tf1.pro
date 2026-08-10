TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    samrh71.dv.xml \
    samrh71.dv.xml
DISTFILES += model_tf1.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += model_tf1.asn
DISTFILES += model_tf1.acn
include(work/taste.pro)
message($$DISTFILES)

SOURCES +=

