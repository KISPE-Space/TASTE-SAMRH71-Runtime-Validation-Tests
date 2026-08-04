TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    samrh71.dv.xml \
    samrh71.dv.xml \
    samrh71.dv.xml
DISTFILES += template.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += template.asn
DISTFILES += template.acn
include(work/taste.pro)
message($$DISTFILES)

SOURCES +=

