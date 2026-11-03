SHELL		:= bash -e -o pipefail
PSYQ_VER	?= 400
AS			:= mipsel-linux-gnu-as
CPP			:= mipsel-linux-gnu-cpp
LD			:= mipsel-linux-gnu-ld
OBJCOPY		:= mipsel-linux-gnu-objcopy
SPLAT		?= .venv/bin/splat

ifeq ($(PSYQ_VER),400)
DECOMP_SRC_DIR	:= src
DECOMP_ASM_DIR	:= asm
OG_INCLUDE_DIR	:= include/og400
PSYQ_CC1		?= ./bin/cc1-psx-272
ASPSX_VERSION	?= 2.56
CC1_DEP		:= bin/cc1-psx-272
else ifeq ($(PSYQ_VER),470)
DECOMP_SRC_DIR	:= src/470
DECOMP_ASM_DIR	:= asm/470
OG_INCLUDE_DIR	:= include/og470
PSYQ_CC1		?=
ASPSX_VERSION	?=
CC1_DEP		:=
else
$(error Unsupported PSYQ_VER '$(PSYQ_VER)' (expected 400 or 470))
endif

MASPSX		:= python3 tools/maspsx/maspsx.py --expand-div
ifneq ($(strip $(ASPSX_VERSION)),)
MASPSX		+= --aspsx-version=$(ASPSX_VERSION)
endif

ASFLAGS		:= -Iinclude -march=r3000 -mtune=r3000 -no-pad-sections -O1 -G0
CPPFLAGS	:= -Iinclude -I$(OG_INCLUDE_DIR) -Wno-builtin-declaration-mismatch \
	-Dmips -D__OPTIMIZE__ -D__mips__ -Dpsx -D__psx__ -D__psx -D_PSYQ \
	-D__EXTENSIONS__ -D_MIPSEL -D_LANGUAGE_C -DLANGUAGE_C
CFLAGS		:= -G0 -w -O2 -g -fno-builtin -funsigned-char -fpeephole \
	-ffunction-cse -fpcc-struct-return -fcommon -fverbose-asm -msoft-float

LIBS_350    := libapi libc libcd libcard libcomb libetc libgpu libgs libgte
LIBS_350    += libgun libmath libpress libsnd libspu libtap
LIBS_360    := libapi libc libcd libcard libcomb libetc libgpu libgs libgte
LIBS_360    += libgun libmath libpress libsnd libspu libtap
LIBS_400    := libapi libc2 libcd libcard libcomb libds libetc libgpu libgs libgte
LIBS_400    += libgun libmath libmcrd libpress libsio libsnd libspu libtap
LIBS_470	:= libapi libc libcd libcard libcomb libds libetc libgpu libgs libgte
LIBS_470	+= libgun libhmd libmath libmcrd libmcx libpad libpress libsio libsnd libspu libtap
LIBS		:= $(LIBS_$(PSYQ_VER))

ORG_ELF		:= build/psyq$(PSYQ_VER)_org.elf

