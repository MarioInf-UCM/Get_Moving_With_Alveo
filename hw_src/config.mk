# Options for TARGET: sw_emu, hw_emu and hw
TARGET ?= sw_emu
# Options for DEVICE: u200, u250. Default platform is XDMA, defined by PLATFORM
DEVICE ?= u200
# If other some specific platforms needs to be used, provide platform path directly
PLATFORM ?= xilinx_$(DEVICE)_gen3x16_xdma_2_202110_1
# If your platform is not in the standard install area edit this line
PLATFORM_REPO_PATHS ?= /opt/xilinx/platforms/
