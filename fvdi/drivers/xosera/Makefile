#!make -f
#
# This software is licensed under the GNU General Public License.
# Please, see LICENSE.TXT for further information.
#

#
# gcc >= 2.95.3 (sparemint) version
#

ifndef ROSCO_M68K_DIR
$(info Please set ROSCO_M68K_DIR to the rosco_m68k root directory to use for rosco_m68k building)
endif
# check for xosera_m68k_api build dir
ifndef XOSERA_M68K_API
$(info Please set XOSERA_M68K_API to the xosera_m68k_api directory to use for Xosera m68k building)
endif

#-include $(ROSCO_M68K_DIR)/user.mk

TARGET = xosera.sys

all: $(TARGET)

top_srcdir = ../..

OPTS    = -mshort -O2 -fomit-frame-pointer
include $(top_srcdir)/CONFIGVARS

CFLAGS  = $(CPUOPTS) $(OPTS) $(WARNINGS) -I$(top_srcdir)/include -I$(top_srcdir)/drivers/include -I$(ROSCO_M68K_DIR)/code/software/libs/build/include -I$(XOSERA_M68K_API)
# don't include rosco firmware I/O in API, also define a few things that rosco_m68k toolchain normally defines to quiet warnings
CFLAGS +=  -DXOSERA_API_MINIMAL -D_XOPEN_SOURCE=700 -D_FORTIFY_SOURCE=0

SINCSRC = \
	$(top_srcdir)/drivers/bitplane/1_expand.inc

SSRC = \
	../common/c_common.s \
	../common/common.s \
	../common/clip.s

CSRC = \
	xosera.c \
	init.c \
	printf.c \
	xosera_spec.c \
	xosera_scr.c \
	xosera_pal.c \
	xosera_line.c \
	xosera_fill.c \
	xosera_mouse.c \
	xosera_blit.c \
	$(XOSERA_M68K_API)/xosera_m68k_api.c

# handle DevPac -> gas conversions
# defines SSRC_GNU and SINCSRC_GNU variables
include $(top_srcdir)/utility/conv2gas/RULES

SINCSRC_GNU += \
	$(top_srcdir)/include/types.inc \
	$(top_srcdir)/include/macros.gnu \
	$(top_srcdir)/include/vdi.gnu \
	$(top_srcdir)/drivers/include/pixelmac.gnu

# engine binary objects
# Engine binary objects
ifeq ($(CPU),v4e)
OBJECTS = $(SSRC_GNU_CF:.s=.o)
else
OBJECTS = $(SSRC_GNU:.s=.o)
endif
OBJECTS += $(CSRC:.c=.o)

$(OBJECTS): $(SINCSRC_GNU)

$(TARGET): $(OBJECTS) $(LIBFILES)
	$(AM_V_LD)$(LD) -o $@ $(OBJECTS) $(LDFLAGS) $(LIBS)

include $(top_srcdir)/DEPENDENCIES


strip:
	$(STRIP) --strip-all $(TARGET)

clean:: clean_gnu
	$(RM) $(OBJECTS) $(TARGET)

install::
	mkdir -p $(DESTDIR)/gemsys
	cp -a $(TARGET) $(DESTDIR)/gemsys/$(TARGET)
