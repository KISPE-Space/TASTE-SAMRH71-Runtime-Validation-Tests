# MAKEFILE_PATH   := $(abspath $(lastword $(MAKEFILE_LIST)))
MAKEFILE_PATH   := $(lastword $(MAKEFILE_LIST))
TOOL_INST       := $(shell taste-config --prefix)
OUTDIR          := $(dir $(MAKEFILE_PATH))
TASTE_SHARED_TYPES?=${HOME}/.local/share/QtProject/QtCreator/shared_types
ASN1_FILES      :=../model_robfinal.asn ${TOOL_INST}/share/taste-types/taste-types.asn system.asn
CP_FILES        :=       # Context parameters
DATAVIEW_PATH   := ${OUTDIR}/dataview
DATAVIEW_UNIQ   := ${DATAVIEW_PATH}/dataview-uniq.asn
DATAVIEW_ACN    := ${DATAVIEW_PATH}/dataview-uniq.acn
# the dataview with AADLv1 data is generated in Python by asn2aadlPlus
DATAVIEW_AADLV1 := ${DATAVIEW_PATH}/dataview_aadlv1.aadl
ASN1_POLICY_FLAGS ?= -typePrefix asn1Scc -renamePolicy 3 -equal -fp AUTO -c -ig -uPER -ACN
#TASTE_SHARED_TYPES?=${TOOL_INST}/share/SharedTypes  # Ellidiss only