SRCS := $(foreach lib,$(LIBS),$(wildcard $(DECOMP_SRC_DIR)/$(lib)/*.c))
OBJS := $(patsubst $(DECOMP_SRC_DIR)/%.c,build/$(PSYQ_VER)/src/%.c.o,$(SRCS))
ASM_SRCS := $(wildcard $(DECOMP_ASM_DIR)/data/*.s) $(foreach lib,$(LIBS),$(wildcard $(DECOMP_ASM_DIR)/data/$(lib)/*.s))
ASM_OBJS := $(patsubst $(DECOMP_ASM_DIR)/%.s,build/$(PSYQ_VER)/asm/%.s.o,$(ASM_SRCS))

.PHONY: build
build: build/psyq$(PSYQ_VER).ld
	$(MAKE) build/psyq$(PSYQ_VER).elf

.PHONY: all
all: compile_commands.json
	$(MAKE) build/psyq$(PSYQ_VER).ld -j
	$(MAKE) expected -j

dependencies: tools/maspsx/maspsx.py $(CC1_DEP)
	cd sdk && $(MAKE) psyq$(PSYQ_VER)
	$(MAKE) $(OG_INCLUDE_DIR)/libgpu.h

.PHONY: clean
clean:
	git clean -xfd build/ asm/ assets/
	rm -rf obj/
	rm -f *.elf* *.map undefined_*_auto*.txt

CLANG_FORMAT := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))../bin/clang-format
CLANG_FORMAT_URL := https://github.com/Xeeynamo/llvm-clang-format-tidy/releases/download/llvmorg-22.1.4/clang-format.xz

$(CLANG_FORMAT):
	@cd $(dir $(CLANG_FORMAT)) && wget --quiet -O clang-format.xz $(CLANG_FORMAT_URL)
	@cd $(dir $(CLANG_FORMAT)) && sha256sum -c clang-format.xz.sha256
	@cd $(dir $(CLANG_FORMAT)) && xz -d clang-format.xz
	@chmod +x $@

.PHONY: format
format: $(CLANG_FORMAT)
	find $(DECOMP_SRC_DIR) -type f -name '*.c' -print0 | xargs -0 -P$$(nproc) -n1 $(CLANG_FORMAT) -i

.PHONY: compile_commands.json
compile_commands.json:
	PSYQ_VER=$(PSYQ_VER) python3 tools/gen_compile_commands.py

.PHONY: expected
expected: compile_commands.json build/psyq$(PSYQ_VER).elf
	rm -rf expected/$(PSYQ_VER)
	mkdir -p expected/$(PSYQ_VER)
	cp -r build expected/$(PSYQ_VER)/

build/psyq$(PSYQ_VER).elf: build/psyq$(PSYQ_VER).ld $(OBJS) $(ASSETS_OBJS)
	@$(MAKE) --no-print-directory build/psyq$(PSYQ_VER).elf.link

build/psyq$(PSYQ_VER).elf.link: $(ASM_OBJS)
	@echo Link build/psyq$(PSYQ_VER).elf
	@$(LD) -o build/psyq$(PSYQ_VER).elf.intermediate -Map=build/psyq$(PSYQ_VER).map \
		-T symbols.$(PSYQ_VER).bss.txt \
		-T build/undefined_funcs_auto.$(PSYQ_VER).txt build/undefined_syms_auto.$(PSYQ_VER).txt -T build/psyq$(PSYQ_VER).ld \
		$(OBJS) $(ASM_OBJS)
	@$(OBJCOPY) -O binary build/psyq$(PSYQ_VER).elf.intermediate build/psyq$(PSYQ_VER).elf
	@rm -f build/psyq$(PSYQ_VER).elf.intermediate
	@sha256sum -c build/psyq$(PSYQ_VER).elf.sha256
build/$(PSYQ_VER)/src/%.c.o: $(DECOMP_SRC_DIR)/%.c build/psyq$(PSYQ_VER).ld $(OG_INCLUDE_DIR)/libgpu.h
	@echo Compile $<
	@mkdir -p $(dir $@)
	@test -n "$(strip $(PSYQ_CC1))" || { echo "PSYQ_CC1 is required for PSY-Q $(PSYQ_VER) C sources" >&2; exit 1; }
	@test -n "$(strip $(ASPSX_VERSION))" || { echo "ASPSX_VERSION is required for PSY-Q $(PSYQ_VER) C sources; the 4.7 assembler mode is not established" >&2; exit 1; }
	@$(CPP) $(CPPFLAGS) -MMD -MF $@.d -MT $@ -lang-c $< | $(PSYQ_CC1) $(CFLAGS) -quiet | $(MASPSX) | $(AS) $(ASFLAGS) -o $@
-include $(OBJS:=.d)
build/$(PSYQ_VER)/asm/%.s.o: $(DECOMP_ASM_DIR)/%.s
	@echo Assemble $<
	@mkdir -p $(dir $@)
	@$(AS) $(ASFLAGS) -o $@ $<

build/psyq$(PSYQ_VER).ld: splat$(PSYQ_VER).yaml $(ORG_ELF) symbols.$(PSYQ_VER).txt
	@rm -rf $@ $(DECOMP_ASM_DIR) build/$(PSYQ_VER)/asm build/$(PSYQ_VER)/src
	$(SPLAT) split $<
$(ORG_ELF): $(patsubst %,build/obj/$(PSYQ_VER)/%, $(LIBS)) psyq-gen.sh rm-o-dups-$(PSYQ_VER).sh
	./rm-o-dups-$(PSYQ_VER).sh
	./psyq-gen.sh $(PSYQ_VER) "$(LD)"
	$(OBJCOPY) -O binary $@ build/psyq$(PSYQ_VER)_org.bin
	sha256sum -c psyq$(PSYQ_VER).bin.sha256
	echo "$$(sha256sum $@ | cut -d' ' -f1)  build/psyq$(PSYQ_VER).elf" > build/psyq$(PSYQ_VER).elf.sha256
build/obj/$(PSYQ_VER)/lib%: sdk/psyq$(PSYQ_VER) bin/psyqdump
	@mkdir -p $@ && \
		bin/psyqdump $</LIB/LIB$(shell echo $* | tr '[:lower:]' '[:upper:]').LIB $@ || \
		rm -r $@
	@for file in $@/*.OBJ; do \
		output="$$(echo $${file%.OBJ}.o | tr '[:upper:]' '[:lower:]')"; \
		(cd build && ../bin/psyq-obj-parser "../$$file" -o "$${output#build/}") > /dev/null; \
	done
include/og%/libgpu.h: sdk/psyq% bin/psyq2elf
	@mkdir -p $(@D)
	cd bin/psyq2elf && ./psyqinc.sh ../../$</INCLUDE ../../$(@D)
bin/psyqdump: bin/psyq2elf
	cd bin/psyq2elf && make
	cp bin/psyq2elf/psyqdump bin/
bin/psyq2elf:
	git clone --depth 1 https://gitlab.com/jype/psyq2elf.git bin/psyq2elf
bin/cc1-psx-272:
	wget --quiet -O bin/gcc-2.7.2-psx.tar.gz https://github.com/decompals/old-gcc/releases/download/0.13/gcc-2.7.2-psx.tar.gz
	sha256sum -c bin/gcc-2.7.2-psx.tar.gz.sha256
	cd bin && tar -xf gcc-2.7.2-psx.tar.gz
	rm -f bin/gcc-2.7.2-psx.tar.gz bin/cc1plus bin/cpp bin/g++ bin/gcc
	mv bin/cc1 $@
tools/maspsx/maspsx.py:
	git submodule update tools/maspsx