# These languages are used in the system: Ada, C, Timer_Manager
# Project cache folder is used to speed up all ASN.1-related processing
export PROJECT_CACHE=${HOME}/.taste_AST_cache
export IV_FILE=$(shell readlink -f ../interfaceview.xml)
all:	build-default
	$(info Run "make -C work check_stack" to analyze the stack usage of your application")

# Call the stack checker
check_stack:
	$(MAKE) -C build -f Makefile.taste check_stack


# Check that all runtimes used in the system are installed
check_targets:
	$(MAKE) -C build -f Makefile.taste check_targets

# Generate the language-specific data view needed before editing user code
dataview:	${DATAVIEW_UNIQ} dataview/C/built
	# Copy the dataview to SDL/SEDS function TestSDL08 (no context parameters)
	cp -u ${DATAVIEW_UNIQ} testsdl08/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "testsdl08/SDL/src/dataview.md5" > /dev/null 2>&1 || md5sum  "testsdl08/SDL/src/dataview-uniq.asn" >  "testsdl08/SDL/src/dataview.md5"
	# Copy the dataview to SDL/SEDS function TestSDL14 (no context parameters)
	cp -u ${DATAVIEW_UNIQ} testsdl14/SDL/src
	# Compute MD5 of the dataview, needed to decide if code needs to be re-generated
	md5sum -c "testsdl14/SDL/src/dataview.md5" > /dev/null 2>&1 || md5sum  "testsdl14/SDL/src/dataview-uniq.asn" >  "testsdl14/SDL/src/dataview.md5"
	# Pre-cache the Dataview for opengeode to speed up parsing
	taste-cache-datamodel-for-sdl --toAda
	# Pre-cache the Dataview for opengeode to speed up parsing
	taste-cache-datamodel-for-sdl --toC

# Generate the complete dataview, including Python bindings if there is a GUI
${DATAVIEW_PATH}/built:  dataview/C/built dataview/Ada/built dataview
	touch $@

${DATAVIEW_AADLV1}: ${DATAVIEW_UNIQ}
	echo [-] Generate dataview entry in Python for aadl2glueC
	asn2aadlPlus  $< $@


# Build based on the deployment view
# The parallel invocation can not be added here because of matlab remote error
# For local matlab instalation it can be added
build-default:	aadl2glueC build/system_config.h ${DATAVIEW_PATH}/built build/deploymentview_final/Makefile
	$(MAKE) -C build -f Makefile.taste

# Execute the generated binaries (used in Space Creator when using the Run button)
run: # Space creator will always build before, so no need to depend on build-default
	$(MAKE) -j -C build -f Makefile.taste run

# Run the Concurrency View analysis tool (cheddar/marzhin)
run_cv: build/ConcurrencyView.aadl
	TASTECV --load $^

# The Concurrency View needed by Cheddar is the concatenation of system.aadl and ocarina_components.aadl
build/ConcurrencyView.aadl:	build/system.aadl
	cat $^ $(shell taste-config --prefix)/share/ocarina/AADLv2/ocarina_components.aadl > $@

# Rule to invoke Ocarina (generation of POHI middleware code)
build/deploymentview_final/Makefile:	build/main.aadl ${DATAVIEW_UNIQ}
	# Nothing will be generated if POHIC is not needed
	$(MAKE) -C build -f Makefile.taste ocarina

# Optionally manage SQL Database (run taste-create-database to enable)
sql_db/DV.py:
	mkdir -p sql_db && touch $@

# Create dataview-uniq.asn by concatenating all asn1 input files
${DATAVIEW_UNIQ}:	${ASN1_FILES}
	mkdir -p ${PROJECT_CACHE} && mkdir -p ${DATAVIEW_PATH}
	sed -e '$$s/$$/\n/' -s $^ > $@

# Create dataview-uniq.acn by concatenating all input files
${DATAVIEW_ACN}:	../model_robfinal.acn
	mkdir -p ${DATAVIEW_PATH}
	sed -e '$$s/$$/\n/' -s $^ > $@

# system_config.h is used to filter out non-needed ASN.1 encoder/decoders
build/system_config.h:	$(wildcard */*/wrappers/*_system_config.h)
	cat $^ > $@

#  Call DMT/aadl2glueC to generate glue code from the mini-cv.aadl files
aadl2glueC:	activationlog/C/wrappers/aadl2glueC_built boothelper00f/C/wrappers/aadl2glueC_built brokerlock00g/C/wrappers/aadl2glueC_built brokertest002a/C/wrappers/aadl2glueC_built deathreport00c/C/wrappers/aadl2glueC_built escapertest002b/C/wrappers/aadl2glueC_built function_1/C/wrappers/aadl2glueC_built function_10/C/wrappers/aadl2glueC_built function_11/C/wrappers/aadl2glueC_built function_12/C/wrappers/aadl2glueC_built function_13/C/wrappers/aadl2glueC_built function_14/C/wrappers/aadl2glueC_built function_15/C/wrappers/aadl2glueC_built function_16/C/wrappers/aadl2glueC_built function_17/C/wrappers/aadl2glueC_built function_18/C/wrappers/aadl2glueC_built function_19/C/wrappers/aadl2glueC_built function_2/C/wrappers/aadl2glueC_built function_20/C/wrappers/aadl2glueC_built function_21/C/wrappers/aadl2glueC_built function_22/C/wrappers/aadl2glueC_built function_23/C/wrappers/aadl2glueC_built function_24/C/wrappers/aadl2glueC_built function_3/C/wrappers/aadl2glueC_built function_4/C/wrappers/aadl2glueC_built function_5/C/wrappers/aadl2glueC_built function_6/C/wrappers/aadl2glueC_built function_7/C/wrappers/aadl2glueC_built function_8/C/wrappers/aadl2glueC_built function_9/C/wrappers/aadl2glueC_built hal00d/C/wrappers/aadl2glueC_built monitorcallback/C/wrappers/aadl2glueC_built monitoring00a/C/wrappers/aadl2glueC_built mqueuecallback12/C/wrappers/aadl2glueC_built paketizer002c/C/wrappers/aadl2glueC_built partition_1_timer_manager/Timer_Manager/wrappers/aadl2glueC_built prot00if/C/wrappers/aadl2glueC_built prot05ifin/C/wrappers/aadl2glueC_built prot05ifout/C/wrappers/aadl2glueC_built rcvacn01/C/wrappers/aadl2glueC_built rcvacn02/C/wrappers/aadl2glueC_built rcvacn03/C/wrappers/aadl2glueC_built rcvacn04/C/wrappers/aadl2glueC_built rcvacn05/C/wrappers/aadl2glueC_built receiver001/C/wrappers/aadl2glueC_built receiver011/C/wrappers/aadl2glueC_built receiver012/C/wrappers/aadl2glueC_built receiver013/C/wrappers/aadl2glueC_built receiver014/C/wrappers/aadl2glueC_built receiver015/C/wrappers/aadl2glueC_built receiver016/C/wrappers/aadl2glueC_built receiver017/C/wrappers/aadl2glueC_built receiver018/C/wrappers/aadl2glueC_built receiver019/C/wrappers/aadl2glueC_built receiver020/C/wrappers/aadl2glueC_built samrh71core00h/C/wrappers/aadl2glueC_built sendacn/C/wrappers/aadl2glueC_built sender001/C/wrappers/aadl2glueC_built sender002/C/wrappers/aadl2glueC_built sender003/C/wrappers/aadl2glueC_built sender004/C/wrappers/aadl2glueC_built sender005/C/wrappers/aadl2glueC_built sender006/C/wrappers/aadl2glueC_built sender007/C/wrappers/aadl2glueC_built sender008/C/wrappers/aadl2glueC_built sender009/C/wrappers/aadl2glueC_built sender010/C/wrappers/aadl2glueC_built sender011/C/wrappers/aadl2glueC_built testcyclic05/C/wrappers/aadl2glueC_built testmodules/C/wrappers/aadl2glueC_built testprotected/C/wrappers/aadl2glueC_built testsdl08/SDL/wrappers/aadl2glueC_built testsdl14/SDL/wrappers/aadl2glueC_built testsendcomms09/C/wrappers/aadl2glueC_built testspcc/C/wrappers/aadl2glueC_built teststart00/C/wrappers/aadl2glueC_built testunprot00/C/wrappers/aadl2glueC_built testunprotected/C/wrappers/aadl2glueC_built testunprotin05/C/wrappers/aadl2glueC_built testunprotout05/C/wrappers/aadl2glueC_built threads00e/C/wrappers/aadl2glueC_built

activationlog/C/wrappers/aadl2glueC_built: activationlog/C/wrappers/activationlog_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

boothelper00f/C/wrappers/aadl2glueC_built: boothelper00f/C/wrappers/boothelper00f_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

brokerlock00g/C/wrappers/aadl2glueC_built: brokerlock00g/C/wrappers/brokerlock00g_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

brokertest002a/C/wrappers/aadl2glueC_built: brokertest002a/C/wrappers/brokertest002a_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

deathreport00c/C/wrappers/aadl2glueC_built: deathreport00c/C/wrappers/deathreport00c_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

escapertest002b/C/wrappers/aadl2glueC_built: escapertest002b/C/wrappers/escapertest002b_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_1/C/wrappers/aadl2glueC_built: function_1/C/wrappers/function_1_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_10/C/wrappers/aadl2glueC_built: function_10/C/wrappers/function_10_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_11/C/wrappers/aadl2glueC_built: function_11/C/wrappers/function_11_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_12/C/wrappers/aadl2glueC_built: function_12/C/wrappers/function_12_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_13/C/wrappers/aadl2glueC_built: function_13/C/wrappers/function_13_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_14/C/wrappers/aadl2glueC_built: function_14/C/wrappers/function_14_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_15/C/wrappers/aadl2glueC_built: function_15/C/wrappers/function_15_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_16/C/wrappers/aadl2glueC_built: function_16/C/wrappers/function_16_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_17/C/wrappers/aadl2glueC_built: function_17/C/wrappers/function_17_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_18/C/wrappers/aadl2glueC_built: function_18/C/wrappers/function_18_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_19/C/wrappers/aadl2glueC_built: function_19/C/wrappers/function_19_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_2/C/wrappers/aadl2glueC_built: function_2/C/wrappers/function_2_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_20/C/wrappers/aadl2glueC_built: function_20/C/wrappers/function_20_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_21/C/wrappers/aadl2glueC_built: function_21/C/wrappers/function_21_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_22/C/wrappers/aadl2glueC_built: function_22/C/wrappers/function_22_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_23/C/wrappers/aadl2glueC_built: function_23/C/wrappers/function_23_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_24/C/wrappers/aadl2glueC_built: function_24/C/wrappers/function_24_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_3/C/wrappers/aadl2glueC_built: function_3/C/wrappers/function_3_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_4/C/wrappers/aadl2glueC_built: function_4/C/wrappers/function_4_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_5/C/wrappers/aadl2glueC_built: function_5/C/wrappers/function_5_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_6/C/wrappers/aadl2glueC_built: function_6/C/wrappers/function_6_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_7/C/wrappers/aadl2glueC_built: function_7/C/wrappers/function_7_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_8/C/wrappers/aadl2glueC_built: function_8/C/wrappers/function_8_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

function_9/C/wrappers/aadl2glueC_built: function_9/C/wrappers/function_9_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

hal00d/C/wrappers/aadl2glueC_built: hal00d/C/wrappers/hal00d_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

monitorcallback/C/wrappers/aadl2glueC_built: monitorcallback/C/wrappers/monitorcallback_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

monitoring00a/C/wrappers/aadl2glueC_built: monitoring00a/C/wrappers/monitoring00a_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

mqueuecallback12/C/wrappers/aadl2glueC_built: mqueuecallback12/C/wrappers/mqueuecallback12_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

paketizer002c/C/wrappers/aadl2glueC_built: paketizer002c/C/wrappers/paketizer002c_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

partition_1_timer_manager/Timer_Manager/wrappers/aadl2glueC_built: partition_1_timer_manager/Timer_Manager/wrappers/partition_1_timer_manager_mini_cv.aadl ${DATAVIEW_AADLV1}
	aadl2glueC -allboards -o $(dir $@) $^
	touch $@

prot00if/C/wrappers/aadl2glueC_built: prot00if/C/wrappers/prot00if_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

prot05ifin/C/wrappers/aadl2glueC_built: prot05ifin/C/wrappers/prot05ifin_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

prot05ifout/C/wrappers/aadl2glueC_built: prot05ifout/C/wrappers/prot05ifout_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

rcvacn01/C/wrappers/aadl2glueC_built: rcvacn01/C/wrappers/rcvacn01_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

rcvacn02/C/wrappers/aadl2glueC_built: rcvacn02/C/wrappers/rcvacn02_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

rcvacn03/C/wrappers/aadl2glueC_built: rcvacn03/C/wrappers/rcvacn03_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

rcvacn04/C/wrappers/aadl2glueC_built: rcvacn04/C/wrappers/rcvacn04_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

rcvacn05/C/wrappers/aadl2glueC_built: rcvacn05/C/wrappers/rcvacn05_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

receiver001/C/wrappers/aadl2glueC_built: receiver001/C/wrappers/receiver001_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

receiver011/C/wrappers/aadl2glueC_built: receiver011/C/wrappers/receiver011_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

receiver012/C/wrappers/aadl2glueC_built: receiver012/C/wrappers/receiver012_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

receiver013/C/wrappers/aadl2glueC_built: receiver013/C/wrappers/receiver013_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

receiver014/C/wrappers/aadl2glueC_built: receiver014/C/wrappers/receiver014_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

receiver015/C/wrappers/aadl2glueC_built: receiver015/C/wrappers/receiver015_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

receiver016/C/wrappers/aadl2glueC_built: receiver016/C/wrappers/receiver016_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

receiver017/C/wrappers/aadl2glueC_built: receiver017/C/wrappers/receiver017_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

receiver018/C/wrappers/aadl2glueC_built: receiver018/C/wrappers/receiver018_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

receiver019/C/wrappers/aadl2glueC_built: receiver019/C/wrappers/receiver019_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

receiver020/C/wrappers/aadl2glueC_built: receiver020/C/wrappers/receiver020_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

samrh71core00h/C/wrappers/aadl2glueC_built: samrh71core00h/C/wrappers/samrh71core00h_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sendacn/C/wrappers/aadl2glueC_built: sendacn/C/wrappers/sendacn_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sender001/C/wrappers/aadl2glueC_built: sender001/C/wrappers/sender001_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sender002/C/wrappers/aadl2glueC_built: sender002/C/wrappers/sender002_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sender003/C/wrappers/aadl2glueC_built: sender003/C/wrappers/sender003_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sender004/C/wrappers/aadl2glueC_built: sender004/C/wrappers/sender004_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sender005/C/wrappers/aadl2glueC_built: sender005/C/wrappers/sender005_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sender006/C/wrappers/aadl2glueC_built: sender006/C/wrappers/sender006_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sender007/C/wrappers/aadl2glueC_built: sender007/C/wrappers/sender007_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sender008/C/wrappers/aadl2glueC_built: sender008/C/wrappers/sender008_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sender009/C/wrappers/aadl2glueC_built: sender009/C/wrappers/sender009_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sender010/C/wrappers/aadl2glueC_built: sender010/C/wrappers/sender010_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

sender011/C/wrappers/aadl2glueC_built: sender011/C/wrappers/sender011_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

testcyclic05/C/wrappers/aadl2glueC_built: testcyclic05/C/wrappers/testcyclic05_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

testmodules/C/wrappers/aadl2glueC_built: testmodules/C/wrappers/testmodules_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

testprotected/C/wrappers/aadl2glueC_built: testprotected/C/wrappers/testprotected_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

testsdl08/SDL/wrappers/aadl2glueC_built: testsdl08/SDL/wrappers/testsdl08_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

testsdl14/SDL/wrappers/aadl2glueC_built: testsdl14/SDL/wrappers/testsdl14_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

testsendcomms09/C/wrappers/aadl2glueC_built: testsendcomms09/C/wrappers/testsendcomms09_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

testspcc/C/wrappers/aadl2glueC_built: testspcc/C/wrappers/testspcc_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

teststart00/C/wrappers/aadl2glueC_built: teststart00/C/wrappers/teststart00_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

testunprot00/C/wrappers/aadl2glueC_built: testunprot00/C/wrappers/testunprot00_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

testunprotected/C/wrappers/aadl2glueC_built: testunprotected/C/wrappers/testunprotected_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

testunprotin05/C/wrappers/aadl2glueC_built: testunprotin05/C/wrappers/testunprotin05_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

testunprotout05/C/wrappers/aadl2glueC_built: testunprotout05/C/wrappers/testunprotout05_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@

threads00e/C/wrappers/aadl2glueC_built: threads00e/C/wrappers/threads00e_mini_cv.aadl ${DATAVIEW_AADLV1}
	touch $@


# Compile the ASN.1 models in C
dataview/C/built: ${DATAVIEW_UNIQ} ${DATAVIEW_ACN} ${CP_FILES}
	$(info [-] Compiling the dataview in C)
	mkdir -p $(dir $@)
	asn1scc ${ASN1SCC_FLAGS} -o $(dir $@) ${ASN1_POLICY_FLAGS} $^
	cp ${TOOL_INST}/share/AutoGUI/debug_messages.? dataview/C
	cp ${TOOL_INST}/share/AutoGUI/timeInMS.? dataview/C
	cd dataview/C && msgPrinterASN1 ../dataview-uniq.asn
	touch $@


dataview/Ada/built: ${DATAVIEW_UNIQ} ${CP_FILES}
	$(info [-] Compiling the dataview in Ada)
	mkdir -p $(dir $@)
	asn2dataModel -allboards -o $(dir $@) -toAda $^
	touch $@
	cd dataview/Ada && rm -f gnat.cfg GPS_project.gpr IgnoredExaminerWarnings.wrn runSpark.sh

simulink_skeletons:
	# target required only for SIMULINK and VHDL, which use specific DMT paths
	# empty otherwise

clean:
	rm -rf binaries dataview
	$(MAKE) -C build -f Makefile.taste clean

.PHONY: clean simu compile-all-linux function-instances-linux function-types-linux build-default dataview build-rtems-ada dataview build/modelchecking modelchecking/subtypes/$(SUBTYPE) obs-to-if aadl-to-if asn-to-if $(PROPERTIES_CONFIG) run_cv simulink_skeletons

